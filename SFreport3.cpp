/* 가장 큰 수 찾기 프로그램*/
#include <stdio.h>

int main() {

	int input = 0;
	int input2 = 0;
	int input3 = 0;
	int max = 0;
	printf("[>] 입력 : ");//35 72 1
	scanf_s("%d %d %d", &input, &input2, &input3); //학번 입력

	max = input > input2 ? input : input2;
	max = max < input3 ? input3 : max;

	printf("가장 큰 수는 \"%d\" 입니다.", max);

}