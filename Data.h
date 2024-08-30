#pragma once
#include <mutex>
#include <vector>
#include <string>

class Data
{
private:
	std::string stroka;

public:
	Data() = default;
	Data(std::string stroka1) : stroka(stroka1) {}
	
	std::mutex m;
	
	std::string getValue() const;
	void setValue(std::string value);
};