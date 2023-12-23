#include <iostream>
#include <cassert>
#include "string.hpp"

int main() {
    // Test Case 1: Normal case with space as ch
    {
        String s("abc ef gh");
        std::vector<String> result = s.split(' ');
        assert(result[0] == "abc");
        assert(result[1] == "ef");
        assert(result[2] == "gh");
        std::cout << result[0] << std::endl;
        std::cout << result[1] << std::endl;
        std::cout << result[2] << std::endl;
    }

    // Test Case 2: Normal case with '-' as ch
    {
        String s("-a--b-");
        std::vector<String> result = s.split('-');
        assert(result[0] == "");
        assert(result[1] == "a");
        assert(result[2] == "");
        assert(result[3] == "b");
        assert(result[4] == "");
    }

    // Test Case 3: No ch
    {
        String s("no_chToFind");
        std::vector<String> result = s.split('-');
        assert(result[0] == "no_chToFind");
    }

    // Test Case 4: ch at the beginning and end
    {
        String s("-abc-def-");
        std::vector<String> result = s.split('-');
        assert(result[0] == "");
        assert(result[1] == "abc");
        assert(result[2] == "def");
        assert(result[3] == "");
    }

    // Test Case 5: empty string
    {
        String s;
        std::vector<String> result = s.split('-');
        assert(result[0] == "");
    }

    // Test Case 6: ch as a number
    {
        String s("8abc8def8");
        std::vector<String> result = s.split('8');
        assert(result[0] == "");
        assert(result[1] == "abc");
        assert(result[2] == "def");
        assert(result[3] == "");
    }

    // Test Case 6: ch as a char
    {
        String s("wabcwdefw");
        std::vector<String> result = s.split('w');
        assert(result[0] == "");
        assert(result[1] == "abc");
        assert(result[2] == "def");
        assert(result[3] == "");
    }

    // Test Case 6: ch as a whitespace
    {
        String s(" abc def ");
        std::vector<String> result = s.split(' ');
        assert(result[0] == "");
        assert(result[1] == "abc");
        assert(result[2] == "def");
        assert(result[3] == "");
    }

    // Test Case 7: long string
    {
        String s("a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z");
        std::vector<String> result = s.split('|');
        assert(result[0] == "a");
        assert(result[1] == "b");  
        assert(result[2] == "c");    
        assert(result[3] == "d"); 
        assert(result[4] == "e"); 
        assert(result[5] == "f");  
        assert(result[6] == "g"); 
        assert(result[7] == "h"); 
        assert(result[8] == "i"); 
        assert(result[9] == "j"); 
        assert(result[10] == "k"); 
        assert(result[11] == "l"); 
        assert(result[12] == "m");
        assert(result[13] == "n");  
        assert(result[14] == "o");    
        assert(result[15] == "p"); 
        assert(result[16] == "q"); 
        assert(result[17] == "r");  
        assert(result[18] == "s"); 
        assert(result[19] == "t"); 
        assert(result[20] == "u"); 
        assert(result[21] == "v"); 
        assert(result[22] == "w"); 
        assert(result[23] == "x"); 
        assert(result[24] == "y"); 
        assert(result[25] == "z"); 
        
    }

    // Test Case 8: multiple ch in a row
    {
        String s("abc,,def,,,ghi");
        std::vector<String> result = s.split(',');
        assert(result[0] == "abc");
        assert(result[1] == "");
        assert(result[2] == "def");
        assert(result[4] == "");
        assert(result[5] == "ghi");
    }


    std::cout << "Thank god everything is passing!" << std::endl;

    return 0;
}
