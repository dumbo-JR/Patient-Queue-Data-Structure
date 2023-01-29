//ACS211002 MUJTABA AHMED
//PATIENT MANAGEMENT SYSTEM
#include<iostream>
#define max 5
using namespace std;


class q
{
	char start[max][10];
	int priority[max];
	int size;
	int f, r;
public:
	q()
	{
		f = r = -1;
		size = 0;
	}
	bool check_full();
	bool check_empty();
	void sort();
	void add();
	void delete_queue();
	void display();

};
bool q::check_empty()
{
	if (size == 0)
		return 1;
	else
		return 0;
}

bool q::check_full()
{
	if (size == max)
		return 1;
	else
		return 0;
}
void q::sort()
{
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - j - 1; i++)
		{
			if (priority[i] < priority[i + 1])
			{
				swap(start[i], start[i + 1]);
				swap(priority[i], priority[i + 1]);

			}
		}
	}

}

void q::delete_queue()
{
	if (!check_empty())
	{
		f++;
		cout << "\n the patient sent to O.T. is : " << start[f] << endl;
	}
	else
	{
		cout << "\n  there are no patients in the hospital wards \n";
	}
}

void q::add()
{
	char an;
	cout << " \n **** THE STATE OF THE PATIENT **** \n\n 1. GOOD : Vital signs are stable and within normal limits. Patient is conscious and comfortable.\n \n 2. FAIR : Vital signs are stable and within normal limits. Patient is conscious, but may be uncomfortable.\n \n 3. SERIOUS: Vital signs may be unstable and not within normal limits. Patient is acutely ill.\n \n4. CRITICAL : Vital signs are unstable and not within normal limits. Patient is unconscious. \n \n ";
	do
	{
		if (check_full() == 1)
		{

			cout << " THE HOSPITAL WARDS ARE FULL \n";
			break;
		}
		else
		{
			cout << "enter the name of patient \n";
			r = r + 1;
			cin >> start[r];
			cout << "ENTER 1,2,3 or 4 \n1.GOOD\n2.FAIR\n3.SERIOUS\n4.CRITICAL\n";
			cin >> priority[r];

			size++;
			cout << "do you want to add more patients : \n if yes then enter y ?" << endl;
			cin >> an;
		}
	} while (an == 'y' || an == 'Y');
	sort();
}
void q::display()
{
	if (!check_empty())
	{
		for (int j = f + 1; j < size; j++)
		{
			cout << start[j] << "\n";
		}

	}
	else
	{
		cout << "\n There are no patients in the hospital wards \n";
	}
}

int main()
{
	char ans;
	int ch;

	q ob;
	do
	{
		cout << "\n*********** CUST HOSPITAL ***************\n";
		cout << "\n 1. ADD A NEW PATIENT";
		cout << "\n 2.DISPLAY ALL PATIENTS ";
		cout << "\n 3.DISPLAY THE PATIENT IN THE CHECKUP ROOM";
		cout << "\n 4. Exit";
		cout << "\n Enter your choice :";
		cin >> ch;
		switch (ch)
		{
		case 1:
			ob.add();
			break;
		case 2:
			ob.display();
			break;
		case 3:
			ob.delete_queue();
			break;
		case 4:
			break;
		default:
			cout << "Wrong choice" << endl;
			break;
		}
		cout << "Do you want to continue ?" << endl;
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
	return 0;
}