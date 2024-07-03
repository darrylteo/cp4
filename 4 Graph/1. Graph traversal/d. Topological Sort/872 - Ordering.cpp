#include <bits/stdc++.h>

using namespace std;

vector<int> adjList[30];
vector<char> letters, ans;
int used[30], ansFound = 0;

void dfs(int u) {
    // make sure this letter is smaller than all remaining letters before we add it to the answer
    // i.e. nothing unused points to this letter
    for (int i = 0; i < letters.size(); ++i) {
        if (used[letters[i] - 'A']) {
            continue;
        }
        for (int j : adjList[letters[i] - 'A']) {
            if (j == letters[u] - 'A') { // letters[i] points to letters[u] (i.e. letters[i] < letters[u])
                return;
            }
        }
    }

    ans.push_back(letters[u]);
    used[letters[u] - 'A'] = 1;

    if (ans.size() == letters.size()) {
        ansFound = 1;
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i];
            if (i != ans.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    } else {
        for (int i = 0; i < letters.size(); ++i) {
            int newLetterInt = letters[i] - 'A';
            int prevLetterInt = letters[u] - 'A';
            if (used[newLetterInt]) {
                continue;
            } else {
                dfs(i);
            }
        }
    }

    ans.pop_back();
    used[letters[u] - 'A'] = 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    string buf;
    getline(cin, buf);
    T = stoi(buf);
    while (T--) {
        // clear
        for (int i = 0; i < 30; ++i) {
            adjList[i].clear();
            used[i] = 0;
        }
        letters.clear();
        ans.clear();
        // get input
        getline(cin, buf);
        getline(cin, buf);
        stringstream ss(buf);
        char c;
        while (ss >> c) {
            letters.push_back(c);
        }
        getline(cin, buf);
        stringstream ss2(buf);
        string s;
        while (ss2 >> s) {
            adjList[s[0] - 'A'].push_back(s[2] - 'A');
        }
        // solve
        ansFound = 0;
        sort(letters.begin(), letters.end());
        for (int i = 0; i < letters.size(); ++i) {
            dfs(i);
        }
        if (!ansFound) {
            cout << "NO\n";
        }
        if (T) {
            cout << "\n";
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



