#ifndef DATA_HEADER_H
#define DATA_HEADER_H

#include <memory>
#include <optional>

//for holding types that are shared
template<typename T>
using ShPtr = std::shared_ptr<T>;

//for holding optional data
template<typename T>
using Optional = std::optional<T>;

#endif
