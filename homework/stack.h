#ifndef STACK_GWON_
#define STACK_GWON_



void _init_(int** stack);
void change_show(int n);
void change_stack_memory(int** stack, int n);
char stack_pop(int** stack);
void stack_put(int** stack, int n);
void print_stack_all(int** stack);
int return_stack_i(int** stack, int i);
void stack_word_put_list(char ***stack, char* list);
void stack_word_print(char** stack, int n);
void stack_word_put(char*** stack, char* input);
void stack_word_init(char*** stack);
int stack_word_compare(char* a, char* b);

#endif
