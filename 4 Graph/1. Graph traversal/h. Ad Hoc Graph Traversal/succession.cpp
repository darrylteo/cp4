#include <bits/stdc++.h>

using namespace std;

struct person {
    vector<string> children;
    long long blood{};
    int inDegree{};
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    unordered_map<string, person> people;
    string king;
    cin >> king;
    for (int i = 0; i < n; ++i) {
        string child, p1, p2;
        cin >> child >> p1 >> p2;
        people[p1].children.push_back(child);
        people[p2].children.push_back(child);
        people[child].inDegree += 2;
    }
    people[king].blood = 1LL << 60;
    queue<string> q;
    // add all the people with 0 inDegree to the queue. gotta do 0 indegree since they can have "weird relations"
    // not really weird but say king - a - b - c and king - d - c. if don't wait to 0. c incorrectly propagate without receiving all blood
    for (auto&[name, p] : people) {
        if (p.inDegree == 0) {
            q.push(name);
        }
    }
    while (!q.empty()) {
        string parent = q.front();
        q.pop();
        for (const string& child : people[parent].children) {
            people[child].blood += people[parent].blood / 2;
            if (--people[child].inDegree == 0) {
                q.push(child);
            }
        }
    }
    long long bestBlood = 0;
    string bestName;
    for (int i = 0; i < m; ++i) {
        string name;
        cin >> name;
        if (people[name].blood > bestBlood) {
            bestBlood = people[name].blood;
            bestName = name;
        }
    }
    cout << bestName << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
