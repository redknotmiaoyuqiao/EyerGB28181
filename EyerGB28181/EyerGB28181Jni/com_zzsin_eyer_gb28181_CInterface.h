/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_zzsin_eyer_gb28181_CInterface */

#ifndef _Included_com_zzsin_eyer_gb28181_CInterface
#define _Included_com_zzsin_eyer_gb28181_CInterface
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_zzsin_eyer_gb28181_CInterface
 * Method:    eyer_gb_get_version
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1get_1version
  (JNIEnv *, jclass);

/*
 * Class:     com_zzsin_eyer_gb28181_CInterface
 * Method:    eyer_gb_gbserver_init
 * Signature: (I)J
 */
JNIEXPORT jlong JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1init
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_zzsin_eyer_gb28181_CInterface
 * Method:    eyer_gb_gbserver_uninit
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1uninit
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_zzsin_eyer_gb28181_CInterface
 * Method:    eyer_gb_gbserver_start
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1start
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_zzsin_eyer_gb28181_CInterface
 * Method:    eyer_gb_gbserver_stop
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1stop
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_zzsin_eyer_gb28181_CInterface
 * Method:    eyer_gb_gbserver_set_passive_callback
 * Signature: (JLcom/zzsin/eyer/gb28181/callback/PassiveCallback;)I
 */
JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1set_1passive_1callback
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_zzsin_eyer_gb28181_CInterface
 * Method:    eyer_gb_gbserver_get_device_list
 * Signature: (JLcom/zzsin/eyer/gb28181/callback/GBDeviceList;)I
 */
JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1get_1device_1list
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_zzsin_eyer_gb28181_CInterface
 * Method:    eyer_gb_gbserver_catalog
 * Signature: (JLjava/lang/String;Lcom/zzsin/eyer/gb28181/callback/CatalogCallback;)I
 */
JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1catalog
  (JNIEnv *, jclass, jlong, jstring, jobject);

#ifdef __cplusplus
}
#endif
#endif
