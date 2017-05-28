#include <stdio.h>
#include "stack.h"

int process_percentage(int now_position, int** stack_origin, int** stack_write);
int wrong_word(int** stack_origin, int** stack_write);
int now_type();
int high_type();
int accuracy(int** stack_origin, int** stack_write);



int process_percentage(int now_position, int** stack_origin,int** stack_write) {
	int return_value;
	if(now_position==1){
		return ((*stack_write)[1] + 1 - wrong_word(stack_origin, stack_write)) * 5;
	}
	return ((*stack_write)[1] + 1) * 5;
}
int wrong_word(int** stack_origin, int** stack_write) {
	int return_value=0;
	for (int i = 0; i <= (*stack_write)[1]; i++) {
		if (return_stack_i(stack_write,i)!= return_stack_i(stack_origin,i)){
			return_value++;
		}
	}
	return return_value;
}
int now_type();
int high_type();
int accuracy(int** stack_origin, int** stack_write) {
	if ((*stack_write)[1] == -1) return 0;
	return ((float)(*stack_write)[1] + 1 - wrong_word(stack_origin, stack_write))/((*stack_write)[1]+1) * 100;
}
