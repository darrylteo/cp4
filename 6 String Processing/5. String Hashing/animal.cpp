#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
    ll hash1, hash2, l, r;
};

struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int>& v) const {
        return v.first * 31 + v.second;
    }
};

node Node[200005], Node2[200005];
ll p1 = 131, p2 = 313, MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
int pos, cnt, ans = 0;
string s;
unordered_set<pair<ll, ll>, pair_hash> mp;

vector<ll> p1powers, p2powers;  // 2^i mod M
void computePpowers(int n) {
    p1powers.push_back(1);
    for (int i = 1; i <= n; i++) {
        p1powers.push_back((p1powers[i - 1] * p1) % MOD1);
    }
    p2powers.push_back(1);
    for (int i = 1; i <= n; i++) {
        p2powers.push_back((p2powers[i - 1] * p2) % MOD2);
    }
}

ll fhash(int i, ll p) { return (p == p1) ? p1powers[i] : p2powers[i]; }

inline int build() {
    int id = cnt++;
    Node[id] = {1, 1, -1, -1};
    // collect the entire node name
    if (isdigit(s[pos])) {
        string curr = "";
        while (isdigit(s[pos])) {
            curr += s[pos];
            pos++;
        }
        Node[id].hash1 = fhash(stoi(curr), p1);
        Node[id].hash2 = fhash(stoi(curr), p2);
    }
    // if start function ()
    if (s[pos] == '(') {
        pos++;
        Node[id].l = build();
        Node[id].hash1 = (Node[id].hash1 + Node[Node[id].l].hash1) % MOD1;
        Node[id].hash2 = (Node[id].hash2 + Node[Node[id].l].hash2) % MOD2;
        pos++;
        Node[id].r = build();
        Node[id].hash1 = (Node[id].hash1 + Node[Node[id].r].hash1) % MOD1;
        Node[id].hash2 = (Node[id].hash2 + Node[Node[id].r].hash2) % MOD2;
        pos++;
        mp.insert(make_pair(Node[id].hash1, Node[id].hash2));
    }

    return id; // return the id of the node which will be stored in the left and right subtrees
}

int build2() {
    int id = cnt++;
    Node2[id] = {1, 1, -1, -1};
    // collect the entire node name
    if (isdigit(s[pos])) {
        string curr = "";
        while (isdigit(s[pos])) {
            curr += s[pos];
            pos++;
        }
        Node2[id].hash1 = fhash(stoi(curr), p1);
        Node2[id].hash2 = fhash(stoi(curr), p2);
    }
    // if start function ()
    if (s[pos] == '(') {
        pos++;
        Node2[id].l = build2();
        Node2[id].hash1 = (Node2[id].hash1 + Node2[Node2[id].l].hash1) % MOD1;
        Node2[id].hash2 = (Node2[id].hash2 + Node2[Node2[id].l].hash2) % MOD2;
        pos++;
        Node2[id].r = build2();
        Node2[id].hash1 = (Node2[id].hash1 + Node2[Node2[id].r].hash1) % MOD1;
        Node2[id].hash2 = (Node2[id].hash2 + Node2[Node2[id].r].hash2) % MOD2;
        pos++;
        if (mp.find(make_pair(Node2[id].hash1, Node2[id].hash2)) != mp.end()) {
            ans++;
        }
    }

    return id; // return the id of the node which will be stored in the left and right subtrees
}

void removeSpaces() {
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
}

// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_6_String_Processing/String_Matching_with_Hashing/kattis_animal.cpp
// constructing trees is ok since we did that in a few chapters ago in 1. Ad Hoc String Processing (Harder) - recursive - subexpression.cpp
// but didn't know how to add the hashes. stuck very long for example (1,3) and (2,2) both counted same tree
// the ref showed how to do it. we need to add the hashes of the left and right subtrees
// e.g. 313^1 + 313^3 for (1,3) and 313^2 + 313^2 for (2,2)
// good trick to use!

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    computePpowers(n + 9);

    mp.clear();
    cnt = pos = 0;
    cin >> s;
    removeSpaces();
    build();

    cnt = pos = 0;
    cin >> s;
    removeSpaces();
    build2();

    cout << ans + n << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
