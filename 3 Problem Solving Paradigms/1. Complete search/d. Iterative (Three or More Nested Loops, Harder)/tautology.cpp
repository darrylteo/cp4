#include <bits/stdc++.h>

using namespace std;

// doing recursion since u can bracket and bracket until A(SOLVE THIS)(SOLVE THIS)
// decent practice for recursion

bitset<5> b;
string s;
int idx;

bool solve() {
    // last value will always be small letter
    if (s[idx] == 'p') return b[0];
    if (s[idx] == 'q') return b[1];
    if (s[idx] == 'r') return b[2];
    if (s[idx] == 's') return b[3];
    if (s[idx] == 't') return b[4];

    // follow table
    // we have to solve recursively the first item, which shifts the idx ptr to end of first item
    // then solve second item
    if (s[idx] == 'K') {
        idx++;
        bool a1 = solve();
        idx++;
        bool a2 = solve();
        return a1 && a2;
    }
    if (s[idx] == 'A') {
        idx++;
        bool a1 = solve();
        idx++;
        bool a2 = solve();
        return a1 || a2;
    }
    if (s[idx] == 'N') {
        idx++;
        bool a1 = solve();
        return !a1;
    }
    if (s[idx] == 'C') {
        idx++;
        bool a1 = solve();
        idx++;
        bool a2 = solve();
        return !a1 || a2;
    }
    if (s[idx] == 'E') {
        idx++;
        bool a1 = solve();
        idx++;
        bool a2 = solve();
        return a1 == a2;
    }

    // should never reach here
    return false;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> s, s != "0") {
        // 2^5 permutations for w x
        bool flag = true; // must be all true
        for (int i = 0; i < 32; i++) {
            idx = 0;
            b = i;
            if (!solve()) {
                cout << "not" << endl;
                flag = false;
                break;
            }
        }
        if (flag) cout << "tautology" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
