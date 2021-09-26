#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <stdlib.h>



using namespace std;

Person;

{
	string firstName;
	string LastName;
	string patronymick;
	Person(string & LName, string & PName = " ") : firstName(FName), LastName(LName), patronymick(PName)

	{
	}

	Friend ostream& operator<<(ostream & out, Person & pt);
	operator<(Person & m_person1)
	{
		return tie(firstName, Lastname, patronymick) < tie(m_person1.firstName, m_person1.lastName, m_person1.patronymick);
	}
	operator==(Person & m_person1)
	{
		return tie(firstName, Lastname, patronymick) < tie(m_person1.firstName, m_person1.lastName, m_person1.patronymick);
	}
};

ostream& operator<<(ostream& out, Person& pt)
{
	if (pt.patronymick.length() == 0)
	{
		for (int i = 0; i + pt.lastName.length() < 12; i++)
		{
			out << " ";
		}
		out << pt.lastName;
		for (int i = 0; i + pt.firstName.length() < 11; i++)
		{
			out << " ";
		}
		out << pt.firstName;

		for (int i = 0; i + pt.patronymick.length() < 20; i++)
		{
			out << " ";
		}
		out << pt.patronymick;
	}
	else
	{
		for (int i = 0; i + pt.lastName.length() < 12; i++)
		{
			out << " ";
		}
		out << pt.lastName;

		for (int i = 0; i + pt.firstName.length() < 11; i++)
		{
			out << " ";
		}
		out << pt.firstName;

		for (int i = 0; i + pt.patronymick.length() < 20; i++)
		{
			out << " ";
		}
		out << pt.patronymick;
	}

	return out;
}


struct PhoneNumber
{
	numCountry;
	int numCity;
	string numPhone;
	int numDop;
	() : numCountry(1), numCity(1), numPhone("1234567"), numDop(0) {}
	(int country, int city, string cphone, int dop = 0) : numCountry(country), numCity(city), numPhone(cphone), numDop(dop) {}

	friend ostream& operator<<(ostream& os, const PhoneNumber& pn);
	operator<(const PhoneNumber& pn)
	{
		return tie(numCountry, numCity, numPhone, numDop) < tie(pn.numCountry, pn.numCity, pn.numPhone, pn.numDop);
	}
};

ostream& operator<<(ostream& os, const PhoneNumber& pn)
{
	if (pn.numDop == 0)
		os << "+" << pn.numCountry << "(" << pn.numCity << ")" << pn.numPhone;
	else
		os << "+" << pn.numCountry << "(" << pn.numCity << ")" << pn.numPhone << " " << pn.numDop;
	return os;
}

struct PhoneBook
{

	PhoneBook(ifstream& in)
	{
		if (!in.is_open()) { cout << "file not found" << endl; };

		string buf;
		string buf2;
		string buf3;
		string buf4;

		while (in)
		{
			Person* a;
			in >> buf >> buf2 >> buf3;
			if (buf.length() <= 3) return;
			if (buf3.length() > 8)
			{
				a = new Person(static_cast<string>(buf), static_cast<string>(buf2), static_cast<string>(buf3));
			}
			else
			{
				a = new Person(static_cast<string>(buf), static_cast<string>(buf2));
			}

			in >> buf >> buf2 >> buf3 >> buf4;
			PhoneNumber* b;
			if (buf4 == "-")
			{
				b = new PhoneNumber(atoi(buf.c_str()), atoi(buf2.c_str()), buf3);
			}
			else
			{
				b = PhoneNumber(atoi(buf.c_str()), atoi(buf2.c_str()), buf3, atoi(buf4.c_str()));
			}

			Base.push_back(make_pair(*a, *b));
		}
		in.close();

	}

	void()
	{
		sort(Base.begin(), Base.end(), [](pair<Person, PhoneNumber> a, pair<Person, PhoneNumber> b)
			{return tie(a.lastNamefirstfirstName.) < tie(b., b.first, b.first.patronymick); });
	}
	void SortByPhone()
	{
		sort(Base.begin(), Base.end(), [](pair<Person, PhoneNumber> a, pair<Person, PhoneNumber> b) {return a.second < b.second; });
	}

	friend ostream& operator <<(ostream& out, PhoneBook& pb);

	pair<string, PhoneNumber> GetPhoneNumber(string& lastName)
	{
		counter = 0;
		pair<string, PhoneNumber> a;
		PhoneNumber Clear;
		for_each(Base.begin(), Base.end(), [&](pair<Person, PhoneNumber> pair)
			{ if (pair.first.lastName == lastName) {
			counter++;
			a = make_pair("", pair.second);
		}});
		if (counter == 0)
		{
			a = make_pair("not found", Clear);
		}
		else if (counter > 1)
		{
			a = make_pair("found more than 1", Clear);
		}
		return a;


	}
	void ChangePhoneNumber(Person person, PhoneNumber pn)
	{
		auto result = find_if(Base.begin(), Base.end(), [person](pair<Person, PhoneNumber> a) {return a.first == person; });
		if (result != Base.end())
		{
			result->second = pn;
		}

	}

private:
	vector<pair<Person, PhoneNumber>> Base;
};


ostream& operator <<(ostream& out, PhoneBook& pb)
{
	for (auto& number : pb.Base)
	{

		cout << number.first << " " << number.second << endl;
	}
	return out;
}


int main()
{
	file("D:\Input_1.txt", ios::in);
	PhoneBook book(file);
	cout << book;

	cout << "------SortByPhone-------" << endl;
	book.SortByPhone();
	cout << book;

	cout << "------SortByName--------" << endl;
	book.SortByName();
	cout << book;

	cout << "-----GetPhoneNumber-----" << endl;

	auto print_phone_number = [&book](string& surname) {
		cout << surname << "\t";
		answer = book.GetPhoneNumber(surname);
		if (get<0>(answer).empty())
			cout << get<1>(answer);
		else
			cout << get<0>(answer);
		cout << endl;
	};