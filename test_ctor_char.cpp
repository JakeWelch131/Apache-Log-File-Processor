//  String Test Program
//
//  Tests: constructor that converts a single char into a string
//
// 
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {

    {
        //------------------------------------------------------
        // Test: Construct with 0
        // Setup fixture

        // Test 
        String s('0');

        // Verify
        assert(s == "0");        
    }

    {
        //------------------------------------------------------
        // Test: Construct with 1
        // Setup fixture

        // Test 
        String s('1');

        // Verify
        assert(s == "1");
    }

    {
        //------------------------------------------------------
        // Test: Construct with 1
        // Setup fixture

        // Test 
        String s('\0');

        // Verify
        assert(s.length() == 0);
    }

    {
        //------------------------------------------------------
        // Test: Construct with multiple declarations.
        // Setup fixture

        // Test
        String a('0');
        String b('1');
        String c('2');

        // Verify
        assert(a == "0");
        assert(b == "1");
        assert(c == "2");
   
   }


    std::cout << "Done testing constructor String(const char[])." << std::endl;
    return 0;
}

