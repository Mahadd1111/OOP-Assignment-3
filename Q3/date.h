//Mahad Ahmed 20i0426
#include<iostream>
using namespace std;

class date{
int day;
int month;
int year;
string tasks[10];
int s;
public:
date(){ }
void setdate(int,int,int);
int getday();
int getmonth();
int getyear();
void setTasks(int);
void removetask(int,int);
void getTasks();
void setsize(int);

};
