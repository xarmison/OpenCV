# 1. KEEP UBUNTU OR DEBIAN UP TO DATE
echo 'Updating and Upgrading ...'
sudo apt-get -y update
sudo apt-get -y upgrade
sudo apt-get -y dist-upgrade
sudo apt-get -y autoremove

# 2. INSTALL THE DEPENDENCIES
echo 'Installing the dependencies ...'

sudo apt-get install -y build-essential cmake build-essential cmake git unzip pkg-config libjpeg-dev libtiff5-dev libjasper-dev libpng12-dev libavcodec-dev libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev libx264-dev libgtk-3-dev libhdf5-serial-dev graphviz libopenblas-dev libatlas-base-dev gfortran python-tk python3-tk python-imaging-tk python2.7-dev python3-dev linux-image-generic linux-image-extra-virtual linux-source linux-headers-generic unzip wget qt5-default

# 4. INSTALL THE LIBRARY (YOU CAN CHANGE '3.3.0' FOR THE LAST STABLE VERSION)
echo 'Installing the library ...'

wget https://github.com/opencv/opencv/archive/3.3.0.zip
unzip 3.3.0.zip
rm 3.3.0.zip

wget https://github.com/opencv/opencv_contrib/archive/3.3.0.zip
unzip 3.3.0.zip
rm 3.3.0.zip

cd opencv-3.3.0

echo 'Fixing stuff for CUDA ...'
wget https://raw.githubusercontent.com/vanluwin/OpenCV/master/install_opencv/FindCUDA.cmake -O cmake/FindCUDA.cmake

wget https://raw.githubusercontent.com/vanluwin/OpenCV/master/install_opencv/OpenCVDetectCUDA.cmake -O cmake/OpenCVDetectCUDA.cmake

wget https://raw.githubusercontent.com/vanluwin/OpenCV/master/install_opencv/common.hpp -O modules/cudev/include/opencv2/cudev/common.hpp

mkdir build
cd build

cmake -D CMAKE_BUILD_TYPE=RELEASE \
    -D CMAKE_INSTALL_PREFIX=/usr/local \
    -D WITH_CUDA=ON \
    -D ENABLE_FAST_MATH=1 \
    -D CUDA_FAST_MATH=1 \
    -D WITH_CUBLAS=1 \
    -D WITH_QT=1 \
    -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-3.3.0/modules/ ..

make -j8
sudo make install
sudo ldconfig
echo 'Done !'

