#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <math.h>
#include <iterator>
#include <cctype>
#include <ctime>

#define MAX_SIZE 1000
#define TEXT_FILE "H://Algorithm/Exercise2/text.txt"
#define LIB_FILE "H://Algorithm/Exercise2/lib.txt"

using namespace std;

typedef struct Sentence{
    string sentence;	//��¼����
    int num;			//��¼���ӵ��ʸ���
}Sentence; 
typedef struct sameSentence{
    string libsent;     //��¼�Ե�����������е�lib�ľ���
	string textsent;    //��¼test�жԱȵľ���
    int textnum;		//��¼test�жԱȵľ��ӵĵ��ʵĸ���
	int samenum;	    //����������еĵ��ʸ���
}sameSentence;

sameSentence saveall[MAX_SIZE];   //�洢���жԱȺõ���Ϣ
Sentence libSentence[MAX_SIZE];     //����洢lib�ļ�������
int sameWords[MAX_SIZE][MAX_SIZE];  
float Score[MAX_SIZE][MAX_SIZE];      //��¼����������еĵ÷֡���ͬ+1����ͬ-1���ո��滻-0.5 
string str1[MAX_SIZE],str2[MAX_SIZE];   //�洢ÿ�����ӷָ�����ĵ���    
string str_out1[MAX_SIZE],str_out2[MAX_SIZE];
int libline = 0;     //lib�ļ��ľ��ӵĸ���
int testline = 0;    //test�ļ��ľ��ӵĸ���

void Delay(int time);
void lib_to_sentence( string file);  // ��lib������ݰ����Ӵ洢
void text_to_sentence( string file );   // ��ȡtext�ı������ݲ�ʹ�ö�̬�滮���в���
float max_of_two( float a, float b );
float max_of_three( float a, float b, float c );


int main()
{
	system("color f0");
		printf(" ----------------------------------------------------------\n");
		printf("|                                                          |\n");
		printf("|                   ***���ײ��� v1.0***                    |\n");
		printf("|                                                          |\n");
		printf(" ----------------------------------------------------------\n");
		printf("                   ��ȡ��");
	int j;
	for(int i1=0;i1<=5;i1++){
		printf(">>");
		Delay(0.8*1000);
	}
	printf("\n") ;
	
	lib_to_sentence( LIB_FILE );
	text_to_sentence( TEXT_FILE );
	float result=0;
	float res_temp=0;
	float i=0;
	int all_number_of_words=0;
	for(int j=0; j<testline; j++ )
	{
		printf("-------------------------------------------------------------------------------\n");
		printf("��%d��Ա�:\n\n",j+1);
		printf("lib�еľ��ӣ�\n");
		cout<<saveall[j].libsent<<endl;
		printf("\n"); 
		printf("text�еľ��ӣ�\n");
		cout<<saveall[j].textsent<<endl;
		printf("\n\n");
		printf("lib�еĵ��ʣ�\n");
		string t,s;
		int n=0;
		istringstream is1(saveall[j].libsent);   //�洢��lib�ľ��ӷָ�ɵ���
		while(is1>>t){
			cout<<"��"<<t<<"��\t"; 
		}
		printf("\n\n");
		printf("text�еĵ��ʣ�\n");
		istringstream is2(saveall[j].textsent);   //�洢��test�ľ��ӷָ�ɵ���
		while(is2>>s){
			cout<<"��"<<s<<"��\t"; 
		}
		printf("\n"); 
		printf("�÷֣�%d\t���ʸ�����%d\n",saveall[j].samenum,saveall[j].textnum);
		i=(float)saveall[j].samenum/(float)saveall[j].textnum;
		printf("��仰�����ƶȣ�%.1f%%\n",i*100);
		printf("-------------------------------------------------------------------------------\n\n\n");
		all_number_of_words += saveall[j].textnum;
		if(i>=0.400000)	res_temp = res_temp + i*saveall[j].textnum;
	}
	result=res_temp/(float)all_number_of_words;
	printf("========================RESULT=========================\n");
	printf("*******************************************************\n");
	printf("* �����ı������ƶȣ�%.1f%%\t\t",result*100);
	if (i>=0.400000)	printf(" ��Ϊ���ظ��� *\n");
		else	printf("����Ϊ���ظ��� *\n");
	printf("*******************************************************\n");
	return 0;
}

void Delay(int time)//time*1000Ϊ���� 
{ 
	clock_t now= clock(); 
	while( clock() - now < time); 
} 

void lib_to_sentence( string file )   // ��lib������ݰ����Ӵ洢
{
    ifstream infile; 
    infile.open( file.data() );   //���ļ����������ļ��������� 
    assert( infile.is_open() );   //��ʧ��,�����������Ϣ,����ֹ�������� 
 
    char currentChar;
	string tempSentence="";
	Sentence temp;
	int num1 = 0;
 
    infile >> noskipws;
 
    while ( !infile.eof() )
    {
        infile>>currentChar;
 
		if((( currentChar >='a' )&&( currentChar <='z' ))||(( currentChar >='A' )&&( currentChar <='Z' )))
		{
			tempSentence += currentChar;
 
		}else if(( currentChar =='.' )||( currentChar =='?' )||( currentChar =='!' ))
		{
			transform(tempSentence.begin(), tempSentence.end(), tempSentence.begin(), ::tolower);
			temp.num = num1+1;
			temp.sentence = tempSentence;
			libSentence[libline] = temp;     //��ÿ���Ӵ洢lib�����ݵ�libSentence[]��
			num1 = 0;
			tempSentence = "";
			libline++;      //lib�ļ��ľ��ӵĸ���
		}else    //ƥ�䵽�ո�
		{
			if( tempSentence=="" )
			{
				continue;
			}
			else if(tempSentence[tempSentence.size()==1?1:tempSentence.size()-1] != ' ')  //ƥ�䵽�ո񣬵�ǰ��ĩ��Ϊ�ո���ӿո�
			{
				tempSentence += " ";
				num1 += 1;    //���ʸ�����1
			}
		}
    }
    infile.close();             //�ر��ļ������� 
}

void text_to_sentence( string file )    // ��ȡtext�ı������ݲ�ʹ�ö�̬�滮���в���
{
    ifstream infile; 
    infile.open( file.data() );   //���ļ����������ļ��������� 
    assert( infile.is_open() );   //��ʧ��,�����������Ϣ,����ֹ�������� 
 
    char currentChar;
	string tempSentence="";
	Sentence temp;
	int num1 = 0;
 
    infile >> noskipws;
 
    while ( !infile.eof() )
    {
        infile>>currentChar;
 
		if((( currentChar >='a' )&&( currentChar <='z' ))||(( currentChar >='A' )&&( currentChar <='Z' )))
		{
			tempSentence += currentChar;
 
		}else if(( currentChar =='.' )||( currentChar =='?' )||( currentChar =='!' ))   //���һ�����ӵĶ�ȡ�����ж�̬�滮ƥ�����
		{
			transform(tempSentence.begin(), tempSentence.end(), tempSentence.begin(), ::tolower);
			temp.num = num1+1;            // �ѵ�ǰ��ȡ����test���ӵĵ��ʸ�������
			temp.sentence = tempSentence;  // �ѵ�ǰ��ȡ����test���Ӵ��� 
			num1 = 0;
			tempSentence = "";
 
			for(int i=0;i<libline-1;i++ )   //�ֱ���lib�е�ÿһ����жԱ�
			{
				string t;
				int n = 0;
				int k,j;
 
				for(istringstream is(temp.sentence); is>>t;) {   //�洢��test�ľ��ӷָ�����ĵ���
					str1[n++] =t;
				}
 
				n = 0;
				for(istringstream is1(libSentence[i].sentence); is1>>t;) {   //�洢��lib�ľ��ӷָ�����ĵ���
					str2[n++] =t;
				}
 
				for( k=0;k<temp.num;k++)   //test��ǰ���ӵĸ���
				{
					for( j=0;j<libSentence[i].num;j++)  //��lib�ļ��ľ��ӵĵ��ʷֱ���жԱ�
					{
						if(str1[k]==str2[j])
							sameWords[k][j] = 1;
						else
							sameWords[k][j] = 0;
					}
				}
				
				for(k=0; k<temp.num; k++)
				{  
					Score[k][0] = max_of_two(Score[k-1][0]-0.5, sameWords[k][0]-0.5*(k-1) );
				} 
				for(k=0; k<libSentence[i].num; k++)
				{  
					Score[0][k] = max_of_two(Score[0][k-1]-0.5, sameWords[0][k]-0.5*(k-1) );
				}
				for(k=1;k<temp.num;k++)
				{
					for(j=1;j<libSentence[i].num;j++)
					{
						Score[k][j] = max_of_three( Score[k-1][j]-0.5, Score[k][j-1]-0.5, Score[k-1][j-1]+sameWords[k][j] );
					}
				}
 
				int sum = Score[temp.num-1][libSentence[i].num-1];
				
				if(saveall[testline].samenum < sum)
				{
					saveall[testline].libsent = libSentence[i].sentence;
					saveall[testline].samenum = sum;
					saveall[testline].textnum = temp.num;
					saveall[testline].textsent = temp.sentence;
				}
			}
			testline++;   //test�ļ��ľ��ӵĸ���
 
		}else  //ƥ�䵽�ո�
		{
			if( tempSentence=="" )
			{
				continue;
			}
			else if(tempSentence[tempSentence.size()==1?1:tempSentence.size()-1] != ' ') //ƥ�䵽�ո񣬵�ǰ��ĩ��Ϊ�ո���ӿո�
			{
				tempSentence += " ";
				num1 += 1;
			}
		}
    }
    infile.close();             //�ر��ļ������� 
}

float max_of_two( float a, float b )
{
	if( a > b )
		return a;
	else
		return b;
} 
 
 
float max_of_three( float a, float b, float c )
{
	float temp = a;
	
	if( temp < b )
		temp = b;
	if( temp < c )
		temp = c;
	
	return temp;
} 

