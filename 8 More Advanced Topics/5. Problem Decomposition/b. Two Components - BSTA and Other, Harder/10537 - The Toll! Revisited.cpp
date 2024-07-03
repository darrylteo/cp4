#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct rat {
    ll ds, sp; // distance, spoon
    vector<ll> path;

    bool operator<(const rat &r) const {
        if (ds != r.ds) return ds < r.ds; // less dist
        if (sp != r.sp) return sp > r.sp; // more spoon
        return path < r.path; // less path
    }

    bool operator==(const rat &r) const {
        return ds == r.ds && sp == r.sp;
    }
};

struct rat2 {
    ll ds, sp, u; // distance, spoon, node
    vector<ll> path;

    bool operator<(const rat2 &r) const {
        if (ds != r.ds) return ds < r.ds; // less dist
        if (sp != r.sp) return sp > r.sp; // more spoon
        return path < r.path; // less path
    }
};

vector<ll> adj[52];
ll s, t;

void addEdge(ll u, ll v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

rat remSpoon(ll n) {
    vector<rat> dist(52, {(ll) 1e18, 0}, {});
    dist[s] = {0, n, {}}; // at start we have n spoons - cost of 1st node
    set<rat2> pq; // nn
    pq.insert({0, n, s, {}}); // distance, spoons, node, path
    while (!pq.empty()) {
        auto uu = *pq.begin();
        ll u = uu.u, ds = uu.ds, sp = uu.sp;
        vector<ll> path = uu.path;
        pq.erase(pq.begin());

        for (ll v: adj[u]) {
            bool isVillage = v >= 26;
            ll nsp;
            if (isVillage) nsp = 1; // pay 1 spoon to village
            else {
                if (sp % 20) nsp = sp / 20LL + 1; // some tricks to avoid precision error
                else nsp = sp / 20LL;
            }
            if (sp - nsp < 0) continue; // not enough spoons

            path.push_back(v);
            rat curr = {ds + nsp, sp - nsp, path};
            if (curr < dist[v]) {
                pq.erase({dist[v].ds, dist[v].sp, v});
                dist[v] = curr;
                pq.insert({dist[v].ds, dist[v].sp, v, path});
            }
            path.pop_back();
        }
    }
    return dist[t];
}

// let nodes A-Z is 0-25, a-z is 26-51
// kinda weirdchamp but i stored the entire path since there are only 52 nodes at most

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll E;
    int cases = 1;
    while (cin >> E, E != -1) {
        cout << "Case " << cases++ << ":\n";
        for (auto &i: adj) i.clear();
        for (ll i = 0; i < E; ++i) {
            char u, v;
            cin >> u >> v;
            ll uu, vv;
            if (isupper(u)) uu = u - 'A';
            else uu = u - 'a' + 26;
            if (isupper(v)) vv = v - 'A';
            else vv = v - 'a' + 26;
            addEdge(uu, vv);
        }
        for (auto &i: adj) sort(i.begin(), i.end());
        ll need;
        char start, end;
        cin >> need >> start >> end;
        if (isupper(start)) s = start - 'A';
        else s = start - 'a' + 26;
        if (isupper(end)) t = end - 'A';
        else t = end - 'a' + 26;
        if (s == t) {
            cout << need << endl;
            cout << start << endl;
            continue;
        }
        ll l = 0, r = 1e15;
        while (l < r) {
            ll m = (l + r) / 2;
            if (remSpoon(m).sp >= need) r = m;
            else l = m + 1;
        }
        cout << l << endl;
        rat res = remSpoon(l);
        cout << start;
        for (ll i: res.path) {
            cout << '-';
            if (i < 26) cout << (char) (i + 'A');
            else cout << (char) (i - 26 + 'a');
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}