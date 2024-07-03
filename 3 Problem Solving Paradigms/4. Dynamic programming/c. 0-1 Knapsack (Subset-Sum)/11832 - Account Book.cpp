#include <bits/stdc++.h>

using namespace std;

// need to offset 0 = 40000. -40000 = 0. 40000 = 80000. since index can't be negative

int N, F, T[45], canAdds[45], canSubs[45], memo[45][80005];

// remaining value should be 0 (aka 40000)
bool DFS(int id, int remW) {
    if (id == N) return remW == 40000;
    int &ans = memo[id][remW];
    if (ans != -1)
        return memo[id][remW]; // if u got here with this remaining weight, this will tell u if it is possible to complete or not
    bool canAdd = false, canSub = false;
    if (remW + T[id] <= 80000) canAdd = DFS(id + 1, remW - T[id]); // u added it so u need to subtract remaining weight
    if (remW - T[id] >= 0) canSub = DFS(id + 1, remW + T[id]);
    if (canAdd) canAdds[id] = 1;
    if (canSub) canSubs[id] = 1;
    return ans = canAdd || canSub; // as long can get to ans with either add or sub, it is ok
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N >> F, N || F) {
        for (int i = 0; i < N; i++) cin >> T[i];
        memset(memo, -1, sizeof memo);
        memset(canAdds, 0, sizeof canAdds);
        memset(canSubs, 0, sizeof canSubs);
        if (!DFS(0, 40000 + F)) {
            cout << "*" << endl;
        } else {
            for (int i = 0; i < N; i++) {
                if (canAdds[i] && canSubs[i]) cout << "?";
                else if (canAdds[i]) cout << "+";
                else cout << "-";
            }
            cout << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
