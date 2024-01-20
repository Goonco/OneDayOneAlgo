/*
    [BOJ1240_노드사이의_거리] - 23.01.18
    * Tree + DFS 문제.
    * 부모와 자식 관계가 확실한 tree 였으면 보다 낮은 공간복잡도와 시간복잡도로 해결할 수 있었을 문제.
*/

#include <iostream>
#include <vector>

using namespace std;
vector<vector<pair<int, int>>> edges;

int ans;

void dfs(int from, int cur, int target, int dis) {
    if (cur == target) {
        ans = dis;
    }


    for (pair<int, int> edge : edges[cur]) {
        if (edge.first == from) continue;
        dfs(cur, edge.first, target, dis + edge.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int NODE_NUM, DIS_NUM;
    cin >> NODE_NUM >> DIS_NUM;

    edges.resize(NODE_NUM + 1, vector<pair<int, int>>(0));

    int a, b, dis;
    for (int i = 0; i < NODE_NUM - 1; i++) {
        cin >> a >> b >> dis;

        edges[a].push_back({ b, dis });
        edges[b].push_back({ a, dis });
    }

    for (int i = 0; i < DIS_NUM; i++) {
        cin >> a >> b;

        ans = -1;
        dfs(a, a, b, 0);
        cout << ans << "\n";
    }

    return 0;
}
