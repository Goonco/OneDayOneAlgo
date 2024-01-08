/*
    [BOJ1138_한_줄로_서기] - 23.01.08
    * 비록 N의 범위가 매우 작지만, 중간 삽입이 자주 발생하기 때문에 list를 사용했다.
    * 키가 가장 큰 사람부터 정렬한다고 생각하면 해결이 쉽다. 생각해내기 어렵진 않지만 아이디어가 필요하다.
*/

#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int NUMBER;
    cin >> NUMBER;

    stack<int> st;
    
    int k;
    for (int i = 1; i <= NUMBER; i++) {
        cin >> k;
        st.push(k);
    }

    list<int> line;
    int idx;
    for (int i = NUMBER; i >= 1; i--) {
        idx = st.top();
        st.pop();

        auto iter = next(line.begin(), idx);
        line.insert(iter, i);
    }

    for (const auto& el : line)
        cout << el << " ";

    return 0;
}
