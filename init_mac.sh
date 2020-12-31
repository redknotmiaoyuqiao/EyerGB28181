if [ -d ./Eyer3rdpart ];then 
    rm -rf Eyer3rdpart
fi

basepath=$(cd `dirname $0`; pwd)
echo ${basepath}

# sudo apt-get install nasm
# sudo apt-get install yasm

git clone https://gitee.com/redknot/Eyer3rdpart

chmod -R 777 Eyer3rdpart


cd ${basepath}/Eyer3rdpart/libosip2-5.2.0
./configure --prefix=${basepath}/Eyer3rdpart/libosip2-5.2.0/libosip2_install --enable-static --enable-shared
make clean
make -j4
make install


cd ${basepath}/Eyer3rdpart/libexosip2-5.2.0
./configure \
--enable-static \
--enable-shared \
--libdir="${basepath}/Eyer3rdpart/libosip2-5.2.0/libosip2_install/lib" \
--includedir="${basepath}/Eyer3rdpart/libosip2-5.2.0/libosip2_install/include" \
--prefix="${basepath}/Eyer3rdpart/libexosip2-5.2.0/libexosip2_install"

make clean
make -j4
make install

cd ${basepath}/Eyer3rdpart/tinyxml2-8.0.0
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=../tinyxml_install -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_STATIC_LIBS:BOOL=ON ../
make clean
make
make install


:<<!

!

cd ${basepath}

if [ -d ./Lib ];then
    rm -rf Lib
fi

mkdir Lib

cp -r Eyer3rdpart/libosip2-5.2.0/libosip2_install Lib/libosip2_install
cp -r Eyer3rdpart/libexosip2-5.2.0/libexosip2_install Lib/libexosip2_install
cp -r Eyer3rdpart/tinyxml2-8.0.0/tinyxml_install Lib/tinyxml_install