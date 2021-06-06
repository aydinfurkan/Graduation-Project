close all
clear all

load('yeniref.mat')

Range_frame_length = 64;
Azimuth_frame_length = 64;


%% Read raw data
[cdata,nrow,ncol] = read_rawsar('E1_25194_STD_L0_F331.000.raw');

%% Image Create
srow = 1000;
scol = 10000;
row0 = 2^8;
col0 = 2^8;

cdata0 = cdata(srow:srow+row0-1,scol:scol+col0-1);

%% New ref function generate
fcref = fcref(srow:srow+row0-1);
fcazi = fcazi(scol:scol+col0-1);

%% Visualization
figure(1)

subplot(1,2,1)
imagesc(abs(cdata));
hold on;
rectangle('Position',[scol srow col0 row0],'EdgeColor','r');
title('unfocussed raw data');

subplot(1,2,2)
imagesc(abs(cdata0));
title('unfocussed new raw data');

%% Generate stream to Simulink

for i = 1:col0
    SAR_core_data_stream((i-1)*row0+1:i*row0) = cdata0(1:row0,i);
end

SAR_core_data_real_stream = real(SAR_core_data_stream);
SAR_core_data_imag_stream = imag(SAR_core_data_stream);

%% vector for 8 bits
for i = 0:8191
    SAR_core_data_stream_vector(i+1,1:8) = SAR_core_data_stream(i*8+1:i*8+8);
end

SAR_core_data_real_stream_vector = real(SAR_core_data_stream_vector);
SAR_core_data_imag_stream_vector = imag(SAR_core_data_stream_vector);

%% Range Simulink
%% Range

fcdata=fft(cdata0);
cout=0.*fcdata;
for k=1:col0
ctmp=fcdata(:,k);
ctmp=fcref.*ctmp;
cout(:,k)=ctmp;
end
odata=ifft(cout);

%% Verify Simulink Results 

for i = 1:col0
    for f = 1:row0/Range_frame_length
        Range_results_re_matrix((f-1)*Range_frame_length+1:f*Range_frame_length,i) = out.Range_results_re((i-1)*row0+(f-1)*Range_frame_length+1:(i-1)*row0+(f)*Range_frame_length);
    end
end

for i = 1:col0
    for f = 1:row0/Range_frame_length
        Range_results_im_matrix((f-1)*Range_frame_length+1:f*Range_frame_length,i) = out.Range_results_im((i-1)*row0+(f-1)*Range_frame_length+1:(i-1)*row0+(f)*Range_frame_length);
    end
end

Range_results_final_matrix = complex(Range_results_re_matrix,Range_results_im_matrix);

Range_result_error = mean((abs(odata)-abs(Range_results_final_matrix))/abs(odata),'all') * 100

figure(1)
imagesc(abs(Range_results_final_matrix));
xlabel('range')
ylabel('azimuth')
title('simulink range result')

%% Generate stream to Simulink

Range_results_final_matrix_T = double(Range_results_final_matrix');

for i = 1:col0
    Range_results_data_stream((i-1)*row0+1:i*row0) = Range_results_final_matrix_T(1:row0,i);
end

Range_results_data_real_stream = real(Range_results_data_stream);
Range_results_data_imag_stream = imag(Range_results_data_stream);

%% Azimuth Simulink
%% Azimuth

fcdata=fft(odata');
cout=0.*fcdata;
for k=1:row0
ctmp=fcdata(:,k);
ctmp=fcazi.*ctmp;
cout(:,k)=ctmp;
end

odata=ifft(cout);

%% Verify Simulink Results 

for i = 1:col0
    for f = 1:row0/Azimuth_frame_length
        Azimuth_results_re_matrix((f-1)*Azimuth_frame_length+1:f*Azimuth_frame_length,i) = out.Azimuth_results_re((i-1)*row0+(f-1)*Azimuth_frame_length+1:(i-1)*row0+(f)*Azimuth_frame_length);
    end
end

for i = 1:col0
    for f = 1:row0/Azimuth_frame_length
        Azimuth_results_im_matrix((f-1)*Azimuth_frame_length+1:f*Azimuth_frame_length,i) = out.Azimuth_results_im((i-1)*row0+(f-1)*Azimuth_frame_length+1:(i-1)*row0+(f)*Azimuth_frame_length);
    end
end

Azimuth_results_final_matrix = complex(Azimuth_results_re_matrix,Azimuth_results_im_matrix);

Azimuth_result_error = mean((abs(odata)-abs(Azimuth_results_final_matrix))/abs(odata),'all') * 100

figure(1)
imagesc(abs(Azimuth_results_final_matrix));
xlabel('range')
ylabel('azimuth')
title('simulink range-azimuth result')

figure(2)
imagesc(abs(odata));
xlabel('range')
ylabel('azimuth')
title('matlab range-azimuth result')
