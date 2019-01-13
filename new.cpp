#include <iostream>
#define BOYUT 12
using namespace std;

int main (){
  int a[BOYUT] = {1,2,4,5,5,3,1,8,9,8,1,2};

  int toplam = 0;

  for (int i=0; i<BOYUT; i++)
      toplam += a[i];

  cout << "elamanlar toplami = " << toplam << endl;
  cout << "hello dunya" << endl;

  for (int i=0; i < BOYUT; i++)
      cout << a[i] << " ";

  cout << endl;

  return 0;
}
