#include <iostream>
using namespace std;



class Game{
private:
    char board[10][10];
    void setBoard(){
        for (int i = 0; i < 10; ++i) {
            board[0][i] = '0';
            board[9][i] = '0';
            board[i][0] = '0';
            board[i][9] = '0';
        }
        for (int i = 1; i < 9; ++i) {
            for (int j = 1; j < 9; ++j) {
                board[i][j] = '.';
            }
        }
        board[4][4] = 'X';
        board[5][5] = 'X';
        board[4][5] = 'O';
        board[5][4] = 'O';
    }
    void showBoard(){
        cout << "  " << "A B C D E F G H\n";
        for (int i = 1; i < 9; ++i) {
            cout << i << " ";
            for (int j = 1; j < 9; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    int readEntry(string entry){
        int rtn = 0;
        switch (entry[0]) {
            case 'a':
                rtn = 10;
                break;
            case 'b':
                rtn = 20;
                break;
            case 'c':
                rtn = 30;
                break;
            case 'd':
                rtn = 40;
                break;
            case 'e':
                rtn = 50;
                break;
            case 'f':
                rtn = 60;
                break;
            case 'g':
                rtn = 70;
                break;
            case 'h':
                rtn = 80;
                break;
        }
        switch (entry[1]) {
            case '1':
                rtn += 1;
                break;
            case '2':
                rtn += 2;
                break;
            case '3':
                rtn += 3;
                break;
            case '4':
                rtn += 4;
                break;
            case '5':
                rtn += 5;
                break;
            case '6':
                rtn += 6;
                break;
            case '7':
                rtn += 7;
                break;
            case '8':
                rtn += 8;
                break;
        }
        return rtn;
    }
    bool checkEntry(int entry, char crt){
        if(board[entry%10][entry/10] == '.' && numChange(entry,crt) != 0){
            return true;
        } else{
            return false;
        }
    }
    void updateBoard(int entry, char crt){
        if(checkEntry(entry,crt)){
            board[entry%10][entry/10] = crt;
        } else{
            string temp;
            cout << "\npleas Enter cell (EX: b7)'" << crt << "': ";
            cin >> temp;
            updateBoard(readEntry(temp), crt);
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10][entry/10+i] == '.' || board[entry%10][entry/10+i] == '0'){
                break;
            }else if(board[entry%10][entry/10+i] == crt){
                for (int j = 1; j < i; ++j) {
                    board[entry%10][entry/10+j] = crt;
                }
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10][entry/10-i] == '.' || board[entry%10][entry/10-i] == '0'){
                break;
            }else if(board[entry%10][entry/10-i] == crt){
                for (int j = 1; j < i; ++j) {
                    board[entry%10][entry/10-j] = crt;
                }
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10+i][entry/10] == '.' || board[entry%10+i][entry/10] == '0'){
                break;
            }else if(board[entry%10+i][entry/10] == crt){
                for (int j = 1; j < i; ++j) {
                    board[entry%10+j][entry/10] = crt;
                }
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10-i][entry/10] == '.' || board[entry%10-i][entry/10] == '0'){
                break;
            }else if(board[entry%10-i][entry/10] == crt){
                for (int j = 1; j < i; ++j) {
                    board[entry%10-j][entry/10] = crt;
                }
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10+i][entry/10+i] == '.' || board[entry%10+i][entry/10+i] == '0'){
                break;
            }else if(board[entry%10+i][entry/10+i] == crt){
                for (int j = 1; j < i; ++j) {
                    board[entry%10+j][entry/10+j] = crt;
                }
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10+i][entry/10-i] == '.' || board[entry%10+i][entry/10-i] == '0'){
                break;
            }else if(board[entry%10+i][entry/10-i] == crt){
                for (int j = 1; j < i; ++j) {
                    board[entry%10+j][entry/10-j] = crt;
                }
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10-i][entry/10+i] == '.' || board[entry%10-i][entry/10+i] == '0'){
                break;
            }else if(board[entry%10-i][entry/10+i] == crt){
                for (int j = 1; j < i; ++j) {
                    board[entry%10-j][entry/10+j] = crt;
                }
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10-i][entry/10-i] == '.' || board[entry%10-i][entry/10-i] == '0'){
                break;
            }else if(board[entry%10-i][entry/10-i] == crt){
                for (int j = 1; j < i; ++j) {
                    board[entry%10-j][entry/10-j] = crt;
                }
                break;
            }
        }
    }
    int numChange(int entry, char crt){
        int n=0;
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10][entry/10+i] == '.' || board[entry%10][entry/10+i] == '0'){
                break;
            }else if(board[entry%10][entry/10+i] != crt){
                continue;
            }else if(board[entry%10][entry/10+i] == crt && i>1){
                n += i-1;
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10][entry/10-i] == '.' || board[entry%10][entry/10-i] == '0'){
                break;
            }else if(board[entry%10][entry/10-i] != crt){
                continue;
            }else if(board[entry%10][entry/10-i] == crt && i>1){
                n += i-1;
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10+i][entry/10] == '.' || board[entry%10+i][entry/10] == '0'){
                break;
            }else if(board[entry%10+i][entry/10] != crt){
                continue;
            }else if(board[entry%10+i][entry/10] == crt && i>1){
                n += i-1;
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10-i][entry/10] == '.' || board[entry%10-i][entry/10] == '0'){
                break;
            }else if(board[entry%10-i][entry/10] != crt){
                continue;
            }else if(board[entry%10-i][entry/10] == crt && i>1){
                n += i-1;
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10+i][entry/10+i] == '.' || board[entry%10+i][entry/10+i] == '0'){
                break;
            }else if(board[entry%10+i][entry/10+i] != crt){
                continue;
            }else if(board[entry%10+i][entry/10+i] == crt && i>1){
                n += i-1;
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10+i][entry/10-i] == '.' || board[entry%10+i][entry/10-i] == '0'){
                break;
            }else if(board[entry%10+i][entry/10-i] != crt){
                continue;
            }else if(board[entry%10+i][entry/10-i] == crt && i>1){
                n += i-1;
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10-i][entry/10+i] == '.' || board[entry%10-i][entry/10+i] == '0'){
                break;
            }else if(board[entry%10-i][entry/10+i] != crt){
                continue;
            }else if(board[entry%10-i][entry/10+i] == crt && i>1){
                n += i-1;
                break;
            }
        }
        for (int i = 1; i < 9; ++i) {
            if (board[entry%10-i][entry/10-i] == '.' || board[entry%10-i][entry/10-i] == '0'){
                break;
            }else if(board[entry%10-i][entry/10-i] != crt){
                continue;
            }else if(board[entry%10-i][entry/10-i] == crt && i>1){
                n += i-1;
                break;
            }
        }
        return n;
    }
    void checkWin(){
        showBoard();
        int n=0;
        for (int i = 1; i < 9; ++i) {
            for (int j = 1; j < 9; ++j) {
                if(board[i][j] == 'X'){
                    n++;
                }
            }
        }
        if(n>32){
            cout << "\nplayer X win\n";
        }else{
            cout << "\nplayer O win\n";
        }
    }
    void bot(char crt){
        int n = 11;
        for (int i = 1; i < 9; ++i) {
            for (int j = 1; j < 9; ++j) {
                if(numChange(i*10+j,crt) > numChange(n,crt)){
                    n = i*10+j;
                }
            }
        }
        _sleep(800);
        updateBoard(n,crt);
    }
public:
    void play(bool PorB){
        setBoard();
        string cell;
        for (int i = 0; i < 60; ++i) {
            showBoard();
            if(i%2 == 0){
                cout << "\npleas Enter cell (EX: b7)'X': ";
                cin >> cell;
                updateBoard(readEntry(cell),'X');
                cout << "\n" <<numChange(readEntry(cell),'X') << "\n\n";
            }else if(PorB){
                cout << "\npleas Enter cell (EX: b7)'O': ";
                cin >> cell;
                updateBoard(readEntry(cell),'O');
                cout << "\n" <<numChange(readEntry(cell),'O') << "\n\n";
            }else{
                bot('O');
            }
            system("cls");
        }
        checkWin();
    }
};

int main() {
    cout << "Welcome\nOtello Game v0.1\n\nOpen Source :)";
    _sleep(1500);
    system("cls");
    Game g{};
    int entry;
    cout << "Menu:\n\n1-play by player\n2-play by bot\n\noption: ";
    cin >> entry;
    system("cls");
    if(entry==1){
        g.play(true);
    }else if(entry==2){
        g.play(false);
    }else{
        cout << "Entry is not valid :(";
    }
    return 0;
}
