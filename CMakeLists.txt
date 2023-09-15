cmake_minimum_required(VERSION 3.16.3)
project(otp_m13452874)

add_library(applibrary OneTimePad.cpp)
add_executable(runMain main.cpp)
target_link_libraries(runMain applibrary)