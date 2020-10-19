#include "Collision.h"
#include "StructRect.h"
#include <SFML/Graphics.hpp>

Collision::Collision()
{
    COLLISION=0;
}

int Collision::testCol(Dim_Rect rect1,Dim_Rect rect2)
{
    if(rect1.posx2>rect2.posx && rect1.posy2>rect2.posy && rect1.posx<rect2.posx2 && rect1.posy<rect2.posy2)
    {
        COLLISION=1;
    }else
    {
        COLLISION=0;
    }
    return COLLISION;
}
