// Deitel array exercise - 6.28 -
/*
  This program is firstly create 10 number between 1-20 with rand function.
  And than if this generated numbers is not copy each other's, this number
  is stored in an array and print this array. In this way,repeated numbers 
  are eliminated.
*/
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
int main (){
    srand( time ( NULL ));
    int value [10];

    cout << "ori values = ";
    for (int i = 0;  i < 10;  i++) {
        value [i] = 1 + rand() % 20;
        cout << value [i] << " ";
    }

    cout << "\nnew values = ";
    for (int i = 0;  i < 10;  i++) {
        for (int j = 0 ;  j < i ;  j++) {
            if ( value [i] == value [j] )
               value [i] = 0;
        }
        if (value[i])
           cout << value [i] << " ";
    }

return 0;
}
