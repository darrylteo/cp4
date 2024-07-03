#include <bits/stdc++.h>

using namespace std;

string shuntingYard(string s) {
    string res;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        if (isalpha(s[i])) {
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

int solve(string eqn, vector<int> vals, map<char, int> m) {
    stack<int> st;
    for (char c: eqn) {
        if (isalpha(c)) {
            st.push(vals[m[c]]);
        } else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
        }
    }
    return st.top();
}

// shunting from uva 727 - Equation
// feels like a 4.0 problem...

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        vector<int> vals(n);
        for (int i = 0; i < n; i++) cin >> vals[i];
        int ans;
        cin >> ans;
        sort(vals.begin(), vals.end());
        string s;
        cin >> s;
        string eqn = shuntingYard(s);
        int found = 0;
        map<char, int> m;
        int idx = 0;
        for (char c: eqn) { // map the variables to their index
            if (isalpha(c)) m[c] = idx++;
        }
        do {
            int curr = solve(eqn, vals, m);
            if (curr == ans) {
                found = 1;
                break;
            }
        } while (next_permutation(vals.begin(), vals.end()));
        if (found) cout << "YES\n";
        else cout << "NO\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
