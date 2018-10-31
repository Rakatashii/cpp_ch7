#include <iostream>
#include <iomanip>

int main(int argc, const char * argv[]) {
    int* n = new int(10);
    std::cout << std::left << std::setw(8) << std::setfill(' ') << "n    = ";
    std::cout << std::left << std::setw(12) << std::setfill(' ') << n;
    std::cout << std::left << std::setw(15) << std::setfill(' ') <<  "(A memory address)" << std::endl;
    std::cout << std::left << std::setw(8) << std::setfill(' ') << "(*n) = ";
    std::cout << std::left << std::setw(12) << std::setfill(' ') << (*n);
    std::cout << std::left << std::setw(15) << std::setfill(' ') << "(The object that n points to)" << std::endl;
    std::cout << "\n";
    
    int* i = n;
    delete n;
    n = NULL;
    
    std::cout << std::left << std::setw(8) << std::setfill(' ') << "n    = ";
    std::cout << std::left << std::setw(12) << std::setfill(' ') << n;
    std::cout << std::left << std::setw(15) << std::setfill(' ') <<  "(A memory address)" << std::endl;
    // ^ This works, the memory address is "0x0", which indicates that there is actually no set memory address
    /*
     std::cout << std::left << std::setw(8) << std::setfill(' ') << "(*n) = ";
     std::cout << std::left << std::setw(12) << std::setfill(' ') << (*n);
     std::cout << std::left << std::setw(15) << std::setfill(' ') << "(The object that n points to)" << std::endl;
     */
    // ^ This does not work. n no longer points to an object, so it is an error to try and dereference n.
    std::cout << "\n";
    
    std::cout << std::left << std::setw(8) << std::setfill(' ') << "i    = ";
    std::cout << std::left << std::setw(12) << std::setfill(' ') << i;
    std::cout << std::left << std::setw(15) << std::setfill(' ') <<  "(A memory address)" << std::endl;
    std::cout << std::left << std::setw(8) << std::setfill(' ') << "(*i) = ";
    std::cout << std::left << std::setw(12) << std::setfill(' ') << (*i);
    std::cout << std::left << std::setw(15) << std::setfill(' ') << "(The object that i points to)" << std::endl;
    std::cout << "\n";
    
    std::shared_ptr<int> x(new int(50));
    
    std::cout << std::left << std::setw(8) << std::setfill(' ') << "x    = ";
    std::cout << std::left << std::setw(12) << std::setfill(' ') << x;
    std::cout << std::left << std::setw(15) << std::setfill(' ') <<  "(A memory address)" << std::endl;
    std::cout << std::left << std::setw(8) << std::setfill(' ') << "(*x) = ";
    std::cout << std::left << std::setw(12) << std::setfill(' ') << (*x);
    std::cout << std::left << std::setw(15) << std::setfill(' ') << "(The object that i points to)" << std::endl;
    std::cout << "\n";
    
    std::shared_ptr<int> y = x;
    std::cout << std::left << std::setw(8) << std::setfill(' ') << "y    = ";
    std::cout << std::left << std::setw(12) << std::setfill(' ') << y;
    std::cout << std::left << std::setw(15) << std::setfill(' ') <<  "(A memory address)" << std::endl;
    std::cout << std::left << std::setw(8) << std::setfill(' ') << "(*y) = ";
    std::cout << std::left << std::setw(12) << std::setfill(' ') << (*y);
    std::cout << std::left << std::setw(15) << std::setfill(' ') << "(The object that i points to)" << std::endl;
    std::cout << "\n";
    
    std::cout << "Here, using std::shared_ptr::unique(), which returns a boolean value depending on how many references there are to the object pointed to." << std::endl;
    std::cout << "It follows, #unique() is a member function of the objects of the shared_ptr class." << std::endl;
    std::cout << "\n";
    
    if (y.unique()){
        std::cout << "y IS unique." << std::endl;
    } else if (!(y.unique())){
        std::cout << "y IS NOT unique." << std::endl;
    }
    std::cout << "\n";
    
    x = NULL;
    std::cout << "After 'x = NULL;': " << std::endl;
    if (y.unique()){
        std::cout << "y IS unique." << std::endl;
    } else if (!(y.unique())){
        std::cout << "y IS NOT unique." << std::endl;
    }
    std::cout << "\n";
    
    return 0;
}

