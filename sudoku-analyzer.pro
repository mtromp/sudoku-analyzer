TEMPLATE = subdirs

SUBDIRS += \
    sudokuLibrary \
    sudokuApplication \
    sudokuTests

GOOGLETEST_DIR=/Users/Shared/gitrepositories/googletest

sudokuApplication.depends = sudokuLibrary
sudokuTests.depends = sudokuLibrary

