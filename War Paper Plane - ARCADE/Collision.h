#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

#include "StructRect.h"
#include <SFML/Graphics.hpp>

class Collision
{
    public:

    Collision();
    int testCol(Dim_Rect rect1,Dim_Rect rect2);

    private:

    int COLLISION;

};

#endif // COLLISION_H_INCLUDED
