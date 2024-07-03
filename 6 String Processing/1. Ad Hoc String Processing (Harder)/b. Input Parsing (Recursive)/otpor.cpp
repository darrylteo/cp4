#include <bits/stdc++.h>

using namespace std;

vector<double> v;

string eval(vector<string> tmp) {
    string res;
    int series = 0;
    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] == "-") {
            series = 1;
            break;
        }
    }
    double ans = 0;
    if (series) {
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i][0] == 'R') {
                int idx = stoi(tmp[i].substr(1));
                ans += v[idx - 1];
            } else if (isdigit(tmp[i][0])){
                ans += stod(tmp[i]);
            }
        }
    } else {
        double denom = 0;
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i][0] == 'R') {
                int idx = stoi(tmp[i].substr(1));
                denom += 1.0 / v[idx - 1];
            } else if (isdigit(tmp[i][0])){
                denom += 1.0 / stod(tmp[i]);
            }
        }
        ans = 1.0 / denom;
    }
    return to_string(ans);
}

// "Inside of a pair of brackets, there will not be the character ‘-’ and the character ‘|’ at the same time." - quite a key point save alot steps
// remember to use vector of doubles
// i might've been able to parse the previous question kattis - calculator using the idea from this qn...

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    string exp;
    cin >> exp;
    stack<string> s;
    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] == 'R') {
            string tmp;
            tmp += exp[i];
            tmp += exp[i + 1];
            s.push(tmp);
            i++;
        } else if (isdigit(exp[i])) {
            string tmp;
            int j = i;
            while (j < exp.size() && isdigit(exp[j])) {
                tmp += exp[j];
                j++;
            }
            i = j - 1;
            s.push(tmp);
        } else if (exp[i] == ')') {
            vector<string> tmp;
            while (s.top() != "(") {
                tmp.push_back(s.top());
                s.pop();
            }
            s.pop();
            string res = eval(tmp);
            s.push(res);
        } else {
            string tmp;
            tmp += exp[i];
            s.push(tmp);
        }
    }
    cout << eval({s.top()}) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

