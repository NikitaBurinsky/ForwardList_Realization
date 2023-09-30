#include "ForwardList.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

template <class T>
int mainFunc()
{
	int pause;
	int choose;
	bool contin = true;
	T data;
	int index;
	List<T> list;
	while (contin)
	{
	gotolink:
		system("cls");
		SetConsoleTextAttribute(hConsole, 10);
		cout << "--------------------";
		cout << "\nChoose action: \n";
		cout << " 1 - Add Element\n 2 - Delete Element \n 3 - Show Element\n 4 - Sort Elements\n 5 - Exit";
		cout << "\n--------------------\n";
		choose = _getch();
		choose -= 48;
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		switch (choose)
		{
		case 1:
		{
			cout << " 1 - Add Element in the beginning\n 2 - Add Element in the end\n 3 - Add Element by Number\t\t5 - Exit\n";
			choose = _getch();
			choose -= 48;
			system("cls");
			cout << "Enter data: ";
			cin >> data;
			switch (choose)
			{
			case 1:
				list.push_front(data); ///////////////////////////////////////////////////////////
				goto gotolink;
			case 2:
				list.push_back(data);
				goto gotolink;
			case 3:
				cout << "Enter index: ";
				cin >> index;
				list.insert(--index, data);
				goto gotolink;
			default:
				cout << "\n//Exit//\n";
				goto gotolink;
			}
		}
		case 2:
		{
			cout << " 1 - Delete Element in the beginning\n 2 - Delete Element in the end\n 3 - Delete Element by Number\n\n 4 - Clear List\t\t5 - Exit\n";
			choose = _getch();
			choose -= 48;
			system("cls");
			switch (choose)
			{
			case 1:
				list.pop_front(); ///////////////////////////////////////////////////////////
				goto gotolink;
			case 2:
				list.pop_back();
				goto gotolink;
			case 3:
				cout << "Enter index: ";
				cin >> index;
				list.erase(--index);
				goto gotolink;
			case 4:
				list.clear();
			default:
				cout << "\n//Exit//\n";
				goto gotolink;
			}
		}
		case 3:
			cout << " 1 - Show Element from the beginning\n 2 - Show Element in the end\n 3 - Show Element by Number\n 4 - Show All the Elements\t\t5 - Exit\n";
			choose = _getch();
			choose -= 48;
			system("cls");
				switch (choose)
				{
				case 1:
					cout << "| " << list[0] << " |\n";
					pause = _getch();
					goto gotolink;
				case 2:
					cout << "| " << list.back() << " |\n";
					pause = _getch();
					goto gotolink;
				case 3:
					cout << "Enter index: ";
					cin >> index;
					cout << "| " << list[--index] << " |\n";
					pause = _getch();

					goto gotolink;
				case 4:
					cout << "| ";
					for (int i = 0; i < list.size; i++)
						cout << list[i] << " ";
					cout << "|\n";
					pause = _getch();

				default:
					cout << "\n//Exit//\n";
					goto gotolink;
				}
				break;
		case 4:
		{
			list.sort();
			break;
		}
		default:
			return 0;
			break;
		}

	}
}


int main()
{
	int type;
	startlink:
	SetConsoleTextAttribute(hConsole, 14);
	cout << "List data struct working\nChoose list data type: \n "
		<< "1 - int\n 2 - float \n 3 - string\n 4 - char \n 5 - Exit\n ";
	type = _getche();
	type -= 48;
	cout << endl;
	switch (type)
	{
	case 1:
		mainFunc<int>();
		break;
	case 2:
		mainFunc<float>();
		break;
	case 3:
		mainFunc<string>();
		break;
	case 4:
		mainFunc<char>();
		break;
	case 5:
		exit(666);
	default:
		goto startlink;
		break;
	}

	
}