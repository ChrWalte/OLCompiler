/*
OneLang Compiler

WHAT HAS BEEN USED IN THIS PROJECT:
	Opening screen with a description of the application and instructions -Tells user if they need help to type help.
	Menu for the user to choose options - Main menu, waiting for commands.
	At least 4 classes total - 6 classes in total.
	Encapsulation - Public and private variables and methods.
	File input and output processing - Both in the compiler and the language in itself.
	Vector - Where the memory is stored and where the variables are stored.
	Iterator - The line of code is an iterator that keeps track of where it is in the code/ memory.
	Exception handling - Many try, catch, and throws. Application should not crash and burn . . . don't try.

WHAT HAS NOT BEEN USED IN THIS PROJECT (MAX FIVE):
	Inheritance(minimum 2 derived classes) - Only did one. :(
	Polymorphism - Overloading yes, overriding no. :(
	Multi - Threading - Didn't find a use in this particular application.
	Templates - Could have been used but not too familiar with it.
	Recursion - BLAH!!!

Things I plan to add after this class:
	I want to make all the variables type safe.

*/

// Include only the Command Line Interface. That is where the magic happens.
#include "CLI.h"

// New CLI object where the main application loop is. Program enters and exits
// here:
int main() { CLI::CLI cli = CLI::CLI(); }