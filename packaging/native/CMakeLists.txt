cmake_minimum_required(VERSION 3.24)
project(WindowsGamepadFilterSDK VERSION 0.1.0.0 LANGUAGES C CXX)
if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
  message(FATAL_ERROR "This SDK requires Windows x64. No driver is installed by this build.")
endif()
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
add_library(TitanWindowsGamepadFilter STATIC
  "sdk/InputFilter/InputFilter.cpp"
)
add_library(WindowsGamepadFilterSDK::sdk ALIAS TitanWindowsGamepadFilter)
set_target_properties(TitanWindowsGamepadFilter PROPERTIES EXPORT_NAME sdk)
target_compile_features(TitanWindowsGamepadFilter PUBLIC cxx_std_17)
target_compile_definitions(TitanWindowsGamepadFilter PUBLIC )
target_compile_definitions(TitanWindowsGamepadFilter PRIVATE UNICODE _UNICODE NOMINMAX WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0A00)
if(MSVC)
  target_compile_options(TitanWindowsGamepadFilter PRIVATE /utf-8 /EHsc /W4)
endif()
target_include_directories(TitanWindowsGamepadFilter PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/sdk>"
  "$<INSTALL_INTERFACE:include/>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/sdk/InputFilter>"
  "$<INSTALL_INTERFACE:include/InputFilter>"
)
target_link_libraries(TitanWindowsGamepadFilter PUBLIC advapi32 bcrypt cfgmgr32 comctl32 hid newdev ole32 setupapi user32)
install(TARGETS TitanWindowsGamepadFilter EXPORT WindowsGamepadFilterSDKTargets ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY sdk/ DESTINATION include FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp" PATTERN "*.inl")
install(FILES LICENSE DESTINATION share/windows-gamepad-filter)
install(EXPORT WindowsGamepadFilterSDKTargets NAMESPACE WindowsGamepadFilterSDK:: DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/WindowsGamepadFilterSDK)
configure_file("WindowsGamepadFilterSDKConfig.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/WindowsGamepadFilterSDKConfig.cmake" @ONLY)
write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/WindowsGamepadFilterSDKConfigVersion.cmake" VERSION 0.1.0.0 COMPATIBILITY SameMajorVersion)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/WindowsGamepadFilterSDKConfig.cmake" "${CMAKE_CURRENT_BINARY_DIR}/WindowsGamepadFilterSDKConfigVersion.cmake" DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/WindowsGamepadFilterSDK)
