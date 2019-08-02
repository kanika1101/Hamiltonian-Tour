TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        checkTriangleInequality.c \
        dfs.c \
        graph.c \
        hash.c \
        heapsort.c \
        llist.c \
        main.c \
        minimumSpanningTree.c \
        vertices.c

DISTFILES += \
    MST-1a2 \
    MST-2-2 \
    Parse-1.txt \
    Parse-2.txt \
    Parse-3.txt \
    Parse-4.txt \
    Parse-5.txt \
    Parse-6.txt \
    Parse-7.txt \
    Parse-8.txt \
    Parse-9a.txt \
    Parse-9b.txt \
    Triangle-1.txt \
    Triangle-2.txt \
    graph

HEADERS += \
    checkTriangleInequality.h \
    dfs.h \
    graph.h \
    hash.h \
    heapsort.h \
    llist.h \
    main.h \
    minimumSpanningTree.h \
    vertices.h
