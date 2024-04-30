#pragma once

#include "Material.h"
#include "Artwork.h"

#include <vector>
#include <string>

class MaterialsEditor
{
private:
	std::vector<Material>& _materials;
public:
	MaterialsEditor(std::vector<Material>& materials);

	int GetFreeId(bool isAdvancedArtwork);

	std::vector<Material> GetById(int id); // ������� ��� ��� ���� ��������� �� ��� � �� ��������

	bool AddMaterial(Material* material, Artwork* art);

	bool UpdateFullMaterial(Material* material);

	bool DeleteByObject(Material* material);
	bool DeleteByIndex(int index);
	bool DeleteByName(const std::string& name);
};

