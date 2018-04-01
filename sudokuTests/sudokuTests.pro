GOOGLETEST_DIR = /Users/Shared/gitrepositories/googletest/
include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     tst_sudokutestcase.h

SOURCES +=     main.cpp \
    tst_sudokucell.cpp

INCLUDEPATH += $$PWD/../sudokuLibrary
LIBS += -L$$OUT_PWD/../sudokuLibrary -lsudokuLibrary
