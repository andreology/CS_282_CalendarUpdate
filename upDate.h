//Andre Barajas
//Professor Gold
//CECS282
//November 2017
//Fall 2017
//Update project i.e. operator overloading and memory allocation 

#pragma once
#pragma once
#include <iostream>
using namespace std;
#include <string>
#ifndef MYDATE_H
#define MYDATE_H
class upDate
{
public:
	upDate(); //Constructor set the date to May 11, 1959 (A very important date.)
	upDate(int M, int D, int Y);

	//Overloaded operators...
	friend ostream& operator<<(ostream& os, upDate& aupDate);
	upDate operator+(int);
	friend upDate operator+(int, upDate);
	upDate operator-(int);
	int operator-(upDate);
	friend upDate operator-(int, upDate);
	upDate& upDate ::operator= (const upDate& c); //Overloaded assignment op def
	bool upDate :: operator> (upDate& c);
	bool upDate :: operator== (upDate& c);
	bool upDate :: operator< (upDate& c);
	upDate operator++();
	upDate operator++(int);
	upDate operator--(); //prefix
	upDate operator--(int);//postfix
	~upDate();

	int* getDptr();
	upDate(const upDate&);
	void display();
	void incrDate(int N);
	void decrDate(int N);
	int daysBetween(upDate D);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	string dayOfWeek();
	void GDate(int JD, int &y, int &m, int &d);
	int JD(int y, int m, int d);
	int julian();
	static int GetDateCount();
	static int counter;
private:

	int* dptr;
};

#endif