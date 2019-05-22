// DEİTEL EXERCISE RECURSİVE EXAMPLES -6.32-
/*
(Selection Sort) A selection sort searches an array looking for the smallest element in the array. Then, the smallest element
is swapped with the first element of the array. The process is repeated for the subarray beginning with the second element of
the array. Each pass of the array results in one element being placed in its proper location. This sort performs comparably to
the bubble sort—for an array of n elements, n - 1 passes must be made, and for each subarray, n - 1 comparisons must be made to
find the smallest value. When the subarray being processed contains one element, the array is sorted. Write recursive function
selectionSort to perform this algorithm.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#define SIZE 10
using namespace std;

void selection ( int array[ ], int );
int main (){

    int array [ SIZE ] = { 0 }, range;
    cout << "enter range of array elements = ";
    cin >> range;

    srand ( time ( NULL ));

    for (int i = 0; i < SIZE;  i++)
       array [i] = 1 + rand() % range;

    cout << "unsorted array : " << endl ;
    for (int i = 0; i < SIZE;  i++)
        cout << array [i] << " ";
    cout << endl;

    selection ( array , SIZE );

    cout << "sorted array : " << endl ;
    for (int i = 0; i < SIZE;  i++)
        cout << array [i] << " ";
    cout << endl;

    return 0;
}

void selection ( int array[], int size ){
    int temp;
    if ( size >= 1 ){
       for (int i = 0; i < size; i++)
           if ( array[ i ] < array[ 0 ] ){
               temp = array[ i ];
               array[ i ] = array[ 0 ];
               array[ 0 ] = temp;
           }
     selection ( &array[ 1 ] , size - 1 );
    }
}
