#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// buy low from producer, sell high to consumer :D

// anyone who starts selling on a later date, must sell at a lower price else don't even bother buying from him
struct pd { // producer
    ll d, p; // date, price
    bool operator<(const pd &o) const { // smaller date first, smaller price first
        if (d != o.d) return d < o.d;
        return p < o.p;
    }
};

// anyone who stops buying on an earlier date, must buy at a higher price else don't even bother selling to him
struct cn { // consumer
    ll d, p; // date, price
    bool operator<(const cn &o) const { // bigger date first, bigger price first
        if (d != o.d) return d > o.d;
        return p > o.p;
    }
};

int P, C; // number of producers, consumers
vector<pd> pdsTmp(P), pds;
vector<cn> cnsTmp(C), cns;

void clean() { // get the useful producers and consumers
    pdsTmp.resize(P), cnsTmp.resize(C);
    for (int i = 0; i < P; i++) cin >> pdsTmp[i].p >> pdsTmp[i].d;
    for (int i = 0; i < C; i++) cin >> cnsTmp[i].p >> cnsTmp[i].d;
    sort(pdsTmp.begin(), pdsTmp.end());
    sort(cnsTmp.begin(), cnsTmp.end());
    ll bestP = 1e18, bestC = -1;
    for (int i = 0; i < P; i++) {
        if (pdsTmp[i].p < bestP) {
            pds.push_back(pdsTmp[i]);
            bestP = pdsTmp[i].p;
        }
    }
    for (int i = 0; i < C; i++) {
        if (cnsTmp[i].p > bestC) {
            cns.push_back(cnsTmp[i]);
            bestC = cnsTmp[i].p;
        }
    }
    reverse(cns.begin(), cns.end()); // see the youtube diagram. it's like a pareto front.
}

ll solve(int pdL, int pdR, int cnL, int cnR) {
    if (pdL > pdR || cnL > cnR) return 0;
    ll ans = 0, ansIdx = cnL; // we will find the best consumer, given must use producer middle.
    int pdM = (pdL + pdR) / 2; // producer middle
    for (int i = cnL; i <= cnR; i++) {
        if (cns[i].d <= pds[pdM].d) {
            ansIdx = min(cnR, i + 1); // producers to the right of pdM will not sell to any consumer idx i or less!!
            continue; // consumer date must be after producer date
        }
        if (cns[i].p <= pds[pdM].p) continue; // consumer price must be higher than producer price
        ll curr = (cns[i].d - pds[pdM].d) * (cns[i].p - pds[pdM].p); // profit of days*price
        if (curr > ans) {
            ans = curr;
            ansIdx = i;
        }
    }
    // 1 left to producer middle, 1 right to producer middle
    // see youtube diagram that it is up to ansIdx inclusive
    ll best = max(solve(pdL, pdM - 1, cnL, ansIdx), solve(pdM + 1, pdR, ansIdx, cnR));
    return max(ans, best);
}

// beautiful drawing of the divide and conquer algorithm
// https://www.youtube.com/watch?v=oZBHAGnCs9U
// nothing to do with dp?

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> P >> C;
    clean();
    cout << solve(0, pds.size() - 1, 0, cns.size() - 1) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
