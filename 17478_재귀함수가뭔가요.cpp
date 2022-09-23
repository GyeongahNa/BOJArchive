#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;

void _bar(int blank, const char* str) {

    for (int i=0; i<blank*4; i++) printf("_");
    printf("%s\n", str);
    return ;
}

void func(int cnt) {

    if (cnt == N) {
        _bar(cnt, "\"재귀함수가 뭔가요?\"");
        _bar(cnt, "\"재귀함수는 자기 자신을 호출하는 함수라네\"");
        _bar(cnt, "라고 답변하였지.");
        return ;
    }

    _bar(cnt, "\"재귀함수가 뭔가요?\"");
    _bar(cnt, "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
    _bar(cnt, "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
    _bar(cnt, "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
    func(cnt+1);
    _bar(cnt, "라고 답변하였지.");
    return ;
}

int main() {

    scanf("%d", &N);
    printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
    func(0);
    return 0;
}