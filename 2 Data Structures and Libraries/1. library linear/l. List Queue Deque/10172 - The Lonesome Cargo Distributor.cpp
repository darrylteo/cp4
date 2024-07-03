#include <bits/stdc++.h>

using namespace std;

// simplified problem statement:
// given a stack of N stations, each has a queue of capacity Q, with some queues empty (0), some have items (5 2 3) means station 5 has items 2 and 3 in queue
// given a carrier stack that can hold S items, move it around the stations, push permanent if items and station no. is same, else push onto station queue
// pick up items from queue if carrier has space and queue has items.
// continue and count moves until all stations are empty

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    while (T--) {
        int N, S, Q;
        cin >> N >> S >> Q;
        stack<int> carrier;
        vector<queue<int>> stations(N);
        for (int i = 0; i < N; i++) {
            int Qi;
            cin >> Qi;
            for (int j = 0; j < Qi; j++) {
                int x;
                cin >> x;
                stations[i].push(x - 1);
            }
        }
        int currStation = 0;
        int moves = 0;
        while (true) {
            // unload carrier
            while (!carrier.empty()) {
                if (carrier.top() == currStation) {
                    carrier.pop();
                } else if (stations[currStation].size() < Q) {
                    stations[currStation].push(carrier.top());
                    carrier.pop();
                } else {
                    break;
                }
                moves++;
            }
            // load carrier
            while (carrier.size() < S && !stations[currStation].empty()) {
                carrier.push(stations[currStation].front());
                stations[currStation].pop();
                moves++;
            }
            // check if done
            bool done = true;
            for (int i = 0; i < N; i++) {
                if (!stations[i].empty()) {
                    done = false;
                    break;
                }
            }
            if (!carrier.empty()) {
                done = false;
            }
            if (done) {
                break;
            }
            // move to next station
            currStation = (currStation + 1) % N;
            moves += 2;
        }
        cout << moves << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
