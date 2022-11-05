#include "session.hpp"


session::session(recorder* rec , manager* man) : recorder_ptr(rec) , manager_ptr(man) , m_step(step::START) , 
m_last_step(step::START)
{

}

void session::start()
{
    m_last_step = m_step;
    m_step = step::START;
}

void session::restart()
{
    m_last_step = m_step;
    recorder_ptr->restart();
    m_step = step::RESTART;
}


void session::pause()
{
    m_last_step = m_step;
    m_step = step::PAUSE;
}

void session::end()
{
    m_last_step = m_step;
    m_step = step::END;
}

step session::stat() const
{
    return m_step;
}

step session::last_stat() const
{
    return m_last_step;
}
