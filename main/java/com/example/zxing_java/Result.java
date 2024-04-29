package com.example.zxing_java;
import org.opencv.core.Mat;

public class Result {
    public final String text;
    public final long addr;

    public Result(String text, long addr) {
        this.text = text;
        this.addr = addr;
    }

    public Mat getImg() {
        return new Mat(addr);
    }
}
