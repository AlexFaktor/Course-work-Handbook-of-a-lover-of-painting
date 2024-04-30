#include "MenuText.h"


void MenuText::SetEncoding1251()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void MenuText::SetEncodingUTF_8()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
}

void MenuText::Indents(int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << std::endl;
	}
}

void MenuText::InvalidInput(const std::string userInput)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

	std::cout << "Невідомий вибір - \""
		<< userInput
		<< "\"\n"
		<< std::endl;

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void MenuText::TheOperationIsSuccessful()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	std::cout << "Операція прошла успішно :)" << std::endl;

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void MenuText::TheOperationIsFailed()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

	std::cout << "Під час операції виникли проблеми :(\n" << std::endl;

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void MenuText::DataInputCyrillicNotSupported()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

	std::cout << "Введення даних кирилицею не підтримується!\n" << std::endl;

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void MenuText::ProgramEnd()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

	std::cout << "\nВихід з програми..." << std::endl;

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void MenuText::WaitForUser()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);

	std::cout << "\nНатистніть клавішу, щоб продовжити..." << std::endl;

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void MenuText::RoleChoice()
{
	std::cout << "<Виберіть рівень доступу>\n" << std::endl;
	std::cout << "1 - Глядач " << std::endl;
	std::cout << "2 - Адміністратор " << std::endl;
	std::cout << "0 - Вихід " << std::endl;
	std::cout << "\n=> ";
}

void MenuText::ViewerChoice()
{
	std::cout << "<Виберіть операцію глядача>\n" << std::endl;
	std::cout << "1 - Список всіх картин " << std::endl;
	std::cout << "2 - Список всіх продвинутих картин " << std::endl;
	std::cout << "3 - Список всіх авторів " << std::endl;
	std::cout << "4 - Список всіх матерялів" << std::endl;
	std::cout << "0 - Повернутися до вибору ролі " << std::endl;
	std::cout << "\n=> ";
}

void MenuText::AdminChoice()
{
	std::cout << "<Виберіть операцію адміністратора>\n" << std::endl;
	std::cout << "1 - Картини " << std::endl;
	std::cout << "2 - Продвинуті картини " << std::endl;
	std::cout << "3 - Автори " << std::endl;
	std::cout << "4 - Матеріали " << std::endl;
	std::cout << "0 - Повернутися до вибору ролі " << std::endl;
	std::cout << "\n=> ";
}

void MenuText::ViewAuthorChoice()
{
	std::cout << "<Виберіть що хочете переглянути у автора>\n" << std::endl;
	std::cout << "1 - Біографія " << std::endl;
	std::cout << "2 - Картини автора " << std::endl;
	std::cout << "0 - Вихід " << std::endl;
	std::cout << "\n=> ";
}

void MenuText::AdminArtworksChoice()
{
	std::cout << "<Виберіть операцію>\n" << std::endl;
	std::cout << "1 - Додати картину " << std::endl;
	std::cout << "2 - Оновити картину " << std::endl;
	std::cout << "3 - Видалити картину " << std::endl;
	std::cout << "0 - Вихід " << std::endl;
	std::cout << "\n=> ";
}

void MenuText::AdminAdvancedArtworkChoice()
{
	std::cout << "<Виберіть операцію>\n" << std::endl;
	std::cout << "1 - Додати продвинуту картину " << std::endl;
	std::cout << "1 - Оновити продвинуту картину " << std::endl;
	std::cout << "3 - Видалити продвинуту картину " << std::endl;
	std::cout << "0 - Вихід " << std::endl;
	std::cout << "\n=> ";
}

void MenuText::AdminAuthorsChoice()
{
	std::cout << "<Виберіть операцію>\n" << std::endl;
	std::cout << "1 - Додати автора " << std::endl;
	std::cout << "2 - Оновити автора " << std::endl;
	std::cout << "3 - Видалити автора " << std::endl;
	std::cout << "0 - Вихід " << std::endl;
	std::cout << "\n=> ";
}

void MenuText::AdminMaterialsChoice()
{
	std::cout << "<Виберіть операцію>\n" << std::endl;
	std::cout << "1 - Оновити матеріал " << std::endl;
	std::cout << "2 - Видалити матеріал " << std::endl;
	std::cout << "0 - Вихід " << std::endl;
	std::cout << "\n=> ";
}

void MenuText::ChoiceTypeArtworks()
{
	std::cout << "<Виберіть тип картини>\n" << std::endl;
	std::cout << "1 - Звичайна " << std::endl;
	std::cout << "2 - Продвинута " << std::endl;
	std::cout << "0 - Вихід " << std::endl;
	std::cout << "\n=> ";
}

void MenuText::TypeNewValue(int valueCode)
{
	DataInputCyrillicNotSupported();
	switch (valueCode)
	{
	case 1:
		std::cout << "Напишіть нове ім'я -> ";
		break;
	case 2:
		std::cout << "Напишіть нового автора -> ";
		break;
	case 3:
		std::cout << "Напишіть нову дату написання -> ";
		break;
	case 4:
		std::cout << "Напишіть нову історію -> ";
		break;
	case 5:
		std::cout << "Напишіть нові матеріали -> ";
		break;
	case 6:
		std::cout << "Напишіть нову техніку -> ";
		break;
	default:
		std::cout << "Error, invalid valueCode";
		break;
	}
}

void MenuText::TypeNameForDelete()
{
	std::cout << "Напишіть ім'я картини для видалення -> ";
}

void MenuText::ShowListOfAdvancedArtworks(const std::vector<AdvancedArtwork> artworks, bool isNeedBackOption)
{
	if (artworks.size() < 1)
	{
		std::cout << "Продвинуті картини відсутні." << std::endl;
	}

	SetConsoleOutputCP(CP_UTF8);

	for (int i = 1; i < artworks.size() + 1; i++)
	{
		std::cout << i << ". " << artworks[i - 1].Name() << std::endl;
	}

	SetConsoleOutputCP(1251);

	if (isNeedBackOption)
	{
		std::cout << "\n0 - Повернутися назад" << std::endl;
		std::cout << "\n=> ";
	}
}

void MenuText::ShowListOfArtworks(const std::vector<Artwork> artworks, bool isNeedBackOption)
{
	if (artworks.size() < 1)
	{
		std::cout << "Картини відсутні." << std::endl;
	}

	SetConsoleOutputCP(CP_UTF8);

	for (int i = 1; i < artworks.size() + 1; i++)
	{
		std::cout << i << ". " << artworks[i - 1].Name() << std::endl;
	}

	SetConsoleOutputCP(1251);

	if (isNeedBackOption)
	{
		std::cout << "\n0 - Повернутися назад" << std::endl;
		std::cout << "\n=> ";
	}
}

void MenuText::ShowListOfAuthors(const std::vector<Author> author, bool isNeedBackOption)
{
	if (author.size() < 1)
	{
		std::cout << "Автори відсутні." << std::endl;
	}

	SetConsoleOutputCP(CP_UTF8);

	for (int i = 1; i < author.size() + 1; i++)
	{
		std::cout << i << ". " << author[i - 1].Name() << std::endl;
	}

	SetConsoleOutputCP(1251);

	if (isNeedBackOption)
	{
		std::cout << "\n0 - Повернутися назад" << std::endl;
		std::cout << "\n=> ";
	}
}

void MenuText::ShowListOfMaterials(const std::vector<Material> material, bool isNeedBackOption)
{
	if (material.size() < 1)
	{
		std::cout << "Матеріали відсутні." << std::endl;
	}

	SetConsoleOutputCP(CP_UTF8);

	for (int i = 1; i < material.size() + 1; i++)
	{
		std::cout << i << ". " << material[i - 1].Name() << std::endl;
	}

	SetConsoleOutputCP(1251);

	if (isNeedBackOption)
	{
		std::cout << "\n0 - Повернутися назад" << std::endl;
		std::cout << "\n=> ";
	}
}

void MenuText::ShowFullInfoOfArtwork(const Artwork* artwork, std::vector<Author> authors)
{

	std::cout << "Назва - " << artwork->Name() << std::endl;
	std::cout << "Автор - " << GetAuthorBuId(artwork->AuthorId(), authors).Name() << std::endl;

}

void MenuText::ShowFullInfoOfAdvancedArtworks(const AdvancedArtwork* artwork, std::vector<Author> authors)
{
	std::cout << "Назва - " << artwork->Name() << std::endl;
	std::cout << "Автор - " << GetAuthorBuId(artwork->AuthorId(), authors).Name() << std::endl;
	std::cout << "Опис - " << artwork->Description() << std::endl;
}

void MenuText::ShowFullInfoOfAuthor(const Author* author)
{
	std::cout << "Ім'я - " << author->Name() << std::endl;
	std::cout << "Біографія - " << author->Description() << std::endl;
}

void MenuText::ShowArtworkMaterials(Artwork art, bool typeInfo, MaterialsEditor editor)
{
	std::vector<Material> artMat = editor.GetById(art.MaterialsId());
	if (typeInfo == true)
	{
		for (int i = 0; i < artMat.size(); i++)
		{
			std::cout << i << ". " << artMat[i].Name() << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < artMat.size(); i++)
		{
			std::cout << artMat[i].Name() << ", ";
		}
	}
}

void MenuText::ShowAuthorArtworks(Author author, std::vector<Artwork> arts, std::vector<AdvancedArtwork> advArts)
{
	std::cout << "Звичайні картини: " << std::endl;
	for (int i = 0; i < arts.size(); i++)
	{
		if (arts[i].AuthorId() == author.Id())
		{
			std::cout << arts[i].Name() << std::endl;
		}
	}
	std::cout << "\nПродвинуті картини: " << std::endl;
	for (int i = 0; i < advArts.size(); i++)
	{
		if (advArts[i].AuthorId() == author.Id())
		{
			std::cout << advArts[i].Name() << std::endl;
		}
	}
	Indents(1);
}

Artwork MenuText::CreateArtworkForm(std::vector<Author> authors, MaterialsEditor editor)
{
	Artwork* art = new Artwork();

	DataInputCyrillicNotSupported();

	std::cout << "Напишіть назву картини -> ";
	std::string name; std::getline(std::cin, name);

	system("cls");
	while (true)
	{
		if (authors.size() < 1)
		{
			art->AuthorId(0);
			break;
		}

		std::cout << "<Виберіть автор>" << std::endl;
		ShowListOfAuthors(authors, false);
		int index; std::cin >> index;
		std::cin.ignore();

		if (index >= 1 && index <= authors.size())
		{
			art->AuthorId(authors[index - 1].Id());
			break;
		}
	}

	art->Name(name);

	art->MaterialsId(editor.GetFreeId(false));

	return *art;
}

AdvancedArtwork MenuText::CreateAdvancedArtworkForm(std::vector<Author> authors, MaterialsEditor editor)
{
	AdvancedArtwork* art = new AdvancedArtwork();

	DataInputCyrillicNotSupported();

	std::cout << "Напишіть назву продвинутої картини -> ";
	std::string name; std::getline(std::cin, name);

	std::cout << "Напишіть опис продвинутої картини -> ";
	std::string desc; std::getline(std::cin, desc);

	system("cls");
	while (true)
	{
		if (authors.size() < 1)
		{
			art->AuthorId(0);
			break;
		}

		std::cout << "<Виберіть автор>" << std::endl;
		ShowListOfAuthors(authors, false);
		int index; std::cin >> index;
		std::cin.ignore();

		if (index >= 1 && index <= authors.size())
		{
			art->AuthorId(authors[index - 1].Id());
			break;
		}
	}

	art->Name(name);
	art->Description(desc);

	art->MaterialsId(editor.GetFreeId(true));

	return *art;
}

Author MenuText::CreateAuthorForm()
{
	Author* author = new Author();

	DataInputCyrillicNotSupported();

	std::cout << "Напишіть ім'я автора -> ";
	std::string name; std::getline(std::cin, name);

	std::cout << "Напишіть біографію автора -> ";
	std::string desc; std::getline(std::cin, desc);

	author->Name(name);
	author->Description(desc);

	return *author;
}

Author MenuText::GetAuthorBuId(int id, std::vector<Author> authors)
{
	for (int i = 0; i < authors.size(); i++)
	{
		if (authors[i].Id() == id)
			return authors[i];
	}

	Author author; author.Name("Автора немає"); return author;
}