#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        int x;
        cin >> x;
        if (x == b) {
            if (i == 0) cout << "fyrst";
            else if (i == 1) cout << "naestfyrst";
            else cout << i + 1 << " fyrst";
            return 0;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
