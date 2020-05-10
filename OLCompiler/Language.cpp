// Required .h file:
#include "Language.h"

// Method that writes a value to console:
void Language::Language::writeToConsole(std::string userInput) {
	std::cout << userInput;
}

// Method that writes a value to the console with a new line at the end:
void Language::Language::writeLineToConsole(std::string userInput) {
	std::cout << userInput << std::endl;
}

// Method that returns a value from the console:
std::string Language::Language::readFromConsole() {
	std::string userInput;
	std::getline(std::cin, userInput);
	return userInput;
}

// Adds one to a given variable:
void Language::Language::addToIntVariable(std::string nameOfVariable) {
	addToIntVariable(nameOfVariable, 1);
}

// Adds a given number to a given variable:
void Language::Language::addToIntVariable(std::string nameOfVariable,
	int amountToAdd) {
	// Loop that goes through all of the variables:
	for (int i = 0; i < variableNames.size(); i++) {
		// If the variable name is equal to the given vairable name:
		if (variableNames[i] == nameOfVariable) {
			// Get the value of the variable as an int and add the given value:
			int variableAsInt = std::stoi(variableValues[i]) + amountToAdd;

			// Set the value of variable to the new value:
			variableValues[i] = std::to_string(variableAsInt);
			return;
		}
	}

	// Throw error, no variable by given name:
	throw 0;
}

// Subtract one from a variable:
void Language::Language::subtractFromIntVariable(std::string nameOfVariable) {
	addToIntVariable(nameOfVariable, -1);
}

// Subtract a given value from a variable:
void Language::Language::subtractFromIntVariable(std::string nameOfVariable,
	int amountToSubtact) {
	addToIntVariable(nameOfVariable, -amountToSubtact);
}

// Method that returns the length of a given variable:q
int Language::Language::getLengthOfVariable(std::string nameOfVariable) {
	for (int i = 0; i < variableNames.size(); i++) {
		if (variableNames[i] == nameOfVariable)
			return variableValues[i].length();
	}

	// Throw error, no variable with given name:
	throw 0;
}

// Method that returns the given variable as a number:
int Language::Language::getVariableAsInt(std::string nameOfVariable) {
	// Loop that will loop through all of the variables:
	for (int i = 0; i < variableNames.size(); i++) {
		// If the variable names are equal:
		if (variableNames[i] == nameOfVariable)
			// return value as int:
			return std::stoi(variableValues[i]);
	}

	// Throw error, no variable by name found:
	throw 0;
}

// Method that returns the value of a given variable:
std::string Language::Language::getVariableValue(std::string nameOfVariable) {
	// Loop through all the variables:
	for (int i = 0; i < variableNames.size(); i++) {
		// If the variable names are equal:
		if (variableNames[i] == nameOfVariable)
			// return thr variable value:
			return variableValues[i];
	}

	// Throw error, no variable by name found:
	throw 0;
}

// Method that generates a random number:
int Language::Language::generateRandomNumber() {
	return generateRandomNumber(0, std::numeric_limits<int>::max());
}

// Method that generates a random number with a given max:
int Language::Language::generateRandomNumber(int max) {
	return generateRandomNumber(0, max);
}

// Method that generates a random number with the given min and max:
int Language::Language::generateRandomNumber(int min, int max) {
	srand(time(NULL));
	return rand() % (max - min + 1) + min;
}

// Method that sets a given variable to all uppercase:
std::string Language::Language::setVariableToUppercase(std::string nameOfVariable) {
	// Loops through all the variables:
	for (int i = 0; i < variableNames.size(); i++) {
		// If the variable names are equal:
		if (variableNames[i] == nameOfVariable) {
			// Get the variable value and set it to uppercase:
			std::string oldVariableValue = variableValues[i];
			std::string uppercaseVariableValue;

			for (int i = 0; i < oldVariableValue.length(); i++)
				uppercaseVariableValue += std::toupper(oldVariableValue[i]);

			variableValues[i] = uppercaseVariableValue;
			return variableValues[i];
		}
	}

	// Throw error, no variable with given name:
	throw 0;
}

// Method that sets a given variable to all lowercase:
std::string Language::Language::setVariableToLowercase(std::string nameOfVariable) {
	// Loops through all of the variables:
	for (int i = 0; i < variableNames.size(); i++) {
		// If the variable names are equal:
		if (variableNames[i] == nameOfVariable) {
			// Set the value of the variable to lowercase:
			std::string oldVariableValue = variableValues[i];
			std::string lowercaseVariableValue;

			for (int i = 0; i < oldVariableValue.length(); i++)
				lowercaseVariableValue += std::tolower(oldVariableValue[i]);

			variableValues[i] = lowercaseVariableValue;
			return variableValues[i];
		}
	}

	// Throw error, no variable by given name:
	throw 0;
}

// Method that creates a new variable and sets its value:
void Language::Language::addValueTolistOfVariables(std::string name, std::string value) {
	// Loops through the variable list:
	for (int i = 0; i < variableNames.size(); i++) {
		// If the name already exists:
		if (variableNames[i] == name) {
			// Set the value of the variable:
			variableValues[i] = value;
			return;
		}
	}

	// Create a new Variable:
	variableNames.push_back(name);
	variableValues.push_back(value);
}

// Method that deletes a variable from the list:
void Language::Language::deleteValueFromListOfVariables(std::string name) {
	// Loops through the variables:
	for (int i = 0; i < variableNames.size(); i++) {
		// If the names are equal:
		if (variableNames[i] == name) {
			// Delete the variable from the list of variables:
			variableNames.erase(variableNames.begin() + i);
			variableValues.erase(variableValues.begin() + i);
			return;
		}
	}

	// Throw error, no variable with given name found:
	throw 0;
}

// Method that sets the value of a given variable:
void Language::Language::setValueOfVariable(std::string name, std::string value) {
	// Loops through all of the variables:
	for (int i = 0; i < variableNames.size(); i++) {
		// If the variable names are equal:
		if (variableNames[i] == name) {
			// Set the value:
			variableValues[i] = value;
			return;
		}
	}

	// Throw error, no variable with given name found:
	throw 0;
}

// Write a variables value to a file location:
void Language::Language::writeToFile(std::string fileLocation, std::string variableName) {
	// File stream:
	std::ofstream fileToWrite;

	// Open file at location:
	fileToWrite.open(fileLocation);

	// Write to file:
	fileToWrite << getVariableValue(variableName);

	// Close file:
	fileToWrite.close();
}

// Read from file to a variable:
void Language::Language::readFromFile(std::string fileLocation, std::string variableName) {
	// File stream:
	std::ifstream fileToRead;

	// Open file at location:
	fileToRead.open(fileLocation);

	// string to hold File value:
	std::string fileValue;

	// While there are lines in the file:
	while (std::getline(fileToRead, fileValue))
		// Set the value of the variable:
		setValueOfVariable(variableName, fileValue);

	// Close the file:
	fileToRead.close();
}

// Clear all variables from memory:
void Language::Language::clearAllVariables() {
	variableNames.clear();
	variableValues.clear();
}