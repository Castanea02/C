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
		printf("%d번째 도전~~\n", i);
		printf("[>] 입력 : ");
		scanf_s("%d", &input);

		if (input > 100 || input < 1) {
			printf("1~100 사이의 숫자를 입력해주세요\n");
			i = 0;
		}else {
			if (random < input) {
				printf("[*] DOWN\n\n");
			}else if (random > input) {
				printf("[*] UP\n\n");
			}else if (random == input) {
				printf("[*] 정답입니다!!!!~~~~");
				return 0;
			}
		}

		printf("===========================================\n");

	}

	printf("끝~~~");
	return 0;
}