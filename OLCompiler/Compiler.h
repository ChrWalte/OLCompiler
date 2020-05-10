#pragma once

// Native includes:
#include <iostream>

// Created includes:
#include "Language.h"
#include "Memory.h"

// Always place classes in its own namespace so the global namespace stays
// clean.
namespace Compiler {
	// Compiler class inherits from the Language class but only allows inself to see
	// the public methods:
	class Compiler : private Language::Language {
	public:
		// Constructor and destructor:
		Compiler();
		Compiler(Memory::Memory*);

		// Method that runs the current program in memory:
		void compileProgram();

	private:
		// Static memory object:
		static Memory::Memory memory;

		// Iterator to know what line of code it is on:
		int lineInCode = 0;

		// Booean for the mutiline comment function:
		bool mutiLineComment = false;

		// Compute the current line of code:
		std::string computeLine(std::string);

		// The line of code is a variable operation:
		std::string variableOperation(std::string);

		// The line of code is a jump operation:
		std::string performJumpOperation(std::string);
	};
} // namespace Compiler
