#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

// maximum number of walks = N * (N + 1) / 2, since not necessarily distinct
// when N = 2e5 max value is its around 2e10, so use ll

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll N, K;
    cin >> N >> K;
    vll A(K + 2);
    A[0] = 0;
    A[K + 1] = N + 1;
    for (int i = 1; i <= K; i++) {
        cin >> A[i];
    }
    ll totalWalks = N * (N + 1) / 2;
    ll dangerWalks = 0;
    for (int i = 0; i < K + 1; i++) {
        if (A[i] + 1 < A[i + 1]) {
            dangerWalks += (A[i + 1] - A[i] - 1) * (A[i + 1] - A[i]) / 2 ;
        }
    }
    cout << totalWalks - dangerWalks << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


