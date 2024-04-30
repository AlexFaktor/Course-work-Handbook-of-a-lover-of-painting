#include "AuthorEditor.h"

AuthorEditor::AuthorEditor(std::vector<Author>& authors)
	: _authors(authors)
{
}

int AuthorEditor::GetFreeId()
{
	int id = 1;
	while (true)
	{
		if (std::find_if(_authors.begin(), _authors.end(), [id](const Author& artwork) { return artwork.Id() == id; }) == _authors.end())
		{
			return id;
		}
		++id;
	}
	return -1;
}

Author AuthorEditor::GetById(int id)
{
	for (int i = 0; i < _authors.size(); i++)
	{
		if (_authors[i].Id() == id)
			return _authors[i];
	}
	throw new _exception();
}

bool AuthorEditor::AddAuthor(Author* author)
{
	author->Id(GetFreeId());
	_authors.push_back(*author);
	return true;
}

bool AuthorEditor::UpdateFullAuthor(Author* author)
{
	for (int i = 0; i < _authors.size(); i++)
	{
		if (_authors[i].Id() == author->Id())
		{
			_authors[i].Name(author->Name());
			_authors[i].Description(author->Description());
			return true;
		}
	}
	return false;
}

bool AuthorEditor::DeleteByIndex(int index)
{
	_authors.erase(_authors.begin() + index);
	return true;
}

bool AuthorEditor::DeleteByName(const std::string& name)
{
	return false;
}
