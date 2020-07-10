#include<iostream>
#include <string>
using namespace std;
//calculation met values for each exercise and their speed values .
double calculateMET(double speed,string exercise)
{
	if(exercise =="Walking")
	{
		if(speed>= 4 && speed < 6.5)
		{
			return 4;
		}
		else if(speed>=6.5)
		{
			return 6.5;
		}
	}
	else if (exercise =="Running")
	{
		if(speed>= 4 && speed < 11)
		{
			return 9;
		}
		else if(speed>=11)
		{
			return 12.5;
		}
	}
	else if (exercise =="Cycling")
	{
		if(speed>= 4 && speed < 20)
		{
			return 6.0;
		}
		else if(speed>= 20 && speed < 25)
		{
			return 8.0;
		}
		else if (speed>=25)
		{
			return 10.5;
		}
	}
}
//displaying results walk calorie runcalorie cyclecalorie and finding needs for finding complement value
void displayResults(double difference,double total,double weight,double walkMET,double runMET,double cyclingMET,double walkcalorie,double runCalorie,double cycleCalorie)
{
	cout<<"From walking, you burned "<<walkcalorie<<" calories."<<endl;
	cout<<"From running, you burned "<<runCalorie<<" calories."<<endl;
	cout<<"From cycling, you burned "<<cycleCalorie<<" calories."<<endl;
	cout<<"You burned "<<total<<" calories."<<endl;
	if(difference==0)
	{
		cout<<"Congratulations! You have reached your goal!"<<endl<<endl;
		}	
	else if(difference<0)
	{
		cout<<"You have surpassed your goal! You can eat something worth "<<-difference<<" calories :)"<<endl;
	}
	else
	{
		cout<<"You did not reach your goal by "<<difference<<" calories."<<endl;
		cout<<"You need to walk "<<(difference*60.0)/(weight*walkMET)<<" minutes more to reach your goal or,"<<endl;
		cout<<"You need to run "<<(difference*60.0)/(weight*runMET)<<" minutes more to reach your goal or,"<<endl;
		cout<<"You need to do cycling "<<(difference*60.0)/(weight*cyclingMET)<<" minutes more to reach your goal."<<endl<<endl;	
			
	}
}
//computing results with using met values and determining calories.
void computeResults(double minwalk,double minrun,double mincycling,double speedWalk,double speedRun,double speedCycling,double weight,double week)	
{

	double met1=calculateMET(speedWalk,"Walking");
	double met2=calculateMET(speedRun,"Running");
	double met3=calculateMET(speedCycling,"Cycling");
	
	double walkcalorie =weight*minwalk/60.0*met1;
	double runcalorie =weight*minrun/60.0*met2;
	double cycleCalorie=weight*mincycling/60.0*met3;
	double total=walkcalorie+runcalorie+cycleCalorie;
	double difference=week-total;
	displayResults(difference,total,weight,met1,met2,met3,walkcalorie,runcalorie,cycleCalorie);
	
}

//using bool false/true determining values are true or not
bool inputcheck(double speed,double speed1,double speed2,double weight,double min,double min1,double min2)
{
	bool flag=false;
	if ((speed >= 4 && speed <= 30) && (speed2 >= 4 && speed2 <= 30) && (speed1 >= 4 && speed1 <= 30))
	// if (30>=speed>=4 && 30>=speed1>=4 && 30>=speed2>=4 )
	{
		if(weight>=30)
		{
			// if(2000>=min>=0 && 2000>=min1>=0 && 2000>=min2>=0)
			if ( (min >= 0 && min <= 2000) && (min1 >= 0 && min1 <= 2000) && (min2 >= 0 && min2 <= 2000) )
			{
				flag=true;
			}
			else
			{
				cout<<"Minute out of range!"<<endl;
				flag=false;
			}
		}
		else
		{
			cout<<"Weight out of range!"<<endl;
			flag =false;
		}
	
	}
	else
	{
		cout<<"Speed out of range!"<<endl<<endl;
		flag=false;
	}
	return flag;
	
}
//get input include all the phase of functions and determining values .
void getInput(string username)
{
	double min1,min2,min3;
	double weight;
	double sp1,sp2,sp3;
	double week;
	cout<<"Welcome "<<username<<", please enter your weight(kg): ";
	cin>>weight;
	cout<<username<<", please enter speed(km/h) and minutes spent in a week for the activities below.";
	cout<<endl<<"Walking: ";
	cin>>sp1>>min1;
	cout<<"Running: ";
	cin>>sp2>>min2;
	cout<<"Cycling: ";
	cin>>sp3>>min3;
	cout<<username<<", please enter your weekly calorie burn goal: ";
	cin>>week;

	bool result_check;
	result_check = inputcheck(sp1,sp2,sp3,weight,min1,min2,min3);

	if (result_check)
		computeResults(min1,min2, min3, sp1, sp2, sp3, weight, week);
	
	
	
	
		
	
	
}

//main funciton is our function which shows all the phase of this program

int main()
{
	string username, username2;
	cout<<"Please enter your name: ";
	cin>>username;
	getInput(username);

	cout<<"Please enter your name: ";
	cin>>username2;
	getInput(username2);

	return 0;
	
}
	
	
	
	



