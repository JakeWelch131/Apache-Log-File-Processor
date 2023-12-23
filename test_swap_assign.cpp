// String Test Program
//
// Tests:   overload=
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        String s("0");
        String s2;
        s2 = s;
        // Test 
        assert(s == s2);
    }
    
    {
        // Setup
        String s1('W');
        String s2;
        s2 = s1;
        // Test
        assert(s1 == s2);
    }

    {
        // Setup
        String s1("abcd");
        String s2("123");
        s2 = s1;
        // Test
        assert(s1 == s2);
    }

    {
        // Setup
        String s1;
        String s2("abcd");
        s1 = s2;
        // Test
        assert(s1 == s2);

    }

    {
        // Setup
        String s1;
        String s2;
        s1 = s2;
        // Test
        assert(s1 == s2);

    }

    std::cout << "Done testing overload=" << std::endl;
    return 0;
}
