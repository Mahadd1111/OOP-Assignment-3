//Mahad Ahmed 20i0426
#include<iostream>
#include<string>
#include<iomanip>
#include "customer.h" 
#include<stdlib.h>
using namespace std;

//************************FUNCTIONS OF CATEGORIES.H ****************************************
void category::setcategory(int i,string n){
id=i;
name=n;
}

int category::getid(){
return id;
}

string category::getname(){
return name;
}

//***********************FUNCTIONS OF ITEMS.H************************************************
void items::setitems(string n,category m){
name=n;
c=m;
}

string items::getname(){
return name;
}

category items::getc(){
return c;
}

//***********************FUNCTIONS OF CUSTOMER.H************************************************
void customer::setcustomer(int i,string n,items a,items b){
id=i;
name=n;
past[0]=a;
past[1]=b;
}

int customer::getid(){
return id;
}

string customer::getname(){
return name;
}

items customer::getpast(int x){
return past[x];
}

//Function that first displays all saved data 
void displaywhole(customer a[25]){
cout<<"DISPLAYING CUSTOMER DATA: "<<endl<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
cout<<setw(5)<<left<<"ID"<<setw(20)<<left<<"Customer Name"<<setw(20)<<left<<"Past Item 1"<<setw(20)<<left<<"Past Item 2"<<endl;
        for(int i=0;i<25;i++){
        cout<<setw(5)<<left<<a[i].getid()<<setw(20)<<left<<a[i].getname()<<setw(20)<<left<<a[i].getpast(0).getname()<<setw(20)<<left<<a[i].getpast(1).getname()<<endl;
        }
cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
}

//function that displays the menu
void menu(){
cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
cout<<"Enter Options from the list"<<endl;
cout<<"1-View All items\n2-View Purchase History\n3-View recommended items\n4-Login Again\n5-Exit"<<endl;
cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
}


int main(){
string cname[25]={"John","Mahad","Ali","Katy","Mariam","Ahmad","Saif","Alishba","Tokyo","Thomas","Arthur","Michael","Jaden","Margot","Lauren","Lisa","Carmen","Alizay","Hania","george","Elizabeth","Holly","Jacob","Joseph","Mary"};
string iname[30]={"Dolby speakers","Samsung TV","Wireless Headset","Sofa set","Curtains","Coffee Table","Tea cups","Jugs","Pans","Footballs","Cricket Bats","Basketballs","T-Shirts","Hoodies","Jeans","Iphone 12","One Plus 9","Nokia 3310","Nike Air","Adidas Adizero","Yeezys","Ps5","Xbox one","Nintendo Switch","Harry potter(DVD)","Hobbit(DVD)","Jumanji(DVD)","Cereals","Milkshakes","Barbecue"};

category cat[10];
items t[30];
customer c[25];
//Setting Categories
cat[0].setcategory(0,"Tech");
cat[1].setcategory(1,"Home");
cat[2].setcategory(2,"Cutlery");
cat[3].setcategory(3,"Sports");
cat[4].setcategory(4,"Clothing");
cat[5].setcategory(5,"Phones");
cat[6].setcategory(6,"Shoes");
cat[7].setcategory(7,"VideoGames");
cat[8].setcategory(8,"Movies");
cat[9].setcategory(9,"Food");

//setting items
for(int i=0;i<30;i++){

        if(i>=0 and i<3){
        t[i].setitems(iname[i],cat[0]);
        }
        if(i>=3 and i<6){
        t[i].setitems(iname[i],cat[1]);
        }
        if(i>=6 and i<9){
        t[i].setitems(iname[i],cat[2]);
        }
        if(i>=9 and i<12){
        t[i].setitems(iname[i],cat[3]);
        }
        if(i>=12 and i<15){
        t[i].setitems(iname[i],cat[4]);
        }
        if(i>=15 and i<18){
        t[i].setitems(iname[i],cat[5]);
        }
        if(i>=18 and i<21){
        t[i].setitems(iname[i],cat[6]);
        }
        if(i>=21 and i<24){
        t[i].setitems(iname[i],cat[7]);
        }
        if(i>=24 and i<27){
        t[i].setitems(iname[i],cat[8]);
        }
        if(i>=27 and i<30){
        t[i].setitems(iname[i],cat[9]);
        }
        
}

//Setting Customers
for(int i=0;i<25;i++){
        srand(i); 
        int n1=rand()%30; //random item one (past purchase)
        srand(i+n1);
        int n2=rand()%30; //random item two (past purchase)
        if(n2==n1){ //check to make sure two items arent the same
        srand(n1);
        n2=rand()%30;
        }
        c[i].setcustomer(i,cname[i],t[n1],t[n2]);
}

//Displaying this data
displaywhole(c);

//Login
int n,option;
cout<<"WELCOME TO EZSHOP ONLINE STORE"<<endl;
login:
cout<<"Enter Your Customer ID (0-24): ";
cin>>n;
cout<<endl;

//menu 
option=0;

while(option!=5){
menu();
cin>>option;
        if(option==1){
        cout<<"ALL ITEMS"<<endl;
        cout<<setw(20)<<left<<"Item"<<setw(20)<<left<<"Category"<<endl;
        cout<<"_____________________________________"<<endl;
                for(int i=0;i<30;i++){
                cout<<i+1<<"-"<<setw(20)<<left<<t[i].getname()<<setw(20)<<left<<t[i].getc().getname()<<endl;
                cout<<"_____________________________________"<<endl;
                }
        }
        else if(option==2){
                cout<<"_______________________________________"<<endl;
                cout<<"PREVIOUSLY PURCHASED ITEMS: "<<endl;
                cout<<"1-"<<c[n].getpast(0).getname()<<endl;
                cout<<"2-"<<c[n].getpast(1).getname()<<endl;
                cout<<"_______________________________________"<<endl;
        }
        else if(option==3){
        cout<<"_______________________________________"<<endl;
        cout<<"RECOMMENDED ITEMS"<<endl;
                for(int i=0;i<30;i++){//go through all items for past purchase 1
                        if((c[n].getpast(0).getc().getid()==t[i].getc().getid() and t[i].getname()!=c[n].getpast(0).getname() and t[i].getname()!=c[n].getpast(1).getname()) or c[n].getpast(1).getc().getid()==t[i].getc().getid() and t[i].getname()!=c[n].getpast(0).getname() and t[i].getname()!=c[n].getpast(1).getname()){
                        cout<<t[i].getname()<<endl;
                        }
                }
                cout<<"_______________________________________"<<endl;                
        }
        else if(option==4){
        goto login;
        }
}
return 0;
}


