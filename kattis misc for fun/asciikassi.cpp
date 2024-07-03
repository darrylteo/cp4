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
    cout << '+' << string(n, '-') << '+' << endl;
    for (int i = 0; i < n; ++i) {
        cout << '|' << string(n, ' ') << '|' << endl;
    }
    cout << '+' << string(n, '-') << '+' << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
