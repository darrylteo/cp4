#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    stack<bool> s;
    vector<bool> v;
    for (int i = 0; i < n; i++) {
        bool x;
        string tmp;
        cin >> tmp;
        if (tmp == "T") x = true;
        else x = false;
        v.push_back(x);
    }
    string buf;
    getline(cin >> ws, buf);
    stringstream ss(buf);
    vector<char> v1;
    while (ss >> buf) {
        v1.push_back(buf[0]);
    }
    for (int i = 0; i < v1.size(); i++) {
        if (isalpha(v1[i])) {
            s.push(v[v1[i] - 'A']);
        } else {
            if (v1[i] == '+') {
                bool a = s.top();
                s.pop();
                bool b = s.top();
                s.pop();
                s.push(a | b);
            } else if (v1[i] == '-') {
                bool a = s.top();
                s.pop();
                s.push(!a);
            } else if (v1[i] == '*') {
                bool a = s.top();
                s.pop();
                bool b = s.top();
                s.pop();
                s.push(a & b);
            }
        }
    }
    if (s.top() == 0) {
        cout << "F" << endl;
    } else {
        cout << "T" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
