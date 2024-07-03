#include <bits/stdc++.h>

using namespace std;

vector<string> process(const string &s) {
    vector<string> res;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        while (word[0] == '(' && word.size() > 1) {
            res.emplace_back("(");
            word = word.substr(1);
        }
        int cnt = 0;
        while (word.back() == ')' && word.size() > 1) {
            word = word.substr(0, word.size() - 1);
            cnt++;
        }
        res.push_back(word);
        while (cnt--) {
            res.emplace_back(")");
        }
    }
    return res;
}

double solve(const vector<string> &v) {
    stack<string> st;
    for (const string &s: v) {
        if (s == ")") {
            vector<string> tmp;
            while (st.top() != "(") {
                tmp.push_back(st.top());
                st.pop();
            }
            st.pop();
            // should be 3 strings in tmp
            double p = stod(tmp[2]), e1 = stod(tmp[1]), e2 = stod(tmp[0]);
            st.push(to_string(p * (e1 + e2) + (1 - p) * (e1 - e2)));
        } else {
            st.push(s);
        }
    }
    return stod(st.top());
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf;
    while (getline(cin, buf), buf != "()") {
        vector<string> v = process(buf);
        cout << fixed << setprecision(2) << solve(v) << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

