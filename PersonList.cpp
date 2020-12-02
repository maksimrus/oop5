#include "PersonList.h"

namespace Lab5
{
	void PersonList::Add(Person* person)
	{
		PersonListItem* temp = new PersonListItem(person);
		if (_head != nullptr)
		{
			temp->Prev = _tail;
			_tail->Next = temp;
			_tail = temp;
		}
		else
		{
			_head = _tail = temp;
		}
	}

	Person* PersonList::Find(int index)
	{
		if (index < 0)
		{
			return nullptr;
		}
		int i = 0;
		PersonListItem* temp = _head;
		while (i < index)
		{
			if (temp == nullptr)
			{
				return nullptr;
			}
			temp = temp->Next;
			i++;
		};
		return temp->GetValue();
	}

	int PersonList::IndexOf(Person* person)
	{
		PersonListItem* temp = _head;
		int index = 0;
		while (temp != nullptr)
		{
			if (temp->GetValue() == person)
			{
				return index;
			}
			index++;
			temp = temp->Next;
		}
		return -1;
	}

	void PersonList::Remove(Person* person)
	{
		PersonListItem* temp = _head;
		while (temp != nullptr)
		{
			if (temp->GetValue() == person)
			{
				if (_head == temp)
				{
					if (temp->Next == nullptr)
					{
						_head = nullptr;
						_tail = nullptr;
						break;
					}
					_head->Next->Prev = nullptr;
					_head = _head->Next;
					break;
				}

				if (_tail == temp)
				{
					_tail->Prev->Next = nullptr;
					_tail = _tail->Prev;
					break;
				}

				if (_head != temp && _tail != temp)
				{
					temp->Prev->Next = temp->Next;
					temp->Next->Prev = temp->Prev;
					break;
				}
			}
			temp = temp->Next;
		}
	}

	void PersonList::RemoveAt(int index)
	{
		Person* person = Find(index);
		Remove(person);
	}

	void PersonList::Clear()
	{
		PersonListItem* next = _head;
		while (next != nullptr)
		{
			PersonListItem* tempNext = next->Next;
			delete next->GetValue();
			delete next;
			next = tempNext;
		}
		_head = nullptr;
		_tail = nullptr;
	}

	int PersonList::GetCount()
	{
		int count = 0;
		PersonListItem* temp = _head;
		while (temp != nullptr)
		{
			temp = temp->Next;
			count++;
		}
		return count;
	}

	void PersonList::ShowNodeInConsole(PersonListItem list, string message)
	{
		cout << message << " Surname: " << list.GetValue()->GetSurname() << endl;
		cout << message << " Name: " << list.GetValue()->GetName() << endl;
		cout << message << " Age: " << list.GetValue()->GetAge() << endl;
		cout << message << " Sex: ";
		
		if (list.GetValue()->GetSex() == Male)
		{
			cout << "Male";
		}
		else
		{
			cout << "Female";
		}
		cout << endl << endl;
	}

	void PersonList::ShowInConsole()
	{
		cout << endl;
		PersonListItem* temp = _head;
		while (temp != nullptr)
		{
			ShowNodeInConsole(*temp);
			temp = temp->Next;
		}

		if (_head != nullptr)
		{
			cout << "-------------------------------------------------" << endl;
			ShowNodeInConsole(*_head, "Head =");
			ShowNodeInConsole(*_tail, "Tail =");
			cout << "-------------------------------------------------" << endl;
		}
		else
		{
			cout << "Head = NULL " << " Tail = NULL " << endl;
		}
	}

	bool PersonList::CheckName(char name[])
	{
		bool validate = true;
		for (int i = 0; i < strlen(name); i++)
		{
			if (isdigit(name[i]) || isspace(name[i]))
			{
				validate = false;
				break;
			}
			if (name[i] == '-')
			{
				if (isalpha(name[i + 1]))
				{
					name[i + 1] = toupper(name[i + 1]);
				}
				else
				{
					validate = false;
					break;
				}
			}
		}
		name[0] = toupper(name[0]);
		return validate;
	}

	void PersonList::Read()
	{
		char name[20];
		char surname[20];
		Sex sex;

		bool key = true;
		while (key)
		{
			cout << endl << "Insert Surname: ";
			cin >> surname;
			key = !CheckName(surname);
		}

		key = true;
		while (key)
		{
			cout << endl << "Insert Name: ";
			cin >> name;
			key = !CheckName(name);
		}

		cout << endl << "Insert Age: ";
		int age;
		do
		{
			age = CheckSymbol();
		} 
		while (age < 0 || age > 150);

		cout << endl << "Insert Sex: ";
		int n;
		do
		{
			n = CheckSymbol();
		} 
		while (n != 0 && n != 1);

		switch (n)
		{
			case Female:
				sex = Female;
				break;
			case Male:
				sex = Male;
				break;
			default:
				break;
		}
		this->Add(new Person(name, surname, age, sex));
	}

	PersonList::PersonList(int count, Person* first, ...)
	{
		Person* pointer = first;
		while (count--)
		{
			this->Add(pointer);
			pointer++;
		}
	}

	PersonList::~PersonList()
	{
		Clear();
	}

	PersonList::PersonList()
	{

	}
}
