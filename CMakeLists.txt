#you need 3.20 suck it up
cmake_minimum_required(VERSION 3.20)
#we need c++17
set(CMAKE_CXX_STANDARD 17)
#heres the stuff about the thing
project (BetterFNFCharter 
    LANGUAGES C CXX
    VERSION 0.0.1
    DESCRIPTION yeah
)
#normal lib files
include_directories(src/lib)
#nana root files
include_directories(src/lib/nana)
#nana subdir files (god i hate you nana)
include_directories(src/lib/nana/audio src/lib/nana/filesystem src/lib/nana/gui src/lib/nana/paint
    src/lib/nana/pat src/lib/nana/system src/lib/nana/threads
    src/lib/nana/audio/detail
    src/lib/nana/gui/detail src/lib/nana/gui/widgets src/lib/nana/gui/widgets src/lib/nana/gui/widgets/detail src/lib/nana/gui/widgets/skeletons
    src/lib/nana/paint/detail)
#c o d e
add_executable(BetterFNFCharter src/BetterFNFCharter.cpp)
#fix for bad bug
set_property(TARGET BetterFNFCharter PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
#nana lib
target_link_libraries(BetterFNFCharter src/lib/nana)
#and copy
install(TARGETS BetterFNFCharter RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/export)