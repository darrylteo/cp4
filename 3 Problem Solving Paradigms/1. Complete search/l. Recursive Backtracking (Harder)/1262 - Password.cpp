#include <bits/stdc++.h>

using namespace std;

// small notes:
// there may be repeat letters in the 6 char column. i opted to use set to remove repeats but thinking again, the set should be vector<set<char>> v1,v2 instead and just count numPasswords
// the flags make code hard to read. try to improve on this
// multiple WA when if(passwords.size() == K) was outside the idx==5 loop. because check on a separate loop from the password generated and inserted loop

int K, flag;
set<vector<char>> passwords;
vector<char> password;
vector<vector<char>> v1, v2;

int dfs(int idx) {
    if (idx == 5) {
        passwords.insert(password);
        if (passwords.size() == K) {
            vector<char> tmp = *passwords.rbegin();
            for (int i = 0; i < 5; ++i) {
                cout << tmp[i];
            }
            cout << endl;
            flag = 1;
            return 1;
        }
        return 0;
    }
    vector<char> line1 = v1[idx], line2 = v2[idx];
    for (int i = 0; i < 6; ++i) {
        if (flag) {
            return 1;
        }
        if (find(line1.begin(), line1.end(), line2[i]) != line1.end()) {
            password.push_back(line2[i]);
            dfs(idx + 1);
            password.pop_back();
        }
    }
    if (flag) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> K;
        flag = 0;
        v1.clear();
        v1.resize(5);
        v2.clear();
        v2.resize(5);
        passwords.clear();
        for (int i = 0; i < 6; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < 5; ++j) {
                v1[j].push_back(s[j]);
            }
        }
        for (int i = 0; i < 6; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < 5; ++j) {
                v2[j].push_back(s[j]);
            }
        }
        // sort each vector within v1 and v2 so we generate the answer alphabetically
        for (int i = 0; i < 5; ++i) {
            sort(v1[i].begin(), v1[i].end());
            sort(v2[i].begin(), v2[i].end());
        }
        if (!dfs(0)) {
            cout << "NO" << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

