#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char name[255][255];
    char phone[255][255];
    int list, start, finish, choose;
    int select = 5;
    int i, j, k;
    printf("��� ���� ����Ʈ�� ����ðڽ��ϱ�?\n[>] : ");
    scanf("%d", &list);

    for (i = 1; i <= list; i++) {
        printf("\n%d��° ���� �Է�\n�̸��� �Է��� �ּ���\n[>] : ", i);
        scanf("%s", name[i]);

        printf("��ȭ��ȣ�� �Է��� �ּ���\n[>] : ");
        scanf("%s", phone[i]);
    }

    do{
        printf("\n���� ����Ʈ\n1. ������� 2. ������� 3. �ϳ��� ���\n\n");

        printf("��ȣ�� �������ּ���!!\n[>] : ");
        scanf("%d", &select);
        if (select <= 0 || select >= 4) {
            printf("\n�ٽ� �Է����ֽʽÿ�.\n");
            select = 0;
        }
    } while (select <= 0 || select >= 4);

    if (select == 1) {
        for (i = 1; i <= list; i++) {
            printf("\n%d��° ���� ����Ʈ \n[>] �̸� : %s\n[>] ��ȭ��ȣ : %s\n\n", i, name[i], phone[i]);
        }
    }
    else if (select == 2) {
        while (1) {
            printf("\n���۹��� �Է�\n[>] : ");
            scanf("%d", &start);

            printf("������ �Է�\n[>] : ");
            scanf("%d", &finish);

            if (start < finish && 0 < start && finish <= list) {
                for (i = start; i <= finish; i++) {
                    printf("\n%d��° ���� ����Ʈ \n[>] �̸� : %s\n[>] ��ȭ��ȣ : %s\n\n", i, name[i], phone[i]);
                }
                return 0;
            }
            else if (start == finish || start < 0 || list < finish || start == 0 || start > finish) {
                printf("\n������ �̻��մϴ� \n�ٽ� �Է����ֽʽÿ�.\n");
            }
        }
        
    }
    else if (select == 3) {
        while (1) {
            printf("\n���° ����Ʈ? \n[>] : ");
            scanf("%d", &choose);

            if (choose <= list && choose > 0) {
                printf("\n%d��° ���� ����Ʈ \n[>] �̸� : %s\n[>] ��ȭ��ȣ : %s\n\n", choose, name[choose], phone[choose]);
                return 0;
            }
            else {
                printf("\n����Ʈ�� �̻��մϴ� \n�ٽ� �Է����ֽʽÿ�.\n");
            }
        }
    }

    return 0;
}