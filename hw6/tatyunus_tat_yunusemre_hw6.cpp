#include <iostream>
#include "date.h"
using namespace std;
#include <fstream>
#include <vector>
#include <string>
#include<sstream>
struct student 
{
	int idnumber;
	vector <int> x;

};

struct finals
{
	int k1;
	string ders,saat;
	Date d;
};

void Swap (finals & s1, finals & s2)
{
	finals temp;
	temp = s1;
	s1 = s2;
	s2 = temp;
}

void SelectSort( vector<finals> & a, int size)
{
	int j,k,min;

	for(j=0 ; j< size-1; j++)
	{	
		min = j;

		for(k=j+1; k<size; k++)
		{
			if (a[k].d < a[min].d) 
			{
				min = k;
			}
			else if( a[k].d == a[min].d)
			{
				if(a[k].saat < a[min].saat)
					min = k;
			}
		}

		Swap(a[min],a[j]);
	}    

}


void processingcourse (ifstream &n, vector<student> & vecs)
{
	int number,courseid;
	string line;

	while(getline(n,line))
	{
		student s;
		istringstream input(line);
		input>>number;	
		s.idnumber=number;

		while(input>>courseid)
		{
			s.x.push_back(courseid);
		}

		vecs.push_back(s);

	}
}

void processingfile(ifstream &n, vector<finals> & vecf)
{
	int k1;
	string ders,tarih,saat;
	int month,day,year;
	while(!n.eof())
	{
		n>>k1>>ders>>tarih>>saat;
		int x=tarih.find(".");
		int day=stoi(tarih.substr(0,x));
		int y=tarih.find(".",x+1);
		int month=stoi(tarih.substr(x+1,y-x-1));
		int year=stoi(tarih.substr(y+1,4));
		Date mydate(month,day,year);
		finals f;
		f.d=mydate;
		f.k1=k1;
		f.ders=ders;
		f.saat=saat;
		vecf.push_back(f);
	}
}

int main()
{
	vector<finals> Stufinal;
	vector<finals> vecf;
	vector<student> vecs;
	string filecourse,filefinal;
	int studentid;
	cout<<"Please enter filename for the courses list: ";
	cin>>filecourse;
	ifstream infile,filefinali;
	infile.open(filecourse.c_str());

	while(infile.fail())
	{
		cout<<"Program cannot open "<<filecourse<<"."<<endl;
		cout<<"Please enter filename for the courses list: ";
		cin>>filecourse;
		infile.open(filecourse.c_str());

	}
	cout<<"Please enter filename for the finals list: ";
	cin>>filefinal;
	filefinali.open(filefinal.c_str());
	while(filefinali.fail())
	{
		cout<<"Program cannot open "<<filefinal<<"."<<endl;
		cout<<"Please enter filename for the finals list: ";
		cin>>filefinal;
		filefinali.open(filefinal.c_str());
	}
	processingfile(filefinali,vecf);
	processingcourse (infile,vecs); 
	
	cout<<"Please enter a student ID number: ";
	cin>>studentid;
	bool okID = false;
	for(int i=0; i<vecs.size();i++)
	{
		if(vecs[i].idnumber == studentid)
			okID = true;
	}
	while(!okID)
	{
		cout << "There is no such student!" << endl;
		cout<<"Please enter a student ID number: ";
		cin>>studentid;
		for(int i=0; i<vecs.size();i++)
		{
			if(vecs[i].idnumber == studentid)
				okID = true;
		}
	}

	int ahmet = 0;
	for(int i = 0; i< vecs.size();i++)
	{
		if (vecs[i].idnumber==studentid)
		{
			ahmet = i;
			for(int k=0;k<vecs[i].x.size();k++)
			{
				for(int t=0;t<vecf.size();t++)
				{
					if(vecs[i].x[k]==vecf[t].k1)
					{
						Stufinal.push_back(vecf[t]);
					}

				}

			}


		}


	}
	vector<finals> YESFinal;
	//SelectSort(Stufinal,Stufinal.size());
	for(int g=0;g<vecs[ahmet].x.size();g++)
	{
		bool flag=false;
		for(int i=0;i<Stufinal.size();i++)
		{
			if(vecs[ahmet].x[g] == Stufinal[i].k1)
			{
				YESFinal.push_back(Stufinal[i]);
			}
		}
	}
	SelectSort(YESFinal,YESFinal.size());
	cout<<"Here are the final exams for student number "<<studentid<<":"<<endl;
	for(int i=0;i<YESFinal.size();i++)
		cout<<YESFinal[i].k1 << "\t" << YESFinal[i].ders <<"\t"<<YESFinal[i].d<<"\t"<<YESFinal[i].saat<< endl;

	for(int i=0; i<vecs[ahmet].x.size();i++)
	{
		bool flag = true;
		for(int j=0; j<YESFinal.size();j++)
		{
			if(YESFinal[j].k1 == vecs[ahmet].x[i])
				flag = false;
		}
		if(flag)
		{
			cout << "There is no final exam for " <<vecs[ahmet].x[i]<<"."<< endl;
		}
	}

	
	return 0;
}