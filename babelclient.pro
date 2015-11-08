QT       += core gui

TARGET = babelclient

TEMPLATE = app

SOURCES +=      Client/src/* \ 
                CommonIncludes/*.cpp

HEADERS  += 

LIBS = -L ../libgdl/libs/ -lm -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -ldl -lpthread

INCLUDEPATH = ./classes/includes/ ./core/includes/ ./libgdl/includes/

DISTFILES +=






