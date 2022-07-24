TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE inc)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE
        src/core.S
        src/exception.c
        src/memory.c
        src/process.c
        src/system.c)
