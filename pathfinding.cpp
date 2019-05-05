#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define SIZE 4

bool is_prime (int);
void create_pyramid (int [][SIZE]);
int maxPathSum (int [][SIZE]);

int main (){

    int pyramid [SIZE][SIZE];
    create_pyramid (pyramid);
    cout << "\nsum of max path = " << maxPathSum (pyramid);

}
void create_pyramid (int pyramid [SIZE][SIZE]){
   srand(time(NULL));
   for (int i = 0; i < SIZE;  i++){
        for (int j = 0; j <= i;  j++){
            int num = 1 + rand() % 10;
            if (i == 0 || j == 0){
               for (;;){
                   if (!is_prime(num))
                      break;
                   else
                      num = 1 + rand() % 10;
               }
             }
             pyramid [i][j] = num;
             cout << " " << pyramid [i][j] << " " ;
        }
        cout << endl;
   }
}

bool is_prime (int number){
   int count = 0;
   if (number == 1)
      return false;
   for (int i = 2; i < number; i++)
       if (number % i == 0)
           count++;
   if (count == 0)
      return true;
   else
      return false;
}
int maxPathSum(int pyramid [SIZE][SIZE]){
            for (int i = SIZE - 2; i >= 0; i--)
            {
                for (int j = 0; j <= i; j++)
                {
                    if (i == (SIZE - 2))
                    {
                        if (is_prime(pyramid [i][j]))
                            pyramid[i][j] = 0;
                        else
                        {
                            if (!is_prime(pyramid[i + 1][j]) || !is_prime(pyramid[i + 1][j + 1]))
                            {
                                if (!is_prime(pyramid[i + 1][j]))
                                {
                                    if (!is_prime(pyramid[i + 1][j + 1]))
                                    {
                                        if (pyramid[i + 1][j] > pyramid[i + 1][j + 1])
                                            pyramid[i][j] += pyramid[i + 1][j];
                                        else
                                            pyramid[i][j] += pyramid[i + 1][j + 1];
                                    }
                                    else
                                        pyramid[i][j] += pyramid[i + 1][j];
                                }
                                else
                                    pyramid[i][j] += pyramid[i + 1][j + 1];
                            }
                            else
                                pyramid[i][j] = 0;
                        }
                    }
                    else
                    {
                        if (is_prime(pyramid[i][j]))
                            pyramid[i][j]= 0;
                        else
                        {
                            if (pyramid[i + 1][j] !=0 || pyramid[i + 1][j + 1] !=0)
                            {
                                if (pyramid[i + 1][j] != 0)
                                {
                                    if (pyramid[i + 1][j + 1] != 0)
                                    {
                                        if (pyramid[i + 1][j] > pyramid[i + 1][j + 1])
                                            pyramid[i][j] += pyramid[i + 1][j];
                                        else
                                            pyramid[i][j] += pyramid[i + 1][j + 1];
                                    }
                                    else
                                        pyramid[i][j]+= pyramid[i + 1][j];
                                }
                                else
                                    pyramid[i][j] += pyramid[i + 1][j + 1];
                            }
                            else
                                pyramid[i][j] = 0;
                        }
                    }
                }
            }
return pyramid[0][0];
}
