/*
    [BOJ20040_사이클_게임] - 23.02.11
    * Union Find를 아느냐 모르느냐 그것이 문제로다..
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> groups;

int find(int idx) {
    if (groups[idx] == idx) return idx;
    groups[idx] = find(groups[idx]);
    return groups[idx];
}

bool myUnion(int i, int j) {
    int rep1 = find(i);
    int rep2 = find(j);
    if (rep1 == rep2) return true;

    groups[rep1] = rep2;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int circle = 0;
    
    groups.resize(N);
    for (int i = 0; i < N; i++)
        groups[i] = i;

    bool flag = false;
    int left, right;
    for(int i = 0; i < M; i++) {
        cin >> left >> right;
        if (flag) continue;
        if (myUnion(left, right)) {
            circle = i + 1;
            flag = true;
        }
    }

    cout << circle;
    return 0;
}