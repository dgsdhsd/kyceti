#include<iostream>
#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<time.h>

using namespace std;

typedef struct lianbiao {        //链表结构初步完成 
	int num;
	lianbiao* next;           //1.这里必须使用lianbiao  
}ss,*mm;                           //2.这里采用*mm，而不是mm* 
mm head=(mm)malloc(sizeof(ss));
mm rear=(mm)malloc(sizeof(ss));
char bc[1000];
int shuru  (int sum){
	int i,j,k;
	mm p=(mm)malloc(sizeof(ss));
	p->num=1;  
	//cout<<p->num<<'M';
	head->next=p;                                 //P好像未赋值的原因 
	for(i=1;i<sum;i++){
		mm q=(mm)malloc(sizeof(ss));            //这里好像是没问题，不清楚
		//cout<<p<<' '<<q<<'\n'; 
		p->next=q;
		q->num=i+1;
		p=q;
	//	cout<<p->num<<'P';
		//free(q)                                     就是因为多了free,导致全盘皆错 
	}
	rear->next=p;
	p->next=head->next; 
	/*for(i=0;i<sum;i++){
		cout<<p->num<<'\n';
		p=p->next;	
	} */
	free(p);          
	return 0;
}
int dele(mm p,mm q){
	if(head->next==rear->next)return 1;
	q->next=p->next;
	if(head->next==p)
	head->next=p->next;
	if(rear->next==p)
	rear->next=q;
	return 0;
}
int shuchu(int sum,int x){                            //X为步数 
	int i,j,k;
	int step=0; 
	mm p=(mm)malloc(sizeof(ss));
    mm q=(mm)malloc(sizeof(ss));
	p=head->next; 
	int times=sum/x;                       //这里应该有向上取整的算法 
	if(sum%x!=0)  times+=1;
	for(i=0;i<times;i++){
		cout<<"你的第"<<i+1<<"套题"; 
	//	int *l=(int*)malloc(sizeof(int)*x);
		for(j=0;j<x;j++){
			step=rand()%sum+1;
		//	cout<<step<<'\n';
			for(k=0;k<step;k++){
			//	cout<<p->num<<'\n'; 
			q=p;        p=p->next;
		}
		    cout<<p->num<<':'<<bc[p->num-1]<<' ';
		    
			if(dele(p,q)) break;
		}
		cout<<'\n';	
	}
}
int main(){
	int i,j,k;
	int mum;
	int sum;
	mm p=(mm)malloc(sizeof(ss));
	mm q=(mm)malloc(sizeof(ss));
//	freopen("启用输出1.txt","w",stdout);
    memset(bc,'?',sizeof(bc));
	srand (time(NULL)); 
	cout<<"please input the truth(input 1 break)"<<'\n'; 
	for(i=1;;i++){
		cout<<i<<':';
		cin>>bc[i-1];
		if(bc[i-1]=='1')break;
	}
	cout<<"please input the step:";                         //cin>>bc;
    cin>>mum;                                              //	for(i=0;bc[i]!='?';i++);
	sum=i-1;        //3.这里按照思维惯性是应该，但是这里最好有个' ' 
	cout<<sum<<" "<<mum;
	shuru(sum);                   //序列号排列 
	cout<<sum<<'\n'; 
	p=head->next;
	shuchu(sum,mum);
}
