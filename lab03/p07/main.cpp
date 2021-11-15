#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }
using namespace std;
typedef long long ll;

class Game {
    vector <string> lines;
    vector<vector <char> > cells;
    int result = 0;
    string snf;
    
    private:
    
    void read(string snf){
        string str;
        int i = 0;
        for (auto e : snf) {
            if (e == '/') {
                lines.push_back(str);
                i++;
                str = "";
            } else {
                str += e;
            }
        }
        lines.push_back(str);
        if (i == 6){
            lines.push_back("/8");  ////////
        }
    }

    void fillEmpty(){
        for (int i = 0; i < 8; i ++){
            for (int j = 0; j < 8; j ++){
                
            }
        }
    }
    
    void fillCells(){
        for (int i = 0; i < 8; i ++){
            string temp = lines[i];
            for (int j = 0; j < temp.size(); j++){
                if (!isalpha(temp[j])) {
                    int num = (int) temp[j] - 48;
                    for (int k = 0; k < num; k ++){
                        cells[i].push_back('e');
                    }
                } else {
                    cells[i].push_back(temp[j]);
                }
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
            if (cells[x-1][y] == 'e'){cells[x-1][y] = 'A';}
            if (cells[x+1][y] == 'e'){cells[x+1][y] = 'A';}
            if (cells[x][y-1] == 'e'){cells[x][y-1] = 'A';}
            if (cells[x][y+1] == 'e'){cells[x][y+1] = 'A';}
        }
        if (x == 0) {if (cells[x+1][y] == 'e') cells[x+1][y] = 'A';}
        if (x == 7) {if (cells[x-1][y] == 'e') cells[x-1][y] = 'A';} 
        if (y == 0) {if (cells[x][y+1] == 'e') cells[x][y+1] = 'A';}
        if (y == 7) {if (cells[x][y-1] == 'e') cells[x][y-1] = 'A';}
        if (y != 0) {if (cells[x][y-1] == 'e') cells[x][y-1] = 'A';}
        if (y != 7) {if (cells[x][y+1] == 'e') cells[x][y+1] = 'A';}
        if (x != 0) {if (cells[x-1][y] == 'e') cells[x-1][y] = 'A';}
        if (x != 7) {if (cells[x+1][y] == 'e') cells[x+1][y] = 'A';}
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
            if (cells[x-1][y-1] == 'e'){cells[x-1][y-1] = 'A';}
            if (cells[x-1][y+1] == 'e'){cells[x-1][y+1] = 'A';}
        } else if (x != 0 && y == 0){
            if (cells[x-1][y+1] == 'e'){cells[x-1][y+1] = 'A';}
        } else if (x != 0 && y == 7){  //
            if (cells[x-1][y-1] == 'e'){cells[x-1][y-1] = 'A';}
        }
    }
    
    void pawnBlackMove(int x, int y){
        if (x != 7 && y != 0 && y !=7){
            if (cells[x+1][y-1] == 'e'){cells[x+1][y-1] = 'A';}
            if (cells[x+1][y+1] == 'e'){cells[x+1][y+1] = 'A';}
        } else if (x != 7 && y == 0){   //
            if (cells[x+1][y+1] == 'e'){cells[x+1][y+1] = 'A';}
        } else if (x != 7 && y == 7){
            if (cells[x+1][y-1] == 'e'){cells[x+1][y-1] = 'A';}
        }
    }
    
    void bishop(){
        for (int x = 0; x < 8; x ++){
            for (int y = 0; y < 8; y ++){
                if (cells[x][y] == 'b' || cells[x][y] == 'B'){
                    bishopMove(x,y);
                }
            }
        }
    }
    
    void bishopMove(int a, int b){
        int x = a; int y = b;
        while (x != 0 && y != 0){x--;y--;
            if (cells[x][y] == 'e' || cells[x][y] == 'A'){cells[x][y] = 'A';}
            else {break;}
        }
        x = a; y = b;
        while (x != 7 && y != 7){
            x++; y++;
            if (cells[x][y] == 'e' || cells[x][y] == 'A'){cells[x][y] = 'A';}
            else {break;}
        }
        x = a; y = b;
        while (x != 0 && y != 7){
            x--; y++;
            if (cells[x][y] == 'e' || cells[x][y] == 'A'){cells[x][y] = 'A';}
            else {break;}
        }
        x = a; y = b;
        while (x != 7 && y != 0){
            x++; y--;
            if (cells[x][y] == 'e' || cells[x][y] == 'A'){cells[x][y] = 'A';}
            else {break;}
        }
        x = a; y = b;
    }
    
    void rook(){
        for (int x = 0; x < 8; x ++){
            for (int y = 0; y < 8; y ++){
                if (cells[x][y] == 'r' || cells[x][y] == 'R'){
                    rookMove(x,y);
                }
            }
        }
    }
    
    void rookMove(int a, int b){
        int x = a; int y = b;
        while (x != 0){ 
            x--;
            if (cells[x][y] == 'e' || cells[x][y] == 'A'){cells[x][y] = 'A';}
            else {break;}
        }
        x = a; y = b;
        while (x != 7){
            x++;
            if (cells[x][y] == 'e' || cells[x][y] == 'A'){cells[x][y] = 'A';}
            else {break;}
        }
        x = a; y = b;
        while (y != 0){
            y--;
            if (cells[x][y] == 'e' || cells[x][y] == 'A'){cells[x][y] = 'A';}
            else {break;}
        }
        x = a; y = b;
        while (y != 7){
            y++;
            if (cells[x][y] == 'e' || cells[x][y] == 'A'){cells[x][y] = 'A';}
            else {break;}
        }
        x = a; y = b;
    }
    
    void queen(){
        for (int x = 0; x < 8; x ++){
            for (int y = 0; y < 8; y ++){
                if (cells[x][y] == 'q' || cells[x][y] == 'Q'){
                    queenMove(x,y);
                }
            }
        }
    }
    
    void queenMove(int x, int y){
        rookMove(x,y);
        bishopMove(x,y);
    }
    
    void knight(){
        for (int x = 0; x < 8; x ++){
            for (int y = 0; y < 8; y ++){
                if (cells[x][y] == 'n' || cells[x][y] == 'N'){
                    knightMoveUp(x,y);
                    knightMoveDown(x,y);
                    knightMoveLeft(x,y);
                    knightMoveRight(x,y);
                }
            }
        }
    }
    
    void knightMoveUp(int x, int y){
        if (x != 0 && x != 1){
            if (y != 0 && y != 7){
                if (cells[x-2][y-1] == 'e' || cells[x-2][y-1] == 'A'){cells[x-2][y-1] = 'A';}
                if (cells[x-2][y+1] == 'e' || cells[x-2][y+1] == 'A'){cells[x-2][y+1] = 'A';}
            } else if (y == 0){
                if (cells[x-2][y+1] == 'e' || cells[x-2][y+1] == 'A'){cells[x-2][y+1] = 'A';}
            } else if (y == 7){
                if (cells[x-2][y-1] == 'e' || cells[x-2][y-1] == 'A'){cells[x-2][y-1] = 'A';}
            }
        }
    }
    
    void knightMoveDown(int x, int y){
        if (x != 7 && x != 6){
            if (y != 0 && y != 7){
                if (cells[x+2][y-1] == 'e' || cells[x+2][y-1] == 'A'){cells[x+2][y-1] = 'A';}
                if (cells[x+2][y+1] == 'e' || cells[x+2][y+1] == 'A'){cells[x+2][y+1] = 'A';}
            } else if (y == 0){
                if (cells[x+2][y+1] == 'e' || cells[x+2][y+1] == 'A'){cells[x+2][y+1] = 'A';}
            } else if (y == 7){
                if (cells[x+2][y-1] == 'e' || cells[x+2][y-1] == 'A'){cells[x+2][y-1] = 'A';}
            }
        }
    }
    
    void knightMoveRight(int x, int y){
        if (y != 7 && y != 6){
            if (x != 0 && x != 7){
                if (cells[x-1][y+2] == 'e' || cells[x-1][y+2] == 'A'){cells[x-1][y+2] = 'A';}
                if (cells[x+1][y+2] == 'e' || cells[x+1][y+2] == 'A'){cells[x+1][y+2] = 'A';}
            } else if (x == 0){
                if (cells[x+1][y+2] == 'e' || cells[x+1][y+2] == 'A'){cells[x+1][y+2] = 'A';}} else if (x == 7){
                if (cells[x-1][y+2] == 'e' || cells[x-1][y+2] == 'A'){cells[x-1][y+2] = 'A';}
            }
        }
    }
    
    void knightMoveLeft(int x, int y){
        if (y != 0 && y != 1){
            if (x != 0 && x != 7){
                if (cells[x-1][y-2] == 'e' || cells[x-1][y-2] == 'A'){cells[x-1][y-2] = 'A';}
                if (cells[x+1][y-2] == 'e' || cells[x+1][y-2] == 'A'){cells[x+1][y-2] = 'A';}
            } else if (x == 0){
                if (cells[x+1][y-2] == 'e' || cells[x+1][y-2] == 'A'){cells[x+1][y-2] = 'A';}
            } else if (x == 7){
                if (cells[x-1][y-2] == 'e' || cells[x-1][y-2] == 'A'){cells[x-1][y-2] = 'A';}
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
    }
    
    void findAnswer(){
        for (int i = 0; i < 8; i ++){
            for (int j = 0; j < 8; j ++){
                if (cells[i][j] == 'e') {result ++;}
            }
        }
        cout <<result<<"\n";
    }
    
    public:
    Game(string str)
    :cells(8)
    {
        snf = str;
    }
    
    void solve(){
        read(snf);
        fillCells();
        pawnWhite();
        pawnBlack();
        king();
        bishop();
        rook();
        queen();
        knight();
    //    runCheck();
        findAnswer();
    }
};

int main()
{
    iostream::sync_with_stdio(false);
    
    for (string snf; getline(cin,snf);){
        Game game(snf);
        game.solve();
    }
}