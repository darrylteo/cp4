#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    while (cin >> n, n) {
        string arrangement[n];
        int current = -1, used[100] = {};
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            // we would need to move s2.size() steps, but don't count steps on used positions
            int steps = s2.size();
            while (steps--) {
                current++; if (current == n) current = 0;
                while (used[current]) {
                    current++; if (current == n) current = 0;
                }
            }
            used[current] = 1;
            arrangement[current] = s1;
        }

        for (int i = 0; i < n - 1; i++) {
            cout << arrangement[i] << " ";
        }
        cout << arrangement[n - 1] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




