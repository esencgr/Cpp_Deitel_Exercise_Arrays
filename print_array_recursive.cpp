// Deitel array exercise - 6.37 -
/*
(Print an array) Write a recursive function printArray that takes an array and the size of the array as arguments and
returns nothing. The function should stop processing and return when it receives an array of size zero.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define SIZE 10
#define MAX 500

void print_array ( const int [], int, int );

int main(){
    int array [ SIZE ];
    srand ( time ( NULL ));

    for ( int i= 0;  i < SIZE;  i++)
        array[ i ] = 1 + rand() %  MAX;

    cout << "Array values printed in main:\n";

    for ( int j = 0;  j < SIZE;  j++)
        cout << array[ j ] << " ";
    cout << endl;

    cout << "Array values printed in recursive function:\n";
    print_array ( array, 0 , SIZE - 1 );
    cout << endl;

    return 0;
}

void print_array ( const int array[], int low, int high ){
     cout << array[ low ] << " ";
     if ( low == high )
        return;
     else
        print_array ( array , low + 1, high );
}
