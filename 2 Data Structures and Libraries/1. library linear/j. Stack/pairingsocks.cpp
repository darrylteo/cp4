#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, swaps = 0;
    cin >> n;
    n *= 2;
    stack<int> s1, s2;
    while (n--) {
        int x;
        cin >> x;
        s1.push(x);
    }
    while (!s1.empty()) {
        if (!s2.empty()) {
            if (s1.top() == s2.top()) {
                s1.pop();
                s2.pop();
                swaps++;
            } else {
                s2.push(s1.top());
                s1.pop();
                swaps++;
            }
        } else {
            s2.push(s1.top());
            s1.pop();
            swaps += 1;
        }
    }
    if (!s2.empty()) {
        cout << "impossible" << endl;
    } else {
        cout << swaps << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
