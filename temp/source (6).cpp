#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

class Book
{
protected:
	string name, genre;
	int pages = 2;
	bool isTaken = false;

public:

	Book()
	{
		
		this->name = "", this->genre = "";
		this->pages = 0;
		cin.ignore();
		cout << "Enter name of the book: ";
		getline(cin, name);
		cout << "Enter genre of the book: ";
		getline(cin, genre);
		cout << "Enter count of pages of the book: ";
		cin >> pages;
		
			if (pages < 0)
			{
				throw (invalid_argument("Negative count of pages:(\n"));
			}
		
	}

	string getName()
	{
		return name;
	}

	string getGenre()
	{
		return genre;
	}

	int getPages()
	{
		return pages;
	}
	
	bool getIsTaken()
	{
		return isTaken;
	}

	void setIsTaken(bool o)
	{
		isTaken = o;
	}

	void setIsTaken(int a)
	{
		if (a == 0)
			isTaken = true;
		else if (a == 1)
			isTaken = false;
		else throw invalid_argument("Incorrect state of book from choices yes(0) and No(1) :(");
	} 

	bool operator !=(Book b)
	{
		return this->pages != b.pages;
	}

	bool operator ==(Book b)
	{
		return this->pages == b.pages;
	}

	bool operator >(Book b)
	{
		return this->pages > b.pages;
	}

	bool operator <(Book b)
	{
		return this->pages < b.pages;
	} 

	bool operator!()
	{
		return this->isTaken = !isTaken;
	}

	void show() const
	{
		cout << "Name of the book: " << this->name << endl;
		cout << "Genre of the book: " << this->genre << endl;
		cout << "this book has " << this->pages << " pages\nType of book is undef" << endl;
		cout << "Book is";
		if (this->isTaken == true)
			cout << " on someone's hands." << endl;
		else cout << " in library." << endl;
	}
}; 








class InHardCover : public Book
{
	bool hasSecondCover = false;
public:
	InHardCover()
	{
		int answer;

		cout << "Does this book has second cover? yes(0)/no(1) ";
		cin >> answer;

		if (answer != 0 && answer != 1)
		{
			throw invalid_argument("Option incorrect:(\n");
		}

		if (answer == 0) hasSecondCover = true;
		else hasSecondCover = false;
	}

	InHardCover(string n, string g, int p, bool iT, bool hSC)
	{
		name = n;
		genre = g;
		pages = p;
		isTaken = iT;
		hasSecondCover = hSC;
	}

	bool getHasSecondCover()
	{
		return hasSecondCover;
	};


	void show() const
	{
			cout << "Name of the book: " << this->name << endl;
			cout << "Genre of the book: " << this->genre << endl;
			cout << "This book has " << this->pages << " pages\nBook ";
			if (hasSecondCover == true)
			{
				cout << "has second cover.\nBook is";
			}
			else cout << "has no second cover.\nBook is";

			if (this->isTaken == true)
				cout << " on someone's hands." << endl;
			else cout << " in library." << endl;
	}
	
}; 









class InSoftCover : public Book
{
	bool isMagazine = false;
public:
	InSoftCover()
	{
		int answer;
		cout << "Is this book a magazine? Yes(0)/No(1) ";
		cin >> answer;

		if (answer != 0 && answer != 1)
		{
			throw invalid_argument("Option incorrect:(\n");
		}

		if (answer == 0) isMagazine = true;
		else isMagazine = false;
	}

	InSoftCover(string n, string g, int p, bool iT, bool iM)
	{
		name = n;
		genre = g;
		pages = p;
		isTaken = iT;
		isMagazine= iM;
	}

	bool getIsMagazine()
	{
		return isMagazine;
	}


	void show() const
	{
		cout << "Name of the book: " << this->name << endl;
		cout << "Genre of the book: " << this->genre << endl;
		cout << "This book has " << this->pages << " pages" << endl;
		if (isMagazine == true)
		{
			cout << "Book is magazine.\nBook is";
		}
		else cout << "Book is not magazine.\nBook is";

		if (this->isTaken == true)
			cout << " on someone's hands." << endl;
		else cout << " in library." << endl;
	}

}; 



TEST(TEST, TEST_TEST) {
    string name = "To Kill a Mocking Bird";
    string genre = "Romance";
    int pages = 352;

    Book book();
    string name_of_book = book.getName();

    EXPECT_EQ(name_of_book.c_str(), name);


}


int main()
{
	::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);


    return RUN_ALL_TESTS();
}
