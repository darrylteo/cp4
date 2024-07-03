#include <bits/stdc++.h>

using namespace std;

// invalid if not in the form ?M?E? where 1 or more ?'s
bool isValid(string s) {
    if (s.size() < 3) {
        return false;
    }
    if (s[0] != '?' || s[s.size() - 1] != '?') {
        return false;
    }
    int foundM = 0, foundE = 0;
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == 'M') {
            foundM++;
        } else if (s[i] == 'E') {
            foundE++;
        } else if (s[i] != '?') {
            return false;
        }
    }
    if (foundM != 1 || foundE != 1) {
        return false;
    }
    return true;
}

// check if is axiom
bool isTheorem(const string& s) {
    if (!isValid(s)) {
        return false;
    }
    int cntLeft = 0, cntMid = 0, cntRight = 0;
    bool foundM = false, foundE = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?' && !foundM) {
            cntLeft++;
        } else if (s[i] == 'M') {
            foundM = true;
        } else if (s[i] == '?' && foundM && !foundE) {
            cntMid++;
        } else if (s[i] == 'E') {
            foundE = true;
        } else if (s[i] == '?' && foundE) {
            cntRight++;
        }
    }
    // is axiom
    if (cntLeft + 1 == cntRight && cntMid == 1) {
        return true;
    }
    // is theorem
    if (cntRight - cntLeft == cntMid && cntMid > 0) {
        return true;
    }

    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    while(n--) {
        cin >> s;
        if (isTheorem(s)) {
            cout << "theorem" << endl;
        } else {
            cout << "no-theorem" << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
