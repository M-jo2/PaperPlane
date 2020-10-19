#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>

#include "ArmeHero.h"

const int TAILLE_X=10,TAILLE_Y=10;
using namespace sf;
using namespace std;

ArmeHero::ArmeHero()
{
    _Iballe.LoadFromFile("image/hero/balle hero.png");
    _Sballe.SetImage(_Iballe);
    for(_i=0;_i<10;_i++)
    {
        _tireOK[_i]=1;

        _posballe[_i].posx=-1000;
        _posballe[_i].posy=-1000;
        _posballe[_i].posx2=TAILLE_X;
        _posballe[_i].posy2=TAILLE_Y;
    }
    _j=0;
    _vitesse=17;
    _degat=2;
}

void ArmeHero::tirer(Dim_Rect poshero,int etat,int cadence)
{

    if(_posballe[_j].posx>=1000)
    {
        disparaitre(_j);
    }

    if(etat==1 && _tireOK[_j]==1 && _temp>cadence)
    {
        //position du projectile
        _posballe[_j].posx=poshero.posx2;
        _posballe[_j].posy=poshero.posy+TAILLE_Y;
        _tireOK[_j]=0;
        _temp=0;

    }







    _j++;
    _temp++;
    if(_j>=10)
    {
        _j=0;
    }


}

void ArmeHero::disparaitre(int j)
{
    _posballe[j].posy=10000;
    _posballe[j].posx=-10000;
    _tireOK[j]=1;
}

void ArmeHero::afficher(RenderWindow &app)
{



    for(_i=0;_i<10;_i++)
    {
            _posballe[_i].posx+=_vitesse;
            _posballe[_i].posx2=_posballe[_i].posx+TAILLE_X;
            _posballe[_i].posy2=_posballe[_i].posy+TAILLE_Y;
            _Sballe.SetPosition(_posballe[_j].posx,_posballe[_i].posy);
            app.Draw(_Sballe);
    }
}
Dim_Rect ArmeHero::getRect(int a)
{

    return _posballe[a];
}

int ArmeHero::degat()
{
    return _degat;
}
