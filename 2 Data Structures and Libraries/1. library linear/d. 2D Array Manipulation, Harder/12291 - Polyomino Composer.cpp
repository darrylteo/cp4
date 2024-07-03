#include <bits/stdc++.h>

using namespace std;

bool solve (vector<vector<char>> bigPoly, vector<vector<char>> smallPoly) {
    int n = bigPoly.size();
    // strip small poly of empty rows and cols
    int top = 0, bottom = smallPoly.size() - 1, left = 0, right = smallPoly.size() - 1;
    for (int i = 0; i < smallPoly.size(); ++i) {
        bool flag = true;
        for (int j = 0; j < smallPoly.size(); ++j) {
            if (smallPoly[i][j] == '*') {
                flag = false;
                break;
            }
        }
        if (flag) {
            top++;
        } else {
            break;
        }
    }
    for (int i = smallPoly.size() - 1; i >= 0; --i) {
        bool flag = true;
        for (int j = 0; j < smallPoly.size(); ++j) {
            if (smallPoly[i][j] == '*') {
                flag = false;
                break;
            }
        }
        if (flag) {
            bottom--;
        } else {
            break;
        }
    }
    for (int i = 0; i < smallPoly.size(); ++i) {
        bool flag = true;
        for (int j = 0; j < smallPoly.size(); ++j) {
            if (smallPoly[j][i] == '*') {
                flag = false;
                break;
            }
        }
        if (flag) {
            left++;
        } else {
            break;
        }
    }
    for (int i = smallPoly.size() - 1; i >= 0; --i) {
        bool flag = true;
        for (int j = 0; j < smallPoly.size(); ++j) {
            if (smallPoly[j][i] == '*') {
                flag = false;
                break;
            }
        }
        if (flag) {
            right--;
        } else {
            break;
        }
    }
    vector<vector<char>> temp(bottom - top + 1, vector<char>(right - left + 1));
    for (int i = top; i <= bottom; ++i) {
        for (int j = left; j <= right; ++j) {
            temp[i - top][j - left] = smallPoly[i][j];
        }
    }
    smallPoly = temp;
    int height = smallPoly.size();
    int width = smallPoly[0].size();




    int total = 0, cnt = 0, matches = 0; // number of * in smallPoly
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j)
            if (smallPoly[i][j] == '*')
                total++;
    }
    for (int i = 0; i <= n - height; ++i) {
        for (int j = 0; j <= n - width; ++j) {
            cnt = 0;
            for (int k = 0; k < height; ++k) {
                for (int l = 0; l < width; ++l) {
                    if (bigPoly[i + k][j + l] == '*' && smallPoly[k][l] == '*') {
                        cnt++;
                    }
                }
            }
            if (cnt == total) {
                matches++;
                // remove the smallPoly from bigPoly
                for (int k = 0; k < height; ++k) {
                    for (int l = 0; l < width; ++l) {
                        if (smallPoly[k][l] == '*') {
                            bigPoly[i + k][j + l] = '.';
                        }
                    }
                }
            }
        }
    }

    if (matches == 2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, m;
    while (cin >> n >> m, n) {
        vector<vector<char>> bigPoly(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j) {
                bigPoly[i][j] = s[j];
            }
        }
        vector<vector<char>> smallPoly(m, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                smallPoly[i][j] = s[j];
            }
        }
        if (solve(bigPoly, smallPoly)) {
            cout << 1 << endl;
        } else {
            // TRANSLATED not TRANSPOSED -_-
//            vector<vector<char>> temp(m, vector<char>(m));
//            for (int i = 0; i < m; i++) {
//                for (int j = 0; j < m; j++)
//                    temp[i][j] = smallPoly[j][i];
//            }
//            smallPoly = temp;
//            if (solve(bigPoly, smallPoly)) {
//                cout << 1 << endl;
//            } else {
//                cout << 0 << endl;
//            }
            cout << 0 << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
