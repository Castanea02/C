#include <stdio.h>

int main() {
	int sta;
	int fin;
	int dan;
	int i = 0;
	int num = 0;
	printf("[>] ������ ���� ������ : ");
	scanf_s("%d", &sta);
	printf("[>] ������ ���� ������ : ");
	scanf_s("%d", &fin);

	for (num = 1; num <= 9; num++) {
		for (i = sta; i <= fin; i++) {
			printf("%d X %d = %d \t", i, num, i*num);
		}
		printf("\n");
	}
	return 0;
}