cmake_minimum_required(VERSION 3.12)
project(game_dev)
set(CMAKE_CXX_STANDARD 14)



set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(./glfw-3.2.1)

#add_subdirectory(./nanogui)


include_directories(./glm-0.9.9.2)
include_directories(./include)
include_directories(./glad/include)
include_directories(./assimp-4.1.0/include)
LINK_DIRECTORIES(assimp-4.1.0/lib/)
FILE(COPY resource/  DESTINATION "${CMAKE_BINARY_DIR}/resource")



add_executable(game_dev src/main.cpp ./glad/src/glad.c)
target_link_libraries(game_dev glfw)

add_executable(Hello-Triangle src/Hello-Triangle.cpp ./glad/src/glad.c)
target_link_libraries(Hello-Triangle glfw)


add_executable(Hello-Triangle1 src/Hello-Triangle1.cpp ./glad/src/glad.c)
target_link_libraries(Hello-Triangle1 glfw)

add_executable(Hello-Triangle2 src/Hello-Triangle2.cpp ./glad/src/glad.c)
target_link_libraries(Hello-Triangle2 glfw)


add_executable(shaders1 src/shaders1.cpp ./glad/src/glad.c)
target_link_libraries(shaders1 glfw)

add_executable(shaders2 src/shaders2.cpp ./glad/src/glad.c)
target_link_libraries(shaders2 glfw)

add_executable(shaders_interpolation src/shaders_interpolation.cpp ./glad/src/glad.c)
target_link_libraries(shaders_interpolation glfw)

add_executable(shaders_class src/shaders_class.cpp ./glad/src/glad.c)
target_link_libraries(shaders_class glfw)

add_executable(textures src/textures.cpp ./glad/src/glad.c)
target_link_libraries(textures glfw)

add_executable(textures_combined src/textures_combined.cpp ./glad/src/glad.c)
target_link_libraries(textures_combined glfw)

add_executable(textures_exercise4 src/textures_exercise4.cpp ./glad/src/glad.c)
target_link_libraries(textures_exercise4 glfw)

add_executable(transformations src/transformations.cpp ./glad/src/glad.c)
target_link_libraries(transformations glfw)

add_executable(coordinate_systems src/coordinate_systems.cpp ./glad/src/glad.c)
target_link_libraries(coordinate_systems glfw)

add_executable(coordinate_systems_multiple src/coordinate_systems_multiple.cpp ./glad/src/glad.c)
target_link_libraries(coordinate_systems_multiple glfw)

add_executable(camera_circle src/camera_circle.cpp ./glad/src/glad.c)
target_link_libraries(camera_circle glfw)

add_executable(camera_class src/camera_class.cpp ./glad/src/glad.c)
target_link_libraries(camera_class glfw)


add_executable(model_loading src/model_loading.cpp ./glad/src/glad.c)
target_link_libraries(model_loading glfw assimp)

add_executable(httpTest src/httpTest.cpp)


add_executable(color src/color.cpp ./glad/src/glad.c)
target_link_libraries(color glfw)

add_executable(basic_lighting_diffuse src/basic_lighting_diffuse.cpp ./glad/src/glad.c)
target_link_libraries(basic_lighting_diffuse glfw)

add_executable(basic_lighting_specular src/basic_lighting_specular.cpp ./glad/src/glad.c)
target_link_libraries(basic_lighting_specular glfw)

add_executable(materials src/materials.cpp ./glad/src/glad.c)
target_link_libraries(materials glfw)

add_executable(lighting_maps_diffuse src/lighting_maps_diffuse.cpp ./glad/src/glad.c)
target_link_libraries(lighting_maps_diffuse glfw)

add_executable(multiple_lights src/multiple_lights.cpp ./glad/src/glad.c)
target_link_libraries(multiple_lights glfw)


