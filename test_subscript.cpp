// String
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        String s('4');

        // Test 
        char digit = s[0];

        // Verify
        assert(s    == "4");  
        assert(digit == '4');
    }

    

    {
        // Setup
        String s('4');

        // Test 
        char digit = s[3];

        // Verify
        assert(s    == "4");  
        assert(digit != '4');
    }

    {
        // Setup
        String s("1234");

        // Test 
        char digit = s[3];

        // Verify
        assert(s    == "1234");  
        assert(digit == '4');
    }

    {
        // Setup
        String s("abcd");

        // Test 
        char zero   = s[0];
        char one    = s[1];
        char two    = s[2];
        char three  = s[3];


        // Verify
        assert(s    == "abcd");  
        assert((zero == 'a') && (one == 'b') && (two == 'c') && (three == 'd'));
    }
    
    {
        // Setup
        String s("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"  );

        // Test 
        char digit = s[254];

        // Verify
        assert(s == "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");  
        assert(digit == '5');
    }

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

