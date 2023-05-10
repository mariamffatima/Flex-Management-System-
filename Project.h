// header file
#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <string>

using namespace std;

class Administrative
{
protected:
	string username;
	string passward;

public:
	Administrative();
	bool signin();
	void addstudent();
	void addteacher();
	void editstudentdetails();
	void editteacherdetails();
	void viewallstudent();
	void viewallteachers();
};

class Student
{
protected:
	string username;
	string password;

public:

	Student();
	bool signin();
	void viewAttendence();
	void viewmarks();
	void viewgrades();
	void viewregisteredcources();
	void viewfeestatus();
};

class Teacher
{
	string firstName;
	string lastName;
	string username;
	string password;
	string cours;

public:
	void setFName(string);
	void setLName(string);
	string getFName();
	string getLName();
	string getCourse();
	Teacher(string, string, string);
	Teacher();
	bool signin();
	void teachertimetable(Teacher tec[]);
	void assignmarks();
	void markattendence();
	void assigngrades();
};

class HOD : public Administrative, public Teacher, public Student
{
	string username;
	string password;

public:
	HOD(string uname, string pass);
	bool signin();
	void asteacher();
	void Viewallactivitiesofteachermodule();
	void accesstostudentmodule();
	void Viewallstudents();
	void Viewallteachers();
};

#endif