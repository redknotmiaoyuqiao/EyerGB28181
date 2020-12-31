if [ -d ./Eyer3rdpart ];then 
    rm -rf Eyer3rdpart
fi

basepath=$(cd `dirname $0`; pwd)
echo ${basepath}

# sudo apt-get install nasm
# sudo apt-get install yasm

git clone https://gitee.com/redknot/Eyer3rdpart

chmod -R 777 Eyer3rdpart


cd ${basepath}/Eyer3rdpart/c-ares-1.17.1
./configure --prefix=${basepath}/Eyer3rdpart/c-ares-1.17.1/c_ares_install --enable-static --enable-shared
# ./configure --enable-static --enable-shared
make clean
make -j4
make install


echo "+"
echo "+"
echo "+"
echo "+"
echo "++++++++++++++++++++++++++++++++++++++++++++++++++"
echo "+"
echo "+"
echo "+"
echo "+"



cd ${basepath}/Eyer3rdpart/libosip2-5.0.0
./configure --prefix=${basepath}/Eyer3rdpart/libosip2-5.0.0/libosip2_install --enable-static --enable-shared
autoreconf -ivf
# ./configure --enable-static --enable-shared
# autoreconf -ivf
make clean
make -j4
make install


echo "+"
echo "+"
echo "+"
echo "+"
echo "++++++++++++++++++++++++++++++++++++++++++++++++++"
echo "+"
echo "+"
echo "+"
echo "+"



cp -r ${basepath}/Eyer3rdpart/libosip2-5.0.0/libosip2_install/include/osip2 ${basepath}/Eyer3rdpart/libexosip2-5.0.0/include/osip2
cp -r ${basepath}/Eyer3rdpart/libosip2-5.0.0/libosip2_install/include/osipparser2 ${basepath}/Eyer3rdpart/libexosip2-5.0.0/include/osipparser2
cd ${basepath}/Eyer3rdpart/libexosip2-5.0.0
mkdir libexosip2_install

cp -r ${basepath}/Eyer3rdpart/libosip2-5.0.0/libosip2_install/lib ${basepath}/Eyer3rdpart/libexosip2-5.0.0/libexosip2_install/lib


cd ${basepath}/Eyer3rdpart/libexosip2-5.0.0
./configure --prefix=${basepath}/Eyer3rdpart/libexosip2-5.0.0/libexosip2_install --enable-static --enable-shared
# ./configure --enable-static --enable-shared
# autoreconf -ivf
make clean
make -j4
make install


cd ${basepath}

if [ -d ./Lib ];then
    rm -rf Lib
fi

mkdir Lib

cp -r Eyer3rdpart/libosip2-5.0.0/libosip2_install Lib/libosip2_install
cp -r Eyer3rdpart/libexosip2-5.0.0/libexosip2_install Lib/libexosip2_install
cp -r Eyer3rdpart/c-ares-1.17.1/c_ares_install Lib/c_ares_install