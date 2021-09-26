#include <iostream>
#include"DateType.hh"
#include "Extdatetype.hh"

using namespace std;

// class studentinfo 
class StudentInfo {
private:
    string firstName;
    string lastName;
    int matricNum;


public:
    StudentInfo(string fname, string lname, int num) {
        firstName = fname;
        lastName = lname;
        matricNum = num;
    }

    //Task D
    void showStudentDetail(extdatetype& x)
    {
        // because extdatetype is friend of datetype so it can access 
        // private members of Datetype 
        cout << "***********Student Informayion*********** \n";
        cout << "enter your information as following" << endl;
        cout << "First Name:";
        cin >> firstName;
        cout << "lastName:";
        cin >> lastName;
        cout << "Matric Number:";
        cin >> matricNum;

        cout << "name:" << firstName << " " << lastName << endl;
        //using friend function
        x.printdate();
    }
};
int main() {
    // take month/day/year as input
    int month = 0;
    int day = 0;
    int year = 0;
    int fixedNo;
    cout << "Enter Your Date as mm/dd/yyyy " << endl;
    cin >> month;
    cin >> day;
    cin >> year;

    datetype d1 = datetype(month, day, year);
    //show the input
    d1.printdate();
    // show the days in the selecting month
    cout << "Days in the month are =" << d1.Days_num() << endl;

    cout << "Enter your fixed number" << endl;
    //adding a fixed number of days
    // It will calculate the day,month and year
    cin >> fixedNo;
    d1 = d1 + fixedNo;  // operator overloading
    d1.printdate();
    // is it leap year or not
    d1.Leapyear(year);
    cout << endl;
    //class extdatetype
    // To show the month as string
    extdatetype e1 = extdatetype(month, day, year);
    e1.printdate();
    // student information class
    StudentInfo info = StudentInfo("Muaadh", "Esmail", 149686);
    info.showStudentDetail(e1);   // friend function implementation
    return 0;
}