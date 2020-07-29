#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char name[255][255];
    char phone[255][255];
    int list, start, finish, choose;
    int select = 5;
    int i, j, k;
    printf("몇개의 맛집 리스트를 만드시겠습니까?\n[>] : ");
    scanf("%d", &list);

    for (i = 1; i <= list; i++) {
        printf("\n%d번째 맛집 입력\n이름을 입력해 주세요\n[>] : ", i);
        scanf("%s", name[i]);

        printf("전화번호를 입력해 주세요\n[>] : ");
        scanf("%s", phone[i]);
    }

    do{
        printf("\n맛집 리스트\n1. 전부출력 2. 범위출력 3. 하나만 출력\n\n");

        printf("번호를 선택해주세요!!\n[>] : ");
        scanf("%d", &select);
        if (select <= 0 || select >= 4) {
            printf("\n다시 입력해주십시오.\n");
            select = 0;
        }
    } while (select <= 0 || select >= 4);

    if (select == 1) {
        for (i = 1; i <= list; i++) {
            printf("\n%d번째 맛집 리스트 \n[>] 이름 : %s\n[>] 전화번호 : %s\n\n", i, name[i], phone[i]);
        }
    }
    else if (select == 2) {
        while (1) {
            printf("\n시작범위 입력\n[>] : ");
            scanf("%d", &start);

            printf("끝범위 입력\n[>] : ");
            scanf("%d", &finish);

            if (start < finish && 0 < start && finish <= list) {
                for (i = start; i <= finish; i++) {
                    printf("\n%d번째 맛집 리스트 \n[>] 이름 : %s\n[>] 전화번호 : %s\n\n", i, name[i], phone[i]);
                }
                return 0;
            }
            else if (start == finish || start < 0 || list < finish || start == 0 || start > finish) {
                printf("\n범위가 이상합니다 \n다시 입력해주십시오.\n");
            }
        }
        
    }
    else if (select == 3) {
        while (1) {
            printf("\n몇번째 리스트? \n[>] : ");
            scanf("%d", &choose);

            if (choose <= list && choose > 0) {
                printf("\n%d번째 맛집 리스트 \n[>] 이름 : %s\n[>] 전화번호 : %s\n\n", choose, name[choose], phone[choose]);
                return 0;
            }
            else {
                printf("\n리스트가 이상합니다 \n다시 입력해주십시오.\n");
            }
        }
    }

    return 0;
}