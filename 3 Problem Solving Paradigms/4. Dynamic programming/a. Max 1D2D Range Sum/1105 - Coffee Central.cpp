#include <bits/stdc++.h>

using namespace std;

// ref: https://morris821028.github.io/2015/04/27/uva-1105/

int sum[2048][2048];

// this guy is good... without this can't relate to 2d sum
void rotate(int x, int y, int &tx, int &ty, int dx, int dy) {
    tx = x - y + dy;
    ty = x + y;
}

void query(int limit, int dx, int dy) {
    int best = 0, bestx = 1, besty = 1;
    int tx, ty;
    // for each point, find how many shops can reach with this limit
    // j first since minimal y 1st
    for (int j = 1; j <= dy; j++) {
        for (int i = 1; i <= dx; i++) {
            rotate(i, j, tx, ty, dx, dy);
            int x1 = max(1, tx - limit);
            int y1 = max(1, ty - limit);
            int x2 = min(dx + dy, tx + limit);
            int y2 = min(dx + dy, ty + limit);
            int s = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
            if (s > best) {
                best = s;
                bestx = i;
                besty = j;
            }
        }
    }
    cout << best << " (" << bestx << "," << besty << ")\n";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int dx, dy, n, q;
    int x, y, tx, ty, limit, cases = 0;
    while (cin >> dx >> dy >> n >> q) {
        if (dx == 0 && dy == 0 && n == 0 && q == 0) break;
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            rotate(x, y, tx, ty, dx, dy);
            sum[tx][ty]++;
        }
        for (int i = 1; i <= dx + dy; i++) {
            int s = 0; // to quickly calculate the sum (no need inclusion exclusion)
            for (int j = 1; j <= dx + dy; j++) {
                s += sum[i][j];
                sum[i][j] = sum[i - 1][j] + s;
            }
        }
        cout << "Case " << ++cases << ":\n";
        for (int i = 0; i < q; i++) {
            cin >> limit;
            query(limit, dx, dy);
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


