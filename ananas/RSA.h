#pragma once
#include <vector>
#include "boost/multiprecision/cpp_int.hpp"
#include "Windows.h"

std::vector<boost::multiprecision::uint1024_t> createKeys();
std::string decrypt(std::string message, boost::multiprecision::uint1024_t d, boost::multiprecision::uint1024_t n);
std::string encrypt(std::string message, boost::multiprecision::uint1024_t e, boost::multiprecision::uint1024_t n);