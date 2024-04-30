#include "Artwork.h"

Artwork::Artwork()
{
}

void Artwork::Name(const std::string& name)
{
	_name = name;
}

void Artwork::AuthorId(int authorId)
{
	_authorId = authorId;
}

void Artwork::MaterialsId(int materialsId)
{
	_materialsId = materialsId;
}
