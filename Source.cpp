#include<iostream>
#include <fstream>
#include <string>
using namespace std;

bool checkLoggin() {
	string username, password;
	cout << "Enter Username: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;

	string usernameInside, passwordInside;
	ifstream file;
	file.open("accounts\\" + username + ".txt");
	getline(file, usernameInside);
	getline(file, passwordInside);

	if (usernameInside == username && passwordInside == password) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int choice;

	do {
		cout << "1: Register" << endl << "2:Login" << endl << "3:Exit" << endl<< "Your Choice: ";
		cin >> choice;
		if (choice == 1) {
			string username, password;

			cout << "Select a Username: ";
			cin >> username;

			string filename= "accounts/" + username +".txt";
			if (FILE* file = fopen(filename.c_str(), "r")) {
				fclose(file);
				cout << "This username already exits, please login" << endl;
			}
			else {
				cout << "Select a Password: ";
				cin >> password;
				ofstream MyFile;
				MyFile.open("data\\" + username + ".txt");
				MyFile << username << endl << password;
				MyFile.close();
				main();
			}

		}
		else if (choice == 2) {
			bool isLoggin = checkLoggin();

			if (!isLoggin) {
				cout << "Incorrect Username Or Password!" << endl;
			}
			else {
				cout << "Succesfully Logged In" << endl;
			}
		}
		else if (choice == 3) {
			break;
		}
	} while (choice !=3);
}
