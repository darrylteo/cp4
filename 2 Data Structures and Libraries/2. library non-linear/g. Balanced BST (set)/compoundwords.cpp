#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> v;
    string s;
    while (cin >> s) {
        v.push_back(s);
    }
    set<string> st;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            st.insert(v[i] + v[j]);
            st.insert(v[j] + v[i]);
        }
    }
    for (auto i : st) {
        cout << i << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

