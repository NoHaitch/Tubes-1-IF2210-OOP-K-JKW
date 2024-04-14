#include "header/game.hpp"
#include "header/printColor.hpp"
#include "header/utils.hpp"
#include <iostream>
#include <string>

using namespace std;
    
int main(){
    // Print title
    printTitle();

    // Starting a Game
    Game game;

    // Reading Configuration
    if(game.readConfig() == 1){
        cerr << "Config Reading Failed" << endl;
        return 0;
    }
    resetTextColor();

    // Load or Initilize New Game State
    game.getGameStateIO();

    // Player Turns
    while(true){
        game.nextTurnIO();

        // Player Commands
        int command = 0;
        while(true){
            // Do Player Commands
            command = game.playerCommandIO();
            if(command == 1 || command == 2) {
                break;
            }

            // Win Condition
            if(game.checkWinningCondition()){            
                game.printWinner();
                break;
            }
        }
        
        // Exit Game
        if(command == 1 || game.checkWinningCondition()){
            break;
        }
    }

    return 0;
}