from scipy.io import loadmat
import numpy as np

#load matlab data
cnn = loadmat("./cnn_99.14.mat")
#open and write files
f = open("./cnn_weight_1.txt", "w")
fb = open("./cnn_weight_1.bin", "wb+")

#-------------------------for cluster0(c1)-------------------------------------------------
kernel_c1 = cnn['cnn'][0,0]['layers'][1,0]['k'][0,0][0,0]
for idx_kernel in range (0, 12):
    for idx_row in range(0, 5):
        for idx_col in range(0, 5):
            kernel_element_float = kernel_c1[0,idx_kernel][4 -idx_row,4-idx_col]
            
            kernel_element_fixed = int((kernel_element_float * (2 ** 22)))
            
            #convert data
            kernel_element_byte = kernel_element_fixed.to_bytes(
                length=4, byteorder='little', signed=True)
            kernel_element_byte_txt = kernel_element_fixed.to_bytes(
                length=4, byteorder='big', signed=True)
            
            #Three kernels in one PE
            idx_in_pe = idx_kernel % 3
            #Four PEs in total
            idx_pe = idx_kernel / 3

            #write data
            f.write("WeightMemPE_%d[%d] = 0x%s; " % 
                    (idx_pe, idx_row*5 + idx_col + idx_in_pe*25, kernel_element_byte_txt.hex()))
            f.write("   //kernel[%d], row: %d, col: %d \n" %
                (idx_kernel, idx_row, idx_col))        
            fb.write(kernel_element_byte)
    #next kernel
    f.write("\n")

#-------------------------for cluster2(c3)-------------------------------------------------
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

#-------------------------for cluster3(c3)-------------------------------------------
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

#-------------------------for cluster5(out layer)--------------------------------
ffw = cnn['cnn'][0,0]['ffW']
for idx_row in range (0, 10): 
    for idx_col in range (0, 1024):
        weight_cur_float = ffw[idx_row,idx_col]
        weight_cur_fixed = int((weight_cur_float * (2 ** 22)))
        
        #convert data
        weight_cur_byte = weight_cur_fixed.to_bytes(
            length=4, byteorder='little', signed=True)
        weight_cur_byte_txt = weight_cur_fixed.to_bytes(
            length=4, byteorder='big', signed=True)
        
        #write data
        f.write("WeightMemPE_0[%d] = 0x%s;        //[5] \n" % (
            idx_row*1024 + idx_col, weight_cur_byte_txt.hex()))
        fb.write(weight_cur_byte)
#--------------------------------------------------------------------------------       
#close files
f.close()
fb.close()

print("done")