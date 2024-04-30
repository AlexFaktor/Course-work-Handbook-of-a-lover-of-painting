#pragma once

#include <string>
#include "DatabaseObject.h"

class Material : public DatabaseObject
{
private:
	bool _isAdvancedArtwork;
	std::string _name;

public:
	bool IsAdvancedArtwork() { return _isAdvancedArtwork; }
	const std::string& Name() const { return _name; }

	void IsAdvancedArtwork(bool);
	void Name(const std::string& name);
};