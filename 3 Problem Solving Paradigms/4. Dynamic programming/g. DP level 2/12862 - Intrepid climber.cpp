#include <bits/stdc++.h>

using namespace std;

// general idea: dfs down the tree, if there is one or more friends down this route, add it to depth (to check max depth since we don't wanna walk up once we come to max depth)
// if there are no friends down this route, return 0
// if there is one friend down this route, continue checking, with the curr depth added (should be part of state)

int F, N, maxDepth, energyUsed, F1[100005];
vector<vector<pair<int, int>>> adjList; // idx, (child, depth)

int dfs(int idx, int depth) {
    int friendCnt = 0;
    if (F1[idx]) { // friend here
        maxDepth = max(maxDepth, depth);
        friendCnt = 1;
    }
    for (auto &i: adjList[idx]) {
        int friendHere = dfs(i.first, depth + i.second);
        if (friendHere) {
            energyUsed += i.second;
            friendCnt = 1;
        }
    }
    return friendCnt;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> N >> F) {
        adjList.clear();
        adjList.resize(N + 1);
        maxDepth = 0;
        energyUsed = 0;
        memset(F1, 0, sizeof(F1));
        for (int i = 0; i < N - 1; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adjList[a].emplace_back(b, c);
        }
        for (int i = 0; i < F; i++) {
            int x;
            cin >> x;
            F1[x] = 1; // there is a friend (doing this so no need use find)
        }
        dfs(1, 0);
        cout << energyUsed - maxDepth << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


