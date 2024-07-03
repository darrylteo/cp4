#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W, H;
    cin >> N >> W >> H;
    int max = sqrt(W * W + H * H);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        if (L <= max) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}