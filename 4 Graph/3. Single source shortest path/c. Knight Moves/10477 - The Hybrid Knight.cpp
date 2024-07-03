#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct q {
    int r, c, type, cost;
};

const int drK[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dcK[] = {1, -1, 1, -1, 2, -2, 2, -2};
const int drMK[] = {3, 3, -3, -3, 1, 1, -1, -1};
const int dcMK[] = {1, -1, 1, -1, 3, -3, 3, -3};
const int drP[] = {0, 0, 1, -1};
const int dcP[] = {1, -1, 0, 0};
const int drP2[] = {1, -1, 1, -1};
const int dcP2[] = {1, -1, -1, 1}; // last move pawn

// 0 = knight visit, 1 = mutant knight visit, 2 = pawn visit
int visited[3][25][25], N, S, s, t, sr, sc, tr, tc, cost;
queue<q> qs;

inline void moveKnight(int r, int c) {
    for (int i = 0; i < 8; i++) {
        int nr = r + drK[i], nc = c + dcK[i];
        if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[0][nr][nc]) {
            visited[0][nr][nc] = 1;
            qs.push({nr, nc, 1, cost + 1});
        }
    }
}

inline void moveMutantKnight(int r, int c) {
    for (int i = 0; i < 8; i++) {
        int nr = r + drMK[i], nc = c + dcMK[i];
        if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[1][nr][nc]) {
            visited[1][nr][nc] = 1;
            qs.push({nr, nc, 2, cost + 1});
        }
    }
}

inline void movePawn(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + drP[i], nc = c + dcP[i];
        if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[2][nr][nc]) {
            visited[2][nr][nc] = 1;
            qs.push({nr, nc, 0, cost + 1});
        }
    }
}

inline void movePawnLast(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + drP2[i], nc = c + dcP2[i];
        if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
            if (nr == tr && nc == tc) {
                visited[2][nr][nc] = 1;
            }
        }
    }
}

inline int solve() {
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < 3; ++i) {
        visited[i][sr][sc] = 1;
        qs.push({sr, sc, i, 0});
    }
    while (!qs.empty()) {
        q fr = qs.front();
        qs.pop();
        int r = fr.r, c = fr.c, type = fr.type;
        cost = fr.cost;

        if (type == 0) {
            moveKnight(r, c);
        } else if (type == 1) {
            moveMutantKnight(r, c);
        } else if (type == 2) {
            movePawn(r, c);
            movePawnLast(r, c);
        }

        // important to break out asap don't wait for the (tr,tc) to appear in front of queue
        // partly due to how movePawnLast is implemented (didn't add to queue)
        for (int i = 0; i < 3; i++) {
            if (visited[i][tr][tc]) {
                return cost + 1;
            }
        }
    }
    return 0;
}

// ref: https://theriseofdavid.github.io/2021/09/20/UVa/UVa10477/
// initial idea was to allow a revisit as long as cost was lower than or equal to the previous visit
// similar to what i did in 633 - A Chess Knight
// slow for udebug 8seconds
// this is more efficient only 1 visit per type

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases = 1;
    while (cin >> N >> S, N) {
        cout << "Set " << cases++ << ":\n";

        for (int i = 0; i < S; i++) {
            cin >> s >> t;
            s--, t--;
            sr = s / N, sc = s % N, tr = t / N, tc = t % N;
            cout << solve() << endl;
            qs = queue<q>();
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}