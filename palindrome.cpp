/* DEİTEL EXERCISE RECURSİVE EXAMPLES -6.33-
(Palindromes) A palindrome is a string that is spelled the same way forwards and backwards. Some examples of palindromes
are “radar,” “able was i ere i saw elba” and (if blanks are ignored) “a man a plan a canal panama.” Write a recursive function
testPalindrome that returns true if the string stored in the array is a palindrome, and false otherwise. The function should
ignore spaces and punctuation in the string.
*/

#include <iostream>
using namespace std;
bool test_palindrome ( const char [ ], int, int );
#define SIZE 80
int main(){

    char c, string [ SIZE ], copy [ SIZE ] = {'0'};
    int count = 0, copy_count = 0;

    cout << "Enter a sentence:\n";

    while ( ( c = cin.get() ) != '\n'  &&  count < SIZE )
        string [ count++ ] = c;

    string [ count ] = '\0';

    // make a copy of cstring without spaces
    for ( int  i = 0;  string [ i ] != '\0';  i++)
        if ( string [ i ] != ' ' )
           copy [ copy_count++ ] = string[ i ];

    cout << copy << " --> string without spaces" << endl;

    if ( test_palindrome ( copy, 0, copy_count-1 ))
        cout << string << " --> is a palindrome" << endl;
    else
        cout << string << " --> is not a palindrome" << endl;
}

bool test_palindrome ( const char array[], int left, int right ){
    if ( left == right || left > right )
        return true;
    else if ( array[ left ] != array[ right ] )
        return false;
    else
        return test_palindrome ( array, left + 1 , right - 1 );
}
