#include <bits/stdc++.h>

using namespace std;

struct ant {
    int L, W, H, V;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    while (cin >> T, T) {
        vector<ant> ants(T);
        int maxH = 0;
        for (int i = 0; i < T; ++i) {
            cin >> ants[i].L >> ants[i].W >> ants[i].H;
            ants[i].V = ants[i].L * ants[i].W * ants[i].H;
            maxH = max(maxH, ants[i].H);
        }

        int count = 0;
        int antNo[101] = {};
        for (int i = 0; i < T; ++i) {
            if (ants[i].H == maxH) {
                count++;
                antNo[i] = 1;
            }
        }

        if (count == 1) {
            for (int i = 0; i < T; ++i) {
                if (ants[i].H == maxH) {
                    cout << ants[i].V << endl;
                    break;
                }
            }
        } else {
            int maxV = 0;
            for (int i = 0; i < T; ++i) {
                if (antNo[i] == 1) {
                    maxV = max(maxV, ants[i].V);
                }
            }
            cout << maxV << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
