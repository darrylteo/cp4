#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2020;
const int MAX_W = 2020;

// value is the number of delegates in state i, weight is the number of votes required to win state i
int N, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int dp(int id, int remD) {
    if (remD <= 0) return 0;        // enough votes to win
    if (id == N) return 1e9 + 9;        // no more states, lose (must be more than max no. of voters)
    int &ans = memo[id][remD];
    if (ans != -1) return ans;                     // computed before
    return ans = min(dp(id+1, remD), dp(id+1, remD-V[id]) + W[id]); // try both choices
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> N;
    vector<int> cVotes(N), fVotes(N), uVotes(N);
    int totalDelegates = 0;
    for (int i = 0; i < N; i++) {
        cin >> V[i] >> cVotes[i] >> fVotes[i] >> uVotes[i];
        totalDelegates += V[i];
    }
    // delegates needed to win
    int dToWin = (totalDelegates / 2) + 1;
    // number of voters required from each state (weight)
    for (int i = 0; i < N; i++) {
        int vToWin = (cVotes[i] + fVotes[i] + uVotes[i]) / 2 + 1 - cVotes[i];
        if (vToWin > uVotes[i]) W[i] = 1e9 + 9; // cannot win this state... u pay 1 billion humans then can :N
        else if (vToWin <= 0) W[i] = 0; // free state
        else W[i] = vToWin;
    }
    memset(memo, -1, sizeof memo);
    if (dp(0, dToWin) > 1e9) cout << "impossible" << endl;
    else cout << dp(0, dToWin) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
