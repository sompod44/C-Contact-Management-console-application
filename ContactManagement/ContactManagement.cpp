#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;
int totalcontact = 0;
void Ncontact(int serial,string name,string phone); // new contact create function prototype
int main() {
yy: // this is scope
	int count = 0;

	cout<<"\t\t########################################"<<endl;
	cout<<"\t\t#####Store and Manage your contacts#####"<<endl;
	cout<<"\t\t########################################\n"<<endl;

	char AorSorD;

	cout<<"Press A for : Add new contact "<<endl;
	cout<<"Press B for : Show All contacts "<<endl;

	cin>>AorSorD;
	if(AorSorD == 'a' || AorSorD == 'A') {
xx: // this is scope
		string name,phone;
		cout<<"Enter Name : ";
		cin>>name;
		cout<<endl<< "Enter Phone Number : ";
		cin>>phone;

		ifstream tc ("Totalcount.txt");
		if(tc.is_open()) {
			while(!tc.eof()) {
				string s;
				getline(tc,s);
				stringstream (s) >> count;

			}
		}
		++count;
		Ncontact(count,name,phone); // this is function which store contact information

		ofstream sc ("Totalcount.txt");
		sc << to_string(count);
		sc.close();
x:
		string s;
		int n;
		cout<< "Enter 1 for again Add new contact OR Enter 2 for Goto Main Menu."<<endl;
		while(1) {
			cin>>s;
			stringstream(s)>>n;
			if(n==1) {
				goto xx;
				break;
			} else if(n==2) {
				system("cls");
				goto yy;
				break;
			}

		}


	} else if(AorSorD == 'b' || AorSorD == 'B') {
		count = 1;
		ifstream tc ("Totalcount.txt");
		if(tc.is_open()) {
			while(!tc.eof()) {
				string s;
				getline(tc,s);
				stringstream (s) >> count;

			}
		}

		for(int i=1; i<= count; i++) {
			cout<<"Contact No : "<<i<<endl;
			ifstream c ("SerialContact/"+to_string(i)+".txt");
			if(c.is_open()) {
				while(!c.eof()) {
					string s;
					getline(c,s);
					cout<<s<<endl;

				}
			}
		}

		cout<< "Enter 1 for again run software : ";
		int t;
		cin>>t;
		if(t==1) {
			system("cls");
			goto yy;
		} else {
			return 1;
		}
	}
	
	system("pause");

	return 0;
}

void Ncontact(int serial,string name,string phone) {
	string str = name + to_string(serial); // to string is a build in function

	ofstream ncontact,allcontact;
	ncontact.open("Contacts/"+str + ".txt");
	allcontact.open("SerialContact/" + to_string(serial) + ".txt");
	ncontact<<"Name : "+name+"\n";
	ncontact<<"Phone Number : "+phone+"\n";
	ncontact.close();
	allcontact<<"Name : "+name+"\n";
	allcontact<<"Phone Number : "+phone+"\n";
	allcontact.close();
	
}
