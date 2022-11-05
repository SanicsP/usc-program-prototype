#ifndef SPECIALIZED_EFFECTS_HPP
#define SPECIALIZED_EFFECTS_HPP

#include "effect.hpp"
#include <cmath>
#include <iostream>
class size_oscilation_effect  : public basic_effect {

public : 
    
    size_oscilation_effect(double w , double min , double max , sf::Time duration , 
const std::shared_ptr<sf::RectangleShape>& rect_ptr , const std::shared_ptr<sf::Sprite>& sprite_ptr);

    virtual void update();

private : 

    double m_omega;
    double m_min;
    double m_max;


};




#endif