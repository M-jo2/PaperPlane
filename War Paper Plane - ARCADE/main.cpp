#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "jeu.h"

using namespace sf;
using namespace std;

int main()
{

    RenderWindow app(VideoMode(950, 650, 32), "War Paper Plane");
    app.SetFramerateLimit(60);

    int etape=1;//menu-jeu-fin
    Image Imenu;
    Sprite Smenu;
    Imenu.LoadFromFile("image/fond/menu.jpg");
    Smenu.SetImage(Imenu);
    Jeu jeu;

    // Boucle principale
    while (app.IsOpened())
    {
        Event event;

        while (app.GetEvent(event))
        {
            if (event.Type == Event::Closed)
                app.Close();
        }
        //const Input &input= app.GetInput();
        if(etape==0)
        {
            app.Draw(Smenu);
        }
        if(etape==1)
        {
            jeu.Lejeu(app);
        }
        // Affichage de la fenêtre à l'écran
        app.Display();
        // Remplissage de l'écran (couleur noire par défaut)
        app.Clear();
    }

    return EXIT_SUCCESS;
}
