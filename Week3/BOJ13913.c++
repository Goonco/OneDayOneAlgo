/*
    [BOJ13913_숨바꼭질_4] - 23.01.16
    * Dijkstra + Backtracking
    * 숨바꼭질 시리즈 마지막 문제
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

int START_POINT, END_POINT;
vector<pair<int,int>>dij;
bool found = false;

struct cmp {
    bool operator()(pair<int, int> bef, pair<int, int> aft) {
        return bef.second > aft.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> START_POINT >> END_POINT;

    if (START_POINT >= END_POINT) {
        cout << START_POINT - END_POINT << "\n";

        for (int i = START_POINT; i >= END_POINT; i--)
            cout << i << " ";
        return 0;
    }

    int len = max(START_POINT, END_POINT) * 4 / 3 + 1;
    len = min(len, 100001);
    dij.resize(len, {INT_MAX, -1});

    dij[START_POINT] = { 0, -1 };

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // idx, cost
    pq.push({ START_POINT,0 });

    pair<int, int> cur;
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();

        if (dij[cur.first].first < cur.second) continue;

        for (int i = 0; i < 3; i++) {
            int next, newCost;
            switch (i) {
            case 0: next = cur.first - 1; break;
            case 1: next = cur.first + 1; break;
            case 2: next = cur.first * 2; break;
            }
            newCost = cur.second + 1;

            if (next < 0 || next >= dij.size()) continue;
            if (dij[next].first <= newCost) continue;

            dij[next].first = newCost;
            dij[next].second = cur.first;
            pq.push({ next, newCost });
        }
    }

    cout << dij[END_POINT].first << "\n";

    stack<int> st;
    st.push(END_POINT);
    while (dij[st.top()].second != -1) {
        st.push(dij[st.top()].second);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
