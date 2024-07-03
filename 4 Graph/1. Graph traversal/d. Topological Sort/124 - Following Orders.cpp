#include <bits/stdc++.h>

using namespace std;

vector<int> adjList[30];
vector<char> letters, ans;
int used[30];

void dfs(int u) {
    // make sure this letter is smaller than all remaining letters before we add it to the answer
    // i.e. nothing unused points to this letter
    for (int i = 0; i < letters.size(); ++i) {
        if (used[letters[i] - 'a']) {
            continue;
        }
        for (int j : adjList[letters[i] - 'a']) {
            if (j == letters[u] - 'a') { // letters[i] points to letters[u] (i.e. letters[i] < letters[u])
                return;
            }
        }
    }

    ans.push_back(letters[u]);
    used[letters[u] - 'a'] = 1;

    if (ans.size() == letters.size()) {
        for (char c : ans) {
            cout << c;
        }
        cout << "\n";
    } else {
        for (int i = 0; i < letters.size(); ++i) {
            int newLetterInt = letters[i] - 'a';
            if (used[newLetterInt]) {
                continue;
            } else {
                dfs(i);
            }
        }
    }

    ans.pop_back();
    used[letters[u] - 'a'] = 0;
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
    while (true) {
        // clear
        for (int i = 0; i < 30; ++i) {
            adjList[i].clear();
            used[i] = 0;
        }
        letters.clear();
        ans.clear();
        // get input
        stringstream ss(buf);
        char c;
        while (ss >> c) {
            letters.push_back(c);
        }
        getline(cin, buf);
        stringstream ss2(buf);
        char s1, s2;
        while (ss2 >> s1 >> s2) {
            adjList[s1 - 'a'].push_back(s2 - 'a');
        }
        // solve
        sort(letters.begin(), letters.end());
        for (int i = 0; i < letters.size(); ++i) {
            dfs(i);
        }
        // get next input
        if (!getline(cin, buf)) {
            break;
        }
        cout << "\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



