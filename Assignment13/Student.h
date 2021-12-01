// Student.h
// Team: Anthony, An, Van, Vincent, Nhan
#ifndef STUDENT_LOCK
#define STUDENT_LOCK

#include <string>

class Student
{
private:
	int id;
	std::string fullName;
	std::string major;
	float gpa;

public:
	Student()
	{
		id = -1;
		fullName = "NA";
		major = "NA";
		gpa = -1;
	}

	Student(int _id, std::string _fullName, std::string _major, float _gpa)
	{
		id = _id;
		fullName = _fullName;
		major = _major;
		gpa = _gpa;
	}

	void setId(int _id) { id = _id; }

	void setFullName(std::string _fullName) { fullName = _fullName; }

	void setMajor(std::string _major) { major = _major; }

	void setGpa(float _gpa) { gpa = _gpa; }

	int getId(void) { return id; }

	std::string getFullName(void) { return fullName; }

	std::string getMajor(void) { return major; }

	float getGpa(void) { return gpa; }
};

#endif