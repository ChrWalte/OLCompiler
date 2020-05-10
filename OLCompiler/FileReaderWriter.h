#pragma once

// Native includes:
#include <fstream>
#include <iostream>

// Created includes:
#include "Memory.h"

// Always place classes in its own namespace so the global namespace stays
// clean.
namespace FileReaderWriter {
	class FileReaderWriter {
	public:
		// Constructor:
		FileReaderWriter(Memory::Memory*);

		// Method that writes to a file:
		void writeToFileFromMemory();

		// Method that reads from a file:
		void readFromFileToMemory();

	private:
		// Memory object:
		static Memory::Memory memory;

		// Method that sets a string to lowercase then returns it:
		std::string toLowerCase(std::string);
	};
} // namespace FileReaderWriter
