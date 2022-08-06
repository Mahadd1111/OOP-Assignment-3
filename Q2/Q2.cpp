//Mahad Ahmed 20i0426 
#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
using namespace std;

#define NUM_MEDICAL_INSTITUTES 3 //total institutes
#define NUM_PATIENTS 10 //total patients
#define NUM_DOCTORS 5 //total doctors
#define NUM_MEDICINES 10 //total medicines
#define NUM_MEDICAL_VISITS 20 //total visits recorded
#define NUM_MV_PATIENT 3
#define NUM_DOC_PATIENT 3
#define NUM_MAX_MED 4
class patient;
class phr;
class visit;
class time;
//******************************************************CLASS DEFINITIONS****************************************************
class institute
{
	int id;
	string name;

public:
	void setdata(int i, string n){
	id=i;
	name=n;
	}
	int getid() {return id;}
	string getname() {return name;}
};
//****************************************************************************************************************************
class medicine
{
	int id;
	string name;

public:
	void setdata(int i, string n){
	id=i;
	name=n;
	}
	void setid(int i) {this->id = i;}
	int getid() {return id;}
	void setname(string n) {this->name = n;}
	string getname() {return name;}
};
//****************************************************************************************************************************
class doctor
{
	int id;
	string name;
	institute employer;// (i.e. medical institute).

public:
	void setdata(int i, string n, institute mi) {
	id=i;
	name=n;
	employer=mi;
	}
	
	institute getemployer(){
	return employer;
	}
	
	string getname(){
        return name;
        }
        
        int getid(){
        return id;
        }
        
	//PHR getPHRAccess(Patient);
};
//****************************************************************************************************************************
class patient
{
	int id;
	string name;
	phr *myphr;
public:
	void setdata(int i, string n) {
	id=i;
	name=n;
	}
	
	void setphr(phr);
	//void setphr(phr data){
	//*myphr=data;
	//}
	
	int getid(){
        return id;
        }
        
        string getname(){
        return name;
        }
	
	phr getphr();
	//phr getphr(){
	//return *myphr;
	//}
	
	void adddoctophr(doctor);
	phr phraccessrequest(int);
};
//****************************************************************************************************************************
class times{
int hour;
int minute;
public:
void settime(int h,int m){
hour=h;
minute=m;
}
string gettime(){
string t=to_string(hour) + ":" + to_string(minute);
return t;
}

};

class visit
{
	int id;
	times t;//(either create Time class or use any representation of your choice to represent both date and time)
	patient pat;
	institute mi;
	doctor doc;
	medicine med; //assume only a single medicine prescribed in each visit

public:
	void setdata(int i, patient p, institute m, doctor d, medicine md){
	id=i;
	pat=p;
	mi=m;
	doc=d;
	med=md;
	}
	void settimet(int h1,int m1){
	t.settime(h1,m1);
	}
	times gettimet(){
        return t;
        }
	void setid(int i) {id = i;}
	int getid() {return id;}
	institute getinstitute(){
	return mi;
	}
	patient getpatient () {return this->pat;}
	doctor getdoctor() {return this->doc;}
	medicine getmedicine() {return this->med;}
};
//****************************************************************************************************************************
class phr
{
	int id;
	patient pat;
	visit medvisits[NUM_MV_PATIENT]; //array of medical visit objects
	doctor docs[NUM_DOC_PATIENT]; //list of doctors who this patient sees. Not necessary that all past visited doctors are in this list; patient can add and remove, so this is not redundant
	medicine meds[NUM_MAX_MED]; //list of current medications.

public:
	void setdata(int i,patient p, visit mArr[], doctor dArr[], medicine medArr[]){
	id=i;
	pat=p;
	        for(int x=0;x<NUM_MV_PATIENT;x++){
	        medvisits[x]=mArr[x];
	        }
	        for(int x=0;x<NUM_DOC_PATIENT;x++){
	        docs[x]=dArr[x];
	        }
	        for(int x=0;x<NUM_MAX_MED;x++){
	        meds[x]=medArr[x];
	        }
	        
	        
	}
	
	
	doctor getdoctor(int x){
	return docs[x];
	}
	
	visit getvisit(int x){
	return medvisits[x];
	}
	


	void adddoc(doctor);
	//for simplicity, you can assume that a fixed maximum number of doctors can be added (decide the limit yourself).
	//you can ignore requests to add doctor if already the maximum number of doctors is added in a PHR.
	//you can use Doctor objects with ID -1 to represent empty locations.

	void displayphr()
	{
		//Insert code to neatly display all sections of PHR.
		cout<<"---------------------\n\n";
	}
	void addvisit(visit);
	void removedoctor(doctor);
};
//****************************************************************************************************************************
void patient::setphr(phr data){
	*myphr=data;
}
	
phr patient::getphr(){
	return *myphr;
}	
//**************************************************************************************************************************
void displaygenerateddata(institute iarr[],patient parr[],doctor darr[],medicine marr[],phr harr[],visit varr[]){
cout<<"------------------------------------------ALL DATA IN ARCHIVES--------------------------------------"<<endl;

cout<<"DATA FOR ALL INSTITUTES: "<<endl;
cout<<setw(5)<<left<<"ID"<<setw(20)<<left<<"NAME"<<endl;
for(int i=0;i<3;i++){
cout<<setw(5)<<left<<iarr[i].getid()<<setw(20)<<left<<iarr[i].getname()<<endl;
}
cout<<"____________________________________________________________________________________________________"<<endl;

cout<<"DATA FOR ALL PATIENTS: "<<endl;
cout<<setw(5)<<left<<"ID"<<setw(20)<<left<<"NAME"<<setw(12)<<left<<"Visit 1 ID"<<setw(12)<<left<<"Visit 2 ID"<<setw(12)<<left<<"Visit 3 ID"<<setw(20)<<left<<"DOCTOR 1 NAME"<<setw(20)<<left<<"DOCTOR 2 NAME"<<setw(20)<<left<<"DOCTOR 3 NAME"<<endl;
for(int i=0;i<10;i++){
cout<<setw(5)<<left<<parr[i].getid()<<setw(20)<<left<<parr[i].getname()<<setw(12)<<left<<harr[i].getvisit(0).getid()<<setw(12)<<left<<harr[i].getvisit(1).getid()<<setw(12)<<left<<harr[i].getvisit(2).getid()<<setw(20)<<left<<harr[i].getdoctor(0).getname()<<setw(20)<<left<<harr[i].getdoctor(1).getname()<<setw(20)<<left<<harr[i].getdoctor(2).getname()<<endl;
}
cout<<"______________________________________________________________________________________________________"<<endl;

cout<<"DATA FOR ALL DOCTORS: "<<endl;
cout<<setw(5)<<left<<"ID"<<setw(20)<<left<<"NAME"<<setw(20)<<left<<"EMPLOYER"<<endl;
for(int i=0;i<5;i++){
cout<<setw(5)<<left<<darr[i].getid()<<setw(20)<<left<<darr[i].getname()<<setw(20)<<left<<darr[i].getemployer().getname()<<endl;
}
cout<<"________________________________________________________________________________________________________"<<endl;

cout<<"DATA FOR ALL MEDICINES: "<<endl;
cout<<setw(5)<<left<<"ID"<<setw(20)<<left<<"NAME"<<endl;
for(int i=0;i<10;i++){
cout<<setw(5)<<left<<marr[i].getid()<<setw(20)<<left<<marr[i].getname()<<endl;
}
cout<<"________________________________________________________________________________________________________"<<endl;

cout<<"DATA FOR ALL VISITS: "<<endl;
cout<<setw(5)<<left<<"ID"<<setw(10)<<left<<"TIME"<<setw(30)<<left<<"LOCATION"<<setw(20)<<left<<"PATIENT NAME"<<setw(20)<<left<<"DOCTOR NAME"<<setw(20)<<left<<"PRESCRIBED MEDICINE"<<endl;
for(int i=0;i<20;i++){
cout<<setw(5)<<left<<varr[i].getid()<<setw(10)<<left<<varr[i].gettimet().gettime()<<setw(30)<<left<<varr[i].getinstitute().getname()<<setw(20)<<left<<varr[i].getpatient().getname()<<setw(20)<<left<<varr[i].getdoctor().getname()<<setw(20)<<left<<varr[i].getmedicine().getname()<<endl;
}
cout<<"_________________________________________________________________________________________________________"<<endl;

}




int main()

{
    //create arrays to hold data for initializing program:
    //array sizes are global constant integers.
	institute miarr[NUM_MEDICAL_INSTITUTES];
	patient patientarr[NUM_PATIENTS];
	doctor doctorarr[NUM_DOCTORS];
	medicine medarr[NUM_MEDICINES];
	visit visarr[NUM_MEDICAL_VISITS];
	phr phrarr[NUM_PATIENTS];
//*********************************************************************************************	
	//SETTING MEDICAL INSTITUTES
	string iname[3]={"Shifa Hospital","Islamabad Diagnostic","Reliance Hospital"};
	for(int i=0;i<NUM_MEDICAL_INSTITUTES;i++){
	miarr[i].setdata(10+i,iname[i]);
	}
	//SETTING PATIENTS
	string pname[10]={"Mahad","Mariyum","Katy","John","Elizabeth","Jordan","Lionel","Giselle","Martin","Emily"};
	for(int i=0;i<NUM_PATIENTS;i++){
	patientarr[i].setdata(20+i,pname[i]);
	}
	//SETTING DOCTORS
	string dname[5]={"DR.Ali","DR.Alishba","DR.Zohair","DR.Haris","DR.JENNIFER"};
	int n;
	for(int i=0;i<NUM_DOCTORS;i++){
	srand(i);
	n=rand()%3;
	doctorarr[i].setdata(30+i,dname[i],miarr[n]);
	}
	//SETTING MEDICINES
	string mname[10]={"Panadol","Kestine","Tylenol","Brufen","Amifostine","Abacavir","Metoprolol","Albuterol","Omeprazole","Cough"};
	for(int i=0;i<NUM_MEDICINES;i++){
	medarr[i].setdata(40+i,mname[i]);
	}
	//SETTING VISITS
	for(int i=0;i<20;i++){
	srand(i);
	int n1=rand()%24;
	srand(i+2);
	int n2=(rand()%50)+10;
	visarr[i].settimet(n1,n2);
	}
        visarr[0].setdata(50,patientarr[0],doctorarr[1].getemployer(),doctorarr[1],medarr[3]);
        visarr[1].setdata(51,patientarr[0],doctorarr[3].getemployer(),doctorarr[3],medarr[1]);
        visarr[2].setdata(52,patientarr[1],doctorarr[0].getemployer(),doctorarr[0],medarr[4]);
        visarr[3].setdata(53,patientarr[1],doctorarr[2].getemployer(),doctorarr[2],medarr[6]);
        visarr[4].setdata(54,patientarr[2],doctorarr[1].getemployer(),doctorarr[1],medarr[2]);
        visarr[5].setdata(55,patientarr[2],doctorarr[4].getemployer(),doctorarr[4],medarr[0]);
        visarr[6].setdata(56,patientarr[3],doctorarr[3].getemployer(),doctorarr[3],medarr[7]);
        visarr[7].setdata(57,patientarr[3],doctorarr[4].getemployer(),doctorarr[4],medarr[5]);
        visarr[8].setdata(58,patientarr[4],doctorarr[0].getemployer(),doctorarr[0],medarr[5]);
        visarr[9].setdata(59,patientarr[4],doctorarr[4].getemployer(),doctorarr[4],medarr[9]);
        visarr[10].setdata(60,patientarr[5],doctorarr[2].getemployer(),doctorarr[2],medarr[3]);
        visarr[11].setdata(61,patientarr[5],doctorarr[3].getemployer(),doctorarr[3],medarr[2]);
        visarr[12].setdata(62,patientarr[6],doctorarr[4].getemployer(),doctorarr[4],medarr[8]);
        visarr[13].setdata(63,patientarr[6],doctorarr[2].getemployer(),doctorarr[2],medarr[0]);
        visarr[14].setdata(64,patientarr[7],doctorarr[1].getemployer(),doctorarr[1],medarr[4]);
        visarr[15].setdata(65,patientarr[7],doctorarr[3].getemployer(),doctorarr[3],medarr[1]);
        visarr[16].setdata(66,patientarr[8],doctorarr[2].getemployer(),doctorarr[2],medarr[7]);
        visarr[17].setdata(67,patientarr[8],doctorarr[3].getemployer(),doctorarr[3],medarr[8]);
        visarr[18].setdata(68,patientarr[9],doctorarr[0].getemployer(),doctorarr[0],medarr[9]);
        visarr[19].setdata(69,patientarr[9],doctorarr[1].getemployer(),doctorarr[1],medarr[6]);
        
        //SETTING CURRENT PHR'S
        visit tempv[3]={visarr[0],visarr[1]};
        doctor tempd[3]={doctorarr[1],doctorarr[3]};
        medicine tempm[4]={medarr[3],medarr[1]};
        phrarr[0].setdata(70,patientarr[0],tempv,tempd,tempm);
        
        visit tempv1[3]={visarr[2],visarr[3]};
        doctor tempd1[3]={doctorarr[0],doctorarr[2]};
        medicine tempm1[4]={medarr[4],medarr[6]};
        phrarr[1].setdata(71,patientarr[1],tempv1,tempd1,tempm1);
        
        visit tempv2[3]={visarr[4],visarr[5]};
        doctor tempd2[3]={doctorarr[1],doctorarr[4]};
        medicine tempm2[4]={medarr[2],medarr[0]};
        phrarr[2].setdata(72,patientarr[2],tempv2,tempd2,tempm2);
        
        visit tempv3[3]={visarr[6],visarr[7]};
        doctor tempd3[3]={doctorarr[3],doctorarr[4]};
        medicine tempm3[4]={medarr[7],medarr[5]};
        phrarr[3].setdata(73,patientarr[0],tempv3,tempd3,tempm3);
        
        visit tempv4[3]={visarr[8],visarr[9]};
        doctor tempd4[3]={doctorarr[0],doctorarr[4]};
        medicine tempm4[4]={medarr[5],medarr[9]};
        phrarr[4].setdata(74,patientarr[0],tempv4,tempd4,tempm4);
        
        visit tempv5[3]={visarr[10],visarr[11]};
        doctor tempd5[3]={doctorarr[2],doctorarr[3]};
        medicine tempm5[4]={medarr[3],medarr[2]};
        phrarr[5].setdata(75,patientarr[0],tempv5,tempd5,tempm5);
        
        visit tempv6[3]={visarr[12],visarr[13]};
        doctor tempd6[3]={doctorarr[4],doctorarr[2]};
        medicine tempm6[4]={medarr[8],medarr[0]};
        phrarr[6].setdata(76,patientarr[0],tempv6,tempd6,tempm6);
        
        visit tempv7[3]={visarr[14],visarr[15]};
        doctor tempd7[3]={doctorarr[1],doctorarr[3]};
        medicine tempm7[4]={medarr[4],medarr[1]};
        phrarr[7].setdata(77,patientarr[0],tempv7,tempd7,tempm7);
        
        visit tempv8[3]={visarr[16],visarr[17]};
        doctor tempd8[3]={doctorarr[2],doctorarr[3]};
        medicine tempm8[4]={medarr[7],medarr[8]};
        phrarr[8].setdata(78,patientarr[0],tempv8,tempd8,tempm8);
        
        visit tempv9[3]={visarr[18],visarr[19]};
        doctor tempd9[3]={doctorarr[0],doctorarr[1]};
        medicine tempm9[4]={medarr[1],medarr[6]};
        phrarr[9].setdata(79,patientarr[0],tempv9,tempd9,tempm9);
        
      /*  for(int i=0;i<10;i++){
        patientarr[i].setphr(phrarr[i]);
        }*/

//*****************************************************************************************************************

//TIME TO DISPLAY ALL DATA

	//generate and display initial data for Medicines, Patients, Doctors, Medical Institutes, Medical Visits, and PHRs:
//	generatedata(miarr, patientarr, doctorarr, medarr, phrarr, visarr); //this should populate each array with objects of its type, strictly using only setter functions of each class.
	displaygenerateddata(miarr, patientarr, doctorarr, medarr, phrarr, visarr); //display the generated data strictly using getter functions of all classes.
//********************************************************************************************************************
/*


	//Simulate PHR update and access control:

	//Patient adds new doctor to be visited to his PHR.
	//Randomly generate a patient and a doctor:
	int currentPatient = rand()%NUM_PATIENTS;
	int addedDoctor = rand()%NUM_DOCTORS; //randomly generate a doctor to add
	//Add here: functionality to check that this doctor is not already on patient's list of doctors
	cout<<"Patient "<<currentPatient<<" adding doctor "<<addedDoctor<<" to his PHR.\n";
	patientArr[currentPatient].addDocToPHR(doctorArr[addedDoctor]);

	//display patient's PHR to verify that doctor has been added:
	cout<<"Displaying updated PHR: "<<endl;
	patientArr[currentPatient].getPHR().displayPHR();

	//Medical visit happens: currentPatient visits addedDoctor
	//PHR should be updated with visit ID, time, doctor, and prescribed medicine.
	//assume one new medicine is prescribed on each visit, unless the patient is already taking the maximum number of medicines (declare a const int MAX_MEDICINES) (check number of current medicines from PHR).
	Medical_Visit new_medical_visit;
	new_medical_visit.setData(rand(), currentTime, patientArr[currentPatient], med_inst, doctorArr[addedDoctor], med); //generate all missing parameters before calling this function
	Medicine med = medArr[rand()%NUM_MEDS]; //randomly generate a Medicine to be prescribed after checking that it is not already on the patient's list of medicines (check list from patient's PHR)
	patientArr[currentPatient].getPHR().addVisit(new_medical_visit); //implement an addVisit function that adds information from a visit to relevant fields of the patient's PHR.
	cout<<"Another medical visit took place; added to PHR. Displaying updated PHR:\n";
	//Display updated PHR to verify that the last medical visit has been added to it:
	patientArr[currentPatient].getPHR().displayPHR();

	//Doctor requests access to his own patient's PHR, access granted.
	//Use the currentPatient and addedDoctor objects
	cout<<"Doctor visited (ID "<<addedDoctor<<") requested access to PHR of patient ID "<<currentPatient<<".\n";
    //Implement a function in the Doctor class that requests access to a particular
    //patient's PHR; that function should in turn call another function of the patient
    //class because a patient's PHR can only be accessed through the patient class
    //The function should return either the patient's PHR (in case of Access Granted)
    //or an empty PHR with ID=-1 to indicate Access Denied.
    //In this first case, access should be granted.
    PHR accessed = doctorArr[addedDoctor].getPHRAccess(patientArr[currentPatient]);

	if (acc.getID() == -1)
		cout<<"Access Denied\n";
	else
		cout<<"Access Granted\n";

	//Doctor requests access to a different patient's PHR, access denied
	int unknownPatient=0;
	//Find a patient unknown to this doctor, i.e. traverse the patientArr objects until you
	//find a patient whose PHR does not have this doctor on the list.
	cout<<"Doctor (ID "<<addedDoctor<<") requested access to PHR of patient that does not have this doctor on their PHR, Patient ID: "<<unknownPatient<<".\n";
	//Now the following line should return an empty PHR with ID = -1 to indicate access denied.
	acc = doctorArr[addedDoctor].getPHRAccess(patientArr[unknownPatient]);
	if (acc.getID() == -1)
			cout<<"Access Denied\n";
		else
			cout<<"Access Granted\n";

	//Patient edits doctor list to remove previous doctor.
	//currentPatient should now remove addedDoctor from the list of doctors on his PHR.
	patientArr[currentPatient].getPHR().removeDoctor(doctorArr[addedDoctor]);
	cout<<"Now Patient ID "<<currentPatient<<" has removed doctor ID "<<addedDoctor<<" from the list.\n";
	cout<<"Verifying access control:\n";
	//Now addedDoctor again requests access to the patient's PHR, but the patient has now removed this doctor.
	cout<<"Doctor (ID "<<addedDoctor<<") requested access to PHR of patient ID "<<currentPatient<<".\n";
	//Doctor access to PHR (previously granted) now denied.
	acc = doctorArr[addedDoctor].getPHRAccess(patientArr[currentPatient]);
	if (acc.getID() == -1)
		cout<<"Access Denied\n";
	else
		cout<<"Access Granted\n";
*/
    //Simulation complete.
	return 0;
}
