#ifndef KV
#define KV

#include <unordered_map>
#include <string>
#include <optional>


template <typename Key, typename Value>

class KVStore
{
private:
    std::unordered_map<Key,Value> kv;
public:
    std::optional<Value> get(const Key& key) const;
    void    put(const Key& key,const Value& value);
    void    remove(const Key& key);

};



#endif