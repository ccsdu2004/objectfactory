#ifndef SUPPORT_OBJECT_FACTORY_H
#define SUPPORT_OBJECT_FACTORY_H
#include <QMap>
#include <QString>
#include <functional>

class ObjectFactory
{
public:
    template<class Target>
    static Target* create(const QString& name)
    {
        auto itr = creator.find(name);
        if (itr != creator.end())
        {
            QObject* ptr = itr.value()();
            if (!ptr)
                return nullptr;
            return dynamic_cast<Target*>(ptr);
        }
        return nullptr;
    }
   
    static QMap<QString,std::function<QObject*()>> creator;

    template<class Object>
    QObject* createObject()
    {
        return new Object();
    };
};

template<class Object>
class ObjectRegister : public ObjectFactory
{
public:
    ObjectRegister(const QString& name)
    {
        auto fn = std::bind(&ObjectFactory::createObject<Object>,this);
        creator.insert(name,fn);
    }
};

#endif