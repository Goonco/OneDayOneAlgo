/*
    [BOJ2533_사회망_서비스(SNS)] - 23.01.21
    * 원래는 DP 문제이지만 DFS로 해결
    * 궁금한점은 root를 어떻게 잡느냐에 따라 정답이 달라지지 않나?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<bool> visited;
vector<vector<int>> tree;
int counter = 0;

bool dfs(int curIdx, int from) {
    stack<int> unvisited;
    for (int to : tree[curIdx]) {
        if (to == from) continue;
        if (!dfs(to, curIdx)) unvisited.push(to);
    }

    if (unvisited.empty()) return false;

    visited[curIdx] = true;
    counter++;
    while (!unvisited.empty()) {
        visited[unvisited.top()] = true;
        unvisited.pop();
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int NODE_NUM;
    cin >> NODE_NUM;

    tree.resize(NODE_NUM + 1, vector<int>(0));
    visited.resize(NODE_NUM + 1, false);

    int a, b;
    while (cin >> a >> b) {
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    cout << counter;

    return 0;
}