#pragma once

// Native includes:
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

// Always place classes in its own namespace so the global namespace stays
// clean.
namespace Language {
	class Language {
	public:

		//Method that writes the given string to the console:
		void writeToConsole(std::string);

		//Method that writes the given string to the console ending in a new line:
		void writeLineToConsole(std::string);

		//Read a value from the console:
		std::string readFromConsole();

		//Adds one to the given string:
		void addToIntVariable(std::string);

		//Adds the given number to the given strings value:
		void addToIntVariable(std::string, int);

		//Subtracts one from the given strings value:
		void subtractFromIntVariable(std::string);

		//Subtracts the given number from the the given strings value:
		void subtractFromIntVariable(std::string, int);

		//Returns the length of the given strings value:
		int getLengthOfVariable(std::string);

		//returns the value of the string as an int:
		int getVariableAsInt(std::string);

		//Get the value of the given string:
		std::string getVariableValue(std::string);

		//Generate a random number:
		int generateRandomNumber();

		//Generate a random number with a given max:
		int generateRandomNumber(int);

		//Generate a random number between the given min and the given max:
		int generateRandomNumber(int, int);

		//Retring a string that is uppercase:
		std::string setVariableToUppercase(std::string);

		//Retring a string that is lowercase:
		std::string setVariableToLowercase(std::string);

		//Adds to the list of variables using the given name and the given value:
		void addValueTolistOfVariables(std::string, std::string);

		//Deletes from the list of variables using the given name:
		void deleteValueFromListOfVariables(std::string);

		//Sets the value of a variable using the given name of the variable and the given value:
		void setValueOfVariable(std::string, std::string);

		//Write a variable to a file using the given location and using the given variable name:
		void writeToFile(std::string, std::string);

		//Read from a file using the given file location and storing the value into the given variable:
		void readFromFile(std::string, std::string);

		//Clears all the values in the vector of variables:
		void clearAllVariables();

	private:

		//Something I would ike to add later on, having type safty:
		/*std::vector<std::string> intVariableNames = std::vector<std::string>();
		std::vector<int> intVariableValues = std::vector<int>();

		std::vector<std::string> stringVariableNames = std::vector<std::string>();
		std::vector<std::string> stringVariableValues = std::vector<std::string>();

		std::vector<std::string> boolVariableNames = std::vector<std::string>();
		std::vector<bool> boolVariableValues = std::vector<bool>();*/

		//List of variabler names:
		std::vector<std::string> variableNames = std::vector<std::string>();

		//List of variable values:
		std::vector<std::string> variableValues = std::vector<std::string>();
	};
} // namespace Language
