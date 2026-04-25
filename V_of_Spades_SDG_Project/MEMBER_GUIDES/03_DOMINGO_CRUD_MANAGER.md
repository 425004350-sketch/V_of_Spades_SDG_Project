# Member 3 Work Guide - Domingo, Quirc Edrian P.

## Assigned role

CRUD Manager Developer.

## Files owned

```txt
CODE/FoodManager.h
CODE/FoodManager.cpp
```

Domingo works mainly on CRUD functions inside FoodManager.

## Midterm part kept

The midterm system already displayed recommendations, saved favorites, and used loops to traverse arrays.

Final version adjustment:
- Instead of looping through fixed arrays, loop through vector<FoodItem>.
- Add full record management: create, read, update, delete.
- Use the same idea of checking valid choices, but now apply it to record IDs and fields.

## Purpose

CRUD means:

```txt
C - Create/Add new record
R - Read/View or Search records
U - Update/Edit existing record
D - Delete/Remove existing record
```

CRUD is required because the final rubric asks for secure record management.

## Required FoodManager data

Inside FoodManager.h:

```cpp
#include <vector>
#include "FoodItem.h"

class FoodManager {
private:
    vector<FoodItem> foods;
    vector<FoodItem> favorites;

    int findIndexById(int id) const;
    int generateNextId() const;

public:
    void viewAllFoods() const;
    void searchFood() const;
    void addFood();
    void updateFood();
    void deleteFood();
};
```

## Step-by-step work plan

### Step 1 - Implement findIndexById()

Purpose: find where a food record is stored in the vector.

Pseudocode:

```txt
function findIndexById(id)
    for each food in foods
        if food id equals target id
            return index
    return -1
```

C++ pattern:

```cpp
int FoodManager::findIndexById(int id) const {
    for (int i = 0; i < foods.size(); i++) {
        if (foods[i].getId() == id) {
            return i;
        }
    }
    return -1;
}
```

### Step 2 - Implement viewAllFoods()

Purpose: show all records loaded from database.txt.

Pseudocode:

```txt
if foods is empty
    print "No food records available."
else
    for each food in foods
        display food
```

### Step 3 - Implement searchFood()

Allow two search modes:

```txt
[1] Search by ID
[2] Search by Name
```

Search by ID:

```txt
Ask ID
Call findIndexById(ID)
If result is -1, show not found
Else display record
```

Search by name:

```txt
Ask keyword
Convert keyword to lowercase
Loop through foods
If food name contains keyword, display it
If no match, show not found
```

### Step 4 - Implement addFood()

Add should ask for all FoodItem attributes except ID. The system should generate the ID automatically.

Input fields:

```txt
Food name:
Weather: sunny/rainy/cold
Budget level: low/mid/high
Price:
Restaurant:
Health note:
```

Pseudocode:

```txt
newId = generateNextId()
Ask name
Ask weather and validate
Ask budget and validate
Ask price and validate
Ask restaurant
Ask health note
Create FoodItem object
Push object into foods vector
Print success message
```

### Step 5 - Implement updateFood()

Do not force the user to retype the entire record. Let them choose which field to update.

Menu:

```txt
[1] Name
[2] Weather
[3] Budget Level
[4] Price
[5] Restaurant
[6] Health Note
[7] Cancel
```

Pseudocode:

```txt
Ask ID
index = findIndexById(ID)
if index == -1
    print "Record not found."
else
    display current record
    ask field to update
    ask new value
    use setter to update selected field
    print success message
```

### Step 6 - Implement deleteFood()

Important: Ask for confirmation before deleting.

Pseudocode:

```txt
Ask ID
index = findIndexById(ID)
if index == -1
    print "Record not found."
else
    display record
    ask "Are you sure? yes/no"
    if yes
        foods.erase(foods.begin() + index)
        print "Deleted successfully."
    else
        print "Delete cancelled."
```

C++ erase pattern:

```cpp
foods.erase(foods.begin() + index);
```

## Personal CRUD flowchart

```txt
START CRUD OPERATION
  |
  v
User selects Add, View, Search, Update, or Delete
  |
  +--> Add: collect inputs -> validate -> create FoodItem -> push_back
  |
  +--> View: loop through vector -> display records
  |
  +--> Search: ask ID/name -> find matching records -> display result
  |
  +--> Update: ask ID -> find index -> choose field -> setter updates value
  |
  +--> Delete: ask ID -> find index -> confirm -> erase from vector
  |
  v
Return to main menu
```

## Common bugs and fixes

### Bug 1 - Delete removes wrong item

Cause: using ID as vector index.

Wrong:

```cpp
foods.erase(foods.begin() + id);
```

Correct:

```cpp
int index = findIndexById(id);
foods.erase(foods.begin() + index);
```

Reason: ID is not always equal to vector position.

### Bug 2 - Search by name fails because of uppercase/lowercase

Fix: convert both the search keyword and food name to lowercase before comparing.

### Bug 3 - Program crashes after invalid price input

Fix: use InputValidator instead of direct cin for numeric input.

## Defense questions Domingo should prepare for

1. What is CRUD?
   - Create, Read, Update, Delete.

2. Why use vector instead of fixed array?
   - vector can grow and shrink, making add and delete easier.

3. How does delete work?
   - Find the vector index, then erase that element.

4. Why do you use findIndexById()?
   - To avoid repeating ID search logic in update, delete, and search.

5. What happens if the ID does not exist?
   - The function returns -1 and the program shows an error message.

## Testing checklist

- [ ] View all shows records.
- [ ] Search by existing ID works.
- [ ] Search by missing ID shows error.
- [ ] Search by name works with lowercase and uppercase.
- [ ] Add creates new record.
- [ ] Update changes only selected field.
- [ ] Delete asks for confirmation.
- [ ] Delete actually removes record from active session.
- [ ] Invalid ID input does not crash program.
