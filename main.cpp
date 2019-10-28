#include <iostream>
#include <tuple>
#include <optional>

#include "tarantool.h"

using namespace std::string_view_literals;

struct S {
    int type; // Remove it to remove error
    bool hidden = false;
};

tarantool::SmartTntOStream &operator<<(tarantool::SmartTntOStream &stream, const S &res) {
    tarantool::Map::ConstMap map(
        // False positive cast from bool to template class bool
        tarantool::Map::Element("hidden"sv, res.hidden)
    );
    return stream << map;
}
