from scipy.io import loadmat
import numpy as np

#load matlab data
cnn = loadmat("./cnn_99.14.mat")
#open and write files
f = open("./cnn_weight_c1.txt", "w")
fb = open("./cnn_weight_c1.bin", "wb+")

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

#close files
f.close()
fb.close()

print("done")