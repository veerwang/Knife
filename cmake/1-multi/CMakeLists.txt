# 需要依赖的最小的cmake的版本号
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(init0)

# 这句很重要, 否则会出现-lutils找不到的情况
add_subdirectory(utils)

# 项目类型
add_executable(init0 main.cc api.cc)

# 注意顺序，要先有init0这个目标，才能添加链接
target_link_libraries(init0 utils)
