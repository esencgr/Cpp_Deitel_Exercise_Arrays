// CS-TECH APPLICANT ASSESMENT TEST 1
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int rand_number( void );
bool is_valid( int );
void compare( int, int );
int correct_value ( int, int );

int main(){

    srand(time ( 0 ));

    cout << "---------------------GENERATING INITIAL VALUES ---------------------- \n";

    int user1, software1, user2, software2;
    cout << "\n--> Computer is generating a number for user..\n";
    do{
        software1 = rand_number();
    } while (!is_valid ( software1 ));

    cout << "\n\n--> User is generating a number for computer.. \n";
    do{
        cout << " User's generated number : ";
        cin >> user2;
    } while (!is_valid ( user2 ));

    cout << "\n\n ------------------- NEW VALUES & INFO --------------------- ";

    int correct1 = 0, correct2 = 0;
    while ( 1 ){

        cout << "\n\n--> User is guessing computers number..\n";
        do{
           cout << " User's valid number : ";
           cin >> user1;
        } while (!is_valid ( user1));

        cout << " Users information code : ";
        compare( software1, user1 );

        if ( software1 == user1){
           cout << "\n\n ------ THE NUMBER IS => " << user1 << " ------> " << " USER WIN THE GAME!"<< endl;
           break;
        }

        cout << "\n\n--> Computer is guessing users number..\n";
        do{
            software2 = rand_number();
            cout << " Computer valid number : " << software2 << endl;
        } while (!is_valid ( software2 ));

        cout << " Computers information code :";
        compare( software2, user2 );

        if ( software2 == user2 ){
           cout << "\n\n ------ THE NUMBER IS => " << software2 << " ------> " << " COMPUTER WIN THE GAME!"<< endl;
           break;
        }
    }

    return 0;
}

/*
Function that generates random numbers between 1000 and 9999
*/
int rand_number(void){
   return rand() % 900 + 100;
}

/*
This test function is the check whether the number sent to it is a conditional
number that does not repeat steps. If it is valid returned 1 value, 0  if not .
*/
bool is_valid(int number){
   int temp, i, j;
   for (i = 0; i < 10; i++) {
      j = 0;
      temp = number;
      while (temp > 0) {
         if (temp % 10 == i)
            j++;
         if (j > 1)
            return 0;
         temp /= 10;
      }
   }
   return 1;
}

/*
This test function is the compare the users and computers number, and if they
include same digit, the function assignments array's element 1 value, 0 if not.
*/
void compare ( int num1, int num2 ){
    int count [ 3 ] = { 0 }, sum = 0;
    for (int i = 2;  i >= 0;  i--) {
        int x = pow ( 10, i );
        int temp1 = num1 / x;
        int temp2 = num2 / x;
            if ( temp1 == temp2 )
               count[i] = 1;
        num1 %= x;
        num2 %= x;
        cout << count [i];
    }
}
/*
This function is checking the two integers and if includes same digits ( it's mean
element value is 1 ) sum vaariable is increase by 1.
*/
// int correct_value ( int num1, int num2 ){
//     int count [ 3 ] = { 0 }, sum = 0;
//     for (int i = 2;  i >= 0;  i--) {
//         int x = pow ( 10, i );
//         int temp1 = num1 / x;
//         int temp2 = num2 / x;
//             if ( temp1 == temp2 )
//                count[ i ] = 1;
//         num1 %= x;
//         num2 %= x;
//         sum += count[ i ];
//     }
//     return sum;
// }
// correct2 = correct_value( software2, user2 );
// cout << "\n Corectivity : " << correct2;
// correct1 = correct_value( software1, user1 );
// cout << "\n Corectivity : " << correct1;
