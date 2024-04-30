#include "CsvAuthor.h"

CsvAuthor::CsvAuthor() : CsvWriter("")
{
}

CsvAuthor::CsvAuthor(std::string filePath) : CsvWriter(filePath)
{
}

std::vector<Author> CsvAuthor::ReadData()
{
    std::string filePath = GetPath();

    std::vector<Author> authors;
    std::ifstream csvFile(filePath);

    if (csvFile.is_open()) {
        std::string line;
        // Пропускаємо заголовок таблиці (якщо він є)
        std::getline(csvFile, line);

        while (std::getline(csvFile, line)) {
            Author author;
            std::stringstream ss(line);

            // Розбиваємо рядок CSV на окремі поля за роздільником '|'
            std::string field;
            int index = 0;
            while (std::getline(ss, field, '|'))
            {
                switch (index)
                {
                case 0:
                    author.Id(std::stoi(field));
                    break;
                case 1:
                    author.Name(field);
                    break;
                case 2:
                    author.Description(field);
                    break;
                default:
                    // Обробка помилки, якщо поле не розпізнано
                    std::cerr << "Unknown field: " << field << std::endl;
                    break;
                }
                index++;
            }

            authors.push_back(author);
        }

        csvFile.close();
    }
    else
    {
        std::cerr << "CSV Author file could not be opened: " << filePath << std::endl;
    }

    return authors;
}

void CsvAuthor::WriteData(const std::vector<Author>& authors)
{
    std::string filePath = GetPath();
    std::ofstream csvFile(filePath);

    if (csvFile.is_open())
    {
        // Записуємо заголовок таблиці
        csvFile << "Id|Name|Decs\n";

        for (const Author& aut : authors)
        {
            csvFile << aut.Id() << "|" << aut.Name() << "|" << aut.Description() << "\n";
        }

        csvFile.close();
    }
    else
    {
        std::cerr << "CSV Authors file could not be opened for writing: " << filePath << std::endl;
    }
}
