#include <bits/stdc++.h>

using namespace std;

int A, B;



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (scanf("%d %d", &A, &B), A) {
        vector<int> X, Y;
        for (int i = 0; i < A; i++) {
            int x;
            scanf("%d", &x);
            X.push_back(x);
        }
        for (int i = 0; i < B; i++) {
            int y;
            scanf("%d", &y);
            Y.push_back(y);
        }

        // clear the non-unique elements
        X.erase( unique( X.begin(), X.end() ), X.end() );
        Y.erase( unique( Y.begin(), Y.end() ), Y.end() );

        // if == end means not found, so we can trade that card
        int AMaxTrade = 0, BMaxTrade = 0;
        for (int i = 0; i < X.size(); i++) {
            if (find(Y.begin(), Y.end(), X[i]) == Y.end()) {
                AMaxTrade++;
            }
        }
        for (int i = 0; i < Y.size(); i++) {
            if (find(X.begin(), X.end(), Y[i]) == X.end()) {
                BMaxTrade++;
            }
        }

        printf("%d\n", min(AMaxTrade, BMaxTrade));
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


