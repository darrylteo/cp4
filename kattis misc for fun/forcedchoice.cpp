#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, P, S;
    cin >> N >> P >> S;
    while (S--) {
        int n, flag = 0;
        cin >> n;
        while (n--) {
            int x;
            cin >> x;
            if (x == P) flag = 1;
        }
        if (flag) cout << "KEEP\n";
        else cout << "REMOVE\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}