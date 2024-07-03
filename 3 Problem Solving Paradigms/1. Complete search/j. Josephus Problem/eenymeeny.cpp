#include <bits/stdc++.h>

using namespace std;

// straightforward except for the way they start counting
// see diagram, it start from middle so i take eeny - 1

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string buf;
    getline(cin, buf);
    int n, eeny = 1;
    for (char c : buf) {
        if (c == ' ') {
            ++eeny;
        }
    }

    cin >> n;
    vector<string> all, team0, team1;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        all.push_back(s);
    }
    int team = 0, idx = 0;
    while(!all.empty()) {
        idx = (idx + eeny - 1) % all.size();
        if (!team) team0.push_back(all[idx]);
        else team1.push_back(all[idx]);
        all.erase(all.begin() + idx);
        team = !team;
    }

    cout << team0.size() << endl;
    for (string s : team0) {
        cout << s << endl;
    }
    cout << team1.size() << endl;
    for (string s : team1) {
        cout << s << endl;
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

