
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/sortModule SRC_LIST)

#set include dir
INCLUDE_DIRECTORIES(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/sortModule)

#link library dir
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/bin)

#set link libraries


#set output dir
SET(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)

ADD_LIBRARY(SortLib SHARED ${SRC_LIST})

#link libraries
