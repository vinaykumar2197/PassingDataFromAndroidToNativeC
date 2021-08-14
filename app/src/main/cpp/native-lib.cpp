#include <jni.h>
#include <string>

using namespace std;


//getting data from JNI
extern "C" JNIEXPORT jstring JNICALL
Java_com_vinay_passingdatafromandroidtoc_Utility_NativeMethods_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    printf("Inside string from JNI");
    string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


//passing data to JNI
//double[] tmpArray = {1, 2, 3};
//int tmpInt = 1;
//float tmpFloat = 2.3f;
extern "C" JNIEXPORT jstring JNICALL
Java_com_vinay_passingdatafromandroidtoc_Utility_NativeMethods_passingDataToJni(
        JNIEnv* env,
        jobject tempInstance,
        jdoubleArray tempArray,
        jint tempInt,
        jfloat tempFloat) {
    printf("Inside passing data from JNI");
//    string hello = "Hello from C++";
    jdouble *tmpArray = env->GetDoubleArrayElements(tempArray,NULL);
    int ret = 0;
    if(tmpArray[0] == 1 && tmpArray[1] == 1 && tmpArray[2] == 1 && tempInt == 1){
        ret = 0;
    }
    else{
        ret = -1;
    }
//    env->ReleaseDoubleArrayElements(tempArray,tmpArray,0);
//    return ret;
    string successdata = "Passed Data types Successfully";
    return env->NewStringUTF(successdata.c_str());
}




//passing object to JNI
//sampleDataObj
extern "C" JNIEXPORT jstring JNICALL
Java_com_vinay_passingdatafromandroidtoc_Utility_NativeMethods_passingObjectToJni(
        JNIEnv* env,
        jobject tempInstance,
        jobject userObject) {
    printf("Inside passing object to JNI");
//    I : int
//    Z : boolean
//    Ljava/lang/String; : string

    // Get jclass of the object
    jclass  userObjectClass = env->GetObjectClass(userObject);

    // Get data field IDs of the object
    jfieldID  userIdField = env->GetFieldID(userObjectClass,"userId","I");
    jfieldID  isPremiumField = env->GetFieldID(userObjectClass,"isPremium","Z");
    jfieldID  userNameField = env->GetFieldID(userObjectClass,"userName","Ljava/lang/String;");


//    Get Individual Data
    jint  userId = env->GetIntField(userObject,userIdField);
    jboolean isPremium = env->GetBooleanField(userObject,isPremiumField);
//    jstring userName = env->Field(userObjectClass,userNameField);
//    printf("UserId : %s \n", userId);
//    printf("User is premium : %s \n", isPremium);

//    // Update data
    const char *successString = "Vinay";
    env->SetObjectField(userObject, userNameField, env->NewStringUTF(successString));

    // return error code (in this case, return the int value form the object)

    string successdata = "Passed Object Successfully";
    return env->NewStringUTF(successdata.c_str());
//    return "";
}


// get object from jni
extern "C"
JNIEXPORT jobject  JNICALL
Java_com_vinay_passingdatafromandroidtoc_Utility_NativeMethods_gettingObjectFromJni(JNIEnv *env,
                                                                    jobject  instance){
    printf("Inside getting object from JNI");
    // Create a jclass from actual Java object class path
    jclass userObjectClass = env->FindClass(
            "com/vinay/passingdatafromandroidtoc/UserObject");
    jmethodID methodId = env->GetMethodID(userObjectClass, "<init>", "()V");
    jobject userObject = env->NewObject(userObjectClass, methodId);

    //Update fields of object
    const char *successString = "Vinay";
    jfieldID sampStringField = env->GetFieldID(userObjectClass, "userName",
                                               "Ljava/lang/String;");
    env->SetObjectField(userObject, sampStringField, env->NewStringUTF(successString));

    //Update int data field
    int data = 10;
    jfieldID sampIntField = env->GetFieldID(userObjectClass, "userId", "I");
    env->SetIntField(userObject, sampIntField, data);

    return userObject;
}


