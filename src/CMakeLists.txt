cmake_minimum_required(VERSION 3.10)

project(mediaclient)
find_package(Qt5 COMPONENTS Core Qml Quick REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QML_RESOURCE_FILES "qml.qrc")
qt5_add_resources(QML_RESOURCE_SRCS ${QML_RESOURCE_FILES})
add_executable(mediaclient
	main.cpp
	mediaclient.cpp
    mediaclient.h
	mpvobject.cpp
	mpvobject.h
	mpvrenderer.cpp
	mpvrenderer.h
	entry.cpp
	entry.h
	qthelper.hpp
	${QML_RESOURCE_SRCS})

target_link_libraries(mediaclient PRIVATE Qt5::Core Qt5::Qml Qt5::Quick mpv)

install(TARGETS mediaclient DESTINATION bin)
