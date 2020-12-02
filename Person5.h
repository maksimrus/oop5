#pragma once
#include "../CheckSymbol.h"
#include "../Sex.h"

namespace Lab5
{
	class Person
	{
		public:
			Person(char name[], char surname[], int age, Sex sex);
			bool SetName(char name[], int size = 20);
			bool SetSurname(char surname[], int size = 20);
			void SetAge(int age);
			void SetSex(Sex sex);
			char* GetName();
			char* GetSurname();
			int GetAge();
			Sex GetSex();
			bool operator==(const Person& right);
		private:
			char* Name;
			char* Surname;
			int Age;
			Sex Sex;
	};
}
