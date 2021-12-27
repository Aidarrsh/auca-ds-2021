#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }
using namespace std;

struct Team
{
    string name;
    int pt, win, lose, tie, goalOut, goalIn;

    Team()
        : pt(0), win(0), lose(0), tie(0), goalOut(0), goalIn(0)
    {
    }

    void result(int goals, int goals1)
    {
        if (goals > goals1)
        {
            pt += 3;
            win++;
        }

        else if (goals == goals1)
        {
            pt++;
            tie++;
        }
        else
        {
            lose++;
        }
        goalOut += goals;
        goalIn += goals1;
    }
};

void initGame(string game, string &cmd, string &cmd1, int &goals, int &goals1)
{
    vector<string> t;
    string temp;
    for (int i = 0; i < sz(game); i++)
    {
        if (game[i] == '#' || game[i] == '@')
        {
            t.push_back(temp);
            temp = "";
            continue;
        }
        temp += game[i];
    }
    cmd = t[0];
    goals = stoi(t[1]);
    goals1 = stoi(t[2]);
    cmd1 = temp;
}
bool cmp(const Team &a, const Team &b)
{
    if (a.pt != b.pt)
        return a.pt > b.pt;

    if (a.win != b.win)
        return a.win > b.win;

    if (a.goalOut - a.goalIn != b.goalOut - b.goalIn)
        return a.goalOut - a.goalIn > b.goalOut - b.goalIn;

    if (a.goalOut != b.goalOut)
        return a.goalOut > b.goalOut;

    if (a.win + a.lose + a.tie != b.win + b.lose + b.tie)
        return a.win + a.lose + a.tie < b.win + b.lose + b.tie;

    string tA = a.name;
    transform(tA.begin(), tA.end(), tA.begin(), ::tolower);
    string tB = b.name;
    transform(tB.begin(), tB.end(), tB.begin(), ::tolower);
    return lexicographical_compare(begin(tA), end(tA), begin(tB), end(tB));
}

void solve()
{
    string tourName, comName, game;
    getline(cin, tourName);
    int nTeams, nGames;

    cin >> nTeams >> ws;

    map<string, int> cmdNames;
    vector<Team> table(nTeams);

    for (int i = 0; i < nTeams; ++i)
    {
        getline(cin, comName);
        table[i].name = comName;
        cmdNames[comName] = i;
    }

    cin >> nGames >> ws;

    for (int j = 0; j < nGames; ++j)
    {
        string cmd, cmd1;
        int goals, goals1;

        getline(cin, game);

        initGame(game, cmd, cmd1, goals, goals1);

        table[cmdNames[cmd]].result(goals, goals1);
        table[cmdNames[cmd1]].result(goals1, goals);
    }
    sort(begin(table), end(table), cmp);

    cout << tourName << "\n";

    for (int i = 0; i < nTeams; ++i)
    {
        int totalGames = table[i].win + table[i].tie + table[i].lose;
        cout << i + 1 << ") " << table[i].name << " " << table[i].pt << "p, " << totalGames << "g ("
             << table[i].win << "-" << table[i].tie << "-" << table[i].lose << "), "
             << table[i].goalOut - table[i].goalIn << "gd (" << table[i].goalOut << "-" << table[i].goalIn << ")\n";
    }
}

int main()
{
    iostream::sync_with_stdio(false);
    int t;
    cin >> t >> ws;

    for (int tests = 0; tests < t; tests++)
    {
        if (tests)
        {
            cout << "\n";
        }
        solve();
    }
}