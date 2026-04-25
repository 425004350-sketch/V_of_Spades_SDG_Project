// InputValidator.cpp - Paulino template
#include "InputValidator.h"
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

int InputValidator::getIntInRange(string prompt, int min, int max) {
    // TODO: repeat until user enters an integer between min and max.
    return min;
}

double InputValidator::getPositiveDouble(string prompt) {
    // TODO: repeat until user enters a positive number.
    return 0.0;
}

string InputValidator::getWeatherInput() {
    // TODO: accept only sunny, rainy, cold.
    return "";
}

string InputValidator::getBudgetInput() {
    // TODO: accept only low, mid, high.
    return "";
}

string InputValidator::getYesNoInput(string prompt) {
    // TODO: accept only yes/no or y/n.
    return "no";
}

string InputValidator::toLowerCase(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}
