#include"mainFunctions.cpp"

int main(){
    int row = 0, col = 0, turns = 8;
    char grid;

    TicTacToe g1;
    
    cout <<"Welcome to Tic Tac Toe Game\n";
    cout <<"'x' start the game\n";
    cout <<"Remeber dont repeat position of the another ";
    cout <<"in this case lost a turn.\n\n";
    cout <<"The board is Empty\n\n";
    g1.print();
    
    
    
    cout <<"\nStart the Game\n";

    while (turns != 0) {
        cin >> row;
        cin >> col;
        cin >> grid;
        
        cout << "Turn of: " <<grid;
        cout <<" choise: " <<row <<", " <<col <<" position\n";
        
        if (g1.getGame(row, col) != '-')
            cout <<"Lost turn. It is of '" <<g1.getGame(row, col) <<"'\n";

        g1.setGame(row, col, grid);
        
        g1.print();

        turns--;
    }

    cout <<"\nResult of Game:\n";
    printGame(g1);
    cout <<'\n';
    
    if (SearchResult(g1, 'x'))
        cout <<"X is Winner\n";
    else if (SearchResult(g1, 'o'))
        cout <<"O is Winner\n";
    else
        cout <<"Anybody is Winner.";
    
    cout <<"\nThe Game is finished.";
    
    return (0);
}
