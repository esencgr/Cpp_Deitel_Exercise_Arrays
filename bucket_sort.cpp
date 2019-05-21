/* // DEITEL ARRAY EXAMPLES -- 6.31
(Bucket Sort) A bucket sort begins with a single-subscripted array of positive integers to be sorted and a double-subscripted
array of integers with rows subscripted from 0 to 9 and columns subscripted from 0 to n - 1, where n is the number of values
in the array to be sorted. Each row of the double-subscripted array is referred to as a bucket. Write a function bucketSort
that takes an integer array and the array size as arguments and performs as follows:
     a) Place each value of the single-subscripted array into a row of the bucket array based on the value’s ones
        digit. For example, 97 is placed in row 7, 3 is placed in row 3 and 100 is placed in row 0. This is called
        a “distribution pass.”
     b) Loop through the bucket array row by row, and copy the values back to the original array. This is called a
        “gathering pass.” The new order of the preceding values in the single-subscripted array is 100, 3 and 97.
     c) Repeat this process for each subsequent digit position (tens, hundreds, thousands, etc.).
*/
#include <iostream>
using namespace std;
#define SIZE 12

void bucket_sort ( int [] );
int numberof_digits ( int [], int );
void distribute_elements ( int [], int [][ SIZE ], int );
void collect_elements ( int [], int [][ SIZE ] );
void zero_bucket ( int [][ SIZE ] );

int main(){
    int array[ SIZE ] = { 19, 13, 5, 27, 1, 26, 31, 16, 2, 9, 11, 21 };

    cout << "Array elements in original order:\n";
    for ( int i = 0;  i < SIZE;  i++ )
        cout << "  " << array[ i ];
    cout << endl;

    bucket_sort ( array );

    cout << "Array elements in sorted order:\n";
    for ( int j = 0;  j < SIZE;  j++ )
        cout << "  " << array[ j ];
    cout << endl;

    return 0;
}

// Perform the bucket sort algorithm
void bucket_sort( int a[] ) {
    int total_digit, bucket[ 10 ][ SIZE ] = { 0 };

    total_digit = numberof_digits ( a, SIZE );

    for ( int i = 1;  i <= total_digit;  i++ ){
        distribute_elements ( a ,bucket, i );
        collect_elements ( a, bucket );
        if ( i != total_digit )
           zero_bucket ( bucket );
    }
}

// Determine the number of digits in the largest number
int numberof_digits ( int b[], int array_size ){
    int largest = b[ 0 ], digits = 0;

    for ( int i = 1;  i < array_size;  i++ )
        if ( b[ i ] > largest )
           largest = b[ i ];

    while ( largest > 0){
        digits++;
        largest /= 10;
    }

    return digits;
}

// Distribute elements into buckets based on specified digit
void distribute_elements ( int a[], int buckets[][ SIZE ], int digit){
    int divisor = 10, bucket_number, element_number;

    for ( int i = 1;  i < digit;  i++ )   // determine the divisor
        divisor *= 10;                   // used to get specific digit

    for ( int k = 0;  k < SIZE;  k++ ){
        // bucketNumber example for hundreds digit:
        // (1234 % 1000 - 1234 % 100) / 100 --> 2
        bucket_number = ( a[ k ] % divisor - a[ k ] % ( divisor / 10 ) ) / ( divisor / 10 );

        // retrieve value in buckets[bucketNumber][0] to determine
        // which element of the row to store a[i] in.
        element_number = ++buckets[ bucket_number ][ 0 ];
        buckets[ bucket_number ][ element_number ] = a[ k ];
    }

}

// Return elements to original array
void collect_elements ( int a[], int buckets[][ SIZE ]){
    int subscript = 0;

    for ( int i = 0;  i < 10;  i++ )
        for ( int j = 1;  j <= buckets[ i ][ 0 ];  j++ )
            a[ subscript++ ] = buckets[ i ][ j ];
}

// Set all buckets to zero
void zero_bucket ( int buckets[][ SIZE ] ){
    for ( int i = 0;  i < 10;  i++ )
        for ( int j = 0;  j < SIZE;  j++ )
            buckets[ i ][ j ] = 0;
}
