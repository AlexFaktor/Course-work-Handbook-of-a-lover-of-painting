#include "Database.h"

#include "AdvancedArtwork.h"
#include "Artwork.h"
#include "Author.h"
#include "Material.h"

#include "MenuText.h"

#include <iostream>
#include <vector>
#include <Windows.h> 
#include <conio.h>

#include "AdvancedArtworkEditor.h"
#include "ArtworkEditor.h"
#include "AuthorEditor.h"
#include "MaterialsEditor.h"

class Program
{
private:
    Database* _database;

    std::vector<AdvancedArtwork> _advancedArtworks;
    std::vector<Artwork> _artworks;
    std::vector<Author> _authors;
    std::vector<Material> _materials;

    AdvancedArtworkEditor* _editorAdvancedArtworks;
    ArtworkEditor* _editorArtworks;
    AuthorEditor* _editorAuthors;
    MaterialsEditor* _editorMaterials;

public:
    Program(std::string path)
    {
        _database = new Database(path);

        _advancedArtworks = _database->LoadAdvancedArtwork();
        _artworks = _database->LoadArtwork();
        _authors = _database->LoadAuthor();
        _materials = _database->LoadMaterial();

        _editorAdvancedArtworks = new AdvancedArtworkEditor(_advancedArtworks);
        _editorArtworks = new ArtworkEditor(_artworks);
        _editorAuthors = new AuthorEditor(_authors);
        _editorMaterials = new MaterialsEditor(_materials);
    }

    void Start()
    {
        ChoiceRole();

        _database->Save(_advancedArtworks);
        _database->Save(_artworks);
        _database->Save(_authors);
        _database->Save(_materials);

        MenuText::ProgramEnd();
    }

    void ChoiceRole()
    {
        while (true)
        {
            system("cls");
            MenuText::RoleChoice();
            std::string choice; std::getline(std::cin, choice);
            if (choice == "0")
            {
                break;
            }
            else if (choice == "1")
            {
                Viewer();
            }
            else if (choice == "2")
            {
                Admin();
            }
            else
            {
                system("cls");
                MenuText::InvalidInput(choice);
            }
        }
    }

    void Viewer()
    {
        while (true)
        {
            system("cls");
            MenuText::ViewerChoice();
            std::string choice; std::getline(std::cin, choice);
            if (choice == "0")
            {
                break;
            }
            else if (choice == "1")
            {
                ListArtwork();
            }
            else if (choice == "2")
            {
                ListAdvancedArtwork();
            }
            else if (choice == "3")
            {
                ListAuthor();
            }
            else
            {
                system("cls");
                MenuText::InvalidInput(choice);
            }
        }
    }

    void ListArtwork()
    {
        while (true)
        {
            system("cls");
            MenuText::ShowListOfArtworks(_artworks, true);
            int index; std::cin >> index;
            std::cin.ignore();
            if (index == 0) // Go back
            {
                system("cls");
                break;
            }
            else if (index >= 1 && index <= _artworks.size()) // Choosing a picture
            {
                system("cls");
                MenuText::ShowFullInfoOfArtwork(&_artworks[index - 1], _authors, *_editorMaterials);
                MenuText::WaitForUser();
                system("cls");
            }
            else // Unknown choice
            {
                system("cls");
                MenuText::InvalidInput(std::to_string(index - 1));
            }
        }
    }

    void ListAdvancedArtwork()
    {
        system("cls");
        while (true)
        {
            MenuText::ShowListOfAdvancedArtworks(_advancedArtworks, true);
            int index; std::cin >> index; std::cin.ignore();
            if (index == 0) // Go back
            {
                system("cls");
                break;
            }
            else if (index >= 1 && index <= _advancedArtworks.size()) // Choosing a picture
            {
                system("cls");
                MenuText::ShowFullInfoOfAdvancedArtworks(&_advancedArtworks[index - 1], _authors, *_editorMaterials);
                MenuText::WaitForUser();
                system("cls");
            }
            else // Unknown choice
            {
                system("cls");
                MenuText::InvalidInput(std::to_string(index - 1));
            }
        }
    }

    void ListAuthor()
    {
        system("cls");
        while (true)
        {
            MenuText::ShowListOfAuthors(_authors, true);
            int index; std::cin >> index;
            std::cin.ignore();
            if (index == 0) // Go back
            {
                system("cls");
                break;
            }
            else if (index >= 1 && index <= _authors.size()) // Choosing a picture
            {
                while (true)
                {
                    system("cls");
                    MenuText::ViewAuthorChoice();
                    std::string choiceAuthor; std::getline(std::cin, choiceAuthor);

                    if (choiceAuthor == "1") // Full info
                    {
                        system("cls");
                        MenuText::ShowFullInfoOfAuthor(&_authors[index - 1]);
                        MenuText::WaitForUser();
                        system("cls");
                    }
                    else if (choiceAuthor == "2")
                    {
                        system("cls");
                        MenuText::ShowAuthorArtworks(_authors[index - 1], _artworks, _advancedArtworks);
                        MenuText::WaitForUser();
                        system("cls");
                    }
                    else if (choiceAuthor == "0") // Go back
                    {
                        system("cls");
                        break;
                    }
                    else// Unknown choice
                    {
                        system("cls");
                        MenuText::InvalidInput(choiceAuthor);
                    }
                }
            }
            else // Unknown choice
            {
                system("cls");
                MenuText::InvalidInput(std::to_string(index - 1));
            }
        }
    }

    void Admin()
    {
        while (true)
        {
            system("cls");
            MenuText::AdminChoice();
            std::string choice; std::getline(std::cin, choice);
            if (choice == "0")
            {
                break;
            }
            else if (choice == "1")
            {
                MenuArtwork();
            }
            else if (choice == "2")
            {
                MenuAdvancedArtwork();
            }
            else if (choice == "3")
            {
                MenuAuthor();
            }
            else
            {
                system("cls");
                MenuText::InvalidInput(choice);
            }
        }
    }

    void MenuArtwork()
    {
        while (true)
        {
            system("cls");
            MenuText::AdminChoiceArtwork();
            std::string choice; std::getline(std::cin, choice);
            if (choice == "0")
            {
                break;
            }
            else if (choice == "1")
            {
                OperaionAddArtwork();
            }
            else if (choice == "2")
            {
                MenuUpdateArtwork();
            }
            else if (choice == "3")
            {
                OperaionDeleteArtwork();
            }
            else
            {
                system("cls");
                MenuText::InvalidInput(choice);
            }
        }
    }

    void OperaionAddArtwork()
    {
        system("cls");
        Artwork art = MenuText::CreateArtworkForm(_authors, *_editorMaterials, _advancedArtworks, _artworks);
        _editorArtworks->AddArtwork(&art);
        _database->Save(_artworks);
        MenuText::TheOperationIsSuccessful();
        MenuText::WaitForUser();
    }

    void MenuUpdateArtwork()
    {
        while (true)
        {
            system("cls");
            MenuText::ShowListOfArtworks(_artworks, true);
            int index; std::cin >> index;
            if (index == 0)
            {
                system("cls");
                break;
            }
            else if (index >= 1 && index <= _artworks.size())
            {
                MenuUpdateArtworkChoice(index - 1);
            }
            else // Unknown choice
            {
                system("cls");
                MenuText::InvalidInput(std::to_string(index - 1));
            }
        }
    }

    void MenuUpdateArtworkChoice(int index)
    {
        while (true)
        {
            system("cls");
            MenuText::ShowFullInfoOfArtwork(&_artworks[index], _authors, *_editorMaterials);
            MenuText::AdminChoiceArtworkUpdate();
            std::string choice; std::getline(std::cin, choice);
            if (choice == "0")
            {
                system("cls");
                break;
            }
            else if (choice == "1")
            {
                system("cls");
                std::cout << "Введіть нову назву: " << std::endl;
                std::string name; std::getline(std::cin, name);
                _artworks[index].Name(name);
                _database->Save(_artworks);
                MenuText::TheOperationIsSuccessful();
                MenuText::WaitForUser();
                break;
            }
            else if (choice == "2")
            {
                while (true)
                {
                    system("cls");
                    MenuText::ShowListOfAuthors(_authors, true);
                    int indexAuthor; std::cin >> indexAuthor;
                    if (indexAuthor == 0)
                    {
                        system("cls");
                        break;
                    }
                    else if (indexAuthor >= 1 && indexAuthor <= _authors.size())
                    {
                        _artworks[index].AuthorId(_authors[indexAuthor -1].Id());
                        _database->Save(_artworks);
                        MenuText::TheOperationIsSuccessful();
                        MenuText::WaitForUser();
                        break;
                    }
                    else // Unknown choice
                    {
                        system("cls");
                        MenuText::InvalidInput(std::to_string(index - 1));
                    }
                }
            }
            else if (choice == "3")
            {
                system("cls");
                std::cout << "Введіть назву матеріалу -> ";
                std::string nameMaterial; std::getline(std::cin, nameMaterial);
                Material* material = new Material();
                material->Name(nameMaterial);

                _editorMaterials->AddMaterial(material, &_artworks[index]);
                _database->Save(_materials);

                MenuText::TheOperationIsSuccessful();
                MenuText::WaitForUser();
                break;
            }
            else if (choice == "4")
            {
                system("cls");
                std::vector<Material*> artMaterials = _editorMaterials->GetById(_artworks[index].Id(), !_artworks[index].IsArtwork());
                MenuText::ShowArtworkMaterials(_artworks[index], true, *_editorMaterials);
                int indexMater; std::cin >> indexMater; std::cin.ignore();
                if (indexMater == 0)
                {
                    system("cls");
                    break;
                }
                else if (indexMater >= 1 && indexMater <= artMaterials.size())
                {
                    system("cls");
                    std::cout << "Введіть назву матеріалу -> ";
                    std::string nameMaterial; std::getline(std::cin, nameMaterial);
                    artMaterials[indexMater-1]->Name(nameMaterial);
                    MenuText::TheOperationIsSuccessful();
                    MenuText::WaitForUser();
                    break;
                }
                else
                {
                    system("cls");
                    MenuText::InvalidInput(std::to_string(indexMater - 1));
                }
            }
            else if (choice == "5")
            {
                system("cls");
                std::vector<Material*> artMaterials = _editorMaterials->GetById(_artworks[index].Id(), !_artworks[index].IsArtwork());
                MenuText::ShowArtworkMaterials(_artworks[index], true, *_editorMaterials);
                int indexMater; std::cin >> indexMater;
                if (indexMater == 0)
                {
                    system("cls");
                    break;
                }
                else if (indexMater >= 1 && indexMater <= artMaterials.size())
                {
                    system("cls");
                    _editorMaterials->DeleteByObject(artMaterials[indexMater-1]);
                    MenuText::TheOperationIsSuccessful();
                    MenuText::WaitForUser();
                    break;
                }
                else
                {
                    system("cls");
                    MenuText::InvalidInput(std::to_string(indexMater - 1));
                }
            }
            else // Unknown choice
            {
                system("cls");
                MenuText::InvalidInput(std::to_string(index - 1));
            }
        }
    }

    void OperaionDeleteArtwork()
    {
        system("cls");
        while (true)
        {
            MenuText::ShowListOfArtworks(_artworks, true);
            int index; std::cin >> index;
            std::cin.ignore();
            if (index == 0) // Go back
            {
                system("cls");
                break;
            }
            else if (index >= 1 && index <= _artworks.size()) // Select a picture
            {
                if (_editorArtworks->DeleteByIndex(index - 1))
                    MenuText::TheOperationIsSuccessful();
                else
                    MenuText::TheOperationIsFailed();
                MenuText::WaitForUser();
                system("cls");
                _database->Save(_artworks);
            }
            else // Unknown choice
            {
                system("cls");
                MenuText::InvalidInput(std::to_string(index - 1));
            }
            system("cls");
        }
    }

    void MenuAdvancedArtwork()
    {
        while (true)
        {
            system("cls");
            MenuText::AdminChoiceAdvancedArtwork();
            std::string choice; std::getline(std::cin, choice);
            if (choice == "0")
            {
                break;
            }
            else if (choice == "1")
            {
                OperaionAddAdvancedArtwork();
            }
            else if (choice == "2")
            {
                MenuUpdateAdvancedArtwork();
            }
            else if (choice == "3")
            {
                OperaionDeleteAdvancedArtwork();
            }
            else
            {
                system("cls");
                MenuText::InvalidInput(choice);
            }
        }
    }

    void OperaionAddAdvancedArtwork()
    {
        system("cls");
        AdvancedArtwork art = MenuText::CreateAdvancedArtworkForm(_authors, *_editorMaterials, _advancedArtworks, _artworks);
        _editorAdvancedArtworks->AddArtwork(&art);
        _database->Save(_advancedArtworks);
        MenuText::TheOperationIsSuccessful();
        MenuText::WaitForUser();
    }

    void MenuUpdateAdvancedArtwork()
    {
        while (true)
        {
            system("cls");
            MenuText::ShowListOfAdvancedArtworks(_advancedArtworks, true);
            int index; std::cin >> index;
            if (index == 0)
            {
                system("cls");
                break;
            }
            else if (index >= 1 && index <= _advancedArtworks.size())
            {
                MenuUpdateAdvancedArtworkChoice(index - 1);
            }
            else // Unknown choice
            {
                system("cls");
                MenuText::InvalidInput(std::to_string(index - 1));
            }
        }
    }

    void MenuUpdateAdvancedArtworkChoice(int index)
    {
        while (true)
        {
            system("cls");
            MenuText::ShowFullInfoOfAdvancedArtworks(&_advancedArtworks[index], _authors, *_editorMaterials);
            MenuText::AdminChoiceAdvancedArtworkUpdate();
            std::string choice; std::getline(std::cin, choice);
            if (choice == "0")
            {
                system("cls");
                break;
            }
            else if (choice == "1")
            {
                system("cls");
                std::cout << "Введіть нову назву: " << std::endl;
                std::string name; std::getline(std::cin, name);
                _advancedArtworks[index].Name(name);
                _database->Save(_artworks);
                MenuText::TheOperationIsSuccessful();
                MenuText::WaitForUser();
                break;
            }
            else if (choice == "2")
            {
                while (true)
                {
                    system("cls");
                    MenuText::ShowListOfAuthors(_authors, true);
                    int indexAuthor; std::cin >> indexAuthor;
                    if (indexAuthor == 0)
                    {
                        system("cls");
                        break;
                    }
                    else if (indexAuthor >= 1 && indexAuthor <= _authors.size())
                    {
                        _advancedArtworks[index].AuthorId(_authors[indexAuthor - 1].Id());
                        _database->Save(_advancedArtworks);
                        MenuText::TheOperationIsSuccessful();
                        MenuText::WaitForUser();
                        break;
                    }
                    else // Unknown choice
                    {
                        system("cls");
                        MenuText::InvalidInput(std::to_string(index - 1));
                    }
                }
            }
            else if (choice == "3")
            {
                system("cls");
                std::cout << "Введіть назву матеріалу -> ";
                std::string nameMaterial; std::getline(std::cin, nameMaterial);
                Material* material = new Material();
                material->Name(nameMaterial);

                _editorMaterials->AddMaterial(material, &_advancedArtworks[index]);
                _database->Save(_materials);

                MenuText::TheOperationIsSuccessful();
                MenuText::WaitForUser();
                break;
            }
            else if (choice == "4")
            {
                system("cls");
                std::vector<Material*> artMaterials = _editorMaterials->GetById(_advancedArtworks[index].Id(), !_advancedArtworks[index].IsArtwork());
                MenuText::ShowArtworkMaterials(_advancedArtworks[index], true, *_editorMaterials);
                int indexMater; std::cin >> indexMater; std::cin.ignore();
                if (indexMater == 0)
                {
                    system("cls");
                    break;
                }
                else if (indexMater >= 1 && indexMater <= artMaterials.size())
                {
                    system("cls");
                    std::cout << "Введіть назву матеріалу -> ";
                    std::string nameMaterial; std::getline(std::cin, nameMaterial);
                    artMaterials[indexMater - 1]->Name(nameMaterial);
                    MenuText::TheOperationIsSuccessful();
                    MenuText::WaitForUser();
                    break;
                }
                else
                {
                    system("cls");
                    MenuText::InvalidInput(std::to_string(indexMater - 1));
                }
            }
            else if (choice == "5")
            {
                system("cls");
                std::vector<Material*> artMaterials = _editorMaterials->GetById(_advancedArtworks[index].Id(), !_advancedArtworks[index].IsArtwork());
                MenuText::ShowArtworkMaterials(_advancedArtworks[index], true, *_editorMaterials);
                int indexMater; std::cin >> indexMater;
                if (indexMater == 0)
                {
                    system("cls");
                    break;
                }
                else if (indexMater >= 1 && indexMater <= artMaterials.size())
                {
                    system("cls");
                    _editorMaterials->DeleteByObject(artMaterials[indexMater - 1]);
                    MenuText::TheOperationIsSuccessful();
                    MenuText::WaitForUser();
                    break;
                }
                else
                {
                    system("cls");
                    MenuText::InvalidInput(std::to_string(indexMater - 1));
                }
            }
            else if (choice == "6")
            {
                system("cls");
                std::cout << "Введіть новий опис: " << std::endl;
                std::string desc; std::getline(std::cin, desc);
                _advancedArtworks[index].Description(desc);
                _database->Save(_advancedArtworks);
                MenuText::TheOperationIsSuccessful();
                MenuText::WaitForUser();
                break;
            }
            else // Unknown choice
            {
                system("cls");
                MenuText::InvalidInput(std::to_string(index - 1));
            }
        }
    }

    void OperaionDeleteAdvancedArtwork()
    {
        system("cls");
        while (true)
        {
            MenuText::ShowListOfAdvancedArtworks(_advancedArtworks, true);
            int index; std::cin >> index;
            std::cin.ignore();
            if (index == 0) // Go back
            {
                system("cls");
                break;
            }
            else if (index >= 1 && index <= _advancedArtworks.size()) // Select a picture
            {
                if (_editorAdvancedArtworks->DeleteByIndex(index - 1))
                    MenuText::TheOperationIsSuccessful();
                else
                    MenuText::TheOperationIsFailed();
                MenuText::WaitForUser();
                system("cls");
                _database->Save(_advancedArtworks);
            }
            else // Unknown choice
            {
                system("cls");
                MenuText::InvalidInput(std::to_string(index - 1));
            }
            system("cls");
        }
    }

    void MenuAuthor()
    {
        while (true)
        {
            system("cls");
            MenuText::AdminChoiceAuthor();
            std::string choice; std::getline(std::cin, choice);
            if (choice == "0")
            {
                break;
            }
            else if (choice == "1")
            {
                OperaionAddAuthor();
            }
            else if (choice == "2")
            {
                MenuUpdateAuthor();
            }
            else if (choice == "3")
            {
                OperaionDeleteAuthor();
            }
            else
            {
                system("cls");
                MenuText::InvalidInput(choice);
            }
        }
    }

    void OperaionAddAuthor()
    {
        system("cls");
        Author authr = MenuText::CreateAuthorForm();
        _editorAuthors->AddAuthor(&authr);
        _database->Save(_authors);
        MenuText::TheOperationIsSuccessful();
        MenuText::WaitForUser();
    }

    void MenuUpdateAuthor()
    {
        while (true)
        {
            system("cls");
            MenuText::ShowListOfAuthors(_authors, true);
            int index; std::cin >> index;
            if (index == 0)
            {
                system("cls");
                break;
            }
            else if (index >= 1 && index <= _authors.size())
            {
                MenuUpdateAuthorChoice(index - 1);
            }
            else // Unknown choice
            {
                system("cls");
                MenuText::InvalidInput(std::to_string(index - 1));
            }
        }
    }

    void MenuUpdateAuthorChoice(int index)
    {
        while (true)
        {
            system("cls");
            MenuText::ShowFullInfoOfAuthor(&_authors[index]);
            MenuText::AdminChoiceAuthorUpdate();
            std::string choice; std::getline(std::cin, choice);
            if (choice == "0")
            {
                system("cls");
                break;
            }
            else if (choice == "1")
            {
                system("cls");
                std::cout << "Введіть нове імя: " << std::endl;
                std::string name; std::getline(std::cin, name);
                _authors[index].Name(name);
                _database->Save(_authors);
                MenuText::TheOperationIsSuccessful();
                MenuText::WaitForUser();
            }
            else if (choice == "2")
            {
                system("cls");
                std::cout << "Введіть нову біографію: " << std::endl;
                std::string desc; std::getline(std::cin, desc);
                _authors[index].Description(desc);
                _database->Save(_authors);
                MenuText::TheOperationIsSuccessful();
                MenuText::WaitForUser();
            }
            else // Unknown choice
            {
                system("cls");
                MenuText::InvalidInput(choice);
            }
        }
    }

    void OperaionDeleteAuthor()
    {
        while (true)
        {
            system("cls");
            MenuText::ShowListOfAuthors(_authors, true);
            int index; std::cin >> index;
            std::cin.ignore();
            if (index == 0) // Go back
            {
                system("cls");
                break;
            }
            else if (index >= 1 && index <= _authors.size()) // Select a picture
            {
                if (_editorAuthors->DeleteByIndex(index - 1))
                    MenuText::TheOperationIsSuccessful();
                else
                    MenuText::TheOperationIsFailed();
                MenuText::WaitForUser(); _getch();
                system("cls");
                _database->Save(_authors);
            }
            else // Unknown choice
            {
                system("cls");
                MenuText::InvalidInput(std::to_string(index - 1));
            }
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Program* program = new Program("D:\\.ArtworkDB");

    program->Start();
}