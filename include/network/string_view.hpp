#pragma once

#if __cplusplus >= 201703L
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