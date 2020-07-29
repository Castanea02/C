#include<stdio.h>    

int main() {
    int ASCII = 65;
    int i, j, k, m;
   
    for (i = 1; i <= 26; i++){//전체 26번 진행 (알파벳 수 만큼)

        for (j = 26; j >= i; j--) {//공백 찍기
            printf(" ");
        }

        for (k = 1; k <= i; k++) {//1부터 i와 같거나 클때까지(1<=1 == A, 1<=2 == AB 1<=3 == ABC...)
            printf("%c", ASCII++); //ASCII 65=A 이므로 출력후 증가 65+1=B 65+2=C ... 뒤 ++이므로 67이면 다음은 66상태로 시작
        }

        ASCII--;// 67 > 66

        for (m = 1; m < i; m++) {//1부터 i까지 이므로 1 < 1은 거짓이니 A만 찍고 넘어감, 1 < 2부터 시작
            printf("%c", --ASCII);//66은 B이므로 A부터 출력하기 위해 먼저 감소한 후 출력
        }

        printf("\n");
        ASCII = 65; //다음 반복문 A부터 출력하기 위해 초기화
    }
    return 0;
}