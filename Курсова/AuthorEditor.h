#pragma once

#include "Author.h"

#include <vector>
#include <string>

class AuthorEditor
{
private:
	std::vector<Author>& _authors;
public:
	AuthorEditor(std::vector<Author>& authors);

	int GetFreeId();

	Author GetById(int id);

	bool AddAuthor(Author* author);

	bool UpdateFullAuthor(Author* author);

	bool DeleteByIndex(int index);
	bool DeleteByName(const std::string& name);
};

