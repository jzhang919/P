cmake_minimum_required (VERSION 3.1)
project (P)
set(projectName Raft)
find_package (Threads)
add_executable(raft
    Raft.c
    Raft.h
    Main.c
    ext_compat.h
    libhandler.h
    libhandler-internal.h
    Prt.h
    PrtConfig.h
    PrtExecution.h
    PrtLinuxUserConfig.h
    PrtProgram.h
    PrtTypes.h
    PrtValues.h
    sal.h)

target_link_libraries(raft ${CMAKE_SOURCE_DIR}/libPrt_static.a ${CMAKE_SOURCE_DIR}/libhandler.a ${CMAKE_THREAD_LIBS_INIT})