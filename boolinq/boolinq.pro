# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = boolinq
DESTDIR = ../Debug
CONFIG += debug console
DEFINES += _CONSOLE
INCLUDEPATH += . \
    ../gmock \
    ../gmock/include \
    ../gmock/gtest \
    ../gmock/gtest/include
LIBS += -L"."
DEPENDPATH += .
OBJECTS_DIR += debug
QMAKE_CXXFLAGS += -std=c++0x
HEADERS += ./boolinq.h \
    ./SkipRange.h \
    ./TakeRange.h \
    ./ConcatRange.h \
    ./DistinctRange.h \
    ./GroupByRange.h \
    ./OrderByRange.h \
    ./IterRange.h \
    ./ReverseRange.h \
    ./SelectRange.h \
    ./WhereRange.h \
    ./ToSet.h \
    ./ToContainer.h \
    ./ToDeque.h \
    ./ToList.h \
    ./ToVector.h \
    ./All.h \
    ./Any.h \
    ./Avg.h \
    ./Contains.h \
    ./ElementAt.h \
    ./ForEach.h \
    ./Max.h \
    ./Min.h \
    ./Sum.h \
    ./Count.h \
    ./BytesRange.h \
    ./BitsRange.h \
    ./UnbitsRange.h \
    ./UnbytesRange.h \
    ./CommonTests.h
SOURCES += ./main.cpp \
    ./DotCallTest.cpp \
    ./LinqTest.cpp \
    ./ToContainerTest.cpp \
    ./ToDequeTest.cpp \
    ./ToListTest.cpp \
    ./ToSetTest.cpp \
    ./ToVectorTest.cpp \
    ./DistinctRangeTest.cpp \
    ./GroupByRangeTest.cpp \
    ./OrderByRangeTest.cpp \
    ./ReverseRangeTest.cpp \
    ./SelectRangeTest.cpp \
    ./SkipRangeTest.cpp \
    ./TakeRangeTest.cpp \
    ./IterRangeTest.cpp \
    ./ConcatRangeTest.cpp \
    ./WhereRangeTest.cpp \
    ./AllTest.cpp \
    ./AnyTest.cpp \
    ./AvgTest.cpp \
    ./ContainsTest.cpp \
    ./CountTest.cpp \
    ./ElementAtTest.cpp \
    ./ForEachTest.cpp \
    ./MaxTest.cpp \
    ./MinTest.cpp \
    ./SumTest.cpp \
    ./BytesRangeTest.cpp \
    ./BitsRangeTest.cpp \
    ./UnbitsRangeTest.cpp \
    ./UnbytesRangeTest.cpp \
    ../gmock/src/gmock-all.cc \
    ../gmock/gtest/src/gtest-all.cc
