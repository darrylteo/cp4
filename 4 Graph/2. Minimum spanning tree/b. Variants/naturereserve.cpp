#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;                                  // the graph stored in AL
vi taken;                                        // to avoid cycle
priority_queue<ii> pq;                           // to select shorter edges
int num_taken, N, M, L, S, T;
long long mst_cost;
// C++ STL priority_queue is a max heap, we use -ve sign to reverse order (easier read if use greater<>() but i just used book code)

void process(int u) { // set u as taken and enqueue neighbors of u
    taken[u] = 1;
    for (auto &[v, w]: AL[u])
        if (!taken[v]) {
            pq.emplace(-w, -v);                         // sort by non-dec weight then by inc id
        }
}

// more or less standard code from book CP4. just add the last line to print the answer
// prim recommended as multi source allow for each source to have its own MST rather than a single MST for entire graph

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N >> M >> L >> S;
        vector<int> srcs(S);
        for (int i = 0; i < S; ++i) {
            int src;
            cin >> src;
            src--;
            srcs[i] = src;
        }
        AL.assign(N, vii());
        taken.assign(N, 0);                            // no vertex is taken
        while(!pq.empty()) pq.pop(); // clear the priority queue
        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            AL[u].emplace_back(v, w);
            AL[v].emplace_back(u, w);
        }
        for (int src: srcs) process(src); // add stuff to pq
        mst_cost = 0, num_taken = 0;               // no edge has been taken
        while (!pq.empty()) {                          // up to O(E)
            auto [w, u] = pq.top();
            pq.pop();            // C++17 style
            w = -w;
            u = -u;                              // negate to reverse order
            if (taken[u]) continue;                      // already taken, skipped
            mst_cost += w;                             // add w of this edge
            process(u);                                  // take+process vertex u
            ++num_taken;                                 // 1 more edge is taken
            if (num_taken == N - srcs.size()) break;                 // optimization
        }
        cout << mst_cost + L * (N - srcs.size()) << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}