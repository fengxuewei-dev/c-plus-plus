
# upperLayer 下的 CMakeLists.txt
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(PROJECT_NAME "ABC")
PROJECT(${PROJECT_NAME} CXX)
# 生成的 .so 文件存放在 libs 文件夹下面
SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/../libs)

# 设置 libblayer.so 的路径
LINK_DIRECTORIES("${CMAKE_SOURCE_DIR}/../ABC") 
# 不允许 CMake 自行加入任何 RPATH
SET(CMAKE_SKIP_BUILD_RPATH TRUE) 
# 生成的 libxxx.so 的 RPATH 是 "./" 和 "./libs"
SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath,.:.libs")

AUX_SOURCE_DIRECTORY(. SRC_LIST)
ADD_LIBRARY(${PROJECT_NAME} SHARED ${SRC_LIST})

# multi_compile 下的CMakeLists.txt
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(PROJECT_NAME "main")
PROJECT(${PROJECT_NAME} CXX)

# 注意这里变成 RUNTIME 了
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

LINK_DIRECTORIES("${CMAKE_SOURCE_DIR}/libs")

# 下面这句不能写，写了就编译不过了。但是不写的话，rpath 就会被 CMake 设置，加上了一个路径
# 我水平有限，不知道怎么解决或者解释，暂且这样吧
#SET(CMAKE_SKIP_BUILD_RPATH TRUE)
# 注意这里变成 EXE 了
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath,./:./libs")

# source directory，源文件目录 在编译文件的时候需要链接库(函数声明)以及源文件(函数具体实现) !!!!!!!!!!!!!!!!]
# aux_source_directory 查找在某个路径下的所有源文件。
AUX_SOURCE_DIRECTORY(./bottomLayer SRC_LIST)
AUX_SOURCE_DIRECTORY(./upperLayer SRC_LIST)

# 当前目录下的所有源文件
AUX_SOURCE_DIRECTORY(./ SRC_LIST)


# 生成可执行文件
ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_LIST})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ulayer)