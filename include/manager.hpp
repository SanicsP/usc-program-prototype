#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <random>
#include <chrono>


#include "click_box.hpp"
#include "specialized_effects.hpp"




/**
 * @brief effectue les actions du programme , déplacer le rectangle aléatoirement par exemple
*/
class manager {

public : 

    manager(std::shared_ptr<sf::RectangleShape> rect_ptr , click_box* click_box_ptr , sf::VideoMode* screen_ptr , sf::RenderWindow& win);
    
    void remove_rect();

    void update(const sf::Event& event);

    void set_target_sprite_texture(const sf::Texture& texture);

    const sf::Sprite& get_sprite() const ;

    std::shared_ptr<sf::Sprite> get_sprite_ptr();





private : 

    click_box* m_click_box_ptr;

    std::shared_ptr<sf::RectangleShape> m_rect_ptr;
    
    sf::VideoMode* m_screen_ptr;
    
    sf::RenderWindow& m_win;

    std::mt19937 m_engine;

    sf::Sprite m_target_sprite;

    std::unique_ptr<basic_effect> m_sfx_ptr;

    bool m_effect_working;



};




#endif