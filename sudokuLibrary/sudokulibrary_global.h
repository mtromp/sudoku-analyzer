#ifndef SUDOKULIBRARY_GLOBAL_H
#define SUDOKULIBRARY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SUDOKULIBRARY_LIBRARY)
#  define SUDOKULIBRARYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SUDOKULIBRARYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SUDOKULIBRARY_GLOBAL_H