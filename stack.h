#ifndef STACK_GWON_
#define STACK_GWON_

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_DATA_SIZE 10
#define GAP_END_POINT 2
#define DATA_CHANGE_N 5


int SHOW_WORK_MESSAGE=0;


// data0= datasize data1 = datapoint
void _init_(int* data){
	data=(int*)malloc(sizeof(int)*DEFAULT_DATA_SIZE);
	*data[0]=DEFAULT_DATA_SIZE;
	printf("%d",*data[0]);
	sleep(1000);
	*data[1]=-1;
}


void change_show(int n){
	SHOW_WORK_MESSAGE = n;
}

void change_stack_memory(int* data,int n){
	data[0]=data[0]+n;
	data=(int*)realloc(data,sizeof(int)*(data[0]));
}


char stack_pop(int* data){
	if (data[1]==-1){
	        if(SHOW_WORK_MESSAGE)
			printf("꺼낼것이 없습니다.");
		data[1]=0;
		return 0;
	}
	char tmp=data[data[1]+2];
	data[1]=data[1]-1;
	return tmp;
}

void stack_put(int* data, int n){
	data[1]=data[1]+1;
	
	if(data[1]>=data[0]-GAP_END_POINT){
		change_stack_memory(data,DATA_CHANGE_N);
	}
	data[data[1]]=n;
	printf("test");
}

void print_stack_all(int data[]){
	for(int i=0;i<10;i++){
		printf("size : %d\n",sizeof(data));
		data[i]=i;
		printf("%d\n",data[i]);
        }
}

#endif
