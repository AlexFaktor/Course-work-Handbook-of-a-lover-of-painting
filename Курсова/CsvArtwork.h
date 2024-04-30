#pragma once

#include "Artwork.h"
#include "CsvWriter.h"

class CsvArtwork : public CsvWriter
{
private:

public:
	CsvArtwork();
	CsvArtwork(std::string filePath);

	std::vector<Artwork> ReadData();
	void WriteData(const std::vector<Artwork>& artworks);
};

