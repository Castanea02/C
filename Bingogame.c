#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

char start; //시작 변수
int input; //사용자 입력
int player_num[5][5] = { 0, }; //플레이어 빙고판
int computer_num[5][5] = { 0, }; //컴퓨터 빙고판
int player_bingo_count = 0; //플레이어 빙고개수 체크
int computer_bingo_count = 0; //컴퓨터 빙고개수 체크
int remove_num = 0; //플레이어 빙고 삭제 변수
int sum = 0;	    //빙고 체크 합계 계산용 변수
int remove_count = 0; //없는 숫자 계산을 위한 변수
int j = 0; //반복문
int i = 0; //반복문
int k = 0; //반복문
int temp = 0; //컴퓨터 입력을 위한 저장변수
int list1 = 0; //반복문
int list2 = 0; //반복문
int escape = 0; //무한반복을 빠지기위해 조절하는 변수

//빙고 시작
int game_start(int a) {
	printf("[>] 재미나는 빙고게임!\n");
	while (1) {
		printf("[<] 시작해 볼까요? (Y or N) : "); //빙고 시작
		scanf(" %c", &start);
		rewind(stdin);
		if (start == 'Y') {
			return a + 1;
		}
		else if (start == 'N') {
			return a;
		}
		else {
			printf("[!] 다시 입력해주세요!\n"); //Y, N이 아니라면 다시
		}
	}
}

//플레이어 입력
void player_input() {
	//플레이어 입력
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			escape = 0;
			while (escape == 0) {
				do {
					printf("[<] %d, %d의 값 입력 : ", i + 1, j + 1);
					scanf("%d", &input);
					escape = 1;
					if (input > 99 || input < 1) {
						printf("[!] 1~99사이의 숫자만 입력해주십시오\n"); //숫자 범위 지정
					}
				} while (input > 99 || input < 1);


				for (list1 = 0; list1 < 5; list1++) {
					for (list2 = 0; list2 < 5; list2++) {
						if (input == player_num[list1][list2]) {
							printf("[!] 중복입니다. 다시입력해주세요\n"); //중복 거르기
							escape = 0;
						}
					}
				}
			}

			player_num[i][j] = input;//필터가 끝나고 입력 값 저장

		}
	}
}

//컴퓨터 입력
void computer_input() {
	//컴퓨터 입력
	for (i = 0; i < 5; i++) { //0~4
		for (j = 0; j < 5; j++) { //0~4
			escape = 0;
			while (escape == 0) {
				temp = (rand() % 99) + 1; //1~99사이의 난수 넣기
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

//빙고게임 시작 (입력)
void start_game() {
	escape = 0;
		while (escape == 0) {
			printf("[<] 당신 : ");
			scanf("%d", &remove_num);
			escape = 1;

			//빙고판 출력
			if (remove_num == 100) {

				printf("[>] 플레이어 빙고판\n\n");
				for (list1 = 0; list1 < 5; list1++) {
					for (list2 = 0; list2 < 5; list2++) {
						printf("%d \t", player_num[list1][list2]);
					}
					printf("\n\n");
				}

				printf("[>] 컴퓨터 빙고판\n\n");
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
							remove_count++; //나에게 없는 수인지 판별하기 위한 변수
						}
					}
				}
			}

			if (remove_count == 24) { //나를 제외한 수가 24라면 나에게 있는 수
				escape = 1;
			}else if (remove_num == 100) {
				escape = 0;
			}else {
				printf("나에게 없는 번호 입니다 다시 입력하세요.\n"); //24외의 숫자라면 나에게 없는 수이므로 다시
				escape = 0;
			}
			remove_count = 0;//없는 수 판별 초기화
		}
}

//플레이어 빙고판 제거
void player_bingo_remove() {
	for (list1 = 0; list1 < 5; list1++) {
		for (list2 = 0; list2 < 5; list2++) {
			if (player_num[list1][list2] == remove_num) {
				player_num[list1][list2] = 0; //플레이어가 외친 숫자 제거
			}
		}
	}

	for (list1 = 0; list1 < 5; list1++) {
		for (list2 = 0; list2 < 5; list2++) { //컴퓨터 빙고판에 플레이거가 외친 숫자가 존재한다면 제거
			if (computer_num[list1][list2] == remove_num) {
				computer_num[list1][list2] = 0;
			}
		}
	}

	
}

//컴퓨터 빙고판 제거
void computer_bingo_remove() {
	int com_remove = 0;
	int com_remove2 = 0;
	for (;;) {
		com_remove = rand() % 5;
		com_remove2 = rand() % 5;
		for (list1 = 0; list1 < 5; list1++) {
			for (list2 = 0; list2 < 5; list2++) {
				if (player_num[list1][list2] == computer_num[com_remove][com_remove2]) {
					player_num[list1][list2] = 0; //컴퓨터가 외친 숫자가 플레이어에게 존재한다면 제거
				}
			}
		}
		if (computer_num[com_remove][com_remove2] == 0) {
			continue;//무작위로 돌리다 0이라면 다시 시도
		}
		else {
			printf("[>] 컴퓨터 : %d\n", computer_num[com_remove][com_remove2]);
			computer_num[com_remove][com_remove2] = 0; //컴퓨터의 빙고판 제거(무작위)
			break;
		}
	}
}

//플레이어 빙고판 체크
void player_bingo_check() {
	for (i = 0; i < 5; i++) { //X좌표 계산
		sum = 0;
		for (j = 0; j < 5; j++) {
			sum += player_num[i][j];
		}

		if (sum == 0) {
			player_bingo_count++;
		}

	}

	for (i = 0; i < 5; i++) { //Y좌표 계산
		sum = 0;
		for (j = 0; j < 5; j++) {
			sum += player_num[j][i];
		}

		if (sum == 0) {
			player_bingo_count++;
		}

	}
	sum = 0;
	for (i = 0; i < 5; i++) { //왼-오 대각선
		sum += player_num[i][i];
	}
	if (sum == 0) {
		player_bingo_count++;
	}

	sum = 0;
	for (i = 4; i >= 0; i--) { //오-왼 대각선
		sum += player_num[i][5 - i - 1];
	}
	if (sum == 0) {
		player_bingo_count++;
	}
}

//컴퓨터 빙고판 체크
void computer_bingo_check() {
	
	for (i = 0; i < 5; i++) { //X좌표 계산
		sum = 0;
		for (j = 0; j < 5; j++) {
			sum += computer_num[i][j];
		}

		if (sum == 0) {
			computer_bingo_count++;
		}

	}

	for (i = 0; i < 5; i++) { //Y좌표 계산
		sum = 0;
		for (j = 0; j < 5; j++) {
			sum += computer_num[j][i];
		}

		if (sum == 0) {
			computer_bingo_count++;
		}

	}
	sum = 0;
	for (i = 0; i < 5; i++) { //왼-오 대각선
		sum += player_num[i][i];
	}
	if (sum == 0) {
		computer_bingo_count++;
	}

	sum = 0;
	for (i = 4; i >= 0; i--) { //오-왼 대각선
		sum += computer_num[i][5 - i - 1];
	}
	if (sum == 0) {
		computer_bingo_count++;
	}

}

//승리자 빙고 종료
int game_over(int a) {
	if (player_bingo_count < 3) { 
		player_bingo_count = 0; //빙고체크 누적 방지
	}
	else {
		printf("[>] 당신의 승리!\n");
		return a;
	}

	if (computer_bingo_count < 3) { 
		computer_bingo_count = 0; //빙고체크 누적 방지
	}
	else {
		printf("[>] 컴퓨터의 승리!\n");
		return a;
	}
}

int main() {
	srand(time(NULL));
	
	if (0 == game_start(0)) {
		return 0;
	}
	printf("\n================================================================\n");
	printf("[>] 빙고에 값을 입력해주세요.\n");
	printf("[>] 1~99 까지의 숫자중에 값이 중복되지 않도록 입력해주세요.");
	printf("\n================================================================\n");

	player_input(); //플레이어 입력
	computer_input(); //컴퓨터 입력
	
	printf("================================================================\n");
	printf("[>] 게임 시작!\n");
	printf("[>] 1. 상대편 보다 더 빨리 3줄 빙고를 완성하세요.\n");
	printf("[>] 2. 게임 중간에 100을 입력하면 빙고판이 출력됩니다.\n");
	printf("================================================================\n");
	
	while (1) { //게임 반복
		
		start_game(); //게임 시작
		player_bingo_remove(); //플레이어의 빙고 숫자 삭제
		computer_bingo_remove(); //컴퓨터의 빙고 숫자 삭제
		player_bingo_check(); //플레이어 빙고 체크 3개 이상일시 승리
		computer_bingo_check(); //컴퓨터 빙고 체크 3개 이상일시 승리
		if (0 == game_over(0)) { //게임 승리 결정 빙고 체크가 3개 이하일 경우 빙고체크 0으로 고정
			return 0;
		}
	}

}//main 끝