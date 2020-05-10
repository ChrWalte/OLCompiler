// Required .h file:
#include "Memory.h"

// Initialize the memory vector:
std::vector<std::string> Memory::Memory::memory = std::vector<std::string>();

// Default Constructor:
Memory::Memory::Memory() {}

// Destructor that clears all values in memory:
Memory::Memory::~Memory() { clearMemory(); }

// Method to add a value to memory at a certain location:
void Memory::Memory::addToMemory(std::string value, int location) {
	memory.emplace(memory.begin() + location, value);
}

// Method to remove a value from memory at a location:
void Memory::Memory::removeFromMemory(int location) {
	memory.erase(memory.begin() + location);
}

// Method that clears the all memory locations:
void Memory::Memory::clearMemory() { memory.clear(); }

// Method that returns the current memory size:
int Memory::Memory::getMemorySize() { return memory.size(); }

// Get a value from memory at a certain locations:
std::string Memory::Memory::getFromMemory(int location) {
	// Try catch to catch if the location does not exist:
	try {
		// If it does return the location:
		return memory.at(location);
	}
	catch (...) {
		// If is does not exist return an empty string:
		return "";
	}
}