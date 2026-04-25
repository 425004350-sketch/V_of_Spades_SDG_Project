# Member 1 Work Guide - Alvarez, Jerome Oliver P.

## Assigned role

Main Menu, Program Flow, Display Functions, Switch-Case Controller, and Integration Support.

Important correction: Eurie V. Paulino is the official project lead and GitHub repository owner. Alvarez does not create the repository. Alvarez focuses on keeping the main program flow clean and connected to the other modules.

## Files owned

```txt
CODE/main.cpp
```

## Midterm part kept

This role keeps the same logic as the midterm sections:
- displayHeader()
- displayMenu()
- main() variable initialization
- do-while loop
- switch-case menu handling
- exit flow with summary report

The difference is that main.cpp should not contain all system logic anymore. In the final version, main.cpp calls functions from FoodManager and InputValidator.

## Purpose

main.cpp is the control center. It should not do all the work. It should show the menu, read the user's choice, and call the correct function.

## Step-by-step work plan

### Step 1 - Wait for Paulino to create the repository

Repository name:

```txt
V_of_Spades_SDG_Project
```

Alvarez should not create a second repository. Paulino creates the official repository because he is the project lead.

### Step 2 - Work on the assigned branch

After Paulino creates the repository and invites the members, Alvarez works on the main-menu branch.

### Step 3 - Use these branches

```txt
main
feature/main-menu-integration
feature/food-item-class
feature/crud-manager
feature/file-handling-database
feature/recommendation-validation-report
```

Alvarez should work mainly in:

```txt
feature/main-menu-integration
```

### Step 4 - Create main.cpp skeleton

main.cpp should include:

```cpp
#include <iostream>
#include "FoodManager.h"
#include "InputValidator.h"
using namespace std;
```

Basic structure:

```cpp
int main() {
    FoodManager manager;
    string currentWeather = "";
    int choice = 0;

    manager.loadFromFile("../INPUT_DATA/database.txt");

    do {
        displayHeader();
        displayMenu(currentWeather);
        choice = InputValidator::getIntInRange("Enter choice: ", 1, 12);

        switch (choice) {
            case 1:
                // Ask for weather
                break;
            case 2:
                // View recommendations
                break;
            case 3:
                // Save favorite
                break;
            case 4:
                // View favorites
                break;
            case 5:
                // Find restaurants/budget recommendation
                break;
            case 6:
                // View all records
                break;
            case 7:
                // Search record
                break;
            case 8:
                // Add record
                break;
            case 9:
                // Update record
                break;
            case 10:
                // Delete record
                break;
            case 11:
                // Generate summary
                break;
            case 12:
                manager.saveToFile("../INPUT_DATA/database.txt");
                cout << "Data saved. Thank you for using WEASOLVE.\n";
                break;
        }
    } while (choice != 12);

    return 0;
}
```

### Step 5 - Fill in each switch case

Suggested calls:

```cpp
case 1:
    currentWeather = InputValidator::getWeatherInput();
    break;

case 2:
    manager.recommendByWeather(currentWeather);
    break;

case 3:
    manager.saveFavoriteFood(currentWeather);
    break;

case 4:
    manager.viewFavorites();
    break;

case 5:
    manager.recommendByWeatherAndBudget(currentWeather);
    break;

case 6:
    manager.viewAllFoods();
    break;

case 7:
    manager.searchFood();
    break;

case 8:
    manager.addFood();
    break;

case 9:
    manager.updateFood();
    break;

case 10:
    manager.deleteFood();
    break;

case 11:
    manager.generateSummaryReport(currentWeather);
    break;
```

### Step 6 - Add guard checks

Before options 2, 3, and 5, check if weather is already set.

Example logic:

```cpp
if (currentWeather.empty()) {
    cout << "Please enter weather first.\n";
} else {
    manager.recommendByWeather(currentWeather);
}
```

Purpose: this prevents the system from recommending food with no selected weather.

### Step 7 - Compile the full program

From the project root, use:

```bash
g++ CODE/main.cpp CODE/FoodItem.cpp CODE/FoodManager.cpp CODE/InputValidator.cpp -o weasolve
```

Run:

```bash
./weasolve
```

On Windows with MinGW:

```bash
g++ CODE/main.cpp CODE/FoodItem.cpp CODE/FoodManager.cpp CODE/InputValidator.cpp -o weasolve.exe
weasolve.exe
```

## Personal flowchart

```txt
START
  |
  v
Create FoodManager object
  |
  v
Load database.txt
  |
  v
Display header and menu
  |
  v
Get validated menu choice
  |
  v
Switch(choice)
  |-- 1: get weather
  |-- 2: recommend by weather
  |-- 3: save favorite
  |-- 4: view favorites
  |-- 5: restaurant/budget recommendation
  |-- 6: view all records
  |-- 7: search record
  |-- 8: add record
  |-- 9: update record
  |-- 10: delete record
  |-- 11: summary report
  |-- 12: save file and exit
  |
  v
If choice is not 12, repeat menu
  |
  v
END
```

## Fill-in-the-blanks README section

```md
# WEASOLVE: Weather-Based Food Recommendation System

## SDG Goal
This project supports SDG 3 - Good Health and Well-Being by helping users make food decisions based on weather and budget.

## Group Name
V of Spades

## Contributors
- Paulino, Eurie V. - Official project lead, GitHub, README, recommendation, validation, favorites, report
- Alvarez, Jerome Oliver P. - Main menu, program flow, display functions, switch-case controller, integration support
- Beli, Jhon Rey B. - FoodItem class
- Domingo, Quirc Edrian P. - CRUD manager
- Malabanan, Justine Lyle R. - File handling and database

## How to Compile
```bash
g++ CODE/main.cpp CODE/FoodItem.cpp CODE/FoodManager.cpp CODE/InputValidator.cpp -o weasolve
```

## How to Run
```bash
./weasolve
```
```

## Defense questions Alvarez should prepare for

1. Why is the project divided into multiple files?
   - To separate responsibilities and meet modular software design requirements.

2. Why does main.cpp only call functions instead of containing all logic?
   - To keep main.cpp simple and make each module easier to debug and defend.

3. Why use a do-while loop?
   - Because the menu must display at least once and repeat until the user chooses exit.

4. Why use switch-case?
   - Because each menu choice maps clearly to one system operation.

5. How do you prove each member contributed?
   - Through GitHub commits, branches, pull requests, and assigned files.

## Testing checklist

- [ ] Program starts without crashing.
- [ ] Menu displays correctly.
- [ ] Invalid menu input is rejected.
- [ ] Weather must be entered before recommendation.
- [ ] All 12 menu options call the correct function.
- [ ] Data saves before exit.
- [ ] README is complete.
- [ ] Professor account is invited.
