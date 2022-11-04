#include <SFML/Graphics.hpp>

#include <iostream>

#include "manager.hpp"
#include "click_box.hpp"
#include "recorder.hpp"


int main()
{

    sf::RectangleShape rect_test{sf::Vector2f(70 , 40)};
    rect_test.setFillColor({255 , 127 , 0});
    sf::VideoMode win_size{500 , 500};

    sf::RenderWindow win{win_size , "DEFAULT"};

    click_box rect_boutton{std::shared_ptr<sf::RectangleShape>(&rect_test) , sf::Mouse::Button::Left };

    manager manage_test{std::shared_ptr<sf::RectangleShape>(&rect_test) , &rect_boutton , &win_size , win};

    recorder stats{std::shared_ptr<sf::RectangleShape>(&rect_test) , win};
    
    
   

  
    

    recorder::text_box stats_text {sf::Vector2f(300 , 0) , 10 , 20};


    sf::Font font;
    

    if(!font.loadFromFile("ressources/lato-bold.ttf"))
    {
        std::cout<<"aucune police trouvee\n";
        exit(1);
    }

    stats_text.set_font(font);
    stats.set_txt_box(&stats_text);



    
  
    
    while(win.isOpen())
    {
        
        sf::Event win_event;
        while (win.pollEvent(win_event))
        {
            if(win_event.type == sf::Event::Closed) {
               win.close();
            }

            else if(win_event.type == sf::Event::MouseButtonReleased)
            {
                manage_test.update(win_event);
            } 
        }
        
        stats.update();

        win.clear(sf::Color::Black);

        win.draw(rect_test);
        win.draw(stats_text);

        win.display();

        
    }
    

    
    return 0;
}