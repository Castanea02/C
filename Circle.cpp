#include <stdio.h>

double calc_pie(double half) {
	double result;
	result = half * half * 3.141592;

	return result;
}

int main() {
	double cir_half;

	printf("[>] ���� �������� ���������� �Է����ּ���.\n");
	scanf_s("%lf", &cir_half);

	printf("%lf", calc_pie(cir_half));
}



