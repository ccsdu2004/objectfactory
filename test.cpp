#include <iostream>
#include "ObjectFactory.h"

class Animal : public QObject
{
public:
    virtual ~Animal(){}
    virtual void say() = 0;   
};

class Dog : public Animal
{
public:
    void say()
    {
        std::cout<<"Wang!Wang"<<std::endl;   
    }

    static ObjectRegister<Dog> dummy;   
};

ObjectRegister<Dog> Dog::dummy("Dog")

int main()
{
    Animal* animal = ObjectFactory::create<Animal>("Dog");
    if(animal)
        animal->say();
    return 1;
}