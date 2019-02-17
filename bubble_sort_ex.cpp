// DEITEL ARRAY EXAMPLES -- 6.11-b
#include <iostream>
#define SIZE 10
using namespace std;
int main (){
int array [SIZE] = {6, 4, 2, 8, 10, 12, 37, 45, 68, 89};

  cout << "original array : ";
      for (int i=0; i < SIZE; i++)
          cout << array [i] << " ";
  cout << endl << endl;

int temp, comp, number_of_comp = 0;
bool swap_check = true;
    for (int pass = 1; pass < SIZE-1 && swap_check == true; pass++ ){
       cout << "after pass " << pass-1 << " : ";
       swap_check = false;
          for (comp = 0; comp < SIZE-pass; comp++){
               ++number_of_comp;
               if (array [comp] > array [comp+1]){
                   temp = array [comp];
                   array [comp] = array [comp+1];
                   array [comp+1] = temp;
                   swap_check = true;
               }
          cout << array [comp] << " ";
          }
    cout << array [comp] << " "  << endl;
    }

  cout << "\nin ascending order array : ";
    for (int j=0; j < SIZE; j++)
       cout << array [j] << " ";
  cout << "\nNumber of comparisons = " << number_of_comp << endl;
}
