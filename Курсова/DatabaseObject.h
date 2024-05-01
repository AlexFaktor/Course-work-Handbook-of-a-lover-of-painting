#pragma once

#include <string>

class DatabaseObject
{
private:
	int _id;
public:
	DatabaseObject();
	int Id() const { return _id; }

	void Id(int id);
};

