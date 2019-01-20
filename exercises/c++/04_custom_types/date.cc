#include<iostream>

enum class Month {January, February, March, April, May, June, July, August, September, October, November, December};

Month operator+(Month m, int i)
{
	return Month((int(m) + i) % 12);
}

Month& operator++(Month& m)
{
	m = m + 1;
	return m;
}

int size(Month m)
{
	switch(m)
	{
	case Month::January: case Month::March: case Month::May: 
	case Month::July: case Month::August: case Month::October: case Month::December:
	return 31; break;

	case Month::April: case Month::June: case Month::September: case Month::November:
	return 30; break;

	case Month::February: return 28; break;
	}
}

class Date
{

	private:

	int _day;
	Month _month;
	int _year;

	void add_day();
	int month_size() const { return size(_month); };
	void shift_month() {++_month;};

	public:
	
	Date(int day, Month month, int year): _day{day}, _month{month}, _year{year} {}

	int day() const { return _day; };
	Month month() const { return _month; };
	int year() const { return _year; };

	void add_days(const unsigned int n) { for(int i{0}; i<n; i++) add_day(); };
	void show();

};
	
void Date::add_day()
{
	if(_day == Date::month_size())
	{
		Date::shift_month();
		_day = 1;

		if(_month == Month::January)
			_year++;			
	}
	else _day++;
}	

void Date::show()
{
	std::cout << _day << "/" << int(_month)+1 <<"/" << _year << "\n";
}



//################# Helper functions #################//

bool operator==(const Date& lhs, const Date& rhs)
{
	return lhs.day() == rhs.day() &&
	       lhs.month() == rhs.month() &&
	       lhs.year() == rhs.year();
}

bool operator!=(const Date& lhs, const Date& rhs)
{
	return !(lhs==rhs);
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
	os << d.day() << "/" << int(d.month())+1 <<"/" << d.year() << "\n";
	return os;
}
	
bool is_leap(const int y)
{
	return (y%400 == 0) || (y%4 == 0 && y%100 != 0);
}
	


int main()
{
	Date d1{11, Month::December, 1999};
	Date d2{11, Month::December, 1999};
	d1.add_days(365);
	
	std::cout << (d1==d2) << " " << (d1!=d2) << "\n";
	std::cout << d1;
}
