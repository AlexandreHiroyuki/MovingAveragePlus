# Moving Average Methods

The **MovingAverage** class abstracts the implementation of a circular array in order to calculate the arithmetic average of its members.
Because it is a circular array, the next input will replace the oldest element (represented by the first index), so it is also possible to call it a **FIFO queue**.

If you are used to the C++ Standard Library, it will be easier to learn the methods since they follow the same pattern of name and logic.

# 📌Table of Contents

# 🛠Constructor

---

### 📝Syntax

```cpp
// Passing only size as an argument
MovingAverage<class TypeOfArray> yourAverageName(size_t size);
// Or, also, passing a value to initialize the array
MovingAverage<class TypeOfArray> yourAverageName(size_t size, TypeOfArray initialize);
```

- **Template parameter**.
**TypeOfArray** is the **type of the array elements**.
1. **Passing only size as an argument**.
****The class will create an array with the **size** passed as an argument and, ****by **default**, all positions will **initialize with 0**.
2. **Passing size and initializer value as argument**.
****The class will create an array with the **size** passed as an argument and all positions will **initialize with the initializer value**.

### 🔮Example

```cpp
// This will create an MovingAverage of size 10 and unsigned type
MovingAverage<unsigned int> intAverage(10);
// This will create an MovingAverage of size 15 and double type,
// then initialize all elements with 0.5
MovingAverage<double> floatingAverage(15, 0.5);
```

### ⏱Complexity

If the **option "1."** is used, the complexity will be **constant (O(1))**.
Although, if using the **option "2."**, complexity will be **linear (O(n))** in the **array size** passed as an argument.

# 🔗Get Result and Access elements

---

## 📥Push

---

**Inserts** a **new element** in the internal array and **returns** a pointer.
*Methods that **return pointers** allow **chained calls**.*

```cpp
MovingAverage<unsigned int> intAverage(10);

unsigned int x = 5, y = 10;
unsigned int result, first, last;

result = intAverage.push(x).push(y).get();
first = intAverage.push(56).front();
last = intAverage.push(8).back();
```

### 📝Syntax

```cpp
MovingAverage<TypeOfArray> &push(TypeOfArray input)
```

- **Inserts** the **input** of type **TypeOfArray** at the end of the **array**.

### 🔮Example

```cpp
// This will create an MovingAverage of size 5 and unsigned type
// Array: 0 0 0 0 0
MovingAverage<unsigned int> intAverage(5);

// Array: 6 0 0 0 0
intAverage.push(6);

// Array: 1 6 0 0 0
// Array: 2 1 6 0 0
// Array: 3 2 1 6 0
// Array: 4 3 2 1 6
for(int i = 1; i < 5; i++){
	intAverage.push(i);
}

// Array: 21 1 2 3 4
intAverage.push(21);
```

### ⏱Complexity

**Constant (O(1))**.

## 📤Get

---

**Returns** the **current** moving average **value**.

### 📝Syntax

```cpp
TypeOfArray get()
```

### 🔮Example

```cpp
// This will create an MovingAverage of size 4 and int type
// Array: 2 2 2 2
MovingAverage<int> intAverage(4, 2);

// Array: 8 2 2 2
intAverage.push(8);
// Array: 8 8 2 2
intAverage.push(8);

// Returns the average
// Value: (8 + 8 + 2 + 2) / 4 = 5
intAverage.get();
```

### ⏱Complexity

**Constant (O(1))**.

## ➡️Front

---

**Returns** the first element of the **array** (the most recent element added).

### 📝Syntax

```cpp
TypeOfArray front()
```

### 🔮Example

```cpp
// This will create an MovingAverage of size 4 and int type
// Array: 2 2 2 2
MovingAverage<int> intAverage(4, 2);

// Will return 2
intAverage.front();

// Array: 8 2 2 2
intAverage.push(8);

// Will return 8
intAverage.front();
```

### ⏱Complexity

**Constant (O(1))**.

## ⬅️Back

---

**Returns** the last element of the **array** (the oldest element added).

### 📝Syntax

```cpp
TypeOfArray back()
```

### 🔮Example

```cpp
// This will create an MovingAverage of size 4 and int type
// Array: 2 2 2 2
MovingAverage<int> intAverage(4, 2);

// Will return 2
intAverage.back();

// Array: 8 2 2 2
intAverage.push(8);
// Array: 7 8 2 2
intAverage.push(7);
// Array: 12 7 8 2
intAverage.push(12);
// Array: 1 12 7 8
intAverage.push(1);

// Will return 8
intAverage.back();
```

### ⏱Complexity

**Constant (O(1))**.

## 📍Operator[]

---

**Returns** the requested element at the **relative** position of the **array**.

### 📝Syntax

```cpp
TypeOfArray operator[](int index)
```

### 🔮Example

```cpp

```

### ⏱Complexity

**Constant (O(1))**.

## 📍AtIndex

---

**Returns** the requested element at the **absolute** position of the **array**.

### 📝Syntax

```cpp
TypeOfArray atIndex(size_t index)
```

### 🔮Example

```cpp

```

### ⏱Complexity

**Constant (O(1))**.

## 📏Size

---

**Returns** the **size** of the **array**.

### 📝Syntax

```cpp
size_t size()
```

### 🔮Example

```cpp

```

### ⏱Complexity

**Constant (O(1))**.

# 🔏Modify Array

---

## 📐Resize

---

*Methods that **return pointers** allow **chained calls**.*

```cpp
MovingAverage<unsigned int> intAverage(10);

unsigned int x = 5, y = 10;
unsigned int result, first, last;

result = intAverage.push(x).push(y).get();
first = intAverage.push(56).front();
last = intAverage.push(8).back();
```

### 📝Syntax

```cpp
MovingAverage<TypeOfArray> &resize(size_t new_size)
```

### 🔮Example

```cpp

```

### ⏱Complexity

**Linear (O(n))**.

## 💣Reset

---

*Methods that **return pointers** allow **chained calls**.*

```cpp
MovingAverage<unsigned int> intAverage(10);

unsigned int x = 5, y = 10;
unsigned int result, first, last;

result = intAverage.push(x).push(y).get();
first = intAverage.push(56).front();
last = intAverage.push(8).back();
```

### 📝Syntax

```cpp
MovingAverage<TypeOfArray> &reset()
```

### 🔮Example

```cpp

```

### ⏱Complexity

**Linear (O(n))**.

## 🧹Clear

---

*Methods that **return pointers** allow **chained calls**.*

```cpp

```

### 📝Syntax

```cpp
MovingAverage<TypeOfArray> &clear()
```

### 🔮Example

```cpp

```

### ⏱Complexity

**Linear (O(n))**.

## 🌊Fill

---

**Fills and overwrites** the array with the received element.
*Methods that **return pointers** allow **chained calls**.*

```cpp
MovingAverage<unsigned int> intAverage(10);

unsigned int x = 5, y = 10;
unsigned int result, first, last;

result = intAverage.push(x).push(y).get();
first = intAverage.push(56).front();
last = intAverage.push(8).back();
```

### 📝Syntax

```cpp
MovingAverage<TypeOfArray> &fill(TypeOfArray fill_value)
```

### 🔮Example

```cpp
// 0 0 0 0 0
MovingAverage<unsigned int> intAverage(5);

// 1 2 3 4 0
intAverage.push(1).push(2).push(3).push(4)

// 10 10 10 10 10
intAverage.fill(10)
```

### ⏱Complexity

**Linear (O(n))**.

[Moving Average Lib for Arduino Docs](../Moving%20Average%20Lib%20for%20Arduino%20Docs%20462e9a5d4e6d4660b67d8e8f124d851e.md)