#ifndef SESSION_HPP
#define SESSION_HPP

#include <cstdint>
#include "recorder.hpp"
#include "manager.hpp"
#include <iostream>
enum class step {

    START = 0 ,
    PAUSE = 1,
    RESTART = 2 , 
    END = 3
};

class session { 

public:

    session(recorder* rec , manager* man , sf::RenderWindow& win_ref , sf::Event& event_ref);
    
    void set_stat(step stat);
    step stat() const;

    step last_stat() const;

    void s_start();
    void s_restart();
    void s_end();
    void s_pause();



private:
    
    step m_step;
    step m_last_step;
    recorder* recorder_ptr;
    manager* manager_ptr;

    sf::RenderWindow& m_win_ref;
    sf::Event& m_event_ref;

};

#endif