// DEITEL ARRAY EXAMPLES -- 6.11-a
#include <iostream>
#define SIZE 10
using namespace std;
int main (){
  int array [SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

  cout << "original array : ";
      for (int i=0; i < SIZE; i++)
          cout << array [i] << " ";
  cout << endl << endl;

  int temp, comp, number_of_comp ;
    for (int pass = 1; pass < SIZE; pass++ ){
       cout << " after pass " << pass-1 << " : ";
         for (comp = 0; comp < SIZE-pass; comp++){
             ++number_of_comp;
             if (array [comp] > array [comp+1]){
               temp = array [comp];
               array [comp] = array [comp+1];
               array [comp+1] = temp;
             }
          cout << array [comp] << " ";
          }
    cout << array [comp] << " "  << endl;
    }

  cout << "in ascending order array : ";
    for (int j=0; j < SIZE; j++)
       cout << array [j] << " " << endl;
  cout << "\nNumber of comparisons = " << number_of_comp << endl;
}
