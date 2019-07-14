macx: GOOGLETEST_DIR = /Users/Shared/gitrepositories/googletest/
unix:!macx: GOOGLETEST_DIR = /usr/src/googletest/

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
    tst_cellcontainermapper.cpp \
    tst_sudokucell.cpp \
    tst_sudokucellcontainer.cpp \
    tst_cellcontainerintegration.cpp

INCLUDEPATH += $$PWD/../sudokuLibrary
LIBS += -L$$OUT_PWD/../sudokuLibrary -lsudokuLibrary

