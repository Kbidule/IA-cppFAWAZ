cmake_minimum_required(VERSION 3.29)
project(PokemonCPP)
# Specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# For MacOS, we might need to specify the pkg-config path
set(ENV{PKG_CONFIG_PATH} "/opt/homebrew/lib/pkgconfig:/usr/local/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}")

# Find GTK3 package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Include directories
include_directories(${GTK3_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/headers)


add_executable(PokemonCPP main.cpp
        headers/card.h
        headers/pokemon_card.h
        headers/energy_card.h
        headers/trainer_card.h
        headers/player.h
        Card/Card.cpp
        Card/EnergyCard.cpp
        Card/pokemon_card.cpp
        Card/player.cpp
        Card/trainer_Card.cpp
)

# Link against GTK3 libraries
target_link_libraries(PokemonCPP ${GTK3_LIBRARIES})

# MacOS specific settings
if(APPLE)
    target_link_directories(PokemonCPP PRIVATE /opt/homebrew/lib)
    target_include_directories(PokemonCPP PRIVATE /opt/homebrew/include)
endif()