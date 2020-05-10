// Required .h file:
#include "FileReaderWriter.h"

// Constructor:
FileReaderWriter::FileReaderWriter::FileReaderWriter(
	Memory::Memory* mainMemoryPoniter) {
	// Sets the memory object to the memory pointer:
	memory = *mainMemoryPoniter;
}

// Method that writes all the memory locations to the file:
void FileReaderWriter::FileReaderWriter::writeToFileFromMemory() {
	// Try catch if any errors occur:
	try {
		// DISPLAY:
		std::cout << "Writing to file" << std::endl;

		// Get the location from the user and set it to lowercase:
		std::string location;
		std::cout << "Location to save file: ";
		std::getline(std::cin, location);
		location = toLowerCase(location);

		// Get the file name from the user and set it to lowercase:
		std::string fileName;
		std::cout << "File name: ";
		std::getline(std::cin, fileName);
		fileName = toLowerCase(fileName);

		// File stream to write to a file:
		std::ofstream fileToWrite;

		// Open the file with the extension of .dev:
		fileToWrite.open(location + "/" + fileName + ".dev");

		// For loop that will loop through all the memory locations:
		for (int i = 0; i < memory.getMemorySize(); i++)

			// Write the memory location to file:
			fileToWrite << memory.getFromMemory(i) << "\n";

		// Close the file:
		fileToWrite.close();

		// DISPLAY:
		std::cout << "save save at " << location << " under " << fileName << ".dev."
			<< std::endl;
	}
	catch (...) {
		// On error: display:
		std::cout << "Error while saving file. Please try again." << std::endl;
	}

	// DISPLAY:
	std::cout << "Writing Exited." << std::endl;
}

//Methof to read from a text file:
void FileReaderWriter::FileReaderWriter::readFromFileToMemory() {
	//Clears all current memory locations:
	memory.clearMemory();

	//Try catch errors that occur:
	try {
		//DISPLAY:
		std::cout << "Reading from file." << std::endl;

		//Get the file location from the user and set it to lowercase:
		std::string location;
		std::cout << "location of file to load: ";
		std::getline(std::cin, location);
		location = toLowerCase(location);

		//Check if the location has an extension of .dev, if not fail:
		if (location.substr(location.length() - 4, 4) == ".dev") {
			//File stream to read from:
			std::ifstream fileToRead;

			//Open the file at that location:
			fileToRead.open(location);

			//String to hold the current line being read:
			std::string idvlineInFile;

			//current memory location:
			int lineNumber = 0;

			//While loop that will go though every line in the text file:
			while (std::getline(fileToRead, idvlineInFile)) {
				//Display every line to the console before adding it to memory:
				std::cout << "[" << lineNumber << "][" << idvlineInFile << "]"
					<< std::endl;

				//Add the current line in the text file to memory:
				memory.addToMemory(idvlineInFile, lineNumber++);
			}

			//DISPLAY:
			std::cout << "Number of lines read: " << lineNumber << "." << std::endl;

			//Close the text file:
			fileToRead.close();

			//DISPLAY:
			std::cout << "Reading file finished successfully." << std::endl;
		}
		else {
			//DISPLAY:
			std::cout << "Error, file must be of type .dev." << std::endl;
		}
	}
	catch (...) {
		// DISPLAY:
		std::cout << "Error while loading file. Please try again."
			<< std::endl;
	}

	//DISPLAY:
	std::cout << "Reading Exited." << std::endl;
}

//Method that will set a give string to lowercase and then return the string:
std::string FileReaderWriter::FileReaderWriter::toLowerCase(std::string givenString) {
	//String to be returned:
	std::string returnLowerCaseString = "";

	//Loop through every letter in the strting and set it to lowercase:
	for (int i = 0; i < givenString.length(); i++)
		returnLowerCaseString += std::tolower(givenString[i]);

	//return the lowercase string:
	return returnLowerCaseString;
}