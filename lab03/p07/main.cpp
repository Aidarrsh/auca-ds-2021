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
    
    void kingCheck(){
        for (int x = 0; x < 8; x ++){
            for (int y = 0; y < 8; y ++){
                if (cells[x][y] == 'K' || cells[x][y] == 'k'){
                    
                }
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
    
    public:
    Game(string str)
    :cells(8)
    {
        snf = str;
    }
    
    void solve(){
        read(snf);
        fillCells();
        runCheck();
        kingCheck();
    }
};


int main()
{
    iostream::sync_with_stdio(false);
    
    for (string snf; getline(cin,snf);){
        Game game(snf);
        game.solve();
    //    cout << game.solve()<<"\n";
    }
}