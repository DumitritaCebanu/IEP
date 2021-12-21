#CMake version
cmake_minimum_required(VERSION 3.0)

#Assigming the name of the project wich I have chosen "figuri" to a variable called #"project_name"
set(project_name "figuri")

#Giving the name wich I have chosen to the project
project(${project_name})

#Specify the required C++ standards
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OF)


#Define the executable
add_executable(${PROJECT_NAME}
		./src/Figura.cpp)
	
