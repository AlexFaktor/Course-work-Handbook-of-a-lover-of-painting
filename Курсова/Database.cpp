#include "Database.h"
#include "CsvArtwork.h"
#include <filesystem>
#include <cstdlib>

bool Database::CreateFolderIfNotExists(const std::string& folderPath)
{
    std::filesystem::path path(folderPath);

    if (!std::filesystem::exists(path))
    {
        try
        {
            // Створення папки
            std::filesystem::create_directory(path);
            return true;
        }
        catch (const std::filesystem::filesystem_error& e)
        {
            std::cerr << "Error creating a folder: " << e.what() << std::endl;
            return false;
        }
    }
    else
    {
        return true;
    }
}

bool Database::CreateDataFile(const std::string& folderPath, const std::string& nameDataFile)
{
    std::filesystem::path path(folderPath);

    // Створення шляху до файлу ArtworksData.txt
    std::filesystem::path artworksDataFilePath(path / nameDataFile);

    // Спроба створення файлу
    try
    {
        if (!std::filesystem::exists(artworksDataFilePath))
        {
            std::ofstream artworksDataFile(artworksDataFilePath);
            if (!artworksDataFile.is_open())
            {
                std::cerr << "The file ArtworksData.txt could not be opened for writing." << std::endl;
                return false;
            }

            artworksDataFile.close();
        }
        return true;
    }
    catch (const std::filesystem::filesystem_error& e)
    {
        std::cerr << "Error creating ArtworksData.txt file: " << e.what() << std::endl;
        return false;
    }
}

Database::Database(const std::string& pathToDb)
{
    CreateFolderIfNotExists(pathToDb);
    CreateDataFile(pathToDb, "AdvancedArtworksData.txt");
    CreateDataFile(pathToDb, "ArtworksData.txt");
    CreateDataFile(pathToDb, "AuthorsData.txt");
    CreateDataFile(pathToDb, "MaterialsData.txt");

    _fileAdvancedArtworksPath = std::filesystem::path(pathToDb + "/AdvancedArtworksData.txt");
    _fileArtworkPath = std::filesystem::path(pathToDb + "/ArtworksData.txt");
    _fileAuthorsDataPath = std::filesystem::path(pathToDb + "/AuthorsData.txt");
    _fileMaterialsPath = std::filesystem::path(pathToDb + "/MaterialsData.txt");

    _csvAdvancedArtwork = CsvAdvancedArtwork(_fileAdvancedArtworksPath.string());
    _csvArtwork = CsvArtwork(_fileArtworkPath.string());
    _csvAuthor = CsvAuthor(_fileAuthorsDataPath.string());
    _csvMaterial = CsvMaterial(_fileMaterialsPath.string());
}

void Database::Save(std::vector<AdvancedArtwork> artworks)
{
    _csvAdvancedArtwork.WriteData(artworks);
}

void Database::Save(std::vector<Artwork> artworks)
{
    _csvArtwork.WriteData(artworks);
}

void Database::Save(std::vector<Author> author)
{
    _csvAuthor.WriteData(author);
}

void Database::Save(std::vector<Material> materials)
{
    _csvMaterial.WriteData(materials);
}

std::vector<Material> Database::LoadMaterial()
{
    return _csvMaterial.ReadData();
}

std::vector<Author> Database::LoadAuthor()
{
    return _csvAuthor.ReadData();
}

std::vector<AdvancedArtwork> Database::LoadAdvancedArtwork()
{
    return _csvAdvancedArtwork.ReadData();
}

std::vector<Artwork> Database::LoadArtwork()
{
    return _csvArtwork.ReadData();
}
