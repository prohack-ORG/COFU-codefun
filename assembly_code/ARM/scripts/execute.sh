
pushd ../jni/
ndk-build -j4 -B
popd

adb root
adb remount

adb shell rm /data/sample/*.txt

adb push ../libs/armeabi-v7a/sample /data/sample/
adb shell "chmod 777 /data/sample/sample"
adb shell "/data/sample/sample"

adb pull /data/sample/ ../output/

diff -r -s --brief ../output/sample/dst_C.txt ../output/sample/dst_NEON_INTRINSIC.txt

