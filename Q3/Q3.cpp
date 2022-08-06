//Mahad Ahmed 20i0426
#include<iostream>
using namespace std;
#include"calendar.h"

//************************FUNCTIONS FOR CALENDAR.H***************************
//Function that returns day number (0-6) for a given date
int calendar::getday(int d,int m,int y){
static int t[]={0,3,2,5,0,3,5,1,4,6,2,4};
y-=m<3;
return(((y)+(y/4)-(y/100)+(y/400)+t[m-1]+d)%7);
}

//function to return name of day
string calendar::wordgetday(int num){
string days[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
return (days[num]);
}

//function that returns the name of that month(0-11)
string calendar::getmonth(int num){
string months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
return (months[num-1]);
}

//function that returns the number of days of that month
int calendar::numdays(int month,int year){
        if(month==0){
        return 31;
        }
        else if(month==1){
                if((year%400==0) or (year%4==0 and year%100!=0)){
                return 29;
                }
                else{
                return 28;
                }
        }
        else if(month==2){
        return 31;
        }
        else if(month==3){
        return 30;
        }
        else if(month==4){
        return 31;
        }
        else if(month==5){
        return 30;
        }
        else if(month==6){
        return 31;
        }
        else if(month==7){
        return 31;
        }
        else if(month==8){
        return 30;
        }
        else if(month==9){
        return 31;
        }
        else if(month==10){
        return 30;
        }
        else if(month==11){
        return 31;
        }
return -1;
}

void calendar::displaycalendar(int month,int year){
cout<<"Calendar for "<<getmonth(month)<<","<<year<<endl;
cout<<"_____________________________________________"<<endl;
int days=numdays(month,year);
int current = getday(1,month,year);
cout<<"  SUN  MON  TUE  WED  THU  FRI  SAT"<<endl;
int x;
        for(x=0;x<current;x++){
        cout<<"     ";
        }
        for(int i=1;i<=days;i++){
        cout<<setw(5)<<i;
                if(++x>6){
                x=0;
                cout<<endl;
                }
        }
cout<<"______________________________________________"<<endl;
cout<<endl;
return;
}

//returns the number of days between two dates
long int calendar::subtractdates(int d1,int m1,int y1,int d2,int m2,int y2){
        if(m1<=2){
        m1=m1+12;
        y1=y1-1;
        }
        if(m2<=2){
        m2=m2+12;
        y2=y2-1;
        }
long int ndays1 = ((146097*y1)/400) + (((153*m1)+8)/5) + d1;
long int ndays2 = ((146097*y2)/400) + (((153*m2)+8)/5) + d2;
return (ndays1 - ndays2);
}

//returns true for a leap year
bool calendar::leapyear(int y){
        if(y%100!=0 and y%4==0 or y%400==0){
        return true;
        }
return false;
}

//This function returns numbers of days elapsed from that year
int calendar::elapseddays(int d,int m,int y){
int elapsed=d;
        switch(m-1)
        {
        case 11:
                elapsed+=30;
        case 10:
                elapsed+=31;
        case 9:
                elapsed+=30;
        case 8:
                elapsed+=31;
        case 7:
                elapsed+=31;
        case 6:
                elapsed+=30;
        case 5:
                elapsed+=31;
        case 4:
                elapsed+=30;
        case 3:
                elapsed+=31;
        case 2:
                elapsed+=28;
        case 1:
                elapsed+=31;
        }
        
        if(leapyear(y) and m>2){
        elapsed+=1;
        }
return elapsed;
}

//Using year and days elapsed, it finds date by storing in d and m
void calendar::revelapseddays(int elapsed,int y,int*d,int *m){
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
if(leapyear(y)){
month[2]=29;
}
int i;
for(i=1;i<=12;i++){
        if(elapsed<=month[i])
                break;
        elapsed=elapsed-month[i];
}
*d=elapsed;
*m=i; 
}

void calendar::adddays(int d1,int m1,int y1,int x){
int elapsed1=elapseddays(d1,m1,y1);
int remdays=leapyear(y1)?(366-elapsed1):(365-elapsed1);

//y2 is storing result year and elapsed2 will store offset days in resulting year
int y2,elapsed2;
if(x<=remdays){
y2=y1;
elapsed2=elapsed1+x;
}
else{
//x may have many days, find correct year and offset in the year
x-=remdays;
y2=y1+1;
int y2days=leapyear(y2)?366:365;
        while(x>=y2days){
        x-=y2days;
        y2++;
        y2days=leapyear(y2)?366:365;
        }
elapsed2=x;
}
//find day and month from offset of result year
int m2,d2;
revelapseddays(elapsed2,y2,&d2,&m2);
/*cout<<" "<<wordgetday(getday(d2,m2,y2))<<","<<d2<<" "<<getmonth(m2)<<"  "<<y2<<endl;*/
cout<<" is "<<wordgetday(getday(d2,m2,y2))<<","<<d2<<" "<<getmonth(m2)<<"  "<<y2<<endl;
}

//function for subtraction (___ days past from start date)
void calendar::findpast(int look,int d,int m,int y){
//cout<<"Original"<<d<<"/"<<m<<"/"<<y<<endl;
int n=12;
int tdays[n]={31,28,31,30,31,31,31,31,30,31,30,31};
if(leapyear(y)){
tdays[1]=29;
}
while(look!=0){
d--;
if(d==1){
        d=tdays[n-1]+1;
        n=n-1;
        m=m-1;
        if(m<1){
                m=12;
                d=tdays[n-1]+1;
        }
}
look--;
}
while(m<1){
        m=m+12;
        y--;
}
//cout<<"New"<<d<<"/"<<m<<"/"<<y<<endl;
cout<<" is "<<wordgetday(getday(d,m,y))<<","<<d<<" "<<getmonth(m)<<"  "<<y<<endl;
}

//*********************************FUNCTIONS FOR DATE CLASS******************************************
void date::setdate(int d,int m,int y){
day=d;
month=m;
year=y;
}

int date::getday(){
return day;
}

int date::getmonth(){
return month;
}

int date::getyear(){
return year;
}

void date::setTasks(int n){
      s=n;
      for(int i=0;i<s;i++){
          cout<<"Enter Task # "<<i+1<<" :\n";
          string value;
          getline(cin,value);
          tasks[i]=value;
      }
}
  
void date::removetask(int n,int r){
      tasks[r]=" ";
      for(int i=r+1;i<s;i++){
          tasks[i]=tasks[i-1];
      }
      s=n-1;
}  

void date::getTasks(){
cout<<"_______________________________________"<<endl;
      cout<<"Tasks: "<<endl;
      for(int i=0;i<s;i++){
          cout<<i+1<<"-"<<tasks[i]<<endl;
      }
cout<<"_______________________________________"<<endl;
}

void date::setsize(int num){
      s=num;
}

//***************************************************************************************************************

void menu(){
cout<<endl;
cout<<"1-Display Calendar for a different month\n2-Manage Notes (view,add,edit,or delete)\n3-Calculate difference between two dates\n4-Calculate Future Date\n5-Calculate Past date\n6-Exit\n";
}

int main(){
calendar c;
int choice=1;
c.displaycalendar(5,2021);
menu();
cin>>choice;

while(choice!=6){
        if(choice==1){
        int cyear,cmonth;
        cout<<"Enter Year: ";
        cin>>cyear;
        cout<<"\nEnter New Month (1-12): ";
        cin>>cmonth;
        cout<<endl;
                if(cmonth<=0 or cmonth>12 or cyear<0){
                cout<<"INVALID INPUT"<<endl;
                continue;
                }
        c.displaycalendar(cmonth,cyear);
        menu();
        cin>>choice;
        }
        else if(choice==2){
        int std3,stm3,sty3,n,rem,press2;
        cout<<"Enter Date you want to add/delete tasks for (in numbers):"<<endl;
        cout<<"Day: ";
        cin>>std3;
        cout<<"\nMonth: ";
        cin>>stm3;
        cout<<"\nYear: ";
        cin>>sty3;
        cout<<endl;
        date d1;
        d1.setdate(std3,stm3,sty3);
        cout<<"Do you want to set 1-New Tasks or 2-Delete a task?\n";
        cin>>press2;
                if(press2==1){
                    cout<<"\nHow many tasks are there?";
                    cin>>n;
                    cin.ignore();
                    d1.setsize(n);
                    d1.setTasks(n);
                }
                else if(press2==2){
                    cout<<"\nHow many tasks are there Currently?";
                    cin>>n;
                    cout<<"\nwhich task number do you want to remove?";
                    cin>>rem;
                    d1.removetask(n,rem);
                }
        cout<<"Tasks For Date: "<<std3<<"/"<<stm3<<"/"<<sty3<<" Are: "<<endl;
        d1.getTasks();
        menu();
        cin>>choice;
        }
        else if(choice==3){
        int sd,sm,sy,fd,fm,fy;
        cout<<"Entering Information for Start Date in numbers:  "<<endl;
        cout<<"Start Day: ";
        cin>>sd;
        cout<<"\nStart Month: ";
        cin>>sm;
        cout<<"\nStart Year: ";
        cin>>sy;
        cout<<"\nEntering Information for Finish Date in numbers:  "<<endl;
        cout<<"Finish Day: ";
        cin>>fd;
        cout<<"\nFinish Month: ";
        cin>>fm;
        cout<<"\nFinish Year: ";
        cin>>fy;
        cout<<endl;
        long int ddiff=c.subtractdates(fd,fm,fy,sd,sm,sy); //format (finish date, start date) 
        int format;
        cout<<"Do you wish to see the answer in 1-Months or 2-Weeks? (enter 1 or 2): ";
        cin>>format;
        cout<<endl;
                if(format==1){
                long double ans= ddiff/30.4167;
                long double ans2= ((int)ans) - ans;
                cout<<(int)ans<<" Months, "<<(int)(ans2*30.4167*-1)+1<<" Days"<<endl;
                }
                else if(format==2){
                long double ans3=(long double)ddiff/(long double)7;
                int a=(int)ans3;
                long double ans4=a-ans3;
                cout<<a<<" Weeks, "<<(int)(ans4*7*-1)<<" Days"<<endl;
                }
        menu();
        cin>>choice;
        }
        else if(choice==4){
        int std,stm,sty;
        cout<<"Enter Data for Start Date (in Numbers only): "<<endl;
        cout<<"Day: ";
        cin>>std;
        cout<<"\nMonth: ";
        cin>>stm;
        cout<<"\nYear: ";
        cin>>sty;
        cout<<endl;
        cout<<"Enter would you like to input in 1-Days, 2-Weeks, or 3-Months: ";
        int option,time;
        cin>>option;
        long int futuredays;
                if(option==1){
                cout<<"Enter Days: ";
                cin>>time;
                cout<<endl;
                cout<<time<<" Days from "<<std<<" "<<c.getmonth(stm)<<" "<<sty;
                //cout<<"time: "<<time<<endl;
                c.adddays(std,stm,sty,time);   
                }
                else if(option==2){
                cout<<"Enter Weeks: ";
                cin>>time;
                cout<<endl;
                int wtdays=time*7;
                cout<<time<<" Weeks from "<<std<<" "<<c.getmonth(stm)<<" "<<sty;
                c.adddays(std,stm,sty,wtdays); 
                }
                else if(option==3){
                cout<<"Enter Months: ";
                cin>>time;
                cout<<endl;
                int mtdays=(time*30.417)+1;
                cout<<time<<" Months from "<<std<<" "<<c.getmonth(stm)<<" "<<sty;
                c.adddays(std,stm,sty,mtdays); 
                } 
        menu();
        cin>>choice;
        }
        else if(choice==5){
        int std2,stm2,sty2;
        cout<<"Enter Data for Start Date (in Numbers only): "<<endl;
        cout<<"Day: ";
        cin>>std2;
        cout<<"\nMonth: ";
        cin>>stm2;
        cout<<"\nYear: ";
        cin>>sty2;
        cout<<endl;
        cout<<"Enter would you like to input in 1-Days, 2-Weeks, or 3-Months: ";
        int option2,time2;
        long int futuredays;
        cin>>option2;
        if(option2==1){
                cout<<"Enter Days: ";
                cin>>time2;
                cout<<endl; 
                cout<<time2<<" Days back from "<<std2<<" "<<c.getmonth(stm2)<<" "<<sty2;
                c.findpast(time2,std2,stm2,sty2);
                }
                else if(option2==2){
                cout<<"Enter Weeks: ";
                cin>>time2;
                cout<<endl;
                int wtdays2=time2*7; 
                cout<<time2<<" Weeks Back  from "<<std2<<" "<<c.getmonth(stm2)<<" "<<sty2;
                c.findpast(wtdays2,std2,stm2,sty2);
                }
                else if(option2==3){
                cout<<"Enter Months: ";
                cin>>time2;
                cout<<endl;
                int mtdays2=(time2*30.417)+1; 
                cout<<time2<<" Months Back from "<<std2<<" "<<c.getmonth(stm2)<<" "<<sty2;
                c.findpast(mtdays2,std2,stm2,sty2);
                } 
        menu();
        cin>>choice;
        }
        else if(choice==6){
        exit(0);
        }
        else{
        cout<<"INVALID CHOICE,Enter Again"<<endl;
        cin>>choice;
        }
}

}
