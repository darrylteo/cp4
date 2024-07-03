#include <bits/stdc++.h>

using namespace std;

// follow clue from book. calculate total weight of 2^n subsets then minus subsets where weight < 200
// not too bad compared to previous qns (cuz of clue :|)

int n;
long long totalLightweight = 0;
vector<long long> fruits;

void dfs(int index, long long weight) {
    for (int i = index; i < n; ++i) {
        if (weight + fruits[i] < 200) {
            // add basket to light baskets
            totalLightweight += weight + fruits[i];
            weight += fruits[i];
            dfs(i + 1, weight);
            weight -= fruits[i];
        } else {
            // since we sorted, if this basket cannot, all later baskets cannot (prune)
            break;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    long long totalWeight = 0;
    for (int i = 0; i < n; ++i) {
        long long fruit;
        cin >> fruit;
        fruits.push_back(fruit);
        totalWeight += fruit;
    }
    sort(fruits.begin(), fruits.end());
    // each value will appear 2^n / 2 times. 2^n total combinations, divide 2 cuz half the time is 0 half the time is 1
    totalWeight *= (1LL << (n - 1));
    dfs(0,0);
    cout << totalWeight - totalLightweight << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

