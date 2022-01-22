include(FetchContent)
FetchContent_Declare(kydeps_definitions
    GIT_REPOSITORY https://github.com/kydeps/definitions.git
    GIT_TAG main
)
FetchContent_MakeAvailable(kydeps_definitions)

SetInParent(CMAKE_PREFIX_PATH)