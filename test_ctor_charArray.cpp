//  String Test Program
//
//  Tests: converting a character array into a string
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
        String s("0");

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
        // Test: Construct with two-digit value
        // Setup fixture

        // Test 
        String s("Hi");

        // Verify
        assert(s == "Hi");
    }

    {
        //------------------------------------------------------
        // Test: Construct with eight-digit value
        // Setup fixture

        // Test 
        String s("GoBrowns");

        // Verify
        assert(s == "GoBrowns");
    }
    

    {
        //------------------------------------------------------
        // Test: Construct with full sentence
        // Setup fixture

        // Test 
        String s("The quick brown fox jumps over the lazy dog.");
    
        // Verify
        assert(s == "The quick brown fox jumps over the lazy dog.");


    }

    {
        //------------------------------------------------------
        // Test: Construct with multiple declarations.
        // Setup fixture

        // Test
        String a("0");
        String b("11");
        String c("222");
        String d("3333");
        String e("44444");
        String f("555555");
        String g("6666666");
        String h("77777777");
        String i("888888888");


        // Verify
        assert(a == "0");
        assert(b == "11");
        assert(c == "222");
        assert(d == "3333");
        assert(e == "44444");
        assert(f == "555555");
        assert(g == "6666666");
        assert(h == "77777777");
        assert(i == "888888888");
   }


    std::cout << "Done testing character array." << std::endl;
    return 0;
}

