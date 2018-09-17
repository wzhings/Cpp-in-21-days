#include <iostream>
#include <string.h>

using namespace std;

/*
class Human
{
private:
	int age;
	string name;

public:
	Human(string humansName = "Adam", int humansAge = 25) : name(humansName), age(humansAge)
	{
		cout << "Constructed a human called " << name << ", " << age << " years old" << endl;
	}
};
*/

/*
class MyString
{
private:
	char* buffer;

public:
	MyString(const char* initString)
	{
		if (initString != NULL)
		{
			buffer = new char[strlen(initString) + 1];
			//strcpy_s(buffer, strlen(initString) + 1, initString);
			strcpy_s(buffer, strlen(buffer), initString);
			//strcpy(buffer, initString);  //unsafe to use strcpy()
		}
		else
			buffer = NULL;
	}

	~MyString()
	{
		cout << "Invoking destructor, clearing up" << endl;
		if (buffer != NULL)
			delete[] buffer;
	}

	int GetLength()
	{
		return strlen(buffer);
	}

	const char* GetString()
	{
		return buffer;
	}
};
*/

class MyString
{
private:
	char* buffer;

public:
	/*
	MyString(const char* initString)
	{
		buffer = NULL;
		if (initString != NULL)
		{
			buffer = new char[strlen(initString) + 1];
			strcpy_s(buffer, strlen(buffer), initString);
		}
	}*/

	MyString(const char* initString)
	{
		buffer = NULL;
		cout << "Default constructor: creating new MyString" << endl;
		if (initString != NULL)
		{
			buffer = new char[strlen(initString) + 1];
			strcpy_s(buffer, strlen(initString) + 1, initString);

			cout << "buffer points to: 0x" << hex;
			cout << (unsigned int*)buffer << endl;
		}
	}

	MyString(const MyString& copySource)
	{
		buffer = NULL;
		cout << "Copy constructor: copying form MyString" << endl;
		if (copySource.buffer != NULL)
		{
			buffer = new char[strlen(copySource.buffer) + 1];
			strcpy_s(buffer, strlen(copySource.buffer) + 1, copySource.buffer); // deep copy
			//strcpy_s(buffer, strlen(buffer), copySource.buffer); // error!
			cout << "buffer points to: 0x" << hex << (unsigned int*)buffer << endl;
		}
	}


	~MyString() // This will cause program crash
	{
		cout << "Invoking destructor, clearing up" << endl;
		delete[] buffer;
	}

	int GetLength()
	{
		return strlen(buffer);
	}

	const char* GetString()
	{
		return buffer;
	}
};

void UseMyString(MyString str)
{
	cout << "String buffer in MyString is " << str.GetLength();
	cout << " characters long" << endl;

	cout << "buffer contains: " << str.GetString() << endl;
	return;
}


int main()
{
	MyString sayHello("Hello from String class");
	//cout << "String buffer in sayHello is " << sayHello.GetLength() << " characters long" << endl;
	//cout << "Buffer contains: " << sayHello.GetString() << endl;
	UseMyString(sayHello);
	
	return 0;
};