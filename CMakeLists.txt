# cmakeの設定
cmake_minimum_required(VERSION 3.8)
project(mid360_imu_corector)

# 必要なパッケージのinclude
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

# コンパイルオプション
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -O2)
endif()

# c++ファイル
file(GLOB_RECURSE ${PROJECT_NAME}_src_files
  LIST_DIRECTORIES false
  RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
  "src/*/*")
list(LENGTH ${PROJECT_NAME}_src_files src_files_count)
if(src_files_count GREATER 0)
  ament_auto_add_library(${PROJECT_NAME}_lib SHARED "${${PROJECT_NAME}_src_files}")
  target_compile_features(${PROJECT_NAME}_lib PUBLIC c_std_99 cxx_std_17)
endif()

# ディレクトリのinstall
set(install_directories config;launch;${${PROJECT_NAME_UPPER}_INSTALL_DIRECTORIES})
foreach(install_directory IN LISTS install_directories)
  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${install_directory}")
    install(DIRECTORY
      "${install_directory}"
      DESTINATION share/${PROJECT_NAME}/)
  endif()
endforeach()

# ノードプラグインとエグゼキュータ(ros2 runで実行するコマンド)の設定
rclcpp_components_register_node(${PROJECT_NAME}_lib
  PLUGIN "mid360_imu_corector::Mid360ImuCorectorNode"
  EXECUTABLE "mid360_imu_corector_node")

# テスト
if(BUILD_TESTING)
  ament_auto_find_test_dependencies()
  ament_lint_auto_find_test_dependencies()
endif()

# パッケージング
ament_auto_package()
