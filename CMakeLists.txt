cmake_minimum_required(VERSION 4.3)
project(ray_tracing_in_one_weekend)

set(CMAKE_CXX_STANDARD 20)

add_executable(ray_tracing_in_one_weekend src/main.cpp
        src/vec3.h
        src/color.h
        src/ray.h
        src/hittable.h
        src/sphere.h
        src/hittable_list.h)
