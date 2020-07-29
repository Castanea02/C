#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

char start; //���� ����
int input; //����� �Է�
int player_num[5][5] = { 0, }; //�÷��̾� ������
int computer_num[5][5] = { 0, }; //��ǻ�� ������
int player_bingo_count = 0; //�÷��̾� ������ üũ
int computer_bingo_count = 0; //��ǻ�� ������ üũ
int remove_num = 0; //�÷��̾� ���� ���� ����
int sum = 0;	    //���� üũ �հ� ���� ����
int remove_count = 0; //���� ���� ����� ���� ����
int j = 0; //�ݺ���
int i = 0; //�ݺ���
int k = 0; //�ݺ���
int temp = 0; //��ǻ�� �Է��� ���� ���庯��
int list1 = 0; //�ݺ���
int list2 = 0; //�ݺ���
int escape = 0; //���ѹݺ��� ���������� �����ϴ� ����

//���� ����
int game_start(int a) {
	printf("[>] ��̳��� �������!\n");
	while (1) {
		printf("[<] ������ �����? (Y or N) : "); //���� ����
		scanf(" %c", &start);
		rewind(stdin);
		if (start == 'Y') {
			return a + 1;
		}
		else if (start == 'N') {
			return a;
		}
		else {
			printf("[!] �ٽ� �Է����ּ���!\n"); //Y, N�� �ƴ϶�� �ٽ�
		}
	}
}

//�÷��̾� �Է�
void player_input() {
	//�÷��̾� �Է�
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			escape = 0;
			while (escape == 0) {
				do {
					printf("[<] %d, %d�� �� �Է� : ", i + 1, j + 1);
					scanf("%d", &input);
					escape = 1;
					if (input > 99 || input < 1) {
						printf("[!] 1~99������ ���ڸ� �Է����ֽʽÿ�\n"); //���� ���� ����
					}
				} while (input > 99 || input < 1);


				for (list1 = 0; list1 < 5; list1++) {
					for (list2 = 0; list2 < 5; list2++) {
						if (input == player_num[list1][list2]) {
							printf("[!] �ߺ��Դϴ�. �ٽ��Է����ּ���\n"); //�ߺ� �Ÿ���
							escape = 0;
						}
					}
				}
			}

			player_num[i][j] = input;//���Ͱ� ������ �Է� �� ����

		}
	}
}

//��ǻ�� �Է�
void computer_input() {
	//��ǻ�� �Է�
	for (i = 0; i < 5; i++) { //0~4
		for (j = 0; j < 5; j++) { //0~4
			escape = 0;
			while (escape == 0) {
				temp = (rand() % 99) + 1; //1~99������ ���� �ֱ�
				escape = 1;

				for (list1 = 0; list1 < 5; list1++) {
					for (list2 = 0; list2 < 5; list2++) {
						if (temp == computer_num[list1][list2]) {
							escape = 0;
						}
					}
				}
			}

			computer_num[i][j] = temp;
		}
	}
}

//������� ���� (�Է�)
void start_game() {
	escape = 0;
		while (escape == 0) {
			printf("[<] ��� : ");
			scanf("%d", &remove_num);
			escape = 1;

			//������ ���
			if (remove_num == 100) {

				printf("[>] �÷��̾� ������\n\n");
				for (list1 = 0; list1 < 5; list1++) {
					for (list2 = 0; list2 < 5; list2++) {
						printf("%d \t", player_num[list1][list2]);
					}
					printf("\n\n");
				}

				printf("[>] ��ǻ�� ������\n\n");
				for (list1 = 0; list1 < 5; list1++) {
					for (list2 = 0; list2 < 5; list2++) {
						printf("%d \t", computer_num[list1][list2]);
					}
					printf("\n\n");
				}
				escape = 0;
			}else {
				for (list1 = 0; list1 < 5; list1++) {
					for (list2 = 0; list2 < 5; list2++) {
						if (remove_num != player_num[list1][list2]) {
							remove_count++; //������ ���� ������ �Ǻ��ϱ� ���� ����
						}
					}
				}
			}

			if (remove_count == 24) { //���� ������ ���� 24��� ������ �ִ� ��
				escape = 1;
			}else if (remove_num == 100) {
				escape = 0;
			}else {
				printf("������ ���� ��ȣ �Դϴ� �ٽ� �Է��ϼ���.\n"); //24���� ���ڶ�� ������ ���� ���̹Ƿ� �ٽ�
				escape = 0;
			}
			remove_count = 0;//���� �� �Ǻ� �ʱ�ȭ
		}
}

//�÷��̾� ������ ����
void player_bingo_remove() {
	for (list1 = 0; list1 < 5; list1++) {
		for (list2 = 0; list2 < 5; list2++) {
			if (player_num[list1][list2] == remove_num) {
				player_num[list1][list2] = 0; //�÷��̾ ��ģ ���� ����
			}
		}
	}

	for (list1 = 0; list1 < 5; list1++) {
		for (list2 = 0; list2 < 5; list2++) { //��ǻ�� �����ǿ� �÷��̰Ű� ��ģ ���ڰ� �����Ѵٸ� ����
			if (computer_num[list1][list2] == remove_num) {
				computer_num[list1][list2] = 0;
			}
		}
	}

	
}

//��ǻ�� ������ ����
void computer_bingo_remove() {
	int com_remove = 0;
	int com_remove2 = 0;
	for (;;) {
		com_remove = rand() % 5;
		com_remove2 = rand() % 5;
		for (list1 = 0; list1 < 5; list1++) {
			for (list2 = 0; list2 < 5; list2++) {
				if (player_num[list1][list2] == computer_num[com_remove][com_remove2]) {
					player_num[list1][list2] = 0; //��ǻ�Ͱ� ��ģ ���ڰ� �÷��̾�� �����Ѵٸ� ����
				}
			}
		}
		if (computer_num[com_remove][com_remove2] == 0) {
			continue;//�������� ������ 0�̶�� �ٽ� �õ�
		}
		else {
			printf("[>] ��ǻ�� : %d\n", computer_num[com_remove][com_remove2]);
			computer_num[com_remove][com_remove2] = 0; //��ǻ���� ������ ����(������)
			break;
		}
	}
}

//�÷��̾� ������ üũ
void player_bingo_check() {
	for (i = 0; i < 5; i++) { //X��ǥ ���
		sum = 0;
		for (j = 0; j < 5; j++) {
			sum += player_num[i][j];
		}

		if (sum == 0) {
			player_bingo_count++;
		}

	}

	for (i = 0; i < 5; i++) { //Y��ǥ ���
		sum = 0;
		for (j = 0; j < 5; j++) {
			sum += player_num[j][i];
		}

		if (sum == 0) {
			player_bingo_count++;
		}

	}
	sum = 0;
	for (i = 0; i < 5; i++) { //��-�� �밢��
		sum += player_num[i][i];
	}
	if (sum == 0) {
		player_bingo_count++;
	}

	sum = 0;
	for (i = 4; i >= 0; i--) { //��-�� �밢��
		sum += player_num[i][5 - i - 1];
	}
	if (sum == 0) {
		player_bingo_count++;
	}
}

//��ǻ�� ������ üũ
void computer_bingo_check() {
	
	for (i = 0; i < 5; i++) { //X��ǥ ���
		sum = 0;
		for (j = 0; j < 5; j++) {
			sum += computer_num[i][j];
		}

		if (sum == 0) {
			computer_bingo_count++;
		}

	}

	for (i = 0; i < 5; i++) { //Y��ǥ ���
		sum = 0;
		for (j = 0; j < 5; j++) {
			sum += computer_num[j][i];
		}

		if (sum == 0) {
			computer_bingo_count++;
		}

	}
	sum = 0;
	for (i = 0; i < 5; i++) { //��-�� �밢��
		sum += player_num[i][i];
	}
	if (sum == 0) {
		computer_bingo_count++;
	}

	sum = 0;
	for (i = 4; i >= 0; i--) { //��-�� �밢��
		sum += computer_num[i][5 - i - 1];
	}
	if (sum == 0) {
		computer_bingo_count++;
	}

}

//�¸��� ���� ����
int game_over(int a) {
	if (player_bingo_count < 3) { 
		player_bingo_count = 0; //����üũ ���� ����
	}
	else {
		printf("[>] ����� �¸�!\n");
		return a;
	}

	if (computer_bingo_count < 3) { 
		computer_bingo_count = 0; //����üũ ���� ����
	}
	else {
		printf("[>] ��ǻ���� �¸�!\n");
		return a;
	}
}

int main() {
	srand(time(NULL));
	
	if (0 == game_start(0)) {
		return 0;
	}
	printf("\n================================================================\n");
	printf("[>] ���� ���� �Է����ּ���.\n");
	printf("[>] 1~99 ������ �����߿� ���� �ߺ����� �ʵ��� �Է����ּ���.");
	printf("\n================================================================\n");

	player_input(); //�÷��̾� �Է�
	computer_input(); //��ǻ�� �Է�
	
	printf("================================================================\n");
	printf("[>] ���� ����!\n");
	printf("[>] 1. ����� ���� �� ���� 3�� ���� �ϼ��ϼ���.\n");
	printf("[>] 2. ���� �߰��� 100�� �Է��ϸ� �������� ��µ˴ϴ�.\n");
	printf("================================================================\n");
	
	while (1) { //���� �ݺ�
		
		start_game(); //���� ����
		player_bingo_remove(); //�÷��̾��� ���� ���� ����
		computer_bingo_remove(); //��ǻ���� ���� ���� ����
		player_bingo_check(); //�÷��̾� ���� üũ 3�� �̻��Ͻ� �¸�
		computer_bingo_check(); //��ǻ�� ���� üũ 3�� �̻��Ͻ� �¸�
		if (0 == game_over(0)) { //���� �¸� ���� ���� üũ�� 3�� ������ ��� ����üũ 0���� ����
			return 0;
		}
	}

}//main ��