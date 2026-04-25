# Member 2 Work Guide - Beli, Jhon Rey B.

## Assigned role

FoodItem Class Developer.

## Files owned

```txt
CODE/FoodItem.h
CODE/FoodItem.cpp
```

## Midterm part kept

The midterm system stored food recommendations in separate arrays for sunny, rainy, and cold weather.

Final version adjustment:
- Instead of plain strings in arrays, each food becomes a FoodItem object.
- The weather category is still sunny, rainy, or cold.
- The recommendation logic still uses weather, but now it checks the object's weather field.

## Purpose

FoodItem represents one food record. It is the primary class of the system.

One FoodItem contains:

```txt
ID
Food name
Weather category
Budget level
Price
Restaurant
Health note
```

## Step-by-step work plan

### Step 1 - Create FoodItem.h

FoodItem.h contains the declaration. Declaration means the class name, fields, and function names.

Template:

```cpp
#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>
using namespace std;

class FoodItem {
private:
    int id;
    string name;
    string weather;
    string budgetLevel;
    double price;
    string restaurant;
    string healthNote;

public:
    FoodItem();
    FoodItem(int id, string name, string weather, string budgetLevel,
             double price, string restaurant, string healthNote);

    int getId() const;
    string getName() const;
    string getWeather() const;
    string getBudgetLevel() const;
    double getPrice() const;
    string getRestaurant() const;
    string getHealthNote() const;

    void setName(string name);
    void setWeather(string weather);
    void setBudgetLevel(string budgetLevel);
    void setPrice(double price);
    void setRestaurant(string restaurant);
    void setHealthNote(string healthNote);

    void display() const;
    string toFileString() const;
};

#endif
```

### Step 2 - Create FoodItem.cpp

FoodItem.cpp contains the implementation. Implementation means the actual body of each function.

Example pattern:

```cpp
#include "FoodItem.h"
#include <iostream>
#include <sstream>
using namespace std;

FoodItem::FoodItem() {
    id = 0;
    name = "";
    weather = "";
    budgetLevel = "";
    price = 0.0;
    restaurant = "";
    healthNote = "";
}
```

Constructor with values:

```cpp
FoodItem::FoodItem(int id, string name, string weather, string budgetLevel,
                   double price, string restaurant, string healthNote) {
    this->id = id;
    this->name = name;
    this->weather = weather;
    this->budgetLevel = budgetLevel;
    this->price = price;
    this->restaurant = restaurant;
    this->healthNote = healthNote;
}
```

Getter example:

```cpp
int FoodItem::getId() const {
    return id;
}
```

Setter example:

```cpp
void FoodItem::setName(string name) {
    this->name = name;
}
```

Display example:

```cpp
void FoodItem::display() const {
    cout << "ID: " << id << endl;
    cout << "Food: " << name << endl;
    cout << "Weather: " << weather << endl;
    cout << "Budget Level: " << budgetLevel << endl;
    cout << "Price: PHP " << price << endl;
    cout << "Restaurant: " << restaurant << endl;
    cout << "Health Note: " << healthNote << endl;
}
```

File string example:

```cpp
string FoodItem::toFileString() const {
    stringstream ss;
    ss << id << "|" << name << "|" << weather << "|" << budgetLevel
       << "|" << price << "|" << restaurant << "|" << healthNote;
    return ss.str();
}
```

## Why private variables are required

Private variables support encapsulation. Encapsulation means the data is protected inside the class and can only be accessed through public functions.

Bad final design:

```cpp
food.name = "Sinigang";
```

Better final design:

```cpp
food.setName("Sinigang");
```

Reason: setters can later add validation before accepting changes.

## Personal flowchart

```txt
START
  |
  v
FoodItem object is created
  |
  v
Constructor assigns id, name, weather, budget, price, restaurant, note
  |
  v
Other modules access data using getters
  |
  v
Other modules edit data using setters
  |
  v
FoodItem displays itself or converts itself to file format
  |
  v
END
```

## Fill-in-the-blanks class comment

Add this before the class declaration:

```cpp
/*
 * Class Name: FoodItem
 * Purpose: Represents one food recommendation record in WEASOLVE.
 * Data Stored: id, name, weather, budget level, price, restaurant, health note.
 * Used By: FoodManager for CRUD, recommendations, file loading, and saving.
 */
```

## Defense questions Beli should prepare for

1. What is a class?
   - A class is a blueprint for creating objects.

2. What is an object?
   - An object is an actual item created from a class, such as one food record.

3. Why are the attributes private?
   - To protect the data and apply encapsulation.

4. What is a constructor?
   - A function automatically called when an object is created.

5. Why do we need getters and setters?
   - Getters read private data. Setters update private data safely.

6. What does toFileString() do?
   - It converts one FoodItem object into one line that can be saved in database.txt.

## Testing checklist

- [ ] FoodItem.h compiles.
- [ ] FoodItem.cpp compiles.
- [ ] Constructor assigns correct values.
- [ ] Getters return correct data.
- [ ] Setters update correct data.
- [ ] display() prints all fields.
- [ ] toFileString() uses the exact pipe-delimited format.
