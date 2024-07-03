#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, cnt = 0;
    cin >> a >> b >> c;
    int day = b + c - 14;
    while (a--) {
        int x;
        cin >> x;
        if (x <= day) cnt++;
    }
    cout << cnt << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



