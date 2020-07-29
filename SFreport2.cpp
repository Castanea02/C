/* 입학년도 출력프로그램 */
#include <stdio.h>

int main() {

	int input = 0;

	printf("[*] 학번을 입력해주세요 ex)20194606 : \n");
	scanf_s("[>] %d", &input); //학번 입력

	input = 20200000 < input ? 2019 : 2020;

	printf("[*] %d년도에 입학하셨군요!! ", input); //연도 출력



}