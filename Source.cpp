#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

class Room
{
	string room_code;
	string room_type;
public:
	void boot_room_data(string boot_room_code, string boot_room_type);
	void get_room_data();
	void put_room_data();
	string call_room_code();
	string call_room_type();
};

void Room::boot_room_data(string boot_room_code, string boot_room_type)
{
	room_code = boot_room_code;
	room_type = boot_room_type;
}

void Room::get_room_data()
{
	cout << "Enter room code: ";
	cin >> room_code;
	cout << "Enter room type: ";
	cin >> room_type;
}

void Room::put_room_data()
{
	cout << room_code << " ";
	cout << room_type << " ";
	cout << endl;
}

string Room::call_room_code()
{
	return room_code;
}

string Room::call_room_type()
{
	return room_type;
}

class ID_Card
{
	string f_name;
	string l_name;
	int ID;
	int age;
	string role;
public:
	void boot_holder_data(string boot_fname, string boot_lname, string boot_ID, string boot_age, string boot_role);
	void get_ID_data();
	void put_ID_data();
	int call_holder_ID();
	string call_holder_role();
	string call_holder_fname();
	string call_holder_lname();
	int call_holder_age();
};

void ID_Card::boot_holder_data(string boot_fname, string boot_lname, string boot_ID, string boot_age, string boot_role)
{
	f_name = boot_fname;
	l_name = boot_lname;
	ID = stoi(boot_ID);
	age = stoi(boot_age);
	role = boot_role;
}

void ID_Card::get_ID_data()
{
	cout << "Enter First Name: ";
	cin >> f_name;
	cout << "Enter Last Name: ";
	cin >> l_name;
	cout << "Enter ID: ";
	cin >> ID;
	cout << "Enter Age: ";
	cin >> age;
	cout << "Enter Role: ";
	cin >> role;
}

void ID_Card::put_ID_data()
{
	cout << f_name << " ";
	cout << l_name << " ";
	cout << ID << " ";
	cout << age << " ";
	cout << role << " ";
	cout << endl;
}

string ID_Card::call_holder_fname()
{
	return f_name;
}

string ID_Card::call_holder_lname()
{
	return l_name;
}

int ID_Card::call_holder_ID()
{
	return ID;
}

string ID_Card::call_holder_role()
{
	return role;
}

int ID_Card::call_holder_age()
{
	return age;
}

class Access
{
public:
	void attempt_access(string first_name, string last_name, int ID_number, string room, bool access_granted, bool room_state);
};

void Access::attempt_access(string first_name, string last_name, int ID_number, string room, bool access_granted, bool room_state)
{
	time_t result = time(NULL);

	char str[26];
	ctime_s(str, sizeof str, &result);

	ofstream MyFile;
	
	MyFile.open("Access_Log.txt", ios::app);

	MyFile << str << "Name: " << first_name << " " << last_name << " ID_number: " << ID_number << " room code: " << room << " access granted: " << access_granted << " " << " emergency_mode: " << room_state << "\n";

	MyFile.close();
}


class Boot
{
public:
	string boot_room_code;
	string boot_room_type;
	string boot_emergency_mode;
	string boot_fname;
	string boot_lname;
	string boot_ID;
	string boot_age;
	string boot_role;
	string delimiter = " ";
	void splitStringrooms(string str, string delimiter = " ");
	void splitStringholders(string str, string delimiter = " ");
};

void Boot::splitStringrooms(string str, string delimiter)
{
	int i = 0;
	int start = 0;
	int end = str.find(delimiter);
	while (end != -1)
	{
		//cout << str.substr(start, end - start) << endl;
		if (i == 0)
			boot_room_code = str.substr(start, end - start);
		else if (i == 1)
			boot_room_type = str.substr(start, end - start);
		start = end + delimiter.size();
		end = str.find(delimiter, start);
		i++;
	}
	system("CLS");
	if (i == 2)
		boot_emergency_mode = str.substr(start, end - start);
	//cout << boot_room_code << "\n" << boot_room_type << "\n" << boot_emergency_mode;
}

void Boot::splitStringholders(string str, string delimiter)
{
	int i = 0;
	int start = 0;
	int end = str.find(delimiter);
	while (end != -1)
	{
		//cout << str.substr(start, end - start) << endl;
		if (i == 0)
			boot_fname = str.substr(start, end - start);
		if (i == 1)
			boot_lname = str.substr(start, end - start);
		if (i == 2)
			boot_ID = str.substr(start, end - start);
		if (i == 3)
			boot_age = str.substr(start, end - start);
		start = end + delimiter.size();
		end = str.find(delimiter, start);
		i++;
	}
	system("CLS");
	if (i == 4)
		boot_role = str.substr(start, end - start);
	//cout << str.substr(start, end - start);
}




int main()
{
	Room rooms[50];
	ID_Card holders[50];
	Access access;
	Boot boot;
	int n, i, j;
	int current_number_of_rooms = 0;
	int current_number_of_holders = 0;
	int use_selection;
	bool run_program = true;
	string desired_room_code;
	int holders_ID;
	bool emergency = false;
	bool access_granted = false;
	string boot_info;

	ifstream MyReadFile;

	MyReadFile.open("Room_List.txt");

	while (getline(MyReadFile, boot_info))
	{
		boot.splitStringrooms(boot_info, " ");

		rooms[current_number_of_rooms].boot_room_data(boot.boot_room_code, boot.boot_room_type);
		if (boot.boot_emergency_mode == "0")
			emergency = false;
		else if (boot.boot_emergency_mode == "1")
			emergency = true;

		current_number_of_rooms++;

		//_getch();		Test
	}

	system("CLS");

	MyReadFile.close();



	MyReadFile.open("Card_Holder_List.txt");

	while (getline(MyReadFile, boot_info))
	{
		boot.splitStringholders(boot_info, " ");

		holders[current_number_of_holders].boot_holder_data(boot.boot_fname, boot.boot_lname, boot.boot_ID, boot.boot_age, boot.boot_role);

		current_number_of_holders++;

		//_getch();		Test
	}

	system("CLS");

	MyReadFile.close();

	//_getch();			Test


	while (run_program == true)
	{
		system("CLS");
		cout << "Welcome, Are You an Admin or a Card Holder?\n\n" << "1. Admin\n" << "2. Card Holder\n" << "3. Exit Program\n\n";
		cin >> use_selection;
		system("CLS");

		switch (use_selection)
		{
		case 1:
			cout << "Admin: \n\n";
			cout << "What do you want to do?\n\n" << "1. Add Rooms\n" << "2. View Room List\n" << "3. Add Card Holders\n" << "4. View Card Holders\n" << "5. Set Emergency Mode\n" << "6. Exit Program\n\n";
			cin >> use_selection;
			system("CLS");

			switch (use_selection)
			{
			case 1:
				cout << "Enter Number of Rooms to Add - ";
				cin >> n;

				for (i = 0 + current_number_of_rooms; i < n + current_number_of_rooms; i++)
				{
					rooms[i].get_room_data();
					system("CLS");
				}

				current_number_of_rooms = n + current_number_of_rooms;

				//Display Rooms When Adding
				//--------------------------------------------

				cout << "Rooms Data - " << endl;

				for (i = 0; i < n + current_number_of_rooms; i++)
					rooms[i].put_room_data();

				_getch();

				//--------------------------------------------

				break;

			case 2:
				cout << "Rooms Data - " << endl;

				for (i = 0; i < current_number_of_rooms; i++)
					rooms[i].put_room_data();

				_getch();

				break;

			case 3:
				cout << "Enter Number of Holders - ";
				cin >> n;

				for (i = 0 + current_number_of_holders; i < n + current_number_of_holders; i++)
				{
					holders[i].get_ID_data();
					system("CLS");
				}

				current_number_of_holders = n + current_number_of_holders;

				//Display Holders When Adding
				//--------------------------------------------

				cout << "Holders Data - " << endl;

				for (i = 0; i < n + current_number_of_holders; i++)
					holders[i].put_ID_data();

				_getch();

				//--------------------------------------------

				break;

			case 4:
				cout << "Holders Data - " << endl;

				for (i = 0; i < current_number_of_holders; i++)
					holders[i].put_ID_data();

				_getch();

				break;

			case 5:
				cout << "Set Emergency Mode?\n" << "1. Yes" << "2. No";
				cin >> use_selection;
				switch (use_selection)
				{
				case 1:
					emergency = true;
					break;
				case 2:
					emergency = false;
					break;
				}

			case 6:
				ofstream MyFile;

				MyFile.open("Room_List.txt");

				for (i = 0; i < current_number_of_rooms; i++)
					MyFile << rooms[i].call_room_code() << " " << rooms[i].call_room_type() << " " << emergency << "\n";

				MyFile.close();

				MyFile.open("Card_Holder_List.txt");

				for (i = 0; i < current_number_of_holders; i++)
					MyFile << holders[i].call_holder_fname() << " " << holders[i].call_holder_lname() << " " << holders[i].call_holder_ID() << " " << holders[i].call_holder_age() << " " << holders[i].call_holder_role() << "\n";

				MyFile.close();

				run_program = false;
				break;
			}

			break;

		case 2:
			cout << "Card Holder: \n\n";

			cout << "What is your holder ID?";
			cin >> holders_ID;

			for (i = 0; i < current_number_of_holders; i++)
			{
				if (holders_ID == holders[i].call_holder_ID())
				{
					cout << "What Room do You Want to Enter?\n\n";
					cin >> desired_room_code;

					for (j = 0; j < current_number_of_rooms; j++)
					{
						if (desired_room_code == rooms[j].call_room_code())
						{
							if (rooms[j].call_room_type() == "Lecture")
							{
								if (holders[i].call_holder_role() == "Staff")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Student")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Visitor")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Cleaner")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Manager")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Security")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "ER") // Emergency Responder
								{
									if (emergency == false)
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
							}



//-------------------------------------------------------------------------------------------------------------------------------------------




							else if (rooms[j].call_room_type() == "Teaching")
							{
								if (holders[i].call_holder_role() == "Staff")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();	//Test
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Student")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Visitor")
								{
									if (emergency == false)
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Cleaner")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Manager")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Security")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "ER") // Emergency Responder
								{
									if (emergency == false)
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
							}



//-------------------------------------------------------------------------------------------------------------------------------------------




							else if (rooms[j].call_room_type() == "Staff")
							{
								if (holders[i].call_holder_role() == "Staff")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();	//Test
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Student")
								{
									if (emergency == false)
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Visitor")
								{
									if (emergency == false)
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Cleaner")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Manager")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Security")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "ER") // Emergency Responder
								{
									if (emergency == false)
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
							}



//-------------------------------------------------------------------------------------------------------------------------------------------




							else if (rooms[j].call_room_type() == "Secure")
							{
								if (holders[i].call_holder_role() == "Staff")
								{
									if (emergency == false)
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();	//Test
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Student")
								{
									if (emergency == false)
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Visitor")
								{
									if (emergency == false)
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Cleaner")
								{
									if (emergency == false)
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Manager")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "Security")
								{
									if (emergency == false)
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
								else if (holders[i].call_holder_role() == "ER") // Emergency Responder
								{
									if (emergency == false)
									{
										access_granted = false;
										cout << "access_denied";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
									else
									{
										access_granted = true;
										cout << "access_granted";
										access.attempt_access(holders[i].call_holder_fname(), holders[i].call_holder_lname(), holders[i].call_holder_ID(), rooms[j].call_room_code(), access_granted, emergency);
										_getch();
									}
								}
							}

						}

						system("CLS");

					}

				}

			}			

			break;

		case 3:
			ofstream MyFile;

			MyFile.open("Room_List.txt");

			for (i = 0; i < current_number_of_rooms; i++)
				MyFile << rooms[i].call_room_code() << " " << rooms[i].call_room_type() << " " << emergency << "\n";

			MyFile.close();

			MyFile.open("Card_Holder_List.txt");

			for (i = 0; i < current_number_of_holders; i++)
				MyFile << holders[i].call_holder_fname() << " " << holders[i].call_holder_lname() << " " << holders[i].call_holder_ID() << " " << holders[i].call_holder_age() << " " << holders[i].call_holder_role() << "\n";

			MyFile.close();

			run_program = false;
			break;
		}

		ofstream MyFile;

		MyFile.open("Room_List.txt");

		for (i = 0; i < current_number_of_rooms; i++)
			MyFile << rooms[i].call_room_code() << " " << rooms[i].call_room_type() << " " << emergency << "\n";

		MyFile.close();

		MyFile.open("Card_Holder_List.txt");

		for (i = 0; i < current_number_of_holders; i++)
			MyFile << holders[i].call_holder_fname() << " " << holders[i].call_holder_lname() << " " << holders[i].call_holder_ID() << " " << holders[i].call_holder_age() << " " << holders[i].call_holder_role() << "\n";

		MyFile.close();

		run_program = false;
	}
}
