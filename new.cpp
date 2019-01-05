#include<iostream>
using namespace std;
int main (){
  for (int i=0; i<10; i++)
      cout << i;
  for (int l=0; l<110; l++ ){
      if (l % 5 == 0)
        cout << "hey";
      else
        cout << "yo";
  }

  cout << "the process is finish.."<< endl ;
  cout << "değer gir (1 c)" << endl;

  int num ;
  cin >> num;

      if (num == 1){
         for (int k=0; k<=10; k++)
             cout << k;
      }

return 0;
}
