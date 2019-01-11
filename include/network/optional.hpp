#pragma once

#if __cplusplus >= 201703L
#include <optional>
namespace network {
    template<typename T> using optional = std::optional<T>;
    inline constexpr nullopt_t nullopt{};
};
#else
#include <boost/optional.hpp>
#include <boost/none.hpp>
namespace network {
    template<typename T> using optional = boost::optional<T>;
    const boost::none_t nullopt ((boost::none_t::init_tag()));
};
#endif

