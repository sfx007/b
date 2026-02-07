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

typedef struct clientInfo_s
{
    int fd;
    KVStore<std::string, std::string>* DataBase;
    pthread_mutex_t* locker;
}clientInfo_t;

#include "../src/kv_store.tpp"
#endif