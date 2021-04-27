#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <conio.h>
#define CLEAR system("clear")
#define DELAY sleep(1)
#define PAUSE system("pause")

using namespace std;

/*
*
*	Created by Parbhat Sharma
*
*/

class TIMER
{
  protected:
    int hrs,min,sec;
    char ch;
  public:
	void input();
	void disp();
	void update();
}t;

void TIMER::input()
{
	cout<<"enter for hrs\t:";
	cin>>hrs;
	cout<<"enter for min\t:";
	cin>>min;
	cout<<"enter for sec\t:";
	cin>>sec;
	CLEAR;
}

void TIMER::disp()
{
	cout<<"\t\t\tTIMER"<<endl;
	cout<<"\t\t\t\v"<<hrs<<" : "<<min<<" : "<<sec<<endl;
	cout<<"\v\v\v\vpress \'q\' to quit"<<endl;
	cout<<"press \'p\' to pause"<<endl;
}

void TIMER::update()
{
	while(true)
	{
		disp();
		DELAY;
		CLEAR;
		sec--;
		if(sec==-1)
		{
			sec=59;
			if(min!=0)
			{
				min--;
			}
		}
		if(min==0)
		{
			if(hrs!=0)
			{
				min=59;
				hrs--;
			}
		}
		if(kbhit())
		{
			ch=getch();
			if(ch=='q')
			{
				break;
			}
			if(ch=='p')
			{
				PAUSE;
			}
		}
		if(hrs==0 && min==0 && sec==0)
		{
			break;
		}
	}
}

int main()
{
	t.input();
	t.update();
	return 0;
}