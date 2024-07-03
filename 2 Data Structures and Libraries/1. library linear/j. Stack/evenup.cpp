#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    stack<int> s;
    while (n--) {
        int x;
        cin >> x;
        if (!s.empty() && (s.top() + x) % 2 == 0) {
            s.pop();
        } else {
            s.push(x);
        }
    }
    cout << s.size() << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
