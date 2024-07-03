#include <bits/stdc++.h>

using namespace std;

int N, S, bestSize;
vector<int> A, tmp;
vector<pair<int, vector<int>>> success; // {size, values}

void solve(int i) {
    tmp.push_back(A[i]);
    // very important to prune just like how we use breaks and goto in (nested) for loops
    if (tmp.size() > bestSize) {
        tmp.pop_back();
        return;
    }
    int sum = accumulate(tmp.begin(), tmp.end(), 0);
    if (sum == S) {
        success.emplace_back(tmp.size(), tmp);
        bestSize = tmp.size();
        tmp.pop_back();
        return;
    }
    if (sum > S) {
        tmp.pop_back();
        return;
    }
    for (int j = 0; j < A.size(); ++j) {
        solve(j);
    }
    tmp.pop_back();
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        bestSize = INT_MAX;
        success.clear();
        A.clear();
        cout << "Case " << i << ": ";
        cin >> N >> S;
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            A.push_back(x);
        }
        sort(A.begin(), A.end(), greater<int>());
        for (int j = 0; j < A.size(); ++j) {
            solve(j);
        }

        if (success.empty()) {
            cout << "impossible" << '\n';
        } else {
            sort(success.begin(), success.end(), [](const pair<int, vector<int>> &a, const pair<int, vector<int>> &b) {
                if (a.first == b.first) {
                    for (int i = 0; i < a.second.size(); ++i) {
                        if (a.second[i] == b.second[i]) {
                            continue;
                        }
                        return a.second[i] > b.second[i]; // value descending
                    }
                }
                return a.first < b.first; // size ascending
            });
            cout << '[' << success[0].first << ']' << ' ';
            for (int j = 0; j < success[0].second.size() - 1; ++j) {
                cout << success[0].second[j] << ' ';
            }
            cout << success[0].second[success[0].second.size() - 1] << '\n';

        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

