#pragma once

#include <string>
#include "DatabaseObject.h"

class Artwork : public DatabaseObject
{
private:
	std::string _name;
	int _authorId;
	int _materialsId;

public:
	Artwork();

	const std::string& Name() const { return _name; }
	int AuthorId() const { return _authorId; }
	int MaterialsId() const { return _materialsId; }

	void Name(const std::string& name);
	void AuthorId(int authorId);
	void MaterialsId(int materialsId);

	virtual bool IsArtwork() { return true; }
};