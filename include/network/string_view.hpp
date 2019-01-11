#pragma once

#if 0 //__cplusplus >= 201703L
namespace network {
#include <string_view>
using string_view = std::string_view;
};
#else
#include <boost/utility/string_view.hpp>
namespace network {
using string_view = boost::string_view; 
};
#endif
namespace network {
std::string to_string(const network::string_view &s) {
    return std::string(s.begin(), s.end());
}
}; //network