// String
//
// Tests:  length and capacity
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
        String s("");

        // Test 
        int num = s.length();

        // Verify
        assert(s    == "");  
        assert(num == 0);
        assert(s.capacity() == 0);
    }

    

    {
        // Setup
        String s('4');

        // Test 
        int num = s.capacity();

        // Verify
        assert(s    == "4");  
        assert(num == 1);
        assert(s.length() == 1);
    }

    {
        // Setup
        String s("abcd");

        // Test 
        int num = s.length();

        // Verify
        assert(s    == "abcd");  
        assert(num == 4);
        assert(s.capacity() == 4);
    }

    {
         // Setup
        String a("0");
        String b("11");
        String c("222");
        String d("3333");
        String e("44444");
        String f("555555");
        String g("6666666");
        String h("77777777");
        String i("888888888");

        // Test
        int num1 = a.length();
        int num2 = b.length();
        int num3 = c.length();
        int num4 = d.length();
        int num5 = e.length();
        int num6 = f.length();
        int num7 = g.length();
        int num8 = h.length();
        int num9 = i.length();
        
        // Verify
        assert(num1 == 1);
        assert(num2 == 2);
        assert(num3 == 3);
        assert(num4 == 4);
        assert(num5 == 5);
        assert(num6 == 6);
        assert(num7 == 7);
        assert(num8 == 8);
        assert(num9 == 9);
    }
    
    {
        // Setup
        String s("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"  );

        // Test 
        int num = s.length();

        // Verify  
        assert(num == 290);
        assert(s.capacity() == 290);
    }

    std::cout << "Done testing length and cap." << std::endl;
    return 0;
}

