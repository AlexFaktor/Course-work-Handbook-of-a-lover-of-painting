#include "DatabaseObject.h"

DatabaseObject::DatabaseObject()
{
	_id = -1;
}

void DatabaseObject::Id(int id)
{
	_id = id;
}