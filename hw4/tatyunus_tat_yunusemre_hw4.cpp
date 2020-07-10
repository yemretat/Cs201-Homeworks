
#include"randgen.h"
#include"strutils.h"
#include "MiniFW_Modified.h"
#include "Robots_Modified.h"

void ThingPutter()//Randomly planting points
{
	RandGen randgen;
	int i=1;
	while(i<=20)
	{
		int rand1=randgen.RandInt(1,4),a;//between 1-4 determining point
		int randx=randgen.RandInt(12);
		int randy=randgen.RandInt(12);
		a = GetCellCount(randx,randy);//to planting points on 20 empty place looking empthy placeses
		if(a==0)
		{
			PutThings(randx,randy,rand1);
			i++;
		}

	}
}
void Robotmover(Robot &robot)//creating a robot mover 
{
	if(IsPressed(keyRightArrow))//for right
	{
		robot.Turnface(east);
		robot.Move();
		robot.pickallthethings();
	}
	if(IsPressed(keyLeftArrow))//for left
	{
		robot.Turnface(west);
		robot.Move();
		robot.pickallthethings();
	}
	if(IsPressed(keyUpArrow))//for up
	{
		robot.Turnface(north);
		robot.Move();
		robot.pickallthethings();
	}
	if(IsPressed(keyDownArrow))//for down
	{
		robot.Turnface(south);
		robot.Move();
		robot.pickallthethings();
	}
	if(IsPressed(keySpace))//if pressed space 
	{
		robot.puttrap();
	}
}

void monmover(Robot & robot)//monster moving with Turnrandom function
{
	robot.TurnRandom();
	robot.Move();
}
bool Monsterkiller(Robot & robot)//Killing monster with trap function
{
	if(GetCellCount(robot.getxcoord(),robot.getycoord())==5)
	{
		robot.pickallthethings();
	}
	if(robot.getbagcount()==5)
	{
		robot.kill();	
		return true;
	}
	else
	{
		return false;
	}
}

void monsterresurrector(Robot & robot)//some conditions are provided than monsterkilling 
{
	if(Monsterkiller(robot)==false && robot.isalive()==false)
	{
		robot.ressurect();
	}


}
//Monster who was killed surrection again
void robotresurrector(Robot & robot,int &lives)
{
	if(robot.isalive()==false)
	{
		if (lives ==3)
		{
			robot.ressurect();
			lives--;
			ShowMessage("You have "+itoa(lives)+" lives left!");
		}
		else if(lives==2)
		{
			robot.ressurect();
			lives--;
			ShowMessage("You have "+itoa(lives)+" life left!");
		}
		else
		{
			ShowMessage("You have no lives left");
		}
	}


}

int main()
{
	Robot r1(6,6),m1(6,2),m2(2,6),m3(10,6),m4(6,10);//creating new robots
	r1.SetColor(green);m1.SetColor(red);m2.SetColor(red);m3.SetColor(red);m4.SetColor(red);

	ThingPutter();
	int live=3;
	while(r1.isalive()&&(!Monsterkiller(m1)||!Monsterkiller(m2)||!Monsterkiller(m3)||!Monsterkiller(m4)))//a loop some conditions to game 
	{
		Robotmover(r1);
		monmover(m1);
		monmover(m2);
		monmover(m3);
		monmover(m4);
		Monsterkiller(m1);
		Monsterkiller(m2);
		Monsterkiller(m3);
		Monsterkiller(m4);
		monsterresurrector(m1);
		monsterresurrector(m2);
		monsterresurrector(m3);
		monsterresurrector(m4);
		robotresurrector(r1,live);

	} 
	if(r1.isalive())
	{
		ShowMessage("Congratulations,you win!");//announcemenets
	}
	else
	{
		ShowMessage("You run out of lives...You lost the Game!");//announcements
	
	}
	return 0;
}