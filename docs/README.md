# Moving Average Lib for Arduino Docs

---

[AlexandreHiroyuki/MovingAverage_ArduinoLibrary](https://github.com/AlexandreHiroyuki/MovingAverage_ArduinoLibrary)

# 📌Table of Contents

---

# 💾Installation

---

1. Clone the repository and download the zip file at [https://github.com/AlexandreHiroyuki/MovingAverage_ArduinoLibrary](https://github.com/AlexandreHiroyuki/MovingAverage_ArduinoLibrary).
   Also, you can see and download all releases at [https://github.com/AlexandreHiroyuki/MovingAverage_ArduinoLibrary/releases](https://github.com/AlexandreHiroyuki/MovingAverage_ArduinoLibrary/releases).
2. Drag and drop it on `Arduino/libraries/` folder.
3. Include it on your code.

   ```cpp
   #include <MovingAverage.h>
   ```

- You can also download and install the library through the official library manager on the Arduino IDE.
  Access \*\*\*\*[https://www.arduino.cc/en/guide/libraries](https://www.arduino.cc/en/guide/libraries) to see more details about installing libraries on Arduino IDE.

[Arduino - Libraries](https://www.arduino.cc/en/guide/libraries)

- Another site that lists Arduino libraries accepted by the official library manager [https://www.arduinolibraries.info/libraries/moving-average-library](https://www.arduinolibraries.info/libraries/moving-average-library).

[Moving Average Library](https://www.arduinolibraries.info/libraries/moving-average-library)

# 💡Getting Started

---

1. You can easily try out the library by running the example code.
2. Just open the subfolder `MovingAverage_ArduinoLibrary/examples/`.
3. Then try compiling the `moving_average_print.ino`.
4. Open the serial monitor.
5. Then see the array magically moving and calculating it average!

# 📦Moving Average Methods

---

The **MovingAverage** class abstracts the implementation of a circular array in order to calculate the arithmetic average of its members.
Because it is a circular array, the next input will replace the oldest element (represented by the first index), so it is also possible to call it a **FIFO queue**.

If you are used to the C++ Standard Library, it will be easier to learn the methods since they follow the same pattern of name and logic.

_Click on the link below to see more about the class methods._

[Moving Average Methods](Moving%20Average%20Lib%20for%20Arduino%20Docs%20462e9a5d4e6d4660b67d8e8f124d851e/Moving%20Average%20Methods%20a3c6fe04dd90476c988789586ba730ee.md)
