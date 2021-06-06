%****************************************************
% matlab script to focus ERS-2 signal data
close all
clear all
%
% range parameters
%
rng_samp_rate = 1.896e+07;
pulse_dur = 3.71e-05;
chirp_slope = 4.1779e+11;
%
% azimuth parameters
%
PRF=1679.902394;
radar_wavelength=0.0566666;
SC_vel=7125.;
%
% compute the range to the radar reflectors
%
near_range=829924.366;
dr=3.e08/(2.*rng_samp_rate);
range=near_range+2700*dr;
%
% use the doppler centroid estimated from the data and the
% doppler rate from the spacecraft velocity and range
%
fdc=305;
fr=2*SC_vel*SC_vel/(range*radar_wavelength);

[cdata,nrow,ncol] = read_rawsar('E1_25194_STD_L0_F331.000.raw');

map=ones(21,3);
for k=1:21;
level=0.05*(k+8);
level=min(level,1);
map(k,:)=map(k,:).*level;
end
colormap(map);
%
% image the raw data
%
%
%% generate the range reference function
%
[cref,fcref]=range_ref(ncol,rng_samp_rate,pulse_dur,chirp_slope);
%
% take the fft of the SAR data
%
fcdata=fft(cdata);
%
% multiply by the range reference function
%
cout=0.*fcdata;
for k=1:nrow;
ctmp=fcdata(:,k);
ctmp=fcref.*ctmp;
cout(:,k)=ctmp;
end
clear cdata
odata=ifft(cout);
clear cout

%% azimuth compression
%
% generate the azimuth reference function
%
[cazi,fcazi]=azi_ref(nrow,PRF,fdc,fr);
%
% take the column-wise fft of the range-compressed data
%
fcdata=fft(odata');
%
% multiply by the azimuth reference function
%
cout=0.*fcdata;
for k=1:ncol
ctmp=fcdata(:,k);
ctmp=fcazi.*ctmp;
cout(:,k)=ctmp;
end

odata=ifft(cout);
%% final image

ddd = sort(reshape(abs(odata).',1,[]));
c = cumsum(ddd);
index = find(c >= c(end)*0.01,1);
min_value = ddd(index)
index = find(c >= c(end)*0.99,1);
max_value = ddd(index)

figure(1)
imagesc(abs(odata'));
hold on
xlabel('range')
ylabel('azimuth')
title('range and azimuth compressed')
colormap('gray');
caxis([min_value max_value/2.5]);

%%
odata = abs(odata');

scale=10;
final_data = 0;
for i = 0:floor(ncol/scale)*floor(nrow/scale)-1
    koff = (floor(i/floor(nrow/scale)))*scale +1;
    loff = mod(i,floor(nrow/scale))*scale +1;
    sum=0;
    for k = koff:koff+scale
        for l = loff:loff+scale
            sum = sum + odata(k,l);
        end
    end
    final_data((koff-1)/scale +1,(loff-1)/scale +1) = sum/(scale*scale);
end

figure(2)
imagesc(final_data);
hold on
xlabel('range')
ylabel('azimuth')
title('Compressed image')
colormap('gray');
caxis([min_value max_value/2.5]);


