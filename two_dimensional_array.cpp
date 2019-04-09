/* ıt is a basic example */
#include <iostream>
using namespace std;
void print_array (const int [][3]);

int main (){
  int array_1 [2][3] = {{1,7,9},{4,3}};
  int array_2 [2][3] = {1,2,3,4};
  int array_3 [2][3] = {{1,2},{2}};

  cout << "array_1 " << endl;
  print_array (array_1);
  cout << "array_2 " << endl;
  print_array (array_2);
  cout << "array_3 " << endl;
  print_array (array_3);

return 0;
}
void print_array(const int a[][3]){
  for (int i=0; i<2; i++){
      for (int j=0; j<3; j++)
          cout << a[i][j];
  cout << endl;
  }
}
