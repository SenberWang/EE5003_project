cmake_minimum_required(VERSION 3.21)
project(cnn_v1)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers
        D:/Xilinx/Vivado/2019.2/include
        D:/Xilinx/Vivado/2019.2/include/ap_sysc
        D:/Xilinx/Vivado/2019.2/win64/tools/systemc/include
        D:/Xilinx/Vivado/2019.2/include/etc
        D:/Xilinx/Vivado/2019.2/win64/tools/auto_cc/include
        )


add_executable(cnn_v1
        main.cpp
        global_controller.cpp global_vars.h
        PE.cpp PE.h
        ALU.cpp ALU.h
        register_file.cpp register_file.h
        decoder.cpp decoder.h
        spike_scheduler.cpp spike_scheduler.h
        output_mem.cpp output_mem.h
        misc.cpp misc.h
        cluster_scheduler.cpp cluster_scheduler.h
        weight_init.cpp weight_init.h
        potential_init.cpp potential_init.h
        executer.cpp executer.h
        cluster_0.cpp cluster_0.h
        cluster_1.cpp cluster_1.h
        cluster_2.cpp cluster_2.h
        cluster_3.cpp cluster_3.h
        cluster_4.cpp cluster_4.h
        cluster_5.cpp cluster_5.h
        )
