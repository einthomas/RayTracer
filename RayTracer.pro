TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ray.cpp \
    mymath.cpp \
    raytracer.cpp \
    vec2.cpp \
    vec3.cpp \
    worldobject.cpp \
    sphere.cpp

HEADERS += \
    ray.h \
    mymath.h \
    raytracer.h \
    vec2.h \
    vec3.h \
    worldobject.h \
    sphere.h

