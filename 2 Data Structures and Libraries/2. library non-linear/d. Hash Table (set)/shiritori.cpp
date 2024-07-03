#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_set<string> s;
    string curr, prev;
    cin >> curr;
    prev = curr;
    s.insert(curr);
    for (int i = 1; i < n; ++i) {
        cin >> curr;
        if (s.insert(curr).second) { // not repeated word
            if (prev.back() != curr.front()) { // check if linked
                if (i % 2 == 0) {
                    cout << "Player 1 lost";
                    return 0;
                } else {
                    cout << "Player 2 lost";
                    return 0;
                }
            }
        } else {
            if (i % 2 == 0) {
                cout << "Player 1 lost";
                return 0;
            } else {
                cout << "Player 2 lost";
                return 0;
            }
        }
        prev = curr;
    }
    cout << "Fair Game" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
