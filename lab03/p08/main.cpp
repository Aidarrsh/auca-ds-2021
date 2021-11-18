#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }
using namespace std;
typedef long long ll;

class Game {
    vector <string> lines;
    vector<vector <char> > cells;
    string check = "no";
    vector <string> str;
    
    private:
    
    void read(vector <string> str){
        for (int i = 0; i < 8; i ++){
            string s = str[i];
            for (int j = 0; j < 8; j ++){
                cells[i].push_back(s[i]);
            }
        }
    }
    
    void fillCells(){
        for (int i = 0; i < 8; i ++){
            string temp = lines[i];
            for (int j = 0; j < 8; j ++){
                cells[i].push_back(temp[j]);
            }
        }
    }
    
    void king(){
        for (int x = 0; x < 8; x ++){
            for (int y = 0; y < 8; y ++){
                if (cells[x][y] == 'K' || cells[x][y] == 'k'){
                    kingMoveDiagonal(x,y);
                    kingMoveStraight(x,y);
                }
            }
        }
    }
    
    void kingMoveDiagonal(int x, int y){
        pawnWhiteMove(x,y);
        pawnBlackMove(x,y);
    }
    
    void kingMoveStraight(int x, int y){
        if (x != 0 && y != 0 && x != 7 && y != 7){
            if (cells[x-1][y] == '.'){cells[x-1][y] = 'A';}
            if (cells[x+1][y] == '.'){cells[x+1][y] = 'A';}
            if (cells[x][y-1] == '.'){cells[x][y-1] = 'A';}
            if (cells[x][y+1] == '.'){cells[x][y+1] = 'A';}
        }
        if (x == 0) {if (cells[x+1][y] == '.') cells[x+1][y] = 'A';}
        if (x == 7) {if (cells[x-1][y] == '.') cells[x-1][y] = 'A';} 
        if (y == 0) {if (cells[x][y+1] == '.') cells[x][y+1] = 'A';}
        if (y == 7) {if (cells[x][y-1] == '.') cells[x][y-1] = 'A';}
        if (y != 0) {if (cells[x][y-1] == '.') cells[x][y-1] = 'A';}
        if (y != 7) {if (cells[x][y+1] == '.') cells[x][y+1] = 'A';}
        if (x != 0) {if (cells[x-1][y] == '.') cells[x-1][y] = 'A';}
        if (x != 7) {if (cells[x+1][y] == '.') cells[x+1][y] = 'A';}
    }
    
    void pawnBlack(){
        for (int x = 0; x < 8; x ++){
            for (int y = 0; y < 8; y ++){
                if (cells[x][y] == 'p'){
                    pawnBlackMove(x,y);
                }
            }
        }
    }
    
    void pawnWhite(){
        for (int x = 0; x < 8; x ++){
            for (int y = 0; y < 8; y ++){
                if (cells[x][y] == 'P'){
                    pawnWhiteMove(x,y);
                }
            }
        }
    }
    
    void pawnWhiteMove(int x, int y){
        if (x != 0 && y != 0 && y !=7){
            if (cells[x-1][y-1] == 'k'){check = "black";}
            if (cells[x-1][y+1] == 'k'){check = "black";}
        } else if (x != 0 && y == 0){
            if (cells[x-1][y+1] == 'k'){check = "black";}
        } else if (x != 0 && y == 7){ 
            if (cells[x-1][y-1] == 'k'){check = "black";}
        }
    }
    
    void pawnBlackMove(int x, int y){
        if (x != 7 && y != 0 && y !=7){
            if (cells[x+1][y-1] == 'K'){check = "white";}
            if (cells[x+1][y+1] == 'K'){check = "white";}
        } else if (x != 7 && y == 0){  
            if (cells[x+1][y+1] == 'K'){check = "white";}
        } else if (x != 7 && y == 7){
            if (cells[x+1][y-1] == 'K'){check = "white";}
        }
    }
    
    void bishopWhite(){
        for (int x = 0; x < 8; x ++){
            for (int y = 0; y < 8; y ++){
                if (cells[x][y] == 'B'){
                    bishopWhiteMove(x,y);
                }
            }
        }
    }
    
    void bishopBlack(){
        for (int x = 0; x < 8; x ++){
            for (int y = 0; y < 8; y ++){
                if (cells[x][y] == 'b'){
                    bishopBlackMove(x,y);
                }
            }
        }
    }
    
    void bishopWhiteMove(int a, int b){
        int x = a; int y = b;
        while (x != 0 && y != 0){
            x--;y--;
            if (cells[x][y] == '.' || cells[x][y] == 'k'){if (cells[x][y] == 'k') check = "black";}
            else {break;}
        }
        x = a; y = b;
        while (x != 7 && y != 7){
            x++; y++;
            if (cells[x][y] == '.' || cells[x][y] == 'k'){if (cells[x][y] == 'k') check = "black";}
            else {break;}
        }
        x = a; y = b;
        while (x != 0 && y != 7){
            x--; y++;
            if (cells[x][y] == '.' || cells[x][y] == 'k'){if (cells[x][y] == 'k') check = "black";}
            else {break;}
        }
        x = a; y = b;
        while (x != 7 && y != 0){
            x++; y--;
            if (cells[x][y] == '.' || cells[x][y] == 'k'){if (cells[x][y] == 'k') check = "black";}
            else {break;}
        }
        x = a; y = b;
    }
    
    void bishopBlackMove(int a, int b){
        int x = a; int y = b;
        while (x != 0 && y != 0){
            x--;y--;
            if (cells[x][y] == '.' || cells[x][y] == 'K'){if (cells[x][y] == 'K') check = "white";}
            else {break;}
        }
        x = a; y = b;
        while (x != 7 && y != 7){
            x++; y++;
            if (cells[x][y] == '.' || cells[x][y] == 'K'){if (cells[x][y] == 'K') check = "white";}
            else {break;}
        }
        x = a; y = b;
        while (x != 0 && y != 7){
            x--; y++;
            if (cells[x][y] == '.' || cells[x][y] == 'K'){if (cells[x][y] == 'K') check = "white";}
            else {break;}
        }
        x = a; y = b;
        while (x != 7 && y != 0){
            x++; y--;
            if (cells[x][y] == '.' || cells[x][y] == 'K'){if (cells[x][y] == 'K') check = "white";}
            else {break;}
        }
        x = a; y = b;
    }
    
    void rook(){
        for (int x = 0; x < 8; x ++){
            for (int y = 0; y < 8; y ++){
                if (cells[x][y] == 'R'){
                    rookWhiteMove(x,y);
                } else if (cells[x][y] == 'r'){
                    rookBlackMove(x,y);
                }
            }
        }
    }
    
    void rookWhiteMove(int a, int b){
        int x = a - 1; int y = b;
        while (x != -1 && (cells[x][y] == '.' || cells[x][y] == 'k')){ 
            if (cells[x][y] == 'k') {check = "black";}
            x--;
        }
        x = a + 1; y = b;
        while (x != 8 && (cells[x][y] == '.' || cells[x][y] == 'k')){
            if (cells[x][y] == 'k') {check = "black";}
            x++;
        }
        x = a; y = b - 1;
        while (y != -1 && (cells[x][y] == '.' || cells[x][y] == 'k')){
            if (cells[x][y] == 'k') {check = "black";}
            y--;
        }
        x = a; y = b + 1;
        while (y != 8 && (cells[x][y] == '.' || cells[x][y] == 'k')){
            if (cells[x][y] == 'k') {check = "black";}
            y++;
        }
        x = a; y = b;
    }
    
    void rookBlackMove(int a, int b){
        int x = a - 1; int y = b;
        while (x != -1 && (cells[x][y] == '.' || cells[x][y] == 'K')){ 
            if (cells[x][y] == 'K') {check = "white";}
            x--;
        }
        x = a + 1; y = b;
        while (x != 8 && (cells[x][y] == '.' || cells[x][y] == 'K')){
            if (cells[x][y] == 'K') {check = "white";}
            x++;
        }
        x = a; y = b - 1;
        while (y != -1 && (cells[x][y] == '.' || cells[x][y] == 'K')){
            if (cells[x][y] == 'K') {check = "white";}
            y--;
        }
        x = a; y = b + 1;
        while (y != 8 && (cells[x][y] == '.' || cells[x][y] == 'K')){
            if (cells[x][y] == 'K') {check = "white";}
            y++;
        }
        x = a; y = b;
    }
    
    void queen(){
        for (int x = 0; x < 8; x ++){
            for (int y = 0; y < 8; y ++){
                if (cells[x][y] == 'Q'){
                    queenWhiteMove(x,y);
                } else if (cells[x][y] == 'q'){
                    queenBlackMove(x,y);
;                }
            }
        }
    }
    
    void queenWhiteMove(int x, int y){
        rookWhiteMove(x,y);
        bishopWhiteMove(x,y);
    }
    
    void queenBlackMove(int x, int y){
        rookBlackMove(x,y);
        bishopBlackMove(x,y);
    }
    
    void knight(){
        for (int x = 0; x < 8; x ++){
            for (int y = 0; y < 8; y ++){
                if (cells[x][y] == 'N'){
                    knightWhiteMoveUp(x,y);
                    knightWhiteMoveDown(x,y);
                    knightWhiteMoveLeft(x,y);
                    knightWhiteMoveRight(x,y);
                } else if (cells[x][y] == 'n'){
                    knightBlackMoveUp(x,y);
                    knightBlackMoveDown(x,y);
                    knightBlackMoveLeft(x,y);
                    knightBlackMoveRight(x,y);
                }
            }
        }
    }
    
    void knightWhiteMoveUp(int x, int y){
        if (x != 0 && x != 1){
            if (y != 0 && y != 7){
                if (cells[x-2][y-1] == 'k'){check = "black";}
                if (cells[x-2][y+1] == 'k'){check = "black";}
            } else if (y == 0){
                if (cells[x-2][y+1] == 'k'){check = "black";}
            } else if (y == 7){
                if (cells[x-2][y-1] == 'k'){check = "black";}
            }
        }
    }
    
    void knightWhiteMoveDown(int x, int y){
        if (x != 7 && x != 6){
            if (y != 0 && y != 7){
                if (cells[x+2][y-1] == 'k'){check = "black";}
                if (cells[x+2][y+1] == 'k'){check = "black";}
            } else if (y == 0){
                if (cells[x+2][y+1] == 'k'){check = "black";}
            } else if (y == 7){
                if (cells[x+2][y-1] == 'k'){check = "black";}
            }
        }
    }
    
    void knightWhiteMoveRight(int x, int y){
        if (y != 7 && y != 6){
            if (x != 0 && x != 7){
                if (cells[x-1][y+2] == 'k'){check = "black";}
                if (cells[x+1][y+2] == 'k'){check = "black";}
            } else if (x == 0){
                if (cells[x+1][y+2] == 'k'){check = "black";}
            } else if (x == 7){
                if (cells[x-1][y+2] == 'k'){check = "black";}
            }
        }
    }
    
    void knightWhiteMoveLeft(int x, int y){
        if (y != 0 && y != 1){
            if (x != 0 && x != 7){
                if (cells[x-1][y-2] == 'k'){check = "black";}
                if (cells[x+1][y-2] == 'k'){check = "black";}
            } else if (x == 0){
                if (cells[x+1][y-2] == 'k'){check = "black";}
            } else if (x == 7){
                if (cells[x-1][y-2] == 'k'){check = "black";}
            }
        }
    }
    
    void knightBlackMoveUp(int x, int y){
        if (x != 0 && x != 1){
            if (y != 0 && y != 7){
                if (cells[x-2][y-1] == 'K'){check = "white";}
                if (cells[x-2][y+1] == 'K'){check = "white";}
            } else if (y == 0){
                if (cells[x-2][y+1] == 'K'){check = "white";}
            } else if (y == 7){
                if (cells[x-2][y-1] == 'K'){check = "white";}
            }
        }
    }
    
    void knightBlackMoveDown(int x, int y){
        if (x != 7 && x != 6){
            if (y != 0 && y != 7){
                if (cells[x+2][y-1] == 'K'){check = "white";}
                if (cells[x+2][y+1] == 'K'){check = "white";}
            } else if (y == 0){
                if (cells[x+2][y+1] == 'K'){check = "white";}
            } else if (y == 7){
                if (cells[x+2][y-1] == 'K'){check = "white";}
            }
        }
    }
    
    void knightBlackMoveRight(int x, int y){
        if (y != 7 && y != 6){
            if (x != 0 && x != 7){
                if (cells[x-1][y+2] == 'K'){check = "white";}
                if (cells[x+1][y+2] == 'K'){check = "white";}
            } else if (x == 0){
                if (cells[x+1][y+2] == 'K'){check = "white";}
            } else if (x == 7){
                if (cells[x-1][y+2] == 'K'){check = "white";}
            }
        }
    }
    
    void knightBlackMoveLeft(int x, int y){
        if (y != 0 && y != 1){
            if (x != 0 && x != 7){
                if (cells[x-1][y-2] == 'K'){check = "white";}
                if (cells[x+1][y-2] == 'K'){check = "white";}
            } else if (x == 0){
                if (cells[x+1][y-2] == 'K'){check = "white";}
            } else if (x == 7){
                if (cells[x-1][y-2] == 'K'){check = "white";}
            }
        }
    }
    
    void runCheck(){
        for (int i = 0; i < 8; i ++){
            for (int j = 0; j < 8; j ++){
                cout <<cells[i][j]<<" ";
            }
            cout <<"\n";
        }
        //написать ретурны.
    }
    
    void findAnswer(){
        cout <<"Game #1: "<< check <<" king is in check.\n";
    }
    
    void f(){
        for (int i = 0; i < 8; i ++){
            for (int j = 0; j < 8; j ++){
                cout <<cells[i][j]<<" ";
            }
            cout <<"\n";
        }
    }
    
    public:
    Game(vector <string> str)
    :cells(8)
    {
        lines = str;
    }
    
    string solve(){
    //    read(str);
        fillCells();
        pawnWhite();
        pawnBlack();
    //    king();
        bishopWhite();
        bishopBlack();
        rook();
        queen();
        knight();
    //    runCheck();
    //    findAnswer();
        return check;
    }
};

int main()
{
iostream::sync_with_stdio(false);
int cnt = 1;
    while (true){
        int check = 0;
        vector <string> lines;
        for (int i = 0; i < 8; i ++){
            string s;
            cin >> s;
            lines.push_back(s);
            if (s == "........"){check++;}
        }
        if (check == 8){break;}
        Game game(lines);
        cout <<"Game #"<<cnt<<": "<< game.solve() <<" king is in check.\n";
        cnt ++;
        string s;
        getline(cin,s);
    }
}