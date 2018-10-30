#include<unistd.h> //符合常数
#include<stdio.h>	
#include<stdlib.h>	//公用函数
#include<sys/stat.h>	//文件状态
#include<sys/types.h>	//原系统数据类型
#include<libgen.h>	//模式匹配函数定义
#include<string.h>	//字符串操作

#define MAXSIZE 100
void Createdir(char *);

int main(int argc,char *argv[])
{
//判断参数
	if(argc <= 1){
		printf("error\n");
		exit(1);
	}
//遍历参数，对每个参数进行操作
	while(--argc){
		argv++;
		Createdir(*argv);//调用函数进行创建文件	
	}
}

void Createdir(char *path){
	char data[MAXSIZE];
	//判断是否是当前目录或/目录
	if(access(path,F_OK)==0){
		return;
	}
	else{
		//保存目录
		strcpy(data,path);
		//获取目录的父目录
		dirname(path);
		//递归执行
		Createdir(path);
	}
//创建目录
if(mkdir(data,777)==-1){
	perror("mkdir error");
	exit(1);
}
return ;
}


