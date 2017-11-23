TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    app.cpp \
    intersection.cpp \
    road.cpp \
    movingcar.cpp

HEADERS += \
    app.h \
    car.h \
    intersection.h \
    road.h \
    intertrafficcntrlr.h \
    movingcar.h

CONFIG += c++11

LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

