#include "recorder.hpp"


recorder::recorder(std::shared_ptr<sf::RectangleShape> rect_ptr , sf::RenderWindow& win_ref) : 
m_rect_ptr(rect_ptr) , m_win_ref(win_ref) , m_counter(0)
{
    m_record_rect_pos =  m_rect_ptr->getPosition() ;
    m_start_moment = std::chrono::steady_clock::now() ; 
    
    sf::Vector2f dist_vector = sf::Vector2f ( 
        
          sf::Mouse::getPosition(m_win_ref).x - m_record_rect_pos.x , 
          sf::Mouse::getPosition(m_win_ref).y - m_record_rect_pos.y

    );

    m_record_distbtw_mouse_rect = sqrt(pow(dist_vector.x , 2) + pow(dist_vector.y , 2));



}

bool recorder::rect_moved() 
{
    if(!(m_record_rect_pos == m_rect_ptr->getPosition()))
    {
        m_record_old_rect_pos = m_record_rect_pos;
        m_record_rect_pos = m_rect_ptr->getPosition();
    
    }
    
    
}

double recorder::record_speed()
{
    return PIXEL_SIZE * m_record_distbtw_mouse_rect / m_click_duration.count()  ;
}

void recorder::store_speed()
{

    m_recorder_speed_array.push_back(record_speed());

}


void recorder::record_dist_btwnMR(sf::RenderWindow& win)
{
    sf::Vector2f dist_vector = sf::Vector2f ( 
        
          sf::Mouse::getPosition(win).x - m_record_rect_pos.x , 
          sf::Mouse::getPosition(win).y - m_record_rect_pos.y

    );

    m_record_distbtw_mouse_rect = sqrt(pow(dist_vector.x , 2) + pow(dist_vector.y , 2));

}

void recorder::record_duration()
{
    m_click_moment = std::chrono::steady_clock::now();
    m_click_duration = m_click_moment - m_start_moment;
    m_start_moment = std::chrono::steady_clock::now();
}

void recorder::update()
{
    if(rect_moved())
    {
        m_counter++;
        record_duration();
        record_dist_btwnMR(m_win_ref);
        record_speed();
        store_speed();

       



    }

}

double recorder::get_speed_mean() const 
{
    return std::accumulate(m_recorder_speed_array.begin() , m_recorder_speed_array.end() , 0) / m_recorder_speed_array.size();
}

double recorder::get_curret_speed() const 
{
    return m_recorder_speed_array.back();
}

void recorder::set_txt_box(text_box* box_ptr)
{
    m_stat_box = box_ptr;
}

///////////////////////////////////////////////////////////////////////////////////

recorder::text_box::text_box(const sf::Vector2f& pos , uint16_t text_size , uint16_t text_dist) : 
m_text_size(text_size) ,
m_text_dist(text_dist) 
{


    this->replace(pos);
}

void recorder::text_box::replace(const sf::Vector2f& new_pos)
{
    /* m_counter_text.setPosition(new_pos);
    
    m_current_speed_text.setPosition(sf::Vector2f{m_counter_text.getPosition().x , 
                                    m_counter_text.getPosition().y + m_text_dist});
    
    m_speed_mean_text.setPosition(sf::Vector2f{m_current_speed_text.getPosition().x 
                                  , m_current_speed_text.getPosition().y + m_text_dist}); */
     
}

void recorder::text_box::set_font(const sf::Font& font)
{
   
}

void recorder::text_box::draw(sf::RenderTarget& target , sf::RenderStates states) const
{
   

}
