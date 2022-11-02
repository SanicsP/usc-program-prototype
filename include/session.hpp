#ifndef SESSION_HPP
#define SESSION_HPP
#include <cstdint>

class session { 

public:

    session();

    void start();

    void restart();

    void end();

private:
    
    uint8_t m_step;

};

#endif