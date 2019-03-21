// Deitel array exercise - 6.20 -
#include <iostream>
#include <cctype>
#define SEATS 11
using namespace std;
/*
 This is a plane company's reservation system.The economy class seat numbers are
 1-5 and  the first class seat numbers are 6-10. If the passenger assignment is
 1, the seat is in the first class section passenger assignment is 2, the seat
 is in the economy section.

 This program should prints boarding pass indicating the person’s seat number
 and whether it is in the first class or economy section of the plane.

 This program should,of course,never assign a seat that has already been assigned.

 When the first class section is full, this program asks the person if it is
 acceptable to be placed in the economy section (and vice versa).
 If yes, then it does  the appropriate seat assignment.
 If no, then prints the message "Next flight leaves in 3 hours."..
*/
int main(){

    int plane [ SEATS ] = {0}, people, economy = 1, firstclass = 6, choise;
    char response;

    while ( people < 10 ){
         cout << "Please select type 1 for / firstclass / \n"
              << "Please select type 2 for / economy /\n";
         cin >> choise;
             if ( choise == 1 ){
                if ( !plane [firstclass] && firstclass <= 10 ){
                   cout << "Your assignment is firstclass --> "
                        <<  firstclass << endl << endl;
                   plane [ firstclass++ ] = 1;
                   people++;
                }
                else if ( firstclass > 10 && economy <= 5 ){
                   cout << "Firstclass section is full. \n "
                        << "Would you like economy section Y or N ? \n ";
                   cin >> response;
                       if ( toupper (response) == 'Y'){
                          cout << "Your assignment is economy --> "
                               <<  economy  << endl << endl;
                          plane [ economy++ ] = 1;
                          people++;
                       }
                       else
                          cout << "Next plane is 3 hours later ..\n" << endl;
                }
                else
                   cout << "Next plane is 3 hours later ..\n" << endl;
             }
             else {
                if ( !plane [economy] && economy <= 5 ){
                   cout << "Your assignment is economy --> "
                        << economy << endl << endl;
                   plane [ economy++ ] = 1;
                   people++;
                }
                else if ( economy > 5 && firstclass <= 10 ){
                   cout << "Economy section is full. \n "
                        << "Would you like firstclass section Y or N ? \n ";
                   cin >> response;
                       if ( toupper (response) == 'Y'){
                          cout << "Your assignment is firstclass --> "
                               << firstclass << endl << endl ;
                          plane [ firstclass++ ] = 1;
                          people++;
                       }
                       else
                          cout << "Next plane is 3 hours later ..\n" << endl;
                }
                else
                   cout << "Next plane is 3 hours later ..\n" << endl;
             }
    }
    cout << "\n All seats for this flight are sold. " << endl;
    return 0;
}
