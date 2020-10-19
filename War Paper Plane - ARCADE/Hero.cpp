#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>

#include "Vaisseau.h"
#include "StructRect.h"
#include "Hero.h"
#include "ArmeHero.h"

const int TAILLE_X=90,TAILLE_Y=50;
using namespace sf;
using namespace std;

Hero::Hero():Vaisseau()
{
    _Ihero.LoadFromFile("image/hero/avion3.png");
    _Shero.SetImage(_Ihero);
    _Shero.SetSubRect(IntRect(0,0,TAILLE_X,TAILLE_Y));

    _vie=10;
    _RectHero.posx=0;
    _RectHero.posy=0;
    _vitesseTir=10;
    _vitessex=10;
    _vitessex=10;
    _vitmax=5;
    _tireOK=0;
    _temp=0;



}



void Hero::Action(RenderWindow &app)
{
    _RectHero.posx2=_RectHero.posx+TAILLE_X;
    _RectHero.posy2=_RectHero.posy+TAILLE_Y;
    const Input &input= app.GetInput();
    if(Vaisseau::Mourir()==1)
    {
        Bouger(0);
        if(input.IsKeyDown(Key::Z))
        {
            Bouger(1);
        }else if(input.IsKeyDown(Key::S))
        {
            Bouger(2);
        }
        if (input.IsKeyDown(Key::Q))
        {
            Bouger(3);

        }else if(input.IsKeyDown(Key::D))
        {
            Bouger(4);
        }
        if (input.IsKeyDown(Key::M))
        {

            arme.tirer(_RectHero,1,70);
        }
        arme.afficher(app);
        app.Draw(_Shero);

    }else if(Vaisseau::Mourir()==0)
    {
        //Mourir();
        _RectHero.posx=1000;
        _RectHero.posy=0;
        if (input.IsKeyDown(Key::R))
        {
            _vie=10;
            _RectHero.posx=0;
            _RectHero.posy=320;
        }

    }

}

void Hero::Bouger(int bouger)
{
    if(_RectHero.posy<-TAILLE_Y)
    {
        _RectHero.posy=650;
    }
    if(_RectHero.posy>650)
    {
        _RectHero.posy=-TAILLE_Y;
    }
    if(_RectHero.posx<=0)
    {
        _RectHero.posx=0;
    }
    if(bouger==0)
    {
        _Shero.SetSubRect(IntRect(0,0,TAILLE_X,TAILLE_Y));
        if(_vitessex<0)
        {
            _vitessex+=0.1;//réinitialistaion à 0
        }
        if(_vitessex>0)
        {
            _vitessex-=0.1;//réinitialistaion à 0
        }
        if(_vitessey<0)
        {
            _vitessey+=0.1;//réinitialistaion à 0
        }
        if(_vitessey>0)
        {
            _vitessey-=0.1;//réinitialistaion à 0
        }
    }
    if(bouger==3)
    {
        _vitessex-=2;
    }
    if(bouger==4)
    {
        _vitessex+=2;
    }
    if(bouger==1)
    {
        _vitessey-=2;
        _Shero.SetSubRect(IntRect(0,TAILLE_Y*2,TAILLE_X,TAILLE_Y*3));

    }
    if(bouger==2)
    {
        _vitessey+=2;
        _Shero.SetSubRect(IntRect(0,TAILLE_Y,TAILLE_X,TAILLE_Y*2));
    }



    if(_vitessey>=_vitmax)
    {
        _vitessey=_vitmax;
    }
    if(_vitessey<=-_vitmax)
    {
        _vitessey=-_vitmax;
    }
    if(_vitessex>=_vitmax)
    {
        _vitessex=_vitmax;
    }
    if(_vitessex<=-_vitmax )
    {
        _vitessex=-_vitmax;
    }
    _RectHero.posx+=_vitessex;
    _RectHero.posy+=_vitessey;
    //positionnement de l image
    _Shero.SetPosition(_RectHero.posx,_RectHero.posy);

}

int Hero::Mourir() //evenement de la mort toussa toussa
{
    if(_vie<=0) return 0;
        //hero est mort

    return 1;
        //hero est en vie

}

Dim_Rect Hero::gereBalle(int j, int view)
{
    if(view==1)
    {
        arme.disparaitre(j);
    }
    return arme.getRect(j);
}

Dim_Rect Hero::getRect()
{
    return _RectHero;
}
