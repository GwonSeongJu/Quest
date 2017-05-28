#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//#include "linux_getch.h"
#include "stack.h"



//char[][] short_list={"aa","bb"};


void print_UI(int now_position, int** stack_origin, int** stack_write) {
	system("cls");
	printf(">> ���� Ÿ�� ���� ���α׷� ");
	switch (now_position) {
	case 0:
		printf("<<\n");
		printf("1.�ڸ� ����	2.���� ����\n");
		printf("3.ª�� �� ����	4.�� �� ����\n");
		printf("5.���α׷� ����\n\n");
		break;
	case 1:
		printf(": �ڸ� ���� <<\n");
		printf("���൵: %d\% ��Ÿ��: %d\% ��Ȯ��: %d\%\n", process_percentage(now_position,stack_origin,stack_write),wrong_word(stack_origin, stack_write), accuracy(stack_origin,stack_write));
		printf("\n\n");
		break;
	case 2:
		printf(": ���� ���� <<");
		printf("\n\n");
		break;
	case 3:
		printf(": ª�� �� ���� <<");
		printf("\n\n");
		break;
	case 4:
		printf(": �� �� ���� <<");
		printf("\n\n");
		break;
	}
}

int no_echo_save_stack() {
	char tmp;
	tmp = getch();
	return tmp;
}

void one_work(int** stack_origin, int** stack_write) {
	int now_position = 1;
	int tmp;
	int n;
	for (int i = 0; process_percentage(now_position,stack_origin,stack_write)<100; i++) {
		if (rand() % 2 == 1) {
			n = rand() % 26 + 65;
		}
		else {
			n = rand() % 26 + 97;
		}
		stack_put(stack_origin, n);	
		print_UI(now_position, stack_origin, stack_write);
		printf("%c\n", return_stack_i(stack_origin,i));
		tmp = no_echo_save_stack();
		stack_put(stack_write, tmp);
	}
	
}

void word_work(int** stack_origin, int** stack_write) {
	int now_position = 2;
	int n;
	int tmp_word[30];
	char**tmp_word_stack;
	char* word_list = { "ab\nbc\ncd\nde\ndf\nfg\ngh\nhj" };
	stack_word_init(&tmp_word_stack);
	stack_word_put_list(&tmp_word_stack, word_list);
	for (int i = 0; i < 20; i++) {
		print_UI(now_position, stack_origin, stack_write);
		n = rand() % tmp_word_stack[0][0] + 1;
		stack_word_print(tmp_word_stack,n);
		scanf("%30s", &tmp_word);
		stack_put(stack_origin, 1);
		if (stack_word_compare(tmp_word_stack[n], tmp_word)) {
			stack_put(stack_write, 1);
		}
		else {
			stack_put(stack_write, 0);
		}
	}
}

void short_work(int** stack_origin, int** stack_write) {
	int now_position = 3;
	for (int i = 0; i < 5; i++) {	
	}
	for (int i = 0; i<5; i++) {
		no_echo_save_stack();
	}
}

void long_work(int** stack_origin, int** stack_write) {
	int now_position = 4;
	no_echo_save_stack();
}
/*
void check_option(int kn){
//���൵,��Ÿ��,����Ÿ��,�ְ�Ÿ��,��Ȯ��
switch(kn){
case 0:
printf(" ");
break;

}
}
*/


int main() {

	int now_position = 0;
	int input_number_main = 0;
	int* stack_origin, stack_write;

	srand(time(NULL));

	while (input_number_main != 5) {
		_init_(&stack_origin);
		_init_(&stack_write);
		print_UI(now_position, &stack_origin, &stack_write);
		scanf("%d", &input_number_main);
		switch (input_number_main) {
		case 1:
			one_work(&stack_origin, &stack_write);
			break;
		case 2:
			word_work(&stack_origin, &stack_write);
			break;
		case 3:
			short_work(&stack_origin, &stack_write);
			break;
		case 4:
			long_work(&stack_origin, &stack_write);
			break;
		}
	}
	printf("\n\n���α׷� ����~!!!!!!!!");
	return 1;

}
