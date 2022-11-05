#include "manager.hpp"


manager::manager(std::shared_ptr<sf::RectangleShape> rect_ptr , click_box* click_box_ptr , sf::VideoMode* screen_ptr , sf::RenderWindow& win) : 
m_rect_ptr(rect_ptr) , 
m_click_box_ptr(click_box_ptr) ,
m_screen_ptr(screen_ptr),
m_win(win)
{
    m_engine.seed(1);
}

void manager::remove_rect()
{
    m_engine.seed(std::chrono::system_clock::now().time_since_epoch().count());

    std::uniform_real_distribution<float> distX{0.f , m_screen_ptr->width - 100};

    std::uniform_real_distribution<float> distY{0.f , m_screen_ptr->height - 100};

    sf::Vector2f new_pos{ distX(m_engine) , distY(m_engine) };

    m_rect_ptr->setPosition(new_pos);
}

void manager::update(const sf::Event& event)
{
    if(m_click_box_ptr->pressed(m_win , event.mouseButton))
    {
        this->remove_rect();
        m_target_sprite.setPosition(m_rect_ptr->getPosition());
    }

}

void manager::set_target_sprite_texture(const sf::Texture& texture)
{
    m_target_sprite.setTexture(texture);

}

const sf::Sprite& manager::get_sprite() const 
{
    return m_target_sprite;
}

std::shared_ptr<sf::Sprite> manager::get_sprite_ptr()
{
    return std::make_shared<sf::Sprite>(&m_target_sprite);
}


