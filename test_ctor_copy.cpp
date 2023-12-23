//  String Test Program
//
//  Tests: copy ctor
//
// 
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {

    {
        //------------------------------------------------------

        // Test 
        String s("0");
        String copy(s);

        // Verify
        assert(s == copy);        
    }

    {
        //------------------------------------------------------

        // Test 
        String s('a');
        String copy(s);

        // Verify
        assert(s == copy);
    }

    {
        //------------------------------------------------------
   

        // Test 
        String s("Hi Mom");
        String copy(s);
        // Verify
        assert(s == copy);
    }

    {

        // Test 
        String s("GoBrowns");
        String copy = s;

        // Verify
        assert(s == copy);
    }

    {

        // Test 
        String s('1');
        String copy(s);

        // Verify
        assert(s == copy);
    }
    

    {
        //------------------------------------------------------

        // Test 
        String s;
        String copy(s);
    
        // Verify
        assert(s == copy);


    }

    std::cout << "Done testing copy ctor array." << std::endl;
    return 0;
}

