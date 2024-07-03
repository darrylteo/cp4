#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int gsum = 0, esum = 0;
    for (int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        if (i < 4) gsum += x;
        else esum+=x;
    }
    if (gsum > esum) cout << "Gunnar";
    else if (gsum < esum) cout << "Emma";
    else cout << "Tie";


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}