// Bus Reservation System Project:

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
#include<cstdlib>

using namespace std;

class bus
{
	private:
		string b_no,b_name,d_name;
		int b_seats;
	public:
		void menu();
		void new_bus();
		void view_bus();
		void single_view_bus();
		void all_view_bus();
		void update_bus();
		void del_bus();
		void rout_bus();
		void detail_seats_bus();
		void booking();
		void renew_bus();
		void search_booking();
		void update_booking();
		void del_booking();
		void show_booking();
};

void bus::menu()
{

	p:
	system("cls");
	int choice;
	cout<<"\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
	cout<<"\n\n 1.  ADD BUS RECORD";
	cout<<"\n 2.  VIEW BUS DETAIL";
	cout<<"\n 3.  UPDATE BUS DETAIL";
	cout<<"\n 4.  DELETE BUSES";
	cout<<"\n 5.  ROUTS OF BUSES";
	cout<<"\n 6.  BUS SEATS DETAILS";
	cout<<"\n 7.  SEAT BOOKING";
	cout<<"\n 8.  SEATS RENEW";
	cout<<"\n 9.  SEARCH BOOKING RECORD";
	cout<<"\n 10. UPDATE BOOKIING RECORD";
	cout<<"\n 11. DELETE BOOKING RECORD";
	cout<<"\n 12. SHOW ALL BOOKING RECORD";
	cout<<"\n 13. EXIT.";
	cout<<"\n\n ENTER YOUR CHOICE : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			new_bus();
			break;
		case 2:
			view_bus();
			break;
		case 3:
			update_bus();
			break;
		case 4:
			del_bus();
			break;
		case 5:
			rout_bus();
			break;
		case 6:
			detail_seats_bus();
			break;
		case 7:
			booking();
			break;
		case 8:
			renew_bus();
			break;
		case 9:
			search_booking();
			break;
		case 10:
			update_booking();
			break;
		case 11:
			del_booking();
			break;
		case 12:
			show_booking();
			break;
		case 13:
			exit(0);
		default: 
		cout<<"\n\n Invalid Choice...Please Try Again..";
	}
	getch();
	goto p;
}

void bus::new_bus()
{
	p:
	system("cls");
	fstream file;
	string t_no,tb_name,td_name;
	int t_seats,found=0;	
	cout<<"\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
	cout<<"\n\n Bus No : ";
	cin>>b_no;
	cout<<"\n\n Bus Name : ";
	cin>>b_name;
	cout<<"\n\n Total seates : ";
	cin>>b_seats;
	cout<<"\n\n Driver Name : ";
	cin>>d_name;
	file.open("bus.txt", ios::in);
	if(!file)
	{
		file.open("bus.txt", ios::app|ios::out);
		file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
		file.close();
	}
	else
	{
		file>>t_no>>tb_name>>t_seats>>td_name;
		while(!file.eof())
		{
			if(t_no == b_no)
			{
				found++;
			}
			file>>t_no>>tb_name>>t_seats>>td_name;
		}
		file.close();
		if(found == 0)
		{
			file.open("bus.txt", ios::app|ios::out);
			file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			file.close();
		}
		else
		{
			cout<<"\n\n Duplicate Record Found...";
			getch();
			goto p;
		}
	}
	cout<<"\n\n New Bus Insereted Successfully.";
}

void bus::view_bus()
{
	p:
	system("cls");
	int choice;
	cout<<"\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
	cout<<"\n\n 1. Single Bus View";
	cout<<"\n 2. All Buses View";
	cout<<"\n 3. Go Back";
	cout<<"\n\n Enter Your Choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			single_view_bus();
			break;
		case 2:
			all_view_bus();
			break;
		case 3:
			menu();
			break;
		default:
			cout<<"\n\nInvalid Choice... Please Try Again...";
	}
	getch();
	goto p;
	
}

void bus::single_view_bus()
{
	system("cls");
	string t_no;
	fstream file;
	int found=0;
	cout<<"\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
	cout<<"\n\n Enter Bus No. : "; cin>>t_no;
	file.open("bus.txt", ios::in);
	if(!file)
	{
		cout<<"\n\n File Opening Error...";
	}
	else
	{
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof())
		{
			if(t_no==b_no)
			{
				system("cls");
				cout<<"\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
				cout<<"\n BUS NO. \tBUS NAME\tNO. OF SEATS\tDriver NAME";
				cout<<"\n "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
				found++;
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
		if(found==0)
		{
			cout<<"\n\n Invalid Bus No....";
		}
	}
}

void bus::all_view_bus()
{
	system("cls");
	fstream file; 
	cout<<"\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
	file.open("bus.txt", ios::in);
	if(!file)
	{
		cout<<"\n\n File Opening Error...";
	}
	else
	{
		cout<<"\n BUS NO. \tBUS NAME\tNO. OF SEATS\tDRIVER NAME";
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof())
		{
			cout<<"\n "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
	}
}

void bus::update_bus()
{
	system("cls");
	fstream file, file1;
	string t_no, no, t_name, td_name;
	int t_seats, found=0;
	cout<<"\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
	file.open("bus.txt", ios::in);
	if(!file)
	{
		cout<<"\n\n File Opening Error...";
	}
	else
	{
		cout<<"\n\n Bus No. : ";
		cin>>t_no;
		file1.open("bus1.txt", ios::app|ios::out);   // create new file to store new data
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof())
		{
			if(t_no==b_no)
			{
				cout<<"\n\n New Bus No. : ";
				cin>>no;
				cout<<"\n\n New Bus Name : ";
				cin>>t_name;
				cout<<"\n\n No. of Seats : ";
				cin>>t_seats;
				cout<<"\n\n Driver Name : ";
				cin>>td_name;
				file1<<no<<" "<<t_name<<" "<<t_seats<<" "<<td_name<<"\n";
				cout<<"\n\n\n Update Bus Record Successfully...";
				found++;
			}
			else
			{
				file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		} 
		file.close();
		file1.close();
		remove("bus.txt");
		rename("bus1.txt", "bus.txt");
		if(found==0)
		{
			cout<<"\n\n Bus No. is Invalid...";
		}
	}
}

void bus::del_bus() {
    system("cls");
    fstream file, file1;
    string t_no;
    int found = 0;
    cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
    file.open("bus.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error...";
    }
    else {
        cout << "\n\n Bus No. : ";
        cin >> t_no;
        file1.open("bus1.txt", ios::out); // Create new file to store new data
        while (file >> b_no >> b_name >> b_seats >> d_name) {
            if (t_no == b_no) {
                cout << "\n\n\n Delete Bus Record Successfully...";
                found++;
            }
            else {
                file1 << b_no << " " << b_name << " " << b_seats << " " << d_name << "\n";
            }
        }
        file.close();
        file1.close();
        remove("bus.txt");
        rename("bus1.txt", "bus.txt");
        if (found == 0) {
            cout << "\n\n Bus No. is Invalid...";
        }
    }
}

void bus::rout_bus()
{
	p:
	system("cls");
	int choice;
	cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
	cout<<"\n\n 1. 1st ROUT DETAILS";
	cout<<"\n 2. 2nd ROUT DETAILS";
	cout<<"\n 3. 3rd ROUT DETAILS";
	cout<<"\n 4. 4th ROUT DETAILS";
	cout<<"\n 5. 5th ROUT DETAILS";
	cout<<"\n\n Enter Your Choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			system("cls");
			cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
			cout<<"\n    From Lucknow to Delhi";
			cout<<"\n9:00 am ............................. 4:00 pm";
			cout<<"\n    From Ghaziabad to Delhi";
			cout<<"\n9:00 am ............................. 10:30 am";
			cout<<"\n    From Meerut to Delhi";
			cout<<"\n8:00 am ............................. 11:00 am";
			cout<<"\n    From Faridabad to Delhi";
			cout<<"\n7:00 am ............................. 9:00 am";
			cout<<"\n    From Chandigarh to Delhi";
			cout<<"\n1:00 pm ............................. 6:00 pm";
			cout<<"\n    From Lucknow to Delhi";
			cout<<"\n3:00 pm ............................. 11:00 pm";
			break;
		case 2:
			system("cls");
			cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
			cout<<"\n    From Rithala to Kashmere Gate";
			cout<<"\n9:00 am ............................. 12:00 pm";
			cout<<"\n    From Shahdara to Rithala";
			cout<<"\n9:00 am ............................. 10:30 am";
			cout<<"\n    From Chandni Chawk to NSP";
			cout<<"\n8:00 am ............................. 11:00 am";
			cout<<"\n    From Delhi cantt to New Delhi";
			cout<<"\n7:00 am ............................. 9:00 am";
			cout<<"\n    From Peeragarhi to Loni";
			cout<<"\n1:00 pm ............................. 5:00 pm";
			cout<<"\n    From Shahdara to Lal Quila";
			cout<<"\n3:00 pm ............................. 5:00 pm";
			break;
		case 3:
			system("cls");
			cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
			cout<<"\n    From Wazirabad to Kashmere Gate";
			cout<<"\n9:00 am ............................. 12:00 pm";
			cout<<"\n    From Anand vihar to Rithala";
			cout<<"\n9:00 am ............................. 10:30 am";
			cout<<"\n    From Chandni Chawk to Delhi cantt";
			cout<<"\n8:00 am ............................. 11:00 am";
			cout<<"\n    From Delhi cantt to NSP";
			cout<<"\n7:00 am ............................. 9:00 am";
			cout<<"\n    From Peeragarhi to India Gate";
			cout<<"\n1:00 pm ............................. 5:00 pm";
			cout<<"\n    From Shahdara to Kutub Minar";
			cout<<"\n3:00 pm ............................. 5:00 pm";
			break;
		case 4:
			system("cls");
			cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
			cout<<"\n    From Noida to Kashmere Gate";
			cout<<"\n9:00 am ............................. 12:00 pm";
			cout<<"\n    From Sector 16 to Sector 62";
			cout<<"\n9:00 am ............................. 10:30 am";
			cout<<"\n    From Sector 62 to NSP";
			cout<<"\n8:00 am ............................. 11:00 am";
			cout<<"\n    From Electronic City to New Delhi";
			cout<<"\n7:00 am ............................. 9:00 am";
			cout<<"\n    From City Centre to Pari chawk";
			cout<<"\n1:00 pm ............................. 5:00 pm";
			cout<<"\n    From Shahdara to Lal Quila";
			cout<<"\n3:00 pm ............................. 5:00 pm";
			break;
		case 5:
			system("cls");
			cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
			cout<<"\n    From Rithala to Kashmere Gate";
			cout<<"\n9:00 am ............................. 12:00 pm";
			cout<<"\n    From Shahdara to Rithala";
			cout<<"\n9:00 am ............................. 10:30 am";
			cout<<"\n    From Chandni Chawk to NSP";
			cout<<"\n8:00 am ............................. 11:00 am";
			cout<<"\n    From Delhi cantt to New Delhi";
			cout<<"\n7:00 am ............................. 9:00 am";
			cout<<"\n    From Peeragarhi to Loni";
			cout<<"\n1:00 pm ............................. 5:00 pm";
			cout<<"\n    From Shahdara to Lal Quila";
			cout<<"\n3:00 pm ............................. 5:00 pm";
			break;
		default:
			cout<<"\n\n Invalid Choice...Please Try Again";
			getch();
			goto p;
	}
}

void bus::detail_seats_bus()
{
	system("cls");
	fstream file,file1;
	string t_no, s_no, s_b_no;
	int count = 0, found =0; 
	cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
//	file1.open("seat.txt", ios::app|ios::out);
//	file1<<"1"<<" "<<5<<"\n";
//	file1<<"1"<<" "<<25<<"\n";
//	file1<<"1"<<" "<<35<<"\n";
//	file1.close();
	file.open("bus.txt", ios::in);
	file1.open("seat.txt",ios::in);
	if(!file || !file1)
	{
		cout<<"\n\n File Opening Error...";
	}
	else
	{
		cout<<"\n\n Enter Bus No. ";
		cin>>t_no;
		file1>>s_b_no>>s_no;
		while(!file1.eof())
		{
			if(t_no == s_b_no)
			{
				count++;
			}
			file1>>s_b_no>>s_no;
		}
		file1.close();
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof())
		{
			if(t_no==b_no)
			{
				system("cls");
				cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
				cout<<"\n\n Total No. of Seats : "<<b_seats;
				cout<<"\n\n Reserved  No. of Seats : "<<count;
				cout<<"\n\n Empty No. of Seats : "<<b_seats-count;
				found++;
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
		if(found==0)
		{
			cout<<"\n\n Bus No. is Invalid...";
		}
	}
}

void bus::booking() {
    p:
    system("cls");
    fstream file;
    string t_no, s_b_no, pas_name, phone, from, to;
    int found = 0, s_no, seats, count = 0, s_s_no, ss_no[50], i = 0, r_amount, s_amount, total_amount = 0;
    char x;
    cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
    file.open("bus.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error...";
    } else {
        cout << "\n\n Bus No. : ";
        cin >> t_no;
        file.close();
        file.open("seat.txt", ios::in);
        if (file) {
            while (file >> s_b_no >> s_s_no) {
                if (t_no == s_b_no) {
                    count++;
                }
            }
            file.close();
        }
        file.open("bus.txt", ios::in);
        while (file >> b_no >> b_name >> b_seats >> d_name) {
            if (t_no == b_no) {
                seats = b_seats;
                found++;
            }
        }
        file.close();
        if (seats - count == 0) {
            cout << "\n\n All Seats are already Reserved....";
        } else if (found == 1) {
            do {
                h:
                cout << "\n\n Seat No. : ";
                cin >> s_no;
                if (s_no > seats) {
                    cout << "\n\n Seat No. is Invalid...Please Try Again...";
                    goto h;
                }
                file.open("seat.txt", ios::in);
                if (!file) {
                    file.open("seat.txt", ios::app | ios::out);
                    file << t_no << " " << s_no << "\n";
                    file.close();
                } else {
                    while (file >> s_b_no >> s_s_no) {
                        if (t_no == s_b_no && s_no == s_s_no) {
                            cout << "\n\n Seat is Already Reserved... Please Try Again...";
                            file.close();
                            goto h;
                        }
                    }
                    file.close();
                    file.open("seat.txt", ios::app | ios::out);
                    file << t_no << " " << s_no << "\n";
                    file.close();
                }
                ss_no[i] = s_no;
                i++;
                cout << "\n\n Booking another Seat (Y/N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            system("cls");
            cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
            cout << "\n\n Passenger's Name : ";
            cin >> pas_name;
            cout << "\n\n Phone No. : ";
            cin >> phone;
            cout << "\n\n From : ";
            cin >> from;
            cout << "\n\n To : ";
            cin >> to;
            cout << "\n\n Single Seat Amount : ";
            cin >> s_amount;
            total_amount = s_amount * i;
            cout << "\n\n Total Amount : " << total_amount;
            cout << "\n\n Pay Amount : ";
            cin >> r_amount;
            file.open("customer.txt", ios::app | ios::out);
            file << pas_name << " " << t_no << " " << phone << " " << i << " " << total_amount << "\n";
            file.close();
            system("cls");
            cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
            cout << "\n\n\t\t*********************************************";
            cout << "\n\n\t\t____________Booking Information____________\n";
            cout << "\n\n\t\t*********************************************";
            cout << "\n\n\t\tPassenger's Name :                    " << pas_name;
            cout << "\n\t\tFrom :                                " << from;
            cout << "\n\t\tTo :                                  " << to;
            cout << "\n\t\tTotal Seats :                         " << i;
            cout << "\n\t\tReserved Seats :                      ";
            for (int a = 0; a < i; a++) {
                if (a != 0)
                    cout << ",";
                cout << ss_no[a];
            }
            cout << "\n\t\tSingle Amount :                      " << s_amount;
            cout << "\n\t\tTotal Amount :                       " << total_amount;
            cout << "\n\t\tReceived Amount :                    " << r_amount;
            cout << "\n\t\tReturn Amount :                      " << r_amount - total_amount;
            cout << "\n\n\t\t*********************************************";
            cout << "\n\n\t\t      Thank You So Much For Booking";
            cout << "\n\n\t\t*********************************************";
        } else {
            cout << "\n\n Invalid Bus No. Please Try Again...";
            getch();
            goto p;
        }
    }
}

void bus::renew_bus()
{
	 system("cls"); // This clears the console screen, but it's not portable, consider alternatives

    fstream file;
    char x;

    cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
    file.open("seat.txt", ios::in);

    if (!file) {
        cout << "\n\n File Opening Error...";
    } else {
        cout << "\n\n Do You Want to Renew All Seats (Y/N) : ";
        cin >> x;

        if (x == 'Y' || x == 'y') {
            if (remove("seat.txt") == 0) {
                cout << "\n\n\t\t Error Deleting File.";
            } else {
                cout << "\n\n\t\t All Seats Are Empty....";
            }
        } else {
            cout << "\n\n\t\t Thank You. All Seats Reservation Saved...";
        }
    }
    file.close(); // Close the file after using it
}


void bus::search_booking()
{
	system("cls");
	string t_name,name,no,phone;
	int t_seats,t_amo,found=0;
	fstream file;
	cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
	file.open("customer.txt", ios::in);
	if(!file)
	{
		cout<<"\n\n File Opening Error...";
	}
	else
	{
		cout<<"\n\n Customer Name : ";
		cin>>t_name;
		
		while(file>>name>>no>>phone>>t_seats>>t_amo)
		{
			if(t_name == name)
			{
				if(found == 0)
				{
					system("cls");
					cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
				}
				cout<<"\n\n\n Customer Name : "<<name;
				cout<<"\n\n Bus No. : "<<no;
				cout<<"\n\n Phone No. : "<<phone;
				cout<<"\n\n Reserved Seats : "<<t_seats;
				cout<<"\n\n Total Amount : "<<t_amo;
				cout<<"\n\n=======================================";
				found++;
			}
		}
		file.close();
		if(found == 0)
		{
			cout<<"\n\n Passenger's Name is Invalid....";
		}
	}
}

void bus::update_booking()
{
	system("cls");
	string t_phone, no, name, phone, del_no;
	int t_seats, t_amo, found = 0, del_seats, i = 0;
	fstream file, file1;
	cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
	file.open("customer.txt", ios::in);
	if(!file)
	{
		cout<<"\n\n File Opening Error....";
	}
	else
	{
		cout<<"\n\n Phone No. : "; cin>>t_phone;
		
		while(file>>name>>no>>phone>>t_seats>>t_amo)
		{
			if(t_phone == phone)
			{
				file.close();
				file.open("customer.txt",ios::in);
				file1.open("customer1.txt", ios::app|ios::out);
				while(file>>name>>no>>phone>>t_seats>>t_amo)
				{
					if(t_phone == phone)
					{
						del_no = no;
						del_seats = t_seats;
					}
					if(t_phone != phone)
					{
						file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<"\n";
					}
				}
				file.close();
				file1.close();
				remove("customer.txt");
				rename("customer1.txt","customer.txt");
				file.open("seat.txt", ios::in);
				file1.open("seat1.txt", ios::app|ios::out);
				
				while(file>>no>>t_seats)
				{
					if(!(del_no == no && i < del_seats))
					{
						file1<<no<<" "<<t_seats<<"\n";
					}
					file>>no>>t_seats;
				}
				file.close();
				file1.close();
				remove("seat.txt");
				rename("seat1.txt", "seat.txt");
				booking();
				found++;
				goto h;
			}
		}
		file.close();
		h:
		if(found == 0)
		{
			cout<<"\n\n Phone No. is Invalid...";
		}
	}
}


void bus::del_booking()
{
		system("cls");
	string t_phone, no, name, phone, del_no;
	int t_seats, t_amo, found = 0, del_seats, i = 0;
	fstream file, file1;
	cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
	file.open("customer.txt", ios::in);
	if(!file)
	{
		cout<<"\n\n File Opening Error....";
	}
	else
	{
		cout<<"\n\n Phone No. : "; cin>>t_phone;
		
		while(file>>name>>no>>phone>>t_seats>>t_amo)
		{
			if(t_phone == phone)
			{
				file.close();
				file.open("customer.txt",ios::in);
				file1.open("customer1.txt", ios::app|ios::out);
				while(file>>name>>no>>phone>>t_seats>>t_amo)
				{
					if(t_phone == phone)
					{
						del_no = no;
						del_seats = t_seats;
					}
					if(t_phone != phone)
					{
						file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<"\n";
					}
				}
				file.close();
				file1.close();
				remove("customer.txt");
				rename("customer1.txt","customer.txt");
				file.open("seat.txt", ios::in);
				file1.open("seat1.txt", ios::app|ios::out);
				
				while(file>>no>>t_seats)
				{
					if(!(del_no == no && i < del_seats))
					{
						file1<<no<<" "<<t_seats<<"\n";
					}
					file>>no>>t_seats;
				}
				file.close();
				file1.close();
				remove("seat.txt");
				rename("seat1.txt", "seat.txt");
				found++;
				goto h;
			}
			
		}
		cout<<"\n\n Booking Deleted....";
		file.close();
		h:
		if(found == 0)
		{
			cout<<"\n\n Phone No. is Invalid...";
		}
	}
}

void bus::show_booking()
{
	system("cls");
	string name,no,phone;
	int t_seats,t_amo,found=0;
	fstream file;
	cout << "\n\t\t____________BUS MANAGEMENT SYSTEM____________\n";
	file.open("customer.txt", ios::in);
	if(!file)
	{
		cout<<"\n\n File Opening Error...";
	}
	else
	{
		while(file>>name>>no>>phone>>t_seats>>t_amo)
		{
			
			cout<<"\n\n\n Customer Name : "<<name;
			cout<<"\n\n Bus No. : "<<no;
			cout<<"\n\n Phone No. : "<<phone;
			cout<<"\n\n Reserved Seats : "<<t_seats;
			cout<<"\n\n Total Amount : "<<t_amo;
			cout<<"\n\n=======================================";
			found++;
		}
		file.close();
		if(found == 0)
		{
			cout<<"\n\n No Any Booking Record Found....";
		}
	}
}

int main()
{
	bus b;
	p:
	system("cls");
	string email,pass;
	char ch;
	cout<<"\n\n\t\t\t******Security are Required******";
	cout<<"\n\nEmail: ";
	cin>>email;
	cout<<"\n\nPassword: ";
	for(int i=1;i<=6;i++)
	{
		ch = getch();
		pass += ch;
		cout<<"*";
	}
	if(email == "pk621790@gmail.com" && pass == "Pankaj")
	{
		cout<<"\n\n\n\t\t\tLoading";
		for(int i=0;i<5;i++)
		{
			Sleep(500);
			cout<<".";
		}
		b.menu();
	}
	else
	{
		cout<<"\n\n\t\tYour Email and Password is wrong! ";
		goto p;
	}
}
