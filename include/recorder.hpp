#ifndef RECORDER_HPP
#define RECORDER_HPP

#include "click_box.hpp"
#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <numeric>

#define PIXEL_SIZE 0.264583




class recorder { 

public:
    
    struct text_box;

    typedef std::chrono::duration<double> r_duration;
    typedef std::chrono::time_point<std::chrono::steady_clock> r_t_point;
    recorder(std::shared_ptr<sf::RectangleShape> rect_ptr , sf::RenderWindow& win_ref);
    
   

    void update() ;

    bool rect_moved() ;

    double get_speed_mean() const ;

    double get_curret_speed() const ;

    void set_txt_box(text_box* box_ptr);



private:

    uint32_t m_counter;

    std::shared_ptr<sf::RectangleShape> m_rect_ptr;

    sf::Vector2f m_record_rect_pos;
    sf::Vector2f m_record_old_rect_pos; 


    double m_record_distbtw_mouse_rect;

    r_duration m_click_duration;
    
    r_t_point m_start_moment;
    
    r_t_point m_click_moment;

    sf::RenderWindow& m_win_ref;
    
    std::vector<double> m_recorder_speed_array;
    
    std::shared_ptr<sf::Text>* m_text_ptr;

    text_box* m_stat_box;

    void record_dist_btwnMR(sf::RenderWindow& win);

    void record_duration();

    double record_speed();

    void store_speed();


    
public:

    struct text_box : sf::Drawable
    {   
        
        text_box(const sf::Vector2f& pos , uint16_t text_size , uint16_t text_dist);

        virtual void draw(sf::RenderTarget& target , sf::RenderStates states) const;
        
        sf::Text m_counter_text;
        
        sf::Text m_current_speed_text;
        
        sf::Text m_speed_mean_text; 
        
        void replace(const sf::Vector2f& new_pos);
        
        void set_font(const sf::Font& font);

        private : 

        uint16_t m_text_size;

        uint16_t m_text_dist;

    };

};


#endif