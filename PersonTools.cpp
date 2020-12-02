include "PersonTools.h"

namespace Lab5
{
	Person* PersonTools::GetRandomPerson()
	{
		string surnames[] = { "Holiday","Jacobson","James", "Allford", "Bawerman",
			"MacAdam", "Marlow", "Bosworth", "Neal","Conors",
			"Daniels", "Parson", "Quincy", "Richards", "Fane" };
		string names[] = { "Michael","Joshua","Matthew","Ethan","Andrew",
			"Alexander", "Tyler", "James", "John","Samuel",
			"Christian","Logan","Jose","Justin","Gabriel" };
		int surname = rand() % 15;
		int name = rand() % 15;

		char tempName[20];
		char tempSurname[20];
		Sex tempSex;

		for (int i = 0; i <= strlen(names[name].c_str()); i++)
		{
			tempName[i] = names[name][i];
		}
		for (int i = 0; i <= strlen(surnames[surname].c_str()); i++)
		{
			tempSurname[i] = surnames[surname][i];
		}
		tempSex = Male;
		return new Person(tempName, tempSurname, rand() % 15 + 18, tempSex);
	}
}
