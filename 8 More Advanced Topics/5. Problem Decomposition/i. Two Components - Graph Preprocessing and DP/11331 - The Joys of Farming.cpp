#include <bits/stdc++.h>

using namespace std;

int ok[2005], memo[2005][2005];

inline int dfs(int id, int cows, vector<int> &leftt, vector<int> &rightt) {
    if (id == leftt.size()) {
        if (ok[cows]) return 1;
        return 0;
    }
    if (memo[id][cows] != -1) return memo[id][cows];
    int ans = 0;
    ans = max(ans, dfs(id + 1, cows + leftt[id], leftt, rightt));
    ans = max(ans, dfs(id + 1, cows + rightt[id], leftt, rightt));
    return memo[id][cows] = ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> b >> c >> a;
        if (a == 0) {
            cout << "yes\n";
            continue;
        }
        vector<vector<int>> AL(b + c + 1);
        vector<int> exists(b + c + 1, 0);
        for (int i = 0; i < a; i++) {
            int x, y;
            cin >> x >> y;
            AL[x].push_back(y);
            AL[y].push_back(x);
            exists[x] = 1;
            exists[y] = 1;
        }
        // check if bipartite (and get sizes of current bipartite sets for later)
        queue<int> q;
        vector<int> color(b + c + 1, -1);
        bool isBipartite = true;
        vector<int> leftCum, rightCum;
        for (int i = 1; i < b + c; ++i) {
            if (color[i] != -1 || !exists[i]) continue;
            color[i] = 0;
            q.push(i);
            while (!q.empty() && isBipartite) {
                int u = q.front();
                q.pop();
                for (int v: AL[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        isBipartite = false;
                        break;
                    }
                }
            }
            int left = 0, right = 0;
            for (int j = 1; j <= b + c; j++) {
                if (color[j] == 0) left++;
                else if (color[j] == 1) right++;
            }
            leftCum.push_back(left);
            rightCum.push_back(right);
        }
        if (!isBipartite) {
            cout << "no\n";
            continue;
        }

        // get sizes of each bipartite set
        vector<int> leftt(leftCum.size()), rightt(rightCum.size());
        for (int i = leftCum.size() - 1; i >= 1; i--) {
            leftt[i] = leftCum[i] - leftCum[i - 1];
            rightt[i] = rightCum[i] - rightCum[i - 1];
        }
        leftt[0] = leftCum[0];
        rightt[0] = rightCum[0];
        int free = 0;
        for (int i = 1; i <= b + c; i++) {
            if (color[i] == -1) free++;
        }
        // mark safe counts. can either make full set for cow or bull
        // e.g. 10 free, and need 16 cows, 6-16 cows are all safe
        memset(ok, 0, sizeof(ok));
        for (int i = 0; i <= free; ++i) {
            ok[max(b - i, 0)] = 1;
            ok[max(c - i, 0)] = 1;
        }
        memset(memo, -1, sizeof(memo));
        if (dfs(0, 0, leftt, rightt)) cout << "yes\n";
        else cout << "no\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
