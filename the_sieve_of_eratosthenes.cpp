/*
(The Sieve of Eratosthenes) A prime integer is any integer that is evenly divisible only by itself and 1. The Sieve of
Eratosthenes is a method of finding prime numbers. It operates as follows:
   a) Create an array with all elements initialized to 1 (true). Array elements with prime subscripts will remain 1. Allother
      array elements will eventually be set to zero.
   b) Starting with array subscript 2 (subscript 1 must be prime), every time an array element is found whose value is 1,loop
      through the remainder of the array and set to zero every element whose subscript is a multiple of the subscript for the
      element with value 1. For array subscript 2, all elements beyond 2 in the array that are multiples of 2 will be set to
      zero (subscripts 4, 6, 8, 10, etc.); for array subscript 3, all elements beyond 3 in the array that are multiples of 3
      will be set to zero (subscripts 6, 9, 12, 15, etc.); and so on,
  When this process is complete, the array elements that are still set to one indicate that the subscript is a prime number.
  These subscripts can then be printed. Write a program that uses an array of 1000 elements to determine and print the prime
  numbers between 1 and 999. Ignore element 0 of the array.
*/

#include <iostream>
#define SIZE 1000
using namespace std;
int main(){
    int array [ SIZE ], count = 0;

    for (int k = 0;  k < SIZE;  k++)
        array [k] = 1;

    for (int i = 2;  i < SIZE;  i++)
        for (int j = i;  j <= SIZE;  j++)
            if ( j % i == 0 &&  j != i )
               array [j] = 0;

    for (int q = 2;  q < SIZE;  q++) {
        if (array [q] == 1){
           cout << q << " is prime number.." << endl;
           count++;
        }
    }
    cout << " total prime numbers = " << count << endl;
return 0;
}
