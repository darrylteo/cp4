#include <bits/stdc++.h>

using namespace std;

// strategy:
// drop plates on 2, shift all to 1 whenever it is empty
// always take from 1

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    while (cin >> n, n) {
        string s;
        int x, stack1 = 0, stack2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> s >> x;
            if (s == "DROP") {
                cout << "DROP 2 " << x << endl;
                stack2 += x;
            } else {
                if (x <= stack1) {
                    stack1 -= x;
                    cout << "TAKE 1 " << x << endl;
                } else {
                    if (stack1 > 0) {
                        x -= stack1;
                        cout << "TAKE 1 " << stack1 << endl;
                    }
                    stack1 = 0;
                    cout << "MOVE 2->1 " << stack2 << endl;
                    stack1 = stack2;
                    stack2 = 0;
                    cout << "TAKE 1 " << x << endl;
                    stack1 -= x;
                }
            }
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
