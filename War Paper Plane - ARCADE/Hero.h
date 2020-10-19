#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>

#include "Vaisseau.h"
#include "StructRect.h"
#include "ArmeHero.h"

class Hero:public Vaisseau
{
    public:

    Hero();
    void Action(sf::RenderWindow &app);
    void Bouger(int bouger);
    int Mourir();
    Dim_Rect gereBalle(int j, int view);
    Dim_Rect getRect();

    private:

    Dim_Rect _RectHero;
    sf::Image _Ihero;
    sf::Sprite _Shero;
    ArmeHero arme;
    Dim_Rect _posBalle;//pour la position des balles

    int _vitessex,_vitessey;
    int _vitmax;
    int i;
};

#endif // HERO_H_INCLUDED
