#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int random;
	int input;
	srand(time(NULL));
	random = rand() % 100;

	printf("UP & DOWN\n");
	
	for (int i = 1; i <= 10; i++) {
		printf("%d��° ����~~\n", i);
		printf("[>] �Է� : ");
		scanf_s("%d", &input);

		if (input > 100 || input < 1) {
			printf("1~100 ������ ���ڸ� �Է����ּ���\n");
			i = 0;
		}else {
			if (random < input) {
				printf("[*] DOWN\n\n");
			}else if (random > input) {
				printf("[*] UP\n\n");
			}else if (random == input) {
				printf("[*] �����Դϴ�!!!!~~~~");
				return 0;
			}
		}

		printf("===========================================\n");

	}

	printf("��~~~");
	return 0;
}