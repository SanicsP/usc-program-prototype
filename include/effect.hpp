#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class basic_effect 
{

public : 
    basic_effect(const std::shared_ptr<sf::RectangleShape>& rect_ptr , const std::shared_ptr<sf::Sprite>& sprite_ptr , sf::Time duration);
    
    void effect_on(bool b); 
    
    bool is_activated();
    bool is_finished();

    virtual void update() = 0;



protected : 
    
    std::shared_ptr<sf::RectangleShape> m_rect_ptr;

    std::shared_ptr<sf::Sprite> m_sprite_ptr;

    bool m_activated; 
    bool m_finished;

    sf::Clock m_clock;

    sf::Time m_effect_duration;

};


#endif