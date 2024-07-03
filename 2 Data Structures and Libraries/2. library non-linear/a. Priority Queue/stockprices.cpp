#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        priority_queue<pair<int, int>> ask, bid;
        string order, s;
        int price, quantity, lastPrice = -1;
        cin >> x;
        while (x--) {
            cin >> order >> quantity >> s >> s >> price;
            if (order == "sell") {
                ask.push({-price, quantity}); // the cheapest sale will get filled
            } else {
                bid.push({price, quantity}); // the most expensive purchase will get filled
            }
            while (!ask.empty() && !bid.empty() && -ask.top().first <= bid.top().first) { // can fill order
                int askPrice = -ask.top().first;
                int askQuantity = ask.top().second;
                int bidPrice = bid.top().first;
                int bidQuantity = bid.top().second;
                if (askQuantity > bidQuantity) {
                    askQuantity -= bidQuantity;
                    ask.pop();
                    ask.push({-askPrice, askQuantity});
                    bid.pop();
                } else if (askQuantity < bidQuantity) {
                    bidQuantity -= askQuantity;
                    bid.pop();
                    bid.push({bidPrice, bidQuantity});
                    ask.pop();
                } else {
                    ask.pop();
                    bid.pop();
                }
                lastPrice = askPrice; // must have someone willing sell at this price
            }
            cout << (ask.empty() ? "-" : to_string(-ask.top().first)) << " "
                 << (bid.empty() ? "-" : to_string(bid.top().first)) << " " << (lastPrice == -1 ? "-" : to_string(lastPrice)) << endl;
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
