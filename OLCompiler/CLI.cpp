// Include .h file:
#include "CLI.h"

// Constructor:
CLI::CLI::CLI() {
	// String to hold the user input:
	std::string userInputCommand = "";

	// DISPLAY:
	std::cout << STARTUP << std::endl;

	// Main do - while loop that allows the program to keep running until the user
	// either types in quit or exit:
	do {
		// DISPLAY THE PROMPT EVERY LOOP:
		std::cout << PROMPT;

		// Gets the command from the user and stores it into the variable:
		std::getline(std::cin, userInputCommand);

		// Sets the user input to all lowercase just to keep the commands
		// non-case-sensitive:
		userInputCommand = toLowerCase(userInputCommand);

		// Trys to run the command from the user:
		runCommand(userInputCommand);

		// Loop will run until the user inputs the quit or exit command:
	} while (!areCommandsEqual(userInputCommand, quit) &&
		!areCommandsEqual(userInputCommand, exit));
}

// Destructor, Displays that the CLI has ended:
CLI::CLI::~CLI() { std::cout << "CLI Exited." << std::endl; }

// Attempts to run the command from the user:
void CLI::CLI::runCommand(std::string command) {
	// If the command is quit or exit return, FAIL FAST:
	if (areCommandsEqual(command, quit) || areCommandsEqual(command, exit))
		return;

	// If the command is help then show the help menu:
	else if (areCommandsEqual(command, help))
		showHelpMenu();

	// If the command is clear then clear the console:
	else if (areCommandsEqual(command, cls))
		system("cls");

	// If the command is compile then compile the program currently in memory:
	else if (areCommandsEqual(command, compile))
		compileProgram();

	// if the command is editor show the built in editor:
	else if (areCommandsEqual(command, editor))
		openEditor();

	// If the command is display then display all the memory locations:
	else if (areCommandsEqual(command, display))
		displayMemoryLocations();

	// If the command is documentation then show the OneLang documentation:
	else if (areCommandsEqual(command, documentation))
		displayDocumentation();

	// If the command is save then save all the memory locations to a file:
	else if (areCommandsEqual(command, save))
		performSave();

	// If the command is load then load all the memory locations from file:
	else if (areCommandsEqual(command, load))
		performLoad();

	// If the command was not found display and error message and loop again:
	else
		std::cout << "Unknown command, \"" << command
		<< "\", please input a known command or type help to see all "
		"active commands."
		<< std::endl;
}

// Displays the help menu:
void CLI::CLI::showHelpMenu() {
	// DISPLAY:
	std::cout << "Help Menu:" << std::endl;

	// For loop that will loop for the amount of commands set in the .h file:
	for (int i = 0; i < NUMBER_OF_COMMANDS; i++)
		// DISPLAY THE COMMAND, THE SHORTCUT, AND THE HELP FOR EACH COMMAND:
		std::cout << COMMANDS[i][command] << " - " << COMMANDS[i][shortcut] << " = "
		<< COMMANDS[i][commandHelp] << std::endl;

	// New line:
	std::cout << std::endl;
}

// Creates a new compiler object and passes in a pointer to the memory object:
void CLI::CLI::compileProgram() {
	Compiler::Compiler compiler = Compiler::Compiler(&memory);

	// Compiles the program using the memory:
	compiler.compileProgram();
}

// Opens the built in editor and passes in a pointer to the memory object:
void CLI::CLI::openEditor() {
	// Clears the console:
	system("cls");
	Editor::Editor editor = Editor::Editor(&memory);
}

// Display all of the memory locations:
void CLI::CLI::displayMemoryLocations() {
	// DISPLAY:
	std::cout << "Displaying memory." << std::endl;

	// Loop through all of the memory locations:
	for (int i = 0; i < memory.getMemorySize(); i++) {
		// If memory is not blank then display it with the line number:
		if (memory.getFromMemory(i) != "")
			std::cout << "[" << i << "][" << memory.getFromMemory(i) << "]"
			<< std::endl;
	}

	// DISPLAY:
	std::cout << "Display Ended." << std::endl;
}

// Display the One Lang documentation:
void CLI::CLI::displayDocumentation() {
	std::cout << DOCUMENTATION << std::endl;
}

// Save the current memory locations to a file after asking the user for a
// location and a name for the save:
void CLI::CLI::performSave() {
	// Crates a new FileReaderWriter object and passes in the memory as a pointer:
	FileReaderWriter::FileReaderWriter writeToFile =
		FileReaderWriter::FileReaderWriter(&memory);
	writeToFile.writeToFileFromMemory();
}

// Load the memory from a file:
void CLI::CLI::performLoad() {
	// Crates a new FileReaderWriter object and passes in the memory as a pointer:
	FileReaderWriter::FileReaderWriter readToFile =
		FileReaderWriter::FileReaderWriter(&memory);
	readToFile.readFromFileToMemory();
}

// Method that takes in a string and converts it to all lowercase then returns
// the string back:
std::string CLI::CLI::toLowerCase(std::string givenString) {
	// String that will be returned:
	std::string returnLowerCaseString = "";

	// Loops through every letter in the givenString:
	for (int i = 0; i < givenString.length(); i++)
		// Sets the letter to lowercase and adds it to the returnString
		returnLowerCaseString += std::tolower(givenString[i]);

	// Returns the string:
	return returnLowerCaseString;
}

// Checks of the commands are equal by checking if it is equal to both the
// command and the shortcut:
bool CLI::CLI::areCommandsEqual(std::string given, int commandNumber) {
	return given == COMMANDS[commandNumber][command] ||
		given == COMMANDS[commandNumber][shortcut];
}