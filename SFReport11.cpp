#include <stdio.h>
#include <math.h>

void Length(int a, int b) {
	double c;
	a = pow(a, 2); //a 값의 2 제곱
	b = pow(b, 2); //b 값의 2 제곱

	c = a + b;

	printf("[>] 빗변의 길이는 : %.3lf입니다.", sqrt(c));//루트
	
}


int main() {

	double a;
	double b;
	for (;;) {
		for (;;) {
			printf("선분 a의 길이\n [>] : ");
			scanf_s("%lf", &a);
			if (a < 0) {
				printf("0 이상의 수를 입력해 주세요!\n");
			}
			else {
				break;
			}
		}

		for (;;) {
			printf("선분 b의 길이\n [>] : ");
			scanf_s("%lf", &b);
			if (b < 0) {
				printf("0 이상의 수를 입력해 주세요!\n");
			}
			else {
				break;
			}
			break;
		}
		if (a > 0 && b > 0) {
			break;
		}
	}
	Length(a, b);
	
	return 0;
}