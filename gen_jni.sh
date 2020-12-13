if [ -d ./Eyer3rdpart ];then 
    rm -rf Eyer3rdpart
fi

basepath=$(cd `dirname $0`; pwd)
echo ${basepath}

${JAVA_HOME}javac -h ./ ${basepath}/eyer-gb28181-java/eyer-gb28181-java-interface/src/main/java/com/zzsin/eyer/gb28181/CInterface.java -classpath ${basepath}/eyer-gb28181-java/eyer-gb28181-java-interface/src/main/java/

mv ${basepath}/com_zzsin_eyer_gb28181_CInterface.h ${basepath}/EyerGB28181/EyerGB28181Jni/com_zzsin_eyer_gb28181_CInterface.h