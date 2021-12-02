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

	//PreCondition: input integer
	//PostCondition: mutator set id
	void setId(int _id) { id = _id; }

	//PreCondition: input string
	//PostCondition: mutator set fullName
	void setFullName(std::string _fullName) { fullName = _fullName; }

	//PreCondition: input integer
	//PostCondition: mutator set major
	void setMajor(std::string _major) { major = _major; }

	//PreCondition: input float
	//PostCondition: mutator set gpa
	void setGpa(float _gpa) { gpa = _gpa; }

	//PreCondition: NA
	//PostCondition: return id
	int getId(void) { return id; }

	//PreCondition: NA
	//PostCondition: return fullName
	std::string getFullName(void) { return fullName; }

	//PreCondition: NA
	//PostCondition: return major
	std::string getMajor(void) { return major; }

	//PreCondition: NA
	//PostCondition: return gpa
	float getGpa(void) { return gpa; }
};

#endif