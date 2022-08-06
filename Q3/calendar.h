//Mahad Ahmed 20i0426
#include<iostream>
#include<iomanip>
using namespace std;
#include "date.h"

class calendar{

public:
int getday(int ,int ,int );
string wordgetday(int);
string getmonth(int);
int numdays(int,int);
void displaycalendar(int ,int);
long int subtractdates(int ,int,int,int,int,int);

bool leapyear(int);
int elapseddays(int,int,int);
void revelapseddays(int,int,int*,int* );
void adddays(int,int ,int,int);
void findpast(int,int,int,int);

};
