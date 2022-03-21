/***************************************************************
  MovingAveragePlus.h - Moving average structure manager.
  Created by Alexandre Hiroyuki Yamauchi, September 2, 2019.
***************************************************************/
#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H

#include <Arduino.h>
#include <string.h>

template <class TypeOfArray>
class MovingAveragePlus {
 private:
  size_t _array_size;
  size_t _current_index;
  size_t _average_counter;

  TypeOfArray *_array;
  TypeOfArray _average_sum;

  size_t _partial_sums_counter;
  TypeOfArray *_partial_sums;
  TypeOfArray *_partial_sum_sizes;

  void _nextIndex() {
    _current_index++;
    if (_current_index >= _array_size) _current_index = 0;
  }

 public:
  // Constructor
  MovingAveragePlus(size_t size)
      : _array_size(size),
        _current_index(0),
        _average_counter(0),
        _array((TypeOfArray *)calloc(size, sizeof(TypeOfArray))),
        _average_sum(0),
        _partial_sums_counter(0),
        _partial_sums((TypeOfArray *)calloc(1, sizeof(TypeOfArray))),
        _partial_sum_sizes((TypeOfArray *)calloc(1, sizeof(TypeOfArray))) {}

  // Destructor
  ~MovingAveragePlus() { free(_array); }

  // Get Result and Access elements

  MovingAveragePlus<TypeOfArray> &push(TypeOfArray input) {
    TypeOfArray last_value = _array[_current_index];
    _average_sum -= last_value;
    _average_sum += input;
    _array[_current_index] = input;

    for (size_t i = 0; i < _partial_sums_counter; i++) {
      _partial_sums[i] += input;
      _partial_sums[i] -= (_current_index == _partial_sum_sizes[i] - 1)
                              ? last_value
                              : (*this)[_partial_sum_sizes[i] - 1];
    }

    if (_average_counter < _array_size) {
      _average_counter++;
    }

    _nextIndex();

    return *this;
  }

  TypeOfArray get() {
    return (_average_sum / ((_average_counter == 0) ? 1 : _average_counter));
  }
  TypeOfArray get(size_t n_points) { return get_by_brute(n_points); }

  TypeOfArray get_by_brute(size_t n_points) {
    if (n_points > _average_counter) n_points = _average_counter;

    int sum = 0;
    for (size_t i = 0; i < n_points; i++) {
      sum += (*this)[i];
    }

    return sum / n_points;
  }

  TypeOfArray front() {
    int last_index = _current_index;

    if (last_index - 1 < 0) {
      last_index = _array_size - 1;
    } else {
      last_index -= 1;
    }

    return _array[last_index];
  }

  TypeOfArray back() { return _array[_current_index]; }

  TypeOfArray operator[](size_t index) {
    if (index > _array_size) return 0;

    int final_index = (_current_index - 1) - index;

    int check_index = _array_size + final_index;

    if (final_index < 0) {
      return _array[check_index];
    }

    return _array[final_index];
  }

  TypeOfArray atIndex(size_t index) {
    if (index > _array_size) return 0;
    return _array[index];
  }

  // Modify array

  size_t size() { return _array_size; }

  MovingAveragePlus<TypeOfArray> &resize(size_t new_size) {
    _array = (TypeOfArray *)realloc(_array, new_size * sizeof(TypeOfArray));

    if (_current_index == 0) {
      _current_index = _array_size;
    } else if (_current_index >= new_size) {
      _current_index = new_size - 1;
    }

    if (_average_counter >= new_size) {
      _average_counter = new_size - 1;
    }

    _array_size = new_size;
    return *this;
  }
  MovingAveragePlus<TypeOfArray> &clear() {
    memset(_array, 0, sizeof(TypeOfArray) * _array_size);

    _average_sum = 0;

    _average_counter = 0;

    return *this;
  }
  MovingAveragePlus<TypeOfArray> &fill(TypeOfArray fill_value) {
    for (size_t i = 0; i < _average_counter; i++) {
      _array[i] = fill_value;
    }

    _average_sum = fill_value * _average_counter;

    return *this;
  }

  // Partial Average methods

  size_t create_partial(size_t sum_size) {
    if (sum_size > _array_size) {
      sum_size = _array_size;
    }

    size_t _counter_initial_size = 1;
    _partial_sums_counter++;

    if (_partial_sums_counter > _counter_initial_size) {
      _partial_sums = (TypeOfArray *)realloc(
          _partial_sums, _partial_sums_counter * sizeof(TypeOfArray));
      _partial_sum_sizes = (TypeOfArray *)realloc(
          _partial_sum_sizes, _partial_sums_counter * sizeof(TypeOfArray));
    }

    for (size_t i = 0; i < sum_size; i++) {
      _partial_sums[_partial_sums_counter - 1] += (*this)[i];
    }

    _partial_sum_sizes[_partial_sums_counter - 1] = sum_size;

    return _partial_sums_counter - 1;
  }

  TypeOfArray get_partial(size_t id) {
    if (id > _partial_sums_counter) return 0;

    if (_average_counter >= _partial_sum_sizes[id])
      return _partial_sums[id] / _partial_sum_sizes[id];
    else
      return _partial_sums[id] /
             ((_average_counter == 0) ? 1 : _average_counter);
  }
};

#endif
