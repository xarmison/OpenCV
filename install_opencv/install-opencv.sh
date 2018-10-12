# 1. KEEP UBUNTU OR DEBIAN UP TO DATE
echo 'Updating and Upgrading ...'
sudo apt-get -y update
sudo apt-get -y upgrade
sudo apt-get -y dist-upgrade
sudo apt-get -y autoremove

# 2. INSTALL THE DEPENDENCIES
echo 'Installing the dependencies ...'

sudo apt-get install -y build-essential cmake build-essential cmake git unzip pkg-config libjpeg-dev libtiff5-dev libjasper-dev libpng12-dev libavcodec-dev libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev libx264-dev libgtk-3-dev libhdf5-serial-dev graphviz libopenblas-dev libatlas-base-dev gfortran python-tk python3-tk python-imaging-tk python2.7-dev python3-dev linux-image-generic linux-image-extra-virtual linux-source linux-headers-generic

#Fix stuff in the cmake directory: https://stackoverflow.com/questions/46584000/cmake-error-variables-are-set-to-notfound?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

# 3. FIXING STUFF FOR CUDA
echo 'Fixing stuff for CUDA ...'


# 4. INSTALL THE LIBRARY (YOU CAN CHANGE '3.3.0' FOR THE LAST STABLE VERSION)
echo 'Installing the library ...'
#sudo apt-get install -y unzip wget
#wget https://github.com/opencv/opencv/archive/3.3.0.zip
#unzip 3.3.0.zip
#rm 3.3.0.zip
#mv opencv-3.3.0 OpenCV
#cd OpenCV
#mkdir build
#cd build
#cmake -D CMAKE_BUILD_TYPE=RELEASE \
#    -D CMAKE_INSTALL_PREFIX=/usr/local \
#    -D WITH_CUDA=ON \
#    -D ENABLE_FAST_MATH=1 \
#    -D CUDA_FAST_MATH=1 \
#    -D WITH_CUBLAS=1 \
#    -D INSTALL_PYTHON_EXAMPLES=ON \
#    -D BUILD_EXAMPLES=ON ..
#make -j8
#sudo make install
#sudo ldconfig
#echo 'Done !'

