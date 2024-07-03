#include <bits/stdc++.h>

using namespace std;

bool isOp(const string &s1) {
    if (s1 == "+" || s1 == "-" || s1 == "*" || s1 == "/" || s1 == "(" || s1 == ")") {
        return true;
    }
    return false;
}

// exclude ')' since if a - sign comes after that it's "normal"... not a necessarily negative number.
bool isOp2(const string &s1) {
    if (s1 == "+" || s1 == "-" || s1 == "*" || s1 == "/" || s1 == "(") {
        return true;
    }
    return false;
}

bool isNum(const string &s1) {
    if (isOp(s1) || s1.empty()) {
        return false;
    }
    return true;
}

vector<string> shuntingYard(vector<string> s) {
    vector<string> res;
    stack<string> st;
    for (int i = 0; i < s.size(); i++) {
        if (isNum(s[i])) {
            res.push_back(s[i]);
        } else if (s[i] == "(") {
            st.push(s[i]);
        } else if (s[i] == ")") {
            while (!st.empty() && st.top() != "(") {
                res.push_back(st.top());
                st.pop();
            }
            st.pop();
        } else if (s[i] == "+" || s[i] == "-") {
            while (!st.empty() && st.top() != "(") {
                res.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        } else if (s[i] == "*" || s[i] == "/") {
            while (!st.empty() && st.top() != "(" && st.top() != "+" && st.top() != "-") {
                res.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

string removeSpaces(string s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            res += s[i];
        }
    }
    // for cases such as 3 / -(3 + 23) or -(-(5+3))
    for (int i = 0; i < res.size() - 1; i++) {
        if (res[i] == '-' && res[i+1] == '(' && res[i-1] == '/') {
            res.insert(i + 1, "1/");
            i++;
        } else if (res[i] == '-' && res[i+1] == '(') {
            res.insert(i + 1, "1*");
            i++;
        }
    }
    return res;
}

// process the string into a vector of numbers and operators. necessary to catch negative numbers and numbers with more than one digit
vector<string> process(string s) {
    vector<string> res;
    string num;
    for (int i = 0; i < s.size(); i++) {
        // IF ((operator) AND (NOT a negative sign related to a number)) THEN (add curr num and operator to res) ELSE (add curr num to num)
        if (isOp(string(1, s[i])) && !((s[i] == '-' && isOp2(string(1, s[i - 1]))) || (s[i] == '-' && i == 0))) {
            if (!num.empty()) {
                res.push_back(num);
                num.clear();
            }
            res.emplace_back(1, s[i]);
        } else {
            num += s[i];
        }
    }
    if (!num.empty()) {
        res.push_back(num);
    }
    return res;
}

double eval(const vector<string> &s) {
    stack<double> st;
    for (const auto &i: s) {
        if (isNum(i)) {
            st.push(stod(i));
        } else {
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            if (i == "+") {
                st.push(b + a);
            } else if (i == "-") {
                st.push(b - a);
            } else if (i == "*") {
                st.push(b * a);
            } else if (i == "/") {
                st.push(b / a);
            }
        }
    }
    return st.top();
}

// reuse code from 727 - Equation for shunting yard
// in python u can just eval() but c++ need implement it urself :S
// pretty sure the rating would be around hard if implement urself?? or is there a shortcut...
// was wondering if bracket matching and evaluate whenever u close a bracket would work.

// direct copy paste code from kattis - calculator (except this qn actually doesn't have brackets)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf;
    while (getline(cin, buf)) {
        string s = removeSpaces(buf);
        vector<string> v = process(s);
        vector<string> res = shuntingYard(v);
        double ans = eval(res);
        cout << fixed << setprecision(3) << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

