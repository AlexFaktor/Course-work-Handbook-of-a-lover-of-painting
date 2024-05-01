#pragma once

#include "Material.h"
#include "Artwork.h"
#include "AdvancedArtwork.h"

#include <vector>
#include <string>

class MaterialsEditor
{
private:
	std::vector<Material>& _materials;
public:
	MaterialsEditor(std::vector<Material>& materials);

	int GetMaterialFreeId(bool isAdvancedArtwork, std::vector<Artwork> artworks, std::vector<AdvancedArtwork> advanceds);

	std::vector<Material*> GetById(int id, bool isAdvancedArtwork); // Важливо щоб тут були посилання на одні і тіж матеріали

	bool AddMaterial(Material* material, Artwork* art);

	bool UpdateFullMaterial(Material* material);

	bool DeleteByObject(Material* material);
	bool DeleteByIndex(int index);
	bool DeleteByName(const std::string& name);
};

