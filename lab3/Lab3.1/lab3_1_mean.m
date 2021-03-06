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

%% for-loop mean
clc

mean = [1,3];
mean(1,1) = mean2(imageData{1}(:,:,1));
mean(1,2) = mean2(imageData{1}(:,:,2));
mean(1,3) = mean2(imageData{1}(:,:,3));

imageDataMean = {mean};

for k = 2:12
    mean(1,1) = mean2(imageData{k}(:,:,1));
    mean(1,2) = mean2(imageData{k}(:,:,2));
    mean(1,3) = mean2(imageData{k}(:,:,3));
    
    imageDataMean{end + 1} = mean;
end

%% Choose img 1
clc
delta = zeros(12,6);

for k = 1:12
    delta(k,1) = abs(double(imageDataMean{8}(1)) - double(imageDataMean{k}(1)));
    delta(k,2) = abs(double(imageDataMean{8}(2)) - double(imageDataMean{k}(2)));
    delta(k,3) = abs(double(imageDataMean{8}(3)) - double(imageDataMean{k}(3)));
    delta(k,6) = k;
end

%%
hsv = rgb2hsv(imageData{1});
lumi = {hsv(:,:,3)};

imshow(lumi{1});

for k = 2:12 
    hsv = rgb2hsv(imageData{k});
    lumi{end + 1} = hsv(:,:,3);
end

%%
clc
meanGray = mean2(lumi{1});

grayDataMean = {meanGray};

for k = 2:12
    meanGray = mean2(lumi{k});    
    
    grayDataMean{end + 1} = meanGray;
end

%%
clc

for k = 1:12
    delta(k,4) = abs(double(grayDataMean{8}) - double(grayDataMean{k}));
    delta(k,5) = (delta(k,1) + delta(k,2) + delta(k,3) + delta(k,5)*100)/4;
end

%%
D = sortrows(delta, 5);
bar(delta(:,5))


