#ifndef _GWON_Op
#define _GWON_Op

int process_percentage(int now_position, int** stack_origin, int** stack_write);
int wrong_word(int** stack_origin, int** stack_write);
int now_type();
int high_type();
int accuracy(int** stack_origin, int** stack_write);

#endif