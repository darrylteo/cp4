#include <bits/stdc++.h>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
};

void solve(const string& buf) {
    Node* head = new Node();
    head->data = "";
    head->next = nullptr;
    head->prev = nullptr;

    Node* tail = head;

    Node* cur = head;
    for (char c : buf) {
        if (c == '[') {
            cur = head;
        } else if (c == ']') {
            cur = tail;
        } else {
            Node* node = new Node();
            node->data = c;
            node->next = cur->next;
            node->prev = cur;
            if (cur->next != nullptr) {
                cur->next->prev = node;
            }
            cur->next = node;
            cur = node;
            if (cur->next == nullptr) {
                tail = cur;
            }
        }
    }

    // print nodes
    cur = head->next;
    while (cur != nullptr) {
        cout << cur->data;
        cur = cur->next;
    }
    cout << endl;

    // delete nodes
    cur = head;
    while (cur != nullptr) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string buf;
    while (getline(cin, buf)) {
        solve(buf);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
