#pragma once

#include "Material.h"
#include "CsvWriter.h"

class CsvMaterial : public CsvWriter
{
private:

public:
	CsvMaterial();
	CsvMaterial(std::string filePath);

	std::vector<Material> ReadData();
	void WriteData(const std::vector<Material>& artworks);
};

