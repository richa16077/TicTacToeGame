//
// Created by richa on 21/08/21.
//

#ifndef TICTACTOE_TICTACTOESERVICE_H
#define TICTACTOE_TICTACTOESERVICE_H


#include "../model/Board.h"
#include "../model/Player.h"

class TicTacToeService {
    Board board = Board(0);

    int sizeOfBoard;
    int numberOfPlayers;
    static const int defaultSizeOfBoard = 3;
    static const int defaultNumberOfPlayers = 2;

    // Make a queue of pair<player, char>
    queue<Player> players;
    int turn;
public:
    TicTacToeService(int sizeOfBoard, int numberOfPlayers){
        cout<<"Inside Parameterised Constructor"<<endl;
        this->sizeOfBoard = sizeOfBoard;
        this->numberOfPlayers = numberOfPlayers;
        this->board = Board(sizeOfBoard);
        this->turn = 1;
    }

    TicTacToeService(): TicTacToeService(defaultSizeOfBoard, defaultNumberOfPlayers) {
        cout<<"Inside Default Constructor"<<endl;
    };

    void setPlayers(list<Player> players){
        this->numberOfPlayers = players.size();
        for(Player player: players){
            cout<<"Setting Player "<<player.getName()<<"-"<<player.getPiece()<<endl;
            this->players.push(player);
        }
    }

    int getSizeOfBoard() const {
        return sizeOfBoard;
    }

    void setSizeOfBoard(int sizeOfBoard) {
        TicTacToeService::sizeOfBoard = sizeOfBoard;
    }

    int getNumberOfPlayers() const {
        return numberOfPlayers;
    }

    void setNumberOfPlayers(int numberOfPlayers) {
        TicTacToeService::numberOfPlayers = numberOfPlayers;
    }

    void makeMove(int i, int j){
        Player player = players.front();
        players.pop();
        while(!checkMove(i, j)){
            cout<<"Invalid Move"<<endl;
            cin>>i>>j;
        }
        vector<vector<char>> ticTacBoard = board.getBoard();
        if(gameNotOver()){
            if(turn == 1){
                ticTacBoard[i-1][j-1] = 'X';
                board.setBoard(ticTacBoard);
                if(checkIfWon('X')){
                    cout<<player.getName()<<" has won the game!"<<endl;
                }
                else{
                    players.push(player);
                }
                turn = 0;
            }
            else if(turn == 0){
                ticTacBoard[i-1][j-1] = 'O';
                board.setBoard(ticTacBoard);
                if(checkIfWon('O')){
                    cout<<player.getName()<<" has won the game!"<<endl;
                }
                else{
                    players.push(player);
                }
                turn = 1;
            }
            printBoard();
        }
        else{
            cout<<"Game Over"<<endl;
        }
    }

    bool checkMove(int i, int j){
        vector<vector<char>> ticTacBoard = board.getBoard();
        int sizeOfTicTac = board.getSizeOfBoard();
        if(i>=1 and i<=sizeOfTicTac and j>=1 and j<=sizeOfTicTac and ticTacBoard[i-1][j-1] == '-'){
            return true;
        }
        return false;
    }

    bool checkIfWon(char piece){
        vector<vector<char>> ticTacBoard = board.getBoard();
        if(checkHorizontal(ticTacBoard, piece) or checkVertical(ticTacBoard, piece) or checkDiagonal(ticTacBoard, piece)){
            return true;
        }
        return false;
    }

    bool checkHorizontal(vector<vector<char>> ticTacBoard, char piece){
        bool horizontalFlag = false;

        // Obtain the vector and maintain flag to check for piece values
        for(int i=0; i<sizeOfBoard; i++){
            if(ticTacBoard[i][0] == piece and ticTacBoard[i][1] == piece and ticTacBoard[i][2] == piece){
                horizontalFlag = true;
                break;
            }
        }
        return horizontalFlag;
    }

    bool checkVertical(vector<vector<char>> ticTacBoard, char piece){
        bool verticalFlag = false;

        for(int i=0; i<sizeOfBoard; i++){
            if(ticTacBoard[0][i] == piece and ticTacBoard[1][i] == piece and ticTacBoard[2][i] == piece){
                verticalFlag = true;
                break;
            }
        }
        return verticalFlag;
    }

    bool checkDiagonal(vector<vector<char>> ticTacBoard, char piece){
        bool diagonalFlag = false;

        if(ticTacBoard[0][0] == piece and ticTacBoard[1][1] == piece and ticTacBoard[2][2] == piece){
            diagonalFlag = true;
        }
        else if(ticTacBoard[0][2] == piece and ticTacBoard[1][1] == piece and ticTacBoard[2][0] == piece){
            diagonalFlag = true;
        }

        return diagonalFlag;
    }

    bool gameNotOver(){
        vector<vector<char>> ticTacBoard = board.getBoard();
        int sizeOfTicTac = board.getSizeOfBoard();
        bool emptySpace = false;
        for(int i=0; i<sizeOfTicTac; i++){
            for(int j=0; j<sizeOfTicTac; j++){
                if(ticTacBoard[i][j] == '-'){
                    emptySpace = true;
                    break;
                }
            }
        }
        return emptySpace;
    }

    void printBoard(){
        vector<vector<char>> ticTacBoard = board.getBoard();
        int sizeOfTicTac = board.getSizeOfBoard();
        for(int i=0; i<sizeOfTicTac; i++){
            for(int j=0; j<sizeOfTicTac; j++){
                cout<<ticTacBoard[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};


#endif //TICTACTOE_TICTACTOESERVICE_H
