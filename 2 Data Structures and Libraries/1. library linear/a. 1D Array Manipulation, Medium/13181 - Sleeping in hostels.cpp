#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string s;
    while (cin >> s) {
        int count = 0, mmax = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                count++;
            } else {
                if (count > mmax) {
                    mmax = count;
                }
                count = 0;
            }
        }
        int inBetween = (mmax - 1) / 2;

        // check from left and right (since the space is larger if you sleep in corner)
        int countL = 0, countR = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') countL++;
            else break;
        }
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == '.') countR++;
            else break;
        }

        mmax  = max(inBetween, max(countL - 1, countR - 1));

        cout << mmax << endl;

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
