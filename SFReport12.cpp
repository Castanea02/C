#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dice() {
	srand(time(NULL));

	int dice_num[] = { 0,1 };
	int try_num = 1;

	while (dice_num[0] != dice_num[1]) {
		printf("[>] %d 번째 시도", try_num++);

		for (int i = 0; i < 2; i++) {
			dice_num[i] = (rand() % 6) + 1;
		}

		printf("> (%d, %d)\n", dice_num[0], dice_num[1]);
	}

	printf("[>] 당신은 %d번만에 같은 수의 주사위를 얻었군요!", try_num - 1);
	
}

char choosef() {
	char choose = 'Y';

	printf("[>] [입력] 계속하실거면 Y, 그만하실거면 N을 입력해주세요.\n");
	scanf(" %c", &choose);
	rewind(stdin);

	return choose;
}

int main() {
	char choose;

	printf("[>] [제목] 주사위 게임!\n");
	printf("[>] [설명] 주사위 2개를 던졌을 때, 같은 눈의 수가 나오면 끝나는 게임!!\n");
	printf("[>] [설명] 끝날 때 까지 적게 주사위를 던진 사람이 이긴다!\n");
	
	for (;;) {
		choose = choosef();

		if (choose == 'Y') {
			dice();
			return 0;
		}else if (choose == 'N') {
			return 0;
		}else{
			printf("입력이 잘못되었습니다. 다시 입력해주세요.\n");
		}

	}
}