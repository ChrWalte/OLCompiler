#pragma once

// Native includes:
#include "string"
#include "vector"

// Always place classes in its own namespace so the global namespace stays
// clean.
namespace Memory {
	class Memory {
	public:
		//Constructor:
		Memory();

		//Destructor:
		~Memory();

		//Add one value to memory at a certain location:
		static void addToMemory(std::string, int);

		//Remove a value from a certain location in memory:
		static void removeFromMemory(int);

		//Clear all the values in memory:
		static void clearMemory();

		//Get the current size in memory:
		static int getMemorySize();

		static std::string getFromMemory(int);

	private:
		static std::vector<std::string> memory;
	};
} // namespace Memory
