/***************************************************************
  ArithmeticMovingAverage.h - Arithmetic moving average structure manager.
  Created by Alexandre Hiroyuki Yamauchi, September 2, 2019.
***************************************************************/
#ifndef ARITHMETIC_MA_H
#define ARITHMETIC_MA_H

#include <Arduino.h>

template <class TypeOfArray>
class ArithmeticMA
{
private:
  size_t _array_size;
  TypeOfArray *_array;

  size_t _current_index;
  TypeOfArray _average_sum;

  TypeOfArray _initial_value;

  void _nextIndex();

public:
  ArithmeticMA(size_t size);
  ArithmeticMA(size_t size, TypeOfArray initialize);

  ArithmeticMA<TypeOfArray> &push(TypeOfArray input);
  TypeOfArray get();

  TypeOfArray front();
  TypeOfArray back();

  TypeOfArray atIndex(size_t index);
  size_t size();

  ArithmeticMA<TypeOfArray> &resize(size_t new_size);
  ArithmeticMA<TypeOfArray> &reset();
  ArithmeticMA<TypeOfArray> &clear();
  ArithmeticMA<TypeOfArray> &fill(TypeOfArray fill_value);
};

//////// Private ////////
template <class TypeOfArray>
void ArithmeticMA<TypeOfArray>::_nextIndex()
{
  _current_index++;
  if (_current_index >= _array_size)
    _current_index = 0;
}

//////// Public ////////
template <class TypeOfArray>
ArithmeticMA<TypeOfArray>::ArithmeticMA(size_t size)
    : _array_size(size),
      _current_index(0),
      _array((TypeOfArray *)calloc(size, sizeof(TypeOfArray))),
      _average_sum(0),
      _initial_value(0)
{
  for (size_t i = 0; i < size; i++)
    _array[i] = 0;
}
template <class TypeOfArray>
ArithmeticMA<TypeOfArray>::ArithmeticMA(size_t size, TypeOfArray initialize)
    : _array_size(size),
      _current_index(0),
      _array((TypeOfArray *)calloc(size, sizeof(TypeOfArray))),
      _average_sum(initialize * size),
      _initial_value(initialize)
{
  for (size_t i = 0; i < size; i++)
    _array[i] = initialize;
}

template <class TypeOfArray>
ArithmeticMA<TypeOfArray> &ArithmeticMA<TypeOfArray>::push(TypeOfArray input)
{
  _average_sum -= _array[_current_index];

  _array[_current_index] = input;

  _average_sum += _array[_current_index];

  _nextIndex();

  return *this;
}

template <class TypeOfArray>
TypeOfArray ArithmeticMA<TypeOfArray>::get()
{
  return (_average_sum / _array_size);
}

template <class TypeOfArray>
TypeOfArray ArithmeticMA<TypeOfArray>::front()
{
  int last_index = _current_index;

  if (last_index - 1 < 0)
  {
    last_index = _array_size - 1;
  }
  else
  {
    last_index -= 1;
  }

  return _array[last_index];
}

template <class TypeOfArray>
TypeOfArray ArithmeticMA<TypeOfArray>::back()
{
  return _array[_current_index];
}

template <class TypeOfArray>
TypeOfArray ArithmeticMA<TypeOfArray>::atIndex(size_t index)
{
  return _array[index];
}

template <class TypeOfArray>
unsigned int ArithmeticMA<TypeOfArray>::size()
{
  return _array_size;
}

template <class TypeOfArray>
ArithmeticMA<TypeOfArray> &ArithmeticMA<TypeOfArray>::resize(size_t new_size)
{
  _array_size = new_size;
  _array = realloc(_array, new_size * sizeof(TypeOfArray));

  return *this;
}

template <class TypeOfArray>
ArithmeticMA<TypeOfArray> &ArithmeticMA<TypeOfArray>::reset()
{
  for (size_t i = 0; i < _array_size; i++)
  {
    _array[i] = _initial_value;
  }

  _average_sum = _initial_value * _array_size;

  return *this;
}

template <class TypeOfArray>
ArithmeticMA<TypeOfArray> &ArithmeticMA<TypeOfArray>::clear()
{
  _array[_current_index] = 0;

  _average_sum = 0;

  return *this;
}

template <class TypeOfArray>
ArithmeticMA<TypeOfArray> &ArithmeticMA<TypeOfArray>::fill(TypeOfArray fill_value)
{
  for (size_t i = 0; i < _array_size; i++)
  {
    _array[i] = fill_value;
  }

  _average_sum = fill_value * _array_size;

  return *this;
}

#endif
