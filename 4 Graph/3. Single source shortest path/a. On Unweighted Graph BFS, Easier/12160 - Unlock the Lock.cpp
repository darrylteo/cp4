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

    int start, end, cnt, cases = 1;
    while (cin >> start >> end >> cnt) {
        if (start == 0 && end == 0 && cnt == 0) break;
        vector<int> buttons(cnt);
        for (int &i : buttons) cin >> i;
        int dist[10000];
        for (int &i : dist) i = 1e9;
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == end) break;
            for (int &i : buttons) {
                int v = (u + i) % 10000;
                if (dist[v] == 1e9) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        cout << "Case " << cases++ << ": ";
        if (dist[end] == 1e9) cout << "Permanently Locked\n";
        else cout << dist[end] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}