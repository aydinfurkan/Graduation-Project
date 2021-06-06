close all
clear all

%% Read Weights

for i=1:15
    weights(i) = csvread(sprintf('weights%d.csv',(i-1)));
end

[final_data,odata] = process_func('E1_25509_STD_L0_F329.000.raw');

%% Cut Image

scol = 1200;
srow = 400;
col0 = 2^8;
row0 = 2^6;

c_final_data = final_data(srow:srow+row0-1,scol:scol+col0-1);

%% Visualization

ddd = sort(reshape(abs(final_data).',1,[]));
c = cumsum(ddd);
index = find(c >= c(end)*0.01,1);
min_value = ddd(index);
index = find(c >= c(end)*0.99,1);
max_value = ddd(index);

subplot(1,2,1)

imagesc(abs(final_data));
rectangle('Position',[scol srow col0 row0],'EdgeColor','r');
colormap('gray');
caxis([min_value max_value]);
impixelinfo

subplot(1,2,2)
imagesc(abs(c_final_data));
colormap('gray');
caxis([min_value max_value]);
impixelinfo

%% Create Stream
cutted_data = abs(c_final_data);
for i = 1:col0
    data_stream((i-1)*row0+1:i*row0) = cutted_data(1:row0,i);
end
sample_size = size(data_stream,2);