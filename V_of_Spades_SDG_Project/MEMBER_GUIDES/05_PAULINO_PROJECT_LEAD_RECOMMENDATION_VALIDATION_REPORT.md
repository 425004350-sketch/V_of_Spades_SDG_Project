# Member 5 Work Guide - Paulino, Eurie V. - Official Project Lead

## Assigned role

Official Project Lead, GitHub Repository Owner, README Coordinator, Recommendation, Input Validation, Favorites, and Summary Report Developer.

## Files owned

```txt
README.md
GITHUB_SETUP.md
CODE/InputValidator.h
CODE/InputValidator.cpp
CODE/FoodManager.h
CODE/FoodManager.cpp
```

Paulino works on two responsibilities: leadership/admin work and the original midterm-based validation/recommendation logic. The leadership part means creating the GitHub repository, inviting members, coordinating pull requests, and keeping the README updated. The coding part means validation, recommendations, favorites, and summary reports.

## Midterm part kept

This role keeps the most midterm logic:
- getWeather()
- generateFood()
- saveFavoriteFood()
- savedLastFood()
- viewFavoriteFood()
- restaurantRecommendation()
- generateFavoriteStats()
- getValidatedChoice()
- validateInput()
- validateWeather()
- validateBudget()

Final version adjustment:
- Food recommendations come from vector<FoodItem>, not fixed arrays.
- Favorites store FoodItem objects, not just strings.
- Budget can still use low/mid/high, but a price filter can make the logic stronger.

## Purpose

This module makes the system useful, not just a data storage program.

Value-added logic:

```txt
Input weather + budget/price limit -> filter records -> show appropriate food recommendations
```

This supports the final requirement that the system must process data, not only store it.

## Step-by-step work plan

### Leadership Step 1 - Create the official GitHub repository

Repository name:

```txt
V_of_Spades_SDG_Project
```

Purpose: this becomes the single official repository for the group. Do not let another member create a separate final repository because the final instructions say only the project lead creates the repository.

### Leadership Step 2 - Upload the starting folder structure

Upload these folders and files first:

```txt
.gitignore
README.md
CODE/
INPUT_DATA/
DOCUMENTATION/
```

### Leadership Step 3 - Invite collaborators

Invite all members and the required professor account:

```txt
Alvarez, Jerome Oliver P.
Beli, Jhon Rey B.
Domingo, Quirc Edrian P.
Malabanan, Justine Lyle R.
jlrn-rph
```

### Leadership Step 4 - Assign branches

```txt
Alvarez  -> feature/main-menu-integration
Beli     -> feature/food-item-class
Domingo  -> feature/crud-manager
Malabanan-> feature/file-handling-database
Paulino  -> feature/recommendation-validation-report
```

### Leadership Step 5 - Review before merging

Before merging any branch into main, check:

```txt
1. The code compiles.
2. The feature works.
3. The member committed their own work.
4. The README still matches the final system.
```

## Coding work plan

### Step 1 - Create InputValidator.h

```cpp
#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>
using namespace std;

class InputValidator {
public:
    static int getIntInRange(string prompt, int min, int max);
    static double getPositiveDouble(string prompt);
    static string getWeatherInput();
    static string getBudgetInput();
    static string getYesNoInput(string prompt);
    static string toLowerCase(string text);
};

#endif
```

### Step 2 - Implement getIntInRange()

Purpose: prevent type mismatch errors.

Type mismatch example:

```txt
Program expects number.
User enters abc.
Without validation, cin fails and menu can loop forever or crash logically.
```

Pseudocode:

```txt
repeat
    show prompt
    if input is a number and between min and max
        return number
    else
        clear error
        discard bad input
        show error message
```

### Step 3 - Implement getWeatherInput()

Accepted values only:

```txt
sunny
rainy
cold
```

Pseudocode:

```txt
repeat
    ask weather
    convert to lowercase
    if weather is sunny, rainy, or cold
        return weather
    else
        show error
```

### Step 4 - Implement getBudgetInput()

Accepted values only:

```txt
low
mid
high
```

Pseudocode:

```txt
repeat
    ask budget
    convert to lowercase
    if budget is low, mid, or high
        return budget
    else
        show error
```

### Step 5 - Implement recommendByWeather()

This is the final version of generateFood().

Pseudocode:

```txt
if weather is empty
    print "Please enter weather first."
    return

found = false
for each food in foods
    if food.weather equals selected weather
        display food
        found = true

if found is false
    print "No recommendations found."
```

### Step 6 - Implement recommendByWeatherAndBudget()

This is the final version of restaurantRecommendation().

Simple version:

```txt
Ask budget level low/mid/high
Show foods where food.weather == currentWeather AND food.budgetLevel == budget
```

Better value-added version:

```txt
Ask budget level low/mid/high
Ask actual money available
Show foods where:
    weather matches currentWeather
    budgetLevel matches selected budget
    price <= money available
```

Recommended final implementation:

Use both budget level and price limit. This makes the system more useful for students.

Pseudocode:

```txt
budget = getBudgetInput()
money = getPositiveDouble("Enter your available money: PHP ")

found = false
for each food in foods
    if food.weather == currentWeather AND food.budgetLevel == budget AND food.price <= money
        display food
        found = true

if no result
    print helpful message
```

### Step 7 - Implement saveFavoriteFood()

This is the final version of saveFavoriteFood().

Pseudocode:

```txt
Display recommendations for current weather with numbers
Ask user to choose a number
If valid, add selected FoodItem to favorites vector
Print success message
```

Important:
- Do not save favorites if weather is not set.
- Do not save out-of-range choices.
- Do not crash if there are no recommendations.

### Step 8 - Implement viewFavorites()

Pseudocode:

```txt
if favorites is empty
    print "No favorite foods saved yet."
else
    loop through favorites
    display each favorite
```

### Step 9 - Implement generateSummaryReport()

Suggested report content:

```txt
Total food records loaded
Total favorites saved
Current weather
Number of favorites matching current weather
Number of sunny foods in database
Number of rainy foods in database
Number of cold foods in database
Most budget-friendly recommendation under current weather
```

Pseudocode for weather count:

```txt
sunnyCount = 0
rainyCount = 0
coldCount = 0

for each food in foods
    if weather == sunny, sunnyCount++
    if weather == rainy, rainyCount++
    if weather == cold, coldCount++
```

## Personal recommendation flowchart

```txt
START RECOMMENDATION
  |
  v
Check if current weather is set
  |
  +--> No: show "Please enter weather first" -> return to menu
  |
  v
Ask budget level or money if needed
  |
  v
Loop through vector<FoodItem>
  |
  v
Check weather match
  |
  v
Check budget/price match
  |
  v
Display matching foods
  |
  v
Ask if user wants to save favorite
  |
  v
Store selected FoodItem in favorites vector
  |
  v
Return to menu
```

## Personal validation flowchart

```txt
START INPUT VALIDATION
  |
  v
Ask user for input
  |
  v
Is input type correct?
  |-- No: clear cin, discard bad input, show error, ask again
  |
  v
Is input within allowed values/range?
  |-- No: show error, ask again
  |
  v
Return valid input
  |
  v
END
```

## Common bugs and fixes

### Bug 1 - Weather input accepts "Sunny" but not "sunny"

Fix: convert input to lowercase before checking.

### Bug 2 - Menu repeats forever after typing letters

Fix: clear cin fail state and discard the invalid line.

### Bug 3 - Favorite saves wrong food

Cause: using displayed number incorrectly.

Fix: create a temporary vector of matching recommendations, then save from that vector.

Example:

```cpp
vector<FoodItem> matches;
for (FoodItem food : foods) {
    if (food.getWeather() == currentWeather) {
        matches.push_back(food);
    }
}
```

Then user choice 1 means:

```cpp
favorites.push_back(matches[choice - 1]);
```

## Defense questions Paulino should prepare for

1. Why do we validate input?
   - To prevent crashes, wrong data, and infinite loops.

2. Why only accept sunny, rainy, and cold?
   - Those are the final approved weather categories of the project.

3. How does recommendation work?
   - It filters FoodItem objects based on weather, budget level, and price.

4. Why is this value-added logic?
   - The system processes user conditions and records to produce personalized recommendations.

5. Why use vector for favorites?
   - It can grow dynamically and does not require a fixed maximum size.

## Testing checklist

- [ ] Letters in menu do not crash program.
- [ ] Out-of-range numbers are rejected.
- [ ] Weather accepts only sunny, rainy, cold.
- [ ] Budget accepts only low, mid, high.
- [ ] Recommendation shows only selected weather.
- [ ] Budget recommendation filters by budget level.
- [ ] Price filter works if implemented.
- [ ] Favorite saving works.
- [ ] View favorites handles empty list.
- [ ] Summary report displays correct counts.
