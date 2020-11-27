//
// Created by nicol on 26/11/2020.
//

#include "affichageGraphique.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <time.h>
#include <iostream>


void erreur(const char *txt) {
    ALLEGRO_DISPLAY *d;
    d = al_is_system_installed() ? al_get_current_display() : NULL;
    al_show_native_message_box(d, "Erreur", txt, NULL, NULL, 0);
    exit(EXIT_FAILURE);
}


void affichageGraphique() {
    srand(time(NULL));

    //Creation des éléments nécessaires (ALLEGRO) et initialisation de variables

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_KEYBOARD_STATE key;
    ALLEGRO_BITMAP *image;
    ALLEGRO_MOUSE_STATE mouse;

    int isEnd = 0;
    int isEnd2 = 0;

    if (!al_init()) // Init allegro avec gestion erreur
    {
        erreur("al_init()");
    }

    if (!al_install_keyboard()) // init clavier (avec gestion erreur)
    {
        erreur("al_install_keyboard()");
    }

    if (!al_init_image_addon()) // [..] avec gestion d'erreur
    {
        erreur("al_init_image_addon()");
    }

    display = al_create_display(1050, 800); //  Creation de la fenetre
    if (!display) // Gestion erreur
    {
        erreur("al_create_display()");
    }

    if (!al_install_mouse()) //[..] + gestion erreur
    {
        erreur("al_install_mouse()");
    }

    image = al_load_bitmap("../Conception/Presentation-personages.bmp"); // Téléchargement image
    if (!image) // gestion erreur
    {
        erreur("al_load_bitmap()");
    }


    al_draw_bitmap(image, 0, 0, ALLEGRO_RESIZABLE);
    al_flip_display();
    al_set_window_position(display, 0, 0);


    int Zelda = 0, ND = 0, Sonic = 0, Mario = 0, Cs = 0, fin = 0;

    while (isEnd == 0) { // Tant qu'on ferme pas la fenetre

        al_get_keyboard_state(&key); // On recupere informations clavier ..
        al_get_mouse_state(&mouse); // .. et informations souri

        if (al_key_down(&key, ALLEGRO_KEY_ESCAPE)) { // Touche Echap appuyée
            isEnd = 1; // On fait quitter
        }

        if ((mouse.buttons & 1) || (mouse.buttons & 2) || (mouse.buttons & 4)) { // Si souri clique (peu importe bouton)


            // Si curseur placé sur une des images, on retient dans une des variables que l'image a été "cliquée"

            if ((mouse.x <= (250)) && (mouse.x >= 37) && (mouse.y <= 313) && (mouse.y >= 100)) {
                Zelda = 1;
                Mario = 0;
                Sonic = 0;
                Cs = 0;
                ND = 0;

            } else if ((mouse.x <= (450)) && (mouse.x >= 275) && (mouse.y <= 313) && (mouse.y >= 100)) {
                Zelda = 0;
                Mario = 0;
                Sonic = 0;
                Cs = 0;
                ND = 1;
            } else if ((mouse.x <= (650)) && (mouse.x >= 475) && (mouse.y <= 313) && (mouse.y >= 100)) {
                Zelda = 0;
                Mario = 0;
                Sonic = 1;
                Cs = 0;
                ND = 0;
            } else if ((mouse.x <= (850)) && (mouse.x >= 675) && (mouse.y <= 313) && (mouse.y >= 100)) {
                Zelda = 0;
                Mario = 1;
                Sonic = 0;
                Cs = 0;
                ND = 0;
            } else if ((mouse.x <= (1025)) && (mouse.x >= 875) && (mouse.y <= 313) && (mouse.y >= 100)) {
                Zelda = 0;
                Mario = 0;
                Sonic = 0;
                Cs = 1;
                ND = 0;
            }
        }

        // Si l'image a été cliquée, on affiche les choses qui lui correspondent tant que l'utilisateur n'appuye pas sur 'B' pour quitter

        if (Zelda) {

            image = al_load_bitmap("../Conception/Zelda.bmp");
            while (!isEnd2) {
                al_draw_bitmap(image, 0, 0, ALLEGRO_RESIZABLE);
                al_flip_display();
                al_get_keyboard_state(&key);
                al_get_mouse_state(&mouse);

                if (al_key_down(&key, ALLEGRO_KEY_B)) {
                    isEnd2 = 1;
                }
            }
            isEnd2 = 0;

            Zelda = 0;


        } else if (ND) {

            image = al_load_bitmap("../Conception/ND.bmp");
            while (!isEnd2) {
                al_draw_bitmap(image, 0, 0, ALLEGRO_RESIZABLE);
                al_flip_display();
                al_get_keyboard_state(&key);
                al_get_mouse_state(&mouse);

                if (al_key_down(&key, ALLEGRO_KEY_B)) {
                    isEnd2 = 1;
                }
            }
            isEnd2 = 0;


            ND = 0;


        } else if (Sonic) {

            image = al_load_bitmap("../Conception/Sonic.bmp");
            while (!isEnd2) {
                al_draw_bitmap(image, 0, 0, ALLEGRO_RESIZABLE);
                al_flip_display();
                al_get_keyboard_state(&key);
                al_get_mouse_state(&mouse);

                if (al_key_down(&key, ALLEGRO_KEY_B)) {
                    isEnd2 = 1;
                }
            }
            isEnd2 = 0;

            Sonic = 0;

        } else if (Mario) {
            image = al_load_bitmap("../Conception/Mario.bmp");
            while (!isEnd2) {
                al_draw_bitmap(image, 0, 0, ALLEGRO_RESIZABLE);
                al_flip_display();
                al_get_keyboard_state(&key);
                al_get_mouse_state(&mouse);

                if (al_key_down(&key, ALLEGRO_KEY_B)) {
                    isEnd2 = 1;
                }
            }
            isEnd2 = 0;

            Mario = 0;

        } else if (Cs) {

            image = al_load_bitmap("../Conception/ND.bmp");
            while (!isEnd2) {
                al_draw_bitmap(image, 0, 0, ALLEGRO_RESIZABLE);
                al_flip_display();
                al_get_keyboard_state(&key);
                al_get_mouse_state(&mouse);

                if (al_key_down(&key, ALLEGRO_KEY_B)) {
                    isEnd2 = 1;
                }
            }
            isEnd2 = 0;

            Cs = 0;

        }
        image = al_load_bitmap("../Conception/Presentation-personages.bmp");
        al_draw_bitmap(image, 0, 0, ALLEGRO_RESIZABLE);
        al_flip_display();
    }

    // On détruit les éléments chargés

    al_destroy_display(display);
    al_destroy_bitmap(image);


}
