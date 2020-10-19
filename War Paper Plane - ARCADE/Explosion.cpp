#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include "Explosion.h"
#include "StructRect.h"

const int TAILLE_X=80,TAILLE_Y=80;

using namespace sf;
using namespace std;

Explosion::Explosion()
{
    _poscoupe.posx=0;
    _poscoupe.posy=0;
    _poscoupe.posx2=0;
    _poscoupe.posy2=0;
    _Iexplose.LoadFromFile("image/explosion/explosion 2.png");
    _Sexplose.SetImage(_Iexplose);
    Image _Iexplose;
    Sprite _Sexplose;
    _tempmax=1;
    _vitesse=10;
    _temp=10000;
    _temp2=0;
}

void Explosion::explose(int couleur, Dim_Rect posExplose)
{
    _posexplose.posx=posExplose.posx+(posExplose.posx2-posExplose.posx)/2-TAILLE_X;
    _posexplose.posy=posExplose.posy;
    _temp=0;
    if(_temp==0)
    {
        if(couleur==0)
        {
            _couleur=27;
            _poscoupe.posx=0;
            _poscoupe.posy=0;
        }

        if(couleur==1)
        {
            _couleur=35;
            _poscoupe.posx=0;
            _poscoupe.posy=TAILLE_Y*4;
        }
        if(couleur==2)
        {
            _couleur=27;
            _poscoupe.posx=0;
            _poscoupe.posy=TAILLE_Y*9;
        }
        if(couleur==3)
        {
            _couleur=35;
            _poscoupe.posx=0;
            _poscoupe.posy=TAILLE_Y*13;
        }
        if(couleur==4)
        {
            _couleur=27;
            _poscoupe.posx=0;
            _poscoupe.posy=TAILLE_Y*18;
        }
        _poscoupe.posx2=_poscoupe.posx+TAILLE_X;
        _poscoupe.posy2=_poscoupe.posy+TAILLE_Y;
    }
    _Sexplose.SetPosition(_posexplose.posx,_posexplose.posy);
}

void Explosion::afficher(RenderWindow &app)
{
    if(_temp<=_couleur*_tempmax)
    {
        if(_temp-_temp2==_tempmax)
        {
            if(_poscoupe.posx<=480)
            {
                _poscoupe.posx2+=TAILLE_X;
                _poscoupe.posx+=TAILLE_X;

            }else
            {
                _poscoupe.posy+=TAILLE_Y;
                _poscoupe.posx=0;
                _poscoupe.posx2=_poscoupe.posx+TAILLE_X;
                _poscoupe.posy2=_poscoupe.posy+TAILLE_Y;

            }
            _temp2=_temp;
        }


    }else
    {
        _poscoupe.posx=0;
        _poscoupe.posy=0;
        _poscoupe.posx2=0;
        _poscoupe.posy2=0;
        _temp2=0;
    }
    _temp++;

    _Sexplose.SetSubRect(IntRect(_poscoupe.posx,_poscoupe.posy,_poscoupe.posx2,_poscoupe.posy2));
    app.Draw(_Sexplose);
}
