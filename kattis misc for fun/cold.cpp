#include <bits/stdc++.h>

using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, cnt = 0;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (a < 0) cnt++;
    }
    cout << cnt << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}