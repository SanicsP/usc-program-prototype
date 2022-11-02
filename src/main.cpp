#include <SFML/Graphics.hpp>

#include <iostream>

#include "manager.hpp"
#include "click_box.hpp"


int main()
{

    sf::RectangleShape rect_test{sf::Vector2f(70 , 40)};
    rect_test.setFillColor(sf::Color::Red);
    sf::VideoMode win_size{500 , 500};

    sf::RenderWindow win{win_size , "DEFAULT"};

    click_box rect_boutton{std::shared_ptr<sf::RectangleShape>(&rect_test) , sf::Mouse::Button::Left };

    manager manage_test{std::shared_ptr<sf::RectangleShape>(&rect_test) , &rect_boutton , &win_size , win};
  
    
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

        win.clear(sf::Color::Black);

        win.draw(rect_test);

        win.display();

        
    }
    

    
    return 0;
}