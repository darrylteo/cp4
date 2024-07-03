#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        x--;
        if (a[x] != "?") {
            cout << a[x] << endl;
        } else {
            int l = 0, r = 0;
            bool left = false, right = false; // if left or right guy exists
            for (int i = x - 1; i >= 0; i--) {
                if (a[i] != "?") {
                    l = i;
                    left = true;
                    break;
                }
            }
            for (int i = x + 1; i < n; i++) {
                if (a[i] != "?") {
                    r = i;
                    right = true;
                    break;
                }
            }
            // fix cases when x at the end or start or not found
            if (x==0 || !left) l = -1000;
            if (x==n-1 || !right) r = 1000;

            int actualR = r, actualL = l;
            l = x - l;
            r = r - x;

            if (l == r) {
                cout << "middle of " << a[actualL] << " and " << a[actualR] << endl;
            } else if (l > r) { // closer to right guy
                while (r--) {
                    cout << "left of ";
                }
                cout << a[actualR] << endl;
            } else { // closer to left guy
                while (l--) {
                    cout << "right of ";
                }
                cout << a[actualL] << endl;
            }

        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




