#include <bits/stdc++.h>

using namespace std;

#define maxn 205

int grundy[maxn];
bool vis[maxn];
string s;
vector<int> ANS;
vector<int> INTERVAL;

int dfs(int n) {
    if (n <= 0) return 0;
    if(vis[n]) return grundy[n];
    vis[n]=1;
    bool ok[maxn];
    memset(ok, 0, sizeof(ok));
    for (int i = 1; i <= n; i++) {
        int l = dfs(i - 3); // curr pos and 2 left to it cannot be used else next guy will win
        int r = dfs(n - i - 2); // same but for right
        ok[l ^ r] = true;
        // https://cp-algorithms.com/game_theory/sprague-grundy-nim.html#crosses-crosses also uses xor idk why
    }
    for (int i = 0; i < maxn; i++) { // search until get mex
        if (!ok[i]) return grundy[n] = i;
    }
    return -1;
}

bool solve(int pos) {
    // do the obvious first, check if he will win by putting X here, or will it give opponent sure win next turn
    s[pos] = 'X';
    for (int i = 0; i < s.size() - 2; i++) {
        if (s[i] == 'X' && s[i + 1] == 'X' && s[i + 2] == 'X') {
            s[pos] = '.';
            return true;
        }
    }
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'X' && s[i + 1] == 'X') {
            s[pos] = '.';
            return false;
        }
    }
    for (int i = 0; i < s.size() - 2; i++) {
        if (s[i] == 'X' && s[i + 2] == 'X') {
            s[pos] = '.';
            return false;
        }
    }

    INTERVAL.clear();
    int now = 0;
    for (char c: s) {
        if (c == '.') now++;
        else {
            INTERVAL.push_back(now);
            now = 0;
        }
    }
    // e.g. .....X.....X.....
    // the middle interval only 1 spot to put X, while side intervals have 3 spots each even though all same length
    INTERVAL.push_back(now);
    INTERVAL[0] += 2;
    INTERVAL[INTERVAL.size() - 1] += 2;

    int XOR = 0;
    for (int i: INTERVAL) if (i - 4 >= 0) XOR ^= grundy[i - 4];
    s[pos] = '.';
    return XOR == 0;
}

// more info on nim: https://web.mit.edu/sp.268/www/nim.pdf (SG function defined here)
// ref: https://github.com/AnikSarker/UVA-Online-Judge-solutions/blob/master/UVA%2010561%20-%20Treblecross

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 1; i < maxn; i++) dfs(i);
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        ANS.clear();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'X') continue;
            if (solve(i)) ANS.push_back(i + 1);
        }
        if (ANS.empty()) cout << "LOSING\n";
        else {
            cout << "WINNING\n";
            for (int i = 0; i < ANS.size(); i++) {
                cout << ANS[i];
                if (i != ANS.size() - 1) cout << " ";
            }
        }
        cout << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
