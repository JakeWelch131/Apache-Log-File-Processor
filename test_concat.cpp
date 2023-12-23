// String Test Program
//
// Tests:   +
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        String s1("");
        String s2("b");
        s1 += s2;
        // Test 
        assert(s1 == "b");
    }

    {
        // Setup
        String s1("b");
        String s2("");
        s1 += s2;
        // Test 
        assert(s1 == "b");
    }

    {
        // Setup
        String s1("");
        String s2("");
        s1 += s2;
        // Test 
        assert(s1 == "");
    }
    
    {
        // Settup
        String s1("Reverse");
        s1 += s1;
        // Test
        assert(s1 == "ReverseReverse");
        std::cout << s1.capacity() << std::endl;
    }

   {
        // Setup
        String s1("Hi");
        String s2;
        s1 += s2;
        // Test 
        assert(s1 == "Hi");
    }

    {
        // Setup
        String s1("abc");
        String s2("Hi");
        String s3;
        s3 = s1 + s2;
        // Test
        std::cout << s3 << std::endl;
        assert(s3 == "abcHi");
    }

    {
        // Setup
        String s1("the ");
        String s2("quick ");
        String s3("red fox");
        s1 += s2 += s3;
        // Test
        assert(s1 == "the quick red fox");
    }

    {
        // Setup
        String s1("bc");
        String s2("abcd");
        s1 += s2;
        // Test
        assert(!(s1 == "abcdbc"));
    }

        // Setup
        String s1("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
        String s2("1234567890123456789012345678901234567890123456789012345");
        s1 += s2;
        // Test
        assert(s1 == "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345");

    std::cout << "Done testing +." << std::endl;
    return 0;
}
