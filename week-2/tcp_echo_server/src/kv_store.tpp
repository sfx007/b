#include "../include/kv_store.hpp"


template <typename Key, typename Value>
std::optional<Value> KVStore<Key,Value>::get(const Key& key) const
{
    auto it = kv.find(key);
    if(it == kv.end())
        return std::nullopt;
    return it->second;
}

template <typename Key, typename Value>
void KVStore<Key, Value>::put(const Key& key,const Value& value)
{
    auto it = kv.find(key);
    if(it == kv.end())
        kv.emplace(key, value); 
    else
        it->second = value;
}


template <typename Key, typename Value>
void KVStore<Key, Value>::remove(const Key& key)
{
    kv.erase(key);
}

