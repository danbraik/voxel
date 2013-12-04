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
    src/Mesh.cpp \
    src/LocalChunkSystem.cpp \
    src/VectorTools.cpp \
    src/ChunkPool.cpp \
    src/WorldGenerator.cpp \
    src/ChunkPersistence.cpp \
    src/RaycastHelper.cpp \
    src/ChunkData.cpp \
    src/ChunkDataPool.cpp \
    src/Chunk3dContainer.cpp \
    src/procedural/simplexnoise.cpp \
    src/procedural/simplextextures.cpp

HEADERS += \
    src/Renderer.hpp \
    src/Chunk.hpp \
    src/Block.hpp \
    src/Freeflycamera.h \
    src/Vector3d.h \
    src/Mesh.hpp \
    src/LocalChunkSystem.hpp \
    src/VectorTools.hpp \
    src/ChunkManager.hpp \
    src/ChunkPool.hpp \
    src/WorldGenerator.hpp \
    src/ChunkPersistence.hpp \
    src/RaycastHelper.hpp \
    src/ChunkData.hpp \
    src/ChunkDataPool.hpp \
    src/Chunk3dContainer.hpp \
    src/procedural/simplexnoise.h \
    src/procedural/simplextextures.h

