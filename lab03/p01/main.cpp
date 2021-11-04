#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

vector<int> createDeck();
void printDeck(const vector<int> &deck);
vector<vector<int>> readShuffles();
vector<int> applyShuffleToDeck(vector<int> deck, vector<int> shufle);

int main()
{
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; test++)
    {
        auto shuffles = readShuffles();
        auto deck = createDeck();

        string temp;
        getline(cin, temp);

        for (string line; getline(cin, line) && !line.empty();)
        {
            int m = stoi(line);
            // cout << m << endl;
            deck = applyShuffleToDeck(deck, shuffles[m - 1]);
        }
        if (test != 0)
        {
            cout << "\n";
        }
        printDeck(deck);
    }

    // auto deck = createDeck();
}

void printDeck(const vector<int> &deck)
{
    vector<string> ranks = {
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "10",
        "Jack",
        "Queen",
        "King",
        "Ace",
    };

    vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};

    for (auto card : deck)
    {
        cout << ranks[card % 13] << " of " << suits[card / 13] << endl;
    }
}

vector<int> createDeck()
{
    vector<int> result(52);

    for (int i = 0; i < 52; i++)
    {
        result[i] = i;
    }

    return result;
}

vector<vector<int>> readShuffles()
{
    int num;
    cin >> num;

    vector<vector<int>> result(num, vector<int>(52));

    for (int i = 0; i < sz(result); i++)
    {
        for (int j = 0; j < 52; j++)
        {
            cin >> result[i][j];
        }
    }

    return result;
}

vector<int> applyShuffleToDeck(vector<int> deck, vector<int> shufle)
{
    vector<int> tempV(52);
    for (int i = 0; i < (int)shufle.size(); i++)
    {
        tempV[i] = deck[shufle[i] - 1];
    }

    return tempV;
}