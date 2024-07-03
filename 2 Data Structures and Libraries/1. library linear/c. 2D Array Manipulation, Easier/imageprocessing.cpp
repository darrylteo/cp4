#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // read data
    int H, W, N, M;
    cin >> H >> W >> N >> M;
    vector<vector<int>> grid(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
        {
            int x;
            cin >>x;
            grid[i][j] = x;
        }
    }
    vector<vector<int>> conv(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >>x;
            conv[i][j] = x;
        }
    }
    // flip row
    for (int i = 0; i < N; i++) {
        reverse(conv[i].begin(), conv[i].end());
    }
    // flip col
    reverse(conv.begin(), conv.end());
    // convolution
    vector<vector<int>> ans(H - N + 1, vector<int>(W - M + 1, 0));
    for (int i = 0; i < H - N + 1; i++) {
        for (int j = 0; j < W - M + 1; j++)
        {
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < M; l++)
                {
                    ans[i][j] += grid[i + k][j + l] * conv[k][l];
                }
            }
        }
    }
    // print answer
    for (int i = 0; i < H - N + 1; i++) {
        for (int j = 0; j < W - M + 1; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
