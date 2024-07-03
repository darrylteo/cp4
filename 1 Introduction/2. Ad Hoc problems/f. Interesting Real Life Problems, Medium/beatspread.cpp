#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--){
        long long s, d;
        cin >> s >> d;
        if (s < d || (s + d) % 2 != 0 || (s - d) % 2 != 0) cout << "impossible" << endl;
        else cout << (s + d) / 2 << " " << (s - d) / 2 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
