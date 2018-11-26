class turno {
  public: 

  String estado = "fechado";
  int carros = 0;
  int count = 0;

  void setState(String e){
    estado = e;
    resetCount();
    resetCarros();
  }

  String getState(){
    return estado;
  }

  void addCarro(){
    carros++;
  }

  void resetCarros(){
    carros = 0;
  }

  int getCarros(){
    return carros;
  }

  void addCount(){
    count++;
  }
  
  int getCount(){
    return count;
  }

  void resetCount(){
    count = 0;
  }

  
};
