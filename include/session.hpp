#ifndef SESSION_HPP
#define SESSION_HPP

#include <cstdint>
#include "recorder.hpp"
#include "manager.hpp"

enum class step {

    START = 0 ,
    PAUSE = 1,
    RESTART = 2 , 
    END = 3
};

class session { 

public:

    session(recorder* rec , manager* man);

    void start();

    void restart();

    void end();

    void pause();

    step stat() const;

private:
    
    step m_step;
    recorder* recorder_ptr;
    manager* manager_ptr;
    


};

#endif