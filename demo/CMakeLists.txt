#source code
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/demo SRC_LIST)

#set include dir
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

#link libraries dir
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/bin)

#set link libraries
SET(LIBRARY libSortLib.so)

#set output dir
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

ADD_EXECUTABLE(demo ${SRC_LIST})

#link libraries
TARGET_LINK_LIBRARIES(demo ${LIBRARY})
