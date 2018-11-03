/*
 Exercise P7.14. The program in Exercise P7.13 is limited by the fact that it can only handle inputs of 1,000 characters or 100 lines. Remove this limitation as follows. Concatenate the input in one long string object. Use the c_str member function to obtain a char* into the string’s character buffer. Establish the offsets of the beginnings of the lines as a vector<int>.
 Exercise P7.15. Exercise P7.14 demonstrated how to use the string and
 vector classes to implement resizable arrays. In this exercise, you should implement that capability manually. Allocate a buffer of 1,000 characters from the heap (new char[1000]). Whenever the buffer fills up, allocate a buffer of twice the size, copy the buffer contents, and delete the old buffer. Do the same for the array of char* pointers—start with a new char*[100] and keep doubling the size.
 */


#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define WIDTH 200
#define HEIGHT 10
const int MAX_BUFFER = WIDTH*HEIGHT;

using namespace std;

string lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. \nUt enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. \nDuis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. \nExcepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\nSed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo.\nNemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt.\nNeque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. \nUt enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";

char** test_func();

/* Has the purpose as the fill lines array, but returns a 2-d char array rather than changing its value as a parameter in #fill_lines_array. The added bonus of this function is that buffer sizes for the number of character arrays in array returned, or the number of characters in those arrays, do not need to be specified. Rather, they are set within the function depending on the inpit string itself.
    @s is the string that will be converted into a character array
    @underscores is simply an option to print spaces as '_' so that they are more clear in output. This argument defaults to false.
 */
char** get_lines(string s, bool underscores = false);
/* This function is similar to the previous, but is less sophisticated since the the 2d character array, the char arrays within that one, and the size of the flat char array, must all be specified before the function is called. Also notice that it returns a 2d array, rather than taking one as a parameter and modifying it, as in the previous.
    @ c[] is the char array that holds the flat string, in this case, the lorem string below.
    @ l[][WIDTH] is the 2d char array that holds of the lines in c[]. Whereas the lines were separated in c[] by '\n', in l[][] that is changed to '\0' to distinguish the invidivual char arrays within l.
    @ MAX_BUFFER is the maximum size of c[], and is also the maximum number of characters in all of the l[] arrays combined.
    @ l_buffer (this isn't named well) is the height of l - the number of char arrays that it contains.
*/
void fill_lines_array(char c[], char l[][WIDTH], int c_buffer = MAX_BUFFER, int l_buffer = MAX_BUFFER/WIDTH);
/* This function does the same thing as the previous. The most important difference is that it does not rely on vectors to provide integer values for the sizes of the subarrays. Not that that is a good thing...
    @s is the string to be converted into a char array.
    @lines_size is simply the reference to an int that is set within the function to give the size of the 2d array that the function is returning
 */
char** make_lines_array(string s, int& lines_size);

int main(int argc, const char * argv[]) {
    char c[MAX_BUFFER];
    strncpy(c, lorem.c_str(), MAX_BUFFER);
    char l[HEIGHT][WIDTH];
    fill_lines_array(c, l, MAX_BUFFER, HEIGHT);
    
    /* // Print l[][], each index for each char array in l
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            cout << "l[" << i << "][" << j << "] = " << l[i][j] << endl;
        }
    }
     */
    
    /* // Print each char array in l
    for (int i = 0; i < HEIGHT; i++){
        //cout << "l[" << i << "] = " << *(l+i) << endl;
    }
     */
    
    /* // print sizes
    cout << "\n";
    cout << "MAX_BUFFER = " << MAX_BUFFER << endl;
    cout << "lorem.length() = " << lorem.length() << endl;
    cout << "sizeof(l) = " << sizeof(l) << endl;
    cout << "\n";
     */
    
    char** arr1 = get_lines(lorem);
    
    /* // print each char array in 2-d char array arr1
    for (int i = 0; i < 7; i++){
        cout << "arr1[" << i << "]:\n" << arr1[i] << endl;
    }
    cout << "\n";
     */
    
    int lines_size = 0;
    char** arr2 = make_lines_array(lorem, lines_size);
    for (int i = 0; i <= lines_size; i++){
        cout << "arr2[" << i << "]:\n" << arr2[i] << endl;
    }
    cout << "\n";
    return 0;
}

char** get_lines(string s, bool underscores){
    char c[s.size()];
    strncpy(c, s.c_str(), s.length());
    
    vector<int> offsets = {};
    int c_size = strlen(c);
    
    int j = 0;
    for (int i = 0; i < c_size; i++){
        if (*(c+i) == '\n'){
            offsets.push_back(j);
            j = 0;
        } else {
            j++;
        }
    }
    
    int arr_size = offsets.size();
    char **arr = new char*[arr_size];
    
    int k = 0;
    j = 0;
    int k_size = offsets[0];
    for (int i = 0; i < c_size && k < arr_size; i++){
        if (j == 0){
            k_size = offsets[k];
            arr[k] = new char[k_size];
            arr[k][j] = *(c+i);
            if (arr[k][j] == '\n'){
                arr[k][j] = ' ';
            }
            if (arr[k][j] == ' ' && underscores == true){
                arr[k][j] = '_';
            }
            j++;
        }
        while (j <= k_size){
            i++;
            if (j == (k_size)){
                arr[k][j] = '\0';
                j = 0;
                k++;
                goto end;
            } else {
                arr[k][j] = *(c+i);
                if (arr[k][j] == ' ' && underscores == true){
                    arr[k][j] = '_';
                }
                j++;
            }
        }
    end: {}
    }
    return arr;
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
            goto end;
        }
    }
end: {}
}

char** make_lines_array(string s, int& lines_size){
    char c[s.size()];
    strcpy(c, s.c_str());
    int c_size = strlen(c);
    
    int arr_size = 1, el_size = 100;
    char **arr = new char*[arr_size];
    
    int k = 0, j = 0;
    bool go = true;
    for (int i = 0; i < c_size; i++){
        if (k >= arr_size){
            char** temp = arr;
            arr_size *= 2;
            arr = new char*[arr_size];
            for (int l = 0; l < k; l++){
                arr[l] = new char[strlen(temp[l])];
                strncpy(arr[l], temp[l], strlen(temp[l]));
            }
            i -= j;
            j = 0;
        }
        if (j > el_size){
            el_size *= 2;
            i -= j+1; // i is reset to j+1, since i will be incremented at the end of the loop
            j = 0; // so the next run will enter the loop below (j == 0)
        } else if (j == 0){
            arr[k] = new char[el_size];
            arr[k][j] = *(c+i);
            j++;
        } else if (*(c+i) == '\n' && (j != 0)){
            arr[k][j] = '\0';
            k++;
            el_size = 100;
            j = 0;
        } else{
            arr[k][j] = *(c+i);
            j++;
        }
    }

    lines_size = k;
    return arr;
}

