# WEASOLVE Finals Blueprint - V of Spades

## 1. Main decision

The final project will keep the midterm idea and menu behavior, but upgrade the internal structure to satisfy the final C++ requirements.

Midterm concept kept:
- User enters weather.
- Accepted weather values remain: sunny, rainy, cold.
- System recommends food based on weather.
- User can save and view favorite foods.
- System suggests restaurants based on weather and budget.
- System produces a summary report.
- System validates invalid input.

Final upgrade:
- Convert the single-file/procedural style into a multi-file OOP C++ project.
- Replace hardcoded food arrays with FoodItem objects loaded from INPUT_DATA/database.txt.
- Add CRUD: create, read, update, delete food records.
- Save updates back to the file on clean exit.
- Use GitHub branches and commits per member.

## 2. Final menu

Keep the first five options close to the midterm version. Add CRUD and saving features after that.

```txt
================ WEASOLVE ================
Weather-Based Food Recommendation System
SDG 3 - Good Health and Well-Being
Current Weather: [not set / sunny / rainy / cold]

[1] Enter Current Weather
[2] View Food Recommendations
[3] Save Favorite Food
[4] View Favorite Foods
[5] Find Restaurants / Budget Recommendation
[6] View All Food Records
[7] Search Food Record
[8] Add New Food Record
[9] Update Food Record
[10] Delete Food Record
[11] Generate Summary Report
[12] Save and Exit
==========================================
Enter choice: 
```

## 3. Data model

Each food item is one object.

```txt
id|name|weather|budgetLevel|price|restaurant|healthNote
```

Example:

```txt
1|Halo-Halo|sunny|low|75|Local Dessert Stall|Cold dessert suitable for hot weather
```

## 4. Mapping from midterm to final

| Midterm part | Final version | Assigned member | Reason |
|---|---|---|---|
| displayHeader() | Same function idea, now in main.cpp or UI helper | Alvarez | Keeps project identity and SDG label visible |
| displayMenu() | Same menu idea, expanded to 12 choices | Alvarez | Required looped menu system |
| getWeather() | Same logic, moved to InputValidator or FoodManager workflow | Paulino | Keeps sunny/rainy/cold validation |
| Weather food arrays | Replaced by database.txt records and vector<FoodItem> | Beli + Malabanan | Meets OOP and file handling |
| generateFood() | recommendByWeather() filters vector by weather | Paulino | Same recommendation idea, stronger implementation |
| saveFavoriteFood() | saveFavoriteFood() stores selected FoodItem in favorites vector | Paulino | Same feature, upgraded data structure |
| viewFavoriteFood() | viewFavorites() displays favorite FoodItem objects | Paulino | Same feature, object-based display |
| restaurantRecommendation() | recommendByBudget() filters by weather, budget, and price | Paulino | Same feature, more useful result |
| generateFavoriteStats() | generateSummaryReport() counts favorites and recommendations | Paulino | Same report idea, more detailed |
| getValidatedChoice() | InputValidator::getIntInRange() | Paulino | Prevents crashes and bad input |
| Hardcoded arrays | loadFromFile() and saveToFile() | Malabanan | Required persistent storage |
| No CRUD in midterm | addFood(), searchFood(), updateFood(), deleteFood() | Domingo | Required final feature |

## 5. Member assignment summary

Important correction: Eurie V. Paulino is the official project lead. Alvarez still handles the main-menu/program-flow module, but Paulino creates and manages the GitHub repository because the final-project instructions say only the project lead creates the repository.


1. Paulino - official project lead, GitHub repository owner, README coordinator, recommendation, validation, favorites, and report.
2. Alvarez - main.cpp, displayHeader(), displayMenu(), menu loop, switch-case flow, and integration support.
3. Beli - FoodItem class.
4. Domingo - CRUD manager logic.
5. Malabanan - database.txt and file handling.

## 6. Suggested timeline

### Week 1
- Paulino creates the GitHub repository.
- Paulino uploads folder structure and README.
- Alvarez starts the main.cpp menu skeleton.
- Add database.txt with 20 records.
- Create FoodItem class skeleton.

### Week 2
- Complete file loading.
- Complete view all and search.
- Complete recommendation by weather.

### Week 3
- Complete add, update, delete.
- Complete favorites and report.
- Begin integration testing.

### Week 4
- Debug invalid input.
- Finish SDAD, flowcharts, screenshots, README.
- Practice defense questions.

## 7. Rule about OpenWeather API

Manual input must be the main final version. OpenWeather API is only a bonus branch or future enhancement.

Decision rule:

```txt
If the main OOP + CRUD + file handling system is not finished one week before defense, do not add API code.
```

Reason:
- The final rubric prioritizes OOP, multi-file architecture, CRUD, file handling, GitHub, README, SDAD, and defense.
- A finished offline system is better than an unfinished API system.
