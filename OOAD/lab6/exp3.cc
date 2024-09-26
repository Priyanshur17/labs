#include<iostream>
#include<string>
#include<map>
#include<fstream>

using namespace std;


void Menu()
{
	cout << "\nChoose from the following:"
		<< "\nA - Add new record"
		<< "\nS - Show the all record"
		<< "\nD - Delete the record"
		<< "\nU - Update the record"
		<< "\nF - Update data in file"
		<< "\nE - Exit program";
	cout << "\nMake a select: ";
}


struct Record
{
	string toolName;
	int quantity;
	float cost;
};


void AddRecord(map<int, Record>& m)
{
	int num;
	Record r;
	cout << "Enter a number of the record: ";
	cin >> num;
	cout << "Enter a tool Name: ";
	cin >> r.toolName;
	cout << "Enter a quantity: ";
	cin >> r.quantity;
	cout << "Enter a cost: ";
	cin >> r.cost;
	m[num] = r;
}


void ShowRecords(map<int, Record>& m)
{
	map<int, Record>::iterator it;
	for (it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second.toolName << " "
			<< it->second.quantity << " " << it->second.cost << endl;
	}
}


void DeleteRecord(map<int, Record>& m)
{
	int n;
	cout << "Please, enter a number of record: ";
	cin >> n;
	m.erase(n);
}

void UpdateRecord(map<int, Record>& m)
{
	int n;
	cout << "Please, enter a number of record to update: ";
	cin >> n;
	cout << "Enter a tool Name: ";
	cin >> m[n].toolName;
	cout << "Enter a quantity: ";
	cin >> m[n].quantity;
	cout << "Enter a cost: ";
	cin >> m[n].cost;
}


void UpdateFile(map<int, Record>& m)
{
	ofstream of;
	of.open("Inventory.txt",ofstream::out| ofstream::trunc);
	if (!of.is_open())
		cout << "File isn`t opened!";
	else
	{
		map<int, Record>::iterator it;
		for (it = m.begin(); it != m.end(); ++it)
		{
			of << it->first << " " << it->second.toolName << " "
				<< it->second.quantity << " " << it->second.cost << endl;
		}
	}
	of.close();
}


int main()
{
	map<int, Record>m;
	ifstream ifs("Inventory.txt");
	if (!ifs.is_open())
		cout << "File isn`t opened!";
	else
	{
		string line;
		while (getline(ifs, line, '\n'))
		{
			string str = line.substr(0, line.find(' '));
			int num = stoi(str);
			Record r;
			line = line.substr(line.find(' ') + 1);
			str = line.substr(0, line.find(' '));
			r.toolName=str;
			line = line.substr(line.find(' ') + 1);
			str = line.substr(0, line.find(' '));
			r.quantity = stoi(str);
			line = line.substr(line.find(' ') + 1);
			str = line.substr(0, line.find(' '));
			r.cost= stod(str);
			m[num] = r;
		}
		ifs.close();
	}
	
	char choice;
	do
	{
		Menu();
		cin >> choice;
		switch (choice)
		{
			case 'A':case 'a':
			{
				AddRecord(m);
				break;
			}
			case 'S':case 's':
			{
				ShowRecords(m);
				break;
			}
			case 'D':case 'd':
			{
				DeleteRecord(m);
				break;
			}
			case 'U':case 'u':
			{
				UpdateRecord(m);
				break;
			}
			case 'F':case 'f':
			{
				UpdateFile(m);
				break;
			}
		}
	} while (choice != 'E');
}