#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii; // In this chapter, we will frequently use these
typedef vector<ii> vii; // three data type shortcuts. They may look cryptic
typedef vector<int> vi; // but shortcuts are useful in competitive programming

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int start, end, cnt, T;
    cin >> T;
    while (T--) {
        start = 0;
        cin >> cnt >> end;
        vector<int> buttons(cnt);
        for (int &i : buttons) cin >> i;
        int dist[4000];
        for (int &i : dist) i = 1e9;
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == end) break;
            for (int &i : buttons) {
                int v = min(3600, max(0, u + i));
                if (dist[v] == 1e9) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int time = end; time < 4000; time++) {
            if (dist[time] != 1e9) {
                cout << dist[time] << " " << time - end << endl;
                break;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}