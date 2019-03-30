#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 5
using namespace std;
int main(){

  srand(time(0));
  int n [SIZE], sum = 0;
  cout << "input array : ";
       for (int i = 0; i <= SIZE - 1; i++){
           n[i] =  1 + rand () % 6;
           cout << n[i] << " ";
           sum += n[i];
       }
  cout << endl;

  int min = n[0];
      for (int i = 0; i <= SIZE - 1; i++){
          if (min > n[i])
             min = n[i];
      }

   cout << "minimum value = " << min << endl;
   cout << "sum of all = " << sum << endl;
   cout << "sum of greatest 4 value = " << sum - min << endl;
}
