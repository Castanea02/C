/* ���� ū �� ã�� ���α׷�*/
#include <stdio.h>

int main() {

	int input = 0;
	int input2 = 0;
	int input3 = 0;
	int max = 0;
	printf("[>] �Է� : ");//35 72 1
	scanf_s("%d %d %d", &input, &input2, &input3); //�й� �Է�

	max = input > input2 ? input : input2;
	max = max < input3 ? input3 : max;

	printf("���� ū ���� \"%d\" �Դϴ�.", max);

}