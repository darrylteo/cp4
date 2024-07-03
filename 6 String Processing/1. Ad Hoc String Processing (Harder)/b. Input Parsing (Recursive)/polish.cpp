#include <bits/stdc++.h>

using namespace std;

bool isNum(string s) {
    if (s.size() == 1 && !isdigit(s[0])) return false;
    return true;
}

bool isOp(string s) {
    if (s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*')) return true;
    return false;
}

// tried lame ole stack but kept running into runtime error
// surprised brute force worked

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf;
    int cases = 1;
    while (getline(cin, buf)) {
        cout << "Case " << cases++ << ": ";
        vector<string> curr, prev;
        stringstream ss(buf);
        string s;
        while (ss >> s) {
            curr.push_back(s);
        }
        int change = 1;
        while (change) {
            change = 0;
            prev = curr;
            curr.clear();
            for (int i = 0; i < prev.size(); i++) {
                if (isOp(prev[i])) {
                    if (i + 2 < prev.size() && isNum(prev[i + 1]) && isNum(prev[i + 2])) {
                        if (prev[i][0] == '+') {
                            curr.push_back(to_string(stoi(prev[i + 1]) + stoi(prev[i + 2])));
                        } else if (prev[i][0] == '-') {
                            curr.push_back(to_string(stoi(prev[i + 1]) - stoi(prev[i + 2])));
                        } else if (prev[i][0] == '*') {
                            curr.push_back(to_string(stoi(prev[i + 1]) * stoi(prev[i + 2])));
                        }
                        change = 1;
                        i += 2;
                    } else {
                        curr.push_back(prev[i]);
                    }
                } else {
                    curr.push_back(prev[i]);
                }
            }
        }
        for (int i = 0; i < curr.size(); i++) {
            cout << curr[i] << " ";
        }
        cout << endl;
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

