#include "ObjectFactory.h"
#include "Animal.h"
#include <iostream>

class Dog : public Animal
{
public:
	void say()
	{
		std::cout << "Wang.Wang" << std::endl;
	}

	static ObjectRegister<Animal,Dog,std::string> dummy;
};

ObjectRegister<Animal,Dog,std::string> Dog::dummy("Dog");