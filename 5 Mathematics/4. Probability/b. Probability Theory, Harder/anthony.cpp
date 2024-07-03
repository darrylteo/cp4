#include <bits/stdc++.h>

using namespace std;

double memo[2005][2005];
int N, M;
vector<double> probs;

// roll number, num ant wins
inline double dp(int i, int j) {
    if (j == M) { // ant wins
        return 1;
    }
    if (i - j == N) { // ant loses
        return 0;
    }
    if (i == N + M) { // no more rolls left
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    return memo[i][j] = probs[i] * dp(i + 1, j + 1) + (1 - probs[i]) * dp(i + 1, j);
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> N >> M;
    probs.resize(N + M - 1);
    for (int i = 0; i < N + M - 1; i++) {
        cin >> probs[i];
    }
    for (int i = 0; i < 2005; i++) {
        for (int j = 0; j < 2005; j++) {
            memo[i][j] = -1;
        }
    }
    cout << fixed << setprecision(10) << dp(0, 0) << '\n';



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
