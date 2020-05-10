// Required .h file:
#include "Editor.h"

// Constructor that takes a pointer to the memory object:
Editor::Editor::Editor(Memory::Memory* mainMemoryPoniter) {
	// Sets private memory to the memory address:
	memory = *mainMemoryPoniter;

	// String for the user input:
	std::string userInput = "";

	// DISPLAY:
	std::cout << STARTUP << std::endl;

	// Do loop that will allow the user to populate the memory with as much data
	// as they would like:
	do {
		// DISPLAY OF THE MEMORY INDEX WITH THE CURRENT VALUE OF MEMORY AT THAT
		// INDEX:
		std::cout << "[" << memoryIndex << "][" << memory.getFromMemory(memoryIndex)
			<< "]: ";

		// Get input from console:
		std::getline(std::cin, userInput);

		// Compute the value from the console:
		computeInput(userInput);

		// Continue until the user types in !
	} while (userInput != "!");

	// DISPLAY:
	std::cout << "Editor Exited." << std::endl;
}

// Compute the value from the user:
void Editor::Editor::computeInput(std::string userInput) {
	// If the value is the quit value then return, FAIL FAST:
	if (userInput == "!")
		return;

	// If the input was + then continue to next line:
	else if (userInput == "+")
		memoryIndex++;

	// If the user input is a - then go back one line in the memory:
	else if (userInput == "-") {
		if (memoryIndex > 0)
			memoryIndex--;
	}

	else {
		// Remove the current value in memory:
		memory.removeFromMemory(memoryIndex);

		// Add the user input to memory:
		memory.addToMemory(userInput, memoryIndex++);
	}
}