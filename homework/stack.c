#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_DATA_SIZE 10
#define GAP_END_POINT 3
#define DATA_CHANGE_N 5

//stack[0] 데이터사이즈 앞쪽 0,1을 합친
//stack[1] 포인터위치 앞쪽 0,1을 제외함 즉 아무것도없을때 포인터는 -1임 처음들어온값이 0을 가짐

void _init_(int** stack) {
	*stack = (int*)malloc(sizeof(int)*DEFAULT_DATA_SIZE);
	(*stack)[0] = DEFAULT_DATA_SIZE;
	(*stack)[1] = -1;
}

void change_show(int n) {
	printf("");
}

int return_stack_i(int** stack, int number) {
	if ((*stack)[1] != -1)
		return (*stack)[number+2];
	return -1;
}


void change_stack_memory(int** stack, int n) {
	(*stack)[0] = (*stack)[0] + n;
	*stack = (int*)realloc(*stack, sizeof(int)*(*stack)[0]);
}


char stack_pop(int** stack) {
	if ((*stack)[1] == -1) {
		return 0;
	}
	char tmp = (*stack)[(*stack)[1]+2];
	(*stack)[1] = (*stack)[1] - 1;
	return tmp;
}

void stack_put(int** stack, int n) {
	(*stack)[1] = (*stack)[1] + 1;

	if ((*stack)[1] >= (*stack)[0] - GAP_END_POINT) {
		change_stack_memory(stack, DATA_CHANGE_N);
	}
	(*stack)[(*stack)[1]+2] = n;
}

void print_stack_all(int** stack) {
	for (int i = 2; i < (*stack)[1]+2; i++) {
		printf("%d\t", (*stack)[i]);
	}
	printf("\n");
}
void stack_word_init(char*** stack) {
	*stack = (char**)malloc(sizeof(char*) * 1);
	(*stack)[0] = (char*)malloc(sizeof(char) * 2);
	(*stack)[0][0] = (int)0;  //[0][0] 0은 기본데이터 저장용 장소 [0][0]은 몇개의 단어인지 
}

void stack_word_put(char*** stack, char* input) {
	int n=0;
	(*stack)[0][0] = (int)(*stack)[0][0] + 1;
	*stack = (char**)realloc(*stack, sizeof(char*)*(*stack)[0][0]);

	for (; input[n] != '\0'; n++);
	(*stack)[(*stack)[0][0]] = (char*)malloc(sizeof(char)*n);
	for (int i = 0; i < n; i++) {
		(*stack)[(*stack)[0][0]][i] = input[i];
	}
}

void stack_word_print(char** stack, int n) {
	for (int i = 0; stack[n][i] != '\0'; i++) {
		printf("%c", stack[n][i]);
	}
	printf("\n");
}

void stack_word_put_list(char ***stack, char* list) {
	char tmp_word[30];
	int n = 0,i;
	while (list[n] != '\0') {
		for (i = 0; (list[n] != '\n') && (list[n] != '\0'); i++, n++) {
			tmp_word[i] = list[n];
		}
		tmp_word[i] = '\0';
		n++;
		stack_word_put(stack, tmp_word);
	}

}

int stack_word_compare(char* a, char* b) {
	int n = -1;
	while (a[n] != '\0') {
		n++;
		if (a[n] != b[n]) return 0;
	}
	return 1;
}