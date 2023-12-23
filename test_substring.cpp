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

int main(){


    {
        String str = "hi mom";
        String s1;
        String s2;
        
        s1 = str.substr(0,0);
        s2 = str.substr(0,5);
        std::cout << s1 << std::endl;
        std::cout << s2 << std::endl;
        assert(s1 == "h");
        assert(s2 == "hi mom");
    } 
       

    {   
        String str = "The quick brown fox jumps over the lazy dog";
        String s1;
        s1 = str.substr(0,8);
        assert(s1 == "The quick"); 
    }

    {   
        String str = "The quick brown fox jumps over the lazy dog";
        String s1;
        String s2;
        s1 = str.substr(0,2);
        s2 = str.substr(16,18);
        assert(s1 == "The"); 
        std::cout << s2 << std::endl;
        assert(s2 == "fox");
    }


    std::cout << "Done testing substr" << std::endl;


}