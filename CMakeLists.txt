cmake_minimum_required(VERSION 3.20)
project(QSqlCipher)
message(STATUS "Building QSqlCipher plugin for Qt (SqlCipher version 4.6.0 based on SQLite 3.45.3)")
find_package(Qt6 REQUIRED COMPONENTS Core Sql)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
# All source files are copied from official Qt6 qsqlite plugin directory
# smain.cpp and sqlite.json are modified to use QSqlCipherDriverPlugin class instead QSQLiteDriverPlugin
# and QSQLCIPHER plugin key instead QSQLITE
# sqlite3.c is taken from sqlcipher amalgamation
include(CheckFunctionExists)
check_function_exists(fallocate HAVE_POSIX_FALLOCATE)
check_function_exists(usleep    HAVE_USLEEP)

qt_add_plugin(QSqlCipherDriverPlugin
    OUTPUT_NAME qsqlcipher
    PLUGIN_TYPE sqldrivers
    SHARED
        qsql_sqlite.cpp
        qsql_sqlite_p.h
        qsql_sqlite_vfs.cpp
        qsql_sqlite_vfs_p.h
        smain.cpp
        3rdparty/sqlcipher/sqlite3.c
)
target_compile_definitions(QSqlCipherDriverPlugin
    PRIVATE
        SQLITE_ENABLE_COLUMN_METADATA
        SQLITE_ENABLE_FTS3
        SQLITE_ENABLE_FTS3_PARENTHESIS
        SQLITE_ENABLE_FTS4
        SQLITE_ENABLE_FTS5
        SQLITE_ENABLE_GEOPOLY
        SQLITE_ENABLE_JSON1
        SQLITE_ENABLE_MATH_FUNCTIONS
        SQLITE_ENABLE_RTREE
        SQLITE_OMIT_COMPLETE

        QT_NO_CAST_FROM_ASCII
        QT_NO_CAST_TO_ASCII
        QT_NO_CONTEXTLESS_CONNECT
        QT_NO_FOREACH
        QT_NO_JAVA_STYLE_ITERATORS
        QT_USE_QSTRINGBUILDER

        $<$<BOOL:HAVE_POSIX_FALLOCATE>:HAVE_POSIX_FALLOCATE>
        $<$<BOOL:HAVE_USLEEP>:HAVE_USLEEP>
        $<$<CONFIG:Release>:NDEBUG>
)
target_link_libraries(QSqlCipherDriverPlugin
    PRIVATE
        Qt::Core
        Qt::SqlPrivate
)
target_include_directories(QSqlCipherDriverPlugin
    PRIVATE
        3rdparty/sqlcipher
)
