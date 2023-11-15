#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

bool hasWon(char (&field)[3][3], char c) {
            // по строкам
    return  (field[0][0] == c && field[0][1] == c && field[0][2] == c) ||  
            (field[1][0] == c && field[1][1] == c && field[1][2] == c) ||
            (field[2][0] == c && field[2][1] == c && field[2][2] == c) ||
            // по столбцам
            (field[0][0] == c && field[1][0] == c && field[2][0] == c) ||  
            (field[0][1] == c && field[1][1] == c && field[2][1] == c) ||
            (field[0][2] == c && field[1][2] == c && field[2][2] == c) ||
            // по диагоналям
            (field[0][0] == c && field[1][1] == c && field[2][2] == c) ||
            (field[0][2] == c && field[1][1] == c && field[2][0] == c) ; 
}

int main() {
    char field [3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'}};
    const int MaxTurn = 9;

    enum Result {undefined, userWin, compWin, noWin};

    int x, y;
    int turn = 0;
    Result result = undefined;

    srand(time(NULL));
    do {    
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                cout << field[i][j];       
            }
            cout << endl;
        }

        do {
            cout << "Enter position: ";
            cin >> x >> y;
        } while (field[x-1][y-1] != '.');       
        field[x-1][y-1]='x';
        turn++; 
        
        if (turn != MaxTurn) {
            do {
                x = rand()%3;   // 0-2
                y = rand()%3;
            } while (field[x][y] != '.');
            field[x][y] = 'o';
            turn++;
        } 

        if (hasWon(field, 'x')) {
            result = userWin;
        }
        if (hasWon(field, 'o')) {
            result = compWin;
        }    
        if (result != userWin && result != compWin && turn == MaxTurn) {
            result = noWin;
        }

        system("CLS");
    } while (result == undefined);
  
    switch (result) {
        case userWin:
            cout << "userWin ";
            break;
        case compWin:
            cout << "compWin ";
            break;
        case noWin:
            cout << "noWin ";
            break;    
        default: cout << "UNDEFINED ";
            break;
    }

    return 0;
}
