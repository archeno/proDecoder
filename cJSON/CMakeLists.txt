
target_sources(${CMAKE_PROJECT_NAME} PRIVATE src/cJSON.c include/cJSON/cJSON.h)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC include)
