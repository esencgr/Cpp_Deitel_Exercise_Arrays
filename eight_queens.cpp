/* Deitel array exercise - 6.26 -
(Eight Queens: Brute-Force Approaches) In this exercise, you will develop several brute-force approaches to solving the
Eight Queens problem introduced in Exercise 4.26.
 a) Solve the Eight Queens exercise, using the random brute-force technique developed in Exercise 4.25.
 b) Use an exhaustive technique, i.e., try all possible combinations of eight queens on the chessboard.
 c) Why do you suppose the exhaustive brute-force approach may not be appropriate for solving the Knight’s Tour problem?
 d) Compare and contrast the random brute-force and exhaustive brute-force approaches in general.
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

bool queen_check ( const char [][ 8 ], int ,int );
void place_queens ( char [][ 8 ] );
void print_board ( const char [][ 8 ] );
void x_conflict ( char [][ 8 ],  int, int );
void x_diagonals ( char [][ 8 ], int, int );
bool available_square ( const char [][ 8 ] );
inline int valid_move ( const char board [][ 8 ], int row, int col )
  { return ( row >= 0 && row < 8 && col >= 0 && col < 8 ); }

int main(){
   char board [ 8 ][ 8 ] = {'\0'};
   srand( time( 0 ) );

   place_queens ( board );
   print_board ( board );

   return 0;
}

bool available_square ( const char board [][ 8 ] ){
    for ( int row = 0;  row < 8;   ++row )
        for ( int col = 0;  col < 8;  ++col )
             if ( board [ row ][ col ] == '\0' )
                 return false;   // at least one open square is available

    return true; // square is not available
}
void place_queens ( char board [][ 8 ] ){
    const char QUEEN = 'Q';
    int row_move, col_move, queens = 0;
    bool done = false;

    while ( queens < 8  &&  !done ) {
        row_move = rand() % 8;
        col_move = rand() % 8;

        if ( queen_check ( board, row_move, col_move )){
           board [ row_move ] [ col_move ] = QUEEN;
           x_conflict ( board, row_move, col_move );
           ++queens;
        }
    done = available_square ( board );
    }
}
void x_conflict ( char board [][ 8 ], int row, int col ){

   for (int loop = 0;  loop < 8;  ++loop){
      // place an '*' in the row occupied by the queen
      if ( board [ row ][ loop ] == '\0' )
           board [ row ][ loop ] = '*';

      // place an '*' in the row occupied by the queen
      if ( board [ loop ][ col ] == '\0' )
           board [ loop ][ col ] = '*';
   }

   // place an '*' in the diagonals occupied by the queen
   x_diagonals ( board, row, col );
}

bool queen_check ( const char board [][ 8 ], int row , int col){
  int r = row, c = col;

  // check row and column for a queen
  for ( int d = 0;  d < 8;  ++d )
      if ( board [ row ][ d ] == 'Q'  ||  board [ d ][ col ] == 'Q' )
         return false;

  // check upper left diagonal for a queen
  for ( int e = 0;  e < 8  &&  valid_move ( board, --r, --c ); ++e )
      if ( board [ r ][ c ] == 'Q')
         return false;

  r = row;
  c = col;
  // check upper right diagonal for a queen
  for ( int f = 0;  f < 8  &&  valid_move ( board, --r, ++c ); ++f )
      if ( board [ r ][ c ] == 'Q')
         return false;

  r = row;
  c = col;
  // check lower left diagonal for a queen
  for ( int g = 0;  g < 8  &&  valid_move ( board, ++r, --c ); ++g )
      if ( board [ r ][ c ] == 'Q')
         return false;

  r = row;
  c = col;
  // check lower right diagonal for a queen
  for ( int h = 0;  h < 8  &&  valid_move ( board, ++r, ++c ); ++h )
      if ( board [ r ][ c ] == 'Q')
         return false;

  return true;   // no queen in conflict
}


void x_diagonals ( char board [][ 8 ], int row, int col ) {
  int  r = row, c = col;

  // upper left diagonal
  for ( int a = 0;  a < 8  &&  valid_move ( board, --r, --c ); ++a )
      board [ r ][ c ] = '*';

  r = row;
  c = col;
  // upper right diagonal
  for ( int b = 0;  b < 8  &&  valid_move ( board, --r, ++c ); ++b )
      board [ r ][ c ] = '*';

  r = row;
  c = col;
  // lower left diagonal
  for ( int d = 0;  d < 8  &&  valid_move ( board, ++r, --c ); ++d )
      board [ r ][ c ] = '*';

  r = row;
  c = col;
  // lower right diagonal
  for ( int e = 0;  e < 8  &&  valid_move ( board, ++r, ++c ); ++e )
      board [ r ][ c ] = '*';

}

void print_board( const char board[][ 8 ] ){
int queens = 0;

// header for columns
cout << "   0 1 2 3 4 5 6 7\n";

   for ( int r = 0; r < 8; ++r ) {
       cout << setw(2) << r << ' ';
       for ( int c = 0; c < 8; ++c ) {
            cout << board[ r ][ c ] << ' ';
            if ( board[ r ][ c ] == 'Q' )
            ++queens;
       }
   cout << '\n';
   }
   if ( queens == 8 )
      cout << "\nEight Queens were placed on the board!" << endl;
   else
     cout << '\n' << queens << " Queens were placed on the board." << endl;
}
