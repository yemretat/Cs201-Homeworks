#include <fstream>
#include "strutils.h"
#include <iostream>
#include "prompt.h"

void stringupperlower(string s);
string processinput(string location,string bussinesloc,string cityname );
void processBusiness(string filename1,string filename2,string locationn,string type)
{
	bool kontrol=false;
	string line,word1;
	ifstream inFile;

	inFile.open(filename1.c_str());

	while(getline(inFile,line))
	{
		int x=line.find("-");
		string word=line.substr(0,x);
		int y=line.find("-",x+1);
		word1=line.substr(x+1,y-x-1);
		int z=line.find("-",y+1);
		string word2=line.substr(y+1,z-y-1);
		string word3=line.substr(z+1,line.length());
		ToUpper(word);
		if(word==type)
		{
			kontrol=true;
			ToUpper(word1);
			string out = processinput(locationn,word1,filename2);
			if(out !="")
			{	
				cout<<word3<<" "<<word2<<" ";
				stringupperlower(word1);
				cout<<" "<<out<<endl;
			}
		}
		
	}
	if(kontrol==false)
	{
		cout<<"Nothing found!"<<endl;
	}
}

string processinput(string location,string bussinesloc,string filename )
{
	string dist="Unknown";
	string sifir="0";
	ifstream infile;
	infile.open(filename.c_str());
	string line,word1,word2,distance;
	ToUpper(location);
	ToUpper(bussinesloc);
	while(getline(infile,line))
	{
		int x=line.find("-");
		word1=line.substr(0,x);
		ToUpper(word1);
		int y=line.find("-",x+1);
		word2=line.substr(x+1,y-x-1);
		ToUpper(word2);
		distance=line.substr(y+1);
		if(word1==location && word2==bussinesloc)
		{
			dist =distance;

		}
		else if (word1==bussinesloc && word2==location)
		{
			dist= distance;

		}
		else if((word1==location &&word1==bussinesloc)||(word2==location&&word2==bussinesloc))
		{
			dist=sifir;
		}
		
	
		
	}
	return dist;
}
void stringupperlower(string s)
{
	s[0]=toupper(s[0]);
	for(int i=1;i<s.length();++i)
	{
		s[i]=tolower(s[i]);
	}

	cout<<s;
}
int main()
{
	string file=PromptlnString("Please enter a city name: ");
	ToUpper(file);
	while(file!="ANKARA" && file !="ISTANBUL")
	{
		cout<<"Invalid city name!" << endl << endl;
		file=PromptlnString("Please enter a city name: ");
		ToUpper(file);
	}

	string type=PromptlnString("What type of business are you looking for? ");
	string line;
	string word1;
	string locationn=PromptString("Please enter your location: ");
	ToUpper(locationn);
	ToUpper(type);
	string filename1="Ankara_Businesses.txt";
	string filename2="Ankara_Distances.txt";

	if(file=="ANKARA")
	{
		filename1="Ankara_Businesses.txt";
		filename2="Ankara_Distances.txt";
	}
	else if(file=="ISTANBUL")
	{
		filename1="Istanbul_Businesses.txt";
		filename2="Istanbul_Distances.txt";

	}
	processBusiness(filename1,filename2,locationn,type);

	return 0;

}