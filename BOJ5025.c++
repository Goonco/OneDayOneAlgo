/*
    [BOJ5025_전화번호_목록] - 23.01.27
    * Node pool 이용 tree 문제
*/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    vector<Node*>next;
    bool complete;
};

int node_cnt = 0;
Node node_pool[999999];
Node* getNode() {
    node_pool[node_cnt].next.clear();
    node_pool[node_cnt].next.resize(10, nullptr);
    node_pool[node_cnt].complete = false;
    return &node_pool[node_cnt++];
}

bool addNumberToTree(Node* head, string number) {
    Node* iter = head;
    int num;
    for (int j = 0; j < number.size(); j++) {
        num = number[j] - '0';
        if (iter->next[num] == nullptr) {
            Node* newNode = getNode();
            iter->next[num] = newNode;
        }

        iter = iter->next[num];
        if (iter->complete) return false;
    }

    for (Node* check : iter->next) 
        if (check != nullptr) return false;
    
    iter->complete = true;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TEST_CASE;
    cin >> TEST_CASE;

    int nums;
    while (TEST_CASE--) {
        cin >> nums;

        bool flag = false;
        node_cnt = 0;
        Node* head = getNode();

        string phoneNum;
        for (int i = 0; i < nums; i++) {
            cin >> phoneNum;
            
            if (flag) continue;
            if (!addNumberToTree(head, phoneNum)) 
                flag = true;
        }

        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}