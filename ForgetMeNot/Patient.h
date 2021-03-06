#pragma once

#include <string>

class Patient {
public:
	std::string firstName;
	std::string lastName;
	int age;
	std::string birthday;
	std::string carePersonEmail;
	int levelOfAlz;

	std::vector<std::vector<std::string>> family;

	void createPatient(std::string, std::string, int, std::string, std::string, int);
	void addFamilyMember(std::string, std::string, std::string);
};

void Patient::createPatient(std::string fn, std::string ln, int ag, std::string bd, std::string cpe, int loa) {
	firstName = fn;
	lastName = ln;
	age = ag;
	birthday = bd;
	carePersonEmail = cpe;
	levelOfAlz = loa;
}

void Patient::addFamilyMember(std::string name, std::string relation, std::string imageLocation) {
	std::vector<std::string> familyMember;
	familyMember.push_back(name);
	familyMember.push_back(relation);
	familyMember.push_back(imageLocation);
	family.push_back(familyMember);
}