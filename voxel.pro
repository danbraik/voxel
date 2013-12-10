TEMPLATE = app
#CONFIG += console
#CONFIG -= qt

# QMAKE_CXXFLAGS_DEBUG -= -O2
# QMAKE_CXXFLAGS_RELEASE += -O2 -Os

# debug
LIBS += -L/usr/local/lib/ -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-system-d -lGL -lGLU -lGLEW
# release
#LIBS += -L/usr/local/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lGL -lGLU -lGLEW


OBJECTS_DIR = .obj
OBJECTS_DIR = .obj

SOURCES += src/main.cpp \
    src/Render/Renderer.cpp \
    src/Chunk/Chunk.cpp \
    src/Block/Block.cpp \
    src/Block/SimpleBlock.cpp \
    src/Freeflycamera.cpp \
    src/Vector3d.cpp \
    src/Chunk/ChunkManager.cpp \
    src/Render/Mesh.cpp \
    src/Chunk/LocalChunkSystem.cpp \
    src/VectorTools.cpp \
    src/Chunk/ChunkPool.cpp \
    src/WorldGenerator.cpp \
    src/Chunk/ChunkPersistence.cpp \
    src/RaycastHelper.cpp \
    src/Chunk/ChunkData.cpp \
    src/Chunk/Chunk3dContainer.cpp \
    src/procedural/simplexnoise.cpp \
    src/procedural/simplextextures.cpp \
    src/ProfilTimer.cpp \
    src/Block/BlockList.cpp \
    src/Render/MeshVertex.cpp \
    src/VoxelEngine.cpp \
    src/Block/NoBlock.cpp \
    src/Block/ComplexBlock.cpp \
    src/Signal/SignalableBlock.cpp \
    src/Signal/Wire.cpp \
    src/Signal/Power.cpp \
    src/Signal/SignalManager.cpp \
    src/Signal/AndLogic.cpp \
    src/Signal/SignalW.cpp
    

HEADERS += \
    src/Render/Renderer.hpp \
    src/Freeflycamera.h \
    src/Vector3d.h \
    src/VectorTools.hpp \
    src/Mesh.hpp \
    src/MeshVertex.hpp \
    src/Chunk/Chunk.hpp \
    src/Block/Block.hpp \
    src/Block/SimpleBlock.hpp \
    src/Chunk/LocalChunkSystem.hpp \
    src/Chunk/ChunkManager.hpp \
    src/Chunk/ChunkPool.hpp \
    src/Chunk/ChunkPersistence.hpp \
    src/Chunk/ChunkData.hpp \
    src/Chunk/Chunk3dContainer.hpp \
    src/WorldGenerator.hpp \
    src/RaycastHelper.hpp \
    src/procedural/simplexnoise.h \
    src/procedural/simplextextures.h \
    src/ProfilTimer.hpp \
    src/Block/BlockList.hpp \
    src/VoxelEngine.hpp \
    src/Block/NoBlock.hpp \
    src/Block/ComplexBlock.hpp \
    src/Signal/SignalableBlock.hpp \
    src/Signal/Wire.hpp \
    src/Signal/Power.hpp \
    src/Signal/SignalManager.hpp \
    src/Signal/AndLogic.hpp \
    src/Signal/SignalW.hpp
    

