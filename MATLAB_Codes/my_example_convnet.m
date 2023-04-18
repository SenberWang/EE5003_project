clear;
clc;
%% Train an example ConvNet to achieve very high classification, fast.
%    Load paths
addpath(genpath('./dlt_cnn_map_dropout_nobiasnn'));
%% Load data
rand('state', 1);
load mnist_uint8;
train_x = double(reshape(train_x',28,28,60000)) / 255;
test_x = double(reshape(test_x',28,28,10000)) / 255;
train_y = double(train_y');
test_y = double(test_y');
% Initialize net
cnn.layers = {
    struct('type', 'i') %input layer
    struct('type', 'c', 'outputmaps', 16, 'kernelsize', 5) %convolution layer
    struct('type', 's', 'scale', 2) %sub sampling layer
    struct('type', 'c', 'outputmaps', 16, 'kernelsize', 5) %convolution layer
    struct('type', 's', 'scale', 2) %subsampling layer
};
cnn = cnnsetup(cnn, train_x, train_y);
% Set the activation function to be a ReLU
cnn.act_fun = @(inp)max(0, inp);
% Set the derivative to be the binary derivative of a ReLU
cnn.d_act_fun = @(forward_act)double(forward_act>0);
%% load exist data (add by senber)
load cnn_99.14.mat;
%% Personal settings (add by senber)
target_img = 1;
target_tsp = 40;
%% Spike-based Testing of a ConvNet
t_opts = struct;
t_opts.t_ref        = 0.000;
t_opts.threshold    =   1.0;
t_opts.dt           = 0.001;
t_opts.duration     = 0.001 * target_tsp;    
t_opts.report_every = 0.001;
t_opts.max_rate     = 400;
cnn = convlifsim(cnn, test_x, test_y, t_opts);
fprintf('Done.\n');

%% L1 input spike
% temp_spike_l1 = cnn.layers{1,1}.spikes{1,1}(:,:,target_img);
% [id_m_s_in,id_n_s_in]=find (temp_spike_l1==1);
% [temp_spike_l1_num, unused] = size(id_m_s_in);

%% L2 potetial
% temp_potential_c1 = zeros(24,24,12);
% for i=1:12
%     temp_potential_c1(:,:,i) = cnn.layers{2,1}.mem{1,i}(:,:,target_img);
% end
%L2 spike
% temp_spike_c1_idxx = zeros(576,12);
% temp_spike_c1_idxy = zeros(576,12);
% temp_spike_c1_num = zeros(1,12);
% 
% for idx_c1_spike = 1:1:12
%     temp_spike_c1{1,idx_c1_spike} = cnn.layers{2,1}.spikes{1,idx_c1_spike}(:,:,1);
%     [id_m_s_c1,id_n_s_c1]=find (temp_spike_c1{1,idx_c1_spike}==1);
%     [temp_spike_c1_num_cur, unused] = size(id_m_s_c1);
%     temp_spike_c1_num(1,idx_c1_spike) = temp_spike_c1_num_cur;
%     for idx_c1_spike_id = 1:1:temp_spike_c1_num_cur
%         temp_spike_c1_idxx(idx_c1_spike_id,idx_c1_spike) = id_m_s_c1(idx_c1_spike_id,1);
%         temp_spike_c1_idxy(idx_c1_spike_id,idx_c1_spike) = id_n_s_c1(idx_c1_spike_id,1);
%     end
% end

%% L3 potential
% temp_potential_s2 = zeros(12,12,12);
% for i=1:12
%     temp_potential_s2(:,:,i) = cnn.layers{3,1}.mem{1,i}(:,:,target_img);
% end
%L3 spike
% for i=1:12
%     temp_spike_s2{1,i} = cnn.layers{3,1}.spikes{1,i}(:,:,target_img);
% 
%     [idm,idn]=find (temp_spike_s2{1,i}==1);
%     [idmax, unused] = size(idm);
%     temp_spike_s2_num(1,i) = idmax;
%     for j = 1:1:idmax
%         temp_spike_s2_idxx(j,i) = idm(j,1);
%         temp_spike_s2_idxy(j,i) = idn(j,1);
%     end
% end

%% L4 potential
% temp_potential_c3 = zeros(8,8,64);
% for i=1:64
%     temp_potential_c3(:,:,i) = cnn.layers{4,1}.mem{1,i}(:,:,target_img);
% end
% %L4 spike
% for i=1:64
%     temp_spike_c3{1,i} = cnn.layers{4,1}.spikes{1,i}(:,:,target_img);
% 
%     [idm,idn]=find (temp_spike_c3{1,i}==1);
%     [idmax, unused] = size(idm);
%     temp_spike_c3_num(1,i) = idmax;
%     for j = 1:1:idmax
%         temp_spike_c3_idxx(j,i) = idm(j,1);
%         temp_spike_c3_idxy(j,i) = idn(j,1);
%     end
% end

%% L5 potential
% temp_potential_s4 = zeros(4,4,64);
% for i=1:64
%     temp_potential_s4(:,:,i) = cnn.layers{5,1}.mem{1,i}(:,:,target_img);
% end
%% Output
% cnn_input_spike.idxx = cnn.inspk_0_idxx;
% cnn_input_spike.idxy = cnn.inspk_0_idxy;
% cnn_input_spike.num = cnn.inspk_0_num;