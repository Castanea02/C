#include <stdio.h>
#include <math.h>

void Length(int a, int b) {
	double c;
	a = pow(a, 2); //a ���� 2 ����
	b = pow(b, 2); //b ���� 2 ����

	c = a + b;

	printf("[>] ������ ���̴� : %.3lf�Դϴ�.", sqrt(c));//��Ʈ
	
}


int main() {

	double a;
	double b;
	for (;;) {
		for (;;) {
			printf("���� a�� ����\n [>] : ");
			scanf_s("%lf", &a);
			if (a < 0) {
				printf("0 �̻��� ���� �Է��� �ּ���!\n");
			}
			else {
				break;
			}
		}

		for (;;) {
			printf("���� b�� ����\n [>] : ");
			scanf_s("%lf", &b);
			if (b < 0) {
				printf("0 �̻��� ���� �Է��� �ּ���!\n");
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