## QSQLCipher-Qt6

This is a Qt6 plugin for [SQLCipher](https://www.zetetic.net/sqlcipher). Since SQLCipher is a drop-in replacement for SQLite, the Qt SQLite driver is
used as the base for this plugin.
The current implementation consists of
  * SQLCipher 4.6.1 (based in SQLite 3.46.1) as amalgamation from https://github.com/chehrlic/sqlcipher-amalgamation
  * libtomcrypt 1.18.2 from https://github.com/libtom/libtomcrypt
  * Qt SQLite plugin for Qt 6.8, modified to compile with Qt 6.6 and sligthly changed so it can be loaded as separate plugin ("QSQLCIPHER")
  
## Compilation and Installation

You will need a Qt installation (e.g. installed through the [Qt Online installer](https://download.qt.io/official_releases/online_installers).
Clone this repository and set up the Qt environment.
  * cd <cloned QSQLCipher directory>
  * mkdir build
  * cd build
  * for MinGW: cmake ..\ -G "MinGW Makefiles"
  * for MSVC: cmake ..\ -G "NMake Makefiles"
  * for Linux: cmake ..\
  * cmake --build .
  * cmake --install .
  
## Use within your Qt programm
Load the QSqlCipher plugin with [QSqlDatabase::addDatabase("QSQLCIPHER")](https://doc.qt.io/qt-6/qsqldatabase.html#addDatabase).
