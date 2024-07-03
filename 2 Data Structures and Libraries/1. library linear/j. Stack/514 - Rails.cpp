#include <bits/stdc++.h>

using namespace std;

// troublesome input format... qn not hard but take long time to format !!

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, flag = 0;
    cin >> n;
    while (true) {
        stack<int> s;
        vector<int> v;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                cin >> n;
                if (n == 0) {
                    cout << endl;
                    return 0;
                }
                cout << endl;
                flag = 1;
                break;
            }
            v.push_back(x);
            flag = 0;
        }
        if (flag) continue;
        for (int i = 1, j = 0; i <= n; i++) {
            s.push(i);
            while (!s.empty() && s.top() == v[j]) {
                s.pop();
                j++;
            }
        }
        if (s.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
