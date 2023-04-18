from scipy.io import loadmat
import numpy as np

#open and write files
f = open("./cnn_spike_one_pic.txt", "w")
fb = open("./cnn_spike_one_pic.bin", "wb+")

#load maltab data
cnn_input_spike = loadmat("./cnn_input_spike.mat")
spike_num = cnn_input_spike['cnn'][0][0]['spike_num']
spike_idxx = cnn_input_spike['cnn'][0][0]['spike_idxx']
spike_idxy = cnn_input_spike['cnn'][0][0]['spike_idxy']

instr_offset = 0
idx_pic = 0
#input spikes for 40 timesteps of one picture
for cur_timestep in range(0,15):
    #number of spikes for current timestep
    num_spike_cur_time = spike_num[0,idx_pic][0,cur_timestep]
    #locations for each spike
    for idx_spike in range(0, num_spike_cur_time):
        row_val = spike_idxx[0,idx_pic][idx_spike,cur_timestep] - 1
        col_val = spike_idxy[0,idx_pic][idx_spike,cur_timestep] - 1
        cur_time = cur_timestep + 1
        #Convert to 32-bit data format
        spike_format = int(cur_time*(2 ** 24) + row_val*(2**5) + col_val)
        
        spike_format_byte = spike_format.to_bytes(
            length=4, byteorder='little', signed=True)
        spike_format_byte_txt = spike_format.to_bytes(
            length=4, byteorder='big', signed=True)
        #write data to files
        f.write("SpikeMemPkg->SpikeMem[0][%d] = 0x%s; " %
                (idx_spike + instr_offset, spike_format_byte_txt.hex()))
        f.write("   //picture: %d, timestep: %d, row: %d, col: %d \n" %
                (idx_pic, cur_time, row_val, col_val))
        fb.write(spike_format_byte)
    instr_offset = instr_offset + num_spike_cur_time

#close files
f.close()
fb.close()

print("done")