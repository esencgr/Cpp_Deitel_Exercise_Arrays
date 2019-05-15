//// deitel array exercise - 6.24 -
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#define SIZE 8
using namespace std;

void clear_board ( int [][ SIZE ] );
void print_board ( const int [][ SIZE ] );
bool valid_move ( int, int, const int [][ SIZE ] );

int main(){
   int board [ SIZE ][ SIZE ], current_row, current_col, access_number;
   int min_access = 9, move_number = 0, test_row, test_col, min_row, min_col;
   int horizontal[ SIZE ] = { 2, 1, -1, -2, -2, -1, 1, 2 };
   int vertical[ SIZE ] = { -1, -2, -2, -1, 1, 2, 2, 1 };
   int access[ SIZE ][ SIZE ] = { 2, 3, 4, 4, 4, 4, 3, 2,
                                  3, 4, 6, 6, 6, 6, 4, 3,
                                  4, 6, 8, 8, 8, 8, 6, 4,
                                  4, 6, 8, 8, 8, 8, 6, 4,
                                  4, 6, 8, 8, 8, 8, 6, 4,
                                  4, 6, 8, 8, 8, 8, 6, 4,
                                  3, 4, 6, 6, 6, 6, 4, 3,
                                  2, 3, 4, 4, 4, 4, 3, 2 };
   bool done;
   srand ( time (NULL) );
   clear_board ( board );
   current_row = rand() % 8;
   current_col = rand() % 8;
   board[ current_row ][ current_col ] = ++move_number;
   done = false;

   while ( !done ){
     access_number = min_access;

     for (int move_type = 0;  move_type < SIZE;  move_type++ ){
         test_row = current_row + vertical[ move_type ];
         test_col = current_col + horizontal[ move_type ];

         if ( valid_move( test_row, test_col, board) ){
            if ( access[ test_row ][ test_col ] < access_number ){
               access_number = access[ test_row ][ test_col ];
               min_row = test_row;
               min_col = test_col;
            }
           --access [ test_row ][ test_col];
         }
     }

     if ( access_number == min_access )
        done = true;
     else {
         current_row = min_row;
         current_col = min_col;
         board[ current_row ][ current_col ] = ++move_number;
     }
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

void clear_board ( int work_board [][ SIZE ] ) {
    for ( int row = 0; row < SIZE;  row++ ) {
        for ( int col = 0; col < SIZE;  col++ ) {
             work_board [ row ][ col ] = 0;
        }
    }
}

void print_board ( const int work_board [][ SIZE ] ) {
    cout << "\t" << "0\t" << "1\t" << "2\t" << "3\t" << "4\t" << "5\t" << "6\t" << "7\n\n";
    for ( int row = 0; row < SIZE;  row++ ) {
        cout << row;
        for ( int col = 0; col < SIZE;  col++ )
             cout << "\t" << work_board [ row ][ col ];
    cout << endl;
    }
 cout << endl;
}

bool valid_move ( int row, int col, const int work_board[][ SIZE ] ) {
    return ( row >= 0  &&  row < SIZE  &&  col >= 0  &&  col < SIZE  &&  work_board [ row ][ col ] == 0 );
}
