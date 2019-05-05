// deitel array exercise - 6.20 -
#include <iostream>
#include <time.h>
#include <stdlib.h>
#define ROLLS 1000
#define SIZE 22
using namespace std;
int dice_throw (void);
int main(){
    enum Outcome { CONTINUE, WIN, LOSE };
    int game_state, sum, game_score, roll, length = 0, wins[ SIZE ] = { 0 },
        losses[ SIZE ] = { 0 }, winSum = 0, loseSum = 0;
    srand (time (0));
/*
This game is playing 1000 times and each play result is calculating in wins[],
and loses[] arrays. Printing number of win and lose game. And calculating
chances of winning in the other for loop. calculating average length of game
in the end for code..
*/
  for (int i = 1; i <= ROLLS; i++){
      sum = dice_throw();
      roll = 1;
      switch (sum){
           case 7: case 11:
             game_state = WIN;
           break;
           case 2: case 3: case 12:
             game_state = LOSE;
           break;
           default:
             game_state = CONTINUE;
             game_score = sum;
           break;
       }

       while (game_state == CONTINUE){
           sum = dice_throw();
           roll++;
           if (sum == game_score)
               game_state = WIN;
           else if(sum == 7)
               game_state = LOSE;
       }

       if (roll > 21)
       roll = 21;

       if (game_state == WIN){
          ++wins[roll];
          ++winSum;
       }
       else{
          ++losses[roll];
          ++loseSum;
       }
  }

  cout << "Games won or lost after the 20th roll"
       << "\nare displayed as the 21st roll.\n\n";

  // number of win and lose game.
  for (int z = 1; z <= 21; z++)
      cout << wins [z] << "games won and " << losses [z] << "games lost "
           << "on roll " << z << endl;

  //calculate chances of winning
  cout     << "\nThe chances of winning are " << winSum << " / "
       << winSum + loseSum << " = %" << 100.0 * winSum / ( winSum + loseSum )
       << endl;

  // calculate average length of game
  for ( int k = 1; k <= 21; ++k )
      length += wins[ k ] * k + losses[ k ] * k;
      cout << "The average game length is " << length / 1000.0 << " rolls."
           << endl;

return 0;
}

int dice_throw (void){
  int dice1, dice2,total;

  dice1 = 1 + rand() % 6;
  dice2 = 1 + rand() % 6;
  total = dice1 + dice2;
  return total;
}
