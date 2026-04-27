// FoodManager.cpp - shared manager template
#include "FoodManager.h"
#include "InputValidator.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int FoodManager::findIndexById(int id) const {
    for (int i = 0; i < foods.size(); ++i) {
        if (foods[i].getId() == id) {
            return i;
        }
    }
    
    return -1;
}
}

int FoodManager::generateNextId() const {
    int maxId = 0;
    for (const auto& food : foods) {
        if (food.getId() > maxId) {
            maxId = food.getId();
        }
    }
    return maxId + 1;
}
}

bool FoodManager::loadFromFile(const string& filename) {
    // TODO Malabanan: open file, parse lines, create FoodItem objects.
    return false;
}

bool FoodManager::saveToFile(const string& filename) const {
    // TODO Malabanan: write all foods to file using toFileString().
    return false;
}

void FoodManager::viewAllFoods() const {
    // TODO Domingo
}

void FoodManager::searchFood() const {
    // TODO Domingo
}

void FoodManager::addFood() {
    // TODO Domingo
}

void FoodManager::updateFood() {
    // TODO Domingo
}

void FoodManager::deleteFood() {
    // TODO Domingo
}

void FoodManager::recommendByWeather(const string& weather) const {
    // TODO Paulino
}

void FoodManager::recommendByWeatherAndBudget(const string& weather) const {
    // TODO Paulino
}

void FoodManager::saveFavoriteFood(const string& weather) {
    // TODO Paulino
}

void FoodManager::viewFavorites() const {
    // TODO Paulino
}

void FoodManager::generateSummaryReport(const string& currentWeather) const {
    // TODO Paulino
}
