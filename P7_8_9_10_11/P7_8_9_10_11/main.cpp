/*
 Exercise P7.8.
 Implement the strncpy function of the standard library.
 Exercise P7.9.
 Implement the standard library function:
 
 int strspn(const char s[], const char t[])
 
 that returns the length of the initial portion of s consisting of characters in t (in any order).
 Exercise P7.10.
 Write a function:
 
 void reverse(char s[])
 
 that reverses a character string. For example, "Harry" becomes "yrraH".
 Exercise P7.11.
 Using the strncpy and strncat functions, implement a function:
 
 void concat(const char a[], const char b[], char result[], int result_maxlength)
 
 that concatenates the strings a and b to the buffer result. Be sure not to overrun the result. It can hold result_maxlength characters, not counting the '\0' terminator. (That is, the buffer has result_maxlength + 1 bytes available.) Be sure to provide a '\0' terminator.
*/

#include <iostream>
//#include <string>

using namespace std;

/* counts number of characters in s that are in t
    @s[] is the string that is scanned
    @t[] is the string that is being matched
    - changed name from strspn bc of overload
*/
size_t strspan(const char s[], const char t[]);
void reverse(char s[]);
void concat(const char a[], const char b[], char result[], int result_maxlength = -1);

int main(int argc, const char * argv[]) {
    char a[] = "Dolphin";
    char b[] = "o2x8l6peknj"; //olpn - 4
    size_t match_size = strspan(a, b);
    cout << "match_size = " << match_size << endl;
    
    reverse(a);
    cout << "reverse(\"Dolphin\") = " << a << endl;
    
    char c[] = "Apple ";
    char d[] = "Cider ";
    size_t c_size = strlen(c);
    size_t d_size = strlen(d);
    size_t max_buffer = c_size+d_size+1;
    char r[max_buffer];
    cout << "\n";
    
    size_t c_size_t = sizeof(c);
    size_t d_size_t = sizeof(d);
    cout << "size of c in bytes = " << c_size_t << endl;
    cout << "size of d in bytes = " << d_size_t << endl;
    
    // An array of char pointers
    char* arr[2] = {c, d};
    cout << "arr[0][0]: " << arr[0][0] << endl;
    cout << "arr[1][0]: " << arr[1][0] << endl;
    size_t arr_size_t = sizeof(arr);
    cout << "size of arr in bytes = " << arr_size_t << endl; // 7 + 7 + 2, the two new local variables.
    cout << "\n";
    
    concat(c, d, r, max_buffer);
    cout << "result (in main) = " << r << endl;
    cout << "result (\\0 apparent?) " << *(r+(max_buffer-1)) << endl; // NOPE
    cout << "\n";
    
    // Tried endlessly to make this more dynamic by passing an *r into the function so that the buffer size does not have to be specified right away. Seems all the variables acting as parameters need to be normal char arrays that act as pointers within that function.
    // concat(c, d, *res);
    // cout << "result (in main) = " << res << endl ;
    
    return 0;
}
/*
 Using the strncpy and strncat functions, implement a function...
 that concatenates the strings a and b to the buffer result. Be sure not to overrun the result. It can hold result_maxlength characters, not counting the '\0' terminator. (That is, the buffer has result_maxlength + 1 bytes available.) Be sure to provide a '\0' terminator.
 */
void concat(const char a[], const char b[], char result[], int result_maxlength){
    int a_size = strlen(a);
    int b_size = strlen(b);
    if (result_maxlength == -1){
        result_maxlength = (a_size+b_size+1);
        result = new char[result_maxlength];
    }
    cout << "result_maxlength: " << result_maxlength << endl;
    for(int i = 0; i < a_size; i++){
        *(result+i) = *(a+i);
    }
    for(int i = a_size; i < result_maxlength-2; i++){
        *(result+i) = *(b+(i-a_size));
    }
    cout << "result (final in function) = " << result << endl;
    *(result+(result_maxlength-1)) = '\0';
}
void reverse(char s[]){
    size_t s_size = strlen(s);

    char r[s_size];
    int i = 0;
    for (int j = s_size-1; j >= 0; j--){
        r[i] = *(s+j);
        i++;
    }
    for (i = 0; i < s_size; i++){
        *(s+i) = r[i];
    }
}
size_t strspan(const char s[], const char t[]){
    size_t s_size = strlen(s);
    size_t t_size = strlen(t);
    size_t match_count = 0;
    char t_copy[t_size];
    
    for (int i = 0; i < s_size; i++){
        for (int j = 0; j < t_size; j++){
            t_copy[j] = *(t+j);
            if (s[i] == t_copy[j]){
                match_count++;
                t_copy[j] = ' ';
            }
        }
    }
    return match_count;
}





