#include<iostream>
#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<time.h>

using namespace std;

typedef struct lianbiao {        //����ṹ������� 
	int num;
	lianbiao* next;           //1.�������ʹ��lianbiao  
}ss,*mm;                           //2.�������*mm��������mm* 
mm head=(mm)malloc(sizeof(ss));
mm rear=(mm)malloc(sizeof(ss));
char bc[1000];
int shuru  (int sum){
	int i,j,k;
	mm p=(mm)malloc(sizeof(ss));
	p->num=1;  
	//cout<<p->num<<'M';
	head->next=p;                                 //P����δ��ֵ��ԭ�� 
	for(i=1;i<sum;i++){
		mm q=(mm)malloc(sizeof(ss));            //���������û���⣬�����
		//cout<<p<<' '<<q<<'\n'; 
		p->next=q;
		q->num=i+1;
		p=q;
	//	cout<<p->num<<'P';
		//free(q)                                     ������Ϊ����free,����ȫ�̽Դ� 
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
int shuchu(int sum,int x){                            //XΪ���� 
	int i,j,k;
	int step=0; 
	mm p=(mm)malloc(sizeof(ss));
    mm q=(mm)malloc(sizeof(ss));
	p=head->next; 
	int times=sum/x;                       //����Ӧ��������ȡ�����㷨 
	if(sum%x!=0)  times+=1;
	for(i=0;i<times;i++){
		cout<<"��ĵ�"<<i+1<<"����"; 
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
//	freopen("�������1.txt","w",stdout);
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
	sum=i-1;        //3.���ﰴ��˼ά������Ӧ�ã�������������и�' ' 
	cout<<sum<<" "<<mum;
	shuru(sum);                   //���к����� 
	cout<<sum<<'\n'; 
	p=head->next;
	shuchu(sum,mum);
}
