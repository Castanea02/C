#include <stdio.h>

int main() {

	char conti = 'Y'; //������� ���� ������ ���� ���� �ʱⰪ = Y
	int num1 = 0;	//ù��° ������ ���� ����
	int num2 = 0;	//�ι�° ������ ���� ����
	int select = 0;	//��������� ���������� ����
	double divnum1 = 0; //ù��° ������ ������ ���� ����
	double divnum2 = 0; //�ι�° ������ ������ ���� ����
	for (;;) {
		
		
		printf("1. ���� 2. ���� 3. ���� 4. ������\n");
		printf("��ȣ�� �������ּ��� : ");
		scanf_s("%d", &select);
		
		switch (select) {
			case 1 : //����
				printf("������ ���ڸ� �Է��� �ּ��� : ");
				scanf_s("%d %d", &num1, &num2);
				printf("%d + %d = %d\n", num1, num2, num1 + num2);
				break;
			case 2 : //����
				printf("������ ���ڸ� �Է��� �ּ��� : ");
				scanf_s("%d %d", &num1, &num2);
				printf("%d - %d = %d\n", num1, num2, num1 - num2);
				break;
			case 3 : //����
				printf("������ ���ڸ� �Է��� �ּ��� : ");
				scanf_s("%d %d", &num1, &num2);
				printf("%d * %d = %d\n", num1, num2, num1 * num2);
				break;
			case 4 : //������
				printf("������ ���ڸ� �Է��� �ּ��� : ");
				scanf_s("%lf %lf", &divnum1, &divnum2);
				printf("%.0lf / %.0lf = %.2lf\n", divnum1, divnum2, divnum1 / divnum2);
				break;
			default :
				printf("�ٽ� �Է����ּ���!\n");
				break;
		}

		while (conti == 'Y') { //�ʱⰪ�� Y ���̹Ƿ� ��� �ݺ�
			printf("��� �Ͻðڽ��ϱ�? (Y or N)\n");
			printf("[>]");
			scanf_s(" %c", &conti);

			if (conti == 'Y') {
				conti = 'N'; //while���� ���������� ���� conti�� ���� N���� ��ü
			}
			else if(conti == 'N'){ //N�� �ԷµǸ� ���α׷� ����
				return 0;
			}
			else {
				printf("�ٽ� �Է��ϼ���!\n"); //�ٸ����� �Էµȴٸ� Y�� ����
				conti = 'Y';
			}

		}
		
		printf("\n=====================================\n\n");

		conti = 'Y'; //���� �ʱ�ȭ ��
		num1 = 0;	
		num2 = 0;	
		select = 0;	
	}

	return 0;
}