// project file
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Project.h"
using namespace std;

Administrative::Administrative()
{
    this->username = "Admin";
    this->passward = "Admin";
}

bool Administrative::signin()
{
    string username, password;

    cout << "Enter the username: ";
    cin >> username;
    cout << "Enter the password: ";
    cin >> password;

    if (this->username == username && this->passward == password)
    {
        return true;
    }
    else
        return false;
}
class Data_student
{
public:
    string first_name;
    string last_name;
    string department;
    string registration_no;
    string gender;
    string bloodgroup;
    string address;
    string feestatus;
    string qualification;
    string marks;
    string contact;
    string sid;
};

void Administrative::addstudent()
{

    ofstream fout;
    int year, departmentchoice;
    fout.open("student.txt", ios::app);

    if (!fout.is_open())
    {
        cout << "Not open.";
    }
    Data_student s;
    cout << "Enter the Year of a batch: ";
    cin >> year;
    year = year % 100;
    cout << "Student id: ";
    cin >> s.sid;
    cout << year << "F- " << s.sid << endl;
    fout << year << "F-" << s.sid << "|";
    cout << "First name: ";
    cin >> s.first_name;
    fout << s.first_name << " ";
    cout << "Last name: ";
    cin >> s.last_name;
    fout << s.last_name << "|";
    cout << "Press 1 for Computer science." << endl;
    cout << "Press 2 for Electrical Engineering." << endl;
    cout << "Press 3 for Software Engineering." << endl;
    cout << "Press 4 for Buisness." << endl;
    cout << "Press 5 for Social Science." << endl;
    cout << "Department choice: ";
    cin >> departmentchoice;
    switch (departmentchoice)
    {
    case 1:
        s.department = "Computer Science";
        break;
    case 2:
        s.department = "Electric Engineering";
        break;
    case 3:
        s.department = "Software Engineering";
        break;
    case 4:
        s.department = "Business";
        break;
    case 5:
        s.department = "Social Sciences";
        break;
    }
    cout << s.department << endl;
    fout << s.department << "|";
    cout << "Registration Date: ";
    cin >> s.registration_no;
    fout << s.registration_no << "|";
    cout << "Gender: ";
    cin >> s.gender;
    fout << s.gender << "|";
    cout << "Blood group: ";
    cin >> s.bloodgroup;
    fout << s.bloodgroup << "|";
    cout << "address: ";
    cin.ignore();
    getline(cin, s.address);
    fout << s.address << "|";
    cout << "Fee statue: ";
    cin >> s.feestatus;
    fout << s.feestatus << "|";
    cout << "Qualification: ";
    cin >> s.qualification;
    fout << s.qualification << "|";
    cout << "Contact No: ";
    cin >> s.contact;
    fout << s.contact << "|";
    cout << "Marks: ";
    cin >> s.marks;
    fout << s.marks << "|"
        << "\n";
    fout.close();
}

class Data_teacher
{
public:
    string fname, l_name, department, username, passward, registration_date, gender, contact_no, address, qualification, salary;
    int T_id;
    static int count;
    Data_teacher()
    {
        T_id = count;
        count++;
    }
};
int Data_teacher::count = 1;
void Administrative::addteacher()
{
    Data_teacher t;
    int department_choice;
    ofstream fout;
    fout.open("Teacher.txt", ios::app);

    if (!fout.is_open())
    {
        cout << "Not found";
    }
    cout << "First name: ";
    cin >> t.fname;
    cout << "Last name: ";
    cin >> t.l_name;
    cout << "Press 1 for Computer science." << endl;
    cout << "Press 2 for Electrical Engineering." << endl;
    cout << "Press 3 for Software Engineering." << endl;
    cout << "Press 4 for Buisness." << endl;
    cout << "Press 5 for Social Science." << endl;

    cout << "Department choice: ";
    cin >> department_choice;
    switch (department_choice)
    {
    case 1:
        t.department = "Computer Science";
        break;
    case 2:
        t.department = "Electric Engineering";
        break;
    case 3:
        t.department = "Software Engineering";
        break;
    case 4:
        t.department = "Business";
        break;
    case 5:
        t.department = "Social Sciences";
        break;
    }
    cout << t.department << endl;

    cout << "Teacher ID: ";
    if (department_choice == 1)
    {
        cout << "C-" << t.T_id;
        fout << "C-" << t.T_id << "|";
    }
    else if (department_choice == 2)
    {
        cout << "E-" << t.T_id;
        fout << "E-" << t.T_id << "|";
    }
    else if (department_choice == 3)
    {
        cout << "S-" << t.T_id;
        fout << "S-" << t.T_id << "|";
    }
    else if (department_choice == 4)
    {
        cout << "B-" << t.T_id;
        fout << "B-" << t.T_id << "|";
    }
    else if (department_choice == 5)
    {
        cout << "S-" << t.T_id;
        fout << "S-" << t.T_id << "|";
    }
    cout << endl;
    fout << t.fname << " ";

    fout << t.l_name << "|";

    fout << t.department << "|";
    cout << "Username: ";
    cin >> t.username;
    fout << t.username << "|";
    cout << "Passward: ";
    cin >> t.passward;
    fout << t.passward << "|";
    cout << "Registration date: ";
    cin >> t.registration_date;
    fout << t.registration_date << "|";
    cout << "Gender: ";
    cin >> t.gender;
    fout << t.gender << "|";
    cout << "Contact number: ";
    cin >> t.contact_no;
    fout << t.contact_no << "|";
    cout << "Address: ";
    cin.ignore();
    getline(cin, t.address);
    fout << t.address << "|";
    cout << "Salary: ";
    cin >> t.salary;
    fout << t.salary << "|";
    cout << "Qualification: ";
    cin >> t.qualification;
    fout << t.qualification << "|";
    fout.close();
}

void Administrative::editstudentdetails()
{
    int fieldchoice;
    string rollno;
    cout << "Enter the Roll no of student to edit: ";
    cin >> rollno;

    ifstream fin;
    fin.open("student.txt");
    if (!fin.is_open())
    {
        cout << "File not found!";
        return;
    }
    string tempRoll;
    string line;
    Data_student s;
    ofstream fout;
    fout.open("student_temp.txt", ios::app);
    if (!fout.is_open())
    {
        cout << "File can't be opened";
        exit(1);
    }
    while (getline(fin, line))
    {
        tempRoll = line.substr(0, line.find("|"));
        tempRoll = (tempRoll).substr((tempRoll).find("-") + 1);
        if (tempRoll == rollno)
        {
            cout << "Which field do you want to edit?" << endl;
            cout << "1. First Name" << endl;
            cout << "2. Last Name" << endl;
            cout << "3. Fee Status" << endl;
            cout << "4. Address" << endl;
            cout << "5. Contact No" << endl;
            cout << "Enter choice: ";
            cin >> fieldchoice;
            string tok;
            int itr = 0, pos = 0, ind = 0;
            string tempLine;
            fin.seekg(0);
            while (getline(fin, tempLine))
            {
                if (tempLine != line)
                {
                    fout << tempLine << '\n';
                }
                else
                {
                    switch (fieldchoice)
                    {
                    case 1:
                    case 2:
                        ind = 1;
                        break;
                    case 3:
                        ind = 7;
                        break;
                    case 4:
                        ind = 6;
                        break;
                    case 5:
                        ind = 9;
                    }
                    for (; !line.empty() && (line.find("|") != string::npos && (pos = line.find("|"))) && ((tok = line.substr(0, pos))[0]); (line = line.substr(pos + 1)))
                    {

                        if (ind != itr)
                        {
                            fout << tok << "|";
                        }
                        else
                        {
                            string edit;
                            switch (fieldchoice)
                            {
                            case 1:

                            case 2:
                                cout << "Enter the name: ";
                                cin.ignore();
                                getline(cin, edit);
                                fout << edit << "|";
                                cout << "Student record updated!" << endl;

                                break;
                            case 3:
                                cout << "Enter fee status to edit: ";
                                cin >> edit;
                                fout << edit << "|";
                                cout << "Student record updated!" << endl;

                                break;
                            case 4:
                                cout << "Enter address to edit: ";
                                cin >> edit;
                                fout << edit << "|";
                                cout << "Student record updated!" << endl;

                                break;
                            case 5:
                                cout << "Enter Contact No to edit: ";
                                cin >> edit;
                                fout << edit << "|";
                                cout << "Student record updated!" << endl;

                                break;
                            }
                        }

                        itr++;
                    }
                    fout << '\n';
                }
            }
        }
    }
    if (tempRoll != rollno)
    {
        cout << "Roll no. is not found.";
    }
    fin.close();
    fout.close();
    remove("student.txt");
    rename("student_temp.txt", "student.txt");
}

void Administrative::editteacherdetails()
{
    int fieldchoice;
    string id;
    cout << "Enter the id of a Teacher to edit: ";
    cin >> id;

    ifstream fin;
    fin.open("Teacher.txt");
    if (!fin.is_open())
    {
        cout << "File not found!";
        return;
    }
    string tempRoll;
    string line;
    Data_teacher t;
    bool found = false; // added boolean flag to track if the id was found
    while (getline(fin, line))
    {
        tempRoll = line.substr(0, line.find("|"));
        tempRoll = (tempRoll).substr((tempRoll).find("-") + 1);
        if (tempRoll == id)
        {
            found = true; // set flag to true if id is found
            cout << "Which field do you want to edit?" << endl;
            cout << "1. Adress" << endl;
            cout << "2. Contact No." << endl;
            cout << "3. Qualification" << endl;
            cout << "4. Salary" << endl;
            cout << "Enter choice: ";
            cin >> fieldchoice;
            string tok;
            int itr = 0, pos = 0, ind = 0;
            ofstream fout;
            fout.open("Teacher_temp.txt", ios::app);
            if (!fout.is_open())
            {
                cout << "File can't be opened";
                exit(1);
            }

            string tempLine;
            fin.seekg(0);
            while (getline(fin, tempLine))
            {
                if (tempLine != line)
                {
                    fout << tempLine << "\n";
                }
                else
                {
                    switch (fieldchoice)
                    {
                    case 1:

                        ind = 8;
                        break;
                    case 2:
                        ind = 7;
                        break;
                    case 3:
                        ind = 10;
                        break;
                    case 4:
                        ind = 9;
                    }
                    for (; !line.empty() && (line.find("|") != string::npos && (pos = line.find("|"))) && ((tok = line.substr(0, pos))[0]); (line = line.substr(pos + 1)))

                    {

                        if (ind != itr)
                        {
                            fout << tok << "|";
                        }
                        else
                        {
                            string edit;
                            switch (fieldchoice)
                            {
                            case 1:

                                cout << "Enter the Address: ";
                                cin.ignore();
                                getline(cin, edit);
                                fout << edit << "|";
                                cout << "Teacher record updated!" << endl;

                                break;
                            case 2:
                                cout << "Enter Conract no. to edit: ";
                                cin >> edit;
                                fout << edit << "|";
                                cout << "Teacher record updated!" << endl;

                                break;
                            case 3:
                                cout << "Enter Qualification to edit: ";
                                cin >> edit;
                                fout << edit << "|";
                                cout << "Teacher record updated!" << endl;

                                break;
                            case 4:
                                cout << "Enter Salary to edit: ";
                                cin >> edit;
                                fout << edit << "|";
                                cout << "Teacher record updated!" << endl;

                                break;
                            }
                        }

                        itr++;
                    }
                    cout << "\n";
                }
            }
            if (tempRoll != id)
            {
                cout << "Record not found";
            }
            fin.close();
            fout.close();

            remove("Teacher.txt");
            rename("Teacher_temp.txt", "Teacher.txt");
            break;
        }
    }
}

void Administrative::viewallteachers()
{
    Data_teacher t;
    ifstream fin;
    string line;
    fin.open("Teacher.txt", ios::app);
    if (!fin.is_open())
    {
        cout << "File is not open.";
    }
    else
    {
        while (getline(fin, line))
        {
            if (!line.find("|"))
            {
                cout << line;
            }
        }
    }
}
string p;
string u;
Student::Student()
{
    ifstream fin;
    fin.open("Studentpassword.txt");
    if (!fin.is_open())
    {
        cout << "File not open";
        return;
    }

    string line;
    while (getline(fin, line))
    {
        // Extract username and password from the first line
        size_t pipePos = line.find("|");
        u = line.substr(0, pipePos);
        p = line.substr(pipePos + 1);
    }

    fin.close();
    this->username = u;
    this->password = p;
}
string srollno;

bool Student::signin()
{
    string line;

    ifstream fin;
    fin.open("student.txt");
    if (!fin.is_open())
    {
        cout << "File is not open.";
        return false;
    }
    cout << "Enter roll no.: ";
    cin >> srollno;

    try {
        while (getline(fin, line))
        {
            string tempRoll = line.substr(0, line.find("|"));
            tempRoll = tempRoll.substr(tempRoll.find("-") + 1);
            if (tempRoll == srollno)
            {
                cout << "Enter the user name: ";
                cin >> username;
                cout << "Enter the password: ";
                cin >> password;

                if (u == username && p == password)
                {
                    cout << line << endl;
                    return true; // return true to indicate sign-in success
                }
                else
                {
                    throw runtime_error("Wrong username and password");
                }
            }
        }

        cout << "Invalid ID." << endl;
        return false; // return false to indicate sign-in failure
    }

    catch (const std::exception& e1) {
        std::cerr << "Error: " << e1.what() << '\n';
        return false;

    }
}
string u1, p1;
Teacher::Teacher()
{
    ifstream fin;
    fin.open("Teacherpassword.txt");
    if (!fin.is_open())
    {
        cout << "File not open";
        return;
    }

    string line;
    while (getline(fin, line))
    {
        // Extract username and password from the first line
        size_t pipePos = line.find("|");
        u1 = line.substr(0, pipePos);
        p1 = line.substr(pipePos + 1);
    }

    fin.close();

    this->username = u1;
    this->password = p1;
}

string id;

bool Teacher::signin()
{

    cout << "Enter id: ";
    cin >> id;

    // Open file and check if it is open
    ifstream fin("teacher.txt");
    if (!fin.is_open())
    {
        cout << "File is not open."; // display error message
        return false;                // return false to indicate sign-in failure
    }

    string line;
    try {
        while (getline(fin, line))
        {
            string tempRoll = line.substr(0, line.find("|"));
            tempRoll = tempRoll.substr(tempRoll.find("-") + 1);
            if (tempRoll == id)
            {
                cout << "Enter the user name: ";
                cin >> username;
                cout << "Enter the password: ";
                cin >> password;

                if (u1 == username && p == password)
                {
                    cout << line << endl;
                    return true; // return true to indicate sign-in success
                }
                else
                {
                    throw runtime_error("Wrong username and password");
                }
            }
        }

        cout << "Invalid ID." << endl;
        return false; // return false to indicate sign-in failure
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return false;
    }
}
istream& operator>>(istream& is, Teacher& t)
{
    is >> t;
    return is;
}

ostream& operator<<(ostream& os, Teacher& t)
{
    os << t;
    return os;
}
void Teacher::markattendence()
{
    ifstream fin("student.txt");
    if (!fin.is_open())
    {
        cout << "File not found." << endl;
        return;
    }

    int totalclass;
    cout << "Enter the number of students in the class: ";
    cin >> totalclass;

    string* student = new string[totalclass];
    for (int i = 0; i < totalclass; ++i)
    {
        string rollno;
        cout << "Enter the student roll no: ";
        cin >> rollno;
        student[i] = rollno;
    }

    string line;
    while (getline(fin, line))
    {
        string tempRoll = line.substr(line.find("-") + 1, line.find("|") - line.find("-") - 1);

        bool studentFound = false;
        string date;
        cout << "Enter the date: ";
        cin >> date;
        for (int i = 0; i < totalclass; ++i)
        {
            if (tempRoll == student[i])
            {
                studentFound = true;
                cout << line << endl;

                char attendance;
                cout << "Press P for present and A for absent: ";
                cin >> attendance;

                string fileName = "Attendance_" + id + ".txt";
                ofstream fout(fileName, ios::app);
                if (!fout.is_open())
                {
                    cout << "Unable to create or open file." << endl;
                    return;
                }

                fout << tempRoll << "|"
                    << "   " << date << "|"
                    << "   " << attendance << endl;
                fout.close();
                break;
            }
            else
            {
                try
                {
                    runtime_error("No data found");
                }
                catch (exception& e)
                {
                    cout << e.what() << '\n';
                }
            }
        }
    }

    delete[] student;
}
// Define the friend function outside the class definition
istream& operator>>(istream& is, Student& s)
{
    is >> s;
    return is;
}

ostream& operator<<(ostream& os, Student& s)
{
    os << s;
    return os;
}

void Student::viewAttendence()
{
    ifstream fin;
    string filename;
    string line;
    int tteachers;

    cout << "Enter the ID of the teacher: ";
    cin >> id;
    filename = "Attendance_" + id + ".txt";
    fin.open(filename);
    if (!fin.is_open())
    {
        cout << "File not opened.";
        return;
    }
    else
    {
        bool datafound = false;
        while (getline(fin, line))
        {
            string tempRoll = line.substr(0, line.find("|"));
            if (tempRoll == srollno)
            {
                size_t pos = line.find('|');
                while (pos != string::npos)
                {
                    line.replace(pos, 1, " ");
                    pos = line.find('|', pos + 1);
                }
                cout << "Rno."
                    << " "
                    << "Date"
                    << " "
                    << "Attendence" << endl;
                cout << line << endl;
                datafound = true;
            }
        }

        if (!datafound)
        {
            try
            {
                throw runtime_error("No data found");
            }
            catch (exception& e)
            {
                cout << e.what() << endl;
            }
        }
    }

    fin.close();
}

void Student::viewregisteredcources()
{
    ifstream fin;
    fin.open("RegisteredCourses.txt");

    string line;
    if (!fin.is_open())
    {
        cout << "File not open." << endl;
    }
    else
    {
        while (getline(fin, line))
        {
            string tempRoll = line.substr(0, line.find("|"));
            tempRoll = tempRoll.substr(tempRoll.find("-") + 1);
            if (tempRoll == srollno)
            {
                // Replace the "|" character with a space
                size_t pos = line.find('|');
                while (pos != string::npos)
                {
                    line.replace(pos, 1, " ");
                    pos = line.find('|', pos + 1);
                }
                cout << "Registered cources are: " << endl;
                cout << line << endl;
            }
        }

        fin.close();
    }
}

void Teacher::assignmarks()
{
    ifstream fin("student.txt");
    if (!fin.is_open())
    {
        cout << "File not found." << endl;
        return;
    }

    int totalclass;
    cout << "Enter the number of students in the class: ";
    cin >> totalclass;

    string* student = new string[totalclass];
    for (int i = 0; i < totalclass; ++i)
    {
        string rollno;
        cout << "Enter the student roll no: ";
        cin >> rollno;
        student[i] = rollno;
    }

    string line;
    while (getline(fin, line))
    {
        string tempRoll = line.substr(line.find("-") + 1, line.find("|") - line.find("-") - 1);

        bool studentFound = false;

        for (int i = 0; i < totalclass; ++i)
        {
            if (tempRoll == student[i])
            {
                studentFound = true;
                cout << line << endl;

                int Marks;
                cout << "Enter a marks of student " << i + 1 << ": ";
                cin >> Marks;

                string fileName = "Marks_" + id + ".txt";
                ofstream fout(fileName, ios::app);
                if (!fout.is_open())
                {
                    cout << "Unable to create or open file." << endl;
                    return;
                }

                fout << tempRoll << "|"
                    << "  " << Marks << endl;
                fout.close();
                break;
            }
            else
            {
                try
                {
                    runtime_error("No data found");
                }
                catch (exception& e)
                {
                    cout << e.what() << '\n';
                }
            }
        }
    }

    delete[] student;
}

void Student::viewmarks()
{
    ifstream fin;
    string filename;
    string line;
    int tteachers;

    cout << "Enter the ID of the teacher: ";
    cin >> id;
    filename = "Marks_" + id + ".txt";
    fin.open(filename);
    if (!fin.is_open())
    {
        cout << "File not opened.";
        return;
    }
    else
    {
        bool datafound = false;
        while (getline(fin, line))
        {
            string tempRoll = line.substr(0, line.find("|"));
            if (tempRoll == srollno)
            {
                size_t pos = line.find('|');
                while (pos != string::npos)
                {
                    line.replace(pos, 1, " ");
                    pos = line.find('|', pos + 1);
                }
                cout << "RNo."
                    << " "
                    << "Marks" << endl;
                cout << line << endl;
                datafound = true;
            }
        }

        if (!datafound)
        {
            try
            {
                throw runtime_error("No data found");
            }
            catch (exception& e)
            {
                cout << e.what() << endl;
            }
        }
    }

    fin.close();
}

void Teacher::assigngrades()
{
    ifstream fin("student.txt");
    if (!fin.is_open())
    {
        cout << "File not found." << endl;
        return;
    }

    int totalclass;
    cout << "Enter the number of students in the class: ";
    cin >> totalclass;

    string* student = new string[totalclass];
    for (int i = 0; i < totalclass; ++i)
    {
        string rollno;
        cout << "Enter the student roll no: ";
        cin >> rollno;
        student[i] = rollno;
    }

    string line;
    while (getline(fin, line))
    {
        string tempRoll = line.substr(line.find("-") + 1, line.find("|") - line.find("-") - 1);

        bool studentFound = false;

        for (int i = 0; i < totalclass; ++i)
        {
            if (tempRoll == student[i])
            {
                studentFound = true;
                cout << line << endl;

                string grades;
                cout << "Enter a Grade of student " << i + 1 << ": ";
                cin >> grades;

                string fileName = "Grades_" + id + ".txt";
                ofstream fout(fileName, ios::app);
                if (!fout.is_open())
                {
                    cout << "Unable to create or open file." << endl;
                    return;
                }

                fout << tempRoll << "|"
                    << "  " << grades << endl;
                fout.close();
                break;
            }
            else
            {
                try
                {
                    runtime_error("No data found");
                }
                catch (exception& e)
                {
                    cout << e.what() << '\n';
                }
            }
        }
    }

    delete[] student;
}

void Student::viewgrades()
{
    ifstream fin;
    string filename;
    string line;
    int tteachers;

    cout << "Enter the ID of the teacher: ";
    cin >> id;
    filename = "Grades_" + id + ".txt";
    fin.open(filename);
    if (!fin.is_open())
    {
        cout << "File not opened.";
        return;
    }
    else
    {
        bool datafound = false;
        while (getline(fin, line))
        {
            string tempRoll = line.substr(0, line.find("|"));
            if (tempRoll == srollno)
            {
                size_t pos = line.find('|');
                while (pos != string::npos)
                {
                    line.replace(pos, 1, " ");
                    pos = line.find('|', pos + 1);
                }
                cout << "RNo."
                    << " "
                    << "Grade" << endl;
                cout << line << endl;
                datafound = true;
            }
        }

        if (!datafound)
        {
            try
            {
                throw runtime_error("No data found");
            }
            catch (exception& e)
            {
                cout << e.what() << endl;
            }
        }
    }

    fin.close();
}
Teacher::Teacher(string first, string last, string course) {
    firstName = first;
    lastName = last;
    cours = course;
}
void Teacher::setFName(string f) {
    firstName = f;
}
void Teacher::setLName(string l) {
    lastName = l;
}
string Teacher::getFName() {
    return firstName;
}
string Teacher::getLName() {
    return lastName;
}
string Teacher::getCourse() {
    return cours;
}
void Teacher::teachertimetable(Teacher tec[])
{
    string courseNames[4] = { "OOP", "Data Base", "Data Structure", "PF" };
    Teacher tec[2]; // assume there are two teachers
    tec[0] = Teacher("John", "Doe", "Data Base"); // create the first teacher object with first name, last name, and course
    tec[1] = Teacher("Jane", "Smith", "Data Structure"); // create the second teacher object with first name, last name, and course
    for (int i = 0; i < 2; i++) {
        cout << "Teacher " << i + 1 << " Time Table:" << endl;

        cout << "Lecturer\t\tDate\t\tTime\t\tCourse Name" << endl;
        for (int j = 0; j < 4; j++) {
            cout << tec[i].getFName() << " " << tec[i].getLName() << "\t";
            string date = to_string(j + 1) + "/5/2023";
            int startHour = 9 + j;
            if (startHour > 12) {
                startHour -= 12;
            }
            int endHour = startHour + 1;
            if (endHour > 12) {
                endHour -= 12;
            }
            string startTime = to_string(startHour) + ":00";
            string endTime = to_string(endHour) + ":00";
            string time = startTime + "-" + endTime;
            string courseName = tec[i].getCourse();
            if (courseName == "") {
                courseName = courseNames[j];
            }
            cout << date << "\t\t" << time << "\t\t" << courseName << endl;
        }
        cout << endl;
    }

}