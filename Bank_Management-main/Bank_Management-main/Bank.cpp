#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include<string.h>
#include<windows.h>
#include<ctime>
#include<conio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
char pw[25],p;
int ip=0;
class bank
{
	private:
		string name,accno,pass,address,phno;
		float amt;
		int i,j,k,tm,i1=0;
		time_t t;
		struct tm *tt;
		ifstream ifile;
		ofstream ofile;
	public:
		void create();
		void replace(string,string,string,string,string,float bal);
		void valid(string);
		void display(string);
		void balance();
		void displayall();
		void deposit();
		void withdraw();
		void modify();
		void load(string fname);
		int check(string);
		void disp();
		void removeacc();
		void removeall();
		void trans();
};
void bank :: trans()
{
	string fname,file,temp;
	cout<<" Enter the account number : ";
	cin>>fname;
	if(check(fname)==0)
	{
		return;
	}
	ifstream fi;
	fi.open(fname+".txt");
	getline(fi,accno);
	getline(fi,pass);
	getline(fi,name);
	getline(fi,phno);
	getline(fi,address);
	getline(fi,file);
	amt = stof(file);
	cout<<"\n\nThe Balance is "<<amt<<endl;
	cout<<"\n\n\t The Transaction History is : "<<endl;
	cout<<"------------------------------------------\n";
	while(!fi.eof())
	{
		if(getline(fi,temp))
		{
			cout<<"\n\n\t"<<temp;
			Sleep(500);
		}
	}
	system("pause");
}
void bank :: removeall()
{
	ifstream filein;
	filein.open("Account_Numbers.txt");
	if(!filein.is_open())
	{
		Sleep(200);
		system("cls");
		system("color 0C");
		cout<<"\n\n\n\t\t\t\tSorry there are No records till now "<<endl;
		Sleep(2000);
		system("cls");
		system("color 0F");
		return;
	}
	string file,accno;
	while(!filein.eof())
	{
		if(getline(filein,accno))
		{
			file=accno+".txt";
			remove(file.c_str());
		}
	}
	filein.close();
	remove("Account_Numbers.txt");
	cout<<"\n\n\t All Records are Deleted Successfully ......."<<endl;
	Sleep(2000);
}
void bank :: removeacc()
{
	string fname;
	cout<<" Enter the account number : ";
	cin>>fname;
	if(check(fname)==0)
	{
		return;
	}
	string filename= fname+".txt";
	int res=remove(filename.c_str());
	if(res==0)
	{
		Sleep(800);
		system("cls");
		system("color 0A");
		cout<<"\n\n\n\n\n\n\tFile Deleted Successfully......."<<endl;
		Sleep(1500);
	}
	else
	{
		Sleep(800);
		system("cls");
		system("color 0C");
		cout<<"\n\n\n\n\n\n\tAccount Number Does not Exist......."<<endl;
		Sleep(2000);
		system("cls");
		system("color 0F");
	}
	ifstream filein;
	filein.open("Account_Numbers.txt");
	string accno,acns[50];
	int i=-1;
	while(!filein.eof())
	{
		if(getline(filein,accno))
		{
			if(accno!=fname)
			{
				i+=1;
				acns[i]=accno;
			}
		}
	}
	ofstream fileout;
	fileout.open("Account_Numbers.txt");
	int j=0;
	while(i>=0)
	{
		fileout<<acns[j]<<endl;
		j++;
		i--;
	}
}
void bank :: disp()
{
	ifstream fi;
	string acno;
	string file;
	cout<<" Enter the Account Number : ";
	cin>>acno;
	file=acno+".txt";
	fi.open(file.c_str());
	if(!fi.is_open())
	{
		Sleep(1000);
		system("cls");
		system("color 0C");
		cout<<" \n\n\n\n\tSorry We did't Find any Record on this Account Number ";
		Sleep(3000);
		system("cls");
		return;
	}
	if(check(acno)==0)
	{
		return;
	}
	system("cls");
	display(acno);
	system("pause");
	system("cls");
}
int bank :: check(string str)
{
	str +=".txt";
	int t=0;
	ifstream fi;
	fi.open(str);
	if(!fi.is_open())
	{
		Sleep(1000);
		system("cls");
		system("color 0C");
		cout<<" \n\n\n\n\tSorry We did't Find any Record on this Account Number ";
		Sleep(3000);
		system("cls");
		return 0;
	}
	string s,pas;
	getline(fi,s);
	getline(fi,s);
	
b:	ip=0;
	system("color 0B");
	cout<<"\nEnter the Password : \n";
	while((p=getch())!=13)
	{
		cout<<"*";
		pw[ip++]=p;
	}
	pas=pw;
//	cin>>pas;
	if(s==pas)
	return 1;
	else
	{
		t++;
		system("color 0C");
		cout<<"\n\n Wrong Password !!";
		cout<<"\n Please Reenter it : ";
		Sleep(2000);
		system("cls");
		system("color 0F");
		if(t==3)
		{
			system("color 0C");
			cout<<"\n\nToo Many Unsuccessfull Attempt ";
			Sleep(2000);
			system("cls");
			system("color 0F");
			return 0;
		}
		goto b;
	}
	
}
void bank :: load(string fname)
{
	ifstream fi;
	fname = fname+".txt";
	fi.open(fname.c_str());
	string file;
	getline(fi,accno);
	getline(fi,pass);
	getline(fi,name);
	getline(fi,phno);
	getline(fi,address);
	getline(fi,file);
	amt = stof(file);
}
void bank :: valid(string str)
{
	ifstream fi;
	string file;
	file = str+".txt";
	fi.open(file.c_str());
	if(!fi.is_open()&&fi.fail())
	{
		return;
	}
	else
	{
		tm++;
		if(tm==3)
		{
			cout<<"\a";
			cout<<"The Bank Account exists !!\nPlease Enter the Diffrent Details : ";
			return;
		}
		system("cls");
		cout<<"\a";
		cout<<"The Bank Account exists !!\n\nPlease Enter the Diffrent Number : ";
		cin>>accno;
		valid(accno);
	}
}
void bank :: create()
{
	ofstream of;
	string file;
tenac:	cout<<"\nEnter the 10 Digit Account Number : ";
	cin>>accno;
	if(accno<10)
	{
		cout<<" Please ";
		goto tenac;
	}
	tm=0;
	valid(accno);
	file = accno + ".txt";
	if(tm>=3)
	{
		return;
	}
	cout<<"\nSet the Password : \n";
	ip=0;
	while((p=getch())!=13)
	{
		cout<<"*";
		pw[ip++]=p;
	}
	pass=pw;
	cout<<"\nEnter the Name : \n";
	char n[50];
	cin.ignore();
	cin.getline(n,sizeof(n));
	name = n;
	cout<<"\nEnter the Phone Number : ";
	cin>>phno;
	cout<<"\nEnter the Address : ";
	char addrs[50];
	cin.ignore();
	cin.getline(addrs,sizeof(addrs));
	address=addrs;
at:	cout<<" \nPlease Deposit some Minimum Amount : ";
	cin>>amt;
	if(amt<500)
	{
		cout<<" Please Enter Amount Greater than 500 Rs. \n";
		goto at;
	}
	of.open(file.c_str());
	ofile.open("Account_Numbers.txt",ios::app);
	ofile<<accno<<endl;
	ofile.close();
	replace(accno,pass,name,phno,address,amt);
	Sleep(750);
	system("cls");
	cout<<"\n\n\tYour Account is Created Successfully :) ";
	Sleep(3500);
	system("cls");
}
void bank :: modify()
{
	ifstream fi;
	cout<<" Enter the Account Number : ";
	cin>>accno;
	string file = accno+".txt";
	fi.open(file.c_str());
	if(!fi.is_open())
	{
		Sleep(1000);
		system("cls");
		cout<<" \n\n\n\n\tSorry We did't Find any Record on this Account Number ";
		Sleep(2250);
		system("cls");
		return;
	}
	Sleep(750);
	system("cls");
	cout<<" The Current Details are : \n\n";
	display(accno);
	if(check(accno)==0)
	{
		return;
	}
	Sleep(1000);
	system("cls");
	cout<<"-------------------------------------------\n"<<endl;
	cout<<"********** Re-Enter the Details **********  ";
	cout<<"     -------------------------------------------              \n\n";
	cout<<"Enter the Name of Bank Account Holder : ";
	char n[50];
	cin.ignore();
	cin.getline(n,50);
	name=n;
	cout<<"\nEnter the Phone Number : ";
	cin>>phno;
	cout<<"\nEnter the Address : ";
	char ads[50];
	cin.ignore();
	cin.getline(ads,50);
	address=ads;
	replace(accno,pass,name,phno,address,amt);
	Sleep(500);
	system("cls");
	cout<<"\n\n\t\t Details are Updated Successfully \n";
	Sleep(1000);
	system("cls");
}
void bank :: replace(string ano,string p,string n,string phone,string adrs,float bal)
{
	string file = ano+".txt";
	ifstream fi;
	fi.open(file);
	int i=0;
	string temp,t[50];
	getline(fi,accno);
	getline(fi,pass);
	getline(fi,name);
	getline(fi,phno);
	getline(fi,address);
	getline(fi,file);
	amt = stof(file);
	while(!fi.eof())
	{
		if(getline(fi,temp))
		{
			t[i]=temp;
			i++;
		}
	}
	i--;
	i--;
	int j=0;
	ofstream of;
	file = ano+".txt";
	of.open(file.c_str(),ios::out);
	of<<ano<<endl<<p<<endl<<n<<endl<<phone<<endl<<adrs<<endl<<bal<<endl;
	while(i>=0)
	{
		of<<t[j]<<endl;
		j++;
		i--;
	}
	return;
}
void bank :: deposit()
{
	float dep;
	cout<<" Enter the Account Number : ";
	cin>>accno;
	string fname = accno+".txt";
	ifstream fi;
	fi.open(fname.c_str());
	if(!fi.is_open())
	{
		Sleep(1000);
		system("cls");
		cout<<" \n\n\n\n\tSorry We did't Find any Record on this Account Number ";
		Sleep(3000);
		system("cls");
		return;
	}
	load(accno);
	cout<<" Enter the Amount to Deposit (less than 1,00,000rs per Transaction) : ";
	cin>>dep;
	if(dep>=100000)
	{
		cout<<" \n\n\tThe Amount you have Entered is out of Limit to Deposit "<<endl;
		return;
	}
	if(check(accno)==0)
	{
		return;
	}
	amt = amt+dep;
	replace(accno,pass,name,phno,address,amt);
	string depdetails;
	time(&t);
	tt = localtime(&t);
	depdetails=to_string(dep)+" was Deposited on "+asctime(tt);
	ofstream of ;
	accno =accno+".txt";
	of.open(accno,ios::app);
	of<<depdetails<<endl;
	Sleep(500);
	system("cls");
	cout<<"\n\n\n\t\t"<<dep<<" is Successfully Deposited \n";
	Sleep(1000);
	system("cls");
}
void bank :: withdraw()
{
	float wit;
	int tm=0;
	cout<<" Enter the Account Number : ";
	cin>>accno;
	string fname = accno+".txt";
	ifstream fi;
	fi.open(fname.c_str());
	if(!fi.is_open())
	{
		Sleep(1000);
		system("cls");
		system("color 74");
		cout<<" \n\n\n\n\tSorry We did't Find any Record on this Account Number ";
		Sleep(3000);
		system("cls");
		return;
	}
	load(accno);
	if(check(accno)==0)
	{
		return;
	}
a:	cout<<" Enter the withdrawing Amount (less than 70,000rs per Transaction) : ";
	cin>>wit;
	if(wit>=70000)
	{
		cout<<" \n\n\tThe Amount you have Entered is out of Limit to Withdraw "<<endl;
		return;
	}
	if((amt-wit)<=0)
	{
		system("cls");
		system("color 74");
		cout<<"\n\n\t\t\t\tWarning !!\n";
		cout<<"\n You have Insufficient Balance Amount \n";
		cout<<" Please re-enter the Withdrawing Amount\n Your Balance Amount is "<<amt<<endl;
		tm++;
		if(tm==3)
		{
			system("cls");
			cout<<" Sorry Many you have done with Wrong Atempts "<<endl;
			Sleep(2000);
			system("cls");
			return;
		}
		goto a;
	}
	int ch;
	if((amt-wit)<=500&&(amt-wit)>=0)
	{
		system("cls");
		system("color 0C");
		cout<<"\n\n\t\t\t\tWarning !!\n";
		cout<<"\n\t After Withdrawing , Balance Amount will Go bellow 500 \n";
		cout<<"\n\t Do you want to continue Withdraw (1/0) : ";
		cin>>ch;
		if(ch==0)
		return;
	}
	else
	{
		amt = amt - wit;
	}
	if(ch==1)
	amt = amt-wit;
	replace(accno,pass,name,phno,address,amt);
	Sleep(500);
	system("cls");
	system("color 0A");
	cout<<"\n\n\n\t\t"<<wit<<" is Withdrawn Successfully \n";
	Sleep(1000);
	system("cls");
	string depdetails;
	time(&t);
	tt = localtime(&t);
	depdetails=to_string(wit)+" was Withdrawn on "+asctime(tt);
	ofstream of ;
	accno =accno+".txt";
	of.open(accno,ios::app);
	of<<depdetails<<endl;
}
void bank :: display(string str)
{
	ifstream fi;
	string c;
	string file=str+".txt";
	fi.open(file.c_str());
	ifstream f;
	f.open("Account_Numbers.txt");
	if(f.is_open()&&!fi.is_open())
	{
		cout<<"\n\t The Records of  "<<str<<"  are Deleted "<<endl;
		Sleep(700);
		return;
	}
	load(str);
	system("color 0B");
	cout<<"\n *************Details of "<<name<<"********************"<<endl;
	cout<<"       -------------------------------------------------              \n\n";
	cout<<"\n\t\t Account Number : "<<accno<<endl;
	cout<<"\n\t\t Name of Account Holder : "<<name<<endl;
	cout<<"\n\t\t Phone Number : "<<phno<<endl;
	cout<<"\n\t\t Address : "<<address<<endl;
	cout<<"\n\t\t Balance Amount : "<<amt<<endl<<endl;
	Sleep(500);
}
void bank :: displayall()
{
	ifstream f;
	f.open("Account_Numbers.txt");
	if(!f.is_open())
	{
		Sleep(200);
		system("cls");
		system("color 0C");
		cout<<"\n\n\n\t\t\t\tSorry there are No records till now "<<endl;
		Sleep(2000);
		system("cls");
		system("color 0F");
		return;
	}
	string acnos;
	int i=0;
	while(!f.eof())
	{
		if(getline(f,acnos))
		display(acnos);
	}
	system("pause");
}
void bank :: balance()
{
	ifstream fi;
	string pas;
	cout<<" Enter the Account Number : ";
	cin>>accno;
	string file = accno+".txt";
	fi.open(file.c_str());
	if(!fi.is_open())
	{
		Sleep(1000);
		system("cls");
		cout<<" \n\n\n\n\tSorry We did't Find any Record on this Account Number ";
		Sleep(3000);
		system("cls");
		return;
	}
	load(accno);
	if(check(accno)==0)
	{
		return;
	}
	Sleep(700);
	system("cls");
	system("color 0A");
	cout<<"\n\n\n\t\tThe Balance Amount is "<<amt<<endl;
	Sleep(2000);
	system("cls");
}
int main()
{
	bank b1;
	int ch;
	string acno,cp;
	string BP="NAVEED";
	Sleep(100);
	system("color B0");
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t W  E  L  C  O  M  E     T  O     B  I  T  M    B  A  N  K";
	Sleep(2000);
	system("cls");
	do{
		system("cls");
		system("color 0E");
		cout<<"\n\n";
		time_t t;
		struct tm *tt;
		time(&t);
		tt = localtime(&t);
		cout<<"                        "<<asctime(tt)<<endl<<endl;
		cout<<" Enter 1: To Create An Account \n"<<endl;
		cout<<" Enter 2: To Modify An Account \n"<<endl;
		cout<<" Enter 3: To Deposit the Amount \n"<<endl;
		cout<<" Enter 4: To Withdraw the Amount \n"<<endl;
		cout<<" Enter 5: To Show the Balance \n"<<endl;
		cout<<" Enter 6: To Show the Details \n"<<endl;
		cout<<" Enter 7: To Show the Details of all the Bank Account Holders \n"<<endl;
		cout<<" Enter 8: To Delete/Close an Account \n"<<endl;
		cout<<" Enter 9: To Delete All the Records of Bank \n"<<endl;
		cout<<" Enter 10: To Display the Transaction of an Account Holder \n"<<endl;
		cout<<" Enter 11: To Exit From the Application \n"<<endl;
		cout<<"\n\tWHAT SERVICE DO YOU WANT US TO OFFER YOU : ";
		cin>>ch;
		Sleep(500);
		system("cls");
		switch(ch)
		{
			case 1: b1.create();
					break;
			case 2: b1.modify();
					break;		
			case 3: b1.deposit();
					break;
			case 4: b1.withdraw();
					break;
			case 5: b1.balance();
					break;
			case 6: b1.disp();
					break;
			case 7: cout<<" Enter the Bank Password : ";
					ip=0;
					p=' ';
					while((p=getch())!=13)
					{
						cout<<"*";
						pw[ip++]=p;
					}
					cp=pw;
					if(cp==BP)
					b1.displayall();
					else
					{
						cout<<" \n\t Wrong Password";
						Sleep(2000);
					}
					break;
			case 8: b1.removeacc();
						break;
			case 9: cout<<" Enter the Bank Password : ";
					ip=0;
					p=' ';
					while((p=getch())!=13)
					{
						cout<<"*";
						pw[ip++]=p;
					}
					cp=pw;
					if(cp==BP)
					{
						b1.removeall();
					}
					else
					{
						cout<<" \n\t Wrong Password";
						Sleep(2000);
					}
						break;
			case 10: b1.trans();
					break;
			case 11: Sleep(500);
					system("cls");
					system("color 1E");
					cout<<"\n\n\n\n\t\t\t\tT H A N K    Y O U"<<endl;
					Sleep(1200);
					system("cls");
					system("color 0F");
					break;
			default : cout<<" Invalid Input "<<endl;
					Sleep(1500);
		}
	}while(ch!=11);
}