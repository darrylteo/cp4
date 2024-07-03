#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<long long> seq;

void something(int jump, int cnt) {
    int i = 0;
    while (i < N) {
        seq[i] += cnt;
        i += jump;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    seq.resize(N);
    vector<int> calls(N);
    while (K--) {
        int x;
        cin >> x;
        calls[x]++;
    }
    for (int i = 0; i < N; i++) {
        if (calls[i] == 0) continue;
        something(i, calls[i]);
    }
    vector<long long> cum(N);
    cum[0] = seq[0];
    for (int i = 1; i < N; i++) {
        cum[i] = cum[i - 1] + seq[i];
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        if (l == 0) {
            cout << cum[r] << endl;
        } else {
            cout << cum[r] - cum[l - 1] << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

