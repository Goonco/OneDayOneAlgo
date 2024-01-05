/*
    [BOJ15989_1,_2,_3_더하기_4] - 23.01.05
    * 간단한 Dynamic Programming 문제이다.
    * 최초 시도시, 매 테스트 케이스마다 DP Table을 새롭게 채우는 바보같은 실수를 범했다.
    * DP Table을 최대 입력에 대해 채워놓고 매 테스트 케이스의 답을 바로 뽑아낼 수 있도록 구현하는 것이 효율적이다.
*/

#include <iostream>
#include <vector>

using namespace std;

void fillDPTable(int* dpTable, int jmp) {
    for (int i = jmp; i < 10001; i++)
        dpTable[i] += dpTable[i - jmp];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TEST_CASE;
    cin >> TEST_CASE;

    int dpTable[10001] = {0};
    dpTable[0] = 1;
    fillDPTable(dpTable, 1);
    fillDPTable(dpTable, 2);
    fillDPTable(dpTable, 3);
    
    int n;
    for (int ts = 0; ts < TEST_CASE; ts++) {
        cin >> n;
        cout << dpTable[n] << '\n';
    }

    return 0;
}