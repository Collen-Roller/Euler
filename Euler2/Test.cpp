#include "Test.h"

Test::Test(){
    std::cout << "in constructor " << std::endl;
}

Test::~Test(){
    std::cout << "in destructor " << std::endl;
}

void Test::print_fib_numbers(int _max){
   
  
    size_t sum = 0;
    size_t sum_of_even = 0; 
    size_t current = 1;
    size_t prev = 0;
    size_t temp = 0;
    for(int i = 0; i < _max; i++){ 
        
        temp = current + prev;
        prev = current;
        current = temp;

        sum += current; //sum of the number
        //std::cout << " current at i = " << i << " is : " << current << std::endl; 
        
        if(current%2 == 0 && current < 4000000){
            sum_of_even += current;
        }

        //std::cout << " current at i (even) = " << i << " is : " << current << std::endl; 
        
    }
    std::cout << " sum of the fib numbers from 0 to " << _max << " is " << sum << std::endl;
    std::cout << " sum of the even fib numbers from 0 to " << _max << " is " << sum_of_even << std::endl;

}

