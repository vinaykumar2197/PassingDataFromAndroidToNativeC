package com.vinay.passingdatafromandroidtoc;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.vinay.passingdatafromandroidtoc.Utility.NativeMethods;
import com.vinay.passingdatafromandroidtoc.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    private NativeMethods nativeMethods;
    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        nativeMethods = new NativeMethods();

        // Example of a call to a native method
        TextView tv = binding.sampleText;

        binding.btGetData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv.setText(nativeMethods.stringFromJNI());
            }
        });

        binding.btGetObject.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv.setText(nativeMethods.gettingObjectFromJni().getUserId() +" "+
                        nativeMethods.gettingObjectFromJni().getUserName());
            }
        });


        binding.btPassData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                // Temp data which passing to JNI
                double[] tmpArray = {1, 2, 3};
                int tmpInt = 1;
                float tmpFloat = 2.3f;

                tv.setText(""+nativeMethods.passingDataToJni(tmpArray,tmpInt,tmpFloat));
            }
        });


        binding.btPassObject.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                //Create Sample Data Object
                UserObject userObject = new UserObject();
                userObject.setUserId(0);
                userObject.setPremium(true);
                userObject.setUserName("Sachin");

                tv.setText(""+nativeMethods.passingObjectToJni(userObject));


            }
        });
    }

}