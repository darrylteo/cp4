#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    if (n & 1) {
        cout << "still running\n";
    } else {
        int sum = 0;
        for (int i = 0; i < n / 2; i++) {
            int start, end;
            cin >> start >> end;
            sum += end - start;
        }
        cout << sum << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}