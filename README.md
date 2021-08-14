
# Hi, I'm Vinay! 👋


# Passing Data From Android to Native(C++) or vice versa

Here we will learn how to connect your android activity with c++ module and get the data from c++.

# C++ Use Cases
C++ is faster as compared to java. We can use c++ in order to secure our api keys,
or hide encryption/decryption techniques which we are using in the application.
That will make reverse engineering of the these components harder.
Along with this, if you want to work on opencv, tensorflow..., you might use c++ there.

# Getting data from json ( which has been passed from android) requires 3 steps in c++

    1. Get jclass of the object
    2. Get data field IDs of the object
    3. Get Individual Data 


# Java & Native signatures
signatures are required while fetching data from object.
jfieldID requires 2nd param as signature.

| Java Type | Native Type |
| :-------- | :------- |
| `String` | `Ljava/lang/String;` |
| `int` | `I` |
| `boolean` | `Z` |
| `byte` | `B` |
| `char` | `C` |
| `short` | `S` |
| `long` | `J` |
| `float` | `F` |
| `double` | `D` |
| `type[]` | `[type` |


# Java & Native Data Types

| Java Type | Native Type |
| :-------- | :------- |
| `java.lang.Class` | `jclass` |
| `java.lang.Object` | `jobject` |
| `java.lang.String` | `jstring` |
| `object array` | `jobjectArray` |
| `boolean array` | `jbooleanArray` |
| `char array` | `jcharArray` |
| `short array` | `jshortArray` |
| `int array` | `jintArray` |
| `long array` | `jlongArray` |
| `float array` | `jfloatArray` |
| `double array` | `jdoubleArray` |
| `Boolean` | `jboolean` |
| `byte` | `jbyte` |
| `char` | `jchar` |
| `short` | `jshort` |
| `int` | `jint` |
| `long` | `jlong` |
| `float` | `jfloat` |
| `double` | `jdouble` |
| `void` | `void` |






## Authors

- [@Vinaykumar](https://github.com/vinaykumar2197)

  
