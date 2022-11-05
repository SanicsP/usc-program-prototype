#include "effect.hpp"

basic_effect::basic_effect(const std::shared_ptr<sf::RectangleShape>& rect_ptr , const std::shared_ptr<sf::Sprite>& sprite_ptr , sf::Time duration) :
m_rect_ptr(rect_ptr) , m_sprite_ptr(sprite_ptr) , m_effect_duration(duration) , m_activated(false) , m_finished(false)
{

}

void basic_effect::effect_on(bool b)
{
    m_clock.restart();
    m_activated = b;
}

bool basic_effect::is_activated()
{
    return m_activated;
}

bool basic_effect::is_finished()
{
    return m_finished;
}
