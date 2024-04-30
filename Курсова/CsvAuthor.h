#pragma once

#include "Author.h"
#include "CsvWriter.h"

class CsvAuthor : public CsvWriter
{
private:

public:
	CsvAuthor();
	CsvAuthor(std::string filePath);

	std::vector<Author> ReadData();
	void WriteData(const std::vector<Author>& artworks);
};

