#include "CsvWriter.h"

CsvWriter::CsvWriter(std::string filePath)
{
	_filePath = filePath;
}

std::string CsvWriter::GetPath()
{
	return _filePath;
}
