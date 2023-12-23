// String Test Program
//
// Tests:   <
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        String s("a");
        String s1("b");
        // Test 
        assert(s < s1);
        // Verify
        std::cout << "a < ";
        std::cout << s1;
        std::cout << std::endl;
    }
    
    {
        // Setup
        String s1("ab");
        String s2("abc");
        // Test
        assert(s1 < s2);
        // Verify
        std::cout << s1;
        std::cout << " < ";
        std::cout << s2;
        std::cout << std::endl;
    }

    {
        // Setup
        String s1("abcd");
        String s2("bcd");
        // Test
        assert(s1 < s2);
        // Verify
        std::cout << s1;
        std::cout << " !< ";
        std::cout << s2;
        std::cout << std::endl;
    }

    {
        // Setup
        String s1("bc");
        String s2("abcd");
        // Test
        assert(!(s1 < s2));
        // Verify
        std::cout << s1;
        std::cout << " !< ";
        std::cout << s2;
        std::cout << std::endl;
    }

    {
        // Set up
        String s1 = "bcd";
        String s2 = "bcd";
        // Test
        assert(s1 <= s2);
    }  

    {
        // Set up
        String s1;
        String s2 = "bcd";
        // Test
        assert(s1 < s2);
    }  

    std::cout << "Done testing comparison operators." << std::endl;
    return 0;
}
