#include <iostream>
using namespace std;
#define SIZE 10
int main (){
  int a[ SIZE ][ SIZE ];
    for (int i=0; i<10; i++){
      for (int j=0; j<10; j++)
          a[i][j] = i + j;
    }
    for (int i=0; i<10; i++){
      for (int j=0; j<=10; j++)
          cout << a[i][j] << " ";
    cout << endl;
    }
}
