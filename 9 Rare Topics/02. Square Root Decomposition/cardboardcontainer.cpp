#include <bits/stdc++.h>

using namespace std;

// V = l * w * h
// SA = 2lw + 2lh + 2wh
// eliminate h. test all possible w and l, and see if V%lw == 0
// the topic notes in book are kinda complicated but the starred question is just silly
// maybe a O(sqrt(V)) algo can get all factors up to sqrt(V) in O(V^0.25) then try these factors only in O(sqrt(V))

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int V;
    cin >> V;
    int bestSA = INT_MAX;
    for (int l = 1; l <= sqrt(V) + 1; l++) {
        for (int w = 1; w <= sqrt(V) + 1; w++) {
            if (V % (l * w) == 0) {
                int h = V / (l * w);
                int SA = 2 * l * w + 2 * l * h + 2 * w * h;
                bestSA = min(bestSA, SA);
            }
        }
    }
    cout << bestSA << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}