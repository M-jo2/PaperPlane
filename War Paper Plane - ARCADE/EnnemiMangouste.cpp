#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>

#include "Vaisseau.h"
#include "StructRect.h"
#include "EnnemiMangouste.h"


const int TAILLE_X=175,TAILLE_Y=50;
using namespace sf;
using namespace std;
const int VIEMAX=20;
Mangouste::Mangouste():Vaisseau()
{
    _Iennemi.LoadFromFile("image/ennemi/mangouste.png");
    _Sennemi.SetImage(_Iennemi);
    _Sennemi.SetSubRect(IntRect(0,0,TAILLE_X,TAILLE_Y));

    srand(time(NULL));
    _RectEnnemi.posx=1000;
    _RectEnnemi.posy=0;
    _vie=VIEMAX;

    temp=0;
}

void Mangouste::Action(RenderWindow &app)
{
    if(Vaisseau::Mourir()==1)
    {
        animation();
        Bouger();
        _RectEnnemi.posx2=_RectEnnemi.posx+50;
        _RectEnnemi.posy2=_RectEnnemi.posy+TAILLE_Y;
        app.Draw(_Sennemi);
    }else
    {
        _vie=VIEMAX;
    }

}

void Mangouste::Bouger()
{
    if(_RectEnnemi.posx>=-450)
    {
        if(_RectEnnemi.posx<=750 && _RectEnnemi.posy<=500)
        {
            _RectEnnemi.posy+=6;
            _RectEnnemi.posx-=2;
        }else
        {
            _RectEnnemi.posx-=10;
        }
    }


    _Sennemi.SetPosition(_RectEnnemi.posx,_RectEnnemi.posy);
}

void Mangouste::Mourir()
{

}

void Mangouste::animation()
{
    temp++;
    if(temp<=2)
    {
        _Sennemi.SetSubRect(IntRect(0,TAILLE_Y,TAILLE_X,TAILLE_Y*2));

    }
    if(temp>=2)
    {
            _Sennemi.SetSubRect(IntRect(0,0,TAILLE_X,TAILLE_Y));
    }
    if(temp>3)
    {
        temp=0;
    }
}
Dim_Rect Mangouste::RecupBalle(int j)
{

}

Dim_Rect Mangouste::getRect()
{
    return _RectEnnemi;
}
