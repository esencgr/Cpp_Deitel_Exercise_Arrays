//// Exercise 6.25 Part B Solution
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
#define TOURS 1000
#define MAX_MOVES 65
using namespace std;

void clear_board ( int [][ SIZE ] );
bool valid_move ( int, int, int, const int [][ SIZE ] );

int main(){
   int board [ SIZE ][ SIZE ], current_row, current_col, move_number;
   int test_row, test_col, move_type, move_total [ MAX_MOVES ] = {0}, good_move;

   int horizontal [ SIZE ] = { 2, 1, -1, -2, -2, -1, 1, 2 };
   int vertical [ SIZE ] = { -1, -2, -2, -1, 1, 2, 2, 1 };

   bool done;
   srand ( time (NULL) );
   int sum = 0;
   for (int i = 0;  i < TOURS;  i++) {
      clear_board ( board );
      move_number = 0;
      current_row = rand() % SIZE;
      current_col = rand() % SIZE;
      board [ current_row ][ current_col ] = ++move_number;
      done = false;

      while ( !done ){
          move_type = rand() % SIZE;
          test_row = current_row + vertical [ move_type ];
          test_col = current_col + horizontal [ move_type ];
          good_move = valid_move ( test_row, test_col, move_type, board );

             if (good_move){
                current_row = test_row;
                current_col = test_col;
                board[ current_row ][ current_col ] = ++move_number;
             }
             else{
               for (int count = 0;  count < SIZE - 1  &&  !good_move;  ++count) {
                   move_type = ++move_type % SIZE;
                   test_row = current_row + vertical[ move_type ];
                   test_col = current_col + horizontal[ move_type ];
                   good_move = valid_move ( test_row, test_col, move_type, board );

                      if (good_move){
                          current_row = test_row;
                          current_col = test_col;
                          board[ current_row ][ current_col ] = ++move_number;
                       }
               }
               if ( !good_move )
                   done = true;
             }
       if ( move_number == 64 )
          done = true;
      }
    ++move_total[ move_number ];
    }

    for (int j = 0; j < MAX_MOVES; j++)
        if (move_total [j])
            cout << "There were " << move_total[ j ] << " tours of " << j << " moves." << endl;
return 0;
}

void clear_board ( int work_board [][ SIZE ] ) {
    for ( int row = 0; row < SIZE;  row++ ) {
        for ( int col = 0; col < SIZE;  col++ ) {
             work_board[ row ][ col ] = 0;
        }
    }
}

bool valid_move ( int row, int col, int move_type, const int work_board [][ SIZE ] ) {
     if ( row >= 0  &&  row < SIZE  &&  col >= 0  &&  col < SIZE )
         return work_board[ row ][ col ] != 0 ? false : true;
     else
         return false;
}
