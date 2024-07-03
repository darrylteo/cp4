#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    set<char> st;
    bool flag = false;
    for (char c : s) {
        if (!st.insert(c).second) {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << 0;
    } else {
        cout << 1;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

