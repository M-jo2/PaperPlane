#ifndef EXPLOSION_H_INCLUDED
#define EXPLOSION_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>

#include "StructRect.h"
class Explosion
{
    public:

    Explosion();
    void explose(int couleur, Dim_Rect posExplose);
    void afficher(sf::RenderWindow &app);

    private:

    int _vitesse;
    Dim_Rect _posexplose;
    Dim_Rect _poscoupe;

    int _couleur;

    int _temp;
    int _temp2;
    int _tempmax;
    sf::Image _Iexplose;
    sf::Sprite _Sexplose;

};

#endif // EXPLOSION_H_INCLUDED
