#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    stack<string> st;
    while (n--) {
        string s;
        cin >> s;
        if (s == "Sleep") {
            cin >> s;
            st.push(s);
        } else if (s == "Kick") {
            if (!st.empty()) {
                st.pop();
            }
        } else {
            if (st.empty()) {
                cout << "Not in a dream" << endl;
            } else {
                cout << st.top() << endl;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
