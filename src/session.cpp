#include "session.hpp"


session::session(recorder* rec , manager* man , sf::RenderWindow& win_ref , sf::Event& event_ref) : 
recorder_ptr(rec) , manager_ptr(man) , 
m_step(step::START) , m_last_step(step::START) , m_event_ref(event_ref) , m_win_ref(win_ref)
{

}

void session::set_stat(step stat)
{
    m_last_step = m_step;
    m_step = stat;
}

step session::stat() const
{
    return m_step;
}

step session::last_stat() const
{
    return m_last_step;
}

void session::s_start()
{
    if(m_last_step == step::PAUSE)
    {
       recorder_ptr->reset_time();
    }
    recorder_ptr->update();
}

void session::s_restart()
{
     std::cout<<"RESTART->\n"<<std::endl;
     recorder_ptr->restart();
     this->set_stat(step::PAUSE);


}

void session::s_end()
{
    m_win_ref.close();
}

void session::s_pause()
{
    if(m_win_ref.waitEvent(m_event_ref))
            {
                if(m_event_ref.type == sf::Event::KeyReleased)
                {
                  switch(m_event_ref.key.code)
                  {
                    case sf::Keyboard::Q :
                    {
                        this->set_stat(step::END);
                        std::cout<<"exit after pause\n";
                        break;
                    }
                    case sf::Keyboard::R : 
                    {
                        this->set_stat(step::RESTART);
                        std::cout<<"restart after pause\n";
                        break;
                    }
                    case sf::Keyboard::P :
                    {
                        this->set_stat(step::START); 
                        std::cout<<"start after pause\n";
                        break;
                    }
                  }  
                }
                else if(m_event_ref.type == sf::Event::GainedFocus)
                {
                    std::cout<<"Start after lost focuse\n";
                    this->set_stat(step::START);
    
                }
            }
}