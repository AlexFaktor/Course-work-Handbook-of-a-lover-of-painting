#include "AdvancedArtworkEditor.h"

AdvancedArtworkEditor::AdvancedArtworkEditor(std::vector<AdvancedArtwork>& advancedArtworks)
	: _advancedArtworks(advancedArtworks)
{
}

int AdvancedArtworkEditor::GetFreeId()
{
	int id = 1;
	while (true)
	{
		if (std::find_if(_advancedArtworks.begin(),
			_advancedArtworks.end(),
			[id](const AdvancedArtwork& artwork) { return artwork.Id() == id; }) == _advancedArtworks.end())
		{
			return id;
		}
		++id;
	}
	return -1;
}

AdvancedArtwork AdvancedArtworkEditor::GetById(int id)
{
	for (int i = 0; i < _advancedArtworks.size(); i++)
	{
		if (_advancedArtworks[i].Id() == id)
			return _advancedArtworks[i];
	}
	throw new _exception();
}

bool AdvancedArtworkEditor::AddArtwork(AdvancedArtwork* artwork)
{
	artwork->Id(GetFreeId());
	_advancedArtworks.push_back(*artwork);
	return true;
}

bool AdvancedArtworkEditor::UpdateFullArtwork(AdvancedArtwork* artwork)
{
	for (int i = 0; i < _advancedArtworks.size(); i++)
	{
		if (_advancedArtworks[i].Id() == artwork->Id())
		{
			_advancedArtworks[i].Name(artwork->Name());
			_advancedArtworks[i].AuthorId(artwork->AuthorId());
			_advancedArtworks[i].MaterialsId(artwork->MaterialsId());
			_advancedArtworks[i].Description(artwork->Description());
			return true;
		}
	}
	return false;
}

bool AdvancedArtworkEditor::DeleteByIndex(int index)
{
	_advancedArtworks.erase(_advancedArtworks.begin() + index);
	return true;
}

bool AdvancedArtworkEditor::DeleteByName(const std::string& name)
{
	auto it = std::find_if(_advancedArtworks.begin(), _advancedArtworks.end(), [name](const Artwork& obj) { return obj.Name() == name; });

	if (it != _advancedArtworks.end())
	{
		_advancedArtworks.erase(it);
		return true;
	}
	return false;
}
