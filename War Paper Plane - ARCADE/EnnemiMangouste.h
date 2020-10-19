#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>

#include "Vaisseau.h"
#include "StructRect.h"

class Mangouste:public Vaisseau
{
    public:

    Mangouste();
    void Action(sf::RenderWindow &app);
    void Bouger();
    void Mourir();
    void animation();
    Dim_Rect RecupBalle(int j);
    Dim_Rect getRect();

    protected:

    Dim_Rect _RectEnnemi;
    sf::Image _Iennemi;
    sf::Sprite _Sennemi;
    //ArmeEnnemi arme;
    Dim_Rect _posBalle;//pour la position des balles

    int temp;

};

#endif // ENNEMI_H_INCLUDED
