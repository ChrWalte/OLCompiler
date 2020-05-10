#pragma once

// Native includes:
#include "iostream"
#include "string"
#include "vector"

// Created includes:
#include "Compiler.h"
#include "Editor.h"
#include "FileReaderWriter.h"
#include "Memory.h"

// Always place classes in its own namespace so the global namespace stays
// clean.
namespace CLI {
	class CLI {
	public:
		// Constructor and destructor:
		CLI();
		~CLI();

	private:
		// The message that is shown on startup:
		const std::string STARTUP = "One Lang Compiler CLI Version 1.2.1\nThis is "
			"only a compiler with a built in editor.\nType "
			"\"help\" for a list of all active commands.\n";

		// The documentation message shown when a users asks for the documentation:
		const std::string DOCUMENTATION =
			"Variables: $(VariableName) = \"value\" || $(VariableName);\n"
			"Set variable to uppercase: $(VariableName).uppercase();\n"
			"Set variable to lowercase: $(VariableName).lowercase();\n"
			"Write to console: cli.out(\"value\" || $(VariableName));\n"
			"Write line to console: cli.outline(\"value\" || $(VariableName);\n"
			"Get input from console: cli.in($(VariableName));\n"
			"Read from a file: file.read(\"location\", $(VariableName));\n"
			"Write variable to file: file.write(\"location\", $(VariableName));\n"
			"Add to a number variable: $(VariableName)++ || $(VariableName) + 1234;\n"
			"Subtract one from a number variable: $(VariableName)-- || "
			"$(VariableName) - 1234;\n"
			"Generate random number: $(VariableName) = random.number() || "
			"random.number(Max) || random.number(Min, Max);\n"
			"Jump to a line of code: jump($(VariableName) == $(VariableName), 1234) "
			"|| jump($(VariableName) == \"value\", 1234) || jump(\"value\" == "
			"\"value\", 1234);\n"
			"Single line comment: //\n"
			"Start muti line comment: /*\n"
			"End muti-line comment: */\n";

		// The CLI prompt:
		const std::string PROMPT = "OL>: ";

		// Number of commands and the 2D Array with the command, its shortcut, and the
		// help message for every command:
		const int NUMBER_OF_COMMANDS = 9;
		const std::string COMMANDS[10][3] = {
			"help",
			"h",
			"displays the help menu, showing all the active commands for this "
			"compiler",
			"cls",
			"cl",
			"clears the cli",
			"compile",
			"cp",
			"compiles a program stored in memory",
			"editor",
			"et",
			"starts the editor to edit the program in memory",
			"display",
			"dp",
			"display all the populated memory locations",
			"documentation",
			"dc",
			"displays the documentation for the OneLang programming langauge",
			"save",
			"s",
			"saves the current program in memory to file",
			"load",
			"l",
			"loads a file into memory",
			"quit",
			"q",
			"exits the compile",
			"exit",
			"ex",
			"exits the compile",
		};

		// Enum for the three diffecerenct command values, this is used so I don't
		// just have random 0, 1, and 2 everywhere:
		const enum COMMAND_VALUES { command = 0, shortcut = 1, commandHelp = 2 };

		// Enum for every command so I don't have random numbers everywhere:
		const enum ALL_COMMANDS {
			help = 0,
			cls = 1,
			compile = 2,
			editor = 3,
			display = 4,
			documentation = 5,
			save = 6,
			load = 7,
			quit = 8,
			exit = 9
		};

		// Main memory class, this is where the code will be held. Imported from ither
		// the editor or a saved file.
		Memory::Memory memory = Memory::Memory();

		// Method that runs the command given from the user:
		void runCommand(std::string);

		// Shows the help menu to the user:
		void showHelpMenu();

		// Compiles the program in memory:
		void compileProgram();

		// Opens the built in editor:
		void openEditor();

		// This displays all the current memory locations:
		void displayMemoryLocations();

		// Displays the documentations for the OneLang programming language:
		void displayDocumentation();

		// Allows the memory to be loaded from a file with the .dev extension:
		void performLoad();

		// Saves the current memory to a file with the .dev extension:
		void performSave();

		// Sets a string to lowercase and then returns it.
		std::string toLowerCase(std::string);

		// Checks if the commands are equal:
		bool areCommandsEqual(std::string, int);
	};
}; // namespace CLI
