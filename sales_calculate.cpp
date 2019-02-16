// DEITEL ARRAY EXAMPLES -- 6.10
#include <iostream>
using namespace std;
void wages(int []);
void display (const int []);

int main (){
int salaries [11] = {0};
   wages (salaries);
   display (salaries);
return 0;
}

/*
The wages function's purpose is get all workers Commission's value
and calculate them on 9 percentage of commission.And the other process
is  classification  of this calculated value..*/

void wages (int money []){
double sales, i = 0.09, result;
int x;
  do{
    cout << "Enter employee gross sales (-1 to end): ";
    cin >> sales;

       if (sales == -1)
          break;

    result = 200 + i * sales;
    cout << "Employee Commission is $" << result << endl;

    x = result / 100;
    ++money [ x < 10 ? x : 10];

  }while (sales != -1);
}

void display( const int dollars [] )
{
cout << "Employees in the range:";
    for ( int i = 2; i < 10; ++i )
         cout << "\n$" << i << "00-$" << i << "99 : " << dollars[ i ];

cout << "\nOver $1000: " << dollars[ 10 ] << endl;
}
