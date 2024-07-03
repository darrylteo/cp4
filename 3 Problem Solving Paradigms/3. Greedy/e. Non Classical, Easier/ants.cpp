#include <bits/stdc++.h>

using namespace std;

// earliest time when all walk towards the closest end of pole
// latest is when the ants walk to furthest end of pole
// from sample can be guessed... furthest = 10 - 2 = 8, and 214 - 7 = 207

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int l, n;
        cin >> l >> n;
        int earliest = 0, latest = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            earliest = max(earliest, min(x, l - x));
            latest = max(latest, max(x, l - x));
        }
        cout << earliest << " " << latest << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
