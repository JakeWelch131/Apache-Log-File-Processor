// string Test Program
// 
// Tests:  default constructor, uses ==
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    // Setup

    // Test 
    String str;

    // Verify
    std::cout << "0 == " << str << std::endl;
    assert(str == '\0');

    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}
