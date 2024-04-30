#pragma once

#include "Artwork.h"

#include <vector>
#include <string>

class ArtworkEditor
{
private:
	std::vector<Artwork>& _artworks;
public:
	ArtworkEditor(std::vector<Artwork>& artworks);

	int GetFreeId();

	Artwork GetById(int id);

	bool AddArtwork(Artwork* artwork);

	bool UpdateFullArtwork(Artwork* artwork);

	bool DeleteByIndex(int index);
	bool DeleteByName(const std::string& name);
};

