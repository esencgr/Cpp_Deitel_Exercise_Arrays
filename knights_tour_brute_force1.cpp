//// Exercise 6.25 Part A Solution
/*
Knight’s Tour: Brute-Force Approaches) In Exercise 4.24, we developed a solution to the Knight’s Tour problem. The
approach used, called the “accessibility heuristic,” generates many solutions and executes efficiently.
As computers continue increasing in power, we will be able to solve more problems with sheer computer power and
relatively unsophisticated algorithms. Let us call this approach “brute force” problem solving.
     a) Use random-number generation to enable the knight to walk around the chessboard (in its legitimate L-shaped
        moves,of course) at random. Your program should run one tour and print the final chessboard. How far did the
        knight get?
     b) Most likely, the preceding program produced a relatively short tour. Now modify your program to attempt 1000
        tours.Use a single-subscripted array to keep track of the number of tours of each length. When your program
        finishes
*/
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#define SIZE 8
using namespace std;

void print_board ( const int [][ SIZE ] );
bool valid_move ( int, int, const int [][ SIZE ] );

int main(){
   int board [ SIZE ][ SIZE ] = {0}, current_row, current_col, move_number = 0;
   int test_row, test_col, move_type;

   int horizontal[ SIZE ] = { 2, 1, -1, -2, -2, -1, 1, 2 };
   int vertical[ SIZE ] = { -1, -2, -2, -1, 1, 2, 2, 1 };

   bool done, good_move;
   srand ( time (NULL) );
   current_row = rand() % SIZE;
   current_col = rand() % SIZE;
   board[ current_row ][ current_col ] = ++move_number;
   done = false;

   while ( !done ){
       move_type = rand() % SIZE;
       test_row = current_row + vertical [ move_type ];
       test_col = current_col + horizontal [ move_type ];
       good_move = valid_move ( test_row, test_col, board );

          if (good_move){
             current_row = test_row;
             current_col = test_col;
             board [ current_row ][ current_col ] = ++move_number;
          }
          else{
            for (int count = 0;  count < SIZE - 1  &&  !good_move;  ++count) {
                move_type = ++move_type % SIZE;
                test_row = current_row + vertical [ move_type ];
                test_col = current_col + horizontal [ move_type ];
                good_move = valid_move ( test_row, test_col, board );

                   if (good_move){
                       current_row = test_row;
                       current_col = test_col;
                       board [ current_row ][ current_col ] = ++move_number;
                    }
            }
            if ( !good_move )
                done = true;
          }
    if ( move_number == 64 )
       done = true;
   }

   cout << "The tour ended with " << move_number << " moves.\n";

   if ( move_number == 64 )
      cout << "This was a full tour!\n\n";
   else
      cout << "This was not a full tour.\n\n";

   cout << "The board for this test is:\n\n";
   print_board( board );
   return 0;
}

void print_board ( const int work_board [][ SIZE ] ) {
    cout << "\t" << "0\t" << "1\t" << "2\t" << "3\t" << "4\t" << "5\t" << "6\t" << "7\n\n";
    for ( int row = 0; row < SIZE;  row++ ) {
        cout << row;
        for ( int col = 0; col < SIZE;  col++ )
             cout << "\t" << work_board [ row ][ col ];
    cout << endl << endl;
    }
 cout << endl;
}

bool valid_move ( int row, int col, const int work_board[][ SIZE ] ) {
    return ( row >= 0  &&  row < SIZE  &&  col >= 0  &&  col < SIZE  &&  work_board [ row ][ col ] == 0 );
}
