#include "string.h"
#include <iostream>

void String::Alloc(int required_memory) {
	size = required_memory;
	str = new char[size];
}

String::String()
{
	size = 1;
	str = new char[size];
	str[0] = '\0';
}



String::String(const char *_str)
{
	size = strlen(_str) + 1;
	str = new char[size];
	strcpy_s(str, size, _str);
}

String::String(const String &_str)
{
	size = _str.size;
	str = new char[size];
	strcpy_s(str, size, _str.str);
}

String::~String() {
	delete[] str;
}

bool String::operator== (const String &_str) const
{
	return strcmp(str, _str.str) == 0;
}

bool String::operator== (const char *_str) const
{
	if (_str != NULL)
		return strcmp(str, _str) == 0;
	return false;	
}

bool String::operator!= (const String &_str) const
{
	return strcmp(str, _str.str) != 0;
}

bool String::operator!= (const char *_str) const
{
	if (_str != NULL)
		return strcmp(str, _str) != 0;
	return false;
}

const String& String::operator= (const String &_str)
{
	if (_str.size > size)
	{
		delete[] str;
		Alloc(size);
	}

	strcpy_s(str, size, _str.str);
	return (*this);
}

const String& String::operator= (const char *_str)
{
	if (_str != NULL)
	{
		if (strlen(_str) + 1 > size)
		{
			delete[] str;
			Alloc(strlen(_str) + 1);
		}

		strcpy_s(str, size, _str);
	}
	else
		clear();
	return (*this);
}

const String& String::operator+= (const String &_str)
{
	
	char *str_tmp = str;
	unsigned int size_tmp = size;
	size = _str.size + size_tmp;
	
	char *tmp;
	tmp = new char[size];
	strcpy_s(tmp, size, str_tmp);
	strcat_s(tmp, size, _str.str);
	
	delete[] str;
	str = new char[size];
	strcpy_s(str, size, tmp);
	delete[] tmp;

	return (*this);
}

const String& String::operator+= (const char *_str)
{
	if (_str != NULL)
	{
		char *str_tmp = str;
		unsigned int size_tmp = size;
		size = strlen(_str) + size_tmp + 1;

		char *tmp;
		tmp = new char[size];
		strcpy_s(tmp, size, str_tmp);
		strcat_s(tmp, size, _str);

		delete[] str;
		str = new char[size];
		strcpy_s(str, size, tmp);
		delete[] tmp;
	}
	else
		clear();

	return (*this);	
}

unsigned int String::getLength() const
{
	return size - 1;
}

char* String::getString() const
{
	return str;
}

unsigned int String::capacity() const
{
	return size;
}

void String::clear()
{
	str[0] = '\0';
}



