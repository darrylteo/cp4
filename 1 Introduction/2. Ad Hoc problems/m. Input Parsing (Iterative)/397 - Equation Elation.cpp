#include <bits/stdc++.h>

using namespace std;

string tidyString(string s) {
    string res = "";

    // add space before and after operator if it does not exist
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '=') {
            if (res[res.size() - 1] != ' ') res += ' ';
            res += s[i];
            if (s[i + 1] != ' ') res += ' ';
        } else {
            res += s[i];
        }
    }

    // if find + after an operator, remove sign and space
    // if find - after an operator, remove space only
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == '+' || res[i] == '-' || res[i] == '*' || res[i] == '/') {
            if (res[i+2] == '+') res.erase(i+2, 2);
            if (res[i+2] == '-') res.erase(i+3, 1);
        }
    }
    return res;
}

string displaySolved(vector<string> v) {
    string res;
    for (int j = 0; j < v.size(); j++) {
        if (j == v.size() - 1) res += v[j];
        else res += v[j] + " ";
    }
    return res;
}

vector<string> stringToVector(string s) {
    stringstream ss(s);
    string tmp;
    vector<string> v;
    while (ss >> tmp) {
        v.push_back(tmp);
    }
    return v;
}

vector<string> solve(vector<string> v) {
    for (int i = 0; i < v.size(); i++){
        if (v[i] == "*") {
            int c = stoi(v[i-1]) * stoi(v[i+1]);
            v[i-1] = to_string(c);
            v.erase(v.begin() + i);
            v.erase(v.begin() + i);
            return v;
        } else if (v[i] == "/") {
            int c = stoi(v[i-1]) / stoi(v[i+1]);
            v[i-1] = to_string(c);
            v.erase(v.begin() + i);
            v.erase(v.begin() + i);
            return v;
        }
    }
    for (int i = 0; i < v.size(); i++){
        if (v[i] == "+") {
            int c = stoi(v[i-1]) + stoi(v[i+1]);
            v[i-1] = to_string(c);
            v.erase(v.begin() + i);
            v.erase(v.begin() + i);
            return v;
        } else if (v[i] == "-") {
            int c = stoi(v[i-1]) - stoi(v[i+1]);
            v[i-1] = to_string(c);
            v.erase(v.begin() + i);
            v.erase(v.begin() + i);
            return v;
        }
    }
    return v;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string line;
    string TEST;
    while (getline(cin, line)) {
        line = tidyString(line);
        TEST += line + "\n";
        vector<string> v = stringToVector(line);
        while (v.size() > 3){ // 3 means only have "number", "=", "variable"
            v = solve(v);
            TEST += displaySolved(v) + "\n";
        }
        TEST += "\n";
    }
    // dont know how to remove last "\n" so resort to manually remove it
    TEST.pop_back();
    cout << TEST;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}