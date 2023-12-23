#include <MovingAveragePlus.h>
#include <stdio.h>
#include <unity.h>

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_get_average(void) {
  MovingAveragePlus<long int> TestMV(5);

  TestMV.push(2).push(4).push(6);

  TEST_ASSERT_EQUAL(4, TestMV.get());
  TEST_ASSERT_EQUAL(5, TestMV.get_by_brute(2));
}

void test_get_front_n_back_elements(void) {
  MovingAveragePlus<long int> TestMV(5);

  TestMV.push(2).push(4).push(6);

  TEST_ASSERT_EQUAL(6, TestMV.front());
  TEST_ASSERT_EQUAL(2, TestMV.back());
}

void test_get_elements_by_index(void) {
  MovingAveragePlus<long int> TestMV(5);

  TestMV.push(2).push(4).push(6);

  TEST_ASSERT_EQUAL(6, TestMV[0]);
  TEST_ASSERT_EQUAL(4, TestMV[1]);
  TEST_ASSERT_EQUAL(2, TestMV[2]);
  TEST_ASSERT_EQUAL(2, TestMV.at_index(0));
  TEST_ASSERT_EQUAL(4, TestMV.at_index(1));
  TEST_ASSERT_EQUAL(6, TestMV.at_index(2));
}

void test_size_n_resize(void) {
  MovingAveragePlus<long int> TestMV(5);

  TestMV.push(2).push(4).push(6).push(8).push(10).push(12);

  TEST_ASSERT_EQUAL(5, TestMV.size());
  TEST_ASSERT_EQUAL(4, TestMV.back());
  TestMV.resize(10);
  TEST_ASSERT_EQUAL(10, TestMV.size());
}

void test_clear(void) {
  MovingAveragePlus<long int> TestMV(5);

  TestMV.push(2);

  TEST_ASSERT_EQUAL(2, TestMV.get());
  TestMV.clear();
  TEST_ASSERT_EQUAL(0, TestMV.get());
}

void process() {
  UNITY_BEGIN();
  RUN_TEST(test_get_average);
  RUN_TEST(test_get_front_n_back_elements);
  RUN_TEST(test_get_elements_by_index);
  RUN_TEST(test_size_n_resize);
  RUN_TEST(test_clear);

  UNITY_END();
}

#ifdef ARDUINO

#include <Arduino.h>
void setup() {
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  process();
}

void loop() {
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(500);
}

#else

int main(int argc, char **argv) {
  process();
  return 0;
}

#endif