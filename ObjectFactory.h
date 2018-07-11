#ifndef SUPPORT_OBJECT_FACTORY_H
#define SUPPORT_OBJECT_FACTORY_H
#include <functional>
#include <map>
#include <memory>

template<class Product,class ID>
class ObjectFactory
{
public:
    static std::shared_ptr<Product> create(const ID& id)
    {
        auto itr = creator->find(id);
        if (itr != creator->end())
        {
			return itr->second();
        }
		return nullptr;
    }
   
	static std::map<ID,std::function<std::shared_ptr<Product>()>>* creator;

	static void initialize()
	{
		if (!creator)
			creator = new std::map<ID, std::function<std::shared_ptr<Product>()>>();
	}

	static void shutdown()
	{
		if (creator)
			delete creator;
		creator = nullptr;
	}

	template<class Target>
    static std::shared_ptr<Product> createObject()
    {
        return std::shared_ptr<Product>(new Target());
    };
};
     
template<class Product,class Target,class ID>
class ObjectRegister : public ObjectFactory<Product,ID>
{
public:
    ObjectRegister(const ID& id)
    {
		initialize();
		auto fn = &ObjectFactory::createObject<Target>;
		(*creator)[id] = fn;
    }
};

template<class Product,class ID>
std::map<ID,std::function<std::shared_ptr<Product>()>>* ObjectFactory<Product,ID>::creator = nullptr;

#endif