#include <iostream>
#include "Array.hpp"

int main(void)
{
	// Construction vide
	Array<int> empty;
	std::cout << "Empty size: " << empty.size() << std::endl;

	// Construction avec n
	Array<int> ints(5);
	for (unsigned int i = 0; i < ints.size(); i++)
		ints[i] = i * 10;
	std::cout << "Ints: ";
	for (unsigned int i = 0; i < ints.size(); i++)
		std::cout << ints[i] << " ";
	std::cout << std::endl;

	// Copie : modifier l'original n'affecte pas la copie
	Array<int> copy(ints);
	ints[0] = 999;
	std::cout << "Original after modif	: " << ints[0] << std::endl;
	std::cout << "Copy untouched		: " << copy[0] << std::endl;

	// Operateur = : modifier la copie n'affecte pas l'original
	Array<int> assigned;
	assigned = copy;
	assigned[1] = 888;
	std::cout << "Copy untouched	: " << copy[1] << std::endl;
	std::cout << "Assigned modified	: " << assigned[1] << std::endl;

	// Initialisation par defaut (le tip du sujet : new T[n]())
	Array<int> zeroed(3);
	std::cout << "Default init: ";
	for (unsigned int i = 0; i < zeroed.size(); i++)
		std::cout << zeroed[i] << " ";
	std::cout << std::endl;

	// Exception out of bounds
	try {
		std::cout << ints[100] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Tableau vide : toute acces lance une exception
	try {
		std::cout << empty[0] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception on empty: " << e.what() << std::endl;
	}

	// Test avec un autre type
	Array<std::string> words(3);
	words[0] = "cpp";
	words[1] = "templates";
	words[2] = "42";
	std::cout << "Strings: ";
	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << words[i] << " ";
	std::cout << std::endl;

	return 0;
}
