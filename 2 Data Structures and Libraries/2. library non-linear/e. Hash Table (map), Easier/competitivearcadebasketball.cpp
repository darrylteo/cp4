#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, m;
    cin >> n >> p >> m;
    unordered_map<string, int> scores;
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        scores[name] = 0;
    }
    bool win = false;
    for (int i = 0; i < m; ++i) {
        string name;
        int score;
        cin >> name >> score;
        scores[name] += score;
        if (scores[name] >= p) {
            cout << name << " wins!" << endl;
            win = true;
            scores[name] = INT_MIN; // can't win twice
        }
    }
    if (!win) {
        cout << "No winner!" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
