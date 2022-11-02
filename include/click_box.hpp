#ifndef CLICK_BOX_HPP
#define CLICK_BOX_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class click_box
{

public: 

    click_box(std::shared_ptr<sf::RectangleShape> Prect , const sf::Mouse::Button& scoped  );
    bool pressed(sf::RenderWindow& win , const sf::Event::MouseButtonEvent& event_bouton) const; 

    friend class manager;

private:

    std::shared_ptr<sf::RectangleShape> m_rect_ptr;
    sf::Mouse::Button m_waited_boutton;
};



#endif