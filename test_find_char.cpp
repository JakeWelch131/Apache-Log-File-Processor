// String
//
// Tests:  findch
//
#include "string.hpp"
#include <cassert>

//===========================================================================

int main() {

    {
        String one("abcd");
        char two = 'd';
        
        int result = one.findch(0, two); 
        std::cout << "findch Result: " << result << std::endl;
        
        assert(result == 3);
    
    }



    {
        String one = "abcdeCat";
        char two = 'C';
        
        int result = one.findch(3, two); 
        std::cout << "findch Result: " << result << std::endl;
        
        assert(result == 5);
    
    }

    {
        String one = "1234abcde1234";
        char two = '3';
        
        int result = one.findch(0, two); 
        std::cout << "findch Result: " << result << std::endl;
        
        assert(result == 2);
    
    }

    {
        String one = "1234abcde1234";
        char two = '3';
        
        int result = one.findch(3, two); 
        std::cout << "findch Result: " << result << std::endl;
        
        assert(result == 11);
    
    }

    {
        String one = "1234abcde1234";
        char two = '7';
        
        int result = one.findch(3, two); 
        std::cout << "findch Result: " << result << std::endl;
        
        assert(result == -1);
    
    }



    
    std::cout << "Done Testing findch" << std::endl;
}