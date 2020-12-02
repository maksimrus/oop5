#pragma once
#include "Person5.h"

namespace Lab5
{
	Person::Person(char name[], char surname[], int age, enum Sex sex)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);
	}

	bool Person::SetName(char name[], int size)
	{
		try
		{
			Name = new char[size];
			for (int i = 0; i < 20; i++)
			{
				Name[i] = name[i];
				if (name[i] == '\0')
				{
					break;
				}
			}
			return true;
		}
		catch(exception ex)
		{
			cout << ex.what();
			return false;
		}
	}

	bool Person::SetSurname(char surname[], int size)
	{
		try
		{
			Surname = new char[size];
			for (int i = 0; i < 20; i++)
			{
				Surname[i] = surname[i];
				if (surname[i] == '\0')
				{
					break;
				}
			}
			return true;
		}
		catch (exception ex)
		{
			cout << ex.what();
			return false;
		}
	}

	void Person::SetAge(int age)
	{
		Age = age;
	}

	void Person::SetSex(enum Sex sex)
	{
		Sex = sex;
	}

	char* Person::GetName()
	{
		return Name;
	}

	char* Person::GetSurname()
	{
		return Surname;
	}

	int Person::GetAge()
	{
		return Age;
	}

	Sex Person::GetSex()
	{
		return Sex;
	}

	bool Person::operator==(const Person& right)
	{
		return(!strcmp(Name, right.Name) &&
			!strcmp(Surname, right.Surname) &&
			Age == right.Age && Sex == right.Sex);
	}
}
