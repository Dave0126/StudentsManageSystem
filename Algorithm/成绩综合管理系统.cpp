// ����.cpp : Defines the entry point for the console application.
//


#include <stdio.h>      //�õ���ͷ�ļ�
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int t=0;                //����tΪȫ�ֱ�������Ϊ���ݿ��д洢��ѧ��������
int nt;                    //nt����ͳ����¼��ɼ���ѧ������
int pm;

void total();           //��ȡ��ǰѧ������������
void n_total();
int caidan();           //�˵�����
void tianjia();         //��ӹ��ܺ���
int xiugai();           //�޸Ĺ��ܺ���
void numxiugai();       //��ѧ���޸ĺ���
int chaxun();           //��ѯ���ܺ���
void CXbynum();         //��ѧ�Ų�ѯ����
void CXbyid();          //�����֤�Ų�ѯ����
int schaxun();          //�����߳ɼ�ϵͳ��ѯ������
void sCXbynum();        //��ѧ�Ų�ѯ����
void sCXbyname();       //��������ѯ����
void duqu();            //��ȡ���ݿ⺯��
void xianshi();         //��ʾ����ѧ��������Ϣ����
void shanchu();         //ɾ�����ܺ���
void guanli();          //������������
void menu();            //���˵�����
void studentdenglu();   //ѧ����¼����
void managedenglu();    //�����ߵ�¼����
int chengjiguanli();    //�ɼ�����ϵͳ
void stianjia();       //�ɼ�����ϵͳ��Ӻ���
void sxiugai();        //�ɼ�����ϵͳ�޸ĺ���
void sxianshi();       //�ɼ�����ϵͳ��ʾ����
void sduqu();
int schaxunp();         //�����߳ɼ�ϵͳ��ѯ������������
void sCXbyname();
void sCXbynum();
void paiming();         //��������
int point(double s,double p);
void gpa();
void sxianshi();


struct students         //����ѧ��������Ϣ�ṹ��
{
	char name[100];     //����
	char sex[100];      //�Ա�
	char num[100];      //ѧ��
	char yuan[100];     //ѧԺ
	char major[100];    //רҵ
	char cls[100];      //�༶
	char birth[100];    //��������
	char id[100];       //���֤��
	char phone[100];    //�绰����
	char email[100];    //����
	char address[100];  //��ͥסַ
}stu[10000];


struct score            //�ɼ�ϵͳ�ṹ��
{
	char name[100];     //����
	char num[100];      //ѧ��
	char mima[100];     //����

	double math;        //��ѧ�ɼ�
	double mpoint;      //��ѧ����

	double phy;         //����ɼ�
	double ppoint;      //������

	double eng;         //Ӣ��ɼ�
	double epoint;      //Ӣ�Ｈ��

	double gpa;         //GPA
}score[10000];

double mcredit = 6;
double pcredit = 4;
double ecredit = 4;


void n_total()//�����߳ɼ�ϵͳ�����ڼ���ѧ���������ĺ���
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



int main()//�������������棩
{
    int i,a;
	system("color f3");
	printf("\n\n*****************ѧ����Ϣ����ϵͳ*****************\n\n");
	printf("\n                    �������:Dave���\n");
	printf("\n                          Loading...\n");
	printf("\n                          ");
	for(i=0;i<12;i++)
	{
		printf("��");
		Sleep(90);
	}
    printf("\n\n*��ѡ��:1.����ϵͳ 2.�˳�ϵͳ\n");
    scanf("%d",&a);
    while (a!=1&&a!=2)
    {
        printf("\n*�������� ����������*\n");
        scanf("%d",&a);
    }
    if (a==1)
    {
        system("cls");
        menu();
    }
    if (a==2)
    {
        printf("\n*�˳�ϵͳ*\n");
        exit(0);
    }
    return 0;
}


void menu()//ѡ���½����ݵĵ�¼����
{
    int a;
    printf("\n**************************************************\n");
    printf("\n*************��ӭ����ѧ����Ϣ����ϵͳ*************\n");
    printf("\n**********��������ѡ��:1.ѧ�� 2.����Ա**********\n");
    scanf("%d",&a);
    while (a!=1&&a!=2)
    {
        printf("\n*�������� ����������*\n");
        scanf("%d",&a);
    }
    //if (a==1) studentdenglu();
    if (a==2) managedenglu();
}

/*void studentdenglu()
{
    char a[100],b[100];
    printf("\n**************************************************\n");
    printf("\n*************��ӭ����ѧ����Ϣ����ϵͳ*************\n");
    printf("\n\tѧ��:");
    scanf("%s",a);
    printf("\n\t����:");
    scanf("%s",b);

}*/

void managedenglu()//�����ߵ�¼����
{
    char a[100];
    char m[100]="guanli123";
    int b;
    printf("\n**************************************************\n");
    printf("\n*************��ӭ����ѧ����Ϣ����ϵͳ*************\n");
    printf("\n\t���������Ա����:");
    scanf("%s",a);
    if (strcmp(m,a)!=0)
    {
        printf("\n\t�������� ����������:");
        scanf("%s",a);
    }
    if (!strcmp(m,a))
    {
        printf("\n\t��ѡ���������:1.ѧ��������Ϣ���� 2.ѧ���ɼ�����\n");
        scanf("%d",&b);
        while (b!=1&&b!=2)
        {
            printf("\n*�������� ����������*\n");
            scanf("%d",&b);
        }
        //if (b==1) caidan();
        if (b==2) chengjiguanli();
    }
}

int chengjiguanli()//�����߳ɼ�����ϵͳ
{
    int a;
    do
    {
        printf("\n**************************************************\n");
        printf("\n**************ѧ���ɼ�����ϵͳ��ʦ��**************\n");
        printf("\n*1.��ӳɼ�\n");
        printf("\n*2.�޸ĳɼ�\n");
        printf("\n*3.��ѯ�ɼ�\n");
        printf("\n*4.��ʾ�ɼ�\n");
        printf("\n**************************************************\n");
        printf("\n��ѡ��(1~4):\n");
        scanf("%d",&a);
        while (a<1||a>4)
        {
            printf("\n*�������� ����������*\n");
            scanf("%d",&a);
        }
        if (a==1) stianjia();//�����߳ɼ���Ӻ���
        if (a==2) sxiugai();//�����߳ɼ��޸ĺ���
        if (a==3) schaxun();//�����߳ɼ���ѯ����
        if (a==4) sxianshi();//�����߳ɼ���ʾ����
     }while (a!=5);
    printf("\n*�˳�ϵͳ*\n");
    exit(0);
}

void stianjia()
{
	int i,n,s,a;
	printf("������¼����Ϣ������:\n");
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

	for(i=0;i<n;i++)        //����
	{
		printf("************************************************\n");
		printf("N0.%d",t+i+1);
		printf("\n����:");
		scanf("%s",&score[i].name );
		fflush(stdin);//������̻������������ڡ�stdio.h���С�Ҳ������rewind(stdin) ;
	

		printf("\nѧ��:");
		scanf("%s",&score[i].num );
		fflush(stdin);//������̻�����

		printf("\n�����ɼ�:");
		scanf("%lf",&score[i].math );
		fflush(stdin);	//������̻�����
		score[i].mpoint=point(score[i].math,score[i].mpoint);

		printf("\n����ɼ�:");
		scanf("%lf",&score[i].phy );
		fflush(stdin);//������̻�����
		score[i].ppoint=point(score[i].phy,score[i].ppoint);

		printf("\nӢ��ɼ�:");
		scanf("%lf",&score[i].eng  );
		fflush(stdin);//������̻�����
		score[i].epoint=point(score[i].eng,score[i].epoint);



		printf("***************��ѧ����Ϣ¼�����***************\n");
		gpa();
		printf("��ѧ����Ϣ���£�\n");
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

	printf("\n��ѡ��:1.������ҳ�� 2.�˳�ϵͳ\n");
    scanf("%d",&a);
    while (a<1||a>2)
    {
        printf("\n*�������� ����������*\n");
        scanf("%d",&a);
    }
    if (a==1)
    {
        system("cls");
        chengjiguanli();//���ع����߳ɼ�����������
    }
    if (a==2)
    {
        printf("\n*�˳�ϵͳ*\n");
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
        printf("\n��������Ҫ�޸ĵ���Ϣ��ѧ��:\n");
        scanf("%s",&a);
        for (i=0;i<10000;i++)
        {
            if (0==strcmp(a,score[i].num))
            {
                j=1;
                printf("\t������Ϣ���£�\n");
                printf("\t������%s\n\tѧ�ţ�%s\n\t�����ɼ���%.2lf\n\t����ɼ���%.2lf\n\tӢ��ɼ���%.2lf\n\t",score[i].name,score[i].num,score[i].math,score[i].phy,score[i].eng);
                printf("---------------------------------------------------\n");
                printf("\nȷ���޸��밴1  �����޸�ҳ���밴2\n");
                scanf("%d", &x);
                if (x == 1)
                {
                    printf("\n��ѡ�������޸ķ�ʽ:1.�޸�������Ϣ 2.�޸Ĳ�����Ϣ\n");
                    scanf("%d",&b);
                    while (b<1||b>2)
                    {
                        printf("\n*�������� ����������*\n");
                        scanf("%d",&b);
                    }
                    if (b==1)
                    {
                        printf("\n�������޸ĺ��µ���Ϣ:\n");

                      	printf("N0.%d",t+i+1);
                       	printf("\n����:");
						scanf("%s",&score[i].name );
						fflush(stdin);//������̻�����
	

						printf("\nѧ��:");
						scanf("%s",&score[i].num );
						fflush(stdin);//������̻�����

						printf("\n�����ɼ�:");
						scanf("%lf",&score[i].math );
						fflush(stdin);	//������̻�����
						score[i].mpoint=point(score[i].math,score[i].mpoint);

						printf("\n����ɼ�:");
						scanf("%lf",&score[i].phy );
						fflush(stdin);//������̻�����
						score[i].ppoint=point(score[i].phy,score[i].ppoint);

						printf("\nӢ��ɼ�:");
						scanf("%lf",&score[i].eng  );
						fflush(stdin);//������̻�����
						score[i].epoint=point(score[i].eng,score[i].epoint);
						
                    	gpa();



                        printf("\n*�޸ĳɹ�!*");
                        printf("\n*****�޸ĺ������ϢΪ*****\n");
                        printf("\t������%s\n\tѧ�ţ�%s\n\t�����ɼ���%.2lf\n\t����ɼ���%.2lf\n\tӢ��ɼ���%.2lf\n\t",score[i].name,score[i].num,score[i].math,score[i].phy,score[i].eng);
                        printf("**********************************");
                    }
                    if (b==2)
                    {
                        printf("\n��ѡ����Ҫ�޸ĵ�����:\n1.���� 2.ѧ�� 4.�����ɼ� 5.����ɼ� 6.Ӣ��ɼ� 7.�����޸�ҳ��\n");
                        scanf("%d",&c);
                        while (c<1||c>7)
                        {
                            printf("\n*�������� ����������*\n");
                            scanf("%d",&c);
                        }
                        if (c==1)
                        {
                            printf("\n��������ĺ������:\n");
                            scanf("%s",snamenew);
                            strcpy(score[i].name,snamenew);
                        }
                        if (c==2)
                        {
                            printf("\n��������ĺ��ѧ��:\n");
                            scanf("%s",snumnew);
                            strcpy(score[i].num,snumnew);
                        }
                        if (c==4)
                        {
                            printf("\n��������ĺ�ĸ����ɼ�:\n");
                            scanf("%lf",&smathnew);
                            score[i].math=smathnew;
                            score[i].mpoint=point(score[i].math,score[i].mpoint);
                        }
                        if (c==5)
                        {
                            printf("\n��������ĺ�Ĵ���ɼ�:\n");
                            scanf("%lf",&sphynew);
                            score[i].phy=sphynew;
                            score[i].ppoint=point(score[i].phy,score[i].ppoint);
                        }
                        if (c==6)
                        {
                            printf("\n��������ĺ��Ӣ��ɼ�:\n");
                            scanf("%lf",&sengnew);
                            score[i].eng=sengnew;
                            score[i].epoint=point(score[i].eng,score[i].epoint);
                        }
                        if (c==7) sxiugai();
                        printf("\n*�޸ĳɹ�!*");
                        printf("\n*****�޸ĺ������ϢΪ*****\n");
                        printf("\t������%s\n\tѧ�ţ�%s\n\t�����ɼ���%.2lf\n\t����ɼ���%.2lf\n\tӢ��ɼ���%.2lf\n\t",score[i].name,score[i].num,score[i].math,score[i].phy,score[i].eng);
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

                    printf("\n��ѡ��:1.������ҳ�� 2.�����޸� 3.�˳�ϵͳ\n");
                    scanf("%d",&d);
                    while (d<1||d>3)
                    {
                        printf("\n*�������� ����������*\n");
                        scanf("%d",&d);
                    }
                    if (d==1)
                    {
                        system("cls");
                        chengjiguanli();
                    }
                    if (d==3)
                    {
                        printf("\n*�˳�ϵͳ*\n");
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
            printf("\n���޴���\n");
            printf("\n��ѡ��:1.�����޸�ҳ�� 2.������ҳ�� 3.�˳�ϵͳ\n");
            scanf("%d",&e);
            while (e<1||e>3)
            {
                printf("\n*�������� ����������*\n");
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
                printf("\n*�˳�ϵͳ*\n");
                exit(0);
            }
        }
    }while (d==2);
}

int point(double s,double p)       //����ѧ���ɼ���ͬʱ���ô˺���
{                                   //ʾ����point(score[i].math,score[i].mpoint);
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

void gpa()           //����ѧ���ɼ�ʱ�ȵ���point(int s,int p);�ٵ���gpa();
{                    //����ѧ���ɼ���ͬʱͳ�Ƴ�����������ݺ�һ������score.txt��
	int i;
	double sum;
	n_total();
	for (i = 0; i < nt; i++)
	{
		sum = score[i].math*score[i].mpoint + score[i].phy*score[i].ppoint + score[i].eng*score[i].epoint;
		score[i].gpa = sum / (mcredit + pcredit + ecredit);
	}

	FILE*fp;         //�˲������д�ڳɼ����벿�ֵĳ�����
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
    printf("\n*****��ѯ��Ϣ*****\n");
    printf("\n*��ѯ��ʽ*\n");
    printf("\n1.��ѧ�Ų���\n2.����������\n3.����������\n");
    printf("\n*��ѡ���ѯ��ʽ*\n");
    scanf("%d",&a);
    while (a<1||a>3)
    {
        printf("\n*�������� ����������*\n");
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
        printf("��������Ҫ���ҵ���ϵ��ѧ��:");
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
                printf("\n������ϢΪ:\n");
	        	fprintf(fp,"%s %s %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf\n\r",score[i].name,score[i].num,score[i].math,score[i].mpoint,score[i].phy,score[i].ppoint,score[i].eng,score[i].epoint,score[i].gpa);
                printf("**********************************");

                printf("\n��ѡ��:1.������ҳ�� 2.���ز�ѯҳ�� 3.������ѧ�Ų�ѯ 4.�˳�ϵͳ\n");
                scanf("%d",&c);
                while (c<1||c>4)
                {
                    printf("\n*�������� ����������*\n");
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
                    printf("\n*�˳�ϵͳ*\n");
                    exit(0);
                }
            }
        }
        if (j==0)
        {
            printf("\n���޴���\n");
            printf("\n��ѡ��:1.���ز�ѯҳ�� 2.������ҳ�� 3.�˳�ϵͳ\n");
            scanf("%d",&b);
            while (b<1||b>3)
            {
                printf("\n*�������� ����������*\n");
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
                printf("\n*�˳�ϵͳ*\n");
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
        printf("��������Ҫ���ҵ���ϵ������:");
        scanf("%s",a);
        for(i=0;i<nt;i++)
        {
            if(0 == strcmp(a,score[i].name))
            {
                j=1;
				printf("\n������ϢΪ:\n");
	        	fprintf(fp,"%s %s %.2lf %.2f %.2lf %.2lf %.2lf %.2lf %.2lf\n\r",score[i].name,score[i].num,score[i].math,score[i].mpoint,score[i].phy,score[i].ppoint,score[i].eng,score[i].epoint,score[i].gpa);
                printf("**********************************");

				printf("\n��ѡ��:1.������ҳ�� 2.���ز�ѯҳ�� 3.���������� 4.�˳�ϵͳ\n");
                scanf("%d",&c);
                while (c<1||c>4)
                {
                    printf("\n*�������� ����������*\n");
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
                    printf("\n*�˳�ϵͳ*\n");
                    exit(0);
                }
            }
        }
        if (j==0)
        {
            printf("\n���޴���\n");
            printf("\n��ѡ��:1.���ز�ѯҳ�� 2.������ҳ�� 3.�˳�ϵͳ\n");
            scanf("%d",&b);
            while (b<1||b>3)
            {
                printf("\n*�������� ����������*\n");
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
                printf("\n*�˳�ϵͳ*\n");
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
	printf("**********��ǰ�洢��ѧ����Ϣ����************\n");
	for(i=0;i<nt;i++)
	{
		printf("N0.%d\n",i+1);
        printf("\t������%s\n\tѧ�ţ�%s\n\t�����ɼ���%.2lf\n\t����GPA��%.2lf\n\t����ɼ���%.2lf\n\t����GPA��%.2f\n\tӢ��ɼ���%.2lf\n\tӢ��GPA��%.2f\n\tGPA��%.2f\n\t",score[i].name,score[i].num,score[i].math, score[i].mpoint, &score[i].phy, score[i].ppoint, score[i].eng, score[i].epoint, score[i].gpa);
		printf("********************************************\n");
	}

	printf("\n��ѡ��:1.������ҳ�� 2.�˳�ϵͳ\n");
    scanf("%d",&a);
    while (a<1||a>2)
    {
        printf("\n*�������� ����������*\n");
        scanf("%d",&a);
    }
    if (a==1)
    {
        system("cls");
        chengjiguanli();
    }
    if (a==2)
    {
        printf("\n*�˳�ϵͳ*\n");
        exit(0);
    }
}


