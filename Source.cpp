#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include  <bits/stdc++.h>

using namespace std;

//class for resrved customers
class ReserveCustomer
{
	private://private data members
		int day_of_reserving;
		int month_of_reserving;
		int year_of_reserving;
		int reserving_for_days; 
		int advance_payement;
		
	public://public function
		ReserveCustomer();
		void setreserve();
		int getday_of_reserving();
		int getmonth_of_reserving();
		int getyear_of_reserving();
		int getreserving_for_days();
		int getadvance_payement();
		~ReserveCustomer();
};

ReserveCustomer::ReserveCustomer()//constructor
{
	 day_of_reserving = 0;
	 month_of_reserving = 0;
	 year_of_reserving = 0;
	 reserving_for_days = 0; 
	 advance_payement = 0;
}

ReserveCustomer::~ReserveCustomer()//destructor
{
	cout<<" ";
}

void ReserveCustomer::setreserve()//seting values of data members of class
{
	this->day_of_reserving = 32;
	while(this->day_of_reserving > 31)
	{
	cout<< " Enter Todays's Date(day only) : " ;
	cin>>this->day_of_reserving;
	}
	 
	this->month_of_reserving = 13;
	while(this->month_of_reserving > 12)
	{
		cout<<" Enter Current Month(number) : ";
		cin>>this->month_of_reserving;
	} 
	
	cout<<" Enter Year(number) : ";
	cin>>this->year_of_reserving; 
	
	cout<<" Total Days You Want To Stay In The Room For : ";
	cin>>reserving_for_days;
	cout<<endl;
	
	this->advance_payement = 2;
	while(this->advance_payement != 0 && this->advance_payement != 1)
	{
		cout<<" (1) Yes \n (0) No \n";
		cout<<" Will Do Advance Payement? : ";
		cin>>this->advance_payement;
	}
	
}

//getters functions
int ReserveCustomer::getday_of_reserving()
{	return this->day_of_reserving;	}

int ReserveCustomer::getmonth_of_reserving()
{	return this->month_of_reserving;	}

int ReserveCustomer::getyear_of_reserving()
{	return this->year_of_reserving;	}

int ReserveCustomer::getreserving_for_days()
{	return this->reserving_for_days;	}

int ReserveCustomer::getadvance_payement()
{	return this->advance_payement;	}


//class for checkin customers
class CheckinCustomer
{
		private://private data members
		float checkinTime;
		int checkinMonth;
		int checkinYear;
		int checkinDate;
		int days;
		clock_t timeremaing;//runtime 
		
		public:
			CheckinCustomer();
			float getcheckinTime();
			int getcheckinMonth();
			int getcheckinYear();
			int getcheckinDate();
			int getdays();
			int setvalues();
			int gettimeremaing();
			~CheckinCustomer();
};
	CheckinCustomer::CheckinCustomer()//constructor
	{	
		checkinTime = 0;
		checkinMonth = 0;
		checkinYear = 0;
		checkinDate = 0;
		days = 0;
		timeremaing = clock();	
	}
	CheckinCustomer::~CheckinCustomer()//destructor
	{
		cout<<" ";
	}
	
	int CheckinCustomer::setvalues()//setting values for checkin data memebers
	{
		cout<<" Enter days you want to stay in for : ";
		cin>>this->days;
		
		cout<<" Check-In Time : ";
		cin>>checkinTime;
		
		cout<<" Check-In date(Day number) : ";
		cin>>this->checkinDate;
		
		cout<<" Check-In Month(number) : ";
		cin>>this->checkinMonth;
		
		cout<<" Check-In Year(number) : ";
		cin>>this->checkinYear;
	}
	
//getter functions of check in class
	float CheckinCustomer::getcheckinTime()
	{	return this->checkinTime; 	}
	
	int CheckinCustomer::getcheckinMonth()
	{	return this->checkinMonth; 	}
	
	int CheckinCustomer::getcheckinYear()
	{	return this->checkinYear; 	}
	
	int CheckinCustomer::getcheckinDate()
	{	return this->checkinDate; 	}
	
	int CheckinCustomer::getdays()
	{	return this->days;	}
	
	int CheckinCustomer::gettimeremaing()
	{	return this->timeremaing;	}
	

class Customer //Main Custommer Class
{
//Private Customer Data Members For Storing Customer Details	
	private:
		char* fullName;
		int age;
		int gender;
		long idNumber;
		int balance;
	
		int roomType;
		int floor;
		int roomNumber;

//Public Class Functions	
	public:
		
		Customer();
		void setvalues();
		ReserveCustomer Rc;//composition
		CheckinCustomer Cc;//composition
		
		void setfullName(string S);
		void setbalance(int s);
		void setroom(int s);
		void setfloor(int s);
		
		char* getfullName();
		int getage();
		int getgender();
		int getidNumber();
		int getbalance();
		
		int getfloor();
		int getroomNumber();
		int getroomType();
		
		Customer& operator=(const Customer&);
		
		~Customer();
};
	Customer::Customer()//constructor
	{	this->fullName = new char[25];
		 age = 0;
		 gender = 0;
		 idNumber = 0;
		 balance = 0;
	
		 roomType = 0;
		 floor = 0;
		 roomNumber = 0;	
	}
	Customer::	~Customer()//destructor
	{
		cout<<" ";
	}
	
	Customer& Customer::operator=(const Customer& C)//operator overloading
	{
		int len = 0;
		for(int x = 0; C.fullName[x] != '\0'; x++)
		{
			len++;
		}
		this->fullName = new char[len];
		
		for(int x=0; x < len; x++)
		{
			this->fullName[x] = C.fullName[x];
		}
		
		this->idNumber = C.idNumber;
		this->age = C.age;
		this->gender = C.gender;
		
	}
	void Customer::setvalues()//seting values for customer data mmembers
{
	string str;

	cout<<" Enter customer details"<<endl;
		
	cout<<"\n Enter name of customer : ";
	cin.ignore();
	getline(cin,str);
			
	this->setfullName(str);
		 	
	cout<<" Enter age : ";
	cin>>this->age;
		
	this->gender = 5;
	while(this->gender < 0 || this->gender > 1)
	{
		cout<<"\n  (0) Female \n  (1) Male"<<endl;
		cout<<" Enter gender(0/1) : ";
		cin>>this->gender; 
	}
	cout<<" Enter ID-number : ";
	cin>>this->idNumber;
	
	this->roomType = 5; 
	while(this->roomType < 0 || this->roomType > 4)
	{
		cout<<"\n  (0) Standard \n  (1) Moderate \n  (2) Superior \n  (3) Junior Suite \n  (4) Suite "<<endl;
		cout<<" Enter Room Type You Want To Reserve : ";
		cin>>this->roomType;
		cout<<endl;
	}
	
	int balance_payed = 0;
	while(balance_payed != 2) 
	{
		cout<<" Attention : Balance You Have To Pay(Compulsory)"<<endl;
		cout<<" (1)No (2)Yes "<<endl;
		cout<<" Pay balance(1/2) : ";
		cin>>balance_payed;
		cout<<endl;
	}
}

//setters functions for customer class 
	void Customer::setfullName(string S)
	{
		int len = 0;
		
		for(int i=0; S[i] != '\0'; i++)
		{	len++;	}
		
		this->fullName = new char[len];
		
		for(int i=0 ; i < len; i++)
		{	this->fullName[i] = S[i];	}
	}
	
	void Customer::setbalance(int s)
	{	this->balance = s; 	}
	
	void Customer::setroom(int s)
	{	this->roomNumber = s; 	}
	
	void Customer::setfloor(int s)
	{	this->floor = s;	}
	
	char* Customer::getfullName()
	{	return this->fullName;	}
	
	int Customer::getage()
	{	return this->age; 	}
	
	int Customer::getgender()
	{	return this->gender; 	}
	
	int Customer::getidNumber()
	{	return this->idNumber; 	}
	
	int Customer::getbalance()
	{	return this->balance; 	}
	
	int Customer::getfloor()
	{	return this->floor; 	}
	
	int Customer::getroomNumber()
	{	return this->roomNumber; 	}

	int Customer::getroomType()
	{	return this->roomType; 	}


//parent class for room room data members
class Room
{
	public://public data members
		int floor;
		int number;
		int type;
		bool empty;
		int price;
		
		public:
			Room()//constructor
			{
				floor = 0;
				number = 0;
				type = 0;
				empty = 0;
				price = 0;
			}
			void setempty(bool a)
			{
				empty = a;
			}
};
class Standard : public Room//standard is child of room
{
	public:
		void setbalance()//setting balance
		{
			type = 0;
			price = 300;
			empty = true;
		}
		int getprice()//getter
		{	return price;	}
};
class Moderate : public Room//moderate is child of room
{
	public:
		void setbalance()//setting balance
		{
			type = 1;
			price = 500;
			empty = true;
		}
		int getprice()
		{	return price;	}
};
class Superior : public Room//superior is child of room
{
	public:
		void setbalance()//setting balance
		{
			type = 2;
			price = 1000;
			empty = true;
		}
		int getprice()
		{	return price;	}
};
class JuniorSuite : public Room//Junior Suite is child of room
{
	public:
		void setbalance()//setting balance
		{
			type = 3;
			price = 2000;
			empty = true;
		}
		int getprice()
		{	return price;	}
};
class Suite : public Room//suite is child of room
{
	public:
		void setbalance()//setting balance
		{
			type = 4;
			price = 5000;
			empty = true;
		}
		int getprice()
		{	return price;	}
};

void DisplayMenu()//Display Function For Displaying Menu
{
	cout<<"\t\t\t\t(Main Menu)"<<endl;
	cout<<"->Press (1)  Reserve a Room"<<endl;
	cout<<"->Press (2)  Checkin a Visitor"<<endl;
	cout<<"->Press (3)  View Reseved Rooms"<<endl;
	cout<<"->Press (4)  See Detail Report"<<endl;
	cout<<"->Press (5)  Exit"<<endl;
	cout<<"->Press (6)  Read data from file"<<endl;
	cout<<"->Press (7)  Check-out"<<endl;
}
void report(int num_cust ,int all_S ,int all_M ,int all_Sp ,int all_Js ,int all_Su)//function that displays report
{
	cout<<"\n\t\t\t\t ________";
	cout<<"\n\t\t\t\t| REPORT |";
	cout<<"\n\t\t\t\t|________|"<<endl;
	cout<<endl;
	
	cout<<" Number Of People Who Have Checked-In OR Reserved The Room : "<< num_cust <<endl;
	cout<<endl;
	
	cout<<" Number of rooms reserved(or having checked-in customers) : "<<num_cust<<endl;
	cout<<" Number of Standrd rooms reserved : "<<all_S<<endl;
	cout<<" Number of Moderate rooms reserved : "<<all_M<<endl;
	cout<<" Number of Seperior rooms reserved : "<<all_Sp<<endl;
	cout<<" Number of Junior Suite rooms reserved : "<<all_Js<<endl;
	cout<<" Number of Suite rooms reserved : "<< all_Su <<endl;
	cout<<endl;
	cout<<" Number of rooms empty : "<<250 - num_cust<<endl;
	cout<<" Number of Standrd rooms empty : "<<50 - all_S<<endl;
	cout<<" Number of Moderate rooms empty : "<<50 - all_M<<endl;
	cout<<" Number of Seperior rooms empty : "<<50 - all_Sp<<endl;
	cout<<" Number of Junior Suite rooms empty : "<<50 - all_Js<<endl;
	cout<<" Number of Suite rooms empty : "<<50 - all_Su<<endl;
}

void seeresrvedrooms(char P[5][50])//for displaying reserved rooms
{
	cout<<"\n\t\t\t _________________________";
	cout<<"\n\t\t\t| ROOMS RESERVED SECTION  |";
	cout<<"\n\t\t\t|_________________________|"<<endl;
	cout<<endl;
	
	for(int i = 0; i<5; i++)//tells abouut each floor
	{
		cout<<" Reseved Rooms At Floor "<< i + 1<<" are : ";
		for(int j = 0; j<50; j++)
		{
			if(P[i][j] == 'R')
			{	cout<< j + 1<<" , ";	}	 
		}
		cout<<endl;
	}
}

void standardroom(Standard &S , Customer &C , int S_floor , int S_room)//sets data members of standard
{
	
	S.floor = S_floor;
	S.number = S_room;
	S.setbalance(); 
	int rate = S.getprice();
	C.setfloor(S_floor); 
	C.setroom(S_room);
	C.setbalance(rate);
}

void moderateroom(Moderate &M, Customer &C , int M_floor , int M_room)//sets data members of moderate
{
	M.floor = M_floor;
	M.number = M_room;
	M.setbalance(); 
	int rate = M.getprice();
	C.setfloor(M_floor); 
	C.setroom(M_room);
	C.setbalance(rate);
}

void superiorroom(Superior &Sp, Customer &C , int Sp_floor , int Sp_room)//sets data members of superior
{
	Sp.floor = Sp_floor;
	Sp.number = Sp_room;
	Sp.setbalance(); 
	int rate = Sp.getprice();
	C.setfloor(Sp_floor); 
	C.setroom(Sp_room);
	C.setbalance(rate);
}

void juniorsuiteroom(JuniorSuite &Js, Customer &C , int Js_floor , int Js_room)//sets data members of junior suite
{
		Js.floor = Js_floor;
		Js.number = Js_room;
		Js.setbalance(); 
		int rate = Js.getprice();
		C.setfloor(Js_floor); 
		C.setroom(Js_room);
		C.setbalance(rate);	
}

void suiteroom(Suite &Su, Customer &C , int Su_floor , int Su_room)//sets data members of suite room
{
		Su.floor = Su_floor;
		Su.number = Su_room;
		Su.setbalance(); 
		int rate = Su.getprice();
		C.setfloor(Su_floor); 
		C.setroom(Su_room);
		C.setbalance(rate);	
}

void send_to_customer_checkin(fstream &customer , Customer &C, int num_customers)//file writing for checkin
{
		string str;
	
		customer<<"Data for customer "<< num_customers + 1<<endl;
		customer<<"Name : ";
		str = C.getfullName();
		for(int i=0 ; str[i] != '\0'; i++)
		{	customer<<str[i];	}
		
		customer<<" Age : "<<C.getage()<<" "<<endl;
		customer<<"Balance : "<<C.getbalance()<<" "<<endl;
		
		int gen = C.getgender();
		if(gen == 0)
		{	customer<<"Gender : Female"<<" "<<endl;	}
		else if(gen == 1)
		{	customer<<"Gender : Male"<<" "<<endl;	}
		
		customer<<"ID : "<<C.getidNumber()<<" "<<endl;
		
		int rmtype = C.getroomType();
		if(rmtype == 0)
		{	customer<<"RoomType : Standard"<<" "<<endl;	}
		else if(rmtype == 1)
		{	customer<<"RoomType : Moderate"<<" "<<endl;	}
		else if(rmtype == 2)
		{	customer<<"RoomType : Superior"<<" "<<endl;	}
		else if(rmtype == 3)
		{	customer<<"RoomType : Junior Suite"<<" "<<endl;	}
		else if(rmtype == 4)
		{	customer<<"RoomType : Suite"<<" "<<endl;	}
		
		customer<<"Floor : "<<C.getfloor() + 1<<" "<<endl;
		customer<<"Room Number : "<<C.getroomNumber() + 1<<endl;
		
		customer<<"Date : "<<C.Cc.getcheckinDate()<<"-";
		customer<<C.Cc.getcheckinMonth()<<"-";
		customer<<C.Cc.getcheckinYear()<<" ";
		customer<<"Days of Stay : "<<C.Cc.getdays()<<" "<<endl;
		customer<<"Customer Type : Check-In "<<endl;
		
		
		customer<<"\n\n\t -------------------------------------------- \t \n \n";
		cout<<"\t \t -------------------------------------- \t \t";
}

void send_to_customer_reserve(fstream &customer , Customer &C, int num_customers)//file writing for reserve
{
	string str;
	
	customer<<"Data for customer "<< num_customers + 1<<endl;
	str = C.getfullName();
	for(int i=0 ; str[i] != '\0'; i++)
	{	customer<<str[i];	}
	customer<<endl;
	
	customer<<"Age : "<<C.getage()<<" "<<endl;
	customer<<"Balance : "<<C.getbalance()<<" "<<endl;
	
	int gen = C.getgender();
	if(gen == 0)
	{	customer<<"Gender : Female"<<" "<<endl;	}
	else if(gen == 1)
	{	customer<<"Gender : Male"<<" "<<endl;	}
	
	customer<<"ID : "<<C.getidNumber()<<" "<<endl;
	
	int	rmtype = C.getroomType();
	if(rmtype == 0)
	{	customer<<"RoomType : Standard"<<" "<<endl;	}
	else if(rmtype == 1)
	{	customer<<"RoomType : Moderate"<<" "<<endl;	}
	else if(rmtype == 2)
	{	customer<<"RoomType : Superior"<<" "<<endl;	}
	else if(rmtype == 3)
	{	customer<<"RoomType : Junior Suite"<<" "<<endl;	}
	else if(rmtype == 4)
	{	customer<<"RoomType : Suite"<<" "<<endl;	}
	
	customer<<"Floor : "<<C.getfloor() + 1<<" "<<endl;
	customer<<"Room Number : "<<C.getroomNumber() + 1<<endl;
	
	customer<<"Date : "<<C.Rc.getday_of_reserving()<<"-";
	customer<<C.Rc.getmonth_of_reserving()<<"-";
	customer<<C.Rc.getyear_of_reserving()<<" "<<endl;
	customer<<"Days of Stay : "<<C.Rc.getreserving_for_days()<<" "<<endl;
	customer<<"Advance payement: "<<C.Rc.getadvance_payement()<<" "<<endl;
	customer<<"Customer Type : Reserve "<<endl;

	
	customer<<"\n\n\t -------------------------------------------- \t\n\n";
	cout<<"\t \t -------------------------------------- \t \t";
}

void send_to_room(fstream &room , int num_cust ,int all_S ,int all_M ,int all_Sp ,int all_Js ,int all_Su, char P[5][50])//sending room data
{
	room<<" Number Of People Who Have Checked-In OR Reserved The Room : "<< num_cust <<endl;
	room<<endl;
	
	room<<" Number of rooms reserved(or having checked-in customers) : "<<num_cust<<endl;
	room<<" Number of Standrd rooms reserved : "<<all_S<<endl;
	room<<" Number of Moderate rooms reserved : "<<all_M<<endl;
	room<<" Number of Seperior rooms reserved : "<<all_Sp<<endl;
	room<<" Number of Junior Suite rooms reserved : "<<all_Js<<endl;
	room<<" Number of Suite rooms reserved : "<< all_Su <<endl;
	room<<endl;
	room<<" Number of rooms empty : "<<250 - num_cust<<endl;
	room<<" Number of Standrd rooms empty : "<<50 - all_S<<endl;
	room<<" Number of Moderate rooms empty : "<<50 - all_M<<endl;
	room<<" Number of Seperior rooms empty : "<<50 - all_Sp<<endl;
	room<<" Number of Junior Suite rooms empty : "<<50 - all_Js<<endl;
	room<<" Number of Suite rooms empty : "<<50 - all_Su<<endl;
	room<<endl;
	
		for(int i = 0; i<5; i++)
	{
		room<<" Reseved Rooms At Floor "<< i + 1<<" are : ";
		for(int j = 0; j<50; j++)
		{
			if(P[i][j] == 'R')
			{	room<< j + 1<<" , ";	}	 
		}
		room<<endl;
	}
	room<<endl;
	room<<endl;
	for(int i = 0; i<5; i++)
	{
		room<<" Checked-In Rooms At Floor "<< i + 1<<" are : ";
		for(int j = 0; j<50; j++)
		{
			if(P[i][j] == 'C')
			{	room<< j + 1<<" , ";	}	 
		}
		room<<endl;
	}
}

void exiter()//displays during exiting
{
	cout<<"\n\t\t\t\t _______________"; 
	cout<<"\n\t\t\t\t| SYSTEM CLOSED |"; 
	cout<<"\n\t\t\t\t|_______________|"<<endl;	
	cout<<"\n\n Developed By:"; 
	cout<<"  Muhammad Shaffay (20i-2391)"; 
}

void exit()//exiting if rooms are full
{
	int option = 0;
	
	while(option != 5)
	{
		cout<<"Press 5 to exit : ";
		cin>>option;
	}
}

int main()
{
//Variables declarations	
	int option = 0, num_customers = 0 , room_type = 0; 
	int S_room = 0 , S_floor = 0 , M_room = 0 , M_floor = 0 ;
	int Sp_room = 0 , Sp_floor = 0 , Js_room = 0 , Js_floor = 0 ;
	int Su_room = 0 , Su_floor = 0;
	int rate ;
	int overall_S = 0, overall_M = 0, overall_Sp = 0, overall_Js = 0, overall_Su = 0, overall_reserve = 0, overall_checkin = 0;
	char reservedrooms[5][50] , indexreserverom = 0 , indexreserveflor = 0;
	char checkedinroom[5][50] , indexcheckroom = 0 , indexcheckflor = 0;
	
	for(int i=0 ; i<5; i++)
	{
		for(int j=0; j<50; j++)
		{	reservedrooms[i][j] = 'E';	}
	}
	
//Classes declarations
	Customer C[250];
	Standard S[5][10];
	Moderate M[5][10];
	Superior Sp[5][10];
	JuniorSuite Js[5][10];
	Suite Su[5][10];
	
//display
	cout<<"\n\t\t\t ___________________________";
	cout<<"\n\t\t\t| HOTEL MANAGEMENT PROJECT  |";
	cout<<"\n\t\t\t|___________________________|";
	cout<<"\n\n\t\tDeveloped By:";
	cout<<"\t Muhammad Shaffay";

    cout<<"\n\n\t\t---------->(HOTEL MANAGEMENT SYSTEM)<----------"<<endl;;
	
	fstream customer;//customer file handling
	customer.open("Customer.txt" , ios::app);
	
	fstream room;//room file handling
	room.open("room.txt" , ios::out);
	
	
	while(option != 5)
	{
//Taking Menu Options
		cout<<endl;		
		DisplayMenu();
		cout<<"Select Option : ";
		cin>>option;
		cout<<endl;
		
		if(option == 5) //Exiting
		{
			if(!room)
			{	cout<<"Room File cannot be accessed"<<endl;	}
			else
			{	 send_to_room(room , num_customers , overall_S , overall_M , overall_Sp , overall_Js , overall_Su , reservedrooms);	}	
		exiter();  customer.close(); room.close(); return 0;	
		}
		
		else if(option == 1) //Reserve A Room
		{
			int opt = 0;
			
			overall_reserve++;
			cout<<"\t\tReserve Customer Section Can Be Aapproached \n"<<endl;
			cout<<" Customer Number : "<<num_customers + 1<<endl;
			
			while(opt != 1 && opt != 2)
			{
					cout<<" Are you an (1) Old customer or (2) New customer : ";
					cin>>opt;
			}
			if(opt == 1)
			{
				int custnum = 0 , ide = 0;
				cout<<" Enter customer number you were in the past : ";
				cin>>custnum;
				
				cout<<" Enter your ID for verification : ";
				cin>>ide;
				
				if(ide == C[custnum].getidNumber())
				{
					C[num_customers] = C[custnum];
					cout<<"\n  (0) Standard \n  (1) Moderate \n  (2) Superior \n  (3) Junior Suite \n  (4) Suite "<<endl;
					cout<<" Enter Room Type You Want To Reserve : ";
					cin>>room_type;
					C[num_customers].Rc.setreserve();
				}
				else
				{
					cout<<" Your ID not found in record, You are a new customer\n"<<endl;
					C[num_customers].setvalues();//Taking Customer Details
					room_type = C[num_customers].getroomType();
					C[num_customers].Rc.setreserve();
				}
				
			}
			else 
			{
				C[num_customers].setvalues();//Taking Customer Details
				room_type = C[num_customers].getroomType();
				C[num_customers].Rc.setreserve();
			}
			
			if(room_type == 0)//if standard
			{
				standardroom(S[S_floor][S_room], C[num_customers] , S_floor , S_room);
					 	 
				if(S_room == 9)
				{
					if(S_floor < 4)
					{	S_floor++;	S_room = 0; indexreserveflor++; indexreserverom = 0; reservedrooms[indexreserveflor][indexreserverom] = 'R';}
					else 
					{	cout<<" No More Standard Rooms Available"<<endl; exit(); return 0;	}	 	
				}
				else
				{	S_room++; reservedrooms[indexreserveflor][indexreserverom++] = 'R';	}
				overall_S++;
			}
			else if(room_type == 1)//if moderate
			{
				moderateroom(M[M_floor][M_room], C[num_customers] , M_floor , M_room);
					 	 
				if(M_room == 9)
				{
					if(M_floor < 4)
					{	M_floor++;	M_room = 0;	indexreserveflor++; indexreserverom = 0; reservedrooms[indexreserveflor][indexreserverom] = 'R';}
					else 
					{	cout<<"No More Moderate Rooms Available"<<endl;	exit(); return 0;	}
				}
				else 
				{	M_room++;  reservedrooms[indexreserveflor][indexreserverom++] = 'R';	}
				overall_M++;
				}
			else if(room_type == 2)//if superior
				{
					superiorroom(Sp[Sp_floor][Sp_room], C[num_customers] , Sp_floor , Sp_room);
					  
					 if(Sp_room == 9)
					 {
					 	if(Sp_floor < 4)
					 	{	Sp_floor++;	Sp_room = 0; indexreserveflor++; indexreserverom = 0; reservedrooms[indexreserveflor][indexreserverom] = 'R';}
						else 
						{	cout<<"No More Superior Rooms Available"<<endl;	exit(); return 0;	}
					 }
					 else 
					 {	Sp_room++; reservedrooms[indexreserveflor][indexreserverom++] = 'R';	}
					 overall_Sp++;
				}
			else if(room_type == 3)//if junior suite
				{
					juniorsuiteroom(Js[Js_floor][Js_room], C[num_customers] , Js_floor , Js_room);
					  
					 if(Js_room == 9)
					 {
					 	if(Js_floor < 4)
					 	{	Js_floor++;	Js_room = 0; indexreserveflor++; indexreserverom = 0; reservedrooms[indexreserveflor][indexreserverom] = 'R';}
						else 
						{	cout<<"No More Junior Suites Available"<<endl; exit(); return 0;	}
					 }
					 else 
					 {	Js_room++; reservedrooms[indexreserveflor][indexreserverom++] = 'R';	}
					 overall_Js++;
				}
		else if(room_type == 4)//if suite
				{
					suiteroom(Su[Su_floor][Su_room], C[num_customers] , Su_floor , Su_room);
					  
					 if(Su_room == 9)
					 {
					 	if(Su_floor < 4)
					 	{	Su_floor++;	Su_room = 0; indexreserveflor++; indexreserverom = 0; reservedrooms[indexreserveflor][indexreserverom] = 'R';}
						else 
						{	cout<<"No More Suites Available"<<endl; exit();	return 0;	}
					 }
					 else 
					{	Su_room++; reservedrooms[indexreserveflor][indexreserverom++] = 'R';	}
					 overall_Su++;
				} 
				
				int bal = C[num_customers].getbalance() * C[num_customers].Rc.getreserving_for_days();
				C[num_customers].setbalance(bal);
				if(!customer)
				{
					cout<<"Customer section cannot be approached due to uncertain reasons"<<endl;
				}
				else
				{		
					send_to_customer_reserve(customer , C[num_customers] , num_customers);
				}
				num_customers++;
		}
		else if(option == 2)//if checkin customer
		{
			int opt = 0;
			cout<<"\t\tCheck-In Customer section can be approached \n"<<endl;
			cout<<" Customer Number : "<<num_customers + 1<<endl;
			
			while(opt != 1 && opt != 2)
			{
					cout<<" Are you an (1) Old customer or (2) New customer : ";
					cin>>opt;
			}
			if(opt == 1)
			{
				int custnum = 0 , ide = 0;
				cout<<" Enter customer number you were in the past : ";
				cin>>custnum;
				
				cout<<" Enter your ID for verification : ";
				cin>>ide;
				
				if(ide == C[custnum].getidNumber())
				{
					C[num_customers] = C[custnum];
					cout<<"\n  (0) Standard \n  (1) Moderate \n  (2) Superior \n  (3) Junior Suite \n  (4) Suite "<<endl;
					cout<<" Enter Room Type You Want To Reserve : ";
					cin>>room_type;
					C[num_customers].Cc.setvalues();
				}
				else
				{
					cout<<" Your ID not found in record, You are a new customer\n"<<endl;
					C[num_customers].setvalues();//Taking Customer Details
					room_type = C[num_customers].getroomType();
					C[num_customers].Cc.setvalues();
				}
			}
			
			else 
			{
				C[num_customers].setvalues();//Taking Customer Details
				room_type = C[num_customers].getroomType();
				C[num_customers].Cc.setvalues();
			}
			
			if(room_type == 0)//for standard
			{
				standardroom(S[S_floor][S_room], C[num_customers] , S_floor , S_room);
					 	 
				if(S_room == 9)
				{
					if(S_floor < 4)
					{	S_floor++;	S_room = 0;	indexreserveflor++; indexreserverom = 0; reservedrooms[indexreserveflor][indexreserverom] = 'C';}
					else 
					{	cout<<"No More Standard Rooms Available"<<endl; exit(); return 0;	}	 	
				}
				else 
				{ reservedrooms[indexreserveflor][indexreserverom++] = 'C'; S_room++;}
				overall_S++;
			}
			else if(room_type == 1)//for moderate
			{
				moderateroom(M[M_floor][M_room], C[num_customers] , M_floor , M_room);
					 	 
				if(M_room == 9)
				{
					if(M_floor < 4)
					{	M_floor++;	M_room = 0;	indexreserveflor++; indexreserverom = 0; reservedrooms[indexreserveflor][indexreserverom] = 'C';}
					else 
					{	cout<<"No More Moderate Rooms Available"<<endl;	exit(); return 0;	}
				}
				else 
					{ reservedrooms[indexreserveflor][indexreserverom++] = 'C'; M_room++;}
				overall_M++;
				}
			else if(room_type == 2)//for superior
				{
					superiorroom(Sp[Sp_floor][Sp_room], C[num_customers] , Sp_floor , Sp_room);
					  
					 if(Sp_room == 9)
					 {
					 	if(Sp_floor < 4)
					 	{	Sp_floor++;	Sp_room = 0; indexreserveflor++; indexreserverom = 0; reservedrooms[indexreserveflor][indexreserverom] = 'C';}
						else 
						{	cout<<"No More Superior Rooms Available"<<endl; exit(); return 0;	}
					 }
					 else 
					 { reservedrooms[indexreserveflor][indexreserverom++] = 'C'; Sp_room++;}
					 overall_Sp++;
				}
			else if(room_type == 3)//for junior suite
				{
					juniorsuiteroom(Js[Js_floor][Js_room], C[num_customers] , Js_floor , Js_room);
					  
					 if(Js_room == 9)
					 {
					 	if(Js_floor < 4)
					 	{	Js_floor++;	Js_room = 0; indexreserveflor++; indexreserverom = 0; reservedrooms[indexreserveflor][indexreserverom] = 'C';}
						else 
						{	cout<<"No More Junior Suites Available"<<endl; exit(); return 0;	}
					 }
					 else 
					 { reservedrooms[indexreserveflor][indexreserverom++] = 'C'; Js_room++;}
					 overall_Js++;
				}
			else if(room_type == 4)//for suite
				{
					suiteroom(Su[Su_floor][Su_room], C[num_customers] , Su_floor , Su_room);
					  
					 if(Su_room == 9)
					 {
					 	if(Su_floor < 4)
					 	{	Su_floor++;	Su_room = 0; indexreserveflor++; indexreserverom = 0; reservedrooms[indexreserveflor][indexreserverom] = 'C';}
						else 
						{	cout<<"No More Suites Available"<<endl; exit(); return 0;	}
					 }
					 else 
					 { reservedrooms[indexreserveflor][indexreserverom++] = 'C'; Su_room++;}
					 overall_Su++;
				}
				
				int balanc = C[num_customers].getbalance() * C[num_customers].Cc.getdays();
				C[num_customers].setbalance(balanc);
				if(!customer)
				{
					cout<<"Customer section cannot be approached due to uncertain reasons"<<endl;
				}
				else
				{		send_to_customer_checkin(customer , C[num_customers] , num_customers);	}
				num_customers++;
		}
		else if(option == 3)//for reserved rooms
				{	seeresrvedrooms(reservedrooms);	}
		else if(option == 4)//for report
				{	report(num_customers , overall_S , overall_M , overall_Sp , overall_Js , overall_Su);	}
		else if(option == 6)
		{
			string values;
			fstream input;
			input.open("Customer.txt" , ios::in);
			
			if(!input)
			{
				cout<<"Cannot be opened"<<endl;
				return 0;
			}
			
			
			input>>values;
			while ( !input.eof() ) 
			{ 
      		cout << " " << values << " ";
   	   		input >> values; 
   			}
   input.close();
		}
		else if(option == 7)
		{
			int rn , fn , rt;
			cout<<"\n\t\t\t ___________________";
			cout<<"\n\t\t\t| Checkout Section |";
			cout<<"\n\t\t\t|__________________|";
			
			cout<<endl;
			cout<<" Enter your room number : ";
			cin>>rn;
			
			cout<<" Enter floor number : ";
			cin>>fn;
			
			while (rt < 0 || rt > 5)
			{
				cout<<"\n  (0) Standard \n  (1) Moderate \n  (2) Superior \n  (3) Junior Suite \n  (4) Suite \n Enter room type : ";
				cin>>rt;
			}
			
			
			if(rt == 0)
			{
				S[fn][rn].setempty(0);
			}
			else if(rt == 1)
			{
				M[fn][rn].setempty(0);
			}
			else if(rt == 2)
			{
				Sp[fn][rn].setempty(0);
			}
			else if(rt == 3)
			{
				Js[fn][rn].setempty(0);
			}
			else if(rt == 4)
			{
				Su[fn][rn].setempty(0);
			}
			cout<<"\t\t\t\t(Done)"<<endl;
		}
	}
	
	return 0;
}
