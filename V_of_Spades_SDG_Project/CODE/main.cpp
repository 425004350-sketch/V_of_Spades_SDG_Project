// main.cpp - Alvarez main-menu template; official project lead is Paulino
// Fill in after FoodManager and InputValidator functions are available.

#include <iostream>
#include "FoodManager.h"
#include "InputValidator.h"
using namespace std;

void displayHeader() {
    cout << "==========================================\n";
    cout << "WEASOLVE: Weather-Based Food Recommendation\n";
    cout << "SDG 3 - Good Health and Well-Being\n";
    cout << "==========================================\n";
}

void displayMenu(const string& currentWeather) {
    cout << "Current Weather: " << (currentWeather.empty() ? "NOT SET" : currentWeather) << endl;
    cout << "[1] Enter Current Weather\n";
    cout << "[2] View Food Recommendations\n";
    cout << "[3] Save Favorite Food\n";
    cout << "[4] View Favorite Foods\n";
    cout << "[5] Find Restaurants / Budget Recommendation\n";
    cout << "[6] View All Food Records\n";
    cout << "[7] Search Food Record\n";
    cout << "[8] Add New Food Record\n";
    cout << "[9] Update Food Record\n";
    cout << "[10] Delete Food Record\n";
    cout << "[11] Generate Summary Report\n";
    cout << "[12] Save and Exit\n";
}

int main() {
    // TODO: Create FoodManager object.
    // TODO: Load database file.
    // TODO: Create do-while menu loop.
    // TODO: Use switch-case to call each module.
    // TODO: Save database on exit.
    return 0;
}
