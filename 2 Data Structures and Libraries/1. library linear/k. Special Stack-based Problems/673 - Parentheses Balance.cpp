#include <bits/stdc++.h>

using namespace std;

// can reuse "entry level" code xd

void bracketSolve(string s) {
    int ans = 0, i = 0;
    stack<char> st;
    for (; i < s.size(); i++) {
        ans++;
        if (s[i] == '(' && s[i + 1] == '*') {
            st.push(s[i + 1]); // we mark * enough
            i++; // to skip *
        } else if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<') {
            st.push(s[i]);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}' || s[i] == '>' || (s[i] == '*' && s[i + 1] == ')')) {
            if (st.empty() || (s[i] == ')' && st.top() != '(') || (s[i] == ']' && st.top() != '[') ||
                (s[i] == '}' && st.top() != '{') || (s[i] == '>' && st.top() != '<') || (s[i] == '*' && st.top() != '*')) {
                break;
            } else if (s[i] == '*' && st.top() == '*') { // special case here... * enough since we checked in ifelse
                st.pop();
                i++; // skip again
            } else {
                st.pop();
            }
        }
    }

    if (i == s.size()) { // the offending bracket (if exists) is "missing"
        ans++;
    }
    if (!st.empty() || i < s.size()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string s;
    getline(cin, s);
    while (getline(cin, s)) {
        bracketSolve(s);
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
