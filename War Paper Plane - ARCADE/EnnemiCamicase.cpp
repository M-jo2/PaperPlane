#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>

#include "Vaisseau.h"
#include "StructRect.h"
#include "EnnemiCamicase.h"

const int TAILLE_X=150,TAILLE_Y=75;
using namespace sf;
using namespace std;
const int VIEMAX=20;
Camicase::Camicase():Vaisseau()
{
    _Iennemi.LoadFromFile("image/ennemi/camicase.png");
    _Sennemi.SetImage(_Iennemi);
    _Sennemi.SetSubRect(IntRect(0,0,TAILLE_X,TAILLE_Y));

    srand(time(NULL));
    _RectEnnemi.posx=1000;
    _RectEnnemi.posy=rand()%(650-TAILLE_Y);
    _vie=VIEMAX;

    temp=0;
}

void Camicase::Action(RenderWindow &app)
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
        Mourir();
        _vie=VIEMAX;
    }

}

void Camicase::Bouger()
{
    if(_RectEnnemi.posx>=-450)
    {
        _RectEnnemi.posx-=10;
    }

    _Sennemi.SetPosition(_RectEnnemi.posx,_RectEnnemi.posy);
}

void Camicase::Mourir()
{
    _RectEnnemi.posx=1200;
    _RectEnnemi.posy=rand()%(650-TAILLE_Y);
}

void Camicase::animation()
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
Dim_Rect Camicase::RecupBalle(int j)
{

}

Dim_Rect Camicase::getRect()
{
    return _RectEnnemi;
}
