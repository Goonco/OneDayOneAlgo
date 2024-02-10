/*
    [BOJ2252_줄_세우기] - 23.02.07
    * 위상정렬 시 reference count를 줄여나가며 priority를 찾는다.
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

struct Node {
    int val;
    int refCnt;
    vector<int> next;
};

Node pool[32001];

int node_cnt;
Node* getNode(int n) {
    pool[node_cnt].val = n;
    pool[node_cnt].next.clear();
    pool[node_cnt].refCnt = 0;
    return &pool[node_cnt++];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Node*> tracking(N + 1);
    for (int i = 0; i <= N; i++) {
        tracking[i] = getNode(i);
    }

    int left, right;
    for (int i = 0; i < M; i++) {
        cin >> left >> right;

        tracking[right]->refCnt++;
        tracking[left]->next.push_back(right);
    }

    queue<int> leafs;
    for (int i = 1; i <= N; i++) {
        if (tracking[i]->refCnt == 0) leafs.push(i);
    }

    Node* cur;
    while (!leafs.empty()) {
        cur = tracking[leafs.front()];
        leafs.pop();

        cout << cur->val << " ";

        for (int iter : cur->next) {
            tracking[iter]->refCnt--;
            if (tracking[iter]->refCnt == 0) leafs.push(iter);
        }
    }

    return 0;
}