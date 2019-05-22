/* DEİTEL EXERCISE RECURSİVE EXAMPLES -6.33-
(Linear Search) Modify the program in Fig. 4.19 to use recursive function linearSearch to perform a linear search of
the array. The function should receive an integer array and the size of the array as arguments. If the search key is found, return the
array subscript; otherwise, return –1.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#define SIZE 10
using namespace std;
int linear_search ( const int [], int, int, int);
int main(){
    int numbers [ SIZE ], key, element;
    srand( time ( NULL ));

    for ( int i = 0;  i < SIZE;  i++)
        numbers[ i ] = 1 + rand() % 10;

    cout << "Original array : ";
    for ( int i = 0;  i < SIZE;  i++)
        cout  << numbers[ i ] << " ";
    cout << endl;

    cout << "Enter the integer search key : ";
    cin >> key;

    element = linear_search ( numbers, key, 0, SIZE - 1 );

    if ( element != -1 )
        cout << "Found value in element " << element << endl;
    else
        cout << "Value not found " << endl;

    return 0;
}
int linear_search ( const int array[], int key, int low, int high){
    if ( array [low] == key )
        return low;
    else if ( low == high )
        return -1;
    else
        return linear_search ( array, key, low + 1, high);
}
