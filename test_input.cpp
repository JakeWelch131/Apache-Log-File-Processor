// String
//
// Tests:  input operator, >>
//         output operator, <<
//
#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

//===========================================================================

int main() {
    std::ifstream in;
    in.open("test_input.txt");
    
    String word;
    while(in >> word){
        std::cout << word << std::endl;
    }
    
    in.close();
    std::cout << "Done testing input operator" << std::endl;
}