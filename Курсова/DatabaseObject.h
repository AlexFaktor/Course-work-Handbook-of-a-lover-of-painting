#pragma once

#include <string>

class DatabaseObject
{
private:
	int _id;

public:
	int Id() const { return _id; }

	void Id(int id);
};

