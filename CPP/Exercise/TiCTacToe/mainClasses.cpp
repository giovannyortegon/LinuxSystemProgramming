#include<iostream>

using namespace std;

class TicTacToe {
    private:
        char game[4][4];
    public:
        TicTacToe();
        void setGame(int row, int col, char grid);
        char getGame(int row, int col);
        void print();
};

TicTacToe::TicTacToe() {
     for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            game[i][j] = '-';
        }
    }
}

void TicTacToe::setGame(int row, int col, char grid) {
    
    if (game[row][col] == '-')
        game[row][col] = grid;
}
char TicTacToe::getGame(int row, int col) {
    return game[row][col];
}
void TicTacToe::print() {
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout <<'|'<<game[i][j] <<'|';
        }
        cout <<'\n';
    }
}
