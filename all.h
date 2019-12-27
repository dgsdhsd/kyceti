#pragma once
#include <cstdio>
#include <string.h>
#include<stdlib.h>
#include <algorithm>
#include <iostream>
#include<time.h>
#include "winsock.h"
#include "mysql.h"
#include<stdlib.h>
using namespace std;
#pragma comment (lib, "libmysql.lib")
#pragma comment (lib, "mysqlclient.lib")
typedef struct lianbiao {        //链表结构初步完成 
	int num;
	lianbiao* next;              //1.这里必须使用lianbiao  
}ss, * mm;                           //2.这里采用*mm，而不是mm* 
mm head = (mm)malloc(sizeof(ss));
mm rear = (mm)malloc(sizeof(ss));
char bc[1000];
char NUM[100];
int shuru(MYSQL* sock, char* lin);
int control(MYSQL* sock);                     //初始控制模块
int control1(MYSQL* sock, int step);          //创建试卷名
int control2(MYSQL* sock, char* name);        //创建选项
int fun(MYSQL* sock, char* name);
int dele(mm p, mm q);
int shuchu(MYSQL* sock, int sum, int x, char* name);
int listdevise(int sum);
int control3(MYSQL* sock, char* name);
int shitisc(MYSQL* sock);
int home(MYSQL* sock, char* name);
int fuzhu(char* ori, int site, char* alter,char*cop);
int fuzhu2(char* zz, int sit, int number);
int inita(MYSQL* sock,int times,char* name);
int look(MYSQL* sock,char* name);
int answ(MYSQL* sock,int sel,int pp[105][10],char* name);