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
    string sentence;	//记录句子
    int num;			//记录句子单词个数
}Sentence; 
typedef struct sameSentence{
    string libsent;     //记录对到最长公共子序列的lib的句子
	string textsent;    //记录test中对比的句子
    int textnum;		//记录test中对比的句子的单词的个数
	int samenum;	    //最长公共子序列的单词个数
}sameSentence;

sameSentence saveall[MAX_SIZE];   //存储所有对比好的信息
Sentence libSentence[MAX_SIZE];     //按句存储lib文件的内容
int sameWords[MAX_SIZE][MAX_SIZE];  
float Score[MAX_SIZE][MAX_SIZE];      //记录最长公共子序列的得分。相同+1，不同-1，空格替换-0.5 
string str1[MAX_SIZE],str2[MAX_SIZE];   //存储每个句子分割出来的单词    
string str_out1[MAX_SIZE],str_out2[MAX_SIZE];
int libline = 0;     //lib文件的句子的个数
int testline = 0;    //test文件的句子的个数

void Delay(int time);
void lib_to_sentence( string file);  // 把lib里的内容按句子存储
void text_to_sentence( string file );   // 读取text文本的内容并使用动态规划进行查重
float max_of_two( float a, float b );
float max_of_three( float a, float b, float c );


int main()
{
	system("color f0");
		printf(" ----------------------------------------------------------\n");
		printf("|                                                          |\n");
		printf("|                   ***文献查重 v1.0***                    |\n");
		printf("|                                                          |\n");
		printf(" ----------------------------------------------------------\n");
		printf("                   读取中");
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
		printf("第%d句对比:\n\n",j+1);
		printf("lib中的句子：\n");
		cout<<saveall[j].libsent<<endl;
		printf("\n"); 
		printf("text中的句子：\n");
		cout<<saveall[j].textsent<<endl;
		printf("\n\n");
		printf("lib中的单词：\n");
		string t,s;
		int n=0;
		istringstream is1(saveall[j].libsent);   //存储把lib的句子分割成单词
		while(is1>>t){
			cout<<"“"<<t<<"”\t"; 
		}
		printf("\n\n");
		printf("text中的单词：\n");
		istringstream is2(saveall[j].textsent);   //存储把test的句子分割成单词
		while(is2>>s){
			cout<<"“"<<s<<"”\t"; 
		}
		printf("\n"); 
		printf("得分：%d\t单词个数：%d\n",saveall[j].samenum,saveall[j].textnum);
		i=(float)saveall[j].samenum/(float)saveall[j].textnum;
		printf("这句话的相似度：%.1f%%\n",i*100);
		printf("-------------------------------------------------------------------------------\n\n\n");
		all_number_of_words += saveall[j].textnum;
		if(i>=0.400000)	res_temp = res_temp + i*saveall[j].textnum;
	}
	result=res_temp/(float)all_number_of_words;
	printf("========================RESULT=========================\n");
	printf("*******************************************************\n");
	printf("* 整个文本的相似度：%.1f%%\t\t",result*100);
	if (i>=0.400000)	printf(" 认为是重复的 *\n");
		else	printf("不认为是重复的 *\n");
	printf("*******************************************************\n");
	return 0;
}

void Delay(int time)//time*1000为秒数 
{ 
	clock_t now= clock(); 
	while( clock() - now < time); 
} 

void lib_to_sentence( string file )   // 把lib里的内容按句子存储
{
    ifstream infile; 
    infile.open( file.data() );   //将文件流对象与文件连接起来 
    assert( infile.is_open() );   //若失败,则输出错误消息,并终止程序运行 
 
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
			libSentence[libline] = temp;     //按每句子存储lib的内容到libSentence[]中
			num1 = 0;
			tempSentence = "";
			libline++;      //lib文件的句子的个数
		}else    //匹配到空格
		{
			if( tempSentence=="" )
			{
				continue;
			}
			else if(tempSentence[tempSentence.size()==1?1:tempSentence.size()-1] != ' ')  //匹配到空格，当前句末不为空格，添加空格
			{
				tempSentence += " ";
				num1 += 1;    //单词个数加1
			}
		}
    }
    infile.close();             //关闭文件输入流 
}

void text_to_sentence( string file )    // 读取text文本的内容并使用动态规划进行查重
{
    ifstream infile; 
    infile.open( file.data() );   //将文件流对象与文件连接起来 
    assert( infile.is_open() );   //若失败,则输出错误消息,并终止程序运行 
 
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
 
		}else if(( currentChar =='.' )||( currentChar =='?' )||( currentChar =='!' ))   //完成一个句子的读取，进行动态规划匹配查重
		{
			transform(tempSentence.begin(), tempSentence.end(), tempSentence.begin(), ::tolower);
			temp.num = num1+1;            // 把当前读取到的test句子的单词个数存下
			temp.sentence = tempSentence;  // 把当前读取到的test句子存下 
			num1 = 0;
			tempSentence = "";
 
			for(int i=0;i<libline-1;i++ )   //分别与lib中的每一句进行对比
			{
				string t;
				int n = 0;
				int k,j;
 
				for(istringstream is(temp.sentence); is>>t;) {   //存储把test的句子分割出来的单词
					str1[n++] =t;
				}
 
				n = 0;
				for(istringstream is1(libSentence[i].sentence); is1>>t;) {   //存储把lib的句子分割出来的单词
					str2[n++] =t;
				}
 
				for( k=0;k<temp.num;k++)   //test当前句子的个数
				{
					for( j=0;j<libSentence[i].num;j++)  //与lib文件的句子的单词分别进行对比
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
			testline++;   //test文件的句子的个数
 
		}else  //匹配到空格
		{
			if( tempSentence=="" )
			{
				continue;
			}
			else if(tempSentence[tempSentence.size()==1?1:tempSentence.size()-1] != ' ') //匹配到空格，当前句末不为空格，添加空格
			{
				tempSentence += " ";
				num1 += 1;
			}
		}
    }
    infile.close();             //关闭文件输入流 
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

