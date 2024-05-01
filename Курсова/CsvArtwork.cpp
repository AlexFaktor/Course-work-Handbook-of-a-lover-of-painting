#include "CsvArtwork.h"

CsvArtwork::CsvArtwork() : CsvWriter("")
{
}

CsvArtwork::CsvArtwork(std::string filePath) : CsvWriter(filePath)
{
}

std::vector<Artwork> CsvArtwork::ReadData()
{
    std::string filePath = GetPath();

    std::vector<Artwork> artworks;
    std::ifstream csvFile(filePath);

    if (csvFile.is_open()) {
        std::string line;
        // Пропускаємо заголовок таблиці (якщо він є)
        std::getline(csvFile, line);

        while (std::getline(csvFile, line)) {
            Artwork artwork;
            std::stringstream ss(line);

            // Розбиваємо рядок CSV на окремі поля за роздільником '|'
            std::string field;
            int index = 0;
            while (std::getline(ss, field, '|'))
            {
                switch (index)
                {
                case 0:
                    artwork.Id(std::stoi(field));
                    break;
                case 1:
                    artwork.Name(field);
                    break;
                case 2:
                    artwork.AuthorId(std::stoi(field));
                    break;
                default:
                    // Обробка помилки, якщо поле не розпізнано
                    std::cerr << "Unknown field: " << field << std::endl;
                    break;
                }
                index++;
            }

            artworks.push_back(artwork);
        }

        csvFile.close();
    }
    else
    {
        std::cerr << "CSV Artwork file could not be opened: " << filePath << std::endl;
    }

    return artworks;
}

void CsvArtwork::WriteData(const std::vector<Artwork>& artworks)
{
    std::string filePath = GetPath();
    std::ofstream csvFile(filePath);

    if (csvFile.is_open())
    {
        // Записуємо заголовок таблиці
        csvFile << "Id|Name|AuthorId\n";

        for (const Artwork& art : artworks)
        {
            csvFile << art.Id() << "|" << art.Name() << "|" << art.AuthorId() << "\n";
        }

        csvFile.close();
    }
    else
    {
        std::cerr << "CSV Artworks file could not be opened for writing: " << filePath << std::endl;
    }
}
