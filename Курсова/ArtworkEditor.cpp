#include "ArtworkEditor.h"
#include <algorithm>

ArtworkEditor::ArtworkEditor(std::vector<Artwork>& artworks)
	: _artworks(artworks)
{
}

int ArtworkEditor::GetFreeId()
{
	int id = 1;
	while (true)
	{
		if (std::find_if(_artworks.begin(), _artworks.end(), [id](const Artwork& artwork) { return artwork.Id() == id; }) == _artworks.end())
		{
			return id;
		}
		++id;
	}
	return -1;
}

Artwork ArtworkEditor::GetById(int id)
{
	for (int i = 0; i < _artworks.size(); i++)
	{
		if (_artworks[i].Id() == id)
			return _artworks[i];
	}
	throw new _exception();
}

bool ArtworkEditor::AddArtwork(Artwork* artwork)
{
	artwork->Id(GetFreeId());
	_artworks.push_back(*artwork);
	return true;
}

bool ArtworkEditor::UpdateFullArtwork(Artwork* artwork)
{
	for (int i = 0; i < _artworks.size(); i++)
	{
		if (_artworks[i].Id() == artwork->Id())
		{
			_artworks[i].Name(artwork->Name());
			_artworks[i].AuthorId(artwork->AuthorId());
			_artworks[i].MaterialsId(artwork->MaterialsId());
			return true;
		}
	}
	return false;
}

bool ArtworkEditor::DeleteByIndex(int index)
{
	_artworks.erase(_artworks.begin() + index);
	return true;
}

bool ArtworkEditor::DeleteByName(const std::string& name)
{
	auto it = std::find_if(_artworks.begin(), _artworks.end(), [name](const Artwork& obj) { return obj.Name() == name; });

	if (it != _artworks.end())
	{
		_artworks.erase(it);
		return true;
	}
	return false;
}
