#include<iostream>
#include<stdio.h>
#include<fstream>
#include<conio.h>
#include<string>
#include<sys/time.h>
using namespace std;
class bank{
    private:
    
    float balance;
    string id,password,name,fname,address,phone,pin;
    public:
    void menu();
    void bank_management();
    void new_user();
    void old_user();
    void deposit();
    void withdraw();
    void transfer();
    void payment();
    void search();
    void edit();
    void del();
    void show_records();
    void show_payment();
    void user_balance();
    void withdraw_atm();
    
};
void introduction(){
	cout<<"\n\n\n\n\n\t\t\t";
	for(int i=1;i<=60;i++)
		cout<<"*";
	cout<<"\n\t ";
	for(int i=1;i<=58;i++)
		cout<<"*";
	cout<<"\n\t ";
	for(int i=1;i<=56;i++)
		cout<<"*";
	cout<<"\n\n\t\t Bank and ATM Management System\n\n\t\t\t\t Project By K Haritha \n\n\t  ";
	for(int i=1;i<=56;i++)
		cout<<"*";
	cout<<"\n\t ";
	for(int i=1;i<=58;i++)
		cout<<"*";
	cout<<"\n\t ";
	for(int i=1;i<=60;i++)
		cout<<"*";
	getch();
	system("cls");

	
}
void bank::menu(){
    p:
    system("cls");
    cout<<"\n\n\t\t\tControl Panel";
    cout<<"\n\n 1. Bank Management";
    cout<<"\n 2. Exit";
    cout<<"\n\n Enter your choice:";
    int choice;
    char ch;
    string pin,password,email;
    cin>>choice;
    switch(choice){
        case 1:
        system("cls");
        cout<<"\n\n\t\tLogin Account";
        cout<<"\n\n Email:";
        cin>>email;
        cout<<"\n\n\t\t PinCode: ";
        for(int i=1;i<=6;i++){
            ch=getch();
            pin+=ch;
            cout<<"*";
        }
        cout<<"\n\n Password:";
         for(int i=1;i<=6;i++){
            ch=getch();
            password+=ch;
            cout<<"*";
        }
        if(email=="harizz2307@gmail.com" && pin=="123456" && password=="123456"){
            bank_management();
        }
        else{
            cout<<"Invalid details";
        }
        break;
        
        case 2:
        exit(0);
        default:
        cout<<"\n\n Invalid Value...Please try again";
    
    }
    getch();
    goto p;
}
void bank::bank_management(){
     p:
    system("cls");
    cout<<"\n\n\t\t\tBank Management";
    cout<<"\n\n 1. New User";
    cout<<"\n 2.  Old User";
    cout<<"\n 3.  Deposit Option";
    cout<<"\n 4.  Withdraw Option";
    cout<<"\n 5.  Transfer Option";
    cout<<"\n 6.  Payment Option";
    cout<<"\n 7.  Search User Record";
    cout<<"\n 8.  Edit User Record";
    cout<<"\n 9.  Delete User Record";
    cout<<"\n 10. Show All Records";
    cout<<"\n 11. Payment All Records";
    cout<<"\n 12. Go Back";
    cout<<"\n\n Enter your choice:";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
        new_user();
        break;
        case 2:
        old_user();
        break;
        case 3:
        	deposit();
        break;
        case 4:
        	withdraw();
        break;
        case 5:
        	transfer();
        break;
        case 6:
        	payment();
        break;
        case 7:
        	search();
        break;
        case 8:
        	edit();
        break;
        case 9:
        	del();
        break;
        case 10:
        	show_records();
        break;
        case 11:
        	show_payment();
        break;
        case 12:
        menu();
        default:
        cout<<"\n\n Invalid Value...Please try again";

    }
    getch();
    goto p;

}

void bank::new_user(){
    p:
    system("cls");
    fstream file;
    int p;
    float b;
    string n,f,pa,a,ph,i;
    cout<<"\n\n\t\t\tAdd New User";
    cout<<"\n\n User ID: ";
    cin>>id;
    cout<<"\n\n\t\tName:";
    cin>>name;
    cout<<"\n\n Father Name:";
    cin>>fname;
    cout<<"\n\n\t\tAddress:";
    cin>>address;
    cout<<"\n\n Pin code(5 digit):";
    cin>>pin;
    cout<<"\n\n\t\tPassword: (5 digit)";
    cin>>password;
    cout<<"\n\n Phone No.:";
    cin>>phone;
    cout<<"\n\n\t\tCurrent Balance:";
    cin>>balance;
    file.open("bank.txt",ios::in);
    if(!file){
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";
        file.close();
    }
    else{
        file>>i>>n>>f>>a>>p>>pa>>ph>>b;
        while(!file.eof()){
            if(i==id){
                cout<<"\n\n User ID Already Exist";
                getch();
                goto p;
            }
             file>>i>>n>>f>>a>>p>>pa>>ph>>b;
        }
        file.close();
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";
        file.close();
    }
    cout<<"\n\n Account creation Successfull";
    
}
void bank::old_user(){
system("cls");
string t_id;
int found=0;
fstream file;
cout<<"\n\n\t\t\tUser already exist";
file.open("bank.txt",ios::in);
if(!file){
cout<<"\n\n File Opening error";
}
else{
cout<<"\n\n User ID: ";
cin>>t_id;
file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
while(!file.eof()){
if(t_id==id){
system("cls");
cout<<"\n\n\t\t\tRegistered User Account";
cout<<"\n\n User ID: "<<id<<" Pin : "<<pin<<" Password"<<password<<endl;
found++;
}
file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
}
file.close();
if(found==0)
cout<<"\n\n User ID cant be found";
}
}
void bank::deposit(){
	fstream file,file1;
	int found=0;
	string t_id;
	float dep;
	system("cls");
	cout<<"\n\n\t\tDeposit amount option";
	file.open("bank.txt",ios::in);
	if(!file){
		cout<<"\n\n File Opening Error...";
	}
	else{
		 cout<<"\n\n User ID: ";
cin>>t_id;
file1.open("bank1.txt",ios::app|ios::out);
file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
while(!file.eof()){
if(t_id==id){
cout<<"\n\n Amount for deposit";
cin>>dep;
balance+=dep;
file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";
found++;
cout<<"\n\n\t\tYour amount"<<dep<<" successfully deposited..";
}else{
	file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";
	
	
}
file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
}
file.close();
file1.close();
remove("bank.txt");
rename("bank1.txt","bank.txt");

if(found==0)
cout<<"\n\n User ID cant be found";
	}
}
void bank::withdraw(){
	fstream file,file1;
	int found=0;
	string t_id;
	float with;
	system("cls");
	cout<<"\n\n\t\tWithdraw amount option";
	file.open("bank.txt",ios::in);
	if(!file){
		cout<<"\n\n File Opening Error...";
	}
	else{
		 cout<<"\n\n User ID: ";
cin>>t_id;
file1.open("bank1.txt",ios::app|ios::out);
file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
while(!file.eof()){
if(t_id==id){
cout<<"\n\n Amount to withdraw";
cin>>with;
if(with<=balance){
	balance-=with;
file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";

cout<<"\n\n\t\tYour amount"<<with<<" successfully withdrawn..";
}
else{
	file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";
	cout<<"\n\n\t\t\tYour current balance "<<balance<<"is insufficient..";
}
found++;
}else{
	file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";
	
	
}
file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
}
file.close();
file1.close();
remove("bank.txt");
rename("bank1.txt","bank.txt");

if(found==0)
cout<<"\n\n User ID cant be found";
	}
}
void bank::transfer(){
	fstream file,file1;
	system("cls");
	string s_id,r_id;
	float amount;
	int found=0;
	cout<<"\n\n\t\t\tPayment transfer option";
	file.open("bank.txt",ios::in);
		if(!file){
		cout<<"\n\n File Opening Error...";
	}else{
		cout<<"\n\n sender user ID for transaction";
		cin>>s_id;
		cout<<"\n\n receiver user ID for transaction";
		cin>>r_id;
		cout<<"\n\n enter amount to transfer";
		cin>>amount;

		file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
		while(!file.eof()){
			if(s_id==id && amount>=balance){
				found++;
			}
			else if(r_id==id){
				found++; 
			}
			file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
		}
		file.close();
		if(found==2){
			file.open("bank.txt",ios::in);
					file1.open("bank.txt",ios::app|ios::out);
					
		file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
		while(!file.eof()){
			if(s_id==id ){
				balance-=amount;
				file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";
			}
			else if(r_id==id){
				balance+=amount;
				file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";
			} else{
				
				file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";
			}
			file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
		}
		file.close();
		file1.close();
		remove("bank.txt");
rename("bank1.txt","bank.txt");
cout<<"\n\n\t\t\t Transaction successfull";
					}else{
			cout<<"\n\n\t\tID's Invalid or  balance error";
		}
	}
	}
	void bank::payment(){
		system("cls");
		fstream file,file1;
		int found=0;
		float amount;
		string t_id,b_name;
		SYSTEMTIME x;
		cout<<"\n\n\t\t\tBills Payment Option";
		file.open("bank.txt",ios::in);
		if(!file){
			cout<<"\n\n File Opening Error..";
		}
		else{
			cout<<"\n\n User ID:";
			cin>>t_id;
			cout<<"\n\n Bill Name:";
			cin>>b_name;
			cout<<"Bill Amount";
			cin>>amount;
			file1.open("bank1.txt",ios::app|ios::out);
			file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
			while(!file.eof()){
				if(t_id==id && amount<=balance)
				{
					balance-=amount;
					file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";
					found++;	
				}else{
						file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";
						
				}
				file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
				
			}
			file.close();
			file1.close();
			remove("bank.txt");
			rename("bank1.txt","bank.txt");
			if(found==1){
				GetSystem(&x);
				file.open("bill.txt",ios::app|ios::out);
				file<<t_id<<b_name<<" "<<amount<<" "<<x.wDay<<"/"<<x.wMonth;<<"/"<<x.wYear<<"\n";
				file.close();
				cout<<"\n\n\t\t\t"<<b_name<<"Bill payed successfully";
			}
			else{
				cout<<"\n\n\t\t\t User ID or Amount Error";
			}
		}
	}	
}
void bank::search()
{
	system("cls");
	fstream file;
	string t_id;
	int found=0;
	cout<<"\n\n\t\t\tSearch User Record";
	file.open("bank.txt",ios::in);
	if(!file){
		cout<<"\n\n File Opening Error";
	}else{
		cout<<"\n\n User ID:";
		cin>>t_id;
		file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
		while(!file.eof()){
			if(t_id==id){
				system("cls");
				cout<<"\n\n\t\t\tSearch User Record";
				cout<<"\n\n\n User ID: "<<id<<" Name:"<<name<<" Father's Name:"<<fname;
				cout<<"n Address: "<<address<<" Pin: "<<pin<<" Password: "<<pass;
				cout<<"\n Phone No.: "<<phone<<" Current balance: "<<balance;
				found++;
			}
			file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
				
		}
		file.close();
		if(found==0){
			cout<<"\n\n User ID can't found";
		}
	}
}
void bank::edit()
{
      system("cls");
	  fstream file,file1;
	  string t_id,n,f,a,p,ph;
	  int found=0,pi;
	  cout<<"\n\n\t\t\t Edit User Record";
	  
	  file.open("bank.txt",ios::in);
	  if(!file){
	  	cout<<"\n\n File Opening Error";
	  }else{
	  	cout<<"\n\n User ID:";
	  	cin>>t_id;
	  	file1.open("bank1.txt",ios::app|ios::out);
	  	file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
		while(!file.eof()){
			if(t_id==id){
			cout<<"\n\n\t\tName:";
		    cin>>n;
		    cout<<"\n\n Father Name:";
		    cin>>f;
		    cout<<"\n\n\t\tAddress:";
		    cin>>a;
		    cout<<"\n\n Pin code(6 digit):";
		    cin>>pi;
		    cout<<"\n\n\t\tPassword:";
		    cin>>p;
		    cout<<"\n\n Phone No.:";
		    cin>>ph;
		    
		    	file1<<" "<<id<<" "<<n<<" "<<f<<" "<<a<<" "<<pi<<" "<<p<<" "<<ph<<" "<<balance<<"\n";
			    cout<<"Record edited successfully";
			    found++;
			}else{
					file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";
			}
			file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
				
		}
		file.close();
		file1.close();
		remove("bank.txt");
		rename("bank1.txt","bank.txt");
		if(found==0)
		cout<<"\n\n User ID can't found..";
	  }
}
void bank::del()
{
	system("cls");
	  fstream file,file1;
	  string t_id;
	  int found=0;
	  cout<<"\n\n\t\t\t Edit User Record";
	  
	  file.open("bank.txt",ios::in);
	  if(!file){
	  	cout<<"\n\n File Opening Error";
	  }else{
	  	cout<<"\n\n User ID:";
	  	cin>>t_id;
	  	file1.open("bank1.txt",ios::app|ios::out);
	  	file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
		while(!file.eof()){
			if(t_id==id){
				
			    cout<<"Record deleted successfully";
			    found++;
			}else{
					file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<password<<" "<<phone<<" "<<balance<<"\n";
			}
			file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
				
		}
		file.close();
		file1.close();
		remove("bank.txt");
		rename("bank1.txt","bank.txt");
		if(found==0)
		cout<<"\n\n User ID can't found..";
	  }
}
void bank::show_records()
{
    system("cls");
	fstream file;
	int found=0;
	cout<<"\n\n\t\t\tShow all  user records";
	file.open("bank.txt",ios::in);
	if(!file){
		cout<<"\n\n File Opening Error";
	}	else{
	
		file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
		while(!file.eof()){
			cout<<"\n\n\n User ID: "<<id;
			cout<<"\n Name: "<<name;
			cout<<"\n Father Name: "<<fname;
			cout<<"\n Address: "<<address;
			cout<<"\n Pin: "<<pin;
			cout<<"\n Password: "<<pass;
			cout<<"\n Phone No. : "<<phone;
			cout<<"\n Current Balance: "<<balance;
			cout<<"\n\n=======================================";
			file>>id>>name>>fname>>address>>pin>>password>>phone>>balance;
			found++;	
		}
		file.close();
		if(found==0)
		cout<<"\n\n Data Base is Empty...";
	}
}
void bank::show_payment(){
	system("cls");
	fstream file;
	int found=0;
	string c_date;
	float amount;
	cout<<"\n\n\t\t\tShow all bill  records";
	file.open("bill.txt",ios::in);
	if(!file){
		cout<<"\n\n File Opening Error";
	}	else{
	    
	    file>>id>>name>>amount>>c_date;
		while(!file.eof()){
			cout<<"\n\n\n User ID: "<<id;
			cout<<"\n Bill Name: "<<name;
			cout<<"\n Bill Amount: "<<amount;
			cout<<"\n Date: "<<c_date;
			cout<<"\n\n=======================================";
			file>>id>>name>>amount>>c_date;
			found++;	
		}
		file.close();
		if(found==0)
		cout<<"\n\n Data Base is Empty...";
	}
}


main(){
    bank obj;
    introduction();
    obj.menu();
}
