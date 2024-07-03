#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> letters(26, 0);
    string s;
    cin >> s;
    int total = 0;
    for (char c: s) {
        if (letters[c - 'A'] == 0) total++;
        letters[c - 'A']++;
    }
    cin >> s;
    int cnt = 0, life = 10;
    for (char c: s) {
        if (life == 0) break;
        if (letters[c - 'A'] > 0) cnt++;
        else life--;
    }
    if (cnt == total) cout << "WIN\n";
    else cout << "LOSE\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
