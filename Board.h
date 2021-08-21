//
// Created by richa on 21/08/21.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H
#include<bits/stdc++.h>
#include "string"
using namespace std;

class Board {
    int sizeOfBoard;
    vector<vector<char>> board;
public:
    Board(int sizeOfBoard) : sizeOfBoard(sizeOfBoard) {
        for(int i=0; i<sizeOfBoard; i++){
            vector<char> row;
            for(int j=0; j<sizeOfBoard; j++){
                row.push_back('-');
            }
            board.push_back(row);
        }
    }

    int getSizeOfBoard() const {
        return sizeOfBoard;
    }

    void setSizeOfBoard(int sizeOfBoard) {
        Board::sizeOfBoard = sizeOfBoard;
    }

    const vector<vector<char>> &getBoard() const {
        return board;
    }

    void setBoard(const vector<vector<char>> &board) {
        Board::board = board;
    }
};


#endif //TICTACTOE_BOARD_H
