package com.vinay.passingdatafromandroidtoc.Utility;

import com.vinay.passingdatafromandroidtoc.UserObject;

public class NativeMethods {
    // Used to load the 'passingdatafromandroidtoc' library on application startup.
    static {
        System.loadLibrary("passingdatafromandroidtoc");
    }
    /**
     * A native method that is implemented by the 'passingdatafromandroidtoc' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native int passingDataToJni(double[] tmpArray, int tmpInt, float tmpFloat);

    public native String passingObjectToJni(UserObject sampleDataObj);

    public native UserObject gettingObjectFromJni();

}
