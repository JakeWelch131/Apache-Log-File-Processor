//String project implementation file Milestone2-4
//Jacob Welch
//10/6/2023

#include "string.hpp"

String::String() {
    stringSize = 1;
    str = new char[stringSize];
    str[0] = 0;
}

String::String(char ch) {
    if (ch == 0) {                                                          //checks if an empty char is passed
        stringSize = 1;                                                     // if so, it is treated like a default constructor
        str = new char[1];
        str[0] = 0;
    }
    else {
        stringSize = 2;
        str = new char[stringSize];                                         //if it is a single char a new array is created on the heap
        str[0] = ch;                                                    
        str[1] = 0;                                                         //ensures a null terminator
    }
}

String::String(const char charArray[]) {
    int i = 0;
    while (charArray[i] != 0) {                                             //finds how long the charArray is in order to allocate enough space on heap
        ++i;
    }

    stringSize = i + 1;                                                     //add 1 for null terminator

    i = 0;
    str = new char[stringSize];                                             //uses the length we found before to create a charArray on the heap with ample space
    while (charArray[i] !=0) {
        if (i >= stringSize - 1) break;                                     //prevents out-of-bounds assignments
        str[i] = charArray[i];
        ++i;
    }
    str[i] = 0;                                                             //ensures null
}

String::String(const String& copy) {
    stringSize = copy.stringSize;                                           //assigns the size of the copy to the size of the original
    str = new char[stringSize];                                             //creates new charArray with proper size on the heap
    if (stringSize == 1) {
        str[0] = copy.str[0];                                               //ensures copy ctor works with empty strings
    }
    else {
        for (int i = 0; i < stringSize - 1; ++i) {
            str[i] = copy.str[i];                                           //copies values into original array
        }
    }
    str[stringSize - 1] = 0;
}

String::~String() {
    delete[] str;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
    out << rhs.str;
    return out;
}

bool String::operator==(const String& rhs) const {
    int i = 0;
    while (str[i] != 0 && str[i] == rhs[i]) {
        ++i;
    } 
    return str[i] == rhs[i];
}

char String::operator[](int arrayPos) const {
    return str[arrayPos];
}

char& String::operator[](int arrayPos) {
    return str[arrayPos];
}

void String::swap(String& rhs) {
    char *temp = str;                                                       //points a temporary pointer at the original
    str = rhs.str;                                                          //assigns values of rhs to original
    rhs.str = temp;                                                         //assigns values of original to rhs, effectively swapping the values 
    int tempStringSize = stringSize;                                        //assigns value of the original to a temporary int
    stringSize = rhs.stringSize;                                            //assigns the size of rhs to the original
    rhs.stringSize = tempStringSize;                                        //assigns the size of the original to rhs
}

String& String::operator=(String rhs) {
    swap(rhs);
    return *this;
}

int String::capacity() const {
    return stringSize - 1;
}

int String::length() const {
    int length = 0;
    while (str[length] != 0) {
        ++length;
    }
    return length;
}

String& String::operator+=(const String& rhs) {
    int len = length();                                                     // find length of lhs
    int rhsLen = rhs.length();                                              // find length of rhs
    char* newStr = new char[len + rhsLen + 1];                              //creats a pointer to a new char array with the appropriate amount of space to fit lhs,rhs, and null terminator

    int i = 0;
    while(i < len) {                                                        //fills the new string with the values of lhs
        newStr[i] = str[i];
        ++i;
    }

    i = 0;
    while(i < rhsLen) {                                                     //fills the new string with the values of lhs
        newStr[len + i] = rhs.str[i];
        ++i;
    }
    newStr[len + rhsLen] = 0;                                               //Ensure null termination
    delete[] str;                                                           //gets rid of old memory to allow str to be updated
    str = newStr;                                                           //updates str with new values 
    stringSize = len + rhsLen + 1;                                          //updates stringSize

    return *this;                                                           //returns values of updated string                                                            
}

bool String::operator<(const String& rhs) const {
    int i = 0;
    while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) {  //runs loop until the characters do not match
        ++i;
    }
    return str[i] < rhs.str[i];   
}

String String::substr(int start, int end) const {
    if (start < 0) start = 0;
    if (end >= length()) end = length() - 1;
    if (start > end) return String();

    int arrSize = (end - start) + 1;                                        //finds the amount of space needed for substring
    char* subStringchars = new char[arrSize + 1];                           //creates a pointer that points to a charArray on heap

    for (int i = 0; i < arrSize; ++i) {                                     //loops through arrSize
        subStringchars[i] = str[i + start];                                 //assigns the subString the values of the original array starting at the start point
    }

    subStringchars[arrSize] = 0;                                            //ensures null terminator

    String subString(subStringchars);                                       //creates a String from the dynamically allocated characters

    delete[] subStringchars;                                                //frees the dynamically allocated memory

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
        while (j < subLength && str[i + j] == substr.str[j]) {              //loops through substr array starting at startPos searching for a match
            ++j;                                                            //when a character in the two arrays match up, j will increment, representing how many characters match
        }
        if (j == subLength) {                                               //if j (numbers of characters match) equals the amount of characters in the substr
            return i;                                                       //the program will return the starting point of the string
        }
    }
    return -1;                                                              //if j never equals subLen then no match has been found
}

std::vector<String> String::split(char ch) const {
    int startPos = 0;
    std::vector<String> newString;                                          //creates a vector of type ADT String
    int end = findch(startPos, ch);                                         //sets end to where the character is
    
    while (end != -1) {                                                     //loops to end of String
        String subString = substr(startPos, end - 1);
        
        newString.push_back(subString);
        
        startPos = end + 1;
        end = findch(startPos, ch);
    }
    
    String lastString = substr(startPos, length() - 1);
    newString.push_back(lastString);
    return newString;
}

std::istream& operator>>(std::istream& in, String& rhs) {
    const int stringSize = 500;
    char buffer[stringSize];                                                //creates a char array of size STRING_SIZE
    in >> buffer;                                                           //stores input values into the char array
    rhs = String(buffer);                                                   //converts the char array into a string. Then assigns it to rhs
    return in;
}


String  operator+(String lhs, const String& rhs) {
    return lhs += rhs;
}

bool operator==(const char lhs[], const String& rhs) {return String(lhs) == rhs; }

bool operator==(char lhs, const String& rhs) {return String(lhs) == rhs; }

bool operator<(const char lhs[], const String& rhs) {return String(lhs) < rhs; };

bool operator<(char lhs, const String& rhs) {return String(lhs) < rhs; };

bool operator<=(const String& lhs, const String& rhs) {return !(rhs < lhs); };

bool operator!=(const String& lhs, const String& rhs) {return !(lhs == rhs); };

bool operator>=(const String& lhs, const String& rhs) {return !(lhs < rhs); };

bool operator>(const String& lhs, const String& rhs) {return rhs < lhs;}
