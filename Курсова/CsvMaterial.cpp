#include "CsvMaterial.h"

CsvMaterial::CsvMaterial() : CsvWriter("")
{
}

CsvMaterial::CsvMaterial(std::string filePath) : CsvWriter(filePath)
{
}

std::vector<Material> CsvMaterial::ReadData()
{
    std::string filePath = GetPath();

    std::vector<Material> materials;
    std::ifstream csvFile(filePath);

    if (csvFile.is_open()) {
        std::string line;
        // ���������� ��������� ������� (���� �� �)
        std::getline(csvFile, line);

        while (std::getline(csvFile, line)) {
            Material material;
            std::stringstream ss(line);

            // ��������� ����� CSV �� ����� ���� �� ����������� '|'
            std::string field;
            int index = 0;
            while (std::getline(ss, field, '|'))
            {
                switch (index)
                {
                case 0:
                    material.Id(std::stoi(field));
                    break;
                case 1:
                    material.IsAdvancedArtwork(std::stoi(field));
                    break;
                case 2:
                    material.Name(field);
                    break;
                default:
                    // ������� �������, ���� ���� �� ���������
                    std::cerr << "Unknown field: " << field << std::endl;
                    break;
                }
                index++;
            }

            materials.push_back(material);
        }

        csvFile.close();
    }
    else
    {
        std::cerr << "CSV Material file could not be opened: " << filePath << std::endl;
    }

    return materials;
}

void CsvMaterial::WriteData(const std::vector<Material>& materials)
{
    std::string filePath = GetPath();
    std::ofstream csvFile(filePath);

    if (csvFile.is_open())
    {
        // �������� ��������� �������
        csvFile << "Id|IsAdvancedArtwork|Name\n";

        for (Material item : materials)
        {
            csvFile << item.Id() << "|" << item.IsAdvancedArtwork() << "|" << item.Name() << "\n";
        }

        csvFile.close();
    }
    else
    {
        std::cerr << "CSV Materials file could not be opened for writing: " << filePath << std::endl;
    }
}
