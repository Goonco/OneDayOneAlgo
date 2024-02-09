/*
    [BOJ1005_ACM_Craft] - 23.02.09
    * topological sorting은 ref cnt!
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef long long ll;

using namespace std;

struct Node {
    int cost;
    ll befCost;
    int refCnt;
    vector<int> next;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TEST_CASE;
    cin >> TEST_CASE;

    for (int tc = 0; tc < TEST_CASE; tc++) {
        int N, K;
        cin >> N >> K;

        vector<Node>track (N + 1, {0, 0, 0, vector<int>()});

        int cost;
        for (int i = 1; i <= N; i++) {
            cin >> cost;
            track[i].cost = cost;
        }

        int left, right;
        for (int k = 0; k < K; k++) {
            cin >> left >> right;
            track[left].next.push_back(right);
            track[right].refCnt++;
        }

        int target;
        cin >> target;
        queue<int> q;
        for (int i = 1; i <= N; i++)
            if (track[i].refCnt == 0) q.push(i);

        ll ansCost = 0;
        Node cur;
        while (!q.empty()) {
            cur = track[q.front()];
            if (q.front() == target) {
                ansCost = cur.befCost + cur.cost;
                break;
            }
            q.pop();

            ll toNext = cur.befCost + cur.cost;
            for (int next : cur.next) {
                track[next].refCnt--;
                if (track[next].refCnt == 0) q.push(next);
                
                track[next].befCost = max(track[next].befCost, toNext);
            }
        }

        cout << ansCost << "\n";
    }

    return 0;
}