// Exercise1.cpp : 定义控制台应用程序的入口点。
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
#define FILE_ADDRESS "H://Algorithm/Exercise1/text.txt"
 
using namespace std;
 
typedef struct Group{
    string word;
    int frequence;
}Group, Type;     //用于存储词汇表, word表示单词, frequence表示该单词的频率

void readFile( string file );     //按行读取txt文本
void translation_to_Word(  Group verb1[] ,string text1[], int line1 );  //把text文本内容变为单个单词，并存储
void save( string strr, Group verb1[] );
bool com( int type, Type a, Type x );
void sort_by_alphabet( Group verb1[] , int numWords1 );     //按单词排序
void sort_by_frequency(  Group verb1[] , int numWords1 );  //按频率排序
void QuickSort(Type a[], int p, int r, int type); //快速排序
void Swap(Type a[], int i, int j);
bool cmp( int type, Type a, Type x );  //type=1 时按字母排序 ， type=3 时按词频排序
int  Partition(Type a[], int p, int r, int type);
int  RandomizedPartition(Type a[],int p,int r, int type);
int  Random(int p, int r);
 
Group verb[10000];   //10000表示很大的一个值，单词的个数不会超过这个值
int  numWords=0;   //该变量表示不同单词的数量
int  newWord=1;   //该单词用于标记一个单词是否收录进词汇表中
string  text[100];
int line=0;
string  word="";

 void readFile( string file )   //按行读取txt文本
{
    ifstream infile; 
    infile.open( file.data() );   //将文件流对象与文件连接起来 
    assert( infile.is_open() );   //若失败,则输出错误消息,并终止程序运行 
 
    while( getline(infile,text[line]) )
    {
		line++;
    }
    infile.close();             //关闭文件输入流 
}
 
void translation_to_Word( Group verb1[], string text1[], int line1 )   //把text文本内容变为单个单词，并存储
{
	string word1 = "";
	for( int i=0; i<line1; i++ )
	{
		for(int k=0;k<text1[i].size()+1;k++)
		{
			if(((text1[i][k]>='a')&&( text1[i][k]<='z'))||((text1[i][k]>='A')&&(text1[i][k]<='Z')))
			{
				word1 += text1[i][k]; 
			}
			if(((text1[i][k]<'A')||(text1[i][k]>'Z'))&&((text1[i][k]<'a')||(text1[i][k]>'z')))
			{
				if(word1 != "")
				{
					save( word1,verb1 );
					word1 = ""; 
				}
			}
 
		}
	}
}
 
 int main()
{
	int i;
 
	readFile( FILE_ADDRESS );  //按行读取txt文本
 
	translation_to_Word( verb, text, line );
 
	int selection;
	do
	{
		printf(" ----------------------------------------------------------\n");
		printf("|                     ***MENU***                           |\n");
		printf("|                 1.Read the text                          |\n");
		printf("|                 2.Sort by alphabet                       |\n");
		printf("|                 3.Sort by frequency                      |\n");
		printf("|                 0.EXIT                                   |\n");
		printf(" ----------------------------------------------------------\n");
		printf(" Please enter your selection:");
		scanf( "%d", &selection );
		switch( selection )
		{
		case 0:
			exit(0);
			break;

		case 1:
			system("cls");
			printf("\n\n");
			printf("-------------------------------------------------------------------------------\n");
			printf("1.Read the text:\n\n" );
			for( i=0;i<line;i++)
			{
				cout<< text[i] << endl;
			}
			printf("-------------------------------------------------------------------------------\n\n");
			continue;

		case 2:
			system("cls");
			printf("2.Sort by alphabet:\n" );
			printf("==========================\n");
			printf(" WORD\t    FREQUENCIES\n");
			printf("--------------------------\n");
			sort_by_alphabet( verb, numWords );
			cout.setf( ios::left );
			for( i=0;i<numWords;i++ )
			{
				cout<<" "<<setw(16)<< verb[i].word<<setw(5)<<verb[i].frequence  <<endl;	
			}
			printf("---------FINISHED---------\n");
			printf("==========================\n\n\n");
			continue;

		case 3:
			system("cls");
			printf("3.Sort by frequency:\n" );
			printf("==========================\n");
			printf(" WORD\t    FREQUENCIES\n");
			printf("--------------------------\n");
			sort_by_frequency( verb, numWords );
			cout.setf( ios::left );
			for( i=0;i<numWords;i++ )
			{
				cout<<" "<<setw(16)<< verb[i].word<<setw(5)<<verb[i].frequence  <<endl;	
			}
			printf("---------FINISHED---------\n");
			printf("==========================\n\n\n");
			continue;

		default :
			printf("\n---------------------------------------\n");
			printf("****WARNING:PLEASE TRY IT AGAIN!!!!****\n");
			printf("---------------------------------------\n\n");
			continue;
		}
	}
	while (selection = 1);
	return 0;
}

void save( string strr, Group verb1[] )
{
	int newWord1 = 1;
	string str = strr;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	for(int i=0;i< numWords;i++)
	{
		if(str==verb1[i].word)   
		{
			verb1[i].frequence++;
			newWord1 = 0;    
		}
	}
	if(newWord1==1)  
	{
		verb1[numWords].word = str;  
		verb1[numWords].frequence = 1;  
		numWords++;
	}
}
 
 
void sort_by_alphabet( Group verb1[] , int numWords1 )
{
	QuickSort(  verb1, 0, numWords1-1, 1);
}
 
 
void sort_by_frequency(  Group verb1[] , int numWords1 )
{
	QuickSort(  verb1, 0, numWords1-1, 3);
}
 
 
bool cmp( int type, Type a, Type x )    //type=1 时按字母排序 ， type=3 时按词频排序
{
	if( type==1 )
	{
		const char *str1 = a.word.data();
		const char *str2 = x.word.data();
		if( strcmp( str1,str2 )<0 )
			return true;
		else
			return false;
	}else if( type==2 )
	{
		const char *str1 = a.word.data();
		const char *str2 = x.word.data();
		if( strcmp( str1,str2 )>0 )
			return true;
		else
			return false;
	}else if( type==3 )
	{
		if( a.frequence > x.frequence )
			return true;
		else
			return false;
	}else if( type==4 )
	{
		if( a.frequence < x.frequence )
			return true;
		else
			return false;
	}else
		return false;
}
 
 
void QuickSort(Type a[], int p, int r, int type)
{
	if (p<r)
	{
		int q = RandomizedPartition(a,p,r,type);
		QuickSort(a,p,q-1,type); 
		QuickSort(a,q+1,r,type); 
    }
}
 
int Partition(Type a[], int p, int r, int type)
{       
	int i = p, j = r + 1; 
    Type x = a[p];
 
    while (true) {
		while ( cmp( type, a[++i], x ) && i<r );
		while ( cmp( type+1, a[--j], x ) );
        if (i >= j) break; 
        Swap(a,i,j);
    }
    a[p] = a[j];
    a[j] = x;
    return j;
}
 
int RandomizedPartition(Type a[],int p,int r, int type)
{	
	int i = Random(p,r);
	Swap(a,i,p);
	return Partition(a, p, r, type);
}
 
void Swap(Type a[], int i, int j)
{
	Type temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
 
int Random(int p, int r)
{
	return rand()%(r-p)+p;
}


 
 

