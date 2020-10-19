#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "hero.h"
#include "EnnemiCamicase.h"
#include "EnnemiMangouste.h"
#include "Collision.h"
#include "Explosion.h"

class Jeu
{
    public:

    Jeu();
    void Lejeu(sf::RenderWindow &app);
    void BarreEtat(sf::RenderWindow &app);
    void Niveau1(sf::RenderWindow &app);
    private:
    //objet
    sf::Image _Ifond;
    sf::Sprite _Sfond;

    Hero _hero;
    Camicase _camicase[8];
    Mangouste _mangouste[8];

    Explosion _explosion[50];

    Collision _collision;
    double posx;

    int _temps;//gerer le temps
    int _niveau;//gerer les niveau
    int _score;// ///////// score
    int _vague;// pour les vague d ennemi
    std::string _scoret;
};

#endif // JEU_H_INCLUDED
