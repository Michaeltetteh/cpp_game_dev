#ifndef ARCHI_ACTIONMAP_HPP
#define ARCHI_ACTIONMAP_HPP

#include <unordered_map>
#include "Action.hpp"

namespace asteroid
{
    template<typename T=int>
    class ActionMap
    {
    public:
        ActionMap(const ActionMap<T> &) = delete;
        ActionMap<T> &operator=(const ActionMap<T>&) = delete;

        ActionMap() = default;
        void map(const T &key,const Action &action);
        const Action &get(const T &key) const;

    private:
        std::unordered_map<T,Action> _map;
    };
}

#include "ActionMap.tpl"

#endif
