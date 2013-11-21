TEMPLATE = app
#CONFIG += console
#CONFIG -= qt

# debug
LIBS += -L/usr/local/lib/ -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-system-d -lGL -lGLU -lGLEW
# release
#LIBS += -L/usr/local/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lGL -lGLU -lGLEW


OBJECTS_DIR = .obj
OBJECTS_DIR = .obj

SOURCES += src/main.cpp \
    src/Renderer.cpp \
    src/Chunk.cpp \
    src/Block.cpp \
    src/Freeflycamera.cpp \
    src/Vector3d.cpp \
    src/ChunkManager.cpp \
    src/Mesh.cpp

HEADERS += \
    src/Renderer.hpp \
    src/Chunk.hpp \
    src/Block.hpp \
    src/Freeflycamera.h \
    src/Vector3d.h \
    src/ChunkManager.hpp \
    src/Mesh.hpp

