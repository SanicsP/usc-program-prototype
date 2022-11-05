#ifndef EFFECT_HPP
#define EFFECT_HPP

#include "manager.hpp"

class basic_effect 
{

public : 
    basic_effect(const std::shared_ptr<sf::RectangleShape>& rect_ptr , const std::shared_ptr<sf::Sprite>& sprite_ptr);
    
    void effect_on(bool b); 
    
    bool is_activated();

    virtual void update() = 0;

    virtual ~basic_effect() = 0;


protected : 
    
    std::shared_ptr<sf::RectangleShape> m_rect_ptr;

    std::shared_ptr<sf::Sprite> m_sprite_ptr;

    bool m_activated; 

    sf::Clock m_clock;

};


#endif