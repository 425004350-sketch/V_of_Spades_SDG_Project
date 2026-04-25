# SDAD Outline for WEASOLVE

## Section 1 - Introduction

### 1.1 Project Overview and Target SDG
Write:

WEASOLVE is a Weather-Based Food Recommendation System developed by V of Spades. It supports SDG 3 - Good Health and Well-Being by helping users choose food based on weather, budget, and comfort needs.

### 1.2 Problem Statement
Write:

Many users, especially students, families, and couples, struggle to decide what food to eat. The decision becomes harder when weather and budget are considered. WEASOLVE helps reduce decision stress by generating suitable food recommendations.

## Section 2 - Requirements Analysis

### 2.1 Functional Requirements

Use:

FR1: The system must automatically load food data from database.txt.
FR2: The system must store at least 20 records as FoodItem objects.
FR3: The system must allow users to add, view, search, update, and delete records.
FR4: The system must recommend food based on sunny, rainy, or cold weather.
FR5: The system must recommend food based on weather and budget.
FR6: The system must allow users to save and view favorite foods.
FR7: The system must generate a summary report.
FR8: The system must save all updates to database.txt on clean exit.

### 2.2 Non-Functional Requirements

Use:

NFR1: The system must validate invalid input and avoid crashes.
NFR2: The system must use multiple .h and .cpp files.
NFR3: The system must use encapsulation in the FoodItem class.
NFR4: The system must use clear variable and function names.
NFR5: The system must include comments for each major class and function.

## Section 3 - Design Specification

### 3.1 Algorithmic Flowchart
Attach Flowchart_Core_Logic.png.

### 3.2 File Structure Diagram
Show:

```txt
INPUT_DATA/database.txt
id|name|weather|budgetLevel|price|restaurant|healthNote
```

### 3.3 Class Diagram

```txt
FoodItem
- id: int
- name: string
- weather: string
- budgetLevel: string
- price: double
- restaurant: string
- healthNote: string
+ getters/setters
+ display()
+ toFileString()

FoodManager
- foods: vector<FoodItem>
- favorites: vector<FoodItem>
+ loadFromFile()
+ saveToFile()
+ CRUD functions
+ recommendation functions
+ report functions
```
