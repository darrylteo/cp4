#include <bits/stdc++.h>

using namespace std;

int getPrice(int CWH) {
    int price = 0;
    if (CWH <= 100) {
        price = CWH * 2;
    } else if (CWH <= 10000) {
        price = 100 * 2 + (CWH - 100) * 3;
    } else if (CWH <= 1000000) {
        price = 100 * 2 + 9900 * 3 + (CWH - 10000) * 5;
    } else {
        price = 100 * 2 + 9900 * 3 + 990000 * 5 + (CWH - 1000000) * 7;
    }
    return price;
}

int getCWH(int price) {
    int CWH = 0;
    if (price <= 200) {
        CWH = price / 2;
    } else if (price <= 29900) {
        CWH = 100 + (price - 200) / 3;
    } else if (price <= 4979900) {
        CWH = 10000 + (price - 29900) / 5;
    } else {
        CWH = 1000000 + (price - 4979900) / 7;
    }
    return CWH;
}

// make sure A pays less
int getDiff(int CWHA, int CWHB) {
    return getPrice(CWHB) - getPrice(CWHA);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // checking based on price works, but check CWH might be more logical
    int totalPrice, diff;
    while (cin >> totalPrice >> diff, totalPrice) {
        long long l = 0, r = getCWH(totalPrice)*10, CWHA, CWHB;
        while (l < r) {
            int mid = (l + r) / 2;
            CWHA = getCWH(mid);
            CWHB = getCWH(totalPrice) - CWHA;
            int currDiff = getDiff(CWHA, CWHB);
            if (currDiff == diff) {
                cout << getPrice(CWHA) << '\n';
                break;
            } else if (currDiff > diff) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
