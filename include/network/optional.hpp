#pragma once

#if __cplusplus >= 201703L
#include <optional>
namespace network {
    template<typename T> using optional = std::optional<T>;
    constexpr std::nullopt_t nullopt = std::nullopt;
};
#else
#include <boost/optional.hpp>
#include <boost/none.hpp>
namespace network {
    template<typename T> using optional = boost::optional<T>;
    const boost::none_t nullopt ((boost::none_t::init_tag()));
};
#endif

