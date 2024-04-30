#pragma once

#include <string>
#include "Artwork.h"

class AdvancedArtwork : public Artwork
{
private:
	std::string _description;

public:

	const std::string& Description() const { return _description; }

	void Description(const std::string& description);

	bool IsArtwork() { return false; }
};

