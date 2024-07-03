#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<string> dict, sorted_dict;
    string s;
    while (cin >> s, s != "XXXXXX") {
        dict.push_back(s);
    }
    sort(dict.begin(), dict.end()); // so that is already alphabetical
    for (string &d : dict) {
        string t = d;
        sort(t.begin(), t.end());
        sorted_dict.push_back(t);
    }
    while (cin >> s, s != "XXXXXX") {
        sort(s.begin(), s.end());
        int found = 0;
        for (int i = 0; i < dict.size(); i++) {
            if (sorted_dict[i] == s) {
                cout << dict[i] << '\n';
                found = 1;
            }
        }
        if (!found) {
            cout << "NOT A VALID WORD\n";
        }
        cout << "******\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
