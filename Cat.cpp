#include "ObjectFactory.h"
#include "Animal.h"
#include <iostream>

class Cat : public Animal
{
public:
	void say()
	{
		std::cout << "MiaoMiao" << std::endl;
	}

	static ObjectRegister<Animal,Cat,std::string> dummy;
};

ObjectRegister<Animal,Cat,std::string> Cat::dummy("Cat");