#include "Data.h"
#include <iostream>




std::string Data::getValue() const
{
	return Data::stroka;
}

void Data::setValue(std::string value)
{
	Data::stroka = value;
}

//void Data::printDataValue() const
//{
//	std::cout << "value_ = " << value_ << ";" << std::endl;
//}

