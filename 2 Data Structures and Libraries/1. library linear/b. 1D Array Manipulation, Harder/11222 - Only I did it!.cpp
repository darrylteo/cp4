#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ":" << endl;
        int N;
        vector<vector<int>> friends;
        vector<set<int>> friendsSet(3), friendsUnique(3);
        for (int j = 0; j < 3; j++) {
            cin >> N;
            vector<int> temp;
            for (int k = 0; k < N; k++) {
                int x;
                cin >> x;
                for (int otherFriend = 0; otherFriend < 3; otherFriend++) {
                    if (otherFriend != j)
                        friendsSet[otherFriend].insert(x); // add to other friends set to check against
                }
                temp.push_back(x); // always add to his own set
            }
            friends.push_back(temp);
        }

        // find unique numbers compared to other friends
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < friends[j].size(); k++) {
                if (friendsSet[j].find(friends[j][k]) == friendsSet[j].end()) {
                    friendsUnique[j].insert(friends[j][k]);
                }
            }
        }

        // qn ask for sorted SET !! -_-
        vector<vector<int>> friendsUniqueVec(3);
        for (int j = 0; j < 3; j++) {
            for (auto it = friendsUnique[j].begin(); it != friendsUnique[j].end(); it++) {
                friendsUniqueVec[j].push_back(*it);
            }
            sort(friendsUniqueVec[j].begin(), friendsUniqueVec[j].end());
        }

        // calculate score
        vector<int> score(3);
        for (int j = 0; j < 3; j++) {
            score[j] = friendsUnique[j].size();
        }

        // find max score, can print more than 1 friend
        int maxScore = max(score[0], max(score[1], score[2]));
        for (int j = 0; j < 3; j++) {
            if (score[j] == maxScore) {
                if (score[j] > 0) {
                    cout << j + 1 << " " << score[j] << " ";
                    cout << friendsUniqueVec[j][0];
                    for (int k = 1; k < friendsUniqueVec[j].size(); k++) {
                        cout << " " << friendsUniqueVec[j][k];
                    }
                } else {
                    cout << j + 1 << " " << score[j];
                }
                cout << endl;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




