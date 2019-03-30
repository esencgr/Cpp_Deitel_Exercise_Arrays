#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
int main(){
    srand(time(NULL));

    int size;
    cout << "enter the size of array = ";
    cin >> size;

    cout << "array = ";
    int a[size];
        for (int i=0; i<=size-1; i++){
            a[i] = 1 + rand() % 5;
            cout << a[i] << " ";
        }
    cout << endl;

    double sum=0, product=1;
        for (int i=0; i<=size-1; i++){
             sum += a[i];
             product *= a[i];
        }

    cout << "sum of array's elements = " << sum << endl;
    cout << "average of array's elements = " << double(sum / size)<< endl;
    cout << "geometric average of array's elements = " << pow(product,(double)1/size) << endl;

return 0;
}
