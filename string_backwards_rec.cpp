// Deitel array exercise - 6.38 -
/*
(Print a string backwards) Write a recursive function stringReverse that takes a character array containing a string as
an argument, prints the string backwards and returns nothing. The function should stop processing and return when the
terminating null character is encountered.
*/
#include <iostream>
#include <string>
using namespace std;
#define SIZE 30
void string_reverse ( const char[] );

int main(){
    char str [ SIZE ] = " Print this string backwards.";

    for ( int i = 0; i < SIZE;  i++)
        cout << str [ i ];
    cout << endl ;

    string_reverse (str);
    cout << endl;

    return 0;
}

void string_reverse ( const char stra [] ){

     if ( stra[ 0 ] == '\0' )
        return;

     string_reverse( &stra[ 1 ] );
     cout << stra[ 0 ];
}
