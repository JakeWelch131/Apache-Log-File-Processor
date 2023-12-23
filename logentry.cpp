//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//
 
#include "string.hpp"
#include "logentry.hpp"
#include <iostream>
#include <vector>

int convertInt(String temp) {                                           //free function that converts a String into an integer
    const int numSize = temp.length();                                  //finds the length of the String                                
    int num[numSize];
    for (int i = 0; i < temp.length(); ++i) {                           //loops through each character in the string and changes it to an int. 
        num[i] = temp[i] - '0';                                         //saves these ints into an array
    }
    int returnNum = 0;
    for (int i = 0; i < temp.length(); ++i) {                           //loops through the String length (same as num[] length)
        returnNum *= 10;
        returnNum += num[i];                                            //assigns num[] to a single int
    }
    return returnNum;
}

Date::Date(String s) {                                                  //assigns proper values to each member variable based off position in .txt file
    day = s.substr(1, 2);
    month = s.substr(4, 6);
    String temp = s.substr(8, 11);
    year = convertInt(temp);
    
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.day << "/" << date.month << "/" << date.year;
    return out;
}

Time::Time(String s) {                                                  //assigns proper values to each member variable based off position in .txt file
    String tempHour = s.substr(13, 14);
    hour = convertInt(tempHour);
    String tempMinute = s.substr(16, 17);
    minute = convertInt(tempMinute);
    String tempSecond = s.substr(19, 20);
    second = convertInt(tempSecond);
}

std::ostream& operator<<(std::ostream& out, const Time& time) {
    out << time.hour << ":" << time.minute << ":" << time.second;
    return out;
}

// REQUIRES:
// ENSURES: 
//
LogEntry::LogEntry(String s) {
    // ...
    std::vector<String> vec = s.split(' ');                             //uses split to assign vectors to the LogEntry member variables based on position in .txt files
    if (vec.size() == 10) {
        /*for (int i = 0; i <= 10; ++i) {
            vec[i] = "";
        }*/
        if (vec[9] != "") {
            host = vec[0];
            date = vec[3];
            time = vec[3];
            request = vec[5] + vec[6] + vec[7];
            status = vec[8];
            if(vec[9]!= '-'){
            String tempNumber_of_bytes = vec[9];
            number_of_bytes = convertInt(tempNumber_of_bytes);
            }
            else number_of_bytes = 0;

        }
    
    }
   
}

std::ostream& operator<<(std::ostream& out, const LogEntry& logEntry) {
    out << logEntry.getHost() << " ";
    out << logEntry.getDate()<< " ";
    out << logEntry.getTime()<< " ";
    out << logEntry.getRequest()<< " ";
    out << logEntry.getStatus()<< " ";
    out << logEntry.getBytes()<< " ";
    return out;
}

// REQUIRES:
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    char ch;
    String tempLine;
    in.get(ch);
    while (!in.eof())                                                   //loops until end of file
    {
        if (ch != '\n')                                                 //if the character is not the end of line char
        {
            tempLine += ch;                                             //add char to the string
            in.get(ch);
        }
        else                                                            //if we are at the end of the line
        {
            LogEntry tempLog(tempLine);                                 //take the String as a LogEntry object
            //std::cout << tempLog << std::endl;
            result.push_back(tempLog);                                  //and push it to the result vector
            tempLine = "";
            in.get(ch);                                                 //read next char
        }
        //std::cout << tempLine << std::endl;
    }
    return result;
}

// REQUIRES:
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry> &log) {
    for (size_t i = 0; i < log.size(); ++i) {
    out << log[i] << std::endl;
    }
}

// REQUIRES:
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry> &log) {
    for (std::vector<LogEntry>::size_type i = 0; i < log.size(); ++i) {
        out << log[i].getHost() << std::endl;
    }
}

/// REQUIRES:
// ENSURES: 
//
int byte_count(const std::vector<LogEntry> &log) {
    int total_bytes = 0;
    for (std::vector<LogEntry>::size_type i = 0; i < log.size(); ++i) {
        total_bytes += log[i].getBytes();
    }

    return total_bytes;
}

