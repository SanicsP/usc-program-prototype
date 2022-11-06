#include "specialized_effects.hpp"

size_oscilation_effect::size_oscilation_effect(double w , double min , double max , sf::Time duration , 
const std::shared_ptr<sf::RectangleShape>& rect_ptr , const std::shared_ptr<sf::Sprite>& sprite_ptr) : 
basic_effect(rect_ptr , sprite_ptr , duration) , 
m_omega(w) , m_min(min) , m_max(max) , m_first_call(true)
{

}

void size_oscilation_effect::update()
{
    static sf::RectangleShape save_rect;
    static sf::Sprite save_sprite;
    if(m_first_call) { 
        save_rect = *m_rect_ptr;
        save_sprite = *m_sprite_ptr;
    }   
    float result;
    if(m_activated)
    {
    
        if(m_clock.getElapsedTime().asSeconds() >= m_effect_duration.asSeconds()) {
            effect_on(false);
            m_finished = true;
            *m_rect_ptr = save_rect;
            *m_sprite_ptr = save_sprite; 
        }
        else
        {
            result = sin(m_clock.getElapsedTime().asSeconds() * m_omega) * (m_max - m_min) + m_min;    
            m_rect_ptr->setSize(sf::Vector2f(result , result ));
            m_sprite_ptr->setScale(sf::Vector2f(result , result));
        }

    }
    m_first_call = false;
}
