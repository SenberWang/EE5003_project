from scipy.io import loadmat
import numpy as np

#open and write files
f = open("./cnn_spike_all_pic.txt", "w")
fb = open("./cnn_spike_all_pic.bin", "wb+")

#load maltab data
cnn_input_spike = loadmat("./cnn_input_spike.mat")
spike_num = cnn_input_spike['cnn'][0][0]['spike_num']
spike_idxx = cnn_input_spike['cnn'][0][0]['spike_idxx']
spike_idxy = cnn_input_spike['cnn'][0][0]['spike_idxy']

base_addr=0x70000000
addr_offset=0
for idx_pic in range(0,50):
    instr_offset = 0
    cnt=0
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
            fb.write(spike_format_byte)

            cnt += 1
            
    instr_offset = instr_offset + num_spike_cur_time

    # base_addr = base_addr + addr_offset
    # base_addr_byte=base_addr.to_bytes(
    #             length=4, byteorder='big', signed=True)
    # f.write("0x%s, \n" %(base_addr_byte.hex()))

    # f.write("%d, \n" %(cnt))
    
    # addr_offset = 4*cnt
#close files
f.close()
fb.close()

print("done")