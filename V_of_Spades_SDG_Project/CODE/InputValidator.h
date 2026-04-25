// InputValidator.h - Paulino template
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
