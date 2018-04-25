GOOGLETEST_DIR = /Users/Shared/gitrepositories/googletest/
include(gtest_dependency.pri)

QT += testlib
QT += core

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += testcase

HEADERS +=  tst_sudokutestcase.h

SOURCES +=  main.cpp \
    tst_sudokucell.cpp \
    tst_sudokucolumn.cpp

INCLUDEPATH += $$PWD/../sudokuLibrary
LIBS += -L$$OUT_PWD/../sudokuLibrary -lsudokuLibrary

