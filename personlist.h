#pragma once
#include "../CheckSymbol.h"
#include "PersonListItem5.h"

namespace Lab5
{
	class PersonList
	{
		public:
			void Add(Person* person);
			Person* Find(int index);
			int IndexOf(Person* person);
			void Remove(Person* person);
			void RemoveAt(int index);
			void Clear();
			int GetCount();
			void ShowInConsole();
			void Read();
			PersonList();
			PersonList(int count, Person* first, ...);
			~PersonList();
		private:
			PersonListItem* _head;
			PersonListItem* _tail;
			void ShowNodeInConsole(PersonListItem list, string message = "");
			bool CheckName(char name[]);
	};
}
