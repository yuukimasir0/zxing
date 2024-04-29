# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

# Declares the project name. The project name can be accessed via ${ PROJECT_NAME},
# Since this is the top level CMakeLists.txt, the project name is also accessible
# with ${CMAKE_PROJECT_NAME} (both CMake variables are in-sync within the top level
# build script scope).
project("native-lib")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#
# In this top level CMakeLists.txt, ${CMAKE_PROJECT_NAME} is used to define
# the target library name; in the sub-module's CMakeLists.txt, ${PROJECT_NAME}
# is preferred for the same purpose.
#
# In order to load a library into your app from Java/Kotlin, you must call
# System.loadLibrary() and pass the name of the library defined here;
# for GameActivity/NativeActivity derived applications, the same library name must be
# used in the AndroidManifest.xml file.
add_library(${CMAKE_PROJECT_NAME} SHARED
        # List C/C++ source files with relative paths to this CMakeLists.txt.
        native-lib.cpp
        zxing/BarcodeFormat.cpp
        zxing/GTIN.cpp
        zxing/ReedSolomonDecoder.cpp
        zxing/BinaryBitmap.cpp
        zxing/GenericGF.cpp
        zxing/ReedSolomonEncoder.cpp
        zxing/BitArray.cpp
        zxing/GenericGFPoly.cpp
        zxing/Result.cpp
        zxing/BitMatrix.cpp
        zxing/GlobalHistogramBinarizer.cpp
        zxing/ResultPoint.cpp
        zxing/BitMatrixIO.cpp
        zxing/GridSampler.cpp
        zxing/TextDecoder.cpp
        zxing/BitSource.cpp
        zxing/HRI.cpp
        zxing/TextEncoder.cpp
        zxing/CharacterSet.cpp
        zxing/HybridBinarizer.cpp
        zxing/TextUtfEncoding.cpp
        zxing/ConcentricFinder.cpp
        zxing/MultiFormatReader.cpp
        zxing/Utf.cpp
        zxing/Content.cpp
        zxing/MultiFormatWriter.cpp
        zxing/WhiteRectDetector.cpp
        zxing/DecodeHints.cpp
        zxing/PerspectiveTransform.cpp
        zxing/ZXBigInteger.cpp
        zxing/ECI.cpp
        zxing/ReadBarcode.cpp
        zxing/zxing-c.cpp
        zxing/aztec/AZDecoder.cpp
        zxing/aztec/AZEncoder.cpp
        zxing/aztec/AZReader.cpp
        zxing/aztec/AZWriter.cpp
        zxing/aztec/AZDetector.cpp
        zxing/aztec/AZHighLevelEncoder.cpp
        zxing/aztec/AZToken.cpp
        zxing/datamatrix/DMBitLayout.cpp
        zxing/datamatrix/DMDetector.cpp
        zxing/datamatrix/DMReader.cpp
        zxing/datamatrix/DMWriter.cpp
        zxing/datamatrix/DMDataBlock.cpp
        zxing/datamatrix/DMECEncoder.cpp
        zxing/datamatrix/DMSymbolInfo.cpp
        zxing/datamatrix/DMDecoder.cpp
        zxing/datamatrix/DMHighLevelEncoder.cpp
        zxing/datamatrix/DMVersion.cpp
        zxing/libzueci/zueci.c
        zxing/maxicode/MCBitMatrixParser.cpp
        zxing/maxicode/MCDecoder.cpp
        zxing/maxicode/MCReader.cpp
        zxing/oned/ODCodabarReader.cpp
        zxing/oned/ODCode128Reader.cpp
        zxing/oned/ODCode39Writer.cpp
        zxing/oned/ODDXFilmEdgeReader.cpp
        zxing/oned/ODDataBarExpandedReader.cpp
        zxing/oned/ODEAN8Writer.cpp
        zxing/oned/ODMultiUPCEANReader.cpp
        zxing/oned/ODUPCAWriter.cpp
        zxing/oned/ODWriterHelper.cpp
        zxing/oned/ODCodabarWriter.cpp
        zxing/oned/ODCode128Writer.cpp
        zxing/oned/ODCode93Reader.cpp
        zxing/oned/ODDataBarCommon.cpp
        zxing/oned/ODDataBarReader.cpp
        zxing/oned/ODITFReader.cpp
        zxing/oned/ODReader.cpp
        zxing/oned/ODUPCEANCommon.cpp
        zxing/oned/ODCode128Patterns.cpp
        zxing/oned/ODCode39Reader.cpp
        zxing/oned/ODCode93Writer.cpp
        zxing/oned/ODDataBarExpandedBitDecoder.cpp
        zxing/oned/ODEAN13Writer.cpp
        zxing/oned/ODITFWriter.cpp
        zxing/oned/ODRowReader.cpp
        zxing/oned/ODUPCEWriter.cpp
        zxing/pdf417/PDFBarcodeValue.cpp
        zxing/pdf417/PDFCodewordDecoder.cpp
        zxing/pdf417/PDFDetectionResult.cpp
        zxing/pdf417/PDFDetector.cpp
        zxing/pdf417/PDFHighLevelEncoder.cpp
        zxing/pdf417/PDFModulusPoly.cpp
        zxing/pdf417/PDFScanningDecoder.cpp
        zxing/pdf417/PDFBoundingBox.cpp
        zxing/pdf417/PDFDecoder.cpp
        zxing/pdf417/PDFDetectionResultColumn.cpp
        zxing/pdf417/PDFEncoder.cpp
        zxing/pdf417/PDFModulusGF.cpp
        zxing/pdf417/PDFReader.cpp
        zxing/pdf417/PDFWriter.cpp
        zxing/qrcode/QRBitMatrixParser.cpp
        zxing/qrcode/QRCodecMode.cpp
        zxing/qrcode/QRDataBlock.cpp
        zxing/qrcode/QRDecoder.cpp
        zxing/qrcode/QRDetector.cpp
        zxing/qrcode/QREncoder.cpp
        zxing/qrcode/QRErrorCorrectionLevel.cpp
        zxing/qrcode/QRFormatInformation.cpp
        zxing/qrcode/QRMaskUtil.cpp
        zxing/qrcode/QRMatrixUtil.cpp
        zxing/qrcode/QRReader.cpp
        zxing/qrcode/QRVersion.cpp
        zxing/qrcode/QRWriter.cpp
        )

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/zxing
        ${CMAKE_CURRENT_SOURCE_DIR}/zxing/aztec
        ${CMAKE_CURRENT_SOURCE_DIR}/zxing/datamatrix
        ${CMAKE_CURRENT_SOURCE_DIR}/zxing/libzueci
        ${CMAKE_CURRENT_SOURCE_DIR}/zxing/maxicode
        ${CMAKE_CURRENT_SOURCE_DIR}/zxing/oned
        ${CMAKE_CURRENT_SOURCE_DIR}/zxing/pdf417
        ${CMAKE_CURRENT_SOURCE_DIR}/zxing/qrcode
)

# OpenCVのパスを設定
set(OpenCV_DIR "/usr/local/opencv-4.9.0-android-sdk/OpenCV-android-sdk/sdk/native/jni")
find_package(OpenCV REQUIRED)

# OpenCVをインクルード
include_directories(${OpenCV_INCLUDE_DIRS})

# ライブラリにOpenCVをリンク
target_link_libraries(${CMAKE_PROJECT_NAME} ${OpenCV_LIBS})

# Specifies libraries CMake should link to your target library. You
# can link libraries from various origins, such as libraries defined in this
# build script, prebuilt third-party libraries, or Android system libraries.
target_link_libraries(${CMAKE_PROJECT_NAME}
        # List libraries link to the target library
        android
        log)