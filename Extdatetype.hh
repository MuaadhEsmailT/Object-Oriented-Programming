#include<iostream>
#include<string>

using namespace std;

class extdatetype : public datetype {
private:
    string s_month;

public:
    extdatetype(int month = 1, int day = 1, int year = 2020) : datetype(month, day, year) {
        s_month = stringMonth(month);
    }
    string stringMonth(int month);
    void printdate()const;

    friend class StudentInfo;

};

string extdatetype::stringMonth(int month) {

    switch (month) {
    case 1:
        return "January";
        break;
    case 2:
        return "February";
        break;
    case 3:
        return "March";
        break;
    case 4:
        return "April";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "June";
        break;
    case 7:
        return "July";
        break;
    case 8:
        return "August";
        break;
    case 9:
        return "September";
        break;
    case 10:
        return "October";
        break;
    case 11:
        return "November";
        break;
    case 12:
        return "December";
        break;
    default:
        return "Invalid";
        break;
    }
}

//Task C
void extdatetype::printdate()const {
    cout << s_month << "-" << d_day << "-" << d_year << endl;
}