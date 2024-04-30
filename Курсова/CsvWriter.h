#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <Windows.h>

class CsvWriter
{
private:
	std::string _filePath;

public:
	CsvWriter(std::string filePath);

	std::string GetPath();
};