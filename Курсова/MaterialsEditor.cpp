#include "MaterialsEditor.h"
#include "AdvancedArtwork.h"


MaterialsEditor::MaterialsEditor(std::vector<Material>& materials)
	: _materials(materials)
{
}

int MaterialsEditor::GetFreeId(bool isAdvancedArtwork)
{
	if (isAdvancedArtwork)
	{
		int freeId = 1;
		while (true)
		{
			bool isThisIdBusy = false;
			for (int i = 0; i < _materials.size(); i++)
			{
				if (_materials[i].Id() == freeId && _materials[i].IsAdvancedArtwork() == isAdvancedArtwork)
				{
					isThisIdBusy = true;
				}
			}
			if (isThisIdBusy)
			{
				freeId++;
			}
			else if (!isThisIdBusy)
			{
				return freeId;
			}
		}
	}
	else if (!isAdvancedArtwork)
	{
		int freeId = 1;
		while (true)
		{
			bool isThisIdBusy = false;
			for (int i = 0; i < _materials.size(); i++)
			{
				if (_materials[i].Id() == freeId && _materials[i].IsAdvancedArtwork() == !isAdvancedArtwork)
				{
					isThisIdBusy = true;
				}
			}
			if (isThisIdBusy)
			{
				freeId++;
			}
			else if (!isThisIdBusy)
			{
				return freeId;
			}
		}
	}
	else
		return -1;
}

std::vector<Material> MaterialsEditor::GetById(int id)
{
	std::vector<Material> materials;

	for (int i = 0; i < _materials.size(); i++)
	{
		if (_materials[i].Id() == id)
			materials.push_back(_materials[i]);
	}
	return materials;
}

bool MaterialsEditor::AddMaterial(Material* material, Artwork* art)
{
	if (art->IsArtwork() == true)
		material->IsAdvancedArtwork(false);
	else if (art->IsArtwork() == false)
		material->IsAdvancedArtwork(true);
	material->Id(art->MaterialsId());

	_materials.push_back(*material);
	return true;
}

bool MaterialsEditor::UpdateFullMaterial(Material* material)
{
	for (int i = 0; i < _materials.size(); i++)
	{
		if (_materials[i].Id() == material->Id())
		{
			_materials[i].Name(material->Name());
			return true;
		}
	}
	return false;
}

bool MaterialsEditor::DeleteByObject(Material* material)
{
	int index = -1;

	for (int i = 0; i < _materials.size(); i++)
	{
		if (_materials[i].Id() == material->Id() &&
			_materials[i].IsAdvancedArtwork() == material->IsAdvancedArtwork() &&
			_materials[i].Name() == material->Name())
			index = i;
	}

	_materials.erase(_materials.begin() + index);
	return true;
}

bool MaterialsEditor::DeleteByIndex(int index)
{
	_materials.erase(_materials.begin() + index);
	return true;
}

bool MaterialsEditor::DeleteByName(const std::string& name)
{
	return false;
}
