#include<iostream>
using namespace std;
int main()
{
	//determining unknown values
	string name;
	double weight;
	double met,met1,met2,met3;
	int time,time1,time2,time3;
	double totalcal;
	//getting name and weight from user
	cout<<"Please enter your name: ";
	cin>>name;
	cout<<name<<", please enter your weight(kg): ";
	cin>>weight;
	cout<<name<<", please enter MET values and minutes spent in a week for the activities below."<<endl;
	//getting walking running cycling swimming met and time number
	cout<<"Walking: ";
	cin>>met>>time;
	cout<<"Running: ";
	cin>>met1>>time1;
	cout<<"Cycling: ";
	cin>>met2>>time2;
	cout<<"Swimming: ";
	cin>>met3>>time3;
	//getting total calorie which is burned by user
	cout<<name<<", please enter how many calories you have gained: ";
	cin>>totalcal;
	cout<<endl;
	//calculation formula of burned calorie is weight * time/60*met and implementing all of the type of sports
	cout<<"Welcome "<<name<<"!"<<endl;
cout<<"In a week, you burned "<<weight*time/60*met<<" calories from walking, "<<weight*time1/60*met1<<" calories from running, "<<weight*time2/60*met2<<" calories from cycling, "<<weight*time3/60*met3<<" calories from swimming."<<endl;
cout<<"Total amount of calories you burned is: "<<(weight*time/60*met)+(weight*time1/60*met1)+(weight*time2/60*met2)+(weight*time3/60*met3)<<endl;
cout<<"Difference between calories burned and calories gained is: "<<(weight*time/60*met)+(weight*time1/60*met1)+(weight*time2/60*met2)+(weight*time3/60*met3)-totalcal<<endl;
	return 0;
		

	
	
}
