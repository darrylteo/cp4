#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;

    // insert delete O(log n), get min/max O(1)
    priority_queue<int> pq;

    int currMoose;
    vector<pair<int,int>> meese;
    int year, strength, karlYear, karlStrength;
    // get karl
    cin >> karlYear >> karlStrength;
    meese.emplace_back(karlYear, karlStrength);
    // get the rest
    while (cin >> year >> strength) {
        meese.emplace_back(year, strength);
    }
    sort(meese.begin(), meese.end());
    // first competition with k meese
    for (int i = 0; i < k; i++) {
        pq.push(meese[i].second);
    }
    // check if karl won
    if (pq.top() == karlStrength) {
        cout << karlYear << endl;
        return 0;
    }
    // if not, remove winner and add next
    pq.pop();
    int i = k;
    while (i < n + k - 1) {
        pq.push(meese[i].second);
        if (pq.top() == karlStrength) {
            cout << meese[i].first << endl;
            return 0;
        }
        pq.pop();
        i++;
    }

    // output
    if (i == n + k - 1)
        cout << "unknown" << endl;
    else
        cout << meese[i - 1].first << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
