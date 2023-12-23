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

int main() {

    {
        String s1 = "himom";
        String find = "mom";
        
        int value = s1.findstr(0, find); 
        std::cout << "findstr value: " << value << std::endl;
        
        assert(value == 2);
    
    }

 
    {
        String s1 = "hi mom";
        String find = "mom";
        
        int value = s1.findstr(0, find); 
        std::cout << "findstr value: " << value << std::endl;
        
        assert(value == 3);
    
    }  


    {
        String s1 = "hello mother hello world";
        String find = "hello";
        
        int value = s1.findstr(5, find); 
        std::cout << "findstr value: " << value << std::endl;
        
        assert(value == 13);
    
    }

    {
        String s1 = "hello mother hello world";
        String find = "hi";
        
        int value = s1.findstr(0, find); 
        std::cout << "findstr value: " << value << std::endl;
        
        assert(value == -1);
    
    }



 
    std::cout << "Done Testing findstr" << std::endl;
}