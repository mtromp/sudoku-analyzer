QMAKE_MAC_SDK = macosx10.14
TEMPLATE = subdirs

SUBDIRS += \
    sudokuLibrary \
    sudokuApplication \
    sudokuTests

sudokuApplication.depends = sudokuLibrary
sudokuTests.depends = sudokuLibrary
