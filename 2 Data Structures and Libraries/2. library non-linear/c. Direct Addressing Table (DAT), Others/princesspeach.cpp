#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Y;
    cin >> N >> Y;
    vector<bool> v(N);
    for (int i = 0; i < Y; ++i) {
        int x;
        cin >> x;
        v[x] = true;
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (!v[i]) {
            cout << i << endl;
        } else {
            cnt++;
        }
    }

    cout << "Mario got " << cnt << " of the dangerous obstacles." << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
