#include <iostream>
#include <optional>
#include <vector>

#ifndef SPARSE_ARRAY
#define SPARSE_ARRAY

template <typename Component> // You can also mirror the definition of std::vector, that takes an additional allocator.
class sparse_array {
    public:
    using value_type = std::optional<Component>; // optional component type
    using reference_type = value_type &;
    using const_reference_type = const value_type &;
    using container_t = std::vector<value_type>; // optionally add your allocator template here.
    using size_type = typename container_t::size_type;

    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;

    public:
    sparse_array() = default; // You can add more constructors .
    sparse_array(sparse_array const &) = default; // copy constructor
    sparse_array(sparse_array &&) noexcept = default; // move constructor
    ~sparse_array() = default;
    sparse_array & operator=(sparse_array const &) = default;
    
    
     // copy assignment operator
    sparse_array & operator=(sparse_array &&) noexcept = default; // move assignment operator
    reference_type operator[](size_t idx)
    {
        return _data[idx];
    }
    const_reference_type operator[](size_t idx) const
    {
        return _data[idx];
    }
    iterator begin()
    {
        return _data.begin();
    }
    const_iterator begin() const
    {
        return _data.begin();
    }
    const_iterator cbegin() const
    {
        return _data.cbegin();
    }
    iterator end()
    {
        return _data.end();
    }
    const_iterator end() const
    {
        return _data.end();
    }
    const_iterator cend() const
    {
        return _data.cend();
    }
    size_type size() const
    {
        return _data.size();
    }
    reference_type insert_at(size_type pos, Component const &component)
    {
        if (pos > _data.size()) {
            _data.resize(pos);
        }
        _data.insert(_data.begin() + pos, component);
        return _data[pos];
    }
    reference_type insert_at(size_type pos, Component &&component)
    {
        if (pos > _data.size()) {
            _data.resize(pos);
        }
        _data.insert(_data.begin() + pos, component);
        return _data[pos];
    }
    template <class ... Params>
    reference_type emplace_at(size_type pos, Params &&...component) // optional
    {
        _data.emplace(_data.begin() + pos, std::forward<Params>(component)...);
        return _data[pos];
    }
    void erase(size_type pos)
    {
        _data.erase(_data.begin() + pos);
    }
    size_type get_index (value_type const &) const
    {
        for (size_type i = 0; i < _data.size(); i++)
        {
            if (_data[i].has_value()) {
                return i;
            }
        }
        return -1;
    }

    private:
    container_t _data;
};

#endif
