#include <bits/stdc++.h>
#include "../model/Player.h"
#include "../service/TicTacToeService.h"

using namespace std;

int main() {
    cout<<"Enter size of board:"<<endl;
    int sizeOfBoard;
    cin>>sizeOfBoard; //3

    int numberOfPlayers;
    cout<<"Enter Number of Players: "<<endl;
    cin>>numberOfPlayers; //2

    list<Player> players;
    cout<<"Enter the Players: "<<endl;
    for(int i=0; i<numberOfPlayers; i++){
        cout<<"Enter "<<i+1<<"th player:"<<endl;
        char piece;
        cin>>piece;
        string nameOfPlayer;
        cin>>nameOfPlayer;

        Player player(nameOfPlayer, piece);
        players.push_back(player);
    }

    TicTacToeService ticTacToeService;
    ticTacToeService.setSizeOfBoard(sizeOfBoard);
    ticTacToeService.setNumberOfPlayers(numberOfPlayers);
    ticTacToeService.setPlayers(players);

    ticTacToeService.printBoard();
    cout<<"Enter the coordinates of the board: "<<endl;
    while(ticTacToeService.gameNotOver()){
        string input1, input2;
        cin>>input1;
        if(std::equal(input1.begin(), input1.end(), "exit")){
            break;
        }
        else{
            cin>>input2;
            int i = 0;
            stringstream inputToI(input1);
            inputToI>>i;
            int j = 0;
            stringstream inputToJ(input2);
            inputToJ>>j;
            ticTacToeService.makeMove(i, j);
        }
    }
    return 0;
}
