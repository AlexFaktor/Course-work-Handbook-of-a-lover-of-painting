#pragma once

#include "Artwork.h"
#include "AdvancedArtwork.h"
#include "Author.h"
#include "Material.h"

#include "CsvAdvancedArtwork.h"
#include "CsvArtwork.h"
#include "CsvAuthor.h"
#include "CsvMaterial.h"

#include <string>
#include <filesystem>
#include <vector>
#include <iostream>
#include <fstream>

class Database
{
private:
	std::filesystem::path _fileAdvancedArtworksPath;
	std::filesystem::path _fileArtworkPath;
	std::filesystem::path _fileAuthorsDataPath;
	std::filesystem::path _fileMaterialsPath;

	CsvAdvancedArtwork _csvAdvancedArtwork;
	CsvArtwork _csvArtwork;
	CsvAuthor _csvAuthor;
	CsvMaterial _csvMaterial;

	bool CreateFolderIfNotExists(const std::string&);
	bool CreateDataFile(const std::string&, const std::string&);

public:
	Database(const std::string&);

	void Save(std::vector<AdvancedArtwork> artworks);
	std::vector<AdvancedArtwork> LoadAdvancedArtwork();

	void Save(std::vector<Artwork> artworks);
	std::vector<Artwork> LoadArtwork();

	void Save(std::vector<Author> artworks);
	std::vector<Author> LoadAuthor();

	void Save(std::vector<Material> artworks);
	std::vector<Material> LoadMaterial();
};

