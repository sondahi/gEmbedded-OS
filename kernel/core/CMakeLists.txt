TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE include)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE
        src/exception.c
        src/memory.S
        src/mode.S
        src/startup.S
        src/system.c
        src/vectors.S)
