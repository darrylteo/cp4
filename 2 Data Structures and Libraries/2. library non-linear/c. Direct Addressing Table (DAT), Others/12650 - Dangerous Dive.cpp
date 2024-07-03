#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R;
    while (cin >> N >> R) {
        if (N == R) {
            cout << "*\n";
            for (int i = 0; i < N; ++i) {
                int x;
                cin >> x;
            }
            continue;
        }
        bool alive[10001] = {};
        for (int i = 0; i < R; ++i) {
            int x;
            cin >> x;
            alive[x] = true;
        }
        for (int i = 1; i <= N; ++i) {
            if (!alive[i]) {
                cout << i << " ";
            }
        }
        cout << "\n";


    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
