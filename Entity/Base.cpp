#include "Base.h"

short Base::getBaseId()
{
    static short counter = 0;
    counter++;
    id = counter;
    return id;
}

inline Base::~Base()
{
    id = 0;
}