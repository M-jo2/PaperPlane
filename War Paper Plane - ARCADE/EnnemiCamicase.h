#ifndef ENNEMICAMICASE_H_INCLUDED
#define ENNEMICAMICASE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>

#include "Vaisseau.h"
#include "StructRect.h"

class Camicase:public Vaisseau
{
    public:

    Camicase();
    void Action(sf::RenderWindow &app);
    void Bouger();
    void Mourir();
    void animation();
    Dim_Rect RecupBalle(int j);
    Dim_Rect getRect();

    private:

    Dim_Rect _RectEnnemi;
    sf::Image _Iennemi;
    sf::Sprite _Sennemi;
    //ArmeEnnemi arme;
    Dim_Rect _posBalle;//pour la position des balles

    int temp;

};

#endif // ENNEMICAMICASE_H_INCLUDED
