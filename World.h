#pragma warning(push)
#pragma warning(disable: 26812)
#pragma warning(disable: 6054)
#pragma warning(disable: 6385)
#pragma warning(disable: 4267)
#pragma warning(disable: 4244)
#pragma warning(disable: 4267)

#pragma once
#include <chrono>
#include <filesystem>
#include "collectLogin.h"

#define HOME_TIME (15 * 1000)
#define CONNECT_TIME (100 * 1000)


using namespace chrono;
namespace fs = std::filesystem;
using std::filesystem::directory_iterator;

