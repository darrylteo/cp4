#include <bits/stdc++.h>

using namespace std;

void printRes(vector<string> &v) {
    for (string &s: v) {
        reverse(s.begin(), s.end());
    }
    int longest = 0;
    for (const string &s: v) {
        longest = max(longest, (int) s.size());
    }
    for (string &s: v) {
        while (s.size() < longest) {
            s += ' ';
        }
    }
    sort(v.begin(), v.end());
    for (string &s: v) {
        reverse(s.begin(), s.end());
    }
    for (const string& s: v) {
        cout << s << endl;
    }

}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string buf;
    vector<string> v;
    while (getline(cin, buf)) {
        // if new line, print results
        if (buf.empty()) {
            printRes(v);
            cout << endl;
            v.clear();
        } else {
            v.push_back(buf);
        }
    }
    printRes(v);

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
