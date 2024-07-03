#include <bits/stdc++.h>

using namespace std;

// https://en.wikipedia.org/wiki/Pr%C3%BCfer_sequence
// TLE if do it the wikipedia way
// book says use priority queue
// should be retrieving the smallest node with degree 1
// some fail conditions:
// 1. out of bounds (node val > n+1)
// 2. no leaf nodes (degree 1) to insert

// i would say it is a tough question if no have clue from book
// btw mystery of why my code is slow, is solved!!! endl is slow. use \n instead!!!

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // +2: 1-indexed and there are n+1 nodes
    // val = 1: appears in sequence +1
    vector<int> degree(n + 2), ans;
    for (int i = 1; i < n + 2; ++i) { // wiki says add 1 to each degree
        degree[i] = 1;
    }
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int>> pq; // min heap of nodes with degree 1
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > n + 1) {
            cerr << "Error\n";
            return 0;
        }
        degree[a[i]]++;
    }

    // important caveat. do not need to add last (index) edge
    // since this version of prufer does not leave last 2 nodes alone
    // we can never remove the last edge earlier than the last iteration
    // intuitive proof :P. there can never be less than 2 nodes with degree 1 for an ACYCLIC graph (tree here)
    // we always remove the smaller node first, so the last edge will always be the last to be removed
    // actual proof. there are n-1 edges in a tree. sum of degrees is 2(n-1) (handshaking lemma)
    // corner case: if straight line, i.e. 2 leaves, sum of degrees = 2*(n-2) for the internal nodes + 2 for leaves = 2n-2 (OK)
    // if maximum leaf nodes, i.e. n-1 leaves connect to single "source" ("star" shaped?), sum of degrees = (n-1) for the internal node + n-1 for leaves = 2n-2 (OK)
    // other cases can easily prove by induction.. therefore minimum is 2 leaves hence last edge must be last to be removed so don't add to pq (OR if we remove it is error)
    for (int i = 1; i < n + 1; i++) {
        if (degree[i] == 1) pq.push(i);
    }

    bool allPass = true;
    for (int i = 0; i < n; i++) {
        if (pq.empty()) {
            allPass = false;
            break;
        }
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
        degree[u]--;
        degree[a[i]]--;
        if (degree[a[i]] == 1) pq.push(a[i]);
    }

    if (allPass) {
        for (int i: ans) cout << i << "\n";
    } else {
        cout << "Error\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;

}