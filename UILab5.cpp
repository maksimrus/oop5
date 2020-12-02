#include UILab5.h
#include PersonTools.h

void UILab5()
{
	Lab5PersonList list1 = new Lab5PersonList();
	setlocale(0, );
	bool key = true;
	while (key)
	{
		cout  [1] Add Random Person  endl
			 [2] Add My Person  endl
			 [3] Find At Index  endl
			 [4] Remove At Index  endl
			 [5] Clear  endl
			 [6] Get Count  endl
			 [7] Show In Console  endl
			 [0] Exit  endl
			 - Choose ;
		switch (CheckSymbol())
		{
			case 0
				if (list1 != nullptr)
				{
					delete list1;
				}
				key = false;
				break;
			case 1
				list1-Add(Lab5PersonToolsGetRandomPerson());
				cout  Random Person Added in List  endl;
				break;
			case 2
				cout  Enter Person  endl;
				list1-Read();
				break;
			case 3
			{
				cout  Enter Index ;
				Lab5Person person = list1-Find(CheckSymbol());
				if (person != nullptr)
				{
					cout  Find person   endl;
					cout   Surname   person-GetSurname()  endl;
					cout   Name   person-GetName()  endl;
					cout   Age   person-GetAge()  endl;
					cout   Sex ;
					if (person-GetSex() == Male)
					{
						cout  Male;
					}
					else
					{
						cout  Female;
					}
					cout  endl  endl;
				}
				else
				{
					cout  Person not found  endl;
				}
				break;
			}
			case 4
				cout  Enter Index ;
				list1-RemoveAt(CheckSymbol());
				break;
			case 5
				list1-Clear();
				cout  List Clear  endl;
				break;
			case 6
				cout  Count   list1-GetCount()  endl;
				break;
			case 7
				list1-ShowInConsole();
				break;
		}
		system(pause);
		system(cls);	
	}
}

