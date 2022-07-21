TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE include)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE
        src/core.S
        src/exception.c
        src/memory.S
        src/process.c
        src/system.c
        src/time.c
        src/test.c)
