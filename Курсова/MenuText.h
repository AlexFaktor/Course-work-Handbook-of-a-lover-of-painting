#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "Artwork.h"
#include "Author.h"
#include "AdvancedArtwork.h"
#include "Material.h"

#include "MaterialsEditor.h"

class MenuText
{
private:

public:
	void static SetEncoding1251();
	void static SetEncodingUTF_8();

	void static Indents(int);

	void static InvalidInput(const std::string);
	void static TheOperationIsSuccessful();
	void static TheOperationIsFailed();
	void static DataInputCyrillicNotSupported();
	void static ProgramEnd();

	void static WaitForUser();

	void static RoleChoice();
	void static ViewerChoice();
	void static AdminChoice();

	void static ViewAuthorChoice();
	void static AdminArtworksChoice();
	void static AdminAdvancedArtworkChoice();
	void static AdminAuthorsChoice();
	void static AdminMaterialsChoice();
	void static ChoiceTypeArtworks();

	void static TypeNewValue(int);
	void static TypeNameForDelete();

	void static ShowListOfAdvancedArtworks(const std::vector<AdvancedArtwork> artworks, bool isNeedBackOption);
	void static ShowListOfArtworks(const std::vector<Artwork> artworks, bool isNeedBackOption);
	void static ShowListOfAuthors(const std::vector<Author> author, bool isNeedBackOption);
	void static ShowListOfMaterials(const std::vector<Material> material, bool isNeedBackOption);

	void static ShowFullInfoOfArtwork(const Artwork* artwork, std::vector<Author> authors);
	void static ShowFullInfoOfAdvancedArtworks(const AdvancedArtwork* artwork, std::vector<Author> authors);
	void static ShowFullInfoOfAuthor(const Author* author);

	void static ShowArtworkMaterials(Artwork art, bool typeInfo, MaterialsEditor editor);

	void static ShowAuthorArtworks(Author author, std::vector<Artwork> arts, std::vector<AdvancedArtwork> advArts);

	Artwork static CreateArtworkForm(std::vector<Author>, MaterialsEditor editor);
	AdvancedArtwork static CreateAdvancedArtworkForm(std::vector<Author>, MaterialsEditor editor);
	Author static CreateAuthorForm();

	Author static GetAuthorBuId(int id, std::vector<Author> authors);
};

