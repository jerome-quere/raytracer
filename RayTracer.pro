######################################################################
# Automatically generated by qmake (2.01a) Wed Sep 14 18:04:10 2011
######################################################################

TEMPLATE = app
TARGET = rt

DEPENDPATH += . src/conf src/gui src/main src/math src/objects
INCLUDEPATH += . src/conf src/gui src/math src/objects

QT += xml

OBJECTS_DIR = ./objects/
MOC_DIR     = ./mocs/
UI_DIR      = ./mocs/

CXXFLAGS += -std=c++0x

HEADERS += src/calc/RtCalcColor.hpp             \
           src/calc/RtCalcGenerator.hpp         \
           src/calc/RtCalcImage.hpp             \
           src/conf/RtConfConf.hpp              \
           src/conf/RtConfLoader.hpp            \
           src/gui/RtGuiConfFileDialog.hpp      \
           src/gui/RtGuiController.hpp          \
           src/gui/RtGuiMainWindow.hpp          \
           src/math/RtMathDouble.hpp            \
           src/math/RtMathEquationSolver.hpp    \
           src/math/RtMathLine.hpp              \
           src/math/RtMathObject.hpp            \
           src/math/RtMathPlane.hpp             \
           src/math/RtMathPoint.hpp             \
           src/math/RtMathSphere.hpp            \
           src/math/RtMathVector.hpp            \
           src/objects/RtObjectEye.hpp          \
           src/objects/RtObjectObject.hpp       \
           src/objects/RtObjectPlane.hpp        \
           src/objects/RtObjectSphere.hpp       \



SOURCES += src/calc/RtCalcColor.cpp             \
           src/calc/RtCalcGenerator.cpp         \
           src/calc/RtCalcImage.cpp             \
           src/conf/RtConfConf.cpp              \
           src/conf/RtConfLoader.cpp            \
           src/gui/RtGuiConfFileDialog.cpp      \
           src/gui/RtGuiController.cpp          \
           src/gui/RtGuiMainWindow.cpp          \
           src/main/main.cpp                    \
           src/math/RtMathDouble.cpp            \
           src/math/RtMathEquationSolver.cpp    \
           src/math/RtMathLine.cpp              \
           src/math/RtMathPlane.cpp             \
           src/math/RtMathPoint.cpp             \
           src/math/RtMathSphere.cpp            \
           src/math/RtMathVector.cpp            \
           src/objects/RtObjectEye.cpp          \
           src/objects/RtObjectObject.cpp       \
           src/objects/RtObjectPlane.cpp        \
           src/objects/RtObjectSphere.cpp       \


FORMS   += src/gui/RtGuiMainWindow.ui           \
