#include"mainClasses.cpp"

void printGame(TicTacToe &game);

int SearchResult(TicTacToe &game, char grid);
int firstDiagonal(TicTacToe &game, char grid);
int SecondDiagonal(TicTacToe &game, char grid);
int UpDown(TicTacToe &game, char grid);
int LeftRight(TicTacToe &game, char grid);

void printGame(TicTacToe &game) {

    for (int i = 0; i < 4; i++){
        
        for (int j = 0; j < 4; j++){
            cout <<'|'<<game.getGame(i, j) <<'|';
        }
        cout <<'\n';
    }
}

int SearchResult(TicTacToe &game, char grid) {
    
    if (firstDiagonal(game,grid))
        return (1);
    else if (SecondDiagonal(game, grid))
        return (1);
    else if (UpDown(game, grid))
        return (1);
    else if (LeftRight(game, grid))
        return (1);
    else
        return (0);
}

int firstDiagonal(TicTacToe &game, char grid) {
    for (int i = 0; i < 4; i++)
    {
        if (game.getGame(i, i) == grid)
            continue;
        else
            return 0;
        
    }

    return 1;
}

int SecondDiagonal(TicTacToe &game, char grid) {

    for (int i = 0, j = 3; i < 4; i++, j--)
    {
        
        if (game.getGame(i, j) == grid)
            continue;
        else
            return 0;
    }

    return 1;
}

int UpDown(TicTacToe &game, char grid) {
    int count = 0;
    
    for (int i = 0; i < 4; i++){
        count = 0;
        for (int j = 0; j < 4; j++){
            if(!(game.getGame(i, j) == grid))
                break;
            else
                count++;
        }
        if (count == 4) {
            return 1;
        }
    }
    return 0;
}

int LeftRight(TicTacToe &game, char grid) {
    int count;
    
    for (int i = 0; i < 4; i++){
        count = 0;
        for (int j = 0; j < 4; j++){
            if(!(game.getGame(j, i) == grid))
                break;
            else
                count++;
        }
        if (count == 4) {
            return 1;
        }
    }
    return 0;
}
