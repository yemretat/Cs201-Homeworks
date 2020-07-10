#include<iostream>
using namespace std;
// determining the  string checker 
bool stringchecker (string s)
{
	//it is composed of 3 parts one of them is length,iteration and allowing 
	string allowed = "RGBPYM";
	if(!(s.length()==4))
		return false;
	for(int i=0;i<4;++i)
	{
		if(6<allowed.find(s[i]))
		{
			return false;
		}
	}
	for(int i =0;i<6;++i)
	{
		char c = allowed.at(i);
		for(int k=0;k<4;++k)
		{
			if(s.find(c) != s.rfind(c))
				return false;
		}
	}
	
	return true;
}

void emre(string s1, string s2, int &i11, int &i22)
{

	//selecting the secret and determining situations
	string secret,guess;
	cout<<endl<<s1<<", it is your turn to select the secret!"<<endl;
	cout<<"Valid colors: R - Red, G - Green, B - Blue, P - Purple, Y - Yellow, M - Magenta"<<endl;
	cout<<s1<<", please enter your secret: ";
	cin>>secret;
	while(!stringchecker(secret))
	{
		cout<<"Invalid secret!"<<endl;
		cout<<s1<<", please enter your secret: ";
		cin>>secret;
		
	}
	cout<<endl;
//	cout<<endl;
	int ntrail=0;
	
	bool flag=false;
	while(flag==false &&  ntrail <6) //DÝKKAT ET 
	{
	
	int r=0;
	int z=0;
	
	//with using stringcheceker applying inputs which taken from users

	cout<<s2<<", please enter your guess: ";
	cin>>guess;
	while(!stringchecker(guess))
	{
		cout<<"Invalid guess!"<<endl;
		cout<<s2<<", please enter your guess: ";
		cin>>guess;
	}
	++ntrail;

	for(int i=0;i<4;++i)
	{
		if(secret.at(i)==guess.at(i))
		{
			r+=1;
		}
		else 
		{
			for(int k=0;k<4;++k)
			{
				if(secret.at(i)==guess.at(k))
			 	{	
			 		if (i!=k)
			 		{
			 			z+=1;
					}
				 }
			}
		}
	}
	
	//DETERMINING FLAG
	if(r == 4)
	{
		flag=true;
		i11++;
		cout<<s2<<", you won this run!"<<endl;
	}
else
{
	// R AND W
	for(int p=0;p<r;++p)
	{
		cout<<"R";			
	 }			 
	 
	for(int f=0;f<z;++f)
	{
		cout<<"W";
	}
	cout<<endl;
}

	if(r != 4)
	{
		i22++;
	}

	

}
	if(flag==false)
	{
		cout <<s2<<", you're out of chances, you lost this run!" << endl;
		i22++;
	}
	


}
//ý write a main function to implementing my other functions
int main()
{
	string i1,i2;
	string kisi;
	int r=0,z=0;
	int n1;
	string secret,guess;
	cout<<"Please enter the names of the players: ";
	cin>>i1>>i2;
	cout<<"Welcome "<<i1<<" and "<<i2;
	cout<<endl;
	bool flag;
	int ntrail;
	// do while for determining numbers valid or not
	do
	{
		cout<<endl<<"Please enter the number of runs: ";
		cin>>n1;
		if(n1%2!=0 || n1<=0)
		{		 
			cout << "Invalid number of runs!";
		}
	}while(n1%2!=0 || n1<=0);
	 
	// cout << endl;
	int i11=0,i22=0;
	//determining the tie or winer the game
	for (int i =1;i<=n1/2;i++)
	{
		emre(i1,i2, i11, i22);
		emre(i2,i1, i22,i11);	
	}
	cout<<endl<<"The game has ended!"<<endl;
	
	cout<<i1<<": "<<i22<<" - "<<i2<<": "<<i11<<endl;
	cout<<endl;
	if(i11==i22)
	{
		cout<<i1<<" and "<<i2<<", there is a tie!"<<endl;
	}
	else if(i11>i22)
	{
		cout<<"Congrats "<<i2<<", you have won the game!"<<endl;
	}
	else
	{
		cout <<"Congrats "<<i1<<", you have won the game!"<<endl;
	}
		return 0;

}
