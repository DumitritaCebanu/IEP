#Cmake version
cmake_minimum_required(VERSION 3.0)

#Assigming the name of the project which I have chosen to the variable project_name
set(project_name "rectangle")

#Giving the name wich I have chosen to the project
project(${project_name})

#Specify the required c++ standards
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OF)
find_package(Threads REQUIRED)

#Define executable
add_executable(${PROJECT_NAME}
		./iep6.cpp)
target_link_libraries(${PROJECT_NAME} Threads::Threads)