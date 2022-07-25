TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE inc)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE
        src/core.S
        src/exception.c
        src/memory.c
        src/memory.S
        src/process.c
        src/process.S
        src/system.c)
