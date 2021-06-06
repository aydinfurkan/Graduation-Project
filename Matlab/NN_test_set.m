close all
clear all

datas = ["E1_25194_STD_L0_F331.000.raw" "E1_25409_STD_L0_F319.000.raw" "E1_25509_STD_L0_F329.000.raw"];

for i=1:length(datas)
    [final_data,odata] = process_func(datas(i));

    %% Visualization
    ddd = sort(reshape(abs(final_data).',1,[]));
    c = cumsum(ddd);
    index = find(c >= c(end)*0.01,1);
    min_value = ddd(index);
    index = find(c >= c(end)*0.99,1);
    max_value = ddd(index);

    figure(i)

    imagesc(abs(final_data));
    title('final data');
    colormap('gray');
    caxis([min_value max_value]);
    impixelinfo
    
    writematrix(final_data,sprintf('test_datas/test_data%d.csv',i))
end