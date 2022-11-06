#include <SFML/Graphics.hpp>

#include <iostream>

#include "manager.hpp"
#include "click_box.hpp"
#include "recorder.hpp"
#include "session.hpp"

int main()
{

    sf::RectangleShape rect_test{sf::Vector2f(70 , 40)};
    rect_test.setFillColor({255 , 127 , 0});
    sf::VideoMode win_size{800 , 800};
    
    sf::Font font;
    sf::Texture target_texture;
    
    if(!font.loadFromFile("ressources/lato-bold.ttf") || !(target_texture.loadFromFile("ressources/target_texture.png")))
    {
        std::cout<<"aucune police trouvee\n";
        exit(1);
    }



    sf::RenderWindow win{win_size , "DEFAULT"};

    click_box rect_boutton{std::shared_ptr<sf::RectangleShape>(&rect_test) , sf::Mouse::Button::Left };

    manager manage_test{std::shared_ptr<sf::RectangleShape>(&rect_test) , &rect_boutton , &win_size , win};
    manage_test.set_target_sprite_texture(target_texture);
    recorder stats{std::shared_ptr<sf::RectangleShape>(&rect_test) , win};

    recorder::text_box stats_text {sf::Vector2f(300 , 0) , 10 , 20};


    stats_text.set_font(font);
    stats.set_txt_box(&stats_text);

    std::cout<<"start\n P : pause\n R : restart\n Q : quitt\n";
    
    sf::Event win_event;
    session PROGRAMM(&stats , &manage_test , win , win_event);

    while(win.isOpen())
    {
        // execution des différentes phases du programme 
        if(PROGRAMM.stat() == step::START)
        {
           PROGRAMM.s_start();
           manage_test.update();

        }
        else if(PROGRAMM.stat() == step::RESTART)
        {
           PROGRAMM.s_restart();
        }
        else if(PROGRAMM.stat() == step::END)
        {
            PROGRAMM.s_end();
        }
        else // pause 
        {
            PROGRAMM.s_pause();
        }

        
        while (win.pollEvent(win_event)) // Traitement des évennements de la fenêtre 
        {
            if(win_event.type == sf::Event::Closed) {
               win.close();
            }

            else if(win_event.type == sf::Event::MouseButtonReleased)
            {
            
            }

            if(win_event.type == sf::Event::KeyReleased)
            {
                switch(win_event.key.code )
                {
                    case sf::Keyboard::Q :
                    {
                        PROGRAMM.set_stat(step::END);
                        break;
                    }
                    case sf::Keyboard::P : 
                    {
                        PROGRAMM.set_stat(step::PAUSE);
                        break;
                    }
                    case sf::Keyboard::R : 
                    {
                        PROGRAMM.set_stat(step::RESTART);
                        break;
                    }

                }
            
            } 

            if(win_event.type == sf::Event::LostFocus)
            {
                PROGRAMM.set_stat(step::PAUSE);
            }
        }
        
        //Affichage 
        win.clear(sf::Color::Black);

        win.draw(rect_test);
        win.draw(stats_text);
        win.draw(manage_test.get_sprite());

        win.display();

        
    }
    

    
    return 0;
}