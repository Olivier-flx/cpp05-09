#include "Base.hpp"

static void test_print(Base &base)
{
	static int i = 0;

	std::cout << "======= test : " << static_cast<char> ('d' + i) << " ========\n";
		identify(&base);
		identify(base);
	std::cout << std::endl << std::endl;
	i++;
}

int	main (int ac, char **argv)
{
	//for randomize Base generatedresult
	std::srand(std::time(0));

	(void) argv;
	if (ac != 1)
	{
		std::cout << "No argument needed\n";
		return (EXIT_FAILURE);
	}

	Base *d = generate();
	Base *e = generate();
	Base *f = generate();
	Base *g = generate();
	Base *h = generate();
	Base *i = generate();

	test_print(*d);
	test_print(*e);
	test_print(*f);
	test_print(*g);
	test_print(*h);
	test_print(*i);

	delete d;
	delete e;
	delete f;
	delete g;
	delete h;
	delete i;

	return (EXIT_SUCCESS);
}
