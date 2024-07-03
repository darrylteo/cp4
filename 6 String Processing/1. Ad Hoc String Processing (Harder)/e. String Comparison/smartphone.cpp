#include <bits/stdc++.h>

using namespace std;

int getPenalty(string a, string b) {
    int matches = 0;
    while (matches < a.size() && matches < b.size()) {
        if (a[matches] != b[matches]) break;
        matches++;
    }
    return a.size() - matches + b.size() - matches;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string ori;
        cin >> ori;
        int best = INT_MAX;
        string curr;
        cin >> curr;
        best = min(best, getPenalty(curr, ori));
        int cas = 3;
        while (cas--) {
            cin >> curr;
            best = min(best, getPenalty(curr, ori) + 1);
        }
        cout << best << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

