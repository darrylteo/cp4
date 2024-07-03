#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> ans;
    string s;
    cin >> s;
    vector<int> openBrackets, closeBrackets;
    // use stack find all pairs of brackets
    stack<int> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (st.empty()) {
                continue;
            }
            openBrackets.push_back(st.top());
            closeBrackets.push_back(i);
            st.pop();
        }
    }

    int noPairs = openBrackets.size();
    // start from 1 else we repeat original case
    for (int i = 1; i < 1 << noPairs; ++i) {
        string tmp;
        // get pair(s) of brackets to remove
        vector<int> removeChars;
        for (int j = 0; j < noPairs; ++j) {
            if (i & (1 << j)) {
                removeChars.push_back(openBrackets[j]);
                removeChars.push_back(closeBrackets[j]);
            }
        }

        // remove the brackets
        for (int j = 0; j < s.size(); ++j) {
            if (find(removeChars.begin(), removeChars.end(), j) == removeChars.end()) {
                tmp += s[j];
            }
        }

        ans.push_back(tmp);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (auto &i : ans) {
        cout << i << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}