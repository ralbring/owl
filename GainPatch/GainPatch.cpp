class GainPatch : public Patch {
public:
  GainPatch(){
    registerParameter(PARAMETER_A, "Gain");
  }

  void processAudio(AudioBuffer &buffer){
    float gain = getParameterValue(PARAMETER_A);
    FloatArray left = buffer.getSamples(LEFT_CHANNEL);
    FloatArray right = buffer.getSamples(RIGHT_CHANNEL);
    for(int i=0; i<buffer.getSize(); ++i){
      left[i] = gain*left[i];
      right[i] = gain*right[i];
    }
  }
};
