#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int s, t, n;
    cin >> s >> t >> n;
    vi walk, bus, busInterval;
    n++;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        walk.push_back(x);
    }
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        bus.push_back(x);
    }
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        busInterval.push_back(x);
    }
    int currentTime = s;
    for (int i = 0; i < n; i++) {
        currentTime += walk[i];
        if (i < n - 1) {
            int waitTime = busInterval[i] - (currentTime % busInterval[i]);
            if (waitTime != busInterval[i]) currentTime += waitTime;
            currentTime += bus[i];
        }
    }
    if (currentTime <= t) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


