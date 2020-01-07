 #include<iostream>
#include<string.h>
#include<fstream>
#include<time.h>
using namespace std;
class Room
{
	protected:
		string a,n, g, id,f,res_room,i,j,d1,d2,q,r;
		char ch;
		int ci,co,m,m1,m2,z,z1,z2;
		int d,d3,x,y,b,p,t,rt,count;
	public:
		Room()
		{
			a="";
			n="";
			g="";
			id="";
			d=0;
			f="";
			res_room="";
			i="";
			ch=' ';
			x=0;
			y=0;
			b=0;
			p=0;
			ci=0;
			co=0;
			d1="";
			d2="";
			m=0;
			m1=0;
			m2=0;
			count=0;
		}
		int Detail_Report()
		{
			fstream file2,file3;
			file2.open("Customers.txt",ios::in);
			file3.open("Available_Rooms.txt",ios::in);
			cout<<"Press 1 for Check in information:\nPress 2 for check out information:\nPress 3 for Empty rooms information:\nPress 4 for reserve Rooms information:";
			cin>>x;
			
			if(x==1)
			{
			cout<<"\nEnter date in this formate :dd/mm//yyyy\n"<<endl;
			cin>>r;
			q="Check_in_date:";
			q=q+r;
			while(file2>>i)
			{
				if(i==q)
				{
					count++;
				}
			}
			cout<<"\n"<<count<<" customers have checked in today\n"<<endl;
		    }
		    if(x==2)
		    {
		    cout<<"\nEnter date in this formate :dd/mm//yyyy\n"<<endl;
			cin>>r;
			q="Check_out_date:";
			q=q+r;
			while(file2>>i)
			{
				if(i==q)
				{
					count++;
				}
			}
			cout<<"\n"<<count<<" customers have checked out today\n"<<endl;
		    }
		    if(x==3)
		    {
			while(file3>>i)
			{
				if(i=="Standard"|| i=="Moderate"||i=="Superior"||i=="Junior_Suite"||i=="Suite")
				{
				cout<<"\n\nEmpty rooms "<<i<<" Type:"<<endl;
				}
				else
				{
					cout<<i<<" ";
				}
				
			}
		}
			file2.close();
			file3.close();
			return x;
		}
		int Record()
		{
			fstream file;
			file.open("Customers.txt",ios::in);
			if(file.fail())
			{
				cout<<"File NOT Found"<<endl;
			}
			else
			{cout<<"Old Customer: Press 1 "<<endl;
			cout<<"New Customer: Press 0 "<<endl;
			cin>>y;
			if(y==1)
			{
				cout<<"Enter Name: ";
				cin>>n;
				while(file>>i)
				{
					if(i==n)
					{
						 while(file>>i)
					    { 	
					        if(i=="Name:")
					        {
						        break;
					        }
					        else
					        {
						        cout<<i<<endl;
					        }
					    }
						cout<<"\nAlready Registered"<<endl;
						cout<<"\nEnter New data"<<endl;
						cout<<endl<<"Press 1: Standard Room"<<endl;
			            cout<<"Press 2: Moderate Room"<<endl;
		               	cout<<"Press 3: Superior Room"<<endl;
			            cout<<"Press 4: Junior Suite"<<endl;
			            cout<<"Press 5: Suite"<<endl;
			            cout<<endl<<"Enter Choice: ";
			            cin>>x;
			            j="a";
			            break;
					}
				else
					{
						j="o";
					}
				}
				if(j=="o")
				{
					cout<<"\nyou are Not OLd Customer"<<endl;
				}
			}
			file.close();
			if(y==0)
			{
			cout<<endl<<"Press 1: Standard Room"<<endl;
			cout<<"Press 2: Moderate Room"<<endl;
			cout<<"Press 3: Superior Room"<<endl;
			cout<<"Press 4: Junior Suite"<<endl;
			cout<<"Press 5: Suite"<<endl;
			cout<<"Press Any: Exit"<<endl;
			cout<<endl<<"Enter Choice: ";
			cin>>x;
			}
			}
			return x;
			
		}
		
		virtual void reserve_room()=0;
		virtual void reserve_show()=0;
};
class Standard: public Room
{
	public:
		void reserve_room()
		{
			
			string i;
			char ch;
			fstream file1,file2,file3,file4;
			file4.open("Customers.txt",ios::app);
			file1.open("Available_Rooms.txt",ios::in);
			file2.open("Reserve_Rooms.txt",ios::app);
			file3.open("New_Available_Rooms.txt",ios::out);
			if(file1.fail())
			{
				cout<<"File NOT Found"<<endl;
			}
			else
			{
			cout<<"Enter name:";
			cin>>n;
			file4<<"Name: "<<n<<endl;
			cout<<"Enter age:";
			cin>>a;
			file4<<"Age:"<<a<<endl;
			cout<<"Enter Gender:";
			cin>>g;
			file4<<"Gender:"<<g<<endl;
			cout<<"Enter id:";
			cin>>id;
			file4<<"id:"<<id<<endl;
			time_t now = time(0);
	tm *ltm = localtime(&now);
	ci=ltm->tm_hour;
	m1=ltm->tm_min;
	z=ltm->tm_sec;
			cout<<"Check in time : "<<ci<<":"<<m1<<":"<<z<<endl;
			file4<<"Check_in_time:"<<ci<<":"<<m1<<":"<<z<<endl;
			cout<<"Enter Check in date : "<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<"\n";
			file4<<"Check_in_date:"<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<"\n";
			cout<<"\nEnter Time in 24-Hour formate\n"<<endl;
			cout<<"Enter Check out time :\nEnter Hours: ";
			cin>>co;
			cout<<"Enter minutes:";
			cin>>m2;
			cout<<"Enter seconds:";
			cin>>z1;
			if(co>24 || co<1 || m2>60||m2<0||z1>60||z1<0)
			{cout<<"Invlid\nRe_Enter the Check in time:\n Enter Hours:";
			cin>>co;
			cout<<"Enter minutes:";
			cin>>m2;
			cout<<"Enter Seconds:";
			cin>>z1;
			}
			file4<<"Check_out_time:"<<co<<":"<<m2<<":"<<z1<<endl;
			cout<<"\nEnter date in this formate :dd/mm//yyyy\n"<<endl;
			cout<<"Enter Check out date : ";
			cin>>d2;
			file4<<"Check_out_date:"<<d2<<endl;
		    cout<<"Enter days:";
			cin>>d;
			file4<<"Days:"<<d<<endl;
			z2=z+z1;
			ci=24-ci;
			if(m1>0)
			{
				ci=ci-1;
				m1=60-m1;
				
			}
			m=m1+m2;
			if(z2>60)
			{
				m++;
				z2=z2-60;
			}
			t=ci+co;
			d3=d-2;
			rt=d3*24;
			rt=rt+t;
		
			if(m>=60)
			{
			rt++;
			m=m-60;
			}
			cout<<"Price of room for one Day is:300"<<endl;
			p=300*d;
			cout<<" Your balance is: "<<p<<"\n Please Enter Balance:";
			cin>>b;
			b=p-b;
			file4<<"Balance:"<<b<<endl;
			cout<<"Enter floor:";
			int f,x;
			cin>>f;
			file4<<"Floor:"<<f<<endl;
			file2<<"Floor: "<<f<<endl;
			switch(f)
			{
			case 1:
				for(x=1;x<=10;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 2:
				for(x=51;x<=60;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 3:
				for(x=101;x<=110;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 4:
				for(x=151;x<=160;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 5:
				for(x=201;x<=210;x++)
				{
					cout<<x<<" ";
				}
				break;
			}
			cout<<"\nEnter Room:";
			cin>>res_room;
			
				while(file1>>i)
				{
					if(res_room==i)
					{
						file2<<"Standard "<<i<<endl;
						file4<<"Standard "<<i<<endl;
						cout<<endl<<"Room "<<i<<" is Reserved for You"<<endl;
						cout<<"\nTime remaining in the Hotel :"<<rt<<":"<<m<<":"<<z2<<endl;
						ch='y';
						
					}
					else
					{	
					if(ch=='y')
					{
						ch='y';
					}
					else{
					ch='n';
				}
						file3<<i<<" "<<endl;
					}
				}
			
			}
				if(ch=='n')
				{
					cout<<endl<<"***alerady Rserved***"<<endl;
					file4<<"***alerady Rserved***"<<endl;
				}
		    file1.close();
		    file2.close();
		    file3.close();
		    file4.close();
		    remove("Available_Rooms.txt");
		    rename("New_Available_Rooms.txt","Available_Rooms.txt");
		    
			
		}
		void reserve_show()
	    {
	    	string i;
			ifstream file;
			file.open("Reserve_Rooms.txt",ios::in);
			if(file.fail())
			{
				cout<<"File NOT Found"<<endl;
			}
			else
			{
				cout<<endl<<"Standard Reserve Rooms"<<endl;
				while(file>>i)
				{
					if(i=="Standard")
					{
					   file>>i;
					   cout<<i<<" ";
					}
				}
			}
		    file.close();
		}
};
class Moderate: public Room
{
	public:
		void reserve_room()
		{
			string i;
			fstream file1,file2,file3,file4;
			file4.open("Customers.txt",ios::app);
			file1.open("Available_Rooms.txt",ios::in);
			file2.open("Reserve_Rooms.txt",ios::app);
			file3.open("New_Available_Rooms.txt",ios::out);
			if(file1.fail())
			{
				cout<<"File NOT Found"<<endl;
			}
			else
			{
			cout<<"Enter name:";
			cin>>n;
			file4<<"Name: "<<n<<endl;
			cout<<"Enter age:";
			cin>>a;
			file4<<"Age:"<<a<<endl;
			cout<<"Enter Gender:";
			cin>>g;
			file4<<"Gender:"<<g<<endl;
			cout<<"Enter id:";
			cin>>id;
			file4<<"id:"<<id<<endl;
			time_t now = time(0);
	tm *ltm = localtime(&now);
	ci=ltm->tm_hour;
	m1=ltm->tm_min;
	z=ltm->tm_sec;
			cout<<"Check in time : "<<ci<<":"<<m1<<":"<<z<<endl;
			file4<<"Check_in_time:"<<ci<<":"<<m1<<":"<<z<<endl;
			cout<<"Enter Check in date : "<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<"\n";
			file4<<"Check_in_date:"<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<"\n";
			cout<<"\nEnter Time in 24-Hour formate\n"<<endl;
			cout<<"Enter Check out time :\nEnter Hours: ";
			cin>>co;
			cout<<"Enter minutes:";
			cin>>m2;
			cout<<"Enter seconds:";
			cin>>z1;
			if(co>24 || co<1 || m2>60||m2<0||z1>60||z1<0)
			{cout<<"Invlid\nRe_Enter the Check in time:\n Enter Hours:";
			cin>>co;
			cout<<"Enter minutes:";
			cin>>m2;
			cout<<"Enter Seconds:";
			cin>>z1;
			}
			file4<<"Check_out_time:"<<co<<":"<<m2<<":"<<z1<<endl;
			cout<<"\nEnter date in this formate :dd/mm//yyyy\n"<<endl;
			cout<<"Enter Check out date : ";
			cin>>d2;
			file4<<"Check_out_date:"<<d2<<endl;
		    cout<<"Enter days:";
			cin>>d;
			file4<<"Days:"<<d<<endl;
			z2=z+z1;
			ci=24-ci;
			if(m1>0)
			{
				ci=ci-1;
				m1=60-m1;
				
			}
			m=m1+m2;
			if(z2>60)
			{
				m++;
				z2=z2-60;
			}
			t=ci+co;
			d3=d-2;
			rt=d3*24;
			rt=rt+t;
		
			if(m>=60)
			{
			rt++;
			m=m-60;
			}
			cout<<"Price of room for one Day is:500"<<endl;
			p=500*d;
			cout<<" Your balance is: "<<p<<"\n Please Enter Balance:";
			cin>>b;
			b=p-b;
			file4<<"Balance:"<<b<<endl;
			cout<<"Enter floor:";
			int f,x;
			cin>>f;
			file4<<"Floor:"<<f<<endl;
			file2<<"Floor: "<<f<<endl;
			switch(f)
			{
			case 1:
				for(x=11;x<=20;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 2:
				for(x=61;x<=70;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 3:
				for(x=111;x<=120;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 4:
				for(x=161;x<=170;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 5:
				for(x=211;x<=220;x++)
				{
					cout<<x<<" ";
				}
				break;
			}
			cout<<"\nEnter Room:";
			cin>>res_room;
			
				while(file1>>i)
				{
					if(res_room==i)
					{
						file2<<"Moderate "<<i<<endl;
						file4<<"Moderate "<<i<<endl;
						cout<<endl<<"Room "<<i<<" is Reserved for You"<<endl;
						cout<<"\nTime remaining in the Hotel :"<<rt<<":"<<m<<":"<<z2<<endl;
						ch='y';
						
					}
					else
					{
					if(ch=='y')
					{
						ch='y';
					}
					else{
					ch='n';
				}
			file3<<i<<" "<<endl;
					}
				}
			
			}
				if(ch=='n')
				{
					cout<<endl<<"***alerady Rserved***"<<endl;
					file4<<"***alerady Rserved***"<<endl;
				}
		    file1.close();
		    file2.close();
		    file3.close();
		    file4.close();
		    remove("Available_Rooms.txt");
		    rename("New_Available_Rooms.txt","Available_Rooms.txt");
		    
			
		}
		void reserve_show()
	    {
	    	string i;
			ifstream file;
			file.open("Reserve_Rooms.txt",ios::in);
			if(file.fail())
			{
				cout<<"File NOT Found"<<endl;
			}
			else
			{
				cout<<endl<<"Moderate Reserve Rooms"<<endl;
				while(file>>i)
				{
					if(i=="Moderate")
					{
					   file>>i;
					   cout<<i<<" ";
					}
				}
			}
		    file.close();
		}
};
class Superior: public Room
{
	public:
		void reserve_room()
		{
			string i;
			fstream file1,file2,file3,file4;
			file4.open("Customers.txt",ios::app);
			file1.open("Available_Rooms.txt",ios::in);
			file2.open("Reserve_Rooms.txt",ios::app);
			file3.open("New_Available_Rooms.txt",ios::out);
			if(file1.fail())
			{
				cout<<"File NOT Found"<<endl;
			}
			else
			{
				cout<<"Enter name:";
			cin>>n;
			file4<<"Name: "<<n<<endl;
			cout<<"Enter age:";
			cin>>a;
			file4<<"Age:"<<a<<endl;
			cout<<"Enter Gender:";
			cin>>g;
			file4<<"Gender:"<<g<<endl;
			cout<<"Enter id:";
			cin>>id;
			file4<<"id:"<<id<<endl;
				time_t now = time(0);
	tm *ltm = localtime(&now);
	ci=ltm->tm_hour;
	m1=ltm->tm_min;
	z=ltm->tm_sec;
			cout<<"Check in time : "<<ci<<":"<<m1<<":"<<z<<endl;
			file4<<"Check_in_time:"<<ci<<":"<<m1<<":"<<z<<endl;
			cout<<"Enter Check in date : "<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<"\n";
			file4<<"Check_in_date:"<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<"\n";
			cout<<"\nEnter Time in 24-Hour formate\n"<<endl;
			cout<<"Enter Check out time :\nEnter Hours: ";
			cin>>co;
			cout<<"Enter minutes:";
			cin>>m2;
			cout<<"Enter seconds:";
			cin>>z1;
			if(co>24 || co<1 || m2>60||m2<0||z1>60||z1<0)
			{cout<<"Invlid\nRe_Enter the Check in time:\n Enter Hours:";
			cin>>co;
			cout<<"Enter minutes:";
			cin>>m2;
			cout<<"Enter Seconds:";
			cin>>z1;
			}
			file4<<"Check_out_time:"<<co<<":"<<m2<<":"<<z1<<endl;
			cout<<"\nEnter date in this formate :dd/mm//yyyy\n"<<endl;
			cout<<"Enter Check out date : ";
			cin>>d2;
			file4<<"Check_out_date:"<<d2<<endl;
		    cout<<"Enter days:";
			cin>>d;
			file4<<"Days:"<<d<<endl;
			z2=z+z1;
			ci=24-ci;
			if(m1>0)
			{
				ci=ci-1;
				m1=60-m1;
				
			}
			m=m1+m2;
			if(z2>60)
			{
				m++;
				z2=z2-60;
			}
			t=ci+co;
			d3=d-2;
			rt=d3*24;
			rt=rt+t;
		
			if(m>=60)
			{
			rt++;
			m=m-60;
			}
			cout<<"Price of room for one Day is:1000"<<endl;
			p=1000*d;
			cout<<" Your balance is: "<<p<<"\n Please Enter Balance:";
			cin>>b;
			b=p-b;
			file4<<"Balance:"<<b<<endl;
			cout<<"Enter floor:";
			int f,x;
			cin>>f;
			file4<<"Floor:"<<f<<endl;
			file2<<"Floor: "<<f<<endl;
			switch(f)
			{
			case 1:
				for(x=21;x<=30;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 2:
				for(x=71;x<=80;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 3:
				for(x=121;x<=130;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 4:
				for(x=171;x<=180;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 5:
				for(x=221;x<=230;x++)
				{
					cout<<x<<" ";
				}
				break;
			}
			cout<<"\nEnter Room:";
			cin>>res_room;
			
				while(file1>>i)
				{
					if(res_room==i)
					{
						file2<<"Superior "<<i<<endl;
						file4<<"Superior "<<i<<endl;
						cout<<endl<<"Room "<<i<<" is Reserved for You"<<endl;
						cout<<"\nTime remaining in the Hotel :"<<rt<<":"<<m<<":"<<z2<<endl;
						ch='y';
					}
					else
					{	
					if(ch=='y')
					{
						ch='y';
					}
					else{
					ch='n';
				}
						file3<<i<<" "<<endl;
					}
				}
			
			}
				if(ch=='n')
				{
					cout<<endl<<"***alerady Rserved***"<<endl;
					file4<<"***alerady Rserved***"<<endl;
				}
		    file1.close();
		    file2.close();
		    file3.close();
		    file4.close();
		    remove("Available_Rooms.txt");
		    rename("New_Available_Rooms.txt","Available_Rooms.txt");
		    
			
		}
		void reserve_show()
	    {
	    	string i;
			ifstream file;
			file.open("Reserve_Rooms.txt",ios::in);
			if(file.fail())
			{
				cout<<"File NOT Found"<<endl;
			}
			else
			{
				cout<<endl<<"Superior Reserve Rooms"<<endl;
				while(file>>i)
				{
					if(i=="Superior")
					{
					   file>>i;
					   cout<<i<<" ";
					}
				}
			}
		    file.close();
		}
};
class Junior_Suite: public Room
{
	public:
		void reserve_room()
		{
			string i;
			fstream file1,file2,file3,file4;
			file4.open("Customers.txt",ios::app);
			file1.open("Available_Rooms.txt",ios::in);
			file2.open("Reserve_Rooms.txt",ios::app);
			file3.open("New_Available_Rooms.txt",ios::out);
			if(file1.fail())
			{
				cout<<"File NOT Found"<<endl;
			}
			else
			{
				cout<<"Enter name:";
			cin>>n;
			file4<<"Name: "<<n<<endl;
			cout<<"Enter age:";
			cin>>a;
			file4<<"Age:"<<a<<endl;
			cout<<"Enter Gender:";
			cin>>g;
			file4<<"Gender:"<<g<<endl;
			cout<<"Enter id:";
			cin>>id;
			file4<<"id:"<<id<<endl;
				time_t now = time(0);
	tm *ltm = localtime(&now);
	ci=ltm->tm_hour;
	m1=ltm->tm_min;
	z=ltm->tm_sec;
			cout<<"Check in time : "<<ci<<":"<<m1<<":"<<z<<endl;
			file4<<"Check_in_time:"<<ci<<":"<<m1<<":"<<z<<endl;
			cout<<"Enter Check in date : "<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<"\n";
			file4<<"Check_in_date:"<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<"\n";
			cout<<"\nEnter Time in 24-Hour formate\n"<<endl;
			cout<<"Enter Check out time :\nEnter Hours: ";
			cin>>co;
			cout<<"Enter minutes:";
			cin>>m2;
			cout<<"Enter seconds:";
			cin>>z1;
			if(co>24 || co<1 || m2>60||m2<0||z1>60||z1<0)
			{cout<<"Invlid\nRe_Enter the Check in time:\n Enter Hours:";
			cin>>co;
			cout<<"Enter minutes:";
			cin>>m2;
			cout<<"Enter Seconds:";
			cin>>z1;
			}
			file4<<"Check_out_time:"<<co<<":"<<m2<<":"<<z1<<endl;
			cout<<"\nEnter date in this formate :dd/mm//yyyy\n"<<endl;
			cout<<"Enter Check out date : ";
			cin>>d2;
			file4<<"Check_out_date:"<<d2<<endl;
		    cout<<"Enter days:";
			cin>>d;
			file4<<"Days:"<<d<<endl;
			z2=z+z1;
			ci=24-ci;
			if(m1>0)
			{
				ci=ci-1;
				m1=60-m1;
				
			}
			m=m1+m2;
			if(z2>60)
			{
				m++;
				z2=z2-60;
			}
			t=ci+co;
			d3=d-2;
			rt=d3*24;
			rt=rt+t;
		
			if(m>=60)
			{
			rt++;
			m=m-60;
			}
			cout<<"Price of room for one Day is:2000"<<endl;
			p=2000*d;
			cout<<" Your balance is: "<<p<<"\n Please Enter Balance:";
			cin>>b;
			b=p-b;
			file4<<"Balance:"<<b<<endl;
			cout<<"Enter floor:";
			int f,x;
			cin>>f;
			file4<<"Floor:"<<f<<endl;
			file2<<"Floor: "<<f<<endl;
			switch(f)
			{
			case 1:
				for(x=31;x<=40;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 2:
				for(x=81;x<=90;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 3:
				for(x=131;x<=140;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 4:
				for(x=181;x<=190;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 5:
				for(x=231;x<=240;x++)
				{
					cout<<x<<" ";
				}
				break;
			}
			cout<<"\nEnter Room:";
			cin>>res_room;
			
				while(file1>>i)
				{
					if(res_room==i)
					{
						file2<<"Junior_Suite "<<i<<endl;
						file4<<"Junior_Suite "<<i<<endl;
						cout<<endl<<"Room "<<i<<" is Reserved for You"<<endl;
					cout<<"\nTime remaining in the Hotel :"<<rt<<":"<<m<<":"<<z2<<endl;
						ch='y';
						
					}
					else
					{	
					if(ch=='y')
					{
						ch='y';
					}
					else{
					ch='n';
				}
						file3<<i<<" "<<endl;
					}
				}
			
			}
				if(ch=='n')
				{
					cout<<endl<<"***alerady Rserved***"<<endl;
					file4<<"***alerady Rserved***"<<endl;
				}
		    file1.close();
		    file2.close();
		    file3.close();
		    file4.close();
		    remove("Available_Rooms.txt");
		    rename("New_Available_Rooms.txt","Available_Rooms.txt");
		    
			
		}  
		void reserve_show()
	    {
	    	string i;
			ifstream file;
			file.open("Reserve_Rooms.txt",ios::in);
			if(file.fail())
			{
				cout<<"File NOT Found"<<endl;
			}
			else
			{
				cout<<endl<<"Junior Suite Reserve Rooms"<<endl;
				while(file>>i)
				{
					if(i=="Junior_Suite")
					{
					   file>>i;
					   cout<<i<<" ";
					}
				}
			}
		    file.close();
		}
};
class Suite: public Room
{
	public:
		void reserve_room()
		{
			string i;
			fstream file1,file2,file3,file4;
			file4.open("Customers.txt",ios::app);
			file1.open("Available_Rooms.txt",ios::in);
			file2.open("Reserve_Rooms.txt",ios::app);
			file3.open("New_Available_Rooms.txt",ios::out);
			if(file1.fail())
			{
				cout<<"File NOT Found"<<endl;
			}
			else
			{
			cout<<"Enter name:";
			cin>>n;
			file4<<"Name: "<<n<<endl;
			cout<<"Enter age:";
			cin>>a;
			file4<<"Age:"<<a<<endl;
			cout<<"Enter Gender:";
			cin>>g;
			file4<<"Gender:"<<g<<endl;
			cout<<"Enter id:";
			cin>>id;
			file4<<"id:"<<id<<endl;
				time_t now = time(0);
	tm *ltm = localtime(&now);
	ci=ltm->tm_hour;
	m1=ltm->tm_min;
	z=ltm->tm_sec;
			cout<<"Check in time : "<<ci<<":"<<m1<<":"<<z<<endl;
			file4<<"Check_in_time:"<<ci<<":"<<m1<<":"<<z<<endl;
			cout<<"Enter Check in date : "<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<"\n";
			file4<<"Check_in_date:"<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<"\n";
			cout<<"\nEnter Time in 24-Hour formate\n"<<endl;
			cout<<"Enter Check out time :\nEnter Hours: ";
			cin>>co;
			cout<<"Enter minutes:";
			cin>>m2;
			cout<<"Enter seconds:";
			cin>>z1;
			if(co>24 || co<1 || m2>60||m2<0||z1>60||z1<0)
			{cout<<"Invlid\nRe_Enter the Check in time:\n Enter Hours:";
			cin>>co;
			cout<<"Enter minutes:";
			cin>>m2;
			cout<<"Enter Seconds:";
			cin>>z1;
			}
			file4<<"Check_out_time:"<<co<<":"<<m2<<":"<<z1<<endl;
			cout<<"\nEnter date in this formate :dd/mm//yyyy\n"<<endl;
			cout<<"Enter Check out date : ";
			cin>>d2;
			file4<<"Check_out_date:"<<d2<<endl;
		    cout<<"Enter days:";
			cin>>d;
			file4<<"Days:"<<d<<endl;
			z2=z+z1;
			ci=24-ci;
			if(m1>0)
			{
				ci=ci-1;
				m1=60-m1;
				
			}
			m=m1+m2;
			if(z2>60)
			{
				m++;
				z2=z2-60;
			}
			t=ci+co;
			d3=d-2;
			rt=d3*24;
			rt=rt+t;
		
			if(m>=60)
			{
			rt++;
			m=m-60;
			}
			cout<<"Price of room for one Day is:5000"<<endl;
			p=5000*d;
			cout<<" Your balance is: "<<p<<"\n Please Enter Balance:";
			cin>>b;
			b=p-b;
			file4<<"Balance:"<<b<<endl;
			cout<<"Enter floor:";
			int f,x;
			cin>>f;
			file4<<"Floor:"<<f<<endl;
			file2<<"Floor: "<<f<<endl;
			switch(f)
			{
			case 1:
				for(x=41;x<=50;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 2:
				for(x=91;x<=100;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 3:
				for(x=141;x<=150;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 4:
				for(x=191;x<=200;x++)
				{
					cout<<x<<" ";
				}
				break;
			case 5:
				for(x=241;x<=250;x++)
				{
					cout<<x<<" ";
				}
				break;
			}
			cout<<"\nEnter Room:";
			cin>>res_room;
			
				while(file1>>i)
				{
					if(res_room==i)
					{
						file2<<"Suite "<<i<<endl;
						file4<<"Suite "<<i<<endl;
						cout<<endl<<"Room "<<i<<" is Reserved for You"<<endl;
						cout<<"\nTime remaining in the Hotel :"<<rt<<":"<<m<<":"<<z2<<endl;
						ch='y';
						
					}
					else
					{	
					if(ch=='y')
					{
						ch='y';
					}
					else{
					ch='n';
				}
						file3<<i<<" "<<endl;
					}
				}
			
			}
				if(ch=='n')
				{
					cout<<endl<<"***alerady Rserved***"<<endl;
					file4<<"***alerady Rserved***"<<endl;
				}	
		    file1.close();
		    file2.close();
		    file3.close();
		    remove("Available_Rooms.txt");
		    rename("New_Available_Rooms.txt","Available_Rooms.txt");
		    
			
		}
		void reserve_show()
	    {
	    	int x;
	    	string i;
			ifstream file;
			file.open("Reserve_Rooms.txt",ios::in);
			if(file.fail())
			{
				cout<<"File NOT Found"<<endl;
			}
			else
			{
				cout<<endl<<"Suite Reserve Rooms"<<endl;
				while(file>>i)
				{
					if(i=="Suite")
					{
					   file>>i;
					   cout<<i<<" ";
					}
				}
			}
		    file.close();
		}
};
int main()
{
	int x;
	string choice1;
	char ch;
	Room *ptr;
	do
	{
	cout<<"Press 1: Reserve A Room"<<endl;
	cout<<"Press 2: Checkin a Customer/Visitor"<<endl;
	cout<<"Press 3: View Reserve Rooms"<<endl;
	cout<<"Press 4: Detail Report"<<endl;
	cout<<"Press 5: Exit"<<endl;
	cout<<endl<<"Enter Choice: ";
	cin>>x;
	switch(x){
		case 1:
			cout<<endl<<"Press 1: Standard Room"<<endl;
			cout<<"Press 2: Moderate Room"<<endl;
			cout<<"Press 3: Superior Room"<<endl;
			cout<<"Press 4: Junior Suite"<<endl;
			cout<<"Press 5: Suite"<<endl;
			cout<<"Press Any: Exit"<<endl;
			cout<<endl<<"Enter Choice: ";
			cin>>x;
			if(x==1)
			{
				
				ptr=new Standard;
				ptr->reserve_room();
			}
			else if(x==2)
			{
				ptr= new Moderate;
				ptr->reserve_room();
			}
			else if(x==3)
			{
		    	ptr= new Superior;
				ptr->reserve_room();	
			}
			else if(x==4)
			{
				
		    	ptr=new Junior_Suite;
				ptr->reserve_room();	
				
			}
			else if(x==5)
			{
				ptr=new Suite;
				ptr->reserve_room();	
			}
			else
			{
				cout<<"Exit"<<endl;
			}
			
			break;
		case 2:
			{
				int x;
			ptr=new Standard;
			x=ptr->Record();
			if(x==1)
			{
				
				ptr=new Standard;
				ptr->reserve_room();
			}
			else if(x==2)
			{
				ptr= new Moderate;
				ptr->reserve_room();
			}
			else if(x==3)
			{
		    	ptr= new Superior;
				ptr->reserve_room();	
			}
			else if(x==4)
			{
				
		    	ptr=new Junior_Suite;
				ptr->reserve_room();	
				
			}
			else if(x==5)
			{
				ptr=new Suite;
				ptr->reserve_room();	
			}
			else
			{
				cout<<"Exit"<<endl;
			}
			break;
		    }
		case 3:
			ptr=new Standard;
			ptr->reserve_show();
			cout<<endl;
			ptr=new Moderate;
			ptr->reserve_show();
			cout<<endl;
			ptr=new Superior;
			ptr->reserve_show();
			cout<<endl;
			ptr=new Junior_Suite;
			ptr->reserve_show();
			cout<<endl;
			ptr=new Suite;
			ptr->reserve_show();
			cout<<endl;
			break;
		case 4:
			ptr=new Standard;
			x=ptr->Detail_Report();
			if(x==4)
			{
			cout<<"\n\n\t\t\t******Reserve Rooms******"<<endl;
			ptr=new Standard;
			ptr->reserve_show();
			cout<<endl;
			ptr=new Moderate;
			ptr->reserve_show();
			cout<<endl;
			ptr=new Superior;
			ptr->reserve_show();
			cout<<endl;
			ptr=new Junior_Suite;
			ptr->reserve_show();
			cout<<endl;
			ptr=new Suite;
			ptr->reserve_show();
			cout<<endl;}
			break;
			case 5:
				break;
	}
	cout<<endl<<"Do You Want to Continue (y/n): ";
	cin>>ch;
	cout<<endl;
    }while(ch=='y');
}
