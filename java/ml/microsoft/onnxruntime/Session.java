package ml.microsoft.onnxruntime

import ml.microsoft.onnxruntime.Env
import ml.microsoft.onnxruntime.Value
import ml.microsoft.onnxruntime.SessionOptions

class Session {
    static {
        System.loadLibrary("onnxruntime_jni");
    }
    public Session(Env env, String model_path, SessionOptions options) {
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
    public native Value[] Run(RunOptions runOptions, String[] input_names, Value[] input_values, String[] output_names);
}
