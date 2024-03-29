cmake_minimum_required(VERSION 3.21)

include(cmake/utilities.cmake)
project(GSensorTest3d LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(QTLIBS Core Quick Widgets 3DCore 3DInput 3DExtras 3DRender SerialPort)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS ${QTLIBS})
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS ${QTLIBS})

set(CXSOURCES_DIR ${PROJECT_SOURCE_DIR}/sources)

set(W32RESFILE ${PROJECT_SOURCE_DIR}/resources/resources.rc)

set(QMLRESFILES ${PROJECT_SOURCE_DIR}/resources/qml.qrc
                ${PROJECT_SOURCE_DIR}/sources/qml.qrc)

set(QMLSOURCES ${CXSOURCES_DIR}/main.qml
               ${CXSOURCES_DIR}/pages/common/GroupControlView.qml
               ${CXSOURCES_DIR}/pages/ApplicationScene3dView.qml
               ${CXSOURCES_DIR}/pages/PortSettingsView.qml)

set(HEADER_FILES ${CXSOURCES_DIR}/core/scenemodifier.hpp
                 ${CXSOURCES_DIR}/core/inputdialog.hpp
                 ${CXSOURCES_DIR}/core/serialport.hpp
                 ${CXSOURCES_DIR}/core/parameters.hpp
                 ${CXSOURCES_DIR}/core/mainwindow.hpp
                 ${CXSOURCES_DIR}/core/modelloader.hpp
                 ${CXSOURCES_DIR}/model/PortSettingsModel.h
                 ${CXSOURCES_DIR}/core/SerialPortReader.h)

set(SOURCE_FILES ${CXSOURCES_DIR}/main.cpp
                 ${CXSOURCES_DIR}/core/scenemodifier.cpp
                 ${CXSOURCES_DIR}/core/inputdialog.cpp
                 ${CXSOURCES_DIR}/core/serialport.cpp
                 ${CXSOURCES_DIR}/core/mainwindow.cpp
                 ${CXSOURCES_DIR}/core/modelloader.cpp
                 ${CXSOURCES_DIR}/model/PortSettingsModel.cpp
                 ${CXSOURCES_DIR}/core/SerialPortReader.cpp)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
format_source_group(${SOURCE_FILES} ${HEADER_FILES} ${QMLRESFILES} ${QMLSOURCES} ${W32RESFILE})

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${QMLRESFILES} ${QMLSOURCES} ${W32RESFILE})
set_property(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE TRUE)

target_link_libraries(${PROJECT_NAME} Qt::Core Qt::Quick Qt::Widgets Qt::3DCore Qt::3DExtras
                                      Qt::3DRender Qt::3DInput Qt::SerialPort)
