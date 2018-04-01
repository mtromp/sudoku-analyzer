TEMPLATE = subdirs

SUBDIRS += \
    sudokuLibrary \
    sudokuApplication \
    sudokuTests

sudokuApplication.depends = sudokuLibrary
sudokuTests.depends = sudokuLibrary
