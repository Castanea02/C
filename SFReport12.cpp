#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dice() {
	srand(time(NULL));

	int dice_num[] = { 0,1 };
	int try_num = 1;

	while (dice_num[0] != dice_num[1]) {
		printf("[>] %d ��° �õ�", try_num++);

		for (int i = 0; i < 2; i++) {
			dice_num[i] = (rand() % 6) + 1;
		}

		printf("> (%d, %d)\n", dice_num[0], dice_num[1]);
	}

	printf("[>] ����� %d������ ���� ���� �ֻ����� �������!", try_num - 1);
	
}

char choosef() {
	char choose = 'Y';

	printf("[>] [�Է�] ����ϽǰŸ� Y, �׸��ϽǰŸ� N�� �Է����ּ���.\n");
	scanf(" %c", &choose);
	rewind(stdin);

	return choose;
}

int main() {
	char choose;

	printf("[>] [����] �ֻ��� ����!\n");
	printf("[>] [����] �ֻ��� 2���� ������ ��, ���� ���� ���� ������ ������ ����!!\n");
	printf("[>] [����] ���� �� ���� ���� �ֻ����� ���� ����� �̱��!\n");
	
	for (;;) {
		choose = choosef();

		if (choose == 'Y') {
			dice();
			return 0;
		}else if (choose == 'N') {
			return 0;
		}else{
			printf("�Է��� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���.\n");
		}

	}
}