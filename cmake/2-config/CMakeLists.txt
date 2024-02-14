# 需要依赖的最小的cmake的版本号
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(play)

# 添加配置文件
configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_SOURCE_DIR}/config.h"
)

# 添加配置文件
option(USE_DEBUG "是否打开调试开关" ON)

# 这句很重要, 否则会出现-lutils找不到的情况
add_subdirectory(utils)

# 添加C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 项目类型
add_executable(play main.cc api.cc)

# 注意顺序，要先有init0这个目标，才能添加链接
target_link_libraries(play utils)
