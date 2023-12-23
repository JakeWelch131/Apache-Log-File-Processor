//Implementation file for Project 2

#include "string.hpp"
#include <cassert>

//default ctor, creates empty string
String::String() {
    str[0] = 0;
}

//ctor that assigns a single char to the string array
String::String(char ch) {
    str[0] = ch;
    str[1] = 0;                                                                 //ensures NULL terminator
}

//ctor that assigns the multiple characters in invocation to string array
String::String(const char charArray[]) {
    int i = 0;
    while (charArray[i] != 0) {                                                 //runs until it encounters NULL
        if (i>= STRING_SIZE -1) break;                                          //checks that i will not surpass STRING_SIZE
        str[i] = charArray[i];
        ++i;
    }
    str[i] = 0;
}

//returns the max hcars that can be stored
int String::capacity() const {
    return STRING_SIZE - 1;
}

//returns the legnth of the string
int String::length() const {
    int length = 0;
    while (str[length] != 0) {
        ++length;
    }
    return length;
}

//returns the character at the specified array index
//Must have a const version if we want to also pass a const object
char String::operator[](int arrayPos) const {
    //assert((arrayPos >=0) && arrayPos < length());                          //requires 0 <= arrayPos < length()
    return str[arrayPos];
}

//non-const version
char& String::operator[](int arrayPos) {
    //assert((arrayPos >=0) && arrayPos < length());                          //requires 0 <= arrayPos < length()
    return str[arrayPos];
}

//overloading += to be able to concatenate two strings
String& String::operator+=(const String& rhs) {
    int len = length();                                                     //finds length of lhs
    int i = 0;
    if (str == rhs) {                                                       //if the are equal to each other, save the values of lhs to itself
        while ((str[i] != 0) && (i < len)){
            str[len + i] = str[i];
            ++i;
        }
    }
    else {
        while (rhs[i] != 0) {                                                   //loops until it runs into rhs NULL
            str[len + i] = rhs[i];                                              //assigns values of rhs into lhs, starting at the end of the original lhs
            ++i;
        }
    }
    str[len + i] = 0;                                                       //ensures NULL terminator at end
    return *this;                                                           //returns value of the object that was called upon
}

String operator+(String lhs, const String& rhs) {
    lhs += rhs;
    return lhs;
}

bool String::operator==(const String& rhs) const {
    int i = 0;
    while (str[i] != 0 && str[i] == rhs[i]) {
        ++i;
    }
    return str[i] == rhs[i];
}

bool String::operator<(const String& rhs) const {
    int i = 0;
    while ((str[i] != 0) && (rhs[i] != 0) && (str[i] == rhs[i])) {          //runs loop until the characters do not match
        ++i;
    }
    return str[i] < rhs[i];                                                 //returns true or false based on if the character on the left is less than the right
}

String String::substr(int start, int end) const {
    String subString;
    if (start < 0) start = 0;
    if (end >= length()) end = length() - 1;
    if (start > end) return String();

    //int i;
    for (int i = start; i <= end; ++i) {                                    //loops through original array with start and end values specified
        subString.str[i - start] = str[i];                                  //assigns the subString the values of the original array starting at the start point
    }
    subString.str[end + 1] = 0;                                             //ensures NULL
    return subString;                   
}

int String::findch(int startPos, char ch) const {
    if (startPos < 0) startPos = 0;
    if (startPos >= length()) return -1;
    int i = startPos;
    while (str[i] != 0) {                                                   //loops until end of char array
        if (str[i] == ch) return i;                                         //if the array value is equal to the char we are tring to find, return the position
        ++i;
    }
    return -1;
}

int String::findstr(int startPos, const String& substr) const {
    int len = length();
    int subLength = substr.length();
    
    if (startPos >= len) return -1;                                         //checks for out of bounds inputs
    if (subLength == 0) return -1;                                          //checks for empty strings
    
    for (int i = startPos; i < len; ++i) {                                  //loops through original array
        int j = 0;
        while (j < subLength && str[i + j] == substr[j]) {                  //loops through substr array starting at startPos searching for a match
            ++j;                                                            //when a character in the two arrays match up, j will increment, representing how many characters match
        }
        if (j == subLength) {                                               //if j (numbers of characters match) equals the amount of characters in the substr
            return i;                                                       //the program will return the starting point of the string
        }
    }
    return -1;                                                              //if j never equals subLen then no match has been found
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
    out << rhs.str;
    return out;
}

std::istream& operator>>(std::istream& in, String& rhs) {
    char buffer[STRING_SIZE];                                               //creates a char array of size STRING_SIZE
    in >> buffer;                                                           //stores input values into the char array
    rhs = String(buffer);                                                   //converts the char array into a string. Then assigns it to rhs
    return in;
}

bool operator==(const char lhs[], const String& rhs) {return String(lhs) == rhs; }

bool operator==(char lhs, const String& rhs) {return String(lhs) == rhs; }

bool operator<(const char lhs[], const String& rhs) {return String(lhs) < rhs; };

bool operator<(char lhs, const String& rhs) {return String(lhs) < rhs; };

bool operator<=(const String& lhs, const String& rhs) {return !(rhs < lhs); };

bool operator!=(const String& lhs, const String& rhs) {return !(lhs == rhs); };

bool operator>=(const String& lhs, const String& rhs) {return !(lhs < rhs); };

bool operator>(const String& lhs, const String& rhs) {return rhs < lhs;}