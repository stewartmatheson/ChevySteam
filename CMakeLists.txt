cmake_minimum_required(VERSION 3.1)

project(StewCity)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "E:/code/stew-city/deps/SFMLInstall/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(
	StewCity 
	include/CityScape.h
	include/Palatte.h
	include/PixelData.h
	include/PalatteValue.h
	include/SpriteDataRow.h
	include/SpriteLoader.h
	include/Sprite.h
	src/main.cpp 
	src/Palatte.cpp 
	src/PalatteValue.cpp 
	src/SpriteLoader.cpp 
	src/CityScape.cpp 
)

target_include_directories(StewCity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(StewCity sfml-graphics sfml-audio)
