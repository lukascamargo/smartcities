class timer {
  public:

  int delayCount = 0;

  long addDelay(long time){
    if((time / 1000) >= 1){
      delayCount++;
      printDelay();
      return 0;
    } else { return time; }
  }

  void clearDelay(){
    delayCount = 0;
  }

  void printDelay(){
    Serial.println(delayCount);
  }

  bool validity(){
    if(delayCount >= 60){
      return false;
    } else {
      return true; 
    }
  }

  int getDelay(){
    return delayCount;
  }
  
};
