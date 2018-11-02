/*
 Exercise P7.13. Write a program that reads lines of text and appends them to a char buffer[1000]. Stop after reading 1,000 characters. As you read in the text, replace all newline characters '\n' with '\0' terminators. Establish an array char* lines[100], so that the pointers in that array point to the beginnings of the lines in the text. Only consider 100 input lines if the input has more lines. Then display the lines in reverse order, starting with the last input line.
*/

#include <iostream>
#include <string>
#include <sstream>

#define WIDTH 200
#define HEIGHT 10
const int MAX_BUFFER = WIDTH*HEIGHT;

using namespace std;

string lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. \nUt enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. \nDuis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. \nExcepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\nSed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo.\nNemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt.\n Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. \nUt enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";

void fill_lines_array(char c[], char l[][WIDTH], int c_buffer = MAX_BUFFER, int l_buffer = MAX_BUFFER/WIDTH);

int main(int argc, const char * argv[]) {
    char c[MAX_BUFFER];
    strncpy(c, lorem.c_str(), MAX_BUFFER);
    char l[HEIGHT][WIDTH];
    fill_lines_array(c, l, MAX_BUFFER, HEIGHT);
    
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            cout << "l[" << i << "][" << j << "] = " << l[i][j] << endl;
        }
    }
    for (int i = 0; i < HEIGHT; i++){
        cout << "l[" << i << "] = " << *(l+i) << endl;
    }
    cout << "\n";
    cout << "MAX_BUFFER = " << MAX_BUFFER << endl;
    cout << "lorem.length() = " << lorem.length() << endl;
    cout << "sizeof(l) = " << sizeof(l) << endl;
    cout << "\n";
    
    return 0;
}

void fill_lines_array(char c[], char l[][WIDTH], int c_buffer, int l_buffer){
    int k = 0, j = 0;
    for (int i = 0; i < c_buffer; i++){
        if (*(c+i) == '\n'){
            l[k][j] = '\0';
            ++k;
            j = 0;
        } else if (j >= WIDTH-2){
            l[k][j] = *(c+i);
            l[k][j+1] = '\0';
            ++k;
            j = 0;
        } else{
            l[k][j] = *(c+i);
            ++j;
        }
        if (k > HEIGHT){
            exit;
        }
    }
}
