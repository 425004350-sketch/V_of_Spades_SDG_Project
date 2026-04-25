// FoodItem.h - Beli template
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
