#include <iostream>
#include <time.h>
#include <stdlib.h>
#define SIZE 36000
using namespace std;
int main(){

    int dice_1, dice_2, sum = 0, array [SIZE] = {0};
    int expected [13] = {0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
    srand (time (NULL));
    /*
    Two dice are throwing 36000 times in this loop. And calculates
    incoming dice values of each throw. And each of array element is increasing
    according to calculated sum value.
    */
    for (int i = 0; i < SIZE; i++){

        dice_1 = 1 + rand () % 6;
        dice_2 = 1 + rand () % 6;
        sum = dice_1 + dice_2;
        ++ array [sum];
    }

    cout  << "sum\t" << "total\t" << "expected\t" << "actual" << endl;

    /* This loop is prints each sum value and calculates expected,
    actual possibility. And shows as a chart.
    */
    for (int k = 2; k < 13; k++)
       cout << k << "\t" << array [k] << "\t"
            << "%" << 100.0 * expected [k] / 36 << "\t"
            << "%" << 100.0 * array [k] / 36000 << endl;
    return 0;
}
