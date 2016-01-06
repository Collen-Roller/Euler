#include "Test.cpp"

#include <iostream>

int main(int argc, char** argv){

    std::cout << " in main! " << std::endl;
    std::cout << " HELLO WORLD (For Kicks) " << std::endl;

   if(argc < 2){
        std::cerr << argv[0] << " usage, max fib number " << std::endl;
        return 1;
   }
   
   int max = atoi(argv[1]);

   Test* t = new Test();

   t->print_fib_numbers(max);
   
   delete t;

   std::cout << "done using test main, goodbye " << std::endl;

}
