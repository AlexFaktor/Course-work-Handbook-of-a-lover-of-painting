#pragma once

#include <string>
#include "DatabaseObject.h"

class Author : public DatabaseObject
{
private:
	std::string _name;
	std::string _description;

public:
	const std::string& Name() const { return _name; }
	const std::string& Description() const { return _description; }

	void Name(const std::string& name);
	void Description(const std::string& description);
};

