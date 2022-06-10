cmake_minimum_required(VERSION 3.0)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(SceShaccCgExt)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -ffast-math -mtune=cortex-a9 -mfpu=neon -fno-optimize-sibling-calls -ftree-vectorize -Wall -Iinclude")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -ffast-math -mtune=cortex-a9 -mfpu=neon -fno-optimize-sibling-calls -ftree-vectorize -Wall -fno-exceptions -fno-rtti -std=gnu++11 -fpermissive -Iinclude")

add_library(${PROJECT_NAME}
  include/shacccg_ext.h
  include/sce_intrinsics.h
  src/shacccg_ext.c
  src/shacccg_ext_oop.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
  include)

target_link_libraries(${PROJECT_NAME}
  taihen_stub
  SceLibKernel_stub
  SceKernelModuleMgr_stub
)

install(TARGETS ${PROJECT_NAME})

install(FILES include/shacccg_ext.h
  DESTINATION include
)
