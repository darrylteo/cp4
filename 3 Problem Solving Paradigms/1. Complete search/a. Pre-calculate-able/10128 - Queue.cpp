#include <bits/stdc++.h>

using namespace std;

// checking all permutations for 11 people takes 3.5 seconds
// definitely not feasible
// clear explanation: https://stackoverflow.com/questions/44984008/arranging-people-in-queue-uva-10128
//When you calculate DP[N][P][R] you look at the position of the smallest person in the queue. Because he is the smallest, he can't block anybody. But he will get blocked if he doesn't stand at either end of the queue.
//If he is the first person in the queue he is seen from the beginning of the line. So if we remove him, the queue contains N-1 people and you can only see P-1 people from the beginning, but still R people from the end. Therefore there are DP[N-1][P-1][R] combinations.
//If he is in the middle, then by removing him we still can see P and R people. And since there are N-2 positions in the middle, there are DP[N-1][P][R] * (N-2) combinations.
//And if he is the last person in the queue we get DP[N-1][P][R-1] combinations. The reasoning is identically to the first case.
//So the total number of combinations for DP[N][P][R] is the sum of all three cases.

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long DP[14][14][14] = {}, N, P, R;

    DP[1][1][1] = 1;
    for(N = 2; N <= 13; N++)
        for(P = 1; P <= N; P++)
            for(R = 1; R <= N; R++)
                DP[N][P][R] = DP[N-1][P][R]*(N-2) + DP[N-1][P-1][R] + DP[N-1][P][R-1];

    int n;
    cin >> n;
    while (n--) {
        cin >> N >> P >> R;
        cout << DP[N][P][R] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
