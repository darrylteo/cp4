#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define sz(a) int((a).size())
typedef vector<int> vi;
typedef double T; // long double, Rational, double + mod<P>...
typedef vector<T> vd;
typedef vector<vd> vvd;

const T eps = 1e-8, inf = 1 / .0;
#define MP make_pair
#define ltj(X) if(s == -1 || MP(X[j],N[j]) < MP(X[s],N[s])) s=j

struct LPSolver {
    int m, n;
    vi N, B;
    vvd D;

    LPSolver(const vvd &A, const vd &b, const vd &c) :
            m(sz(b)), n(sz(c)), N(n + 1), B(m), D(m + 2, vd(n + 2)) {
        FOR(i, 0, m) FOR(j, 0, n) D[i][j] = A[i][j];
        FOR(i, 0, m) {
            B[i] = n + i;
            D[i][n] = -1;
            D[i][n + 1] = b[i];
        }
        FOR(j, 0, n) {
            N[j] = j;
            D[m][j] = -c[j];
        }
        N[n] = -1;
        D[m + 1][n] = 1;
    }

    void pivot(int r, int s) {
        T *a = D[r].data(), inv = 1 / a[s];
        FOR(i, 0, m + 2) if (i != r && abs(D[i][s]) > eps) {
                T *b = D[i].data(), inv2 = b[s] * inv;
                FOR(j, 0, n + 2) b[j] -= a[j] * inv2;
                b[s] = a[s] * inv2;
            }
        FOR(j, 0, n + 2) if (j != s) D[r][j] *= inv;
        FOR(i, 0, m + 2) if (i != r) D[i][s] *= -inv;
        D[r][s] = inv;
        swap(B[r], N[s]);
    }

    bool simplex(int phase) {
        int x = m + phase - 1;
        for (;;) {
            int s = -1;
            FOR(j, 0, n + 1) if (N[j] != -phase) ltj(D[x]);
            if (D[x][s] >= -eps) return true;
            int r = -1;
            FOR(i, 0, m) {
                if (D[i][s] <= eps) continue;
                if (r == -1 || MP(D[i][n + 1] / D[i][s], B[i])
                               < MP(D[r][n + 1] / D[r][s], B[r]))
                    r = i;
            }
            if (r == -1) return false;
            pivot(r, s);
        }
    }

    T solve(vd &x) {
        int r = 0;
        FOR(i, 1, m) if (D[i][n + 1] < D[r][n + 1]) r = i;
        if (D[r][n + 1] < -eps) {
            pivot(r, n);
            if (!simplex(2) || D[m + 1][n + 1] < -eps) return -inf;
            FOR(i, 0, m) if (B[i] == -1) {
                    int s = 0;
                    FOR(j, 1, n + 1) ltj(D[i]);
                    pivot(i, s);
                }
        }
        bool ok = simplex(1);
        x = vd(n);
        FOR(i, 0, m) if (B[i] < n) x[B[i]] = D[i][n + 1];
        return ok ? D[m][n + 1] : inf;
    }
};

struct route {
    int u, v;
    double t; // time in hours
};

// with ti as time for road i, and di as distance for road i, using speed limits of 30 and 60,
// di/60 <= ti <= di/30.
// for each given previous route of total time T
// ti + tii + tiii <= T and ti + tii + tiii >= T
// only thing we change is objective function to either minimize or maximize ti + tii + tiii + ... from city u to v
// formulation:
// maximize \sum_{i \in (u,v)} ti // min/max time from city u to v and print both (2 runs of simplex per query)
// subject to:
// \sum_{i \in r} T_r <= ti <= T_r // for all previous routes r (2*r constraints)
// di/60 <= ti <= di/30 // for all roads/edges i (2*e constraints)
// phew.. long question.
// also works for uva 1744 - Road Times

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // initial graph
    int n, e = 0;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    map<pair<int, int>, int> e2idx; // keep track of roads (directed)
    map<int, pair<int, int>> idx2e;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) graph[i][j] = 1e9;
            if (graph[i][j] != 1e9 && i != j) {
                e2idx[{i, j}] = e;
                idx2e[e] = {i, j};
                e++;
            }
        }
    }
    vector<vector<vector<int>>> spf(n, vector<vector<int>>(n)); // store shortest path from u to v
    vector<vector<vector<int>>> spe(n, vector<vector<int>>(n)); // store edges in shortest path from u to v
    vector<vector<int>> dist(n, vector<int>(n)); // store shortest distance from u to v
    vector<vector<int>> next(n, vector<int>(n)); // store next node from u to v
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
            if (dist[i][j] == 1e9) next[i][j] = -1;
            else next[i][j] = j;
        }
    }
    // run floyd and store the shortest path. careful that roads are directed. but floyd can take care of it
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    // put all shortest paths into spf. the i and u are a little fuzzy here. clearer if abstracted to a function
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            int u = i;
            if (next[u][v] == -1) continue; // no path from u to v, the spf[u][v] will remain empty
            spf[u][v].push_back(u);
            while (u != v) {
                u = next[u][v];
                spf[i][v].push_back(u);
            }
        }
    }
    // use spf to put all edges in shortest path into spe
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (spf[u][v].empty()) continue;
            for (int j = 0; j < spf[u][v].size() - 1; j++) {
                spe[u][v].push_back(e2idx[{spf[u][v][j], spf[u][v][j + 1]}]);
            }
        }
    }
    int r;
    cin >> r;
    vector<route> routes(r);
    for (int i = 0; i < r; i++) {
        cin >> routes[i].u >> routes[i].v >> routes[i].t;
        routes[i].t /= 60; // convert to hours
    }
    vvd A(2 * (e + r), vd(e, 0)); // 2 * (e + r) constraints, e variables
    vd b(2 * (e + r)); // 2 * (e + r) constraints
    // di/60 <= ti <= di/30 for all roads i
    for (int i = 0; i < e; i++) {
        int u = idx2e[i].first, v = idx2e[i].second;
        int d = graph[u][v];
        double tl = d / 60.0, th = d / 30.0;
        A[2 * i][i] = 1;
        b[2 * i] = th; // ti <= di/30
        A[2 * i + 1][i] = -1;
        b[2 * i + 1] = -tl; // -ti <= -di/60
    }
    // \sum_{i \in r} T_r <= ti <= T_r for all previous routes r
    for (int i = 0; i < r; i++) {
        for (int j: spe[routes[i].u][routes[i].v]) {
            A[2 * (e + i)][j] = 1;
            A[2 * (e + i) + 1][j] = -1;
        }
        b[2 * (e + i)] = routes[i].t;
        b[2 * (e + i) + 1] = -routes[i].t;
    }

    // get queries and set c accordingly
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << u << " " << v << " ";

        vd c(e, 0);
        for (int i: spe[u][v]) c[i] = 1;
        LPSolver solver(A, b, c);
        vd x;
        double maxTime = solver.solve(x);

        vd c2(e, 0);
        for (int i: spe[u][v]) c2[i] = -1;
        LPSolver solver2(A, b, c2);
        vd x2;
        double minTime = -solver2.solve(x2);

        cout << fixed << setprecision(10) << minTime * 60 << " " << maxTime * 60 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
