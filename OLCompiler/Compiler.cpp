// Include the .h file:
#include "Compiler.h"

// Constructor
Compiler::Compiler::Compiler() {}

// Constructor with the memory pointer:
Compiler::Compiler::Compiler(Memory::Memory* mainMemoryPointer) {
	// Sets the memory to the pointer:
	memory = *mainMemoryPointer;

	// Clears all the variables from the last program run:
	clearAllVariables();
}

// Compile program:
void Compiler::Compiler::compileProgram() {
	// DISPLAY
	std::cout << "Program started." << std::endl;

	// For loop that will run through every line of code:
	for (lineInCode = 0; lineInCode < memory.getMemorySize(); lineInCode++) {
		// String to get the current line of code:
		std::string currentLineOfMemory = memory.getFromMemory(lineInCode);

		// Try catch just in case there is an error while compute each line of code:
		try {
			// Checks if the line of code is not empty:
			if (currentLineOfMemory != "")
				// Computes the line of code:
				computeLine(currentLineOfMemory);
		}
		catch (...) {
			// If any error occurs, display the line number and what the line of code
			// was:
			std::cout << "Error on line [" << lineInCode << "]["
				<< currentLineOfMemory << "]." << std::endl;

			// Breaks out of the for loop:
			break;
		}
	}

	// Clears all the variables after program has ran:
	clearAllVariables();

	// DISPLAY
	std::cout << "Program ended." << std::endl;
}

// Cumputes one line of code:
std::string Compiler::Compiler::computeLine(std::string lineOfCode) {
	// If the line of code is the start of a mutiline comment or if mutiline
	// comment has already began:
	if (lineOfCode.substr(0, 2) == "/*" || mutiLineComment) {
		// If the line of code ends the mutiline comment set it to false:
		if (lineOfCode.substr(0, 2) == "*/")
			mutiLineComment = false;

		// If not set it to true:
		else
			mutiLineComment = true;
		return "";
	}

	// If the line starts with the comment then return:
	else if (lineOfCode.substr(0, 2) == "//")
		return "";

	// If the line starts with a variable sign then computeVariableOperation:
	else if (lineOfCode.substr(0, 1) == "$")
		return variableOperation(lineOfCode);

	// If the line of code begins with the cli.out then write something to the
	// console:
	else if (lineOfCode.substr(0, 8) == "cli.out(") {
		// Checks if the value is a variable:
		if (lineOfCode.substr(8, 1) == "$") {
			// Gets the value of the variable:
			std::string variableValue = getVariableValue(
				lineOfCode.substr(8, lineOfCode.find_last_of(")") - 8));

			// Writes that value to the console:
			writeToConsole(variableValue);
		}
		else if (lineOfCode.substr(8, 1) == "\"")
			// Just write the value in the () to console:
			writeToConsole(lineOfCode.substr(9, lineOfCode.find_last_of("\"") - 9));
		else
			// There is an error in the code:
			throw 0;
	}

	// If the line of code begins with cli.outline write to the console ending
	// with a new line:
	else if (lineOfCode.substr(0, 12) == "cli.outline(") {
		// Checks if the value is a variable:
		if (lineOfCode.substr(12, 1) == "$") {
			// Gets the value of the variable:
			std::string variableValue = getVariableValue(
				lineOfCode.substr(12, lineOfCode.find_last_of(")") - 12));

			// writes that value to the console:
			writeLineToConsole(variableValue);
		}
		else if (lineOfCode.substr(12, 1) == "\"")
			// Just write the value to console:
			writeLineToConsole(
				lineOfCode.substr(13, lineOfCode.find_last_of("\"") - 13));
		else
			// There was an error:
			throw 0;
	}

	// if the line of code starts with cli.in then read a value from the console
	// and store it in a variable:
	else if (lineOfCode.substr(0, 7) == "cli.in(") {
		// Get the variable name:
		if (lineOfCode.substr(7, 1) == "$") {
			std::string variableName =
				lineOfCode.substr(7, lineOfCode.find_last_of(")") - 7);

			// get the value from the console:
			std::string userInput = readFromConsole();

			// Set the variable value to the console input:
			setValueOfVariable(variableName, userInput);
		}

		// There was an error:
		else
			throw 0;
	}

	// If the line of code starts with file.read then read from a file:
	else if (lineOfCode.substr(0, 10) == "file.read(") {
		// Get the file location from the line of code:
		std::string fileLocation =
			lineOfCode.substr(11, lineOfCode.find_last_of(",") - 12);

		// Get the variable name that the file value should be stored:
		std::string variableName = lineOfCode.substr(
			lineOfCode.find_last_of(",") + 2,
			lineOfCode.find_last_of(")") - lineOfCode.find_last_of(",") - 2);

		// Read from the file and store it in the variable:
		readFromFile(fileLocation, variableName);
	}

	// If the line of code starts with file.write then write to a file:
	else if (lineOfCode.substr(0, 11) == "file.write(") {
		// Get the file loaction from the line of code:
		std::string fileLocation =
			lineOfCode.substr(12, lineOfCode.find_last_of(",") - 13);

		// Get the variable name from the line of code:
		std::string variableName = lineOfCode.substr(
			lineOfCode.find_last_of(",") + 2,
			lineOfCode.find_last_of(")") - lineOfCode.find_last_of(",") - 2);

		// Write the value from the variable to the file:
		writeToFile(fileLocation, variableName);
	}

	// If the line of code starts with jump then it is a jumpOperation:
	else if (lineOfCode.substr(0, 5) == "jump(")
		performJumpOperation(lineOfCode);

	return "";
}

// Perform a jump operation
std::string Compiler::Compiler::performJumpOperation(std::string lineOfCode) {
	// String to hold the JumpIfTrue statement:
	std::string operationStatement = lineOfCode.substr(
		lineOfCode.find_first_of("(") + 1,
		lineOfCode.find_first_of(",") - lineOfCode.find_first_of("(") - 1);

	// String to hold the number to jump to if true:
	std::string lineNumberToJumpTo = lineOfCode.substr(
		lineOfCode.find_first_of(",") + 2,
		lineOfCode.find_last_of(")") - lineOfCode.find_first_of(",") - 2);

	// String to hold the sign in the middle of the operation statement:
	std::string signInMiddle = "";
	if (operationStatement.find("==") != -1)
		signInMiddle = "==";
	else if (operationStatement.find("!=") != -1)
		signInMiddle = "!=";

	// String to hold the left side value of the operation:
	std::string leftSideOfOperation =
		operationStatement.substr(0, operationStatement.find(signInMiddle) - 1);

	// String to hold the right side of the operation:
	std::string rightSideOfOperation =
		operationStatement.substr(operationStatement.find(signInMiddle) + 3,
			operationStatement.find_first_of(",") -
			operationStatement.find(signInMiddle) - 3);

	// If the left side of the operation is a variable set it to the value of the
	// variable:
	if (leftSideOfOperation.substr(0, 1) == "$")
		leftSideOfOperation = getVariableValue(leftSideOfOperation);
	else
		// Only get the value of the operation:
		leftSideOfOperation =
		leftSideOfOperation.substr(1, leftSideOfOperation.length() - 2);

	// If the right side of the operation is a variable set it to the value of the
	// variable:
	if (rightSideOfOperation.substr(0, 1) == "$")
		rightSideOfOperation = getVariableValue(rightSideOfOperation);
	else
		// Only get the value of the operation:
		rightSideOfOperation =
		rightSideOfOperation.substr(1, rightSideOfOperation.length() - 2);

	// Should we preform the jump:
	bool performOperation = false;

	// Set the boolean value depending on the sign in the middle:
	if (signInMiddle == "==")
		performOperation = leftSideOfOperation == rightSideOfOperation;
	else if (signInMiddle == "!=")
		performOperation = leftSideOfOperation != rightSideOfOperation;

	// If the operation is true then jump to the line of code:
	if (performOperation)
		lineInCode = std::stoi(lineNumberToJumpTo) - 1;

	return "";
}

// Method that computes a variable operation:
std::string Compiler::Compiler::variableOperation(std::string lineOfCode) {
	// Gets the variable name in the lineOfCode:
	std::string variableName =
		lineOfCode.substr(0, lineOfCode.find_first_of(")") + 1);

	// If the variable is being set to seomthing:
	if (lineOfCode.find_last_of("=") != -1) {
		// String that will hold the value of the LineOfCode:
		std::string variableValue = "";

		// if the variable is being set to a random number then run the random
		// number method:
		if (lineOfCode.find("random.number()") != -1)
			variableValue = std::to_string(generateRandomNumber());

		else if (lineOfCode.find("random.number(") != -1) {
			if (lineOfCode.find_last_of(",") != -1) {
				int min = std::stoi(lineOfCode.substr(
					lineOfCode.find_last_of("(") + 1,
					lineOfCode.find_last_of(",") - lineOfCode.find_last_of("(") - 1));
				int max = std::stoi(lineOfCode.substr(
					lineOfCode.find_last_of(",") + 1,
					lineOfCode.find_last_of(")") - lineOfCode.find_last_of(",") - 1));
				variableValue = std::to_string(generateRandomNumber(min, max));
			}
			else {
				int max = std::stoi(lineOfCode.substr(
					lineOfCode.find_last_of("(") + 1,
					lineOfCode.find_last_of(")") - lineOfCode.find_last_of("(") - 1));
				variableValue = std::to_string(generateRandomNumber(max));
			}
		}

		// If the variable is being set to another variable:
		else if (lineOfCode.find("= $(") != -1) {
			// Get the other variable name:
			std::string anotherVariableName = lineOfCode.substr(
				lineOfCode.find("= $(") + 2,
				(lineOfCode.find(");") - lineOfCode.find("= $(") - 1));

			// Set the variable to the other variable:
			variableValue = getVariableValue(anotherVariableName);
		}

		// Set the variable to the value after the = sign:
		else
			variableValue = lineOfCode.substr(lineOfCode.find_first_of("\"") + 1,
				lineOfCode.find_last_of("\"") -
				lineOfCode.find_first_of("\"") - 1);

		// Set the value of the variable:
		addValueTolistOfVariables(variableName, variableValue);
	}

	// If the variable is trying to begin an operation:
	else if (lineOfCode.find_last_of(".") != -1) {
		// Get the length of the variable:
		if (lineOfCode.substr(lineOfCode.find_first_of("."), 9) == ".length()")
			return std::to_string(getLengthOfVariable(variableName));

		// Set the variable to all uppercase:
		else if (lineOfCode.substr(lineOfCode.find_first_of("."), 12) ==
			".uppercase()")
			return setVariableToUppercase(variableName);

		// Set the variable to all lowercase:
		else if (lineOfCode.substr(lineOfCode.find_first_of("."), 12) ==
			".lowercase()")
			return setVariableToLowercase(variableName);
	}

	// Add one to a number variable:
	else if (lineOfCode.find("++") != -1)
		addToIntVariable(variableName);

	// Subtract one from a number variable:
	else if (lineOfCode.find("--") != -1)
		subtractFromIntVariable(variableName);

	// Add an amount to a number variable:
	else if (lineOfCode.find_last_of("+") != -1) {
		// Get the amount to add from line of code:
		int amountToAdd = std::stoi(lineOfCode.substr(
			lineOfCode.find_last_of(" ") + 1,
			lineOfCode.find_last_of(";") - lineOfCode.find_last_of(" ") + 1));

		// add that amount:
		addToIntVariable(variableName, amountToAdd);
	}

	// Subtract an amount from a number variable:
	else if (lineOfCode.find_last_of("-") != -1) {
		// Get the number to subtract from the line of code:
		int amountToSubtract = std::stoi(lineOfCode.substr(
			lineOfCode.find_last_of(" ") + 1,
			lineOfCode.find_last_of(";") - lineOfCode.find_last_of(" ") + 1));

		// Subtract that value from the variable:
		subtractFromIntVariable(variableName, amountToSubtract);
	}
	else
		throw 0;

	return "";
}