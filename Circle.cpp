#include <stdio.h>

double calc_pie(double half) {
	double result;
	result = half * half * 3.141592;

	return result;
}

int main() {
	double cir_half;

	printf("[>] 원의 반지름을 정수값으로 입력해주세요.\n");
	scanf_s("%lf", &cir_half);

	printf("%lf", calc_pie(cir_half));
}



