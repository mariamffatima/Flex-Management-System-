// main .cpp
#include <iostream>
#include "Project.h"

using namespace std;

int main()
{

    int choice;
    cout << "Press 1 for Administrative. " << endl;
    cout << "Press 2 for as a Student." << endl;
    cout << "Press 3 for as a Teacher." << endl;
    cout << "Enter Your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        Administrative a1;
        if (a1.signin())
        {
            int choice;
            cout << "Press 1 to add a student." << endl;
            cout << "Press 2 to add a teacher." << endl;
            cout << "Press 3 to edit student detials." << endl;
            cout << "Press 4 to edit teacher detials." << endl;
            cout << "Press 5 to show all the Teachers." << endl;
            cout << "Enter Choice: ";
            cin >> choice;
            if (choice == 1)
            {
                int totalstudents;
                cout << "Enter the total number of students you want to Add: ";
                cin >> totalstudents;

                for (int i = 0; i < totalstudents; ++i)
                {
                    cout << "Detail of " << i + 1 << ": " << endl;
                    a1.addstudent();
                }
            }
            else if (choice == 2)
            {

                int totalteachers;
                cout << "Enter the total number of teachers you want to Add: ";
                cin >> totalteachers;

                for (int i = 0; i < totalteachers; ++i)
                {
                    cout << "Detail of " << i + 1 << ": " << endl;
                    a1.addteacher();
                }
            }
            else if (choice == 3)
            {
                a1.editstudentdetails();
            }
            else if (choice == 4)
            {
                a1.editteacherdetails();
            }
            else if (choice == 5)
            {
                a1.viewallteachers();
            }
        }
        else
        {
            cout << "Invalid User name and password!";
        }
    }
    else if (choice == 2)
    {
        Student s;
        if (s.signin())
        {
            int choice;
            cout << "Press 1 to view a attendence." << endl;
            cout << "Press 2 to view registered cources." << endl;
            cout << "Press 3 to view a marks." << endl;
            cout << "Press 4 to view grade." << endl;
            cout << "Enter the choice: ";
            cin >> choice;
            if (choice == 1)
            {
                s.viewAttendence();
            }
            else if (choice == 2)
            {
                s.viewregisteredcources();
            }
            else if (choice == 3)
            {
                s.viewmarks();
            }
            else if (choice == 4)
            {
                s.viewgrades();
            }
        }
    }
    else if (choice == 3)
    {
        Teacher t;
        if (t.signin())
        {
            int choice;
            cout << "Press 1 to mark a attendence." << endl;
            cout << "Press 2 to assign a marks." << endl;
            cout << "Press 3 to assign a grade. " << endl;
            cout << "Press 4 to view timetable." << endl;
            cout << "Enter choice: ";
            cin >> choice;
            if (choice == 1)
            {
                t.markattendence();
            }
            else if (choice == 2)
            {
                t.assignmarks();
            }
            else if (choice == 3)
            {
                t.assigngrades();
            }
            else  if (choice == 4) {
                Teacher tec[2];
                tec[0].setFName("Tahir");
                tec[0].setLName("Shah");
                tec[1].setFName("Chahat");
                tec[1].setLName("Fateh");
                tec[0].teachertimetable(tec);
            }
        }
        else
        {
            return 0;
        }
    }
    return 0;
}