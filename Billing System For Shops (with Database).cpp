#include<iostream>
#include<windows.h>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

using namespace std;

class Product
{
	private:
		int pcode;
		float pprice, pdis;
		string pname;
	
		void setpcode()
		{
			cout<<"\n Product Code\t\t: ";
			cin>>pcode;
		}
		void setpname()
		{
			cout<<"\n Product Name\t\t: ";
			cin>>pname;
		}
		void setpprice()
		{
			cout<<"\n Product Price\t\t: ";
			cin>>pprice;
		}
		void setpdis()
		{
			cout<<"\n Discount on Price(%)\t: ";
			cin>>pdis;
		}
		
	public:	
		void addproduct()
		{
			fstream data;
			int code;
			
			system("CLS");
			cout<<"\n ============================"
				<<"\n      ADD NEW PRODUCT"
				<<"\n ============================\n";
			cout<<"\n Product Code\t\t: ";
			cin>>code;
	
			if(checkproduct(code))
			{
				cout<<"\n Record already available !";
			}
			else
			{
				pcode = code;
				setpname();
				setpprice();
				setpdis();
				
				data.open("Database.txt", ios::app|ios::out);
				data<<" "<<pcode<<" "<<pname<<" "<<pprice<<" "<<pdis<<"\n";
				data.close();
				
				cout<<"\n\n Record Inserted !";
			}
			getch();
		}
		
		int getproduct()
		{
			fstream data;
			data.open("Database.txt", ios::in);
			
			if(!data){
				cout<<"\n Sorry !"
					<<"\n No Products Are Available...";
				getch();
				data.close();
				return 0;
			}
			else{
				system("CLS");
				cout<<"\n ================================================="
					<<"\n \tPRODUCT LIST"
					<<"\n =================================================";
				cout<<"\n Code\tProduct\t\t\tPrice\tDiscount(%)"<<endl;
									
				data>>pcode>>pname>>pprice>>pdis;
				while(!data.eof())
				{
					cout<<"\n "<<pcode<<"\t"<<pname<<"\t\t"<<pprice<<"\t"<<pdis;
					data>>pcode>>pname>>pprice>>pdis;
				}
				data.close();
				return 1;
			}
			
		}
		int checkproduct(int code)
		{
			fstream data;
			int c, flag=0;
			string n;
			float p, d;
			
			data.open("Database.txt", ios::in);
			if(data)
			{
				data>>c>>n>>p>>d;
				while(!data.eof())
				{
					if(c == code)
						flag++;
					data>>c>>n>>p>>d;
				}
			}
			
			if(flag >= 1)
				return 1;
			else
				return 0;
			
		}
		
		void modifyproduct()
		{
			fstream data, data1;
			int c,flag=0,code;
			string n;
			float p, d;
			
			system("CLS");
	        cout<<"\n ============================"
				<<"\n \tMODIFY PRODUCT"
				<<"\n ============================\n";
			cout<<"\n Product Code\t\t: ";
			cin>>code;

			data.open("Database.txt",ios::in);
			
			if(!data)
			{
				cout<<"\n File doesn't exists !";
			}
			else{
				data1.open("database1.txt",ios::app|ios::out);
						
				data>>c>>n>>p>>d;
				while(!data.eof())
				{
					if(code == c){
						cout<<"\n Enter new code\t: ";
						cin>>c;
						cout<<"\n Product Name\t: ";
						cin>>n;
						cout<<"\n Product Price\t: ";
						cin>>p;
						cout<<"\n Discount on Product(%) : ";
						cin>>d;
						
						data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
						flag = 1;
					}
					else{
						data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
					}
					data>>c>>n>>p>>d;
				}
				
				data.close();
				data1.close();
				remove("Database.txt");
				rename("database1.txt", "Database.txt");
				
				if(flag == 0)
				{
					cout<<"\n Record not found !";
				}
				else
				{
					cout<<"\n Record Modification Done !";
				}
			}
			getch();
		}
		
		void deleteproduct()
		{
			fstream data, data1;
			int c,flag=0,code;
			string n;
			float p, d;
			
			system("CLS");
			cout<<"\n ============================"
				<<"\n \tDELETE PRODUCT"
				<<"\n ============================\n";
			cout<<"\n Product Code\t\t: ";
			cin>>code;
		
			data.open("Database.txt",ios::in);
			
			if(!data)
			{
				cout<<"\n File doesn't exists !";
			}
			else{
				data1.open("database1.txt",ios::app|ios::out);
						
				data>>c>>n>>p>>d;
				while(!data.eof())
				{
					if(code == c){
						flag = 1;
					}
					else{
						data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
					}
					data>>c>>n>>p>>d;
				}
				
				data.close();
				data1.close();
				remove("Database.txt");
				rename("database1.txt", "Database.txt");
				
				if(flag == 0)
				{
					cout<<"\n Record not found !";
				}
				else
				{
					cout<<"\n Record Removed !";
				}
			}
			getch();
		}
		
		void orderproduct()
		{
			fstream data;
			string chare;
			int o[30], qty[30], n=0;;
			float total=0, ptot;
			
			
			cout<<"\n\n ---------------------------------"
			<<"\n |   Please place your order...  |"
			<<"\n ---------------------------------";
			
			do{
				if(n > 30){
					cout<<"\n Sorry !"
						<<"\n At a time only 30 orders can be placed...";
					getch();
					break;
				}
				else{
					cout<<"\n\n Product Code = ";
					cin>>o[n];
					cout<<"\n Product Quantity = ";
					cin>>qty[n];
					n += 1;	
					cout<<"\n To buy another product press Y else N...";
					cin>>chare;
				}
			}while(chare=="Y" || chare=="y");
			
			system("CLS");				
			cout<<"\n\n THANKS FOR SHOPPING !"
				<<"\n\n Generating your reciept ...\n\n ";
			for(int j=0; j<=28; j++){
				Sleep(40);
				cout<<"|";
			}
										
			system("CLS");
			cout<<"\n ============================================================================="
				<<"\n \tRECIEPT"
				<<"\n =============================================================================";
			cout<<"\n\n Code\tProduct\t\t\tPrice\tQty\tAmount\tDiscounted Amount"<<endl;
			
			data.open("Database.txt", ios::in);
			data>>pcode>>pname>>pprice>>pdis;
			while(!data.eof()){
		
				for(int j=0; j<n; j++)
				{
					if(pcode == o[j])
					{
						ptot = qty[j]*(pprice-(pprice*pdis/100));
						cout<<"\n "<<pcode<<"\t"<<pname<<"\t\t"<<pprice<<"\t"<<qty[j]<<"\t"<<pprice*qty[j]<<"\t"<<ptot;
						total += ptot;
					}
				}
				data>>pcode>>pname>>pprice>>pdis;
			}
			data.close();
			cout<<"\n\n ----------------------------------------------------------------------------"
				<<"\n\tOrder Total = "<<total
				<<"\n\n Press enter to go buyer menu...";
			getch();					
		}
		
} ;

class Admin: protected Product
{
	private:
		string userID="sp", password="@shop";
		
	public:
		int CheckLogin(string ID, string pass){
			if(userID == ID && password == pass)
				return 1;
			else
				return 0;
		}
};

int main()
{
	int ch;
	string id,pass;
	Admin sp;
	Product p;
	
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t===================================="
		<<"\n\n\n\t\t\t\t\t     Welcome To Shoper's Stop"
		<<"\n\n\n\t\t\t\t\t";
		
	for(int j=0; j<=35; j++){
		Sleep(50);
		cout<<"|";
	}
	
	do{
		Shopersstop:
		system("CLS");
		cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t|====================================|"
			<<"\n\t\t\t\t\t|      SHOPER'S STOP MAINMENU        |"
			<<"\n\t\t\t\t\t|====================================|"
			<<"\n\t\t\t\t\t|                                    |"
			<<"\n\t\t\t\t\t|     1. Administration              |"
			<<"\n\t\t\t\t\t|     2. Buyer                       |"
			<<"\n\t\t\t\t\t|     3. Go back                     |"
			<<"\n\t\t\t\t\t|                                    |"
			<<"\n\n\t\t\t\t\tEnter your choice = ";
		cin>>ch;
		
		switch(ch)
		{
			case 1: Adminlogin:
					system("CLS");
					cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t|====================================|"
						<<"\n\t\t\t\t\t|       ADMINISTRATOR LOGIN          |"
						<<"\n\t\t\t\t\t|====================================|";
					cout<<"\n\t\t\t\t\t|                                    |"
						<<"\n\t\t\t\t\t|     User ID = ";
					cin>>id;
					cout<<"\t\t\t\t\t|                                    |"
						<<"\n\t\t\t\t\t|     Password = ";
						cin>>pass;
					if(!sp.CheckLogin(id,pass)){
						cout<<"\n\n\t\t\t\t\tWrong UserID or Password !";
						getch();
						goto Adminlogin;
					}
					else
					{
						cout<<"\t\t\t\t\t|                                    |"
							<<"\n\t\t\t\t\t|     Logging in ...                 |"
							<<"\n\t\t\t\t\t|                                    |\n\t\t\t\t\t";
							
						for(int j=0; j<=37; j++){
							Sleep(20);
							cout<<"|";
						}
 						do{
							Admin:
								
							system("CLS");
							cout<<"\n ==============================="
							    <<"\n      ADMINISTRATOR MENU"
							    <<"\n ==============================="
							    <<"\n 1. Add the Product"
							    <<"\n 2. Modify the Product"
							    <<"\n 3. Delete Product"
							    <<"\n 4. Go Back"
							    <<"\n\n Enter your choice = ";
							cin>>ch;
							
							switch(ch)
							{
								case 1: p.addproduct();
										goto Admin;
										break;
									
								case 2: p.modifyproduct();
										goto Admin;
										break;
										
								case 3: p.deleteproduct();
										goto Admin;
										break;
										
								case 4: goto Shopersstop;
										break;
										
								default: cout<<"\n Plz enter Valid choice !";
					 					 getch();
							}
							
						}while(ch<1 || ch>4);
					}
					break;
			case 2: do{
						Buyer:
						system("CLS");
						cout<<"\n ==============================="
						    <<"\n \tBUYER MENU"
						    <<"\n ==============================="
						    <<"\n 1. Buy Product"
						    <<"\n 2. Go Back"
						    <<"\n\n Enter your choice = ";
						cin>>ch;
							
						switch(ch){
							case 1: if(p.getproduct())
									{
										p.orderproduct();
									}
									goto Buyer;
			
							case 2:	goto Shopersstop;
								
							default: cout<<"\n Plz enter Valid choice !";
					 				 getch();
						}
					}while(ch<1 || ch>2);
					break;
					
			case 3: exit(0);
				
			default: cout<<"\n Plz enter Valid choice !";
					 getch();
		}
	}while(ch>3||ch<1);
	return 0;
}



















