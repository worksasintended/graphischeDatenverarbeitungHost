CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(uebung01)
SET( CMAKE_BUILD_TYPE DEBUG )

SET( CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS} -march=native" )
SET( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -pedantic -D_GLIBCXX_DEBUG -fsanitize=address" )
SET( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}" )

SET( CMAKE_CXX_STANDARD 17 )

SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
#SET( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib )

SET( CMAKE_EXPORT_COMPILE_COMMANDS on )

ADD_EXECUTABLE(teapot 
  teapot.cpp
  backface.cpp 
  flatshading.cpp
  gouraudshading.cpp
  lines.cpp
  math3d.cpp
  projection.cpp
  teapotdata.cpp
  trifill.cpp
  wireframe.cpp
  )

#TARGET_INCLUDE_DIRECTORIES( bin_test )
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(teapot ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
