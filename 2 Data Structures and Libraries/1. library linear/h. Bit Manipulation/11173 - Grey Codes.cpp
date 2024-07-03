#include <bits/stdc++.h>

using namespace std;

// https://en.wikipedia.org/wiki/Gray_code

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x >> x;
        cout << (x ^ (x >> 1)) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}