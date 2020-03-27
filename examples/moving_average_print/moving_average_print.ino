// Include lib:
#include <MovingAverage.h>

// Create an Arithmetic Moving Average object of unsigned int type,
// 10 in size
// and initialize it with value 2
MovingAverage<unsigned> test(10, 2);

// This variable just generates input for average test
unsigned delta_x = 0;

void setup() {
  // Initialize serial interface
  Serial.begin(9600);
}

void loop() {
  // Pushes the input in the moving average object
  test.push(delta_x);

  // Generates the next input
  delta_x += 5;
  if (delta_x > 1000) delta_x = 0;

  // Prints each value stored in the moving average
  for (uint8_t i = 0; i < test.size(); i++) {
    Serial.print(test[i]);
    Serial.print(" ");
  }
  // Prints the result of the average
  Serial.print("= ");
  Serial.print(test.get());
  // Prints the value stored in the first and last indexes
  Serial.print(" | f: ");
  Serial.print(test.front());
  Serial.print(" b: ");
  Serial.println(test.back());

  delay(1000);
}
