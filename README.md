# WEASOLVE: Weather-Based Food Recommendation System

## Project Title and SDG Goal

WEASOLVE is a Weather-Based Food Recommendation System developed by V of Spades.

This project supports SDG 3 - Good Health and Well-Being by helping users make practical food choices based on current weather, budget level, and available money.

## Project Description

Many people struggle to decide what food to eat, especially when weather conditions and budget limitations are considered. WEASOLVE helps users choose food faster by recommending suitable meals for sunny, rainy, or cold weather.

The final version upgrades the midterm console program into a modular Object-Oriented C++ application. Food records are loaded from an external database file, stored as FoodItem objects, managed using vector collections, and saved back to the file after updates.

## Core Features

- Manual weather input: sunny, rainy, or cold
- Food recommendations based on weather
- Restaurant and budget recommendation
- Favorites feature
- Summary report
- Full CRUD record management
- External database file with at least 20 records
- Input validation for menu, weather, budget, and numeric values
- Multi-file architecture using .h and .cpp files

## Repository Structure

```txt
V_of_Spades_SDG_Project/
├── .gitignore
├── README.md
├── CODE/
│   ├── main.cpp
│   ├── FoodItem.h
│   ├── FoodItem.cpp
│   ├── FoodManager.h
│   ├── FoodManager.cpp
│   ├── InputValidator.h
│   └── InputValidator.cpp
├── INPUT_DATA/
│   └── database.txt
└── DOCUMENTATION/
    ├── SDAD_VofSpades.pdf
    └── Flowchart_Core_Logic.png
```

## Contributors and Assigned Modules

Official project lead: Paulino, Eurie V.


| Member | Primary Contribution | Files/Modules |
|---|---|---|
| Paulino, Eurie V. | Official project lead, GitHub repository owner, README coordinator, recommendation, validation, favorites, report | README.md, InputValidator.h, InputValidator.cpp, FoodManager.cpp |
| Alvarez, Jerome Oliver P. | Main menu, program flow, display functions, switch-case integration support | main.cpp |
| Beli, Jhon Rey B. | FoodItem class | FoodItem.h, FoodItem.cpp |
| Domingo, Quirc Edrian P. | CRUD manager | FoodManager.h, FoodManager.cpp |
| Malabanan, Justine Lyle R. | File handling and database | database.txt, loadFromFile(), saveToFile() |

## Data Format

The system uses a pipe-delimited text file.

```txt
id|name|weather|budgetLevel|price|restaurant|healthNote
```

Example:

```txt
1|Halo-Halo|sunny|low|75|Local Dessert Stall|Cold dessert suitable for hot weather
```

## How to Compile

From the project root:

```bash
g++ CODE/main.cpp CODE/FoodItem.cpp CODE/FoodManager.cpp CODE/InputValidator.cpp -o weasolve
```

## How to Run

Linux/macOS:

```bash
./weasolve
```

Windows with MinGW:

```bash
weasolve.exe
```

## Main Menu

```txt
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
```

## OpenWeather API Note

The main final version uses manual weather input to ensure offline reliability and completion of the required OOP, CRUD, and file-handling features. OpenWeather API integration is planned as a bonus or future enhancement.

## Academic Integrity Note

All code must be understood and defended by the member assigned to that module. Any external code or AI-assisted code must be cited according to the course instructions.
