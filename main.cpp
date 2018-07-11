#include <iostream>
#include "ObjectFactory.h"
#include "Animal.h"

int main()
{
    auto animal = ObjectFactory<Animal,std::string>::create("Dog");
    if(animal)
        animal->say();

	animal = ObjectFactory<Animal,std::string>::create("Cat");
	if (animal)
		animal->say();

	ObjectFactory<Animal,std::string>::shutdown();
    return 1;
}