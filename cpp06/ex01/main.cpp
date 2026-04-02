#include "Serializer.hpp"

int	main (int ac, char **argv)
{
	(void) argv;
	if (ac != 1)
	{
		std::cout << "No argument needed\n";
		return (EXIT_FAILURE);
	}

	Data data1 = {'c', 4747, 42.0f, 24.0};

	/////
	std::cout << "Before serialize()" << std::endl
	<< "character: " << data1.character << std::endl
	<< "integer: " << data1.integer << std::endl
	<< "floatType: " << data1.floatType << std::endl
	<< "doubleType: " << data1.doubleType << std::endl
	<< "----------------------------------------------"
	<< std::endl;

	uintptr_t Serialized = Serializer::serialize(&data1);
	std::cout << "After serialize()" << std::endl
	<< "character: " << *reinterpret_cast<char *>(Serialized) << std::endl
	<< "integer: " << *reinterpret_cast<int *> (Serialized + sizeof(char)) << std::endl
	<< "floatType: " << *reinterpret_cast<float *> (Serialized + sizeof(char) + sizeof(int)) << std::endl
	<< "doubleType: " << *reinterpret_cast<float *> (Serialized + sizeof(char) + sizeof(int) + sizeof(float)) << std::endl
	<< "----------------------------------------------"
	<< std::endl;

	//////
	Data* deserialized  = Serializer::deserialize(Serialized);

	std::cout << "After deserialize()" << std::endl
	<< "character: " << deserialized->character << std::endl
	<< "integer: " << deserialized->integer << std::endl
	<< "floatType: " << deserialized->floatType << std::endl
	<< "doubleType: " << deserialized->doubleType << std::endl
	<< "----------------------------------------------"
	<< std::endl;

	return (EXIT_SUCCESS);
}
