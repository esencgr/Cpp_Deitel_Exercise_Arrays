#include <iostream>
#define SIZE 15
using namespace std;

int binary(const int[], int, int, int);
void head_printing(void);
void line_print(const int[], int, int, int);

int main (){
   int a[SIZE], search_value, result;

   for (int i=0; i <= SIZE-1; i++)
       a[i] = i * 2;

   cout << "enter a number between 0-28 : ";
   cin >> search_value;

   head_printing();
   result = binary(a, search_value, 0, SIZE-1);

   if (result == -1)
     cout << "the searched value is not find " << endl;
   else
     cout << "searched value " << search_value << " is finding in " << result << '\n';

return 0;
}

void head_printing (void){

  cout << "indeces" << endl;

  for (int i=0; i<=SIZE-1; i++)
      cout << " " << i;
  cout << endl;

  for (int j=0; j<SIZE*4; j++)
      cout << "-";
  cout << endl;
}

int binary (const int b[], int value, int down, int up){

    int medium;

    while (down <= up){
      medium = (up + down) / 2;

      line_print (b, down, medium, up);

      if (value == b[medium])
         return medium;
      else if (value < b[medium])
         up = medium - 1;
      else
         down = medium + 1;
    }

  return -1;
}
void line_print (const int b[], int down, int medium, int up){

   for (int i=0; i<=SIZE-1; i++){
       if (i < down || i > up)
          cout << " ";
       else if (i == medium)
          cout << " *" << b[i];
       else
          cout << " "<< b[i];
   }
   cout << endl;
}
