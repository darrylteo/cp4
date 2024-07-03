#include <bits/stdc++.h>

using namespace std;

double TINY = 1e-9;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, g;
    cin >> p >> g;
    unordered_map<string, double> votes;
    for (int i = 0; i < p; ++i) {
        string name;
        double vote;
        cin >> name >> vote;
        votes[name] = vote;
    }
    cin.ignore();
    for (int i = 0; i < g; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string s;
        double total = 0;
        while (ss >> s) {
            if (s == "<" || s == "<=" || s == ">" || s == ">=" || s == "=") break;
            if (votes.find(s) != votes.end()) {
                total += votes[s];
            }
        }
        double guess;
        ss >> guess;
        if (s == "<") {
            // make sure it's less than guess
            if (total + TINY < guess) cout << "Guess #" << i + 1 << " was correct.\n";
            else cout << "Guess #" << i + 1 << " was incorrect.\n";
        } else if (s == "<=") {
            // check if it's less than or equal to guess (can expand range a bit)
            if (total <= guess + TINY) cout << "Guess #" << i + 1 << " was correct.\n";
            else cout << "Guess #" << i + 1 << " was incorrect.\n";
        } else if (s == ">") {
            if (total - TINY > guess) cout << "Guess #" << i + 1 << " was correct.\n";
            else cout << "Guess #" << i + 1 << " was incorrect.\n";
        } else if (s == ">=") {
            if (total >= guess - TINY) cout << "Guess #" << i + 1 << " was correct.\n";
            else cout << "Guess #" << i + 1 << " was incorrect.\n";
        } else if (s == "=") {
            if (total <= guess + TINY && total >= guess - TINY) cout << "Guess #" << i + 1 << " was correct.\n";
            else cout << "Guess #" << i + 1 << " was incorrect.\n";
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
