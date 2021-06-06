close all
clear all

datas = ["E1_25509_STD_L0_F329.000.raw" "E1_25094_STD_L0_F299.000.raw" "E1_25194_STD_L0_F331.000.raw" "E1_25409_STD_L0_F319.000.raw" "E1_25509_STD_L0_F297.000.raw"];
cuts = [1500 400 ; 1800 150 ; 50 50 ; 2130 55 ; 2650 110];
ranges = [2^5 2^5 ; 2^5 2^5 ; 2^5 2^5 ; 2^5 2^5 ; 2^5 2^5];

for i=1:length(datas)
    [final_data,odata] = process_func(datas(i));

    %% Image Create
    scol = cuts(i,1);
    srow = cuts(i,2);
    row0 = ranges(i,1);
    col0 = ranges(i,2);

    c_final_data = final_data(srow:srow+row0-1,scol:scol+col0-1);

    %% Visualization
    ddd = sort(reshape(abs(final_data).',1,[]));
    c = cumsum(ddd);
    index = find(c >= c(end)*0.01,1);
    min_value = ddd(index);
    index = find(c >= c(end)*0.99,1);
    max_value = ddd(index);

    figure(i)

    imagesc(abs(final_data));
    rectangle('Position',[scol srow col0 row0],'EdgeColor','r');
    title('final data');
    colormap('gray');
    caxis([min_value max_value]);
    impixelinfo

    writematrix(c_final_data,sprintf('train_datas/train_data%d.csv',i))
end