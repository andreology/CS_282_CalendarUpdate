#include <iostream>
using namespace std;
#include "upDate.h"
#include <string>
int upDate::counter = 0;
//Set default constructor in order to set the date to May 11, 1959
upDate::upDate()
{
	//	month, day and year
	dptr = new int[3];
	//month = 5;
	dptr[0] = 5;
	//day = 11;
	dptr[1] = 11;
	//year = 1959;
	dptr[2] = 1959;
	counter++;
}
int upDate::GetDateCount()
{
	return counter;
}
//Overloaded constructor in order to set the date to the values passed in through the parameter list represented by month, day and year. 
upDate::upDate(int M, int D, int Y)
{
	//populate pointer with data 
	dptr = new int[3];
	if (M > 0 && M < 13)
	{
		dptr[0] = M;
		if (D > 0 && D < 32)
		{
			dptr[1] = D;
			//day = D;
			dptr[2] = Y;
			//year = Y;
		}
	}
	else
	{
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
	}
	counter++;
}
//overloaded Constructor i.e. copy constructor

upDate::upDate(const upDate &D)
{
	//allocate memory dynamically (new)
	dptr = new int[3];
	*dptr = D.dptr[0];
	*(dptr + 1) = D.dptr[1];
	*(dptr + 2) = D.dptr[2];
	//delete D.dptr;

}

int* upDate::getDptr()
{
	return dptr;
}
ostream&  operator<<(ostream& os, upDate& aupDate)
{

	string monthStr = "";
	switch (aupDate.getMonth())
	{
	case 1:
		monthStr = "January";
		break;
	case 2:
		monthStr = "February";
		break;
	case 3:
		monthStr = "March";
		break;
	case 4:
		monthStr = "April";
		break;
	case 5:
		monthStr = "May";
		break;
	case 6:
		monthStr = "June";
		break;
	case 7:
		monthStr = "July";
		break;
	case 8:
		monthStr = "August";
		break;
	case 9:
		monthStr = "September";
		break;
	case 10:
		monthStr = "October";
		break;
	case 11:
		monthStr = "November";
		break;
	case 12:
		monthStr = "December";
		break;
	}
	os << aupDate.getMonth() << "/" << aupDate.getDay() << "/" << aupDate.getYear();

	return os;
}
upDate upDate :: operator++()
{
	this->incrDate(1);
	return *this;

}
upDate upDate :: operator++(int)
{
	this->incrDate(1);
	return *this;
}

upDate upDate :: operator--()
{
	this->decrDate(1);
	return *this;

}
upDate upDate :: operator--(int)
{
	this->decrDate(1);
	return *this;

}
upDate upDate :: operator-(int n)
{
	upDate temp = *this;
	temp.decrDate(n);

	return temp;
}
upDate& upDate :: operator= (const upDate& c) //Overloaded assignment op def
{
	if (this != &c) //test the address of both objects
	{
		delete dptr;
		dptr = new int[3];
		*dptr = c.dptr[0];
		*(dptr + 1) = c.dptr[1];
		*(dptr + 2) = c.dptr[2];
	}
	return *this;
}
bool upDate :: operator> (upDate& c) //Overloaded assignment op def
{

	return (julian()) > c.julian();
}
bool upDate :: operator< (upDate& c) //Overloaded assignment op def
{

	return (julian()) < c.julian();
}
bool upDate :: operator== (upDate& c) //Overloaded assignment op def
{

	return (julian()) == c.julian();
}
upDate operator-(int n, upDate D)
{
	upDate temp(D);
	temp.decrDate(n);

	return temp;
}
upDate upDate :: operator+(int n)
{
	upDate temp = *this;
	temp.incrDate(n);

	return temp;
}

upDate  operator+(int n, upDate D)
{
	upDate temp(D);
	temp.incrDate(n);

	return temp;
}
int upDate :: operator-(upDate D)
{
	upDate temp0 = *this;
	int temp = temp0.daysBetween(D);
	return temp;
}
//upDate destructor
upDate ::  ~upDate()
{
	//deleting memory in the heap
	delete[] dptr; //deletes everything in array. 
	counter--;
}
//Increment date by N days.
void upDate::incrDate(int N)
{
	int month = *dptr;
	int day = *(dptr + 1);
	int year = *(dptr + 2);

	int j = JD(year, month, day);

	//Convert negative number into positive for correct value
	if (N < 0)
	{
		N = -N;
	}
	j += N;
	int x, y, z;
	GDate(j, x, y, z);
	*dptr = y;
	*(dptr + 1) = z;
	*(dptr + 2) = x;
}

//Decrement date by N days.
void upDate::decrDate(int N)
{
	int month = *dptr;
	int day = *(dptr + 1);
	int year = *(dptr + 2);
	int j = JD(year, month, day);

	if (N < 0)
	{
		N = -N;
	}
	j -= N;
	int x, y, z;

	GDate(j, x, y, z);
	*dptr = y;
	*(dptr + 1) = z;
	*(dptr + 2) = x;
}

//Return number of days between this date and the date D. If date D is a future date return value as positive int. If date D is in the past return value as a negative int.
int upDate::daysBetween(upDate D)
{

	int a, b, c;
	int month = *dptr;
	int day = *(dptr + 1);
	int year = *(dptr + 2);

	a = JD(D.getYear(), D.getMonth(), D.getDay());
	b = JD(year, month, day);
	c = b - a;
	if (c < 0)
	{
		c = c * -1;
	}
	//Return the difference in days
	return c;
}

//Return month in integer form
int upDate::getMonth()
{
	return *dptr; //Month
}

//Return day of the month
int upDate::getDay()
{
	return *(dptr + 1);
}

//Return the year
int upDate::getYear()
{
	return *(dptr + 2);
}
//Return number of days since the current year began
int upDate::dayOfYear() {
	int a = 0;
	int month = *dptr;
	int day = *(dptr + 1);
	int year = *(dptr + 2);
	//Is leap year?
	if (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0)))
	{
		switch (month)
		{
		case 2: a = 31;
			break;
		case 3: a = 60;
			break;
		case 4:	a = 91;
			break;
		case 5: a = 121;
			break;
		case 6: a = 152;
			break;
		case 7:	a = 182;
			break;
		case 8:	 a = 213;
			break;
		case 9:	a = 244;
			break;
		case 10: a = 274;
			break;
		case 11: a = 305;
			break;
		case 12: a = 335;
			break;
		default: a = 0;
			break;
		}
		a = a + day;
	}

	//If not a leap yaer
	else
	{
		switch (month)
		{
		case 2: a = 31;
			break;
		case 3: a = 59;
			break;
		case 4:	a = 90;
			break;
		case 5: a = 120;
			break;
		case 6: a = 151;
			break;
		case 7:	a = 181;
			break;
		case 8:	 a = 212;
			break;
		case 9:	a = 243;
			break;
		case 10: a = 273;
			break;
		case 11: a = 304;
			break;
		case 12: a = 334;
			break;
		default: a = 0;
			break;
		}
		a = a + day;
	}

	return a;
}

//Returns Monday, Tuesday, etc according to the day of the week.
string upDate::dayOfWeek()
{
	int m, d, y;
	int month = *dptr;
	int day = *(dptr + 1);
	int year = *(dptr + 2);
	m = month;
	y = year;
	d = day;

	if (m == 1 || m == 2)
	{
		m = m + 12;
		y = y - 1;
	}
	//Cool method to convert a date into the day of week
	int z = (d + (int)floor((13 * (m + 1)) / 5) + y % 100 + (int)floor((y % 100) / 4) + (int)floor(((int)floor(y / 100)) / 4) + 5 * (int)floor(y / 100)) % 7;

	string dow;
	switch (z)
	{
	case 0: dow.append("Saturday");
		break;
	case 1: dow.append("Sunday");
		break;
	case 2: dow.append("Monday");
		break;
	case 3: dow.append("Tuesday");
		break;
	case 4: dow.append("Wednesday");
		break;
	case 5: dow.append("Thursday");
		break;
	case 6: dow.append("Friday");
		break;
	}

	return dow;
}

void upDate::GDate(int JD, int &year, int &month, int &day)
{
	int I, J, K;
	int L, N;

	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	year = I;
	month = J;
	day = K;

}

int upDate::JD(int y, int m, int d)
{
	int Julian = d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;

	return Julian;
}

int upDate::julian()
{
	int m = *dptr;
	int d = *(dptr + 1);
	int y = *(dptr + 2);

	int Julian = d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;


	return Julian;
}