#include <bits/stdc++.h>

using namespace std;

int L; // length of the field
int N; // number of sprinklers
vector<int> posSprinks, maxSprinks;

// return total land covered
// idx of sprinkler, flow left, land covered
int totalLandCovered(int idx, int flowLeft, bitset<25> field) {
    if (idx == N || flowLeft == 0) return (int) field.count();
    int ans = 0;
    // skip this sprinkler
    ans = max(ans, totalLandCovered(idx + 1, flowLeft, field));
    // check from 1 flow to max(flowLeft, maxSprinks[idx])
    for (int i = 1; i <= maxSprinks[idx] && i <= flowLeft; ++i) {
        bitset<25> newField = field;
        for (int j = posSprinks[idx] - i; j <= posSprinks[idx] + i; ++j) {
            if (j >= 0 && j <= L) newField[j] = true;
        }
        ans = max(ans, totalLandCovered(idx + 1, flowLeft - i, newField));
    }
    return ans;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> L;
        cin >> N;
        posSprinks.resize(N);
        maxSprinks.resize(N);
        for (int i = 0; i < N; ++i) cin >> posSprinks[i];
        int C;
        cin >> C; // max total flow
        for (int i = 0; i < N; ++i) cin >> maxSprinks[i];
        cout << totalLandCovered(0, C, 0) << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}