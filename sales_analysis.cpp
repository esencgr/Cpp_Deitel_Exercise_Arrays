/*                   Deitel array exercise - 6.22 -
   Use a double-subscripted array to solve the following problem. A company has
four salespeople (1 to 4) who sell five different products (1 to 5). Once a
day, each salesperson passes in a slip for each different type of product
sold. Each slip contains the following:
         1) The salesperson number
         2) The product number
         3) The total dollar value of that product sold that day
   Thus, each salesperson passes in between 0 and 5 sales slips per day. Assume
that the information from all of the slips for last month is available. Write a
program that will read all this information for last month’s sales and summarize
the total sales by salesperson by product.
   All totals should be stored in the double-subscripted array sales. After
processing all the information for last month,print the results in tabular
format with each of the columns representing a particular salesperson and each
of the rows representing a particular product.
   Cross total each row to get the total sales of each product for last month;
cross total each column to get the total sales by salesperson for last month.
Your tabular printout should include these cross totals to the right of the
totaled rows and to the bottom of the totaled columns.
*/
#include <iostream>
using namespace std;
int main(){
    const int PERSON = 5, PRODUCT = 6;
    double sales[ PERSON ][ PRODUCT ] = { 0.0 }, value, total_sales, product_sales[ PRODUCT ] = { 0.0 };
    int sales_person, product;
    cout << "Enter the salesperson (1 - 4), product number (1 - 5), "
         << "and total sales.\n Enter -1 for the salesperson to end input.\n";
    cin >> sales_person;

    while (sales_person != -1){
          cin >> product >> value;
          sales [ sales_person ][ product ] += value;
          cin >> sales_person;
    }

    cout <<"\t" << "1" << "\t" << "2" << "\t" << "3";
    cout <<"\t" << "4" << "\t" << "5" << "\t" << "total\n";

    for (int i = 1; i < PERSON; i++) {
        total_sales = 0.0;
        cout << i;
             for ( int j = 1; j < PRODUCT; j++){
                 total_sales += sales [i][j];
                 cout << "\t" << sales [i][j];
                 product_sales [j] += sales [i][j];
             }
        cout << "\t" << total_sales << endl;
    }

    cout << "\nTotal" ;
    for (int k = 1; k < PRODUCT; k++)
        cout <<  "\t" << product_sales[k];

    cout << endl;

 return 0;
}
