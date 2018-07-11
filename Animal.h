#include "ObjectFactory.h"

class Animal
{
public:
	virtual ~Animal() {}
	virtual void say() = 0;
};