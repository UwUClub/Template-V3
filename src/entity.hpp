//
// Created by beafowl on 27/06/23.
//

#include <cstddef>

#ifndef ENTITY_HPP
#define ENTITY_HPP

class entity
{
    public:
        size_t _id;
        explicit entity(size_t aId);

        [[nodiscard]] size_t getId() const;
        operator std::size_t() const { return _id; }
};

#endif // ENTITY_HPP
