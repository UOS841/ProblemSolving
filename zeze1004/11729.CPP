// 참고: https://dyndy.tistory.com/232

#include <stdio.h>
#include <math.h>

using namespace std;
// num는 원판의 갯수
// from에서 to까지 원판 n개를 옮기는 것
// tmp 나머지 기둥
void hanoi(int num, int from, int tmp, int to)
{
    if (num == 1) {
        printf("%d %d\n", from, to);
    } else {
        hanoi(num - 1, from, to, tmp);
        printf("%d %d\n", from, to);
        hanoi(num - 1, tmp, from, to);
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    printf("%d\n", (1 << N) - 1); 
    // printf("%d\n",(int)pow(2,N)-1);
    hanoi(N, 1, 2, 3);
    return 0;
}