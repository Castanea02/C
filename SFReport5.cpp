#include <stdio.h>

int main() {

	char conti = 'Y'; //계속할지 말지 결정을 위한 변수 초기값 = Y
	int num1 = 0;	//첫번째 연산할 숫자 변수
	int num2 = 0;	//두번째 연산할 숫자 변수
	int select = 0;	//산술연산자 선택을위한 변수
	double divnum1 = 0; //첫번째 연산할 나눗셈 숫자 변수
	double divnum2 = 0; //두번째 연산할 나눗셈 숫자 변수
	for (;;) {
		
		
		printf("1. 덧셈 2. 뺄셈 3. 곱셈 4. 나눗셈\n");
		printf("번호를 선택해주세요 : ");
		scanf_s("%d", &select);
		
		switch (select) {
			case 1 : //덧셈
				printf("연산할 숫자를 입력해 주세요 : ");
				scanf_s("%d %d", &num1, &num2);
				printf("%d + %d = %d\n", num1, num2, num1 + num2);
				break;
			case 2 : //뺄셈
				printf("연산할 숫자를 입력해 주세요 : ");
				scanf_s("%d %d", &num1, &num2);
				printf("%d - %d = %d\n", num1, num2, num1 - num2);
				break;
			case 3 : //곱셈
				printf("연산할 숫자를 입력해 주세요 : ");
				scanf_s("%d %d", &num1, &num2);
				printf("%d * %d = %d\n", num1, num2, num1 * num2);
				break;
			case 4 : //나눗셈
				printf("연산할 숫자를 입력해 주세요 : ");
				scanf_s("%lf %lf", &divnum1, &divnum2);
				printf("%.0lf / %.0lf = %.2lf\n", divnum1, divnum2, divnum1 / divnum2);
				break;
			default :
				printf("다시 입력해주세요!\n");
				break;
		}

		while (conti == 'Y') { //초기값은 Y 참이므로 계속 반복
			printf("계속 하시겠습니까? (Y or N)\n");
			printf("[>]");
			scanf_s(" %c", &conti);

			if (conti == 'Y') {
				conti = 'N'; //while문을 빠져나오기 위해 conti의 값을 N으로 교체
			}
			else if(conti == 'N'){ //N이 입력되면 프로그램 종료
				return 0;
			}
			else {
				printf("다시 입력하세요!\n"); //다른것이 입력된다면 Y로 고정
				conti = 'Y';
			}

		}
		
		printf("\n=====================================\n\n");

		conti = 'Y'; //변수 초기화 ↓
		num1 = 0;	
		num2 = 0;	
		select = 0;	
	}

	return 0;
}