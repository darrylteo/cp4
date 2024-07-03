#include <bits/stdc++.h>

using namespace std;

// i was wondering why the title was angry birds ._. silly pun

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int p, c;
        vector<int> vP, vC;
        cin >> p >> c;
        for(int i = 0; i < p; ++i) {
            int x;
            cin >> x;
            vP.push_back(x);
        }
        for(int i = 0; i < c; ++i) {
            int x;
            cin >> x;
            vC.push_back(x);
        }
        sort(vP.begin(), vP.end());
        sort(vC.begin(), vC.end());
        if (p == 0) cout << "0 0\n"; // no producers, sell cheapest value, all happy
        else if (c == 0) cout << vP.back() <<" 0\n"; // no consumers, sell most expensive value, all happy
        else {
            int bestPriceP, bestAngryP = INT_MAX;
            // check for each producer price, how many angry consumer
            // there will be p-i-1 angry producers.
            for (int i = 0; i < p; ++i) {
                int angryConsumers = lower_bound(vC.begin(), vC.end(), vP[i]) - vC.begin();
                int angryProducers = p - i - 1;
                if (angryConsumers + angryProducers < bestAngryP) {
                    bestPriceP = vP[i];
                    bestAngryP = angryConsumers + angryProducers;
                }
            }

            // check for each consumer price, how many angry producer
            // there will be i angry consumers.
            int bestPriceC, bestAngryC = INT_MAX;
            for (int i = 0; i < c; ++i) {
                int angryProducers = p - (lower_bound(vP.begin(), vP.end(), vC[i]) - vP.begin());
                int angryConsumers = i;
                if (angryConsumers + angryProducers < bestAngryC) {
                    bestPriceC = vC[i];
                    bestAngryC = angryConsumers + angryProducers;
                }
            }

            // corner case. if bestAngry is equal to p, we could set price at 0 and make p producers angry
            // same angriness, lower price
            if (min(bestAngryP, bestAngryC) == p) {
                cout << "0 " << p << "\n";
                continue;
            }

            if (bestAngryP == bestAngryC) {
                if (bestPriceP < bestPriceC) cout << bestPriceP << " " << bestAngryP << "\n";
                else cout << bestPriceC << " " << bestAngryC << "\n";
            } else if (bestAngryP < bestAngryC) cout << bestPriceP << " " << bestAngryP << "\n";
            else cout << bestPriceC << " " << bestAngryC << "\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

