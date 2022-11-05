#ifndef RECORDER_HPP
#define RECORDER_HPP

#include "click_box.hpp"
#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <unordered_map>

#define PIXEL_SIZE 0.264583
#define TXTBSIZE 3



class recorder { 

public:
    
    struct text_box;

    typedef std::chrono::duration<double> r_duration;
    typedef std::chrono::time_point<std::chrono::steady_clock> r_t_point;
    recorder(std::shared_ptr<sf::RectangleShape> rect_ptr , sf::RenderWindow& win_ref);
    
   
    /**
     * @brief mise à jour de l'instance 
     * @note lors de l'appelle à cette fonction les calculs pour les statistiques sont effectués dans le but
     * d'avoir une évolution en temps réel
    */
    void update() ;

    /**
    * @brief verifie si le rectangle pointé a changé de position sur la fenêntre 
    * @return true si c'est le cas et false dans le cas contraire 
    */
    bool rect_moved() ;

    /**
     * @brief donne la moyenne des vitesses de l'utilisateur à partir du tableau de vitesses 
     * @return la vitesse moyenne de l'utilisateur
    */
    double get_speed_mean() const ;

    /**
     * @brief donne la vitesse moyenne de l'utilisateur entre le changement de position de la cible et le 
     * click sur cette dernière 
    */
    double get_curret_speed() const ;

    /**
     * @brief affect un pointeur à l'instance pour pouvoir gérer une zone de texte
     * @param box_ptr l'adresse de la boîte de texte
    */
    void set_txt_box(text_box* box_ptr);

    /// @brief renitialise les stats de l'utilisateur 
    void restart();

    /// @brief renitialise le point de temps après la pause , afin que le temps entre la pause ne soit pas compté 
    void reset_time();


private:
    /// @brief compteur du nombre de clicks 
    uint32_t m_counter;

    /// @brief pointeur vers la boite de la cible affin de capter un mouvement 
    std::shared_ptr<sf::RectangleShape> m_rect_ptr;

    /// @brief position du rectangle 
    sf::Vector2f m_record_rect_pos;
    
    /// @brief ancienne position du rectangle 
    sf::Vector2f m_record_old_rect_pos; 

    /// @brief la distance entre la souris et le rectangle 
    double m_record_distbtw_mouse_rect;

    /// @brief la duree entre le repositionnement du rectangle et le click de l'utilisateur 
    r_duration m_click_duration;
    
    /// @brief momment dans le temps : celui où le rectangle s'est repositionné 
    r_t_point m_start_moment;
    
    /// @brief momment dans le temps : celui où le joueur a cliqué sur le rectangle 
    r_t_point m_click_moment;

    /// @brief reference sur la fenêtre 
    sf::RenderWindow& m_win_ref;
    
    /// @brief vecteur de valeurs de vitesse moyenne 
    std::vector<double> m_recorder_speed_array;

    /// @brief pointeur vers la boîte de dialogue à afficher 
    text_box* m_stat_box;

    /**
     * @brief enregistre la distance ente la souris et le rectangle par rapport à la fenêtre 
     * @param win la fenêtre de référece 
    */
    void record_dist_btwnMR(sf::RenderWindow& win);

    /// @brief enregistre la durée entre le repositionnement du rectangle et le click de ce dernier 
    void record_duration();

    /// @brief enregistre la vitesse moyenne de l'utilisateur par rapport à la distance rectangle/souris et la durée 
    /// repositionnement/click 
    double record_speed();

    /// @brief enregistre la vitesse moyenne courante dans un vecteur de vitesses 
    void store_speed();


    
public:

    struct text_box : sf::Drawable
    {   
        
        
        text_box(const sf::Vector2f& pos , uint16_t text_size , uint16_t text_dist);

        virtual void draw(sf::RenderTarget& target , sf::RenderStates states) const;
        
        
        
        
        void replace(const sf::Vector2f& new_pos);
        
        void set_font(const sf::Font& font);

        void set_size(const uint16_t& new_size);

        sf::Text m_text_array[TXTBSIZE];


        private : 

        uint16_t m_text_size;

        uint16_t m_text_dist;

    };

};


#endif