#ifndef HEADER_HPP
#define HEADER_HPP

#include <unordered_map>
#include <optional>


template <typename Key, typename Value>
class KVStore
{

private:
    std::unordered_map<Key, Value> kv;
public:
    void put(const Key& key, const Value& value);
    std::optional<Value> get(const Key& key) const;
    void remove(const Key& key);
};
#include "../src/header.tpp"


#endif