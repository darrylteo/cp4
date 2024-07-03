#include <bits/stdc++.h>

using namespace std;

// apparently this is a very standard problem running median ._.
// tried "normal" way but O(N) not accepted

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        long long mySum = 0;
        priority_queue<int> maxHeap, minHeap;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (maxHeap.empty() || x < maxHeap.top()) {
                maxHeap.push(x);
            } else {
                minHeap.push(-x);
            }
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(-maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(-minHeap.top());
                minHeap.pop();
            }
            if (maxHeap.size() == minHeap.size()) {
                mySum += (maxHeap.top() - minHeap.top()) / 2;
            } else {
                mySum += maxHeap.top();
            }
        }
        cout << mySum << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




