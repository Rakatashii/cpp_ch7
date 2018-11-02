#include "ccc_empl.h"

Employee::Employee()
{  
   salary = 0;
}

Employee::Employee(string employee_name, double initial_salary)
{  
   name = employee_name;
   salary = initial_salary;
}

void Employee::set_salary(double new_salary)
{  
   salary = new_salary;
}

double Employee::get_salary() const
{  
   return salary;
}

string Employee::get_name() const
{  
   return name;
}
char* Employee::name_char_array(){
    //char* name_chars = const_cast<char*>(name.c_str());
    char *name_chars = new char[name.length() + 1];
    strcpy(name_chars, name.c_str());
    // for some reason, this gives the correct name, whereas this->get_name().c_str() gives the wrong output...
    //cout << "name_chars_in_member: " << name_chars << endl;
    return name_chars;
}
char* Employee::salary_char_array(){
    int num_digits_in_salary = ceil(log10(salary));
    ostringstream os;
    os << setprecision(num_digits_in_salary) << salary;
    string salary_string = os.str();
    //char* salary_chars = const_cast<char*>(salary_string.c_str());
    char* salary_chars = new char(num_digits_in_salary+1);
    // ^ Why does this work but not the const cast?
    strcpy(salary_chars, salary_string.c_str());
    return salary_chars;
}
/*
 Exercise P7.12. Add a member function
 void Employee::format(char buffer[], int buffer_maxlength)
 to the Employee class. The member function should fill the buffer with the name and salary of the employee. Be sure not to overrun the buffer. It can hold buffer_maxlength characters, not counting the '\0' terminator. (That is, the buffer has buffer_maxlength + 1 bytes available.) Be sure to provide a '\0' terminator.
 */
void Employee::format(char buffer[], int buffer_maxlength, bool space){
    char* name_chars = name_char_array();
    char* salary_chars = salary_char_array();
    //cout << "name_chars (in format): " << name_chars << endl;
    //cout << "salary_chars (in format): " << salary_chars << endl;
    int name_size = strlen(name_chars);
    int salary_size = strlen(salary_chars);
    if (buffer_maxlength <= (name_size+salary_size)){
        buffer_maxlength = name_size+salary_size+1;
    }
    for (int i = 0; i < name_size; i++){
        *(buffer+i) = *(name_chars+i);
    }
    if (space){
        *(buffer+name_size) = ' ';
        name_size++;
        buffer_maxlength++;
        
    }
    for (int i = name_size; i < buffer_maxlength; i++){
        *(buffer+i) = *(salary_chars+(i-name_size));
    }
    *(buffer+(buffer_maxlength-1)) = '\0';
}

