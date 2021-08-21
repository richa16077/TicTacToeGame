//
// Created by richa on 21/08/21.
//
#include<string>
#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H
using namespace std;

static int currentId = 0;
class Player {
    string name;
    char piece;
public:
    Player(const string &name, char piece) : name(name), piece(piece) {}

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Player::name = name;
    }

    char getPiece() const {
        return piece;
    }

    void setPiece(char piece) {
        Player::piece = piece;
    }

};


#endif //TICTACTOE_PLAYER_H
