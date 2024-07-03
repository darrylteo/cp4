#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    while (T--){
        int C = 0, H = 0, O = 0, N = 0;
        string formula;
        cin >> formula;
        for (int i = 0; i < formula.size(); ++i) {
            int count = 0;
            int pos = i;
            // idk why static_cast<unsigned char> is needed
            // check how many of current element
            while (pos+1 < formula.size() && isdigit(static_cast<unsigned char>(formula[pos+1]))){
                count = count * 10 + (formula[pos+1] - '0');
                pos++;
            }
            if (count == 0) count = 1;
            // add to total
            if (formula[i] == 'C') C += count;
            else if (formula[i] == 'H') H += count;
            else if (formula[i] == 'O') O += count;
            else if (formula[i] == 'N') N += count;
            // move to next element
            i = pos;
        }
        double total = 12.01 * C + 1.008 * H + 16.00 * O + 14.01 * N;
        cout << fixed << setprecision(3) << total << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

