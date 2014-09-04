#ifndef EULER54_H
#define EULER54_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <vector>

class Euler54 {
    
    public :
    
        struct Card {
            int value;
            std::string symbol;
            std::string suit;
        };

        struct Hand {
            std::vector<Card> cards;
        };


        Euler54();
        
        ~Euler54();
        
        void read_hands(std::string _file_name, int _number_of_hands);
        int get_winner(Hand h1, Hand h2);
        void compute_results();
        void print_results();
        std::string print_card(Card _card);
        void print_hand(Hand _hand);
        int get_value(std::string _value);
        int compute_best_hand(Hand _hand);
        void remove_highest_card(Hand & _hand);
        int face_off(Hand _p1_hand, Hand _p2_hand, Card _p1_highest, Card _p2_highest, bool _squat);
        void set_highest_card(Card _card);
        std::string find_suit(Hand _hand, int _value);
        Card highest_card(Hand _hand);
        bool two_pair(Hand _hand);
        bool flush(Hand _hand);
        bool straight(Hand _hand);
        bool pair(Hand _hand, int _ex_value);
        bool quads(Hand _hand);
        bool trips(Hand _hand);
        bool straight_flush(Hand _hand);
        bool royal_flush(Hand _hand);
        bool full_house(Hand _hand); 

    private :
        
        Card current_highest_card;

};

#endif
