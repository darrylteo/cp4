#include <bits/stdc++.h>

using namespace std;
typedef tuple<double, int, int> dii;

// similar to kattis - ballotboxes

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int p, n;
    while (cin >> p >> n) {
        priority_queue<dii> pq;                      // max pq
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            pq.emplace((double) a / 1.0, a, 1);            // initially, 1 box/city
        }
        p -= n;                                      // remaining boxes
        while (p--) {                                // extra box->largest city
            auto [r, num, den] = pq.top();
            pq.pop();   // current largest city
            pq.push({num / (den + 1.0), num, den + 1});      // reduce its workload
        }
        printf("%d\n", (int) ceil(get<0>(pq.top()))); // the final answer
    } // all other cities in the max pq will have equal or lesser ratio
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}