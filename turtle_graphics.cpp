/*
   (Turtle Graphics) The Logo language, which is particularly popular among personal computer users, made the concept of
turtle graphics famous. Imagine a mechanical turtle that walks around the room under the control of a C++ program. The turtle
holds a pen in one of two positions, up or down. While the pen is down, the turtle traces out shapes as it moves; while the
pen is up,the turtle moves about freely without writing anything. In this problem, you will simulate the operation of the turtle
and create a computerized sketchpad as well.
   Use a 20-by-20 array floor that is initialized to zeros. Read commands from an array that contains them. Keep track of the
current position of the turtle at all times and whether the pen is currently up or down. Assume that the turtle always starts at
position 0,0 of the floor with its pen up. The set of turtle commands your program must process are as follows:
                           COMMAND    MEANİNG
                             1        Pen up
                             2        Pen down
                             3        Turn right
                             4        Turn left
                             5,10     Move forward 10 spaces (or a number other than 10)
                             6        Print the 20-by-20 array
                             9        End of data (sentinel)
Suppose that the turtle is somewhere near the center of the floor. The following “program” would draw and print a 12-by-12
square and end with the pen in the up position..

*/
#include <iostream>
using namespace std;
#define SIZE 20
#define MAXCOMMANDS 100

int turn_right (int);
int turn_left (int);
void get_commands( int [][2]);
void move_pen (int, int [][SIZE], int, int );
void print_array (const int [][SIZE]);

int main (){
    int floor [SIZE][SIZE] = {0}, command, distance, direction = 0;
    int command_array [MAXCOMMANDS][2] = {0}, count = 0;
    bool pen_down = false;

    get_commands (command_array);
    command = command_array [count][0];
    while (command != 9){
        switch (command){
           case 1:
              pen_down = false;
           break;
           case 2:
              pen_down = true;
           break;
           case 3:
              direction = turn_right (direction);
           break;
           case 4:
              direction = turn_right (direction);
           break;
           case 5:
              distance = command_array[ count ][ 1 ];
              move_pen( pen_down, floor, direction, distance );
           break;
           case 6:
              cout << "\nThe drawing is:\n\n";
              print_array( floor );
              break;
        }
    command = command_array [++count][0];
    }
return 0;
}

void get_commands (int commands[MAXCOMMANDS][2]){
    int temp_commands;
    int i;
    cout << "Enter command (9 to end input): ";
    cin >> temp_commands;
        for ( i = 0; i < MAXCOMMANDS  &  temp_commands != 9; i++){
            commands [i][0] = temp_commands;
              if (temp_commands == 5){
                 cin.ignore();
                 cin >> commands [i][1];
              }
        cout << "Enter command (9 to end input): ";
        cin >> temp_commands;
        }
    commands[ i ][ 0 ] = 9; // last command
}

int turn_right (int d){
    return  ++d > 3 ? 0 : d;
}

int turn_left (int d){
    return  --d < 0 ? 3 : d;
}

void move_pen (int down, int a[][ SIZE ], int dir, int dist){
    static int x_pos = 0, y_pos = 0;
    int j;
    switch (dir){
        case 0:                                                   //move right
              for ( j = 1; j <= dist & y_pos + j < SIZE;  j++)
                  if (down)
                     a [x_pos][y_pos + j] = 1;

              y_pos += j - 1;
        break;
        case 1:                                                   //move down
              for ( j = 1; j <= dist & x_pos + j < SIZE;  j++)
                  if (down)
                     a [x_pos + j][y_pos] = 1;

              x_pos += j - 1;
        break;
        case 2:
              for ( j = 1; j <= dist & y_pos - j >= 0;  j++)    //move left
                 if (down)
                    a [x_pos][y_pos - j] = 1;

              y_pos -= j - 1;
        break;
        case 3:                                                   //move up
              for ( j = 1; j <=dist & y_pos + j >= 0;  j++)
                 if (down)
                   a [x_pos - j][y_pos] = 1;

              x_pos -= j - 1;
        break;
    }
}

void print_array (const int a[][SIZE]){
    for (int i=0; i < SIZE; i++){
        for (int j=0; j < SIZE; j++)
            cout << ( a [i][j] ? '*' : ' ' );
    cout << endl;
    }
}
