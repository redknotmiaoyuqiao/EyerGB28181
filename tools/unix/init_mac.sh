cd ../../

basepath=$(cd `dirname $0`; pwd)
echo ${basepath}

if [ -d ./Eyer3rdpart ];then 
    rm -rf Eyer3rdpart
fi

git clone https://gitee.com/redknot/Eyer3rdpart

chmod -R 777 Eyer3rdpart

cd ${basepath}/Eyer3rdpart/libosip2-5.2.1
./configure --prefix=${basepath}/Eyer3rdpart/libosip2-5.2.1/libosip2_install --enable-static --disable-shared

make clean
make -j4
make install


cd ${basepath}/Eyer3rdpart/libexosip2-5.2.1
./configure \
--enable-static \
--disable-shared \
--libdir="${basepath}/Eyer3rdpart/libosip2-5.2.1/libosip2_install/lib" \
--includedir="${basepath}/Eyer3rdpart/libosip2-5.2.1/libosip2_install/include" \
--prefix="${basepath}/Eyer3rdpart/libexosip2-5.2.1/libexosip2_install"

make clean
make -j4
make install


cd ${basepath}/Eyer3rdpart/c-ares-1.17.1
./configure \
--prefix=${basepath}/Eyer3rdpart/c-ares-1.17.1/c_ares_install \
--enable-static \
--enable-shared

# autoreconf -ivf

make clean
make -j4
make install


cd ${basepath}

if [ -d ./Lib ];then
    rm -rf Lib
fi

mkdir Lib

cp -r Eyer3rdpart/libosip2-5.2.1/libosip2_install Lib/libosip2_install
cp -r Eyer3rdpart/libexosip2-5.2.1/libexosip2_install Lib/libexosip2_install
cp -r Eyer3rdpart/c-ares-1.17.1/c_ares_install Lib/c_ares_install