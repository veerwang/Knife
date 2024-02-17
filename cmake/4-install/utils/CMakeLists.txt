# 设置目录
aux_source_directory(. DIR_UTILS_SRC)

# 项目类型
add_library(utils SHARED ${DIR_UTILS_SRC})

# 设置版本号
set_target_properties(utils PROPERTIES VERSION 2.1 SOVERSION 2)

