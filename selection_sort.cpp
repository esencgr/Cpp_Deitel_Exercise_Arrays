#include <iostream>
using namespace std;
int main (){

    int array [10] = {4, 2, 1, 5, 7, 9, 1, 5, 9, 7}, temp;

    for (int tour = 1; tour <= 9;  tour++){
       for (int j = 0; j <= 8;  j++){
         if ( array [j] > array [j+1] ){
            temp = array [j];
            array [j] = array [j+1];
            array [j+1] = temp;
         }
       }
     }

      cout << "sorted array : " << endl ;
      for (int i = 0; i < 10;  i++)
          cout << array [i] << " ";

cout << endl;
return 0;
}
