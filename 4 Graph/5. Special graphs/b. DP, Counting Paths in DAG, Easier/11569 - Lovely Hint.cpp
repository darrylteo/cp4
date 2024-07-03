#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<iii> viii;

int ways, N;

void dfs(int u, vi& dist, vi adj[], vi& nums, int cnt) {
    if (cnt == N) {
        ways++;
        return;
    }
    for (int v: adj[u]) {
        dfs(v, dist, adj, nums, cnt + 1);
    }
}

// very weird that i had a hard time doing this when it is a "trivial" problem on uva
// tried to do weird tricks like tracking parents but ended up doing dfs
// longest path code is standard (copy paste)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf;
    getline(cin, buf);
    while (getline(cin, buf)) {
        ways = 0;
        set<int> st;
        for (char c: buf) {
            if (isupper(c)) {
                st.insert(c - 'A' + 1);
            }
        }
        vector<int> nums(st.begin(), st.end());
        vi adj[st.size()];
        for (int i = 0; i < st.size(); i++) {
            for (int j = 0; j < st.size(); j++) {
                if (i == j) continue;
                if (5 * nums[i] <= 4 * nums[j]) {
                    adj[i].push_back(j);
                }
            }
        }

        // get longest path
        vi dist(nums.size(), 0);
        dist[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: adj[u]) {
                if (dist[v] < dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        N = *max_element(dist.begin(), dist.end());
        // get number of ways to get this path length (brute force)
        for (int i = 0; i < st.size(); i++) {
            dfs(i, dist, adj, nums, 1);
        }
        cout << N << ' ' << ways << endl;
    }
    
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}