#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void output(vector <vector <char>> v, int &cnt){
    cout <<"Puzzle #"<<cnt<<":\n";
    for (int i = 0; i < 5; i ++){
        for (int j = 0; j < 5; j ++){
            if (j != 4){cout <<v[i][j] <<" ";}
            else {cout <<v[i][j];}
        }
        cout <<"\n";
    }
 //   cout <<"\n";
}

bool move(vector <vector <char>> &v, string str,int &xi, int &yi){
    bool check = true;
    for (int i = 0; i < (int) str.size() - 1; i ++){
        if (str[i] == 'A'){
            if (xi!= 0){
                v[xi][yi] = v[xi-1][yi];
                v[xi-1][yi] = ' ';
                xi--;
            } else{check = false;}
        }else if (str[i] == 'B'){
            if (xi != 4){
                v[xi][yi] = v[xi+1][yi];
                v[xi+1][yi] = ' ';
                xi++;
            } else{check = false;}
        } else if (str[i] == 'L'){
            if (yi != 0){
                v[xi][yi] = v[xi][yi-1];
                v[xi][yi-1] = ' ';
                yi--;
            } else{check = false;}
        } else if (str[i] == 'R'){
            if (yi != 4){
                v[xi][yi] = v[xi][yi+1];
                v[xi][yi+1] = ' ';
                yi++;
            } else {check = false;}
        } else if (str[i] != '0'){check = false;}
    }
    return check;
}

bool input(){
    int cnt = 1;
    while (true){
        vector <vector <char>> v(5);
        vector <int> index {0,0};
        int xi = 0, yi = 0;
        string str = "";
        string line = "";
        for (int i = 0; i < 5; i ++){
            getline(cin, line);
            if (line.size() == 4){line += " ";}
            if (line == "Z"){return false;}
            for (int j = 0; j < (int) line.size() && j <= 4; j ++){
                if (line[j] == ' ' ){xi = i;yi = j;}
                v[i].push_back(line[j]);
            }
        }
        if (cnt != 1){cout << "\n";}
        while (true){
            string com;
            cin>>com;
            str += com;
            if (com[com.size()-1] == '0'){break;}
        }
        if (move(v,str,xi,yi)) {output(v, cnt);}
        else {cout <<"Puzzle #"<<cnt<<":\n"<<"This puzzle has no final configuration.\n";}
        cnt ++;
        string temp;
        getline (cin,temp);
    }
}

int main()
{
    iostream::sync_with_stdio(false);
    input();
}