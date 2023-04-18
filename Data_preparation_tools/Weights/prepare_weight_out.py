from scipy.io import loadmat
import numpy as np

cnn = loadmat("./cnn_99.14.mat")
ffw = cnn['cnn'][0,0]['ffW']

f = open("./cnn_weight_out.txt", "w")
fb = open("./cnn_weight_out.bin", "wb+")

for idx_row in range (0, 5): 
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

for idx_row in range (5, 10): 
    for idx_col in range (0, 1024):
        weight_cur_float = ffw[idx_row,idx_col]
        weight_cur_fixed = int((weight_cur_float * (2 ** 22)))
        
        #convert data
        weight_cur_byte = weight_cur_fixed.to_bytes(
            length=4, byteorder='little', signed=True)
        weight_cur_byte_txt = weight_cur_fixed.to_bytes(
            length=4, byteorder='big', signed=True)
        
        #write data
        f.write("WeightMemPE_1[%d] = 0x%s;        //[5] \n" % (
            idx_row*1024 + idx_col-5120, weight_cur_byte_txt.hex()))
        fb.write(weight_cur_byte)
#close files
f.close()
fb.close()

print("done")