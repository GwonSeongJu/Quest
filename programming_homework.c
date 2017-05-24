#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "linux_getch.h"
#include "stack.h"

char** word_list={"a","b"};
char** short_list={"aa","bb"};
int now_postion = 0;
int ing,error,now_type,high_type,ex;

int d_origin[],d_write[];



void no_echo_save_stack(){
	char tmp;
	tmp=_getch();
	printf("%c\n",tmp);
	return tmp;
}

void one_work(){
	now_postion=1;
	for (int i=0;i<20;i++){
		int n;
		srand(time(NULL));
		if(rand()%2==1){
			n=rand()%26+65;
		}
		else{
			n=rand()%26+97;
		}
		printf("3\n");
		printf("%d\n",d_origin[0]);
		print_stack_all(d_origin);
		printf("4\n");
		stack_put(d_origin,n);
	}
	for(int i=0;i<20;i++){ 
		printf("\n\n\n");
		no_echo_save_stack();


	}
}

void word_work(){
	now_postion=2;
	char tmp[20];
	for(int i=0;i<20;i++){
		scanf("%c",&tmp);
	}
}

void short_work(){
	now_postion=3;
	for(int i=0;i<5;i++){
		//스택쌓고
		no_echo_save_stack();
	}
}

void long_work(){
	now_postion=4;
	no_echo_save_stack();
}

void check_option(int kn){
	//진행도,오타수,현재타수,최고타수,정확도
	switch(kn){
		case 0:
			printf(" ");
			break;

	}
}

void print_UI(){
	system("clear");
	printf(">> 영문 타자 연습 프로그램 ");
	switch(now_postion){
		case 0:
			printf("<<\n");
			printf("1.자리 연습	2.낱말 연습\n");
			printf("3.짧은 글 연습	4.긴 글 연습\n");
			printf("5.프로그램 종료\n\n");
			break;
		case 1:
			printf(": 자리 연습 <<");
			printf("\n\n");
			break;
		case 2:
			printf(": 낱말 연습 <<");
			printf("\n\n");
			break;
		case 3:
			printf(": 짧은 글 연습 <<");
			printf("\n\n");
			break;
		case 4:
			printf(": 긴 글 연습 <<");
			break;
	}
}

int main(){

	int input_number_main=0;


	while(input_number_main!=5){
		_init_(&d_origin);
	        _init_(&d_write);
	        print_UI();
		scanf("%d",&input_number_main);
		switch(input_number_main){
			case 1:
				one_work();
				break;
			case 2:
				word_work();
				break;
			case 3:
				short_work();
				break;
			case 4:
				long_work();
				break;
		}
	}
	printf("\n\n프로그램 종료~!!!!!!!!");
	return 1;

}
