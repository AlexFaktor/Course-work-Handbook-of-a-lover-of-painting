#pragma once

#include "AdvancedArtwork.h"

#include <vector>
#include <string>

class AdvancedArtworkEditor
{
private:
	std::vector<AdvancedArtwork>& _advancedArtworks;
public:
	AdvancedArtworkEditor(std::vector<AdvancedArtwork>& advancedArtworks);

	int GetFreeId();

	AdvancedArtwork GetById(int id);

	bool AddArtwork(AdvancedArtwork* artwork);

	bool UpdateFullArtwork(AdvancedArtwork* artwork);

	bool DeleteByIndex(int index);
	bool DeleteByName(const std::string& name);
};

