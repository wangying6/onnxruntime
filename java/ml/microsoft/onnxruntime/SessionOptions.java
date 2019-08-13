package ml.microsoft.onnxruntime

class SessionOptions {
    static {
        System.loadLibrary("onnxruntime_jni");
    }
    public SessionOptions() {
        initHandle();
    }
    @Override
    protected void finalize() throws Throwable {
        dispose();
        super.finalize();
    }
    private long nativeHandle;
    private native void initHandle();
    public native void dispose();
}


