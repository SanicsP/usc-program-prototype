#include "click_box.hpp"

click_box::click_box(std::shared_ptr<sf::RectangleShape> Prect , const sf::Mouse::Button & scoped )  : m_waited_boutton(scoped) 
, m_rect_ptr(Prect)
{

}


bool click_box::pressed(sf::RenderWindow& win) const 
{
    sf::Vector2f mouse_pos { sf::Mouse::getPosition(win) };
    sf::Vector2f rect_pose { m_rect_ptr->getPosition()} ;
    sf::Vector2f rect_size { m_rect_ptr->getSize() };

    bool bouttonRealesed = false;
    static bool last_state;
    bouttonRealesed =  last_state == true && !(sf::Mouse::isButtonPressed(m_waited_boutton));
    last_state = sf::Mouse::isButtonPressed(m_waited_boutton);


    bool onRect {  mouse_pos.x > rect_pose.x && mouse_pos.x < rect_pose.x + rect_size.x
                &&
                mouse_pos.y > rect_pose.y && mouse_pos.y < rect_pose.y + rect_size.y 
    }; 
    
    if(onRect && bouttonRealesed)
        return true;
        
    return false;

}