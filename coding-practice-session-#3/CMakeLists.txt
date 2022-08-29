cmake_minimum_required(VERSION 3.23)
project(KickStart3_2022)

set(CMAKE_CXX_STANDARD 20)

# In order to execute a .cpp file without having 2 problems conflicting, only include NameOfProblem.cpp & NameOfProblem.h of a single problem
add_executable(KickStart3_2022 main.cpp SherlockAndWatsonGymSecrets.cpp SherlockAndWatsonGymSecrets.h)
