#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }
using namespace std;
typedef long long ll;

class Computer
{
    vector<int> registers;
    vector<int> memory;
    int instructionPointer;

private:
    void runCommand2(int &d, int &n){
        registers[d] = n;
        ++instructionPointer;
    }

    void runCommand3(int &d, int &n){
        registers[d] = (registers[d] + n) % 1000;
        ++instructionPointer;
    }

    void runCommand4(int &d, int &n){
        registers[d] = (registers[d] * n) % 1000;
        ++instructionPointer;
    }

    void runCommand5(int &d, int &n){
        registers[d] = registers[n];
        ++instructionPointer;
    }

    void runCommand6(int &d, int &n){
        registers[d] = (registers[d] + registers[n]) % 1000;
        ++instructionPointer;
    }

    void runCommand7(int &d, int &n){
        registers[d] = (registers[d] * registers[n]) % 1000;
        ++instructionPointer;
    }
    void runCommand8(int &d, int &n){
        registers[d] = memory[registers[n]]; //exp
        ++instructionPointer;
    }
    void runCommand9(int &d, int &n){
        memory[registers[n]] = registers[d];
        ++instructionPointer;
    }

public:
    Computer()
        : registers(10, 0),
          memory(1000, 0),
          instructionPointer(0)
    {
    }

    void readCommands(istream &inp){

        int curPos = 0;

        for (string line; getline(inp, line) && !line.empty();){
            memory[curPos] = stoi(line);
            curPos++;
        }
    }

    int run(){

        int res = 1;

        while (memory[instructionPointer] != 100){
            int t = memory[instructionPointer];

            int n = t % 10;
            t /= 10;
            int d = t % 10;
            t /= 10;
            int cmd = t;

            switch (cmd)
            {
            case 2:
                runCommand2(d, n);
                break;
            case 3:
                runCommand3(d, n);
                break;
            case 4:
                runCommand4(d, n);
                break;
            case 5:
                runCommand5(d, n);
                break;
            case 6:
                runCommand6(d, n);

                break;
            case 7:
                runCommand7(d, n);
                break;
            case 8:
                runCommand8(d, n);

                break;
            case 9:
                runCommand9(d, n);

                break;

            case 0:

                if (registers[n] != 0)
                {
                    instructionPointer = registers[d];
                }
                else
                {
                    ++instructionPointer;
                }
                break;
            }
            res++;
        }
        return res;
    }
};

int main(){
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests >> ws;

    for (int test = 1; test <= tests; test++){

        Computer comp;

        comp.readCommands(cin);

        if (test != 1){cout << "\n";}

        cout << comp.run() << "\n";
    }
}