#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string buf;
    unordered_map<string, int> wordToInt;
    while (getline(cin, buf)) {
        if (buf[0] == 'd') {
            stringstream ss(buf);
            string s;
            ss >> s >> s;
            int Int;
            ss >> Int;
            wordToInt[s] = Int;
        } else if (buf[0] == 'c' && buf[1] == 'a') {
            stringstream ss(buf);
            int LHS = 0;
            string currSign = "+";
            string s;
            ss >> s; // don't read the word "calc"
            while (ss >> s) {
                cout << s << " ";
                if (s == "+" || s == "-") {
                    currSign = s;
                } else if (s == "=") {
                    break;
                } else {
                    if (currSign == "+") {
                        if (wordToInt.find(s) == wordToInt.end()) {
                            LHS += 1000000;
                        } else {
                            LHS += wordToInt[s];
                        }
                    } else {
                        if (wordToInt.find(s) == wordToInt.end()) {
                            LHS += 1000000;
                        } else {
                            LHS -= wordToInt[s];
                        }
                    }
                }
            }
            bool found = false;
            for (auto &it : wordToInt) {
                if (it.second == LHS) {
                    cout << it.first << "\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "unknown\n";
            }

        } else {
            wordToInt.clear();
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
