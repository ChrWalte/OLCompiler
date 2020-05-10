#pragma once

// Native includes:
#include "iostream"
#include "string"

// Created includes:
#include "Memory.h"

// Always place classes in its own namespace so the global namespace stays
// clean.
namespace Editor {
	class Editor {
	public:
		// Constructor:
		Editor(Memory::Memory*);

	private:
		// String that holds the start up message:
		const std::string STARTUP =
			"Program Editor Version 1.2.1.\nType \"+\" to go to next line.\nType "
			"\"-\" to go to previous line.\nType \"!\" to go to exit the "
			"editor.\n[LINE NUMBER][CURRENT VALUE]: New Value";

		// Static memory object:
		static Memory::Memory memory;

		// memory Iterator to keep track of the position in memory:
		int memoryIndex = 0;

		// Computer the value that will be put into memory:
		void computeInput(std::string);
	};
} // namespace Editor
