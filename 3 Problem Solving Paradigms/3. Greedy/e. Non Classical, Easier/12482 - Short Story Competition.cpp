#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, M;
    while (cin >> N >> L >> M) {
        int lines = 1, currLength = 0;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            if (currLength == 0) { // only at start
                currLength += s.length();
            } else if (currLength + s.length() + 1 <= M) {
                currLength += s.length() + 1;
            } else {
                lines++;
                currLength = s.length();
            }
        }
        cout << ceil((float) lines / L) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
