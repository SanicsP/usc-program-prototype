#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <random>
#include <chrono>

#include "click_box.hpp"



class manager {

public : 

    manager(std::shared_ptr<sf::RectangleShape> rect_ptr , click_box* click_box_ptr , sf::VideoMode* screen_ptr , sf::RenderWindow& win);
    
    void remove_rect();

    void update(const sf::Event& event);



private : 

    click_box* m_click_box_ptr;

    std::shared_ptr<sf::RectangleShape> m_rect_ptr;
    
    sf::VideoMode* m_screen_ptr;
    
    sf::RenderWindow& m_win;

    std::mt19937 m_engine;


};




#endif