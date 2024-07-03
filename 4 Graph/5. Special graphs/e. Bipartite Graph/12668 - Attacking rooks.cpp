#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

char board[101][101];
int adjMat[5005][5005], fakeRow[101][101], match[5005], visited[5005];
int r, c;

inline int Aug(int u) {
    for (int v = 0; v < c; ++v) {
        if (adjMat[u][v] && !visited[v]) {
            visited[v] = 1;
            if (match[v] == -1 || Aug(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

// hard qn
// ref: https://asdfcoding.wordpress.com/2014/06/09/12668-attacking-rooks-uva/
// also use visualgo to see how it works originally without pawn block
// while ref gives clear explanation, code is slow.


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    while (cin >> N) {
        r = c = 0;
        memset(adjMat, 0, sizeof adjMat);
        memset(fakeRow, -1, sizeof fakeRow);
        for (int i = 0; i < N; ++i) cin >> board[i];
        int ix, iy;
        for (int i = 0; i < N; ++i) {
            ix = -1;
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 'X') {
                    for (int w = ix + 1; w <= j - 1; ++w) fakeRow[i][w] = r;
                    if (j - 1 >= ix + 1) r++;
                    ix = j;
                }
            }
            for (int w = ix + 1; w < N; ++w) fakeRow[i][w] = r; // last few cols
            if (N - 1 >= ix + 1) r++;
        }
        for (int j = 0; j < N; ++j) {
            iy = -1;
            for (int i = 0; i < N; ++i) {
                if (board[i][j] == 'X') {
                    for (int w = iy + 1; w <= i - 1; ++w) {
                        adjMat[fakeRow[w][j]][c] = 1;
                    }
                    if (i - 1 >= iy + 1) c++;
                    iy = i;
                }
            }
            for (int w = iy + 1; w < N; ++w) {
                if (fakeRow[w][j] != -1) adjMat[fakeRow[w][j]][c] = 1;
            }
            if (N - 1 >= iy + 1) c++;
        }

        memset(match, -1, sizeof match);
        int MCBM = 0;
        for (int i = 0; i < r; ++i) {
            memset(visited, 0, sizeof visited);
            MCBM += Aug(i);
        }
        cout << MCBM << endl;
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

