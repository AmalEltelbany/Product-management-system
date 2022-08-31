#include<string>
#include <iomanip>
#include <cstdlib>
#include <iostream>	
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.>
using namespace std;
class product {
public:
	int pno;
	string name;
	float price, qty, dis;
	void create_product()
	{
		cout << "Please Enter The Name of The Product :";
		cin >> name;
		cout << "Please Enter The Product No. of The Product :";
		cin >> pno;
		cout << "Please Enter The Price of The Product : ";
		cin >> price;
		cout << "Please Enter The Discount (%) : ";
		cin >> dis;
	}
	void show_product()
	{
		cout << "\nThe Name of The Product : " << name;
		cout << "\nThe Product No. of The Product : " << pno;
		cout << "\nThe Price of The Product : " << price << "LE";
		cout << "\nDiscount : " << dis << "%";
	}
	int retpno()
	{
		return pno;
	}
	float retprice()
	{
		return price;
	}
	string retname()
	{
		return name;
	}
	int retdis()
	{
		return dis;
	}

};
fstream fp;
product pr;
void main();
void login();
void registr();
void forgot();
void place_order();
void admin_menu();
void accounts()
{
	int choice;
	cout << "***********************************************************************\n\n";
	cout << "                      Welcome To Login Page                               \n\n";
	cout << "*******************        MENU        *******************************\n\n";
	cout << "1.LOGIN" << endl;
	cout << "2.REGISTER" << endl;
	cout << "3.FORGOT PASSWORD (or) USERNAME" << endl;
	cout << "4.Exit" << endl;
	cout << "\nEnter your choice :";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		login();
		break;
	case 2:

		registr();
		break;
	case 3:
		forgot();
		break;
	case 4:
		cout << "Thanks For Using This Program.\n\n";
		exit(0);
		break;
	default:
		system("cls");
		cout << "You've Made a Mistake , Try Again..\n" << endl;
		accounts();
	}

}
void password() {
	fp.open("password.txt", ios::in);
	if (!fp) {
		ofstream fp("password.txt", ios::app);
		fp << "maha" << endl;
		fp.close();
	}
	fp.close();
	string p, pass;
	int count = {};
	cout << "Please Enter Your Password" << endl;
	cout << "PASSWORD :";
	cin >> pass;
	ifstream input("password.txt");
	while (input >> p)
	{
		if (p == pass)

		{
			count++;
			system("cls");
		}
	}
	input.close();
	if (count == 1)
	{
		cout << "\nHello :)\t";
		system("pause");
	}
	if (count != 1)
	{
		cout << "\nPlease Check Your Password\n";
		system("pause");
		password();
	}

}
void change_password() {
	string no;
	cout << "\n\n\tTo change password ";
	cout << "\n\n\t******Please Enter The old password******\n";
	password();
	cout << "\nPlease Enter The New password:" << endl;
	ifstream intf("password.txt");
	cin >> no;
	intf.close();
	cout << "\n\nThe New Password Has Been updated ";
	ofstream outf("password.txt");
	outf << no;
	outf.close();

}
void login()
{
	int count = {};
	string user, pass, u, p;
	system("cls");
	cout << "Please Enter The Following Details" << endl;
	cout << "USERNAME :";
	cin >> user;
	cout << "PASSWORD :";
	cin >> pass;

	ifstream input("database.txt");
	while (input >> u >> p)
	{
		if (u == user && p == pass)

		{
			count++;
			system("cls");
		}
	}
	input.close();
	if (count == 1)
	{
		cout << "\nHello\t" << user << "\n<LOGIN SUCCESSFUL>\nThanks For Logging In..\n";

		system("pause");
		place_order();
	}
	if (count != 1)
	{
		cout << "\nLOGIN ERROR\nPlease Check Your Username And Password\n";
		cout << "This Account Is Incorrect";
		accounts();
	}
}
void registr()
{
	int count = {};
	string reguser, regpass, ru, rp, u, p;
	system("cls");
	cout << setw(50) << "***Welcom New Customer***\n";
	cout << "Enter The Username :";
	cin >> reguser;
	cout << "\nEnter The Password :";
	cin >> regpass;

	ifstream input("database.txt");
	while (input >> u)
	{
		if (u == reguser)
		{
			count++;
		}
	}
	input.close();
	if (count == 1)
	{
		cout << "\nThere is a user with the same username, please select another username\n";
		system("pause");
		accounts();
	}
	if (count != 1)
	{
		ofstream reg("database.txt", ios::app);
		reg << reguser << ' ' << regpass << endl;
		system("cls");
		cout << "\nRegistration Sucessful :)\n";
		system("pause");
		system("cls");
		accounts();
	}

}

void forgot()
{
	int ch;
	system("cls");
	cout << "Forgotten ? We're Here For Help\n";
	cout << "1.Search Your Account By Username" << endl;
	cout << "2.Search Your Account By Password" << endl;
	cout << "3.Main Menu" << endl;
	cout << "Enter your choice :";
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		int count = 0;
		string searchuser, su, sp;
		cout << "\nEnter Your Remembered Username :";
		cin >> searchuser;

		ifstream searchu("database.txt");
		while (searchu >> su >> sp)
		{
			if (su == searchuser)
			{
				count = 1;
			}
		}
		searchu.close();
		if (count == 1)
		{
			cout << "\n\n  Account Found :)\n";
			cout << "\nYour Password Is " << sp;
			cin.get();
			cin.get();
			system("cls");
			accounts();
		}
		else
		{
			cout << "\nSorry, Your Username  Is Not Found In Our Database\n";
			cout << "\nPlease Contact Your System Administrator For More Details \n";
			cin.get();
			cin.get();
			accounts();
		}
		break;
	}
	case 2:
	{
		int count = 0;
		string searchpass, su2, sp2;
		cout << "\nEnter The Remembered Password :";
		cin >> searchpass;

		ifstream searchp("database.txt");
		while (searchp >> su2 >> sp2)
		{
			if (sp2 == searchpass)
			{
				count = 1;
			}
		}
		searchp.close();
		if (count == 1)
		{
			cout << "\nYour Password Is Found In The Database \n";
			cout << "\nYour Username is : " << su2;
			cin.get();
			cin.get();
			system("cls");
			accounts();
		}
		else
		{
			cout << "Sorry, We Cannot Found Your Password In Our Database \n";
			cout << "\nPlease Contact Your Administrator For More Information\n";
			cin.get();
			cin.get();
			accounts();
		}

		break;
	}

	case 3:
	{
		cin.get();
		main();
	}
	default:
		cout << "Sorry, You Entered Wrong Choice, Please Try Again" << endl;
		forgot();
	}
}
void write_product()
{
	fp.open("product.txt", ios::out | ios::app);
	pr.create_product();
	fp.write((char*)&pr, sizeof(product));
	fp.close();
	cout << "The Product Has Been Created ";
}
void display_all()
{
	system("cls");
	cout << "\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	fp.open("product.txt", ios::in);
	while (fp.read((char*)&pr, sizeof(product)))
	{
		pr.show_product();
		cout << "\n\n====================================\n";
	}
	fp.close();
}
void delete_product()
{
	int no;
	system("cls");
	cout << "\n\n\n\tDelete Record";
	cout << "\n\nPlease Enter The product no. of The Product You Want To Delete:";
	cin >> no;
	fp.open("product.txt", ios::in | ios::out);
	fstream fp2;
	fp2.open("product2.txt", ios::out);
	fp.seekg(0, ios::beg);
	while (fp.read((char*)&pr, sizeof(product)))
	{
		if (pr.retpno() != no)
		{
			fp2.write((char*)&pr, sizeof(product));
		}
	}
	fp2.close();
	fp.close();
	remove("product.txt");
	rename("product2.txt", "product.txt");
	cout << "\n\tRecord Deleted ..";
}
void display_sp(int n)
{
	int flag = 0;
	fp.open("product.txt", ios::in);
	while (fp.read((char*)&pr, sizeof(product)))
	{
		if (pr.retpno() == n)
		{
			system("cls");
			pr.show_product();
			flag = 1;
		}
	}
	fp.close();
	if (flag == 0)
		cout << "\n\nrecord not exist";
}
void modifyByDelete(int no) {

	fp.open("product.txt", ios::in | ios::out);
	fstream fp2;
	fp2.open("product2.txt", ios::out);
	fp.seekg(0, ios::beg);
	while (fp.read((char*)&pr, sizeof(product)))
	{
		if (pr.retpno() != no)
		{
			fp2.write((char*)&pr, sizeof(product));
		}
	}
	fp2.close();
	fp.close();
	remove("product.txt");
	rename("product2.txt", "product.txt");

}

void modify_product()
{
	int no, found = 0;
	system("cls");
	cout << "\n\n\tTo Modify ";
	cout << "\n\n\tPlease Enter The Product No. of The Product:";
	cin >> no;
	fp.open("product.txt", ios::in | ios::out);
	while (fp.read((char*)&pr, sizeof(product)) && found == 0)
	{
		if (pr.retpno() == no)
		{
			fp.close();
			pr.show_product();
			cout << "\nPlease Enter The New Details of Product:" << endl;
			modifyByDelete(no);
			write_product();

			int pos = -1 * (int)sizeof(pr);
			fp.seekp(pos, ios::cur);
			fp.write((char*)&pr, sizeof(product));
			cout << "\n\n\t Record Updated";
			found = 1;
		}
	}
	fp.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";
}
void menu()
{
	system("cls");
	fp.open("product.txt", ios::in);
	if (!fp)
	{
		cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
		cout << "\n\n\n Program is closing ….";
		exit(0);
	}
	cout << "\n\t\tPRODUCT MENU\n\n";
	cout << "========================================================\n";
	cout << "P.NO.\t\tNAME\t\tPRICE\t\tDiscount\n";
	cout << "========================================================\n";
	while (fp.read((char*)&pr, sizeof(product)))
	{
		cout << pr.retpno() << "\t\t" << pr.retname() << "\t\t" << pr.retprice() << "LE" << "\t\t" << pr.retdis() << "%" << endl;
	}
	fp.close();
}
void intro()
{
	system("cls");
	cout << setw(10) << "\n\n\ =========================================\n ";
	cout << setw(40) << ">> PRODUCT  MANAGEMENT SYSTEM<<\n ";
	cout << setw(10) << "========================================= \n";
	cout << "\n\n\n     by   \n";
	cout << "1-Amal Mohammed,\n";
	cout << "2-Tassnem Shahen,\n";
	cout << "3-Rehab Mohammed,\n";
	cout << "4-Maha Mohammed,\n";
	cout << "5-Menna Aymen,\n";
	cout << "6-Mariam Samy.\n";
	cout << "\n\nFaculty of Engineering,Helwan University";
	cout << "\n\nDepartment of Computer Engineering \n\n";

}
char ch2;
void admin_menu()
{
	cout << "\n\n\n\tADMINISTRATION MENU \n";
	cout << "\t____________________";
	cout << "\n\n\t1:CREATE PRODUCT";
	cout << "\n\n\t2:DISPLAY ALL PRODUCTS";
	cout << "\n\n\t3:QUERY ";
	cout << "\n\n\t4:MODIFY PRODUCT";
	cout << "\n\n\t5:DELETE PRODUCT";
	cout << "\n\n\t6:VIEW PRODUCT MENU";
	cout << "\n\n\t7:Change Password";
	cout << "\n\n\t8:BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-8) ";
	ch2 = getchar();
	switch (ch2)
	{
	case '1':system("cls");
		write_product();
		break;
	case '2': display_all(); break;
	case '3':
		int num;
		system("cls");
		cout << "\n\n\tPlease Enter The Product No. ";
		cin >> num;
		display_sp(num);

		break;
	case '4': modify_product(); break;
	case '5': delete_product(); break;
	case '6': menu(); break;
	case'7': system("cls"); change_password(); break;
	case '8': break;
	default:cout << "\a"; system("cls"); admin_menu();
	}
}
void place_order()
{
	int order_arr[50], quan[50], c = 0;
	float amt, damt, total = 0;
	char ch = 'Y';
	menu();
	cout << "\n\n\n\n\n =============================== ";
	cout << "\n -->>PLACE YOUR ORDER<<--";
	cout << "\n =============================== \n";
	do {
		cout << "\n\nEnter The No. Of The Product : ";
		cin >> order_arr[c];
		cout << "\nQuantity in number : ";
		cin >> quan[c];
		c++;
		cout << "\nDo You Want To Order Another Product ? (y/n)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	system("cls");
	cout << "\n\t\t***Thank You For Placing The Order***\n";
	cout << "\n********************************INVOICE******************************\n";
	cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
	for (int x = 0; x <= c; x++)
	{
		fp.open("product.txt", ios::in);
		fp.read((char*)&pr, sizeof(product));
		while (!fp.eof())
		{
			if (pr.retpno() == order_arr[x])
			{
				amt = pr.retprice() * quan[x];
				damt = amt - (amt * pr.retdis() / 100);
				cout << "\n" << order_arr[x] << "\t" << pr.retname() << "\t" << quan[x] << "\t\t" << pr.retprice() << "\t" << amt << "\t\t" << damt;
				total += damt;
			}
			fp.read((char*)&pr, sizeof(product));
		}
		fp.close();
	}
	cout << "\n\n\t\t\t\t\tTOTAL = " << total;
}

void main()
{
	char ch;
	intro();
	system("pause");
	system("cls");
	do
	{
		cout << "\n\t\t WELCOME TO PRODUCT MANAGEMENT SYSTEM APPLICATION  \n";
		cout << "\t****************************************************************\n\n";
		cout << "\n\n\n\tMAIN MENU\n";
		cout << "\t_____________";
		cout << "\n\n\t1: CUSTOMER";
		cout << "\n\n\t2: ADMINISTRATOR";
		cout << "\n\n\t3: EXIT";
		cout << "\n\n\tPlease Select Your Option ";
		cin >> ch;
		switch (ch)
		{
		case '1':
			system("cls");
			accounts();
			break;
		case '2':
			system("cls");
			password();
			admin_menu();
			break;

		case '3':exit(0);

		default:
			cout << "\a";
			system("cls");
		}
	} while (ch != '3');
}


