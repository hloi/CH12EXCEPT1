//
// Created by hloi on 12/13/2022.
//

#ifndef CH12EXCEPT1_OPENFILEEXCEPTION_H
#define CH12EXCEPT1_OPENFILEEXCEPTION_H
#include <stdexcept>
#include <string>

using std::exception;
using std::string;

class OpenFileExeption : exception
{
public:
    string msg;
    OpenFileExeption(string s) throw() {
        exception();
        msg = "file not found exception: " +s;
    }
    const char* what() const throw()
    {
        return msg.c_str();
    }
};
#endif //CH12EXCEPT1_OPENFILEEXCEPTION_H
