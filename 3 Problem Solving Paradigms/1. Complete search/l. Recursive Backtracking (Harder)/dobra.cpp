#include <bits/stdc++.h>

using namespace std;

// reduce problem to consonants, vowels, and L. as c, v, l
// since only max 10 _, can brute force 3^10 = 59049
// max 10 means ans can be up to 20^10. need long long. bruh moment keeps happening to me

long long ans = 0;
string s, lettersAdded;

bool checkString() {
    if (s.find('l') == string::npos) {
        return false;
    }
    if (s.size() < 3) {
        return true;
    }
    int pass = 1;
    if (s.size() == 3) {
        string tmp = s.substr(0, 3);
        // all vowel or all consonant
        if (tmp == "vvv" || tmp.find('v') == string::npos) {
            pass = 0;
        }
    }
    for (int i = 0; i < s.size() - 2; ++i) {
        string tmp = s.substr(i, 3);
        if (tmp == "vvv" || tmp.find('v') == string::npos) {
            pass = 0;
            break;
        }
    }
    return pass;
}

long long valAdded() {
    long long val = 1;
    for (char &c: lettersAdded) {
        if (c == 'c') {
            val *= 20; // excl. l
        } else if (c == 'v') {
            val *= 5;
        }
    }
    return val;
}

void dfs(int idx) {
    if (idx == s.size()) {
        if (!checkString()) {
            return;
        }
        ans += valAdded();
        return;
    }
    if (s[idx] == '_') {
        for (char c: {'c', 'v', 'l'}) {
            lettersAdded += c;
            s[idx] = c;
            dfs(idx + 1);
            lettersAdded.pop_back();
            s[idx] = '_';
        }
    } else {
        dfs(idx + 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    for (char &c: s) {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            c = 'v';
        } else if (c == 'L') { // also a consonant
            c = 'l';
        } else if (c == '_') {
            continue;
        } else {
            c = 'c';
        }
    }
    dfs(0);
    cout << ans << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

