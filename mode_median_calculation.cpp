// deitel array exercise - 6.14 -
#include <iostream>
using namespace std;
void mean (int [], int);
void median (int [], int);
void mode (int[],int [], int, int);
int main() {
  const int SIZE = 100, MAXFREQ = 10;
  int frequency [MAXFREQ] = {0};
  int answer [SIZE] = {6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
                       7, 8, 9, 5, 9, 8, 7, 8, 7, 1,
                       6, 7, 8, 9, 3, 9, 8, 7, 1, 7,
                       7, 8, 9, 8, 9, 8, 9, 7, 1, 9,
                       6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
                       7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
                       5, 6, 7, 2, 5, 3, 9, 4, 6 ,4,
                       7, 8, 9, 6, 8, 7, 8, 9, 7, 1,
                       7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
                       4, 5, 6, 1, 6, 5, 7, 8, 7, 9 };

  cout << "\n--- MEAN ---" << endl;
  mean (answer, SIZE);
  cout << "\n--- MEDIAN ---" << endl;
  median (answer, SIZE);
  cout << "\n--- MODE ---" << endl;
  mode (frequency, answer, SIZE, MAXFREQ);
  return 0;
}


/*
mean function calculates sum of each array element and divides total
number of elements, and this value is give mean value (avarage).
*/
void mean (int answer [], int SIZE){
   double total = 0;
       for (int i = 0; i < SIZE; i++)
           total += answer [i];
   cout << "Mean value = " << total << "/" << SIZE << " = " << total / SIZE ;
   cout << endl << endl;
 }


/*
median function organizes the array in increasing form. And finds this array's
hydrangea element.This element is median value. Also this function works when
the array has even or odd element.
*/
void median (int answer [], int SIZE){
   int count = 0;
   cout << "The unsorted array of responses is " << endl;
        for (int i = 0 ; i < SIZE; i++){
            count++;
            cout << answer [i] << " ";
            if (count % 20 == 0)
               cout << endl;
        }
   cout << "\n\n";

   int temp, count1 = 0;
   cout << "The unsorted array of responses is " << endl;
        for (int pass = 0; pass <= SIZE-2; pass++){
            for (int k = 0; k <= SIZE-2; k++){
                if (answer [k] > answer [k+1]){
                   temp = answer [k+1];
                   answer [k+1] = answer [k];
                   answer [k] = temp;
                }
            }
         }
         for (int p = 0 ; p < SIZE; p++){
             count1++;
             cout << answer [p] << " ";
             if (count1 % 20 == 0)
                cout << endl;
         }
    cout << "\n\n";

         if (SIZE % 2 == 0)            // even number of elements
            cout << "The median is the average of elements " << (SIZE + 1) / 2
                 << " and " << 1 + ( SIZE + 1 ) / 2 << " of the sorted "
                 << SIZE << " element array." << "For this run the median is : "
                 << double((answer [(SIZE + 1)/2]) + (answer [1 + (SIZE + 1)/2])) / 2
                 << endl;

         else                           // odd number of elements
            cout << "The median is element " << (SIZE + 1) / 2 << "of "
                 << "the sorted " << SIZE << " element array.\n "
                 << "For this run the median is " << answer[(SIZE + 1) / 2 - 1 ]
                 << endl << endl;
}

/*the mode function calculates frequency of each array element. And shows
this values as a star graphic. Than calculates mode value of this array,
this value is the most repetitive value.
*/
void mode (int frequency [], int answer [], int SIZE , int MAXFREQ){
   const int SIZE2 = 10;
   int largest = 0, count = 0, array [ SIZE2 ] = {0};

   for (int rating = 1; rating < MAXFREQ; rating++)
       frequency [rating] = 0;

   for (int value = 0; value < SIZE; value++)
       ++frequency [answer [value]];

   cout << "answer\t" << "frequency\t" << "graphic" << endl;

   for (int i = 1; i < MAXFREQ; i++ ){
       cout << i << "\t" << frequency [i] << "\t";

       if (frequency[i] > largest){
          largest = frequency [i];

          for (int v = 0; v < SIZE2; v++)
              array [v] = 0;

          array [i] = largest;
          count++;
       }

       else if (frequency [i] == largest){
          array [i] = largest;
          count++;
       }

       for (int grap = 0; grap < frequency [i];  grap++)
           cout << "* ";
       cout << endl;
   }

  cout << ( count > 1 ? "\nThe modes are: " : "\nThe mode is: " );
       for ( int m = 1; m < SIZE2; ++m )
           if ( array[ m ] != 0 )
               cout << "\n" << m << " with a frequency of " << array[ m ] ;
               cout << endl;
}
