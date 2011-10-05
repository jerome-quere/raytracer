#############################################################################
# Makefile for building: rt
# Generated by qmake (2.01a) (Qt 4.7.2) on: Wed Oct 5 02:03:02 2011
# Project:  RayTracer.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile RayTracer.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/qt4 -I. -Isrc/conf -Isrc/calc -Isrc/gui -Isrc/math -Isrc/objects -Imocs -Imocs
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtXml -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
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

OBJECTS_DIR   = objects/

####### Files

SOURCES       = src/calc/RtCalcCalculator.cpp \
		src/calc/RtCalcColor.cpp \
		src/calc/RtCalcGenerator.cpp \
		src/calc/RtCalcImage.cpp \
		src/calc/RtCalcThread.cpp \
		src/calc/RtCalcThreadEventListener.cpp \
		src/calc/RtCalcThreadPool.cpp \
		src/calc/RtCalcThreadTask.cpp \
		src/conf/RtConfConf.cpp \
		src/conf/RtConfLoader.cpp \
		src/gui/RtGuiConfFileDialog.cpp \
		src/gui/RtGuiController.cpp \
		src/gui/RtGuiMainWindow.cpp \
		src/main/main.cpp \
		src/math/RtMathDouble.cpp \
		src/math/RtMathEquationSolver.cpp \
		src/math/RtMathLine.cpp \
		src/math/RtMathPlane.cpp \
		src/math/RtMathPoint.cpp \
		src/math/RtMathSphere.cpp \
		src/math/RtMathTransformation.cpp \
		src/math/RtMathVector.cpp \
		src/objects/RtObjectEye.cpp \
		src/objects/RtObjectObject.cpp \
		src/objects/RtObjectPlane.cpp \
		src/objects/RtObjectSphere.cpp mocs/moc_RtCalcGenerator.cpp \
		mocs/moc_RtCalcThreadEventListener.cpp \
		mocs/moc_RtCalcThreadPool.cpp \
		mocs/moc_RtGuiConfFileDialog.cpp \
		mocs/moc_RtGuiController.cpp \
		mocs/moc_RtGuiMainWindow.cpp
OBJECTS       = objects/RtCalcCalculator.o \
		objects/RtCalcColor.o \
		objects/RtCalcGenerator.o \
		objects/RtCalcImage.o \
		objects/RtCalcThread.o \
		objects/RtCalcThreadEventListener.o \
		objects/RtCalcThreadPool.o \
		objects/RtCalcThreadTask.o \
		objects/RtConfConf.o \
		objects/RtConfLoader.o \
		objects/RtGuiConfFileDialog.o \
		objects/RtGuiController.o \
		objects/RtGuiMainWindow.o \
		objects/main.o \
		objects/RtMathDouble.o \
		objects/RtMathEquationSolver.o \
		objects/RtMathLine.o \
		objects/RtMathPlane.o \
		objects/RtMathPoint.o \
		objects/RtMathSphere.o \
		objects/RtMathTransformation.o \
		objects/RtMathVector.o \
		objects/RtObjectEye.o \
		objects/RtObjectObject.o \
		objects/RtObjectPlane.o \
		objects/RtObjectSphere.o \
		objects/moc_RtCalcGenerator.o \
		objects/moc_RtCalcThreadEventListener.o \
		objects/moc_RtCalcThreadPool.o \
		objects/moc_RtGuiConfFileDialog.o \
		objects/moc_RtGuiController.o \
		objects/moc_RtGuiMainWindow.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		RayTracer.pro
QMAKE_TARGET  = rt
DESTDIR       = 
TARGET        = rt

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

$(TARGET): mocs/ui_RtGuiMainWindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: RayTracer.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQtXml.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -o Makefile RayTracer.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/libQtXml.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile RayTracer.pro

dist: 
	@$(CHK_DIR_EXISTS) objects/rt1.0.0 || $(MKDIR) objects/rt1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) objects/rt1.0.0/ && $(COPY_FILE) --parents src/calc/RtCalcCalculator.hpp src/calc/RtCalcColor.hpp src/calc/RtCalcGenerator.hpp src/calc/RtCalcImage.hpp src/calc/RtCalcThread.hpp src/calc/RtCalcThreadEventListener.hpp src/calc/RtCalcThreadPool.hpp src/calc/RtCalcThreadTask.hpp src/conf/RtConfConf.hpp src/conf/RtConfLoader.hpp src/gui/RtGuiConfFileDialog.hpp src/gui/RtGuiController.hpp src/gui/RtGuiMainWindow.hpp src/math/RtMathDouble.hpp src/math/RtMathEquationSolver.hpp src/math/RtMathLine.hpp src/math/RtMathObject.hpp src/math/RtMathPlane.hpp src/math/RtMathPoint.hpp src/math/RtMathSphere.hpp src/math/RtMathTransformation.hpp src/math/RtMathVector.hpp src/objects/RtObjectEye.hpp src/objects/RtObjectObject.hpp src/objects/RtObjectPlane.hpp src/objects/RtObjectSphere.hpp objects/rt1.0.0/ && $(COPY_FILE) --parents src/calc/RtCalcCalculator.cpp src/calc/RtCalcColor.cpp src/calc/RtCalcGenerator.cpp src/calc/RtCalcImage.cpp src/calc/RtCalcThread.cpp src/calc/RtCalcThreadEventListener.cpp src/calc/RtCalcThreadPool.cpp src/calc/RtCalcThreadTask.cpp src/conf/RtConfConf.cpp src/conf/RtConfLoader.cpp src/gui/RtGuiConfFileDialog.cpp src/gui/RtGuiController.cpp src/gui/RtGuiMainWindow.cpp src/main/main.cpp src/math/RtMathDouble.cpp src/math/RtMathEquationSolver.cpp src/math/RtMathLine.cpp src/math/RtMathPlane.cpp src/math/RtMathPoint.cpp src/math/RtMathSphere.cpp src/math/RtMathTransformation.cpp src/math/RtMathVector.cpp src/objects/RtObjectEye.cpp src/objects/RtObjectObject.cpp src/objects/RtObjectPlane.cpp src/objects/RtObjectSphere.cpp objects/rt1.0.0/ && $(COPY_FILE) --parents src/gui/RtGuiMainWindow.ui objects/rt1.0.0/ && (cd `dirname objects/rt1.0.0` && $(TAR) rt1.0.0.tar rt1.0.0 && $(COMPRESS) rt1.0.0.tar) && $(MOVE) `dirname objects/rt1.0.0`/rt1.0.0.tar.gz . && $(DEL_FILE) -r objects/rt1.0.0


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

compiler_moc_header_make_all: mocs/moc_RtCalcGenerator.cpp mocs/moc_RtCalcThreadEventListener.cpp mocs/moc_RtCalcThreadPool.cpp mocs/moc_RtGuiConfFileDialog.cpp mocs/moc_RtGuiController.cpp mocs/moc_RtGuiMainWindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) mocs/moc_RtCalcGenerator.cpp mocs/moc_RtCalcThreadEventListener.cpp mocs/moc_RtCalcThreadPool.cpp mocs/moc_RtGuiConfFileDialog.cpp mocs/moc_RtGuiController.cpp mocs/moc_RtGuiMainWindow.cpp
mocs/moc_RtCalcGenerator.cpp: src/conf/RtConfConf.hpp \
		src/objects/RtObjectObject.hpp \
		src/objects/RtObjectEye.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/calc/RtCalcImage.hpp \
		src/calc/RtCalcColor.hpp \
		src/calc/RtCalcThreadPool.hpp \
		src/calc/RtCalcThread.hpp \
		src/calc/RtCalcThreadEventListener.hpp \
		src/calc/RtCalcThreadTask.hpp \
		src/math/RtMathLine.hpp \
		src/math/RtMathObject.hpp \
		src/calc/RtCalcGenerator.hpp
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/calc/RtCalcGenerator.hpp -o mocs/moc_RtCalcGenerator.cpp

mocs/moc_RtCalcThreadEventListener.cpp: src/calc/RtCalcThreadEventListener.hpp
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/calc/RtCalcThreadEventListener.hpp -o mocs/moc_RtCalcThreadEventListener.cpp

mocs/moc_RtCalcThreadPool.cpp: src/calc/RtCalcThread.hpp \
		src/calc/RtCalcThreadEventListener.hpp \
		src/calc/RtCalcThreadTask.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/math/RtMathLine.hpp \
		src/math/RtMathObject.hpp \
		src/calc/RtCalcColor.hpp \
		src/conf/RtConfConf.hpp \
		src/objects/RtObjectObject.hpp \
		src/objects/RtObjectEye.hpp \
		src/calc/RtCalcThreadPool.hpp
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/calc/RtCalcThreadPool.hpp -o mocs/moc_RtCalcThreadPool.cpp

mocs/moc_RtGuiConfFileDialog.cpp: src/gui/RtGuiConfFileDialog.hpp
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/gui/RtGuiConfFileDialog.hpp -o mocs/moc_RtGuiConfFileDialog.cpp

mocs/moc_RtGuiController.cpp: src/gui/RtGuiMainWindow.hpp \
		mocs/ui_RtGuiMainWindow.h \
		src/conf/RtConfConf.hpp \
		src/objects/RtObjectObject.hpp \
		src/objects/RtObjectEye.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/gui/RtGuiConfFileDialog.hpp \
		src/gui/RtGuiController.hpp
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/gui/RtGuiController.hpp -o mocs/moc_RtGuiController.cpp

mocs/moc_RtGuiMainWindow.cpp: mocs/ui_RtGuiMainWindow.h \
		src/gui/RtGuiMainWindow.hpp
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/gui/RtGuiMainWindow.hpp -o mocs/moc_RtGuiMainWindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: mocs/qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) mocs/qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: mocs/ui_RtGuiMainWindow.h
compiler_uic_clean:
	-$(DEL_FILE) mocs/ui_RtGuiMainWindow.h
mocs/ui_RtGuiMainWindow.h: src/gui/RtGuiMainWindow.ui
	/usr/bin/uic-qt4 src/gui/RtGuiMainWindow.ui -o mocs/ui_RtGuiMainWindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

objects/RtCalcCalculator.o: src/calc/RtCalcCalculator.cpp src/calc/RtCalcCalculator.hpp \
		src/objects/RtObjectEye.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/math/RtMathTransformation.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtCalcCalculator.o src/calc/RtCalcCalculator.cpp

objects/RtCalcColor.o: src/calc/RtCalcColor.cpp src/calc/RtCalcColor.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtCalcColor.o src/calc/RtCalcColor.cpp

objects/RtCalcGenerator.o: src/calc/RtCalcGenerator.cpp src/calc/RtCalcGenerator.hpp \
		src/conf/RtConfConf.hpp \
		src/objects/RtObjectObject.hpp \
		src/objects/RtObjectEye.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/calc/RtCalcImage.hpp \
		src/calc/RtCalcColor.hpp \
		src/calc/RtCalcThreadPool.hpp \
		src/calc/RtCalcThread.hpp \
		src/calc/RtCalcThreadEventListener.hpp \
		src/calc/RtCalcThreadTask.hpp \
		src/math/RtMathLine.hpp \
		src/math/RtMathObject.hpp \
		src/calc/RtCalcCalculator.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtCalcGenerator.o src/calc/RtCalcGenerator.cpp

objects/RtCalcImage.o: src/calc/RtCalcImage.cpp src/calc/RtCalcImage.hpp \
		src/calc/RtCalcColor.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtCalcImage.o src/calc/RtCalcImage.cpp

objects/RtCalcThread.o: src/calc/RtCalcThread.cpp src/calc/RtCalcThread.hpp \
		src/calc/RtCalcThreadEventListener.hpp \
		src/calc/RtCalcThreadPool.hpp \
		src/calc/RtCalcThreadTask.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/math/RtMathLine.hpp \
		src/math/RtMathObject.hpp \
		src/calc/RtCalcColor.hpp \
		src/conf/RtConfConf.hpp \
		src/objects/RtObjectObject.hpp \
		src/objects/RtObjectEye.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtCalcThread.o src/calc/RtCalcThread.cpp

objects/RtCalcThreadEventListener.o: src/calc/RtCalcThreadEventListener.cpp src/calc/RtCalcThread.hpp \
		src/calc/RtCalcThreadEventListener.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtCalcThreadEventListener.o src/calc/RtCalcThreadEventListener.cpp

objects/RtCalcThreadPool.o: src/calc/RtCalcThreadPool.cpp src/calc/RtCalcThreadPool.hpp \
		src/calc/RtCalcThread.hpp \
		src/calc/RtCalcThreadEventListener.hpp \
		src/calc/RtCalcThreadTask.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/math/RtMathLine.hpp \
		src/math/RtMathObject.hpp \
		src/calc/RtCalcColor.hpp \
		src/conf/RtConfConf.hpp \
		src/objects/RtObjectObject.hpp \
		src/objects/RtObjectEye.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtCalcThreadPool.o src/calc/RtCalcThreadPool.cpp

objects/RtCalcThreadTask.o: src/calc/RtCalcThreadTask.cpp src/calc/RtCalcThreadTask.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/math/RtMathLine.hpp \
		src/math/RtMathObject.hpp \
		src/calc/RtCalcColor.hpp \
		src/conf/RtConfConf.hpp \
		src/objects/RtObjectObject.hpp \
		src/objects/RtObjectEye.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtCalcThreadTask.o src/calc/RtCalcThreadTask.cpp

objects/RtConfConf.o: src/conf/RtConfConf.cpp src/conf/RtConfConf.hpp \
		src/objects/RtObjectObject.hpp \
		src/objects/RtObjectEye.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtConfConf.o src/conf/RtConfConf.cpp

objects/RtConfLoader.o: src/conf/RtConfLoader.cpp src/conf/RtConfLoader.hpp \
		src/conf/RtConfConf.hpp \
		src/objects/RtObjectObject.hpp \
		src/objects/RtObjectEye.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/math/RtMathPlane.hpp \
		src/math/RtMathObject.hpp \
		src/math/RtMathSphere.hpp \
		src/objects/RtObjectSphere.hpp \
		src/objects/RtObjectPlane.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtConfLoader.o src/conf/RtConfLoader.cpp

objects/RtGuiConfFileDialog.o: src/gui/RtGuiConfFileDialog.cpp src/gui/RtGuiConfFileDialog.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtGuiConfFileDialog.o src/gui/RtGuiConfFileDialog.cpp

objects/RtGuiController.o: src/gui/RtGuiController.cpp src/gui/RtGuiController.hpp \
		src/gui/RtGuiMainWindow.hpp \
		mocs/ui_RtGuiMainWindow.h \
		src/conf/RtConfConf.hpp \
		src/objects/RtObjectObject.hpp \
		src/objects/RtObjectEye.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/gui/RtGuiConfFileDialog.hpp \
		src/conf/RtConfLoader.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtGuiController.o src/gui/RtGuiController.cpp

objects/RtGuiMainWindow.o: src/gui/RtGuiMainWindow.cpp src/gui/RtGuiMainWindow.hpp \
		mocs/ui_RtGuiMainWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtGuiMainWindow.o src/gui/RtGuiMainWindow.cpp

objects/main.o: src/main/main.cpp src/gui/RtGuiController.hpp \
		src/gui/RtGuiMainWindow.hpp \
		mocs/ui_RtGuiMainWindow.h \
		src/conf/RtConfConf.hpp \
		src/objects/RtObjectObject.hpp \
		src/objects/RtObjectEye.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/gui/RtGuiConfFileDialog.hpp \
		src/conf/RtConfLoader.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/main.o src/main/main.cpp

objects/RtMathDouble.o: src/math/RtMathDouble.cpp src/math/RtMathDouble.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtMathDouble.o src/math/RtMathDouble.cpp

objects/RtMathEquationSolver.o: src/math/RtMathEquationSolver.cpp src/math/RtMathEquationSolver.hpp \
		src/math/RtMathDouble.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtMathEquationSolver.o src/math/RtMathEquationSolver.cpp

objects/RtMathLine.o: src/math/RtMathLine.cpp src/math/RtMathLine.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/math/RtMathObject.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtMathLine.o src/math/RtMathLine.cpp

objects/RtMathPlane.o: src/math/RtMathPlane.cpp src/math/RtMathLine.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/math/RtMathObject.hpp \
		src/math/RtMathPlane.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtMathPlane.o src/math/RtMathPlane.cpp

objects/RtMathPoint.o: src/math/RtMathPoint.cpp src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtMathPoint.o src/math/RtMathPoint.cpp

objects/RtMathSphere.o: src/math/RtMathSphere.cpp src/math/RtMathSphere.hpp \
		src/math/RtMathObject.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/math/RtMathLine.hpp \
		src/math/RtMathEquationSolver.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtMathSphere.o src/math/RtMathSphere.cpp

objects/RtMathTransformation.o: src/math/RtMathTransformation.cpp src/math/RtMathTransformation.hpp \
		src/math/RtMathVector.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathPoint.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtMathTransformation.o src/math/RtMathTransformation.cpp

objects/RtMathVector.o: src/math/RtMathVector.cpp src/math/RtMathVector.hpp \
		src/math/RtMathDouble.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtMathVector.o src/math/RtMathVector.cpp

objects/RtObjectEye.o: src/objects/RtObjectEye.cpp src/objects/RtObjectEye.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtObjectEye.o src/objects/RtObjectEye.cpp

objects/RtObjectObject.o: src/objects/RtObjectObject.cpp src/objects/RtObjectObject.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtObjectObject.o src/objects/RtObjectObject.cpp

objects/RtObjectPlane.o: src/objects/RtObjectPlane.cpp src/objects/RtObjectPlane.hpp \
		src/objects/RtObjectObject.hpp \
		src/math/RtMathPlane.hpp \
		src/math/RtMathObject.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtObjectPlane.o src/objects/RtObjectPlane.cpp

objects/RtObjectSphere.o: src/objects/RtObjectSphere.cpp src/objects/RtObjectSphere.hpp \
		src/math/RtMathSphere.hpp \
		src/math/RtMathObject.hpp \
		src/math/RtMathPoint.hpp \
		src/math/RtMathDouble.hpp \
		src/math/RtMathVector.hpp \
		src/objects/RtObjectObject.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/RtObjectSphere.o src/objects/RtObjectSphere.cpp

objects/moc_RtCalcGenerator.o: mocs/moc_RtCalcGenerator.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/moc_RtCalcGenerator.o mocs/moc_RtCalcGenerator.cpp

objects/moc_RtCalcThreadEventListener.o: mocs/moc_RtCalcThreadEventListener.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/moc_RtCalcThreadEventListener.o mocs/moc_RtCalcThreadEventListener.cpp

objects/moc_RtCalcThreadPool.o: mocs/moc_RtCalcThreadPool.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/moc_RtCalcThreadPool.o mocs/moc_RtCalcThreadPool.cpp

objects/moc_RtGuiConfFileDialog.o: mocs/moc_RtGuiConfFileDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/moc_RtGuiConfFileDialog.o mocs/moc_RtGuiConfFileDialog.cpp

objects/moc_RtGuiController.o: mocs/moc_RtGuiController.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/moc_RtGuiController.o mocs/moc_RtGuiController.cpp

objects/moc_RtGuiMainWindow.o: mocs/moc_RtGuiMainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objects/moc_RtGuiMainWindow.o mocs/moc_RtGuiMainWindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

