#include "entity.hpp"

entity::entity(size_t aId) : _id(aId)
{
}

size_t entity::getId() const
{
    return _id;
}
