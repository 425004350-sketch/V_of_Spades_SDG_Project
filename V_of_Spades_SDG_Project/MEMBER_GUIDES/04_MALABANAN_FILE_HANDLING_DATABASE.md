# Member 4 Work Guide - Malabanan, Justine Lyle R.

## Assigned role

File Handling and Database Developer.

## Files owned

```txt
INPUT_DATA/database.txt
CODE/FoodManager.h
CODE/FoodManager.cpp
```

Malabanan works mainly on loadFromFile() and saveToFile().

## Midterm part kept

The midterm system used hardcoded arrays for food and a two-dimensional array for restaurants.

Final version adjustment:
- Move the data into database.txt.
- Load records automatically when the program starts.
- Save changed records when the program exits.

## Purpose

File handling allows the system to remember records after the program closes.

Without file handling:

```txt
User adds food -> exits program -> added food disappears
```

With file handling:

```txt
User adds food -> exits program -> system saves database.txt -> food remains next run
```

## database.txt format

Use pipe symbol `|` as delimiter.

```txt
id|name|weather|budgetLevel|price|restaurant|healthNote
```

Example:

```txt
1|Halo-Halo|sunny|low|75|Local Dessert Stall|Cold dessert suitable for hot weather
```

Do not put `|` inside food names, restaurant names, or notes.

## Step-by-step work plan

### Step 1 - Prepare database.txt

Must contain at least 20 records. Recommended distribution:

```txt
Sunny: 7 records
Rainy: 7 records
Cold: 6 records
Total: 20 records
```

Each weather category should include low, mid, and high budget options.

### Step 2 - Add loadFromFile() declaration

In FoodManager.h:

```cpp
bool loadFromFile(const string& filename);
```

### Step 3 - Add saveToFile() declaration

In FoodManager.h:

```cpp
bool saveToFile(const string& filename) const;
```

### Step 4 - Implement line splitting

A database line must be split into 7 parts.

Pseudocode:

```txt
Read one line
Split by |
Check if there are exactly 7 parts
Convert part 1 to int id
Convert part 5 to double price
Create FoodItem object
Push to foods vector
```

### Step 5 - Implement loadFromFile()

Pseudocode:

```txt
open file
if file cannot open
    print error
    return false
clear foods vector
while getline(file, line)
    if line is empty, skip
    split line by pipe
    if parts are invalid, skip or report warning
    create FoodItem
    add to foods
close file
print number of records loaded
return true
```

Important safety checks:

```txt
- Empty file should not crash.
- Missing file should show clear error.
- Bad line format should not crash.
- Price conversion errors should be handled.
```

### Step 6 - Implement saveToFile()

Pseudocode:

```txt
open file for writing
if file cannot open
    print error
    return false
for each food in foods
    write food.toFileString()
close file
return true
```

### Step 7 - Test persistence

Test sequence:

```txt
1. Run program.
2. View all records.
3. Add a new food.
4. Save and exit.
5. Reopen program.
6. View all records again.
7. Confirm added food is still there.
```

## Personal file handling flowchart

```txt
PROGRAM START
  |
  v
Open INPUT_DATA/database.txt
  |
  +--> If file missing: show error message
  |
  v
Read one line at a time
  |
  v
Split line using pipe delimiter
  |
  v
Create FoodItem object
  |
  v
Add object to vector
  |
  v
Repeat until end of file
  |
  v
Program runs with loaded records
  |
  v
On exit: open database.txt for writing
  |
  v
Write each FoodItem using toFileString()
  |
  v
END
```

## Example database.txt content

Use the included INPUT_DATA/database.txt file in this workpack.

## Common bugs and fixes

### Bug 1 - Program cannot find database.txt

Cause: wrong relative path.

Fix options:

Option A, run from project root:

```cpp
manager.loadFromFile("INPUT_DATA/database.txt");
```

Option B, run from CODE folder:

```cpp
manager.loadFromFile("../INPUT_DATA/database.txt");
```

Choose one and document it in README.

### Bug 2 - Program reads only first word of restaurant name

Cause: using cin instead of getline.

Fix: use getline for fields with spaces.

### Bug 3 - Bad data line crashes program

Fix: check number of parts before converting.

## Defense questions Malabanan should prepare for

1. Why do we need database.txt?
   - To provide initial records and save changes after the program ends.

2. What is a delimiter?
   - A character used to separate fields in a file. Here, the delimiter is `|`.

3. What is ifstream?
   - It is used for reading files.

4. What is ofstream?
   - It is used for writing files.

5. How do file records become objects?
   - Each valid line is parsed, converted into a FoodItem object, and stored in vector<FoodItem>.

## Testing checklist

- [ ] database.txt has at least 20 valid records.
- [ ] Program loads file automatically.
- [ ] Missing file gives clear error message.
- [ ] Bad line does not crash program.
- [ ] Added records save to file.
- [ ] Updated records save to file.
- [ ] Deleted records are removed from file after exit.
