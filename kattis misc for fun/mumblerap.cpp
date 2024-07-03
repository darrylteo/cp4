#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s >> s;
    int best = 0;
    string curr = "0";
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            curr += s[i];
        } else {
            if (stoi(curr) > best) best = stoi(curr);
            curr = "0";
        }
    }
    if (stoi(curr) > best) best = stoi(curr);
    cout << best << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}