from scipy.io import loadmat
import numpy as np

#load matlab data
cnn = loadmat("./cnn_99.14.mat")
#open and write files
f = open("./cnn_weight_c3_1.txt", "w")
fb = open("./cnn_weight_c3_1.bin", "wb+")

#-------------------------for cluster2--------------------------------
kernel_c3 = cnn['cnn'][0,0]['layers'][3,0]['k'][0][0]
idx_offset = 0
for idx_pe in range(0, 4):
    idx_kernel_real=0
    for idx_kernel in range (0, 8):
        for idx_ifm in range(0, 12):
            for idx_row in range(0, 5):
                for idx_col in range(0, 5):
                    kernel_element_float = kernel_c3[0,idx_ifm][0,idx_pe *
                                                                    8 + idx_kernel + idx_offset][4 - idx_row,4 - idx_col]
                    kernel_element_fixed = int(
                        (kernel_element_float * (2 ** 22)))

                    #convert data
                    kernel_element_byte = kernel_element_fixed.to_bytes(
                        length=4, byteorder='little', signed=True)
                    kernel_element_byte_txt = kernel_element_fixed.to_bytes(
                        length=4, byteorder='big', signed=True)
                    
                    #write data
                    f.write("WeightMemPE_%d[%d] = 0x%s;        //Clst[2] %f \n" % (
                        idx_pe, idx_kernel_real, kernel_element_byte_txt.hex(), kernel_element_float))
                    fb.write(kernel_element_byte)
                    
                    idx_kernel_real += 1

    f.write("\n")

#close files
f.close()
fb.close()

#-------------------------for cluster3--------------------------------
#open and write files
f = open("./cnn_weight_c3_2.txt", "w")
fb = open("./cnn_weight_c3_2.bin", "wb+")

idx_offset = 32
for idx_pe in range(0, 4):
    idx_kernel_real = 0
    for idx_kernel in range(0, 8):
        for idx_ifm in range(0, 12):
            for idx_row in range(0, 5):
                for idx_col in range(0, 5):
                    kernel_element_float = kernel_c3[0,idx_ifm][0,idx_pe *
                                                                    8 + idx_kernel + idx_offset][4 - idx_row,4-idx_col]
                    kernel_element_fixed = int(
                        (kernel_element_float * (2 ** 22)))

                    #convert data
                    kernel_element_byte = kernel_element_fixed.to_bytes(
                        length=4, byteorder='little', signed=True)
                    kernel_element_byte_txt = kernel_element_fixed.to_bytes(
                        length=4, byteorder='big', signed=True)

                    #write data
                    f.write("WeightMemPE_%d[%d] = 0x%s;        //Clst[3] %f \n" % (
                        idx_pe, idx_kernel_real, kernel_element_byte_txt.hex(), kernel_element_float))
                    fb.write(kernel_element_byte)

                    idx_kernel_real += 1

    f.write("\n")

#close files
f.close()
fb.close()

print("done")