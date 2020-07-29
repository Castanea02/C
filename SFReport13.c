#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//전화번호부 정보 구조체 name, phone, birth
struct info {
	char name[50][50];
	char phone[50][50];
	int birth[10];
}; struct info info;

//메뉴 그리는 함수
void numberlist()
{
	int i;
	for (i = 0; i <= 40; i++) printf("-");
	printf("\n");
	for (i = 0; i <= 30; i++) {
		if (i == 15)
			printf("전화번호부");
		printf("-");
	}
	printf("\n");
	for (i = 0; i <= 40; i++) printf("-");
	printf("\n\n");

	printf("              1.번호 추가\n");
	printf("              2.번호 삭제\n");
	printf("              3.번호 출력\n");
	printf("              4.번호 수정\n");
	printf("              5.종     료\n\n");
	for (i = 0; i <= 40; i++) printf("-");
	printf("\n\n");
}

//전화번호부 추가
void phone_add(int count) {//list_count인자값 전달 받아 해당 인자값의 배열 내용을 추가함

	printf("\n[>] 이    름 : ");
	scanf("%s", info.name[count]);
	printf("[>] 전화번호 : ");
	scanf("%s", info.phone[count]);
	printf("[>] 생년월일 : ");
	scanf("%d", &info.birth[count]);
	count++;
	printf("\n[>] %d번째 전화번호 추가완료\n", count);
	printf("\n-----------------------------------------\n\n");

}

//전화번호부 출력
void phone_print(int count) {
	for (int i = 0; i < count; i++) {//모든 전화번호부 출력
		printf("\n[>] %d번째 전화번호", i + 1);
		printf("\n[>] 이    름 : %s\n[>] 전화번호 : %s\n[>] 생년월일 : %06d\n", info.name[i], info.phone[i], info.birth[i]);
		printf("\n-----------------------------------------\n");
	}
}

//전화번호부 삭제
void phone_delete(int count) {
	int del_num;
	int del_aply = 0;
	while (del_aply == 0) {
		printf("[>] 삭제할 전화번호의 번호 : ");
		scanf("%d", &del_num);//2번 = 1번방

		del_num--;//1번일 경우 0번방을 보기때문
		if (info.birth[del_num] == 0) { //삭제할 방의 생일이 0일시
			printf("\n[!] 없는 번호입니다. 다시입력해주세요.\n\n");
		}
		else {
			del_aply = 1;
		}
	}

	del_num++;

	for (int i = 0; i < count; i++) {
		strcpy(info.name[del_num - 1], info.name[del_num]);//del_num이 2일경우 2번의 모든 내용을 1번으로 덮어쓰기
		strcpy(info.phone[del_num - 1], info.phone[del_num]);
		info.birth[del_num - 1] = info.birth[del_num];

		del_num++; //2일 경우 1의 내용을 2의 내용으 모두 덮어 쓴뒤 3의 내용을 2의 내용으로 덮어쓰기 위함 모든 리스트가 다 할때 까지 반복
	}
	printf("\n[>] 삭 제 완 료\n");
}

//전화번호부 수정
void phone_modify() {
	int modi_num;
	int modi_num2;
	int birth;
	char modicpy[50];
	char aply = 'n';
	int count = 0;

	while (count == 0) {
		printf("[>] 수정할 전화번호부의 번호를 입력하세요.\n[>] : ");
		scanf("%d", &modi_num);
		modi_num--;
		if (info.birth[modi_num] == 0) {//삭제할 방의 생일이 0일시
			printf("\n[!] 없는 번호입니다. 다시입력해주세요.\n\n");
			count = 0;
		}
		else {
			printf("\n[>] 이    름 : %s\n[>] 전화번호 : %s\n[>] 생년월일 : %06d\n\n", info.name[modi_num], info.phone[modi_num], info.birth[modi_num]);
			count = 1;
		}
	}



	do {
		printf("[>] 위 전화번호부의 내용을 수정하시겠습니까?\n[>] 내용 수정을 원하면 Y, 아니면 N을 눌러주세요.\n[>] : ");
		rewind(stdin);//표준입력 메모리 초기화
		scanf("%c", &aply);
		if (aply == 'Y') {
			printf("[>] 이    름 수정을 원하시면 1\n[>] 전화번호 수정을 원하시면 2\n[>] 생년월일 수정을 원하시면 3\n[>] : ");
			scanf("%d", &modi_num2);
			if (modi_num2 == 1) {
				printf("[>] 바꿀 이름을 입력해주세요\n[>] : ");
				scanf("%s", modicpy);
				strcpy(info.name[modi_num], modicpy);//입력내용을 수정하기 위한 배열에 복사
				printf("\n[*]수정완료\n");
			}
			else if (modi_num2 == 2) {
				printf("[>] 바꿀 전화번호를 입력해주세요\n[>] : ");
				scanf("%s", modicpy);
				strcpy(info.phone[modi_num], modicpy);//입력내용을 수정하기 위한 배열에 복사
				printf("\n[*] 수정완료\n");
			}
			else if (modi_num2 == 3) {
				printf("[>] 바꿀 생년월일을 입력해주세요\n[>] : ");
				scanf("%d", &birth);
				info.birth[modi_num] = birth;//입력내용을 수정하기 위한 배열에 복사
				printf("\n[*] 수정완료\n");
			}
			else {
				printf("\n[!] 1~3의 숫자를 입력해주세요.\n");
			}
			aply = 'N';//while 조건을 빠져나가기 위함
		}
		else if (aply == 'N') {
			printf("\n\n");//입력받은 내용이 N이라면 줄바꿈하고 while문 종료
		}
		else {
			printf("[!] 다시 입력 해주세요\n");
		}
	} while (aply != 'N');
}

int main() {
	int select;
	int list_count = 0; //전화번호부 개수를 세기위한 변수

	while (1) {
		numberlist();
		printf("[>] 메뉴 선택 : ");
		scanf("%d", &select);
		printf("\n-----------------------------------------\n");

		if (select == 1) {
			phone_add(list_count);
			list_count++;//전화번호부 추가가 끝나고 전화번호부 개수 추가
		}
		else if (select == 2) {
			phone_delete(list_count);
			list_count--;//전화번호부 삭제가 끝나고 전화번호부 개수 감소
		}
		else if (select == 3) {
			phone_print(list_count);
		}
		else if (select == 4) {
			phone_modify();
		}
		else if (select == 5) {
			printf("\n[※] 사용해주셔서 감사합니다.\n");
			return 0;
		}
		else {
			printf("\n[!] 1~5의 숫자만 입력해주세요.\n\n");
		}
	}


}
