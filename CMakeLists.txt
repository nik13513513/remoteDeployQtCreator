cmake_minimum_required(VERSION 2.8)

#директория на удаленном сервере для деплоя
file(WRITE "${CMAKE_SOURCE_DIR}/QtCreatorDeployment.txt" "2/deploy\n")

macro(add_deployment_file SRC DEST)
  file(RELATIVE_PATH path ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
  file(APPEND "${CMAKE_SOURCE_DIR}/QtCreatorDeployment.txt" "${path}/${SRC}:${DEST}\n")
endmacro()

macro(add_deployment_directory SRC DEST)
 file(GLOB_RECURSE files RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${SRC}/*")
 foreach(filename ${files})
   get_filename_component(path ${filename} PATH)
   add_deployment_file("${filename}" "${DEST}/${path}")
 endforeach(filename)
endmacro()

project(remoteDeploy)
set (CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} "main.cpp")
add_deployment_file(main.cpp ./)#дополнительные файлы
