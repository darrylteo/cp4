#include <bits/stdc++.h>

using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int x;
    priority_queue<int> maxHeap, minHeap;
    while (cin >> x) {
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
            cout << (maxHeap.top() - minHeap.top()) / 2 << endl;
        } else {
            cout << maxHeap.top() << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
