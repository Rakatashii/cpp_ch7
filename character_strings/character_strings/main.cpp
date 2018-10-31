#include <iostream>
#include <string>

#include <catch2/catch.hpp>

int main(int argc, const char * argv[]) {
    std::string s1_name = "Henry";
    //cout << "s1_name = " << s1_name << endl;
    
    // **** String::c_str() ****
    // The string member function #c_str() converts a string object into a char* object
    const char* c1_name = s1_name.c_str();
    //cout << "c1_name = " << c1_name << endl;
    
    // **** String::string(char* c_str) ****
    // The string constructor takes a char* obj as an optional parameter and converts it into a string obj.
    std::string s2_name(c1_name);
    std::cout << "s2_name = " << s2_name << std::endl;
    std::cout << "\n";
    
    // **** (Char*)::char*::tmpname(char* c) ****
    // returns a temporary made up file name. So far, not sure how to get it to work with any parameter aside from NULL though. This seems to be an issue with the buffer size of the char* parameter.
    //const char* dir = tmpnam(NULL);
    //std::cout << "dir = " << dir << std::endl;

    std::cout << "\n";
    return 0;
}

