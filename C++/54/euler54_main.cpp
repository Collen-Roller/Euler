#include "Euler54.cpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <vector>

int main(int argc, char** argv){

    std::cout << " in main! " << std::endl;
    std::cout << " HELLO WORLD (For Kicks) " << std::endl;

   if(argc < 3){
        std::cerr << argv[0] << " usage, file name, number of poker hands" << std::endl;
        return 1;
   }
   
   std::string file_name = argv[1];
   int number_of_hands = atoi(argv[2]);

   Euler54* hand_reader = new Euler54();

   hand_reader->read_hands(file_name, number_of_hands);
   //hand_reader->compute_results();
   //hand_reader->print_results();
   
   delete hand_reader;

   std::cout << "done using main, goodbye " << std::endl;

}
