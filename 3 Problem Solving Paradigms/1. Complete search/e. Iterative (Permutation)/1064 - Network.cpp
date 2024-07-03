#include <bits/stdc++.h>

using namespace std;

// the permutation aspect is... if we have 2 messages, let all of 1 go 1st, then let all of 2 go next
// then let all of 2 go 1st, then let all of 1 go next etc for more numbers 5! total permutations
// thought it was easy but the consecutive part tripped me up

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, caseNum = 1;
    while (cin >> N >> M, N && M) {
        vector<int> msgSize(N), msgOrder(N);
        for (int i = 0; i < N; ++i) {
            cin >> msgSize[i];
            msgOrder[i] = i;
        }
        vector<vector<int>> packetArrivals;
        for (int i = 0; i < M; ++i) {
            int msg, start, end;
            cin >> msg >> start >> end;
            --msg;
            packetArrivals.push_back({msg, start, end});
        }

        int overallBestSize = INT_MAX;
        // for each permutation do
        do {
            vector<int> localMsgOrder = msgOrder, currByte(N, 1);
            int maxSize = 0, currSize = 0;
            // set stores start and end bytes of buffered packets
            // buffer[0] stores all buffered packets for 1st message
            vector<set<pair<int, int>>> buffer(N);
            for (int i = 0; i < M; ++i) {
                int msg, start, end, currMsg = localMsgOrder.back();
                // clear buffer for currMsg if possible (since there may be backlog for message 2, if 1 went first)
                // check if any buffered packets can go through. set is sorted by start byte
                while (!buffer[currMsg].empty()) {
                    auto it = buffer[currMsg].begin();
                    if (it->first == currByte[currMsg]) {
                        currByte[currMsg] = it->second + 1;
                        currSize -= it->second - it->first + 1;
                        buffer[currMsg].erase(it);
                    } else {
                        break;
                    }
                }

                msg = packetArrivals[i][0], start = packetArrivals[i][1], end = packetArrivals[i][2];
                if (msg == currMsg) {
                    if (start == currByte[msg]) {
                        // this message can go through directly
                        currByte[msg] = end + 1;
                        // check if any buffered packets can go through. set is sorted by start byte
                        while (!buffer[msg].empty()) {
                            auto it = buffer[msg].begin();
                            if (it->first == currByte[msg]) {
                                currByte[msg] = it->second + 1;
                                currSize -= it->second - it->first + 1;
                                buffer[msg].erase(it);
                            } else {
                                break;
                            }
                        }
                        // if reach end of message, go to next currMsg
                        if (currByte[msg] == msgSize[msg] + 1) {
                            localMsgOrder.pop_back();
                        }
                    } else {
                        // this message has to be buffered
                        buffer[msg].insert({start, end});
                        currSize += end - start + 1;
                    }
                } else {
                    // we definitely add to buffer if it is not currMsg
                    buffer[msg].insert({start, end});
                    currSize += end - start + 1;
                }
                maxSize = max(maxSize, currSize);
            }
            overallBestSize = min(overallBestSize, maxSize);
        } while (next_permutation(msgOrder.begin(), msgOrder.end()));

        cout << "Case " << caseNum++ << ": " << overallBestSize << "\n\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
