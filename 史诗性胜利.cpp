#include"all.h"
#pragma warning( disable : 6011) 
                              //数据表名
int main()
{
	//connectionparams
    char *host = "localhost";
    char *user = "root";//mysql的用户名
    char *pass = "123456";//你的mysql服务器密码
    char *db = "kyceti";
	int i;
	//char name[100] = "special";
	//char lin[100] = "insert into zyzhenzhi values(0,'gidf')";
    unsigned int port = 3306; //server port
    MYSQL *sock;
    sock=mysql_init(0);                                //0好像也是MYSQL*
    if(sock &&mysql_real_connect(sock,host,user,pass,db,0,NULL,0))
    {
        cout<<"connect mysqlsucceed!"<<'\n'<<endl;
	}
	else
	{
	    cout<<"I'm sorry to tell you that you wrong!"<<endl;
	}

	//result= mysql_store_result(sock);
	//num = mysql_num_fields(result);
	//row = mysql_fetch_row(result);
	//mum = &row[1];
	//cout << mum[0] << mum[1];
	/*while ((row = mysql_fetch_row(result)))  //遇到最后一行，则中止循环
	{
		for (i = 0; i < num; i++)         //利用for循环，输出该行的每一列
		{
			cout << row[i] << "\t";    //row是MYSQL_ROW变量，可以当做数组使用，i为列数
		}
		cout << endl;
	}*/
	control(sock);
	/*cin >> (name + 7);
	for (i = 0; name[i] != '\0'; i++)cout << name[i];
	if (!mysql_query(sock, "create table gijf like xuanxiang"))
		cout << "!" << endl;
	else cout << "flase" << endl;*/
	i=getchar();                 //getchar()返回值为int，导致的警告
	free(head);
	free(rear);
	getchar();
	//cout<<i;
    //input 1 or 2 or 3
	mysql_close(sock);
    return 0;
}
int shitisc(MYSQL* sock) {
	int i, j, k;
	int num;
	MYSQL_RES* resultzz;
	MYSQL_RES* resultsx;
	MYSQL_ROW zz;
	MYSQL_ROW sx;
    if (!mysql_query(sock, "select * from zyzhenzhi"))
		cout << "true" << endl;
	else cout << "flase" << endl;
	resultzz = mysql_store_result(sock);


	if (!mysql_query(sock, "select * from zyshuxue"))
		cout << "true" << endl;
	else cout << "flase" << endl;
	resultsx = mysql_store_result(sock);


	cout << "政治："<<"\t\t"<<"数学："<<'\n';
	while (1)  //遇到最后一行，则中止循环
	{
		zz = mysql_fetch_row(resultzz);
		sx = mysql_fetch_row(resultsx);
		if (sx != NULL && zz != NULL)
			cout << '\t'<<zz[1] << "\t\t" << sx[1] << '\n';
		else if (zz != NULL && sx == NULL)
			cout << '\t'<<zz[1] << '\n';
		else if (zz == NULL && sx != NULL)
			cout << '\t\t\t' << sx[1] << '\n';
		else break;

	}
	return 0;
}
int dele(mm p, mm q) {
	if (head->next == rear->next)return 1;
	q->next = p->next;
	if (head->next == p)
		head->next = p->next;
	if (rear->next == p)
		rear->next = q;
	return 0;
}
int fuzhu(char* ori, int site, char* alter,char*cop) {                
	int i,j,k;
	j = 0;
	for (i = 0; ori[i] != '\0'; i++) {
		if (i!= site) {
			cop[j++] = ori[i];
		}
		else
			for (k = 0; alter[k] != '\0'; k++)
			{
				cop[j++] = alter[k];
			}
	}
	cop[j] = '\0';
	return 0;
}
int fuzhu2(char *zz,int sit,int number) {  //基础字符串，修改位置，需要加入的数
	char string[5];
	int i, j, k;
	char cc[100];
	itoa(number, string, 10);
	j = sit;
	for (; zz[j] <= '9' && zz[j] >= '0'; j++);              //对数字字符进行删除
	strcpy(cc, zz + j);                 //对zz的sit后面进行复制
	for (i = 0; zz[i] != '\0'; i++) {
		if ((i == sit)) {
			for (k = 0; string[k] != '\0'; k++)
			{
				zz[i++] = string[k];
			}
			strcpy(zz + i, cc);
			break;
		}
	}
	return 0;
}
int inita(MYSQL* sock, int times, char* name) {
	int i;
	int sit;
	char zz[100] = "insert into work!(id,test1) values(2,0)";
	char mum[100];
	cout << "列表数：" << times;
	for (i = 0; zz[i] != '!'; i++);
	fuzhu(zz, i, name, mum);
	for (i = 0; mum[i] != '2'; i++);
	sit = i;
	for (i = 0; i < times; i++) {
		fuzhu2(mum, sit, i + 1);
		if (!mysql_query(sock, mum))
			cout << "true" << endl;
		else cout << "flase" << endl;
		cout << '\n'<<endl;
	}
	return 0;
}
int shuchu(MYSQL* sock,int sum, int x,char* name) {                //sum=11,x=3
	int i, j, k,llll;
	int first, second, third;
	int seconds, thirds;                                          //无奈之举，暂时想不出更好的算法
	int step = 0;
	mm p = (mm)malloc(sizeof(ss));
	mm q = (mm)malloc(sizeof(ss));
	char zz[100] = "update work! set test1 =2 where id = 3";//1为first，2为second,3为third
	//char pp[100] = "alter table work! auto_increment=1;";
	//主键约束真的是又恶心又好，真尼玛难受,有时候真想自创数据库，mysql用的太不舒心了
	char mum[100];
	char nun[100];
	j = 0;
	first = second = third = 0;
	seconds = 0;                   
	thirds = 0;
	for (i = 0; zz[i] != '!'; i++);
	fuzhu(zz, i, name,mum);
	/*for (i = 0; pp[i] != '!'; i++);
	fuzhu(pp, i, name,nun);*/
	for (i = 0; mum[i] != '\0'; i++) {
		if (mum[i] == '1')first = i;
		if (mum[i] == '2')second = i;
		if (mum[i] == '3')third = i;
	}
	if (!p || !q) return 5;
	p = head->next;
	int times = sum / x;                       //这里应该有向上取整的算法 
	if (sum % x != 0)  times += 1;
	inita(sock, x, name);
	for (i = 0; i < times; i++) {

		cout << "你的第" << i + 1 << "套题";
		fuzhu2(mum, first, i + 1);
		if (i+1 < 10)seconds = 0;
		if (i + 1 >= 10) seconds = 1;
		if (i + 1 >= 100) seconds = 2;
		//	int *l=(int*)malloc(sizeof(int)*x);
		for (j = 0; j < x; j++) {
			step = rand() % sum + 1;
			cout<<step<<'P'<<'\n';
			for (k = 0; k < step; k++) { 
				q = p;        p = p->next;
				//cout << p->num << 'S';
			}
			//cout << '\n';
			cout << p->num << ':' << bc[p->num - 1] << ' ';
			fuzhu2(mum, second + seconds, p->num);
			if (p->num < 10)thirds = 0;
			if (p->num >= 10) thirds = 1;
			if (p->num >= 100) thirds = 2;
			//cout << first << ' ' << second << ' ' << third << ' ' << seconds << ' ' << thirds << '\n';
			fuzhu2(mum, third+seconds+thirds, j + 1);
			//mum[second] = '0'+p->num;
			//mum[third] = '0' + j + 1;
			cout << '\n';
			for (llll = 0; mum[llll] != '\0'; llll++) 
				cout << mum[llll];
			cout << '\n';

			if (!mysql_query(sock, mum))
				cout << "true" << endl;
			else cout << "flase" << endl;
			if (dele(p, q)) break;
		}
		cout << '\n';
	}
	getchar();
	getchar();
	getchar();
	return 0;
}

int listdevise(int sum) {
	int i, j, k;
	mm p = (mm)malloc(sizeof(ss));
	if (!p) return 5;
	p->num = 1;
	head->next = p;                                 //P好像未赋值的原因 
	for (i = 1; i < sum; i++) {
		mm q = (mm)malloc(sizeof(ss));            //这里好像是没问题，不清楚
		if (!q) return 5;
		//cout<<p<<' '<<q<<'\n'; 
		q->num = i + 1;
		p->next = q;
		p = q;
		cout << p->num<<'\n';
		//free(q);                                     //就是因为多了free,导致全盘皆错 
	}
	rear->next = p;
	p->next = head->next;
	/*for(i=0;i<sum;i++){
		cout<<p->num<<'\n';
		p=p->next;
	} */
	//free(p);                                        //不能乱删，删了之后p的数据会没了
	return 0;
}
int fun(MYSQL* sock,char *name) {
	int i, j, k;
	int num;
	mm p = (mm)malloc(sizeof(ss));
	MYSQL_RES* result;
	MYSQL_ROW row;
	memset(bc, 'S', sizeof(bc));
	char sent[100] = "select * from !";
	char mum[100];
	i = 0;
	j = 0;
	k = 0;
	int step;
	int sum;
	srand(time(NULL));
	for (i = 0; sent[i] != '\0'; i++) {
		if (sent[i] != '!')mum[j++] = sent[i];
		else
			for (k = 0; name[k] != '\0'; k++)
				mum[j++] = name[k];
	}
	mum[j] = '\0';
	if (!mysql_query(sock, mum))
		cout << "true" << endl;
	else cout << "flase" << endl;
	result= mysql_store_result(sock);
	//num = mysql_num_fields(result);
	i = 0;
	while ((row = mysql_fetch_row(result)))  //遇到最后一行，则中止循环
	{
		cout << row[1][0]<<"            ";
		bc[i++] = row[1][0];
	}
	for (i = 0; bc[i] != 'S'; i++)
		cout << bc[i];
	sum = i;
	cout << '\n' << endl;
	//	freopen("启用输出1.txt","w",stdout);
	cout << "please input the step:";                         //cin>>bc;
	cin >> step;                                              //	for(i=0;bc[i]!='?';i++);    
	if(listdevise(sum)>0)cout<<"错误";                   //序列号排列  3.这里按照思维惯性是应该，但是这里最好有个' ' 
	p = head->next;
	for (i = 0; i < 30; i++) {
		cout << p->num << ':' << bc[p->num - 1]<<"    ";
		p = p->next;
	}
	cout << '\n';
	home(sock, name);
	if(shuchu(sock,sum, step,name)>0)cout<<"错误";
	free(p);
	return 0;


}
int control3(MYSQL* sock, char* name) {
	int i, j, k;
	char zz[100] = "insert into ! values(0,'*')";
	char mum[100];
	int suspend;
	char p;
	j = 0;
	for (i = 0; zz[i] != '\0'; i++) {                                  //这里算法真应该优化，有点繁杂
		if (zz[i] != '!')mum[j++] = zz[i];
		else
			for (k = 0; name[k] != '\0'; k++)
				mum[j++] = name[k];
	}
	mum[j] = '\0';
	for (suspend = 0; mum[suspend] != '*'; suspend++);
	cout << "please input the truth ";
	for (i = 1;; i++) {
		cout << i << ':';
		cin >> p;
		if (p == 'S') break;
		mum[suspend] = p;
		for (j = 0; mum[j] != '\0'; j++)
			cout << mum[j];
		if (!mysql_query(sock, mum))
			cout << "true" << endl;
		else cout << "flase" << endl;
	}
	return 0;
}

int home(MYSQL* sock, char* name) {                               //home和control2可以合并
	char num[100] = "create table work! like homework";
	char mum[100];
	int i, j, k;
	j = 0;
	for (i = 0; num[i] != '\0'; i++) {
		if (num[i] != '!')mum[j++] = num[i];
		else
			for (k = 0; name[k] != '\0'; k++)
				mum[j++] = name[k];
	}
	mum[j] = '\0';
	if (!mysql_query(sock, mum))                      //创建一个workspecialXX 表
		cout << "!" << endl;
	else cout << "flase" << endl;
	return 0;
}

int control2(MYSQL* sock, char* name) {                              //负责输入选项
	char num[100] = "create table ! like xuanxiang";
//	char zz[100] = "insert into ! values(0,'*')";
	char mum[100];
	int i, j, k;
	j = 0;
	for (i = 0; num[i] != '\0'; i++) {
		if (num[i] != '!')mum[j++] = num[i];
		else 
			for (k = 0; name[k] != '\0'; k++)
				mum[j++] = name[k];
	}
	mum[j] = '\0';
	if (!mysql_query(sock, mum))                      //创建一个specialXX 表
		cout << "!" << endl;
	else cout << "flase" << endl;
	return 0;
}
int control1(MYSQL *sock,int step) {
	int i;
	char zz[100] = "insert into zyzhenzhi values(0,' ')";    //这里函数中必须使用char类型，vector失败。中文占两个字节
	//lin[31 + i + 1 ]= num[i];    这句话由于编译器等原因造成，读取方式不一样，最好改成lin[]
	char sx[100] = "insert into zyshuxue  values(0,' ')";    //为对对格数的控制，用空格直接对应
	char name[100]="special";
	if (step == 1) shuru(sock, zz);
	else if (step == 2) shuru(sock, sx);                        //待输入模块，有毛病这里都给我显示错误
	/*while (mm != 'N') {                                          //这里觉得没必要，暂时以一对一。
		cout << "if you want add the one again,please input Y,else input N:";
		cin >> mm;
		if (step == 1 && mm == 'Y') shuru(sock, zz);
		else if (step == 2 && mm == 'Y') shuru(sock, sx);                        //待输入模块，有毛病这里都给我显示错误
	}*/       
	for (i = 0; NUM[i] != '\0'; i++) {
		name[i + 7] = NUM[i];
	}
	name[i + 7] = '\0';
	control2(sock, name);
	return 0;
}
int shuru(MYSQL* sock, char* lin) {
	int i, j;
	cout << "please input your Name of examination paper:";
	cin >> NUM;            //仅仅因为cin导致版本不兼容？
		//scanf("%s",num);
	for (i = 0; NUM[i] != '\0'; i++)
	{
		/*for (j = 0; lin[j] != '\0'; j++)//31
			cout << lin[j];
		cout << '\n';
		cout << lin[31 + i + 1]<< ';' << num[i] << '\n';*/
		lin[32 + i] = NUM[i];
	}
	lin[32 + i] = '\'';
	lin[32 + i + 1] = ')';
	lin[32 + i + 2] = '\0';
	//lin[29]++;
	for (i = 0; lin[i] != '\0'; i++)//31
		cout << lin[i];
	if (!mysql_query(sock, lin))
		cout << "!" << endl;
	else cout << "flase" << endl;

	return 0;
}
int control(MYSQL* sock) {
	int i;
	int step=0;
	char name[100] = "special";
	while (step != -1) {
		system("cls");
		cout << "1.add zyzhenzhi name;" << '\n' << endl;                    //这里可以采用swith case结构
		cout << "2.add zyshuxue name;" << '\n' << endl;
		cout << "3.add yours'name xuanxiang;" << '\n' << endl;
		cout << "4.generate a test question;" << '\n' << endl;
		cout << "5.xxxxx" << '\n' << endl;
		/*if (!mysql_query(sock, lin))                        用于编译异常
			cout << "!" << endl;
		else cout << "flase" << endl;*/
		cout << "please input the number:";
		cin >> step;
		if (step <= 2)    control1(sock, step);

		else if (step == 3) {                             //想在这里直接生成所有试题；
			shitisc(sock);
			cout << "please input the yours'name:";
			cin >> (name + 7);
			control3(sock, name);
		}
		else if (step == 4) {
			shitisc(sock);
			cout << "choose what text you want:";
			cin >> (name + 7);
			fun(sock,name);
			//else if ();
		}
		name[7] ='\0' ;
	}
	return 0;
	}
	
