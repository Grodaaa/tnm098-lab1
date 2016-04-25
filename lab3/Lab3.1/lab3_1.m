clc
imageData = {imread('01.jpg')};


for k = 2:12
    if k < 10
      jpgFilename = strcat('0', num2str(k), '.jpg');
      imageData{end + 1} = imread(jpgFilename);
    end
    if k >= 10
        jpgFilename = strcat(num2str(k), '.jpg');
        imageData{end + 1} = imread(jpgFilename);
    end
end

%% Cform
cform = makecform('srgb2lab');
lab_image = applycform(imageData{1},cform);
%% 
ab = double(lab_image(:,:,2:3));
nrows = size(ab,1);
ncols = size(ab,2);
ab = reshape(ab,nrows*ncols,2);
%%
nColors = 3;
[cluster_idx, cluster_center] = kmeans(ab, nColors, 'distance', 'sqEuclidean', 'Replicates', 3);
