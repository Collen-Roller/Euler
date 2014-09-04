#include "Euler54.h"

Euler54::Euler54(){
    std::cout << "in constructor " << std::endl;
    current_highest_card.value = 0;
}

Euler54::~Euler54(){
    std::cout << "in destructor " << std::endl;
}

void Euler54::read_hands(std::string _file_name, int _number_of_hands){

    int player_one_wins = 0;
    int player_two_wins = 0;
    int ties = 0;

    std::cout << "in read hands " << std::endl;
    std::cout << "file name is : " << _file_name << std::endl;
    std::cout << "number of hands is " << _number_of_hands << std::endl;
    //fill hands
    std::ifstream file(_file_name);
    std::string line;
    int line_count = 0;
    while(getline(file,line) && line_count < _number_of_hands){
        std::istringstream ss(line);
 
        Euler54::Hand h1;
        for(int i = 0; i < 5; i++){
            std::string c;
            if(!(ss >> c)){
                std::cout << "invalid hand for player1" << std::endl;
                break;
            }
            Card card;
            card.value = get_value(c.substr(0,1));
            card.symbol = c.substr(0,1);
            card.suit = c.substr(1,2);
            h1.cards.push_back(card);
        }

        Euler54::Hand h2;
        for(int i = 0; i < 5; i++){
            std::string c;
            if(!(ss >> c)) {
                std::cout << "invalid hand for player2" << std::endl;
                break;
            }
            Card card;
            card.value = get_value(c.substr(0,1));
            card.symbol = c.substr(0,1);
            card.suit = c.substr(1,2);
            h2.cards.push_back(card);
        }
        //test hands

        int winner = get_winner(h1, h2);
        if(winner == 1){
            std::cout << "player 1 wins" << std::endl;
            player_one_wins++;
        }else if(winner == 2){
            std::cout << "player 2 wins" << std::endl;
            player_two_wins++;
        }else
            ties++;
        std::cout << "done processing line " << line_count << std::endl;
        line_count++;
    }

    std::cout << "Player one wins : " << player_one_wins << std::endl;
    std::cout << "Player two wins : " << player_two_wins << std::endl;
    std::cout << "Ties : " << ties << std::endl;
    
}

int Euler54::get_value(std::string _value){
    if(_value.compare("T") == 0){
        return 10;
    }else if(_value.compare("J") == 0){
        return 11;
    }else if(_value.compare("Q") == 0){
        return 12;
    }else if(_value.compare("K") == 0){
        return 13;
    }else if(_value.compare("A") == 0){
        return 14;
    }else
        return atoi(_value.c_str());
}

int Euler54::get_winner(Hand _h1, Hand _h2){
    std::cout << " Player 1 hand : ";
    print_hand(_h1);
    std::cout << " Player 2 hand : ";
    print_hand(_h2);
    
    int p1 = compute_best_hand(_h1);
    Card p1_highest = current_highest_card;
    current_highest_card.value = 0; //to reset the hands current highest card
    int p2 = compute_best_hand(_h2);
    Card p2_highest = current_highest_card;
    current_highest_card.value = 0;
    
    if(p1 > p2){
        return 1;
    }else if(p1 < p2){
        return 2;
    }else{

        //std::cout << "P1 highest card is : " << print_card(p1_highest_card) << std::endl;
        //std::cout << "P2 highest card is : " << print_card(p2_highest_card) << std::endl;
        int temp = 0;
        if(p1 == 1){
            temp = face_off(_h1,_h2, p1_highest, p2_highest, true);
        }else{
            temp = face_off(_h1, _h2, p1_highest, p2_highest, false);
        }
        std::cout << " faceoff returned " << temp << std::endl;
        return temp;
    }

    std::cout << "in get_winner " << std::endl;
    return 0;
}

void Euler54::remove_highest_card(Hand & _hand){
    Card temp = highest_card(_hand);
    for(int i = 0; i < _hand.cards.size(); i++){
        if(_hand.cards[i].value == temp.value && strcmp(_hand.cards[i].suit.c_str() ,temp.suit.c_str()) == 0){
            _hand.cards.erase(_hand.cards.begin()+i);
            return;
        }
    }
}


int Euler54::face_off(Hand _p1_hand, Hand _p2_hand, Card _p1_highest, Card _p2_highest, bool _squat){
    //std::cout << "p1 value of card " << _p1_high.value << std::endl;
    //std::cout << "p2 value of card " << _p2_high.value << std::endl; 
    
    if(_squat){
        while(_p1_hand.cards.size() > 0){
            Card p1_high = highest_card(_p1_hand);
            Card p2_high = highest_card(_p2_hand);

            if(p1_high.value > p2_high.value){
                return 1;
            }else if(p1_high.value < p2_high.value){
                return 2;
            }else{
                //remove the highest cards from the hands
                remove_highest_card(_p1_hand);
                remove_highest_card(_p2_hand);
            }
        }
    }else{
        if(_p1_highest.value > _p2_highest.value){
            return 1;
        }else{
            return 2;
        }
    }

    return 3;
}

int Euler54::compute_best_hand(Euler54::Hand _hand){
    if(royal_flush(_hand)){
        std::cout << "Royal Flush" << std::endl;
        return 10;
    }else if(straight_flush(_hand)){
        std::cout << "Straight Flush" << std::endl;
        return 9;
    }else if(quads(_hand)){
        std::cout << "Quads" << std::endl;
        return 8;   
    }else if(full_house(_hand)){
        std::cout << "Full House" << std::endl;
        return 7;
    }else if(flush(_hand)){
        std::cout << "Flush" << std::endl;
        return 6;
    }else if(straight(_hand)){
        std::cout << "Straight" << std::endl;
        return 5;
    }else if(trips(_hand)){
        std::cout << "Trips" << std::endl;
        return 4;
    }else if(two_pair(_hand)){
        std::cout << "Two Pair" << std::endl;
        return 3;
    }else if(pair(_hand, 0)){
        std::cout << "Pair" << std::endl;
        return 2;
    }else{
        set_highest_card(highest_card(_hand));
        std::cout << "you have the high card " << print_card(current_highest_card) << std::endl;
        return 1;
        std::cout << " you got squat " << std::endl;
    }
}

std::string Euler54::find_suit(Hand _hand, int _value){
    for(int i = 0; i < _hand.cards.size(); i++){
        if(_hand.cards[i].value == _value){
            return _hand.cards[i].suit;
        }
    }
    return "S";
}

void Euler54::set_highest_card(Card _card){
    if(current_highest_card.value < _card.value){
        current_highest_card = _card;
    }
}

bool Euler54::full_house(Hand _hand){
    if(trips(_hand)){
       if(pair(_hand, current_highest_card.value)){
            return true;
       }
    }
    return false;
}

bool Euler54::royal_flush(Hand _hand){
    if(straight_flush(_hand)){
        for(int i = 0; i < _hand.cards.size(); i++){
            if(_hand.cards[i].value < 10){
                return false;
            }
        }
        Card temp_card;
        temp_card.value = 14;
        temp_card.suit = find_suit(_hand, 14);
        current_highest_card = temp_card;
        return true;
    }
    return false;
}  

bool Euler54::straight_flush(Hand _hand){
    if(flush(_hand) && straight(_hand)){
       return true;
       current_highest_card = highest_card(_hand);
    }
    return false;
}

bool Euler54::quads(Hand _hand){
    for(int i = 0; i < _hand.cards.size()-3; i++){
        int count = 0;
        for(int j = i+1; j < _hand.cards.size(); j++){
            if(_hand.cards[i].value == _hand.cards[j].value){
                count++;
                if(count == 3){
                    set_highest_card(_hand.cards[i]);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Euler54::trips(Hand _hand){
    for(int i = 0; i < _hand.cards.size()-2; i++){
        int count = 0;
        for(int j = i+1; j < _hand.cards.size(); j++){
            if(_hand.cards[i].value == _hand.cards[j].value){
                count++;
                if(count == 2){
                    set_highest_card(_hand.cards[i]);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Euler54::pair(Hand _hand, int _ex_value){
    for(int i = 0; i < _hand.cards.size()-1; i++){
        int count = 0;
        for(int j = i+1; j < _hand.cards.size(); j++){
            if(_hand.cards[i].value == _hand.cards[j].value && 
                _hand.cards[i].value != _ex_value && 
                _hand.cards[j].value != _ex_value){
                set_highest_card(_hand.cards[i]);
                return true;
            }
        }
    }
    return false;
}

//straight
//this is broken needs fixing
bool Euler54::straight(Hand _hand){
    Card temp_highest = highest_card(_hand);
    //std::cout << "highest card is : " << print_card(temp_highest) << std::endl;
    int current_card = temp_highest.value;
    int straight_count = 1;
    for(int i = 0; i < _hand.cards.size(); i++){
        //if(_hand.cards[i].value == current_card){
        //    continue;
        //}
        if(_hand.cards[i].value == current_card-1){
            
            straight_count++;
            current_card--;
            if(straight_count == 5){
                current_highest_card = temp_highest;
                return true;
            }
            i=-1;
        }
    }
    return false;
}

//flush
bool Euler54::flush(Hand _hand){
    std::string current_suit = _hand.cards[0].suit;
    for(int i = 1; i < _hand.cards.size(); i++){
        if(strcmp(current_suit.c_str(),_hand.cards[i].suit.c_str()) != 0){
            return false;
        }
    }
    set_highest_card(highest_card(_hand));
    return true;
}
//two pair  
bool Euler54::two_pair(Hand _hand){
    if(pair(_hand, 0)){
        if(pair(_hand, current_highest_card.value)){
            return true;
        }
    }
    return false;
}

Euler54::Card Euler54::highest_card(Hand _hand){
    Card max_card = _hand.cards[0]; 
    for(int i = 1; i < _hand.cards.size(); i++){
        if(max_card.value < _hand.cards[i].value){
            max_card = _hand.cards[i];
        }
    }
    return max_card;
}

void Euler54::compute_results(){
    std::cout << "in compute_results" << std::endl;
}

void Euler54::print_results(){
    std::cout << "int print_results " << std::endl;
}

std::string Euler54::print_card(Card _card){
    std::ostringstream convert; 
    if(_card.value > 9){
        convert << _card.symbol << _card.suit << " "; 
    }else{
        convert << _card.value << _card.suit << " ";
    }
    return convert.str();
}

void Euler54::print_hand(Hand _hand){
    for(int i = 0; i < _hand.cards.size(); i++){
        std::cout << print_card(_hand.cards[i]);
    }
    std::cout << std::endl;
}
