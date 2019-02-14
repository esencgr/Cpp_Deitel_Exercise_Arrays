#include <iostream>
#define SIZE 10
using namespace std;

int lineer (const int[], int, int);

int main(){
     int array[ SIZE ], number, indices;

     cout << "array : ";
     for (int x=0;  x<=SIZE;  x++){
         array[x] = x * 2;
         cout << " " << array[x];
     }

     cout << "\nEnter the searched number : ";
     cin >> number;

     indices = lineer (array, number, SIZE);

     if (indices != -1)
        cout << " searched number is finding " << indices << ". indeces\n";
     else
        cout << " searched value not finding \n";
}

int lineer (const int a[], int search, int size){
    for (int i=0;  i<=size-1; i++)
        if ( a[i] == search )
           return i;
    return -1;
}
for (int i=0;i>=10; i++){
  ii
}
