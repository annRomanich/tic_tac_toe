#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

char field [3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'}};
// x
// o
bool userWin = false, compWin = false, noWin = false;
int x, y;
int h = 0;

bool hasWon(char symbol){
    if( // по строкам
    (field[0][0] == symbol && field[0][1] == symbol && field[0][2] == symbol) ||  
    (field[1][0] == symbol && field[1][1] == symbol && field[1][2] == symbol) ||
    (field[2][0] == symbol && field[2][1] == symbol && field[2][2] == symbol) ||
    // по столбцам
    (field[0][0] == symbol && field[1][0] == symbol && field[2][0] == symbol) ||  
    (field[0][1] == symbol && field[1][1] == symbol && field[2][1] == symbol) ||
    (field[0][2] == symbol && field[2][1] == symbol && field[2][2] == symbol) ||
    // по диагоналям
    (field[0][0] == symbol && field[1][1] == symbol && field[2][2] == symbol) ||
    (field[0][2] == symbol && field[1][1] == symbol && field[2][0] == symbol) 
    ) {
        return true;
    }
    return false;
}

int main(){

    srand(time(NULL));
    do{    
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout << field[i][j];       
            }
            cout << endl;
        }

        do
        {
            cout << "Enter position: ";
            cin >> x >> y;
        } while (field[x-1][y-1] != '.');       
        field[x-1][y-1]='x';
        h++; 
        
        if(h != 9){
            do{
                x = rand()%3;   // 0-2
                y = rand()%3;
            } while (field[x][y] != '.');
            field[x][y] = 'o';
            h++;
        }

        userWin = hasWon('x');
        compWin = hasWon('o');

        if(!userWin && !compWin && h==9){
            noWin = true;
        }

        system("CLS");
    } while(!userWin && !compWin && !noWin);

    if(userWin == true){
        cout << "userWin";
    }
    if(compWin == true){
        cout << "compWin";
    }
    if(noWin == true){
        cout << "noWin";
    }

    return 0;
}
