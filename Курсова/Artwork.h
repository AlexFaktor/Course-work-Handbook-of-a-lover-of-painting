#pragma once

#include <string>
#include "DatabaseObject.h"

class Artwork : public DatabaseObject
{
private:
	std::string _name;
	int _authorId;

public:
	Artwork();

	const std::string& Name() const { return _name; }
	int AuthorId() const { return _authorId; }

	void Name(const std::string& name);
	void AuthorId(int authorId);

	virtual bool IsArtwork() { return true; }
};