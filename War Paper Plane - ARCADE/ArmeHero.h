#ifndef ARMEHERO_H_INCLUDED
#define ARMEHERO_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>

#include "StructRect.h"
class ArmeHero
{
  public:

    ArmeHero();
    void tirer(Dim_Rect poshero,int etat,int cadence);
    void disparaitre(int j);
    void afficher(sf::RenderWindow &app);
    Dim_Rect getRect(int a);
    int degat();

  private:

    sf::Image _Iballe;
    sf::Sprite _Sballe;

    int _vitesse;
    int _degat;
    int _i;
    int _j;
    int _temp;
    int _tireOK[11];
    Dim_Rect _posballe[11];
};

#endif // ARMEHERO_H_INCLUDED
