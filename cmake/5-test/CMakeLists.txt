# 需要依赖的最小的cmake的版本号
cmake_minimum_required(VERSION 3.0)

# 项目名称, 使用的语言
project(play LANGUAGES CXX)

# 添加配置文件
configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_SOURCE_DIR}/config.h"
)

# 允许test测试脚本
enable_testing()

# 添加配置文件
option(USE_DEBUG "是否打开调试开关" ON)

# 这句很重要, 否则会出现-lutils找不到的情况
add_subdirectory(utils)

# 设置编译类型
set(CMAKE_BUILD_TYPE RELEASE)

# 添加C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 项目类型
add_executable(play main.cc api.cc)

# 注意顺序，要先有init0这个目标，才能添加链接
target_link_libraries(play utils)

# 测试
add_executable(testapp test.cc)

# 注意顺序，要先有init0这个目标，才能添加链接
target_link_libraries(testapp utils)

add_test(NAME testapp COMMAND testapp)

# 配置安装内容
install(TARGETS play DESTINATION bin
		PUBLIC_HEADER DESTINATION include
		)

# 将目标文件进行安装 
install(FILES utils/module.h DESTINATION include)

# 将目标进行安装 
install(TARGETS utils DESTINATION lib)
