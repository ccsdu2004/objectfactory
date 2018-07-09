#include "ObjectFactory.h"

QMap<QString,std::function<QObject*()>> ObjectFactory::creator;