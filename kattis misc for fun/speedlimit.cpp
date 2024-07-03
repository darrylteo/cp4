#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n, n != -1) {
        int currTime = 0, totalDist = 0;
        for (int i = 0; i < n; i++) {
            int speed, time;
            cin >> speed >> time;
            totalDist += speed * (time - currTime);
            currTime = time;
        }
        cout << totalDist << " miles" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

