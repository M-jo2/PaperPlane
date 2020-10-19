#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "jeu.h"
#include "hero.h"
#include "EnnemiCamicase.h"
#include "EnnemiMangouste.h"
#include "Collision.h"
#include "Explosion.h"

using namespace sf;
using namespace std;

Jeu::Jeu() : posx(0),_temps(0),_score(0),_niveau(0)
{
    _Ifond.LoadFromFile("image/fond/url.jpg");
    _Sfond.SetImage(_Ifond);
}

void Jeu::Lejeu(RenderWindow &app)
{
    posx-=0.2;
    _Sfond.SetPosition(posx,-200);
    app.Draw(_Sfond);
    _hero.Action(app);



    if(_hero.Vaisseau::Mourir()==0)
    {
        _score=0;
        _niveau=0;
    }
    Niveau1(app);

    for(int _j=0;_j<50;_j++)
    {
        _explosion[_j].afficher(app);//permet d afficher les explosion
    }
    _temps++;
}

void Jeu::Niveau1(RenderWindow &app)
{
    if(_temps>10)_camicase[0].Action(app);
    if(_temps>30)_camicase[1].Action(app);
    if(_temps>40)_mangouste[2].Action(app);
    if(_temps>60)_camicase[3].Action(app);
    if(_temps>90)_camicase[4].Action(app);

    for(int _i=0;_i<5;_i++)
    {
        //collision avec les vaisseau.
        if(_collision.testCol(_hero.getRect(),_camicase[_i].getRect())==1)
        {
            //_hero.PrendreDegat(20);
            _camicase[_i].PrendreDegat(20);
            _explosion[_i].explose(3,_camicase[_i].getRect());
            _explosion[_i+1].explose(2,_hero.getRect());
        }
        //collision avec les balle.
        for(int _j=0;_j<10;_j++)
        {
            if(_collision.testCol(_hero.gereBalle(_j,0),_camicase[_i].getRect())==1)
            {
                _explosion[_j+6].explose(3,_camicase[_i].getRect());
                _camicase[_i].PrendreDegat(20);
                _hero.gereBalle(_j,1);
                _score++;

            }
        }
    }
}
