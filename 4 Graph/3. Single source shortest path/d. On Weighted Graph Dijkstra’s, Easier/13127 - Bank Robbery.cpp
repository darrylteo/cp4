#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// interesting to know multisource dijkstra is same as normal dijkstra just start with all sources dist = 0!
// i thought it only applied to BFS

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, B, P;
    while (cin >> N >> M >> B >> P) {
        vector<vii> adjList(N);
        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adjList[u].emplace_back(v, w);
            adjList[v].emplace_back(u, w);
        }
        vi banks(B), bankDist(B, INT_MAX);
        for (int i = 0; i < B; ++i) {
            cin >> banks[i];
        }
        vi police(P);
        for (int i = 0; i < P; ++i) {
            cin >> police[i];
        }

        vi dist(N, INT_MAX);
        priority_queue<ii, vii, greater<ii>> pq;
        for (int S: police) {
            dist[S] = 0;
            pq.emplace(0, S);
        }
        while (!pq.empty()) {
            ii front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if (d > dist[u]) continue;
            for (auto &v: adjList[u]) {
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.emplace(dist[v.first], v.first);
                }
            }
        }

        for (int i = 0; i < B; ++i) {
            bankDist[i] = dist[banks[i]];
        }

        int maxDist = *max_element(bankDist.begin(), bankDist.end());
        vi bestBanks;
        for (int i = 0; i < B; ++i) {
            if (bankDist[i] == maxDist) {
                bestBanks.push_back(banks[i]);
            }
        }
        sort(bestBanks.begin(), bestBanks.end()); // bank input was not sorted

        if (maxDist == INT_MAX) cout << bestBanks.size() << " *\n";
        else cout << bestBanks.size() << " " << maxDist << '\n';

        for (int i = 0; i < bestBanks.size(); ++i) {
            cout << bestBanks[i];
            if (i < bestBanks.size() - 1) {
                cout << " ";
            }
        }
        cout << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}