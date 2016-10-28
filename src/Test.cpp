//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <map>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <algorithm>

using namespace std;
bool GetParam(int argc, char* argv[], std::string &strParm,std::string &strParm2);
void BrowerDir( std::vector<std::string>& vecFiles, const std::string& strDir );
string Upper(string& str);

void RemoveLeftZero( std::string& strData );

typedef struct
{
	int a;
	string b;
}S_A;

map<int,S_A*> mapTest;
void test()
{
	S_A *p = new S_A();
	p->a = 11;
	p->b = "11";
	mapTest[1]= p;

	for(map<int,S_A*>::iterator it = mapTest.begin(); it != mapTest.end(); it++)
		{
			cout <<"1:"<<  it->first << endl;

			cout << "2:" << it->second->a << "||||||" << it->second->b << endl;
		}

	S_A sa;
	sa.a = 3;
	sa.b = "123";
	map<int,S_A*>::iterator it = mapTest.find(1);
	if (it != mapTest.end())
	{
		*(it->second) = sa;
	}

	p->a = 112;
	p->b = "1122222222";

	for(map<int,S_A*>::iterator it = mapTest.begin(); it != mapTest.end(); it++)
	{
		cout <<"1:"<<  it->first << endl;

		cout << "2:" << it->second->a << "||||||" << it->second->b << endl;
	}
};

void Print(int i)
{
	cout << "aa:"<< i << endl;
}

void Print(void* pVoid)
{
	S_A* p=(S_A*)pVoid;
	printf("S_A Info a:%d,b:%s",p->a,p->b.c_str());
}

int main( int argc, char* argv[] )
{
//	std::string cfgPath;
//	std::string strTableName;
//	if( !GetParam(argc, argv, cfgPath,strTableName) )
//	{
//		return 0;
//	}
//
//	std::vector<std::string> vecfile;
//	BrowerDir(vecfile,cfgPath);
//
//	for(int i = 0; i <(int)vecfile.size(); i++)
//	{
//		cout <<"file" << i << ":" << vecfile[i].c_str() << endl;
//	}

//	cfgPath = "asf12";
//
//	string sub = cfgPath.substr(0,8);
//
//	printf("sub:%s \n",sub.c_str());
//
//	if(cfgPath == "asf1232KKdsf")
//		printf("===\n");
//	printf("sf:%s \n",Upper(cfgPath).c_str());
//	printf("data:%s \n",cfgPath.c_str());
//
//	string str1= "123";
//	cout << str1.compare("1234") << endl;
//
//	string str2= "123";
//		cout << str2.compare("1203") << endl;
//
//		string str3= "123";
//			cout << str3.compare("12") << endl;
//			string str4= "123";
//						cout << str4.compare("123") << endl;
//
//	string str5 = str1+str2+str3;
//	cout << str5 << endl;

//	string strData = "00012323";
//	RemoveLeftZero(strData);
//
//	cout << strData << endl;
//
//	string strVal="1235";
//	if(strData.find(strVal) == std::string::npos)
//	{
//	    cout << "can not find strval" <<endl;
//	}
//	else
//	{
//		cout << "can find strval" <<endl;
//	}


//	test();
//
//	for(map<int,S_A*>::iterator it = mapTest.begin(); it != mapTest.end(); it++)
//		{
//		cout << "*****************" << endl;
//			cout <<"1:"<<  it->first << endl;
//
//			cout << "2:" << it->second->a << "||||||" << it->second->b << endl;
//		}

//	S_A *p = NULL;
//	Print(p);
//	string str="123456789";
//	string substr=str.substr(0,3);
//	cout << str <<endl;
//	cout << substr << endl;

	string strempty="111";
	string strtest="127.0.0.1";
	if(strempty.empty())
	{
		strempty = strtest + "&";
		cout << strempty << endl;
	}
	else
	{
		cout << "is not empty!" << endl;
	}

	return 0;
}


string Upper(string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), towupper);
	return str;
}

/*******************************************************************************
  Function:  getParam
  Description: 获取传入参数
  Input:    none
  Output:   cfgPath：参数
  Return:   none
  Others:   none
*******************************************************************************/
bool GetParam(int argc, char* argv[], std::string &strParm,std::string &strParm2)
{
	bool falg = true;
	int inch;
	strParm = "";
	strParm2 = "";

	std::string help;
	help = "\n";
	help += "  Help: ./test -<i,I> 参数\n";
	help += "  For example: ./test -i ../config/ \n";

	while(( inch = getopt( argc, argv, "i:I:h:H:t:T")) != EOF )
	{
		switch(inch)
		{
		case 'i':
		case 'I':
		{
			strParm = optarg;
			break;
		}
		case 't':
		case 'T':
		{
			strParm2 = optarg;
			break;
		}
		case 'h':
		case 'H':
		{
			std::cout << help <<std::endl;
			falg = false;
			break;
		}
		default:
			std::cout << help <<std::endl;
			falg = false;
			break;
		}
	}

	return falg;
}


void BrowerDir( std::vector<std::string>& vecFiles, const std::string& strDir )
{
	vecFiles.clear();
	dirent* pEnt = NULL;
	DIR *pDir;
	struct stat statFile;
	cout << "file dir" << strDir.c_str() << endl;
	if((pDir = opendir( strDir.c_str())) == NULL){
		std::cout << "File does not exist!!! strDir:" <<strDir.c_str() << std::endl;
		return;
	}
	while ( NULL != ( pEnt = readdir( pDir )) )
	{
		if ( ( strcmp ( pEnt->d_name, "." ) == 0 ) || ( strcmp ( pEnt->d_name, ".." ) == 0 ) )
		{
			continue;
		}

		std::string fileName = strDir + pEnt->d_name;
		if( 0 == stat(fileName.c_str(), &statFile))
		{
			if(S_ISDIR(statFile.st_mode))
			continue;
		}


		vecFiles.push_back( strDir + pEnt->d_name );

	}
	closedir(pDir);
}


void RemoveLeftZero( std::string& strData )
{
	cout << strData << endl;
	while(strData[0]!='\0')
	{
		if(strData[0] == '0')
		{
			strData.erase(0,1);
			cout << strData << endl;
		}
		else
		{
			break;
		}
	}
}
