#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// i will start from (R,0), go down 1 step to (R,1) and go clockwise. the number at layer R = R^3 - (R-1)^3
const int dirR[] = {-1, -1, 0, 1, 1, 0};
const int dirC[] = {1, 0, -1, -1, 0, 1};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vi v;
    for (int i = 1; i <= 200; ++i) {
        v.push_back(i * i * i - (i - 1) * (i - 1) * (i - 1));
    }
    int n;
    while (cin >> n) {
        int R = lower_bound(v.begin(), v.end(), n) - v.begin() - 1;
        int currX = R, currY = 1, stepsLeft = n - v[R] - 1;
        if (R == -1) {
            cout << "0 0\n";
            continue;
        }
        for (int i = 0; i < 6; ++i) {
            int steps;
            if (i) {
                steps = min(stepsLeft, R + 1);
            } else {
                steps = min(stepsLeft, R);
            }
            currX += dirR[i] * steps;
            currY += dirC[i] * steps;
            stepsLeft -= steps;
            if (stepsLeft == 0) {
                cout << currX << " " << currY << '\n';
                break;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

