TEMPLATE  = app
LANGUAGE  = C++
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG   += console precompile_header
QMAKE_CXXFLAGS += -std=c++0x -pthread
QMAKE_CXXFLAGS_DEBUG += -pg
QMAKE_LFLAGS_DEBUG += -pg
LIBS += -pthread

QMAKE_CXXFLAGS_RELEASE += -ffast-math
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE *= -O3

PRECOMPILED_HEADER = src/pch/pch.h

SOURCES +=  src/kernel/main.cpp src/kernel/command_enum.cpp \
    src/kernel/class_files_data.cpp \
    src/kernel/class_file_tree_node.cpp \
    src/helpers/string_functions.cpp \
    src/kernel/command_interface.cpp \
    src/kernel/dependencies_data.cpp
HEADERS += src/kernel/command_enum.h  src/helpers/enum_helper.h \
    src/kernel/class_files_data.h \
    src/kernel/class_file_tree_node.h \
    src/helpers/string_functions.h \
    src/kernel/command_interface.h \
    src/kernel/dependencies_data.h \
    src/helpers/future_cpp_features.h
