#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define SIZE 3

using namespace std;
int main (){
    srand(time(0));
    int number;
    for (int i = 1; i < 101; i++){
        number = 1 + rand () % 6;
        cout << number << " ";
        if (i % 10 == 0)
           cout << endl;
    }

    int array1[SIZE], array2[SIZE];
    double array3 [SIZE] ;

    cout << "please enter array1 : ";
    for (int i = 0; i < SIZE;  i++)
         cin >> array1 [i];

    cout << "please enter array2 : ";
    for (int j = 0; j < SIZE;  j++)
         cin >> array2 [j];

    cout << "array3 for this input value :";
    for (int k = 0; k < SIZE;  k++)
         array3 [k] =(double)(array1 [k] * array2 [k]) / (array1 [k] + array2[k]);
    for (int k = 0; k < SIZE;  k++)
         cout << array3 [k] << " ";

    int size = 100;
    bool x = false;
         for (int i = 1; i <= 100; i++) {
             x = false;
             for (int d = 2; d < i; d++){
                 if (i % d == 0){
                    x = true;
                    break;
                 }
             }
             if (x == false)
                cout << i << endl;
         }
    int num1, num2;
         cout << "enter first number : " << endl;
         cin >> num1;
         cout << "enter second number : " << endl;
         cin >> num2;
         cout << "hello";
         cout << "hello";
         cout << "hello";
         cout << "hello";
         cout << "hello";
         cout << "hello";

cout << endl;
return 0;
}
