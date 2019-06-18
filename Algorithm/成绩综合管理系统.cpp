// 管理.cpp : Defines the entry point for the console application.
//


#include <stdio.h>      //用到的头文件
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int t=0;                //定义t为全局变量，意为数据库中存储的学生总人数
int nt;                    //nt用于统计已录入成绩的学生人数
int pm;

void total();           //读取当前学生总人数函数
void n_total();
int caidan();           //菜单函数
void tianjia();         //添加功能函数
int xiugai();           //修改功能函数
void numxiugai();       //按学号修改函数
int chaxun();           //查询功能函数
void CXbynum();         //按学号查询函数
void CXbyid();          //按身份证号查询函数
int schaxun();          //管理者成绩系统查询主函数
void sCXbynum();        //按学号查询函数
void sCXbyname();       //按姓名查询函数
void duqu();            //读取数据库函数
void xianshi();         //显示所有学生个人信息函数
void shanchu();         //删除功能函数
void guanli();          //管理部分主函数
void menu();            //主菜单函数
void studentdenglu();   //学生登录函数
void managedenglu();    //管理者登录函数
int chengjiguanli();    //成绩管理系统
void stianjia();       //成绩管理系统添加函数
void sxiugai();        //成绩管理系统修改函数
void sxianshi();       //成绩管理系统显示函数
void sduqu();
int schaxunp();         //管理者成绩系统查询绩点排名函数
void sCXbyname();
void sCXbynum();
void paiming();         //排名函数
int point(double s,double p);
void gpa();
void sxianshi();


struct students         //定义学生个人信息结构体
{
	char name[100];     //姓名
	char sex[100];      //性别
	char num[100];      //学号
	char yuan[100];     //学院
	char major[100];    //专业
	char cls[100];      //班级
	char birth[100];    //出生年月
	char id[100];       //身份证号
	char phone[100];    //电话号码
	char email[100];    //邮箱
	char address[100];  //家庭住址
}stu[10000];


struct score            //成绩系统结构体
{
	char name[100];     //姓名
	char num[100];      //学号
	char mima[100];     //密码

	double math;        //数学成绩
	double mpoint;      //数学绩点

	double phy;         //物理成绩
	double ppoint;      //物理绩点

	double eng;         //英语成绩
	double epoint;      //英语绩点

	double gpa;         //GPA
}score[10000];

double mcredit = 6;
double pcredit = 4;
double ecredit = 4;


void n_total()//管理者成绩系统中用于计算学生总人数的函数
{
	FILE*fp;
	if((fp=fopen("n_total.txt","r"))==NULL)
	{
		printf("cannot open the file");
		exit(0);
	}
	fscanf(fp,"%d",&nt);
	fclose(fp);
}



int main()//主函数（主界面）
{
    int i,a;
	system("color f3");
	printf("\n\n*****************学生信息管理系统*****************\n\n");
	printf("\n                    ★☆制作:Dave☆★\n");
	printf("\n                          Loading...\n");
	printf("\n                          ");
	for(i=0;i<12;i++)
	{
		printf("▋");
		Sleep(90);
	}
    printf("\n\n*请选择:1.进入系统 2.退出系统\n");
    scanf("%d",&a);
    while (a!=1&&a!=2)
    {
        printf("\n*输入有误 请重新输入*\n");
        scanf("%d",&a);
    }
    if (a==1)
    {
        system("cls");
        menu();
    }
    if (a==2)
    {
        printf("\n*退出系统*\n");
        exit(0);
    }
    return 0;
}


void menu()//选择登陆者身份的登录函数
{
    int a;
    printf("\n**************************************************\n");
    printf("\n*************欢迎进入学生信息管理系统*************\n");
    printf("\n**********请进行身份选择:1.学生 2.管理员**********\n");
    scanf("%d",&a);
    while (a!=1&&a!=2)
    {
        printf("\n*输入有误 请重新输入*\n");
        scanf("%d",&a);
    }
    //if (a==1) studentdenglu();
    if (a==2) managedenglu();
}

/*void studentdenglu()
{
    char a[100],b[100];
    printf("\n**************************************************\n");
    printf("\n*************欢迎进入学生信息管理系统*************\n");
    printf("\n\t学号:");
    scanf("%s",a);
    printf("\n\t密码:");
    scanf("%s",b);

}*/

void managedenglu()//管理者登录函数
{
    char a[100];
    char m[100]="guanli123";
    int b;
    printf("\n**************************************************\n");
    printf("\n*************欢迎进入学生信息管理系统*************\n");
    printf("\n\t请输入管理员密码:");
    scanf("%s",a);
    if (strcmp(m,a)!=0)
    {
        printf("\n\t密码有误 请重新输入:");
        scanf("%s",a);
    }
    if (!strcmp(m,a))
    {
        printf("\n\t请选择管理内容:1.学生基本信息管理 2.学生成绩管理\n");
        scanf("%d",&b);
        while (b!=1&&b!=2)
        {
            printf("\n*输入有误 请重新输入*\n");
            scanf("%d",&b);
        }
        //if (b==1) caidan();
        if (b==2) chengjiguanli();
    }
}

int chengjiguanli()//管理者成绩管理系统
{
    int a;
    do
    {
        printf("\n**************************************************\n");
        printf("\n**************学生成绩管理系统教师端**************\n");
        printf("\n*1.添加成绩\n");
        printf("\n*2.修改成绩\n");
        printf("\n*3.查询成绩\n");
        printf("\n*4.显示成绩\n");
        printf("\n**************************************************\n");
        printf("\n请选择(1~4):\n");
        scanf("%d",&a);
        while (a<1||a>4)
        {
            printf("\n*输入有误 请重新输入*\n");
            scanf("%d",&a);
        }
        if (a==1) stianjia();//管理者成绩添加函数
        if (a==2) sxiugai();//管理者成绩修改函数
        if (a==3) schaxun();//管理者成绩查询函数
        if (a==4) sxianshi();//管理者成绩显示函数
     }while (a!=5);
    printf("\n*退出系统*\n");
    exit(0);
}

void stianjia()
{
	int i,n,s,a;
	printf("请输入录入信息总人数:\n");
	scanf("%d",&n);
	n_total();
	s=t+n;
	FILE*fp;
	if((fp=fopen("score.txt","w"))==NULL)
	{
		printf("cannot open the file");
		exit(0);
	}
	fprintf(fp,"%d",s);
	fclose(fp);

	for(i=0;i<n;i++)        //输入
	{
		printf("************************************************\n");
		printf("N0.%d",t+i+1);
		printf("\n姓名:");
		scanf("%s",&score[i].name );
		fflush(stdin);//清理键盘缓冲区，包含在“stdio.h”中。也可以用rewind(stdin) ;
	

		printf("\n学号:");
		scanf("%s",&score[i].num );
		fflush(stdin);//清理键盘缓冲区

		printf("\n高数成绩:");
		scanf("%lf",&score[i].math );
		fflush(stdin);	//清理键盘缓冲区
		score[i].mpoint=point(score[i].math,score[i].mpoint);

		printf("\n大物成绩:");
		scanf("%lf",&score[i].phy );
		fflush(stdin);//清理键盘缓冲区
		score[i].ppoint=point(score[i].phy,score[i].ppoint);

		printf("\n英语成绩:");
		scanf("%lf",&score[i].eng  );
		fflush(stdin);//清理键盘缓冲区
		score[i].epoint=point(score[i].eng,score[i].epoint);



		printf("***************该学生信息录入完毕***************\n");
		gpa();
		printf("该学生信息如下：\n");
		printf("%s %s %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf\n\n\r",score[i].name,score[i].num,score[i].math,score[i].mpoint,score[i].phy,score[i].ppoint,score[i].eng,score[i].epoint,score[i].gpa);

		FILE*fp;
		if((fp=fopen("score.txt","a+"))==NULL)
		{
		printf("cannot open the output file");
		exit(0);
		}
		fprintf(fp,"%s %s %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf\n\n\r",score[i].name,score[i].num,score[i].math,score[i].mpoint,score[i].phy,score[i].ppoint,score[i].eng,score[i].epoint,score[i].gpa);
		fclose(fp);

	}

	printf("\n请选择:1.返回主页面 2.退出系统\n");
    scanf("%d",&a);
    while (a<1||a>2)
    {
        printf("\n*输入有误 请重新输入*\n");
        scanf("%d",&a);
    }
    if (a==1)
    {
        system("cls");
        chengjiguanli();//返回管理者成绩管理主界面
    }
    if (a==2)
    {
        printf("\n*退出系统*\n");
        exit(0);
    }
}

void sxiugai()

{
	sduqu();
    char a[100];
    char snamenew[100],snumnew[100];
    double smathnew,sphynew,sengnew;
    int i,j=0,b,c,d,e,x;
    do
    {
        j=0;
        printf("\n请输入需要修改的信息的学号:\n");
        scanf("%s",&a);
        for (i=0;i<10000;i++)
        {
            if (0==strcmp(a,score[i].num))
            {
                j=1;
                printf("\t该生信息如下：\n");
                printf("\t姓名：%s\n\t学号：%s\n\t高数成绩：%.2lf\n\t大物成绩：%.2lf\n\t英语成绩：%.2lf\n\t",score[i].name,score[i].num,score[i].math,score[i].phy,score[i].eng);
                printf("---------------------------------------------------\n");
                printf("\n确认修改请按1  返回修改页面请按2\n");
                scanf("%d", &x);
                if (x == 1)
                {
                    printf("\n请选择内容修改方式:1.修改整条信息 2.修改部分信息\n");
                    scanf("%d",&b);
                    while (b<1||b>2)
                    {
                        printf("\n*输入有误 请重新输入*\n");
                        scanf("%d",&b);
                    }
                    if (b==1)
                    {
                        printf("\n请输入修改后新的信息:\n");

                      	printf("N0.%d",t+i+1);
                       	printf("\n姓名:");
						scanf("%s",&score[i].name );
						fflush(stdin);//清理键盘缓冲区
	

						printf("\n学号:");
						scanf("%s",&score[i].num );
						fflush(stdin);//清理键盘缓冲区

						printf("\n高数成绩:");
						scanf("%lf",&score[i].math );
						fflush(stdin);	//清理键盘缓冲区
						score[i].mpoint=point(score[i].math,score[i].mpoint);

						printf("\n大物成绩:");
						scanf("%lf",&score[i].phy );
						fflush(stdin);//清理键盘缓冲区
						score[i].ppoint=point(score[i].phy,score[i].ppoint);

						printf("\n英语成绩:");
						scanf("%lf",&score[i].eng  );
						fflush(stdin);//清理键盘缓冲区
						score[i].epoint=point(score[i].eng,score[i].epoint);
						
                    	gpa();



                        printf("\n*修改成功!*");
                        printf("\n*****修改后该条信息为*****\n");
                        printf("\t姓名：%s\n\t学号：%s\n\t高数成绩：%.2lf\n\t大物成绩：%.2lf\n\t英语成绩：%.2lf\n\t",score[i].name,score[i].num,score[i].math,score[i].phy,score[i].eng);
                        printf("**********************************");
                    }
                    if (b==2)
                    {
                        printf("\n请选择需要修改的内容:\n1.姓名 2.学号 4.高数成绩 5.大物成绩 6.英语成绩 7.返回修改页面\n");
                        scanf("%d",&c);
                        while (c<1||c>7)
                        {
                            printf("\n*输入有误 请重新输入*\n");
                            scanf("%d",&c);
                        }
                        if (c==1)
                        {
                            printf("\n请输入更改后的姓名:\n");
                            scanf("%s",snamenew);
                            strcpy(score[i].name,snamenew);
                        }
                        if (c==2)
                        {
                            printf("\n请输入更改后的学号:\n");
                            scanf("%s",snumnew);
                            strcpy(score[i].num,snumnew);
                        }
                        if (c==4)
                        {
                            printf("\n请输入更改后的高数成绩:\n");
                            scanf("%lf",&smathnew);
                            score[i].math=smathnew;
                            score[i].mpoint=point(score[i].math,score[i].mpoint);
                        }
                        if (c==5)
                        {
                            printf("\n请输入更改后的大物成绩:\n");
                            scanf("%lf",&sphynew);
                            score[i].phy=sphynew;
                            score[i].ppoint=point(score[i].phy,score[i].ppoint);
                        }
                        if (c==6)
                        {
                            printf("\n请输入更改后的英语成绩:\n");
                            scanf("%lf",&sengnew);
                            score[i].eng=sengnew;
                            score[i].epoint=point(score[i].eng,score[i].epoint);
                        }
                        if (c==7) sxiugai();
                        printf("\n*修改成功!*");
                        printf("\n*****修改后该条信息为*****\n");
                        printf("\t姓名：%s\n\t学号：%s\n\t高数成绩：%.2lf\n\t大物成绩：%.2lf\n\t英语成绩：%.2lf\n\t",score[i].name,score[i].num,score[i].math,score[i].phy,score[i].eng);
                        printf("**********************************");
					
						gpa();
						
                    }



                    FILE*fp;
                    if((fp=fopen("score.txt","w"))==NULL)
                    {
                        printf("cannot open the file");
                        exit(0);
                    }
                    fprintf(fp,"%s %s %.2lf %.2f %.2lf %.2lf %.2lf %.2lf %.2lf\n\r",score[i].name,score[i].num,score[i].math,score[i].mpoint,score[i].phy,score[i].ppoint,score[i].eng,score[i].epoint,score[i].gpa);
                    fclose(fp);

                    n_total();
                    for(i=1;i<t;i++)
                    {
                        FILE*fp;
                        if((fp=fopen("score.txt","a+"))==NULL)
                        {
                            printf("cannot open the file");
                            exit(0);
                        }
                        fprintf(fp,"%s %s %.2lf %.2f %.2lf %.2lf %.2lf %.2lf %.2lf\n\r",score[i].name,score[i].num,score[i].math,score[i].mpoint,score[i].phy,score[i].ppoint,score[i].eng,score[i].epoint,score[i].gpa);
                        fclose(fp);
                    }

                    printf("\n请选择:1.返回主页面 2.继续修改 3.退出系统\n");
                    scanf("%d",&d);
                    while (d<1||d>3)
                    {
                        printf("\n*输入有误 请重新输入*\n");
                        scanf("%d",&d);
                    }
                    if (d==1)
                    {
                        system("cls");
                        chengjiguanli();
                    }
                    if (d==3)
                    {
                        printf("\n*退出系统*\n");
                        exit(0);
                    }
                }
                else if (x==2)
                {
                    sxiugai();
                }
            }
        }
        if (j==0)
        {
            printf("\n查无此人\n");
            printf("\n请选择:1.返回修改页面 2.返回主页面 3.退出系统\n");
            scanf("%d",&e);
            while (e<1||e>3)
            {
                printf("\n*输入有误 请重新输入*\n");
                scanf("%d",&e);
            }
            if (e==1) sxiugai();
            if (e==2)
            {
                system("cls");
                chengjiguanli();
            }
            if (e==3)
            {
                printf("\n*退出系统*\n");
                exit(0);
            }
        }
    }while (d==2);
}

int point(double s,double p)       //输入学生成绩的同时调用此函数
{                                   //示例：point(score[i].math,score[i].mpoint);
	if (s >= 95 && s <= 100)p = 4.33;
	else if (s >= 90 && s <= 94)p = 4.00;
	else if (s >= 85 && s <= 89)p = 3.67;
	else if (s >= 82 && s <= 84)p = 3.33;
	else if (s >= 78 && s <= 81)p = 3.00;
	else if (s >= 75 && s <= 77)p = 2.67;
	else if (s >= 72 && s <= 74)p = 2.33;
	else if (s >= 68 && s <= 71)p = 2.00;
	else if (s >= 64 && s <= 67)p = 1.67;
	else if (s >= 61 && s <= 63)p = 1.33;
	else if (s == 60)p = 1.00;
	else p = 0.00;
	
	return p;
}

void gpa()           //输入学生成绩时先调用point(int s,int p);再调用gpa();
{                    //输入学生成绩的同时统计出所有相关数据后，一并存入score.txt中
	int i;
	double sum;
	n_total();
	for (i = 0; i < nt; i++)
	{
		sum = score[i].math*score[i].mpoint + score[i].phy*score[i].ppoint + score[i].eng*score[i].epoint;
		score[i].gpa = sum / (mcredit + pcredit + ecredit);
	}

	FILE*fp;         //此部分最好写在成绩输入部分的程序中
	if ((fp = fopen("score.txt", "a+")) == NULL)
	{
		printf("cannot open the file");
		exit(0);
	}
	for (i = 0; i<nt; i++)
	{
		fprintf(fp, "%s %s %.2lf %.2f %.2lf %.2lf %.2lf %.2lf %.2lf\n\r", score[i].name, score[i].num, score[i].math, score[i].mpoint, &score[i].phy, score[i].ppoint, score[i].eng, score[i].epoint, score[i].gpa);
	}
	fclose(fp);
}

void sduqu()
{
	int i;
	FILE*fp;

	if((fp=fopen("score.txt","r"))==NULL)
	{
		printf("cannot open the file");
		exit(0);
	}
	n_total();
	for(i=0;i<nt;i++)
	{
		fprintf(fp,"%s %s %.2lf %.2f %.2lf %.2lf %.2lf %.2lf %.2lf\n\r",score[i].name,score[i].num,score[i].math,score[i].mpoint,score[i].phy,score[i].ppoint,score[i].eng,score[i].epoint,score[i].gpa);

	}fclose(fp);
}

int schaxun()
{
    int a;
    printf("\n**************************************************\n");
    printf("\n*****查询信息*****\n");
    printf("\n*查询方式*\n");
    printf("\n1.按学号查找\n2.按姓名查找\n3.返回主界面\n");
    printf("\n*请选择查询方式*\n");
    scanf("%d",&a);
    while (a<1||a>3)
    {
        printf("\n*输入有误 请重新输入*\n");
        scanf("%d",&a);
    }
    if (a==1) sCXbynum();
    if (a==2) sCXbyname();
    if (a==3)
    {
        system("cls");
        chengjiguanli();
    }
    return 0;
}

void sCXbynum()
{
    sduqu();
    
    char a[100];
    int i,j,b,c;
    do
    {
        j=0;
        printf("请输入你要查找的联系人学号:");
        scanf("%s",a);
		n_total();
		FILE*fp;
        if((fp=fopen("score.txt","r"))==NULL)
			{
                printf("cannot open the file");
                exit(0);
			}

        for(i=0;i<nt;i++)
        {
            if(!strcmp(a,score[i].num))
            {
                j=1;
                printf("\n该人信息为:\n");
	        	fprintf(fp,"%s %s %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf\n\r",score[i].name,score[i].num,score[i].math,score[i].mpoint,score[i].phy,score[i].ppoint,score[i].eng,score[i].epoint,score[i].gpa);
                printf("**********************************");

                printf("\n请选择:1.返回主页面 2.返回查询页面 3.继续按学号查询 4.退出系统\n");
                scanf("%d",&c);
                while (c<1||c>4)
                {
                    printf("\n*输入有误 请重新输入*\n");
                    scanf("%d",&c);
                }
                if (c==1)
                {
                    system("cls");
                    chengjiguanli();
                }
                if (c==2) schaxun();
                if (c==4)
                {
                    printf("\n*退出系统*\n");
                    exit(0);
                }
            }
        }
        if (j==0)
        {
            printf("\n查无此人\n");
            printf("\n请选择:1.返回查询页面 2.返回主页面 3.退出系统\n");
            scanf("%d",&b);
            while (b<1||b>3)
            {
                printf("\n*输入有误 请重新输入*\n");
                scanf("%d",&b);
            }
            if (b==1) schaxun();
            if (b==2)
            {
                system("cls");
                chengjiguanli();
            }
            if (b==3)
            {
                printf("\n*退出系统*\n");
                exit(0);
            }
        }
    }while (c==3);
}

void sCXbyname()
{
    sduqu();
    char a[100];
    FILE*fp;
    n_total();
	
    if((fp=fopen("score.txt","r"))==NULL)
	{
         printf("cannot open the file");
         exit(0);
	}
    int i,j,b,c;
    do
    {
        j=0;
        printf("请输入你要查找的联系人姓名:");
        scanf("%s",a);
        for(i=0;i<nt;i++)
        {
            if(0 == strcmp(a,score[i].name))
            {
                j=1;
				printf("\n该人信息为:\n");
	        	fprintf(fp,"%s %s %.2lf %.2f %.2lf %.2lf %.2lf %.2lf %.2lf\n\r",score[i].name,score[i].num,score[i].math,score[i].mpoint,score[i].phy,score[i].ppoint,score[i].eng,score[i].epoint,score[i].gpa);
                printf("**********************************");

				printf("\n请选择:1.返回主页面 2.返回查询页面 3.继续按姓名 4.退出系统\n");
                scanf("%d",&c);
                while (c<1||c>4)
                {
                    printf("\n*输入有误 请重新输入*\n");
                    scanf("%d",&c);
                }
                if (c==1)
                {
                    system("cls");
                    chengjiguanli();
                }
                if (c==2) schaxun();
                if (c==4)
                {
                    printf("\n*退出系统*\n");
                    exit(0);
                }
            }
        }
        if (j==0)
        {
            printf("\n查无此人\n");
            printf("\n请选择:1.返回查询页面 2.返回主页面 3.退出系统\n");
            scanf("%d",&b);
            while (b<1||b>3)
            {
                printf("\n*输入有误 请重新输入*\n");
                scanf("%d",&b);
            }
            if (b==1) schaxun();
            if (b==2)
            {
                system("cls");
                chengjiguanli();
            }
            if (b==3)
            {
                printf("\n*退出系统*\n");
                exit(0);
            }
        }
    }while (c==3);
}



void sxianshi()
{
	int i,a;
//	sduqu();
	
	FILE*fp;
	if((fp=fopen("score.txt","r"))==NULL)
	{
		printf("cannot open the file");
		exit(0);
	}
	n_total();
	
	for(i=0;i<nt;i++)
	{
		fprintf(fp, "%s %s %.2lf %.2f %.2lf %.2lf %.2lf %.2lf %.2lf\n\r", score[i].name, score[i].num, score[i].math, score[i].mpoint, &score[i].phy, score[i].ppoint, score[i].eng, score[i].epoint, score[i].gpa);
	}
	fclose(fp);

	printf("********************************************\n");
	printf("**********当前存储的学生信息如下************\n");
	for(i=0;i<nt;i++)
	{
		printf("N0.%d\n",i+1);
        printf("\t姓名：%s\n\t学号：%s\n\t高数成绩：%.2lf\n\t高数GPA：%.2lf\n\t大物成绩：%.2lf\n\t大物GPA：%.2f\n\t英语成绩：%.2lf\n\t英语GPA：%.2f\n\tGPA：%.2f\n\t",score[i].name,score[i].num,score[i].math, score[i].mpoint, &score[i].phy, score[i].ppoint, score[i].eng, score[i].epoint, score[i].gpa);
		printf("********************************************\n");
	}

	printf("\n请选择:1.返回主页面 2.退出系统\n");
    scanf("%d",&a);
    while (a<1||a>2)
    {
        printf("\n*输入有误 请重新输入*\n");
        scanf("%d",&a);
    }
    if (a==1)
    {
        system("cls");
        chengjiguanli();
    }
    if (a==2)
    {
        printf("\n*退出系统*\n");
        exit(0);
    }
}


