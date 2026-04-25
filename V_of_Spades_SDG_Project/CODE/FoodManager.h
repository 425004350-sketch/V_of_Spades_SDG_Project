// FoodManager.h - Domingo, Malabanan, Paulino shared template
#ifndef FOODMANAGER_H
#define FOODMANAGER_H

#include <string>
#include <vector>
#include "FoodItem.h"
using namespace std;

class FoodManager {
private:
    vector<FoodItem> foods;
    vector<FoodItem> favorites;

    int findIndexById(int id) const;
    int generateNextId() const;

public:
    bool loadFromFile(const string& filename);
    bool saveToFile(const string& filename) const;

    void viewAllFoods() const;
    void searchFood() const;
    void addFood();
    void updateFood();
    void deleteFood();

    void recommendByWeather(const string& weather) const;
    void recommendByWeatherAndBudget(const string& weather) const;
    void saveFavoriteFood(const string& weather);
    void viewFavorites() const;
    void generateSummaryReport(const string& currentWeather) const;
};

#endif
