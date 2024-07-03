#include <bits/stdc++.h>

using namespace std;

// similar to 1153 - Keep the Customer Satisfied

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });
    // at time t, throw everyone who has time <= t, make sure pq has less than t elements
    // continue until time T
    long long ans = 0;
    for (int i = 0; i < T; ++i) {
        // add ppl into pq (and their money)
        while (!v.empty() && v.back().second <= i) {
            ans += v.back().first;
            pq.push(v.back().first);
            v.pop_back();
        }
        // remove ppl from pq
        while (pq.size() > i + 1) {
            ans -= pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
