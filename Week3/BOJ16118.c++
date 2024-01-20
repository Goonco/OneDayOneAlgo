/*
    [BOJ16118_달빛_여우] - 23.01.17
    * 두 개의 독립된 type에 따라 Dijkstra를 구하는 문제
    * 접근 방법은 맞았으나 double을 이용하여 정밀도에서 문제가 발생하여 틀린 문제로, double을 비교해야하는 경우 이를 정수화 하여 구현하는 습관을 갖자.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;
typedef vector<pair<int, int>> vp;

struct cmp {
    bool operator()(pair<int, ll> bef, pair<int, ll> aft) {
        return bef.second > aft.second;
    }
};

struct cmp2 {
    bool operator()(pair<int, pair<ll, ll>> bef, pair<int, pair<ll, ll>> aft) {
        if(bef.second.first != aft.second.first) return bef.second.first > aft.second.first;
        return bef.second.second > aft.second.second;

    }
};

int NODE_NUM;
int EDGE_NUM;
vector<vp>edges;

vector<ll> rabbitDij() {
    vector<ll> distances(NODE_NUM + 1, LLONG_MAX);
    distances[1] = 0;

    priority_queue<pair<int, ll>, vector<pair<int, ll>>, cmp> pq; // idx, dis
    pq.push({ 1, 0 });

    pair<int, ll> cur;
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();

        if (cur.second > distances[cur.first]) continue;

        for (pair<int, int> edge : edges[cur.first]) {
            ll nextDis = cur.second + edge.second * 2;
            
            if (distances[edge.first] <= nextDis) continue;
            distances[edge.first] = nextDis;
            pq.push({ edge.first, nextDis });
        }
    }

    return distances;
}

vector<pair<ll, ll>> wolfDij() {
    vector<pair<ll, ll>> distances(NODE_NUM + 1, {LLONG_MAX , LLONG_MAX});
    distances[1] = { LLONG_MAX,0 };

    priority_queue<pair<int, pair<ll, ll>>, vector<pair<int, pair<ll, ll>>>, cmp2> pq; // idx, dis
    pq.push({ 1, {LLONG_MAX,0} });

    pair<int, pair<ll, ll>> cur;
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();

        // 홀수 -> 짝수
        if (cur.second.first != LLONG_MAX && cur.second.first <= distances[cur.first].first) {
            for (pair<int, int> edge : edges[cur.first]) {
                ll nextDis = cur.second.first + edge.second * 4;

                if (distances[edge.first].second > nextDis) {
                    distances[edge.first].second = nextDis;
                    pq.push({ edge.first, {distances[edge.first].first,nextDis}});
                }
            }
        }

        // 짝수 -> 홀수
        if (cur.second.second != LLONG_MAX && cur.second.second <= distances[cur.first].second) {
            for (pair<int, int> edge : edges[cur.first]) {
                ll nextDis = cur.second.second + edge.second;

                if (distances[edge.first].first > nextDis) {
                    distances[edge.first].first = nextDis;
                    pq.push({ edge.first, {nextDis, distances[edge.first].second}});
                }
            }
        }
    }

    return distances;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> NODE_NUM >> EDGE_NUM;

    edges.resize(NODE_NUM + 1, vp(0));
    
    int left, right, dis;
    for (int i = 0; i < EDGE_NUM; i++) {
        cin >> left >> right >> dis;
        edges[left].push_back({ right, dis });
        edges[right].push_back({ left, dis });
    }

    vector<ll> rabbitDistances = rabbitDij();
    vector<pair<ll, ll>> wolfDistances = wolfDij();

    int count = 0;
    for (int i = 2; i <= NODE_NUM; i++) {
        ll left = rabbitDistances[i];
        ll right = min(wolfDistances[i].first, wolfDistances[i].second);
        if (left < right) count++;
    }
    cout << count;
    return 0;
}
