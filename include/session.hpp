#ifndef SESSION_HPP
#define SESSION_HPP

#include <cstdint>
#include "recorder.hpp"
#include "manager.hpp"
#include <iostream>

/// @file session.hpp

/**
 * @enum step 
 * @brief ennumérations symbolisant les différents états du programme
*/
enum class step {

    START = 0 ,
    PAUSE = 1,
    RESTART = 2 , 
    END = 3
};

/**
 * @brief represente le programme lui même et ses différents états 
 * @note cette classe est en relation avec recorder et manager , cette classe actualise ses dernières afin 
 * que l'utilisateur puisse recommencer ses stats avec recorder , et que manager s'actualise également 
 * il gère aussi la fenêtre et les évennements avec la fonction main
*/
class session { 

public:
    /**
     * @brief constructeur de la classe afin d'initiliser les instances 
     * @param rec adresse d'un objet de type recorder : c'est le recorder à gérer 
     * @param man adresse de manager : le manager à gérer 
     * @param win_ref la fenêtre à gérer 
     * @param event_ref l'evennement à gérer 
    */
    session(recorder* rec , manager* man , sf::RenderWindow& win_ref , sf::Event& event_ref);
    
    /**
     * @brief accesseur pour changer les états de la session
    */
    void set_stat(step stat);
    
    /**
     * @brief revoi l'état courant du programme
    */
    step stat() const;
    
    /**
     *@brief renvoi l'ancien état du programme
    */
    step last_stat() const;

    /**
     * @brief fonction appelée lorsque le programme est à l'etat step::START
    */
    void s_start();

    /**
     * @brief fonction appelée lorsque le programme est à l'etat step::RESTART
    */
    void s_restart();
    
    /**
     * fonction appelée lorsque le programme est à l'etat step::END
    */
    void s_end();
    
    /**
     * fonction appelée lorsque le programme est à l'etat step::PAUSE
    */
    void s_pause();



private:
    
    /// @brief l'etat courant du programme 
    step m_step;
    /// @brief l'ancien etat du programme
    step m_last_step;
    /// @brief pointeur sur un recorder
    recorder* recorder_ptr;
    /// @brief pointeur sur un manager 
    manager* manager_ptr;

    /// @brief reference sur une fenêtre 
    sf::RenderWindow& m_win_ref;    
    /// @brief reference sur un evennement 
    sf::Event& m_event_ref;

};

#endif