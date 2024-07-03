#include <bits/stdc++.h>

using namespace std;

// actually no need tm struct, just use int ._.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    tm wifeStart = {}, wifeEnd = {}, meetingStart = {}, meetingEnd = {};
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d:%d %d:%d", &wifeStart.tm_hour, &wifeStart.tm_min, &wifeEnd.tm_hour, &wifeEnd.tm_min);
        scanf("%d:%d %d:%d", &meetingStart.tm_hour, &meetingStart.tm_min, &meetingEnd.tm_hour, &meetingEnd.tm_min);
        // wife first, meeting later
        if (wifeStart.tm_hour > meetingStart.tm_hour || (wifeStart.tm_hour == meetingStart.tm_hour && wifeStart.tm_min > meetingStart.tm_min)){
            swap(wifeStart, meetingStart);
            swap(wifeEnd, meetingEnd);
        }
        if (wifeEnd.tm_hour < meetingStart.tm_hour || (wifeEnd.tm_hour == meetingStart.tm_hour && wifeEnd.tm_min < meetingStart.tm_min)){
            cout << "Case " << i << ": Hits Meeting" << endl;
        } else {
            cout << "Case " << i << ": Mrs Meeting" << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}