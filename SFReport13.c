#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//��ȭ��ȣ�� ���� ����ü name, phone, birth
struct info {
	char name[50][50];
	char phone[50][50];
	int birth[10];
}; struct info info;

//�޴� �׸��� �Լ�
void numberlist()
{
	int i;
	for (i = 0; i <= 40; i++) printf("-");
	printf("\n");
	for (i = 0; i <= 30; i++) {
		if (i == 15)
			printf("��ȭ��ȣ��");
		printf("-");
	}
	printf("\n");
	for (i = 0; i <= 40; i++) printf("-");
	printf("\n\n");

	printf("              1.��ȣ �߰�\n");
	printf("              2.��ȣ ����\n");
	printf("              3.��ȣ ���\n");
	printf("              4.��ȣ ����\n");
	printf("              5.��     ��\n\n");
	for (i = 0; i <= 40; i++) printf("-");
	printf("\n\n");
}

//��ȭ��ȣ�� �߰�
void phone_add(int count) {//list_count���ڰ� ���� �޾� �ش� ���ڰ��� �迭 ������ �߰���

	printf("\n[>] ��    �� : ");
	scanf("%s", info.name[count]);
	printf("[>] ��ȭ��ȣ : ");
	scanf("%s", info.phone[count]);
	printf("[>] ������� : ");
	scanf("%d", &info.birth[count]);
	count++;
	printf("\n[>] %d��° ��ȭ��ȣ �߰��Ϸ�\n", count);
	printf("\n-----------------------------------------\n\n");

}

//��ȭ��ȣ�� ���
void phone_print(int count) {
	for (int i = 0; i < count; i++) {//��� ��ȭ��ȣ�� ���
		printf("\n[>] %d��° ��ȭ��ȣ", i + 1);
		printf("\n[>] ��    �� : %s\n[>] ��ȭ��ȣ : %s\n[>] ������� : %06d\n", info.name[i], info.phone[i], info.birth[i]);
		printf("\n-----------------------------------------\n");
	}
}

//��ȭ��ȣ�� ����
void phone_delete(int count) {
	int del_num;
	int del_aply = 0;
	while (del_aply == 0) {
		printf("[>] ������ ��ȭ��ȣ�� ��ȣ : ");
		scanf("%d", &del_num);//2�� = 1����

		del_num--;//1���� ��� 0������ ���⶧��
		if (info.birth[del_num] == 0) { //������ ���� ������ 0�Ͻ�
			printf("\n[!] ���� ��ȣ�Դϴ�. �ٽ��Է����ּ���.\n\n");
		}
		else {
			del_aply = 1;
		}
	}

	del_num++;

	for (int i = 0; i < count; i++) {
		strcpy(info.name[del_num - 1], info.name[del_num]);//del_num�� 2�ϰ�� 2���� ��� ������ 1������ �����
		strcpy(info.phone[del_num - 1], info.phone[del_num]);
		info.birth[del_num - 1] = info.birth[del_num];

		del_num++; //2�� ��� 1�� ������ 2�� ������ ��� ���� ���� 3�� ������ 2�� �������� ����� ���� ��� ����Ʈ�� �� �Ҷ� ���� �ݺ�
	}
	printf("\n[>] �� �� �� ��\n");
}

//��ȭ��ȣ�� ����
void phone_modify() {
	int modi_num;
	int modi_num2;
	int birth;
	char modicpy[50];
	char aply = 'n';
	int count = 0;

	while (count == 0) {
		printf("[>] ������ ��ȭ��ȣ���� ��ȣ�� �Է��ϼ���.\n[>] : ");
		scanf("%d", &modi_num);
		modi_num--;
		if (info.birth[modi_num] == 0) {//������ ���� ������ 0�Ͻ�
			printf("\n[!] ���� ��ȣ�Դϴ�. �ٽ��Է����ּ���.\n\n");
			count = 0;
		}
		else {
			printf("\n[>] ��    �� : %s\n[>] ��ȭ��ȣ : %s\n[>] ������� : %06d\n\n", info.name[modi_num], info.phone[modi_num], info.birth[modi_num]);
			count = 1;
		}
	}



	do {
		printf("[>] �� ��ȭ��ȣ���� ������ �����Ͻðڽ��ϱ�?\n[>] ���� ������ ���ϸ� Y, �ƴϸ� N�� �����ּ���.\n[>] : ");
		rewind(stdin);//ǥ���Է� �޸� �ʱ�ȭ
		scanf("%c", &aply);
		if (aply == 'Y') {
			printf("[>] ��    �� ������ ���Ͻø� 1\n[>] ��ȭ��ȣ ������ ���Ͻø� 2\n[>] ������� ������ ���Ͻø� 3\n[>] : ");
			scanf("%d", &modi_num2);
			if (modi_num2 == 1) {
				printf("[>] �ٲ� �̸��� �Է����ּ���\n[>] : ");
				scanf("%s", modicpy);
				strcpy(info.name[modi_num], modicpy);//�Է³����� �����ϱ� ���� �迭�� ����
				printf("\n[*]�����Ϸ�\n");
			}
			else if (modi_num2 == 2) {
				printf("[>] �ٲ� ��ȭ��ȣ�� �Է����ּ���\n[>] : ");
				scanf("%s", modicpy);
				strcpy(info.phone[modi_num], modicpy);//�Է³����� �����ϱ� ���� �迭�� ����
				printf("\n[*] �����Ϸ�\n");
			}
			else if (modi_num2 == 3) {
				printf("[>] �ٲ� ��������� �Է����ּ���\n[>] : ");
				scanf("%d", &birth);
				info.birth[modi_num] = birth;//�Է³����� �����ϱ� ���� �迭�� ����
				printf("\n[*] �����Ϸ�\n");
			}
			else {
				printf("\n[!] 1~3�� ���ڸ� �Է����ּ���.\n");
			}
			aply = 'N';//while ������ ���������� ����
		}
		else if (aply == 'N') {
			printf("\n\n");//�Է¹��� ������ N�̶�� �ٹٲ��ϰ� while�� ����
		}
		else {
			printf("[!] �ٽ� �Է� ���ּ���\n");
		}
	} while (aply != 'N');
}

int main() {
	int select;
	int list_count = 0; //��ȭ��ȣ�� ������ �������� ����

	while (1) {
		numberlist();
		printf("[>] �޴� ���� : ");
		scanf("%d", &select);
		printf("\n-----------------------------------------\n");

		if (select == 1) {
			phone_add(list_count);
			list_count++;//��ȭ��ȣ�� �߰��� ������ ��ȭ��ȣ�� ���� �߰�
		}
		else if (select == 2) {
			phone_delete(list_count);
			list_count--;//��ȭ��ȣ�� ������ ������ ��ȭ��ȣ�� ���� ����
		}
		else if (select == 3) {
			phone_print(list_count);
		}
		else if (select == 4) {
			phone_modify();
		}
		else if (select == 5) {
			printf("\n[��] ������ּż� �����մϴ�.\n");
			return 0;
		}
		else {
			printf("\n[!] 1~5�� ���ڸ� �Է����ּ���.\n\n");
		}
	}


}
