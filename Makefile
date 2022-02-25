#############################################################################
# Makefile for building: voxel
# Generated by qmake (2.01a) (Qt 4.8.7) on: jeu. f�vr. 24 17:59:55 2022
# Project:  voxel.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile voxel.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lGL -lGLU -lGLEW -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = .obj/

####### Files

SOURCES       = src/main.cpp \
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
		src/Signal/OrLogic.cpp \
		src/Signal/NotLogic.cpp 
OBJECTS       = .obj/main.o \
		.obj/Renderer.o \
		.obj/Chunk.o \
		.obj/Block.o \
		.obj/SimpleBlock.o \
		.obj/Freeflycamera.o \
		.obj/Vector3d.o \
		.obj/ChunkManager.o \
		.obj/Mesh.o \
		.obj/LocalChunkSystem.o \
		.obj/VectorTools.o \
		.obj/ChunkPool.o \
		.obj/WorldGenerator.o \
		.obj/ChunkPersistence.o \
		.obj/RaycastHelper.o \
		.obj/ChunkData.o \
		.obj/Chunk3dContainer.o \
		.obj/simplexnoise.o \
		.obj/simplextextures.o \
		.obj/ProfilTimer.o \
		.obj/BlockList.o \
		.obj/MeshVertex.o \
		.obj/VoxelEngine.o \
		.obj/NoBlock.o \
		.obj/ComplexBlock.o \
		.obj/SignalableBlock.o \
		.obj/Wire.o \
		.obj/Power.o \
		.obj/SignalManager.o \
		.obj/AndLogic.o \
		.obj/OrLogic.o \
		.obj/NotLogic.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		voxel.pro
QMAKE_TARGET  = voxel
DESTDIR       = 
TARGET        = voxel

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9][^0-9]*\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: voxel.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile voxel.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/declarative_debug.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile voxel.pro

dist: 
	@$(CHK_DIR_EXISTS) .obj/voxel1.0.0 || $(MKDIR) .obj/voxel1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .obj/voxel1.0.0/ && $(COPY_FILE) --parents src/Render/Renderer.hpp src/Freeflycamera.h src/Vector3d.h src/VectorTools.hpp src/Mesh.hpp src/MeshVertex.hpp src/Chunk/Chunk.hpp src/Block/Block.hpp src/Block/SimpleBlock.hpp src/Chunk/LocalChunkSystem.hpp src/Chunk/ChunkManager.hpp src/Chunk/ChunkPool.hpp src/Chunk/ChunkPersistence.hpp src/Chunk/ChunkData.hpp src/Chunk/Chunk3dContainer.hpp src/WorldGenerator.hpp src/RaycastHelper.hpp src/procedural/simplexnoise.h src/procedural/simplextextures.h src/ProfilTimer.hpp src/Block/BlockList.hpp src/VoxelEngine.hpp src/Block/NoBlock.hpp src/Block/ComplexBlock.hpp src/Signal/SignalableBlock.hpp src/Signal/Wire.hpp src/Signal/Power.hpp src/Signal/SignalManager.hpp src/Signal/AndLogic.hpp src/Signal/OrLogic.hpp src/Signal/NotLogic.hpp .obj/voxel1.0.0/ && $(COPY_FILE) --parents src/main.cpp src/Render/Renderer.cpp src/Chunk/Chunk.cpp src/Block/Block.cpp src/Block/SimpleBlock.cpp src/Freeflycamera.cpp src/Vector3d.cpp src/Chunk/ChunkManager.cpp src/Render/Mesh.cpp src/Chunk/LocalChunkSystem.cpp src/VectorTools.cpp src/Chunk/ChunkPool.cpp src/WorldGenerator.cpp src/Chunk/ChunkPersistence.cpp src/RaycastHelper.cpp src/Chunk/ChunkData.cpp src/Chunk/Chunk3dContainer.cpp src/procedural/simplexnoise.cpp src/procedural/simplextextures.cpp src/ProfilTimer.cpp src/Block/BlockList.cpp src/Render/MeshVertex.cpp src/VoxelEngine.cpp src/Block/NoBlock.cpp src/Block/ComplexBlock.cpp src/Signal/SignalableBlock.cpp src/Signal/Wire.cpp src/Signal/Power.cpp src/Signal/SignalManager.cpp src/Signal/AndLogic.cpp src/Signal/OrLogic.cpp src/Signal/NotLogic.cpp .obj/voxel1.0.0/ && (cd `dirname .obj/voxel1.0.0` && $(TAR) voxel1.0.0.tar voxel1.0.0 && $(COMPRESS) voxel1.0.0.tar) && $(MOVE) `dirname .obj/voxel1.0.0`/voxel1.0.0.tar.gz . && $(DEL_FILE) -r .obj/voxel1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

.obj/main.o: src/main.cpp src/Render/Renderer.hpp \
		src/Freeflycamera.h \
		src/Vector3d.h \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/MeshVertex.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp \
		src/WorldGenerator.hpp \
		src/VoxelEngine.hpp \
		src/RaycastHelper.hpp \
		src/ProfilTimer.hpp \
		src/Block/SimpleBlock.hpp \
		src/Signal/Wire.hpp \
		src/Signal/SignalableBlock.hpp \
		src/Block/ComplexBlock.hpp \
		src/Signal/SignalManager.hpp \
		src/Signal/Power.hpp \
		src/Signal/AndLogic.hpp \
		src/Signal/OrLogic.hpp \
		src/Signal/NotLogic.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/main.o src/main.cpp

.obj/Renderer.o: src/Render/Renderer.cpp src/Render/Renderer.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Renderer.o src/Render/Renderer.cpp

.obj/Chunk.o: src/Chunk/Chunk.cpp src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp \
		src/Chunk/LocalChunkSystem.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Chunk.o src/Chunk/Chunk.cpp

.obj/Block.o: src/Block/Block.cpp src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Block.o src/Block/Block.cpp

.obj/SimpleBlock.o: src/Block/SimpleBlock.cpp src/Block/SimpleBlock.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/VectorTools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/SimpleBlock.o src/Block/SimpleBlock.cpp

.obj/Freeflycamera.o: src/Freeflycamera.cpp src/Freeflycamera.h \
		src/Vector3d.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Freeflycamera.o src/Freeflycamera.cpp

.obj/Vector3d.o: src/Vector3d.cpp src/Vector3d.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Vector3d.o src/Vector3d.cpp

.obj/ChunkManager.o: src/Chunk/ChunkManager.cpp src/Chunk/ChunkManager.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp \
		src/VectorTools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/ChunkManager.o src/Chunk/ChunkManager.cpp

.obj/Mesh.o: src/Render/Mesh.cpp src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/Block.hpp \
		src/Render/MeshVertex.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Mesh.o src/Render/Mesh.cpp

.obj/LocalChunkSystem.o: src/Chunk/LocalChunkSystem.cpp src/Chunk/LocalChunkSystem.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp \
		src/VectorTools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/LocalChunkSystem.o src/Chunk/LocalChunkSystem.cpp

.obj/VectorTools.o: src/VectorTools.cpp src/VectorTools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/VectorTools.o src/VectorTools.cpp

.obj/ChunkPool.o: src/Chunk/ChunkPool.cpp src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/ChunkPool.o src/Chunk/ChunkPool.cpp

.obj/WorldGenerator.o: src/WorldGenerator.cpp src/WorldGenerator.hpp \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp \
		src/VoxelEngine.hpp \
		src/RaycastHelper.hpp \
		src/VectorTools.hpp \
		src/procedural/simplextextures.h \
		src/procedural/simplexnoise.h \
		src/Block/SimpleBlock.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/WorldGenerator.o src/WorldGenerator.cpp

.obj/ChunkPersistence.o: src/Chunk/ChunkPersistence.cpp src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/ChunkPersistence.o src/Chunk/ChunkPersistence.cpp

.obj/RaycastHelper.o: src/RaycastHelper.cpp src/RaycastHelper.hpp \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/RaycastHelper.o src/RaycastHelper.cpp

.obj/ChunkData.o: src/Chunk/ChunkData.cpp src/Chunk/ChunkData.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Block/Block.hpp \
		src/Render/MeshVertex.hpp \
		src/Block/BlockList.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/LocalChunkSystem.hpp \
		src/Chunk/Chunk.hpp \
		src/VectorTools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/ChunkData.o src/Chunk/ChunkData.cpp

.obj/Chunk3dContainer.o: src/Chunk/Chunk3dContainer.cpp src/Chunk/Chunk3dContainer.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPool.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Chunk3dContainer.o src/Chunk/Chunk3dContainer.cpp

.obj/simplexnoise.o: src/procedural/simplexnoise.cpp src/procedural/simplexnoise.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/simplexnoise.o src/procedural/simplexnoise.cpp

.obj/simplextextures.o: src/procedural/simplextextures.cpp src/procedural/simplexnoise.h \
		src/procedural/simplextextures.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/simplextextures.o src/procedural/simplextextures.cpp

.obj/ProfilTimer.o: src/ProfilTimer.cpp src/ProfilTimer.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/ProfilTimer.o src/ProfilTimer.cpp

.obj/BlockList.o: src/Block/BlockList.cpp src/Block/BlockList.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Block/NoBlock.hpp \
		src/Block/ComplexBlock.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/BlockList.o src/Block/BlockList.cpp

.obj/MeshVertex.o: src/Render/MeshVertex.cpp src/Render/MeshVertex.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/MeshVertex.o src/Render/MeshVertex.cpp

.obj/VoxelEngine.o: src/VoxelEngine.cpp src/VoxelEngine.hpp \
		src/Render/Renderer.hpp \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/MeshVertex.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp \
		src/RaycastHelper.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/VoxelEngine.o src/VoxelEngine.cpp

.obj/NoBlock.o: src/Block/NoBlock.cpp src/Block/NoBlock.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/NoBlock.o src/Block/NoBlock.cpp

.obj/ComplexBlock.o: src/Block/ComplexBlock.cpp src/Block/ComplexBlock.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/ComplexBlock.o src/Block/ComplexBlock.cpp

.obj/SignalableBlock.o: src/Signal/SignalableBlock.cpp src/Signal/SignalableBlock.hpp \
		src/Block/ComplexBlock.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Signal/SignalManager.hpp \
		src/Signal/Wire.hpp \
		src/Signal/Power.hpp \
		src/Block/SimpleBlock.hpp \
		src/VoxelEngine.hpp \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp \
		src/RaycastHelper.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/SignalableBlock.o src/Signal/SignalableBlock.cpp

.obj/Wire.o: src/Signal/Wire.cpp src/Signal/Wire.hpp \
		src/Signal/SignalableBlock.hpp \
		src/Block/ComplexBlock.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Signal/SignalManager.hpp \
		src/Signal/Power.hpp \
		src/Block/SimpleBlock.hpp \
		src/VoxelEngine.hpp \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp \
		src/RaycastHelper.hpp \
		src/VectorTools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Wire.o src/Signal/Wire.cpp

.obj/Power.o: src/Signal/Power.cpp src/Signal/Power.hpp \
		src/Block/SimpleBlock.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Signal/SignalableBlock.hpp \
		src/Block/ComplexBlock.hpp \
		src/Signal/SignalManager.hpp \
		src/Signal/Wire.hpp \
		src/VoxelEngine.hpp \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp \
		src/RaycastHelper.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Power.o src/Signal/Power.cpp

.obj/SignalManager.o: src/Signal/SignalManager.cpp src/Signal/SignalManager.hpp \
		src/Signal/SignalableBlock.hpp \
		src/Block/ComplexBlock.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Signal/Wire.hpp \
		src/Signal/Power.hpp \
		src/Block/SimpleBlock.hpp \
		src/VoxelEngine.hpp \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp \
		src/RaycastHelper.hpp \
		src/VectorTools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/SignalManager.o src/Signal/SignalManager.cpp

.obj/AndLogic.o: src/Signal/AndLogic.cpp src/Signal/AndLogic.hpp \
		src/Block/ComplexBlock.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Signal/SignalableBlock.hpp \
		src/Signal/SignalManager.hpp \
		src/Signal/Wire.hpp \
		src/Signal/Power.hpp \
		src/Block/SimpleBlock.hpp \
		src/VoxelEngine.hpp \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp \
		src/RaycastHelper.hpp \
		src/VectorTools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/AndLogic.o src/Signal/AndLogic.cpp

.obj/OrLogic.o: src/Signal/OrLogic.cpp src/Signal/OrLogic.hpp \
		src/Block/ComplexBlock.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Signal/SignalableBlock.hpp \
		src/Signal/SignalManager.hpp \
		src/Signal/Wire.hpp \
		src/Signal/Power.hpp \
		src/Block/SimpleBlock.hpp \
		src/VoxelEngine.hpp \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp \
		src/RaycastHelper.hpp \
		src/VectorTools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/OrLogic.o src/Signal/OrLogic.cpp

.obj/NotLogic.o: src/Signal/NotLogic.cpp src/Signal/NotLogic.hpp \
		src/Block/ComplexBlock.hpp \
		src/Block/Block.hpp \
		src/Render/Mesh.hpp \
		src/Render/Renderer.hpp \
		src/Render/MeshVertex.hpp \
		src/Signal/SignalableBlock.hpp \
		src/Signal/SignalManager.hpp \
		src/Signal/Wire.hpp \
		src/Signal/Power.hpp \
		src/Block/SimpleBlock.hpp \
		src/VoxelEngine.hpp \
		src/Chunk/ChunkManager.hpp \
		src/Chunk/Chunk.hpp \
		src/Block/BlockList.hpp \
		src/Block/NoBlock.hpp \
		src/Chunk/ChunkData.hpp \
		src/Chunk/ChunkPool.hpp \
		src/Chunk/ChunkPersistence.hpp \
		src/Chunk/Chunk3dContainer.hpp \
		src/RaycastHelper.hpp \
		src/VectorTools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/NotLogic.o src/Signal/NotLogic.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

