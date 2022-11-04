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

void recorder::update()
{
    if(rect_moved())
    {
        m_counter++;
        record_duration();
        record_dist_btwnMR(m_win_ref);
        record_speed();
        store_speed();

        m_stat_box->m_text_array[0].setString("counter : " + std::to_string(m_counter));
        m_stat_box->m_text_array[1].setString("current speed(mm/s) : " + std::to_string(record_speed()));
        m_stat_box->m_text_array[2].setString("speed mean(mm/s) : " + std::to_string(get_speed_mean()));


    

    }

}
///////////////////////////////////////////////////////////////////////////////////

recorder::text_box::text_box(const sf::Vector2f& pos , uint16_t text_size , uint16_t text_dist) : 
m_text_size(text_size) ,
m_text_dist(text_dist) 
{
    this->replace(pos);
    this->set_size(m_text_size);
}

void recorder::text_box::replace(const sf::Vector2f& new_pos)
{
    m_text_array[0].setPosition(new_pos);

    for(int i = 1 ; i < TXTBSIZE ; i++)
    {
        m_text_array[i].setPosition(sf::Vector2f(m_text_array[i-1].getPosition().x , m_text_array[i-1].getPosition().y + m_text_size));
    }
}

void recorder::text_box::set_font(const sf::Font& font)
{
     for(int i = 0 ; i < TXTBSIZE ; i++)
     {
        m_text_array[i].setFont(font);
     }
   
}

void recorder::text_box::draw(sf::RenderTarget& target , sf::RenderStates states) const
{
    for(int i = 0 ; i < TXTBSIZE ; i++)
    {
        target.draw(m_text_array[i]);
    }

}

void recorder::text_box::set_size(const uint16_t& new_size)
{
    for(int i = 0 ; i < TXTBSIZE ; i++)
    {
        m_text_array[i].setCharacterSize(new_size);
    }

}
