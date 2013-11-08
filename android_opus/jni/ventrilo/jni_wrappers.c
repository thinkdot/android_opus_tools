/*
 *modifed by liyong 1011
 */

#include <jni.h>
#include <stdio.h>
#include <string.h>
#include "libventrilo3.h"
inline jclass get_class(JNIEnv* env, jobject obj) {
	return (*env)->GetObjectClass(env, obj);
}

inline jobject get_object(JNIEnv* env, jobject parent_obj, jclass parent_cls, char* name, char* sig) {
	return (*env)->GetObjectField(env, parent_obj, (*env)->GetFieldID(env, parent_cls, name, sig));
}

inline char* get_string(JNIEnv* env, jstring str) {
	return (char*)(*env)->GetStringUTFChars(env, str, 0);
}

inline jbyte* get_byte_array(JNIEnv* env, jbyteArray pcm) {
	jboolean isCopy;
	return (*env)->GetByteArrayElements(env, pcm, &isCopy);
}

inline void release_byte_array(JNIEnv* env, jbyteArray pcm, jbyte* data) {
	(*env)->ReleaseByteArrayElements(env, pcm, data, 0);	
}

inline void release_string(JNIEnv* env, jstring str, char* _str) {
	(*env)->ReleaseStringUTFChars(env, str, _str);
}

inline void set_short(JNIEnv* env, jobject parent_obj, jclass parent_cls, char *name, jshort val) {
	(*env)->SetShortField(env, parent_obj, (*env)->GetFieldID(env, parent_cls, name, "S"), val);	
}

inline void set_byte(JNIEnv* env, jobject parent_obj, jclass parent_cls, char *name, jbyte val) {
	(*env)->SetByteField(env, parent_obj, (*env)->GetFieldID(env, parent_cls, name, "B"), val);	
}

inline void set_int(JNIEnv* env, jobject parent_obj, jclass parent_cls, char *name, jint val) {
	(*env)->SetIntField(env, parent_obj, (*env)->GetFieldID(env, parent_cls, name, "I"), val);	
}

inline void set_bool(JNIEnv* env, jobject parent_obj, jclass parent_cls, char *name, jboolean val) {
	(*env)->SetBooleanField(env, parent_obj, (*env)->GetFieldID(env, parent_cls, name, "Z"), val);	
}

inline void set_byte_array(JNIEnv* env, jobject parent_obj, jclass parent_cls, char* name, jbyteArray data, jint sz) {
	(*env)->SetByteArrayRegion(env, (*env)->GetObjectField(env, parent_obj, (*env)->GetFieldID(env, parent_cls, name, "[B")), 0, sz, data);	
}
//add by liyong 1012
JNIEXPORT void JNICALL Java_org_mangler_android_VentriloInterface_startOpusEncode(JNIEnv* env, jobject obj, jstring input_src, jstring output_src) {
	char* input = get_string(env, input_src);
	char* output = get_string(env, output_src);
	my_opus_encode(input,output);
	release_string(env, input_src, input);
	release_string(env, output_src, output);
}