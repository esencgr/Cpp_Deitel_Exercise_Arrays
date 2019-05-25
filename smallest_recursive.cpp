// Deitel array exercise - 6.39 -
/*
(Find the minimum value in an array) Write a recursive function recursiveMinimum that takes an integer array and
the array size as arguments and returns the smallest element of the array. The function should stop processing and
return when it receives an array of 1 element.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define SIZE 10
#define MAX 500

int rec_min ( const int [], int, int );

int main(){
    int array [ SIZE ];
    srand ( time ( NULL ));

    for ( int i= 0;  i < SIZE;  i++)
        array[ i ] = 1 + rand() %  MAX;

    cout << "Array values printed in main:\n";

    for ( int j = 0;  j < SIZE;  j++)
        cout << array[ j ] << " ";
    cout << endl;

    cout << "Recursive minimum : ";
    int smallest = rec_min ( array, 0 , SIZE - 1 );
    cout << smallest;
    cout << endl;

    return 0;
}

int rec_min ( const int array[], int low, int high ){
     static int smallest = MAX;
     if ( array [ low ] < smallest )
        smallest = array [ low ];

     if ( low == high )
        return smallest;
     else
        return rec_min ( array, low+1, high );
}
