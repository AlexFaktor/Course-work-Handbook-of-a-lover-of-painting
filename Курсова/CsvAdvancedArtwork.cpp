#include "CsvAdvancedArtwork.h"

CsvAdvancedArtwork::CsvAdvancedArtwork() : CsvWriter("")
{
}

CsvAdvancedArtwork::CsvAdvancedArtwork(std::string filePath) : CsvWriter(filePath)
{
}

std::vector<AdvancedArtwork> CsvAdvancedArtwork::ReadData()
{
    std::string filePath = GetPath();

    std::vector<AdvancedArtwork> artworks;
    std::ifstream csvFile(filePath);

    if (csvFile.is_open()) {
        std::string line;
        // ���������� ��������� ������� (���� �� �)
        std::getline(csvFile, line);

        while (std::getline(csvFile, line)) {
            AdvancedArtwork artwork;
            std::stringstream ss(line);

            // ��������� ����� CSV �� ����� ���� �� ����������� '|'
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
                case 3:
                    artwork.MaterialsId(std::stoi(field));
                    break;
                case 4:
                    artwork.Description(field);
                    break;
                default:
                    // ������� �������, ���� ���� �� ���������
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
        std::cerr << "CSV AdvancedArtwork file could not be opened: " << filePath << std::endl;
    }

    return artworks;
}

void CsvAdvancedArtwork::WriteData(const std::vector<AdvancedArtwork>& artworks)
{
    std::string filePath = GetPath();
    std::ofstream csvFile(filePath);

    if (csvFile.is_open())
    {
        // �������� ��������� �������
        csvFile << "Id|Name|AuthorId|MaterialsId|Decs\n";

        for (AdvancedArtwork art : artworks)
        {
            csvFile << art.Id() << "|" << art.Name() << "|" << art.AuthorId() << "|" << art.MaterialsId() << "|" << art.Description() << "\n";
        }

        csvFile.close();
    }
    else
    {
        std::cerr << "CSV Advanced Artwork Materials file could not be opened for writing: " << filePath << std::endl;
    }
}
