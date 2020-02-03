// File: lab10exe_B.cpp
// ENSF 337 - Fall 2018 - LAB 10

#include <iostream>

using namespace std;

void print (const char** string_array, int n);
/* REQUIRES:
 *   n > 0.
 *   Array elements string_array[0] ... string_array[n - 1] exist, and each
 *   element points to the beginning of a C-string.
 *
 * PROMISES:
 *   prints C-strings in string_array, one string per line.
 */

void append_strings (const char** string_array, int n, char** appended_string);
/* REQUIRES:
 *   n > 0.
 *   Array elements string_array[0] ... string_array[n - 1] exist, and each
 *   element points to the beginning of a C-string. 
 *   appended_string points to a variable of type char *. In other words, 
 *   appended_string must not be a null pointer or some other not-useful 
 *   address.)
 *
 * PROMISES:
 *   uses *appended_string to allocate an array of characters dynamically, large
 *   enough to concatenate copies of C-strings from string_array into this space,
 *   and to create a valid c-string by adding a '\0'.
 *
 * EXAMPLE:
 *   if n is 3 and string_array[0] == "abc", string_array[1] == "XYZ", and
 *   string_arry[2] == "123", this function should result in *appended_strings
 *   pointing to "abcXYZ123"
 */

int main(void) {
    const char* strings[] = {"Red.", "pink.", "almond.","white.", "Law.", "cup"};
    char s[] = "But it doesn't! Please fix it...";
    char* concatenated = s;
    
    int n_elements = sizeof(strings) / sizeof(char*);
    
    cout << "The " << n_elements << " strings are: \n";
    print(strings, n_elements);
    
    append_strings(strings, n_elements, &concatenated);
    
    cout << "\nExpected to display: Red.pink.almond.white.Law.cup\n";
    cout << concatenated << endl;
    
    return 0;
}


void append_strings (const char** string_array, int n, char** appended_string) {
    // Students must complete this function, based on the given function
    // interface comments.
    // Note: you are NOT allowed to use library function strcat to concatenate
    //       the strings in the string_array.
}


void print(const char** string_array, int n) {
    for(int i =0; i < n; i++){
        cout << string_array[i] << endl;
        
    }
}
