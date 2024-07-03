#include <bits/stdc++.h>

using namespace std;

string shuntingYard(string s) {
    string res;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        if (isdigit(s[i])) {
            res += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else if (s[i] == '+' || s[i] == '-') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        } else if (s[i] == '*' || s[i] == '/') {
            while (!st.empty() && st.top() != '(' && st.top() != '+' && st.top() != '-') {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string buf;
    int n;
    getline(cin, buf);
    n = stoi(buf);
    getline(cin, buf);
    for (int i = 0; i < n; i++) {
        string s;
        while (getline(cin, buf), !buf.empty()) {
            s += buf;
        }
        cout << shuntingYard(s) << endl;
        if (i != n - 1) cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
