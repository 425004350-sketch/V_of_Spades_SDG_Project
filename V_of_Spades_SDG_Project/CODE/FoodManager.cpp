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

int FoodManager::generateNextId() const {
    if (foods.empty()) {
        return 1; 
    }

    int maxId = 0;
    for (const auto& food : foods) {
        if (food.getId() > maxId) {
            maxId = food.getId();
        }
    }
    return maxId + 1;
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
    if (foods.empty()) {
        std::cout << "\nNo food items found in the system." << std::endl;
        return;
    }

    std::cout << "\n--- Current Food Inventory ---" << std::endl;
    for (const auto& food : foods) {
        std::cout << "ID: " << food.getId() 
                  << " | Name: " << food.getName() 
                  << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}


void FoodManager::searchFood() const {
    if (foods.empty()) {
        std::cout << "Inventory is empty. Nothing to search." << std::endl;
        return;
    }

    int choice;
    std::cout << "\nSearch by:\n1. ID\n2. Name\nEnter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        int id;
        std::cout << "Enter ID: ";
        std::cin >> id;

        int index = findIndexById(id); 
        if (index != -1) {
            std::cout << "Found: " << foods[index].getName() << " (ID: " << id << ")" << std::endl;
        } else {
            std::cout << "Food with ID " << id << " not found." << std::endl;
        }

    } else if (choice == 2) {
        std::string name;
        std::cout << "Enter Name: ";
        std::cin.ignore(); 
        std::getline(std::cin, name);

        bool found = false;
        for (const auto& food : foods) {
            if (food.getName() == name) {
                std::cout << "Found: ID " << food.getId() << " | " << food.getName() << std::endl;
                found = true;
            }
        }
        if (!found) std::cout << "No food found with that name." << std::endl;

    } else {
        std::cout << "Invalid choice." << std::endl;
    }
}

void FoodManager::addFood() {
    std::string name;
    
    std::cout << "\nEnter food name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    int newId = generateNextId();
    Food newFood(newId, name);
    foods.push_back(newFood);

    std::cout << "Added: " << name << " (ID: " << newId << ")" << std::endl;
}



void FoodManager::updateFood() {
    int id;
    std::cout << "\nEnter Food ID to update: ";
    std::cin >> id;

    int index = findIndexById(id);
    if (index != -1) {
        std::string newName;
        std::cout << "Enter new name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, newName);

        foods[index].setName(newName);
        std::cout << "Food updated successfully." << std::endl;
    } else {
        std::cout << "Food ID not found." << std::endl;
    }
}

void FoodManager::deleteFood() {
    int id;
    std::cout << "\nEnter Food ID to delete: ";
    std::cin >> id;

    int index = findIndexById(id);
    if (index != -1) {
        foods.erase(foods.begin() + index);
        std::cout << "Food deleted successfully." << std::endl;
    } else {
        std::cout << "Food ID not found." << std::endl;
    }
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
