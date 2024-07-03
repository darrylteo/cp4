#include <bits/stdc++.h>

using namespace std;

// assign a new workstation if all in use when new researcher arrives
// feels hard for an easy rated kattis problem

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, unlocksSaved = 0;
    cin >> n >> m;
    vector<pair<int, int>> v(n); // start, time taken
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        if (pq.empty()) {
            pq.push(v[i].first + v[i].second);
            continue;
        }
        while (!pq.empty() && pq.top() + m < v[i].first) { // remove all the small ones since they are locked
            pq.pop();
        }
        if (pq.top() > v[i].first || pq.empty()) { // if all small removed, and curr station is still in use, have to unlock new station for him
            pq.push(v[i].first + v[i].second);
        } else {
            unlocksSaved++;
            pq.pop(); // reuse station
            pq.push(v[i].first + v[i].second);
        }
    }

    cout << unlocksSaved << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
