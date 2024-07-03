#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, x, sum = 0;
    cin >> n >> x;
    while (n--) {
        int a;
        cin >> a;
        sum += a;
    }
    if (x >= sum) cout << "Jebb" << endl;
    else cout << "Neibb" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




