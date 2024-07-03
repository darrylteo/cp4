#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int lim, N, tc = 1;
vector<vi> stk; // easier to manipulate than stack.
vi y, steps; // y is just y. steps to save answer
const vector<string> ops = {"ADD", "DIV", "DUP", "MUL", "SUB"}; // alphabetical order

bool check() {
    for (int i = 0; i < N; ++i) {
        if (stk[i].size() != 1 || stk[i][0] != y[i]) {
            return false;
        }
    }
    return true;
}

bool dfs(int id) {
    if (id == lim) return check(); // with lim moves, did we manage to solve it?
    for (int i = 0; i < N; ++i) {
        if (abs(stk[i].back()) > 30000) return false; // too big.
    }
    // save for backtracking, and check if division is allowed.
    vector<vi> bk = stk;
    bool div = true;
    for (int i = 0; i < N; ++i) {
        if (stk[i].back() == 0) {
            div = false;
            break;
        }
    }
    // try all ops
    for (int i = 0; i < 5; ++i) {
        if (i == 1 && !div) continue;
        if (i == 2) {
            for (int j = 0; j < N; ++j) {
                stk[j].push_back(stk[j].back());
            }
        } else {
            if (stk[0].size() < 2) continue;
            for (int j = 0; j < N; ++j) {
                int a = stk[j].back();
                stk[j].pop_back();
                int b = stk[j].back();
                stk[j].pop_back();
                if (i == 0) stk[j].push_back(a + b);
                else if (i == 1) stk[j].push_back(b / a);
                else if (i == 3) stk[j].push_back(a * b);
                else stk[j].push_back(b - a);
            }
        }
        steps[id] = i;
        if (dfs(id + 1)) return true;
        stk = bk;
    }
    return false;
}

int IDDFS() {
    for (lim = 0; lim <= 10; ++lim) {
        if (dfs(0)) return lim;
    }
    return -1;
}

// no IDA here. just brute force.
// note: in udebug, they say to return an ans even though the initial value of x given is >30000.
// the code here is accepted without doing that however.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> N, N) {
        cout << "Program " << tc++ << endl;
        y.resize(N);
        steps.assign(11, 0);
        stk.assign(N, vi());
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            stk[i].push_back(x);
        }
        for (int i = 0; i < N; ++i) cin >> y[i];
        int ans = IDDFS();
        if (ans == -1) cout << "Impossible" << endl;
        else if (ans == 0) cout << "Empty sequence" << endl;
        else {
            for (int i = 0; i < ans; ++i) {
                cout << ops[steps[i]];
                if (i != ans - 1) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
