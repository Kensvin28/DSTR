#ifndef DATA_H
#define DATA_H

#include <string>

struct Tutor
{
	int tutor_ID;
	std::string name;
	std::string date_joined;
	std::string date_terminated;
	double hourly_rate;
	std::string phone;
	std::string address;
	int centre_code;
	std::string centre_name;
	int subject_code;
	std::string subject_name;
	int rating;
	Tutor* next;
	Tutor* prev;
};

struct Staff
{
	int staff_id;
	std::string staff_name;
	std::string staff_position;
	int centre_code;
	std::string staff_password;
	Staff* next;
	Staff* prev;
};

#endif