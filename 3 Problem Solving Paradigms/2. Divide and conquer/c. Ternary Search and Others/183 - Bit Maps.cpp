#include <bits/stdc++.h>

using namespace std;

string type, bitmapFlat, s;
vector<vector<string>> bitmap;
int rows, cols, idx;

// subsection of bitmap we checking
void BtoD(const vector<vector<string>> &currBitMap, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    int ones = 0, zeroes = 0;
    for (int k = 0; k < i; ++k) {
        for (int l = 0; l < j; ++l) {
            if (currBitMap[k][l] == "1") {
                ones++;
            } else {
                zeroes++;
            }
        }
    }
    if (zeroes == 0) {
        s += '1';
        return;
    } else if (ones == 0) {
        s += '0';
        return;
    } else {
        s += 'D';
        int upSize = (i + 1) / 2;
        int downSize = i - upSize;
        int leftSize = (j + 1) / 2;
        int rightSize = j - leftSize;
        vector<vector<string>> upLeft(upSize, vector<string>(leftSize));
        vector<vector<string>> upRight(upSize, vector<string>(rightSize));
        vector<vector<string>> downLeft(downSize, vector<string>(leftSize));
        vector<vector<string>> downRight(downSize, vector<string>(rightSize));
        for (int k = 0; k < upSize; ++k) {
            for (int l = 0; l < leftSize; ++l) {
                upLeft[k][l] = currBitMap[k][l];
            }
        }
        for (int k = 0; k < upSize; ++k) {
            for (int l = leftSize; l < j; ++l) {
                upRight[k][l - leftSize] = currBitMap[k][l];
            }
        }
        for (int k = upSize; k < i; ++k) {
            for (int l = 0; l < leftSize; ++l) {
                downLeft[k - upSize][l] = currBitMap[k][l];
            }
        }
        for (int k = upSize; k < i; ++k) {
            for (int l = leftSize; l < j; ++l) {
                downRight[k - upSize][l - leftSize] = currBitMap[k][l];
            }
        }
        BtoD(upLeft, upSize, leftSize);
        BtoD(upRight, upSize, rightSize);
        BtoD(downLeft, downSize, leftSize);
        BtoD(downRight, downSize, rightSize);
    }
}

// x y are the starting row and col. row and col is size
void DtoB(int numRow, int numCol, int x, int y) {
    if (numRow == 0 || numCol == 0) {
        return;
    }
    idx++;
    if (idx == s.size()) {
        return;
    }
    // fill up this subsection with the char
    if (s[idx] == '1' || s[idx] == '0') {
        for (int k = x; k < x + numRow; ++k) {
            for (int l = y; l < y + numCol; ++l) {
                bitmap[k][l] = s[idx];
            }
        }
    } else {
        int upSize = (numRow + 1) / 2;
        int downSize = numRow - upSize;
        int leftSize = (numCol + 1) / 2;
        int rightSize = numCol - leftSize;
        DtoB(upSize, leftSize, x, y);
        DtoB(upSize, rightSize, x, y + leftSize);
        DtoB(downSize, leftSize, x + upSize, y);
        DtoB(downSize, rightSize, x + upSize, y + leftSize);
    }
}

// not entry level! >:( i guess difficulty (kattis rating) 4.4

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> type) {
        s = "";
        if (type == "B") {
            cin >> rows >> cols;
            bitmapFlat = "";
            // qn states input may be spread over a few lines with max 50 chars per line
            while (bitmapFlat.size() < rows * cols) {
                string tmp;
                cin >> tmp;
                bitmapFlat += tmp;
            }
            cout << "D" << setw(4) << rows << setw(4) << cols << '\n';
            bitmap.clear();
            bitmap.resize(rows, vector<string>(cols));
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    bitmap[i][j] = bitmapFlat[i * cols + j];
                }
            }
            BtoD(bitmap, rows, cols);
            for (int i = 0; i < s.size(); ++i) {
                if (i % 50 == 0 && i != 0) {
                    cout << '\n';
                }
                cout << s[i];
            }
        } else if (type == "D") {
            idx = -1;
            // BUT the 50 char rule doesn't apply here (thankfully)
            cin >> rows >> cols >> s;
            cout << "B" << setw(4) << rows << setw(4) << cols << '\n';
            bitmap.clear();
            bitmap.resize(rows, vector<string>(cols));
            DtoB(rows, cols, 0, 0);
            string tmpPrint;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    tmpPrint += bitmap[i][j];
                }
            }
            for (int i = 0; i < tmpPrint.size(); ++i) {
                if (i % 50 == 0 && i != 0) {
                    cout << '\n';
                }
                cout << tmpPrint[i];
            }
        } else if (type == "#") {
            break;
        }
        cout << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
