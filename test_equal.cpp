// String Test Program
//
// Tests:   ==
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
        // Test 
        assert(s == "0");
        // Verify
        std::cout << "0 == ";
        std::cout << s;
        std::cout << std::endl;
    }
    
    {
        // Setup
        String s1("1234");
        String s2("1234");
        // Test
        assert(s1 == s2);
        // Verify
        std::cout << s1;
        std::cout << " == ";
        std::cout << s2;
        std::cout << std::endl;
    }

    {
        // Setup
        String s1("abcd");
        String s2("bcd");
        // Test
        assert(!(s1 == s2));
        // Verify
        std::cout << s1;
        std::cout << " != ";
        std::cout << s2;
        std::cout << std::endl;
    }

    {
        // Setup
        String s1("abc");
        String s2("abcd");
        // Test
        assert(!(s1 == s2));
        // Verify
        std::cout << s1;
        std::cout << " != ";
        std::cout << s2;
        std::cout << std::endl;
    }

    {
        // Setup
        String s1 = 'a';
        String s2 = 'b';
        
        bool result = s1 != s2;
        std::cout << "NotEqual Result: " << result << std::endl;
        
        // test
        assert(result == true);
    
    
    
    }


    {
        String s1 = "abcd";
        String s2 = "hi";
        
        bool result = s2 != s1;
        std::cout << "NotEqual Result: " << result << std::endl;
        
        assert(result == true);
    
    
    }

    std::cout << "Done testing == and !=." << std::endl;
    return 0;
}
