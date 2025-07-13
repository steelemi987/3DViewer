cmake_minimum_required(VERSION 3.16)

project(3DViewer VERSION 1.0 LANGUAGES CXX)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем автогенерацию MOC, UIC, RCC (для Qt-шных *.ui, *.qrc и пр.)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Находим нужные модули Qt6
find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGL OpenGLWidgets)

# Подключаем заголовки (include) из соседних папок
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../bl
    ${CMAKE_CURRENT_SOURCE_DIR}/../controller
    ${CMAKE_CURRENT_SOURCE_DIR}/../qtgifimage/gifimage
)

# Список исходников (.cpp) проекта
set(SOURCES
    main.cpp
    TestOpenGLWidget.cpp
    ocolus.cpp

    ../bl/bl.cpp
    ../bl/new_affine.cpp

    ../controller/controller.cpp

    ../qtgifimage/qgifimage.cpp
    ../qtgifimage/quantize.cpp
    ../qtgifimage/gifalloc.cpp
    ../qtgifimage/gif_hash.cpp
    ../qtgifimage/gif_font.cpp
    ../qtgifimage/gif_err.cpp
    ../qtgifimage/egif_lib.cpp
    ../qtgifimage/dgif_lib.cpp
)

# Список заголовков (.h) для удобства IDE (необязателен для сборки)
set(HEADERS
    TestOpenGLWidget.h
    ocolus.h

    ../bl/bl.h
    ../controller/controller.h

    ../qtgifimage/gif_hash.h
    ../qtgifimage/gif_lib.h
    ../qtgifimage/gif_lib_private.h
    ../qtgifimage/qgifglobal.h
    ../qtgifimage/qgifimage.h
    ../qtgifimage/qgifimage_p.h
)

# Создаём исполняемый файл
add_executable(3DViewer
    ${SOURCES}
    ${HEADERS}
)

# Линкуем его с нужными модулями Qt6
target_link_libraries(3DViewer
    PRIVATE
        Qt6::Widgets
        Qt6::OpenGL
        Qt6::OpenGLWidgets
)
