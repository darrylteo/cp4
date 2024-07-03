#include <bits/stdc++.h>

using namespace std;

// The incidence matrix of a graph gives the (0,1)-matrix which has a
// row for each vertex and column for each edge,
// and (v,e)=1 iff vertex v is incident upon edge e (Skiena 1990, p. 135).
// this means for
// 1 1 0
// 0 1 1
// 1 0 1
// col 1 means edge 1 touches vertex 1 and 3
// col 2 means edge 2 touches vertex 2 and 3
// col 3 means edge 3 touches vertex 1 and 3
// i will assume they are just asking us to check if each edge touches 2 vertices
// and each edge is unique
// corner case: ok to have points but no edges but not ok to have edges but no points

bool isValid(vector<vector<int>> &matrix) {
    // check if each edge touches 2 vertices
    for (int i = 0; i < matrix[0].size(); ++i) {
        int count = 0;
        for (int j = 0; j < matrix.size(); ++j) {
            if (matrix[j][i] == 1) {
                ++count;
            }
        }
        if (count != 2) {
            return false;
        }
    }

    // check if each edge is unique
    // transpose matrix to compare cols directly ("==")
    vector<vector<int>> transposed(matrix[0].size(), vector<int>(matrix.size(), 0));
    for (int i = 0; i < matrix[0].size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            transposed[i][j] = matrix[j][i];
        }
    }
    for (int i = 0; i < transposed.size(); ++i) {
        for (int j = i + 1; j < transposed.size(); ++j) {
            if (transposed[i] == transposed[j]) {
                return false;
            }
        }
    }


    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (m == 0) {
            cout << "Yes" << endl;
            continue;
        } else if (n == 0) {
            cout << "No" << endl;
            continue;
        }
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }
        if (isValid(matrix)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
