#pragma once

#include "AdvancedArtwork.h"
#include "CsvWriter.h"


class CsvAdvancedArtwork : public CsvWriter
{
private:

public:
	CsvAdvancedArtwork();
	CsvAdvancedArtwork(std::string filePath);

	std::vector<AdvancedArtwork> ReadData();
	void WriteData(const std::vector<AdvancedArtwork>& artworks);
};

