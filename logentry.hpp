//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class definition for a log entry.
//
//
//
 
#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>

class Date {
public:
            Date() {};
            Date(String);
            String getDay() {return day; };
            String getMonth() {return month; };
            int getYear() {return year; };
            friend  std::ostream& operator<<(std::ostream&, const Date&);


private:
    String  day, month;
    int     year;
};


class Time {
  public:
            Time() {};
            Time(String);
            int getHour() {return hour; };   
            int getMinute() {return minute; };
            int getSecond() {return second; };
            friend  std::ostream& operator<<(std::ostream&, const Time&);
  private:
    int     hour, minute, second;
};



class LogEntry {
public:
            LogEntry() {};
            LogEntry(String);
            String getHost() const {return host; };
            Date getDate() const {return date; };
            Time getTime() const {return time; };
            String getRequest() const {return request; };
            String getStatus() const {return status; };
            int getBytes() const {return number_of_bytes; };
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);
int                     convertInt  (String);
#endif

