/*
    [BOJ1167_트리의_지름] - 23.01.20
    * 두번의 DFS를 통해 해결할 수 있다.
    * dfs의 반복문에서 무언가를 처리하는 일을 주의하자.
*/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int MAX_DIS, MAX_IDX;
vector<vector<pair<int, int>>> tree;
vector<bool> visited;

void dfs(int idx, ll dis) {
    if (visited[idx]) return;
    visited[idx] = true;

    if (MAX_DIS < dis) {
        MAX_DIS = dis;
        MAX_IDX = idx;
    }

    for (pair<int, int> edge : tree[idx]) {
        dfs(edge.first, dis + edge.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int NODE_NUM;
    cin >> NODE_NUM;

    tree.resize(NODE_NUM + 1, vector<pair<int, int>>(0));

    int a, b, dis, _;
    while (cin >> a) {
        while (true) {
            cin >> b;
            if (b == -1) break;

            cin >> dis;
            tree[a].push_back({ b,dis });
            tree[b].push_back({ a,dis });
        }
    }

    MAX_DIS = 0;
    visited.resize(NODE_NUM + 1, false);
    dfs(1,0);

    MAX_DIS = 0;
    visited.clear();
    visited.resize(NODE_NUM + 1, false);
    dfs(MAX_IDX, 0);

    cout << MAX_DIS;
    return 0;
}