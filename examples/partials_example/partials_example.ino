// Include lib:
#include <MovingAveragePlus.h>

// Create an Arithmetic Moving Average object of unsigned int type,
// 10 in size
MovingAveragePlus<unsigned> integer_mv(10);

// This variable just generates input for average integer_mv
unsigned delta_x = 0;

// These variables are the identification of the integer_mv partials
size_t integer_mv_partial_id = 0;
size_t integer_mv_partial_id_2 = 0;

void setup() {
  // Initialize serial interface
  Serial.begin(9600);

  integer_mv_partial_id = integer_mv.create_partial(3);
  integer_mv_partial_id_2 = integer_mv.create_partial(5);
}

void loop() {
  // Pushes the input in the moving average object
  integer_mv.push(delta_x);

  // Generates the next input
  delta_x += 5;
  if (delta_x > 1000) delta_x = 0;

  // Prints each value stored in the moving average
  for (uint8_t i = 0; i < integer_mv.size(); i++) {
    Serial.print(integer_mv[i]);
    Serial.print(" ");
  }
  // Prints the result of the average
  Serial.print("= ");
  Serial.print(integer_mv.get());
  // Prints the value stored in the partials
  Serial.print(" | p(3): ");
  Serial.print(integer_mv.get_partial(integer_mv_partial_id));
  Serial.print(" p(5): ");
  Serial.println(integer_mv.get_partial(integer_mv_partial_id_2));

  delay(1000);
}
