#include <bits/stdc++.h>

using namespace std;

const int primes[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0};
vector<int> cur(8), correct(8), tmp(7); // tmp is remove the current person, then try to slot him in slot 0 to 7

inline bool sgn(int x) { return x > 0; }

bool canInsert(int pos, int val) { // val is the guy u removed
    if (pos == 0) { // slot to left of whole group
        return primes[abs(val) + abs(tmp[0])] && sgn(val) != sgn(tmp[0]);
    }
    if (pos == 7) { // slot to right of whole group
        return primes[abs(val) + abs(tmp[6])] && sgn(val) != sgn(tmp[6]);
    }
    // either left or right pair is ok
    return primes[abs(val) + abs(tmp[pos - 1])] && sgn(val) != sgn(tmp[pos - 1]) ||
           primes[abs(val) + abs(tmp[pos])] && sgn(val) != sgn(tmp[pos]);
}

struct hashh {
    size_t operator()(const vector<int> &v) const {
        size_t res = 0;
        for (int i = 0; i < 7; i++) {
            res = res * 31 + v[i];
        }
        return res;
    }
};

// standard bfs after defining the "next state" operator

int bfs() {
    queue<vector<int>> q;
    q.push(cur);
    unordered_map<vector<int>, int, hashh> dist;
    dist[cur] = 0;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        if (u == correct) return dist[u];
        for (int i = 0; i < 8; i++) {
            tmp = u;
            int val = tmp[i];
            tmp.erase(tmp.begin() + i);
            for (int j = 0; j < 8; j++) {
                if (canInsert(j, val)) {
                    tmp.insert(tmp.begin() + j, val);
                    if (!dist.count(tmp)) {
                        dist[tmp] = dist[u] + 1;
                        q.push(tmp);
                    }
                    tmp.erase(tmp.begin() + j);
                }
            }
        }
    }
    return -1;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases = 1;
    while (true) {
        for (int i = 0; i < 8; i++) {
            cin >> cur[i];
        }
        if (cur[0] == 0) break;
        correct = cur;
        sort(correct.begin(), correct.end(), [](int a, int b) { return abs(a) < abs(b); });
        cout << "Case " << cases++ << ": " << bfs() << '\n';
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}



