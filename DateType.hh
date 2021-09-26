#include<iostream>

using namespace std;

class datetype {
public:
    void setdate(int month, int day, int year);
    void getdate(int& month, int& day, int& year);
    void printdate()const;
    datetype(int month = 1, int day = 1, int year = 2020);
    void SetMonth(int month);
    void GetMonth(int& month);
    void SetDay(int day);
    void getday(int& day);
    void setyear(int year);
    void getyear(int& year);
    bool Leapyear(int year);
    int Days_num();
    datetype operator + (int days);
protected:
    int d_month;
    int d_day;
    int d_year;

};


datetype datetype::operator + (int days) {
    datetype MyData;
    MyData.d_day = d_day;
    MyData.d_month = d_month;
    MyData.d_year = d_year;
    if (MyData.Days_num() - MyData.d_day < days) {
        days -= (MyData.Days_num() - MyData.d_day);
        MyData.d_month += 1;
        if (MyData.d_month > 12) {
            MyData.d_year += 1;
            MyData.d_month -= 12;
        }
        while (days > 0) {
            if (MyData.Days_num() < days) {
                days -= MyData.Days_num();
                MyData.d_month += 1;
                if (MyData.d_month > 12) {
                    MyData.d_year += 1;
                    MyData.d_month -= 12;
                }
            }
            else {
                MyData.d_day = days;
                days = 0;
            }
        }
    }
    else {
        MyData.d_day += days;
        days = 0;
    }


    return MyData;
}

int datetype::Days_num() {
    if (d_month == 1 || d_month == 3 || d_month == 5 || d_month == 7 || d_month == 8 || d_month == 10 || d_month == 12)
        return 31;
    if (d_month == 4 || d_month == 6 || d_month == 9 || d_month == 11)
        return 30;
    if (d_month == 2)
        if (Leapyear(d_year))
            return 29;
        else
            return 28;
}

bool datetype::Leapyear(int d_year) {
    if (d_year % 4 == 0) {
        if (d_year % 100 == 0) {
            if (d_year % 400 == 0)
                cout << " It is a leap year";
            else
                cout << " It is not a leap year";
        }
        else
            cout << " It is a leap year";
    }
    else
        cout << " It is not a leap year";
    return 0;

}

void datetype::setdate(int month, int day, int year) {
    while (month < 1 || month>12)

    {

        cout << " There is no[" << month << "]month" << endl;

        cout << "enter month" << endl;

        cin >> month;

    }
    d_month = month;
    while (day < 1 || day>31)

    {

        cout << "Entered day " << day << " is wrong" << endl;

        cout << "Enter correct day" << endl;

        cin >> day;

    }

    d_day = day;

    d_year = year;
}

void datetype::getdate(int& month, int& day, int& year) {
    month = d_month;
    day = d_day;
    year = d_year;
}

void datetype::SetMonth(int month)
{
    d_month = month;
}



void datetype::GetMonth(int& month) {
    month = d_month;
}

void datetype::SetDay(int day) {
    d_day = day;
}

void datetype::getday(int& day) {
    day = d_day;
}

void datetype::setyear(int year) {
    d_year = year;
}

void datetype::getyear(int& year) {
    year = d_year;
}

void datetype::printdate()const {
    cout << d_month << "-" << d_day << "-" << d_year << endl;


}

datetype::datetype(int month, int day, int year) {
    setdate(month, day, year);
}